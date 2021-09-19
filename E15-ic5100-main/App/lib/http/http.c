#include "system.h"
#include "extern.h"

#define USER_DEBUG 1

int HTTPWrite(_api_Setup * pservice);
int ModemReadData(char *data, int ms10);
int ReadHTTPResponse(int ms10);
int ReadHTTPBody(int ms10);
void HTTPTest(void);

unsigned char RxStream[2048];
unsigned char RxBody[2048];
int httpReponseCode;
unsigned char *RxPtr;

int ReadHTTPResponse(int ms10)
{
	Rprintf("ReadHTTPResponse: ...\r\n");
	int size;
	unsigned char ch;
	unsigned char codeStr[4];

	RxPtr = RxStream;
	memset(&RxStream[0], '\0', sizeof(RxStream));
	memset(&codeStr[0], '\0', sizeof(codeStr));
	TIME_BASE10 = 0x8000 | ms10;
	while( 1 ) {
		if (!(TIME_BASE10 & 0x8000)) break;
		if (CheckRxInput(cDCEPortNo)) {
			ch = RdCom(cDCEPortNo)& 0xFF;
#ifdef USER_DEBUG
			Rprintf("%c", (char)ch);
#endif
			*RxPtr++ = ch;
			if ((*(RxPtr-2) == '\r') && (*(RxPtr-1) == '\n')) {
				size = RxPtr - &RxStream[0] - 2;
				Rprintf("New Line: -----------------------\r\n");
				Rprintf("size: %d\r\n", size);
				Rprintf("data: %s\r\n", RxStream);
				if (size == 0){
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 25 && 
					(
						!memcmp((char *)&RxStream[0], "^SIS: 0,0,201,", 14) ||
						!memcmp((char *)&RxStream[0], "^SIS: 0,0,202,", 14) ||
						!memcmp((char *)&RxStream[0], "^SIS: 0,0,203,", 14) ||
						!memcmp((char *)&RxStream[0], "^SIS: 0,0,204,", 14)
						)) {
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 25 && !memcmp((char *)&RxStream[0], "^SIS: 0,0,2201,", 15)) {
					Rprintf("HTTP Response Received\r\n");
					codeStr[0] = *(RxStream + 25);
					codeStr[1] = *(RxStream + 26);
					codeStr[2] = *(RxStream + 27);
					httpReponseCode = atoi(codeStr);
					// Rprintf("codeStr=%s\r\n", codeStr);
					// Rprintf("httpReponseCode=%d\r\n", httpReponseCode);
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 10 && !memcmp((char *)&RxStream[0], "^SISR: 0,1", 10)) {
					return (1);
				}
				else if (size >= 5 && !memcmp((char *)&RxStream[0], "ERROR", 5)) {
					return (-1);
				}
				if (CheckRxInput(cDCEPortNo)){
					continue;
				}
				else
					return (1);
			}								
		} 
	} //End of While

	return (0);
}

int ReadHTTPBody(int ms10)
{
	Rprintf("ReadHTTPBody: \r\n");
	int i, ret, retry, size, recievedSize;//,size2, size3;
	unsigned char ch;
	unsigned char temp[6];
	unsigned char *RxSizePtr;
	unsigned char str1[] = "^SISR: 0,2";

	recievedSize = i = retry = 0;
	memset(&RxBody[0], '\0', sizeof(RxBody));
	
	Rprintf("HTTP READING...\r\n");
	while( 1 ) {
		if (!(TIME_BASE10 & 0x8000)) break;
		if (!i) {
			WrCom(cDCEPortNo, "AT^SISR=0,1500\r\n", 16); 
			Wait1MS(2);
			RxPtr = RxStream;
			memset(&RxStream[0], '\0', sizeof(RxStream));
			TIME_BASE10 = 0x8000 | ms10;
			i++;
		}
		if (CheckRxInput(cDCEPortNo)) {
			ch = RdCom(cDCEPortNo)& 0xFF;
#ifdef USER_DEBUG
			Rprintf("%c", (char)ch);
#endif
			*RxPtr++ = ch;
			if ((*(RxPtr-2) == '\r') && (*(RxPtr-1) == '\n')) {
				Rprintf("New Line: -----------------------\r\n");
				size = RxPtr - &RxStream[0] - 2;
				// Rprintf("RxStream: %s\r\n", RxStream);
				// Rprintf("RxStreamSize: %d\r\n", size);
				if (size >= 14 && !memcmp((char *)&RxStream[0], "AT^SISR=0,1500", 14)) {
					// Rprintf("AT^SISR=0,1500 recieved\r\n");
					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 2 && !memcmp((char *)&RxStream[0], "OK", 2)) {
					Rprintf("OK recieved\r\n");
					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 10 && !memcmp((char *)&RxStream[size - 10], "^SISR: 0,2", 10)) {
					Rprintf("^SISR: 0,2 recieved\r\n");
					return (1);
				}
				else if (size >= 10 && !memcmp((char *)&RxStream[size - 10], "^SISR: 0,1", 10)) {
					Rprintf("^SISR: 0,1 recieved\r\n");
					i = retry = 0;

					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 10 && !memcmp((char *)&RxStream[0], "^SISR: 0,", 9)) {
					Rprintf("^SISR: 0,x recieved\r\n");
					Rprintf("SISR: %s\r\n", RxStream);

					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
					// return (1);
				}
				else if (size >= 13 && !memcmp((char *)&RxStream[0], "+CME ERROR: 3", 13)) {
					Wait1MS(300);
					i = 0;
					retry++;
					if (retry >= 3) return (-3);

					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else if (size >= 2 
					&& memcmp((char *)&RxStream[0], "^", 1) 
					&& memcmp((char *)&RxStream[0], "+", 1)
					) {
					Rprintf("Body recieved (%d)\r\n", size);
					Rprintf("Body: %s\r\n", RxStream);

					// copy received body to RxBody buffer
					memcpy(&RxBody[recievedSize], &RxStream[0], size);
					recievedSize = recievedSize + size;

					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
					// return (1);
				}

				if (CheckRxInput(cDCEPortNo)){
					// reset RxStream
					RxPtr = RxStream;
					memset(&RxStream[0], '\0', sizeof(RxStream));
					continue;
				}
				else
					return (1);
			}								
		} 
	} //End of While
	return (0);
}

int ModemReadData(char *data, int ms10)
{
	int i, retry, size;
	unsigned char ch;
	
	Rprintf("ModemReadData: \r\n");
	
	i = retry = 0;
	size = strlen(data);
	TIME_BASE10 = 0x8000 | ms10;
	while( 1 ) {
		if (!(TIME_BASE10 & 0x8000)) break;
		if (CheckRxInput(cDCEPortNo)) {
			ch = RdCom(cDCEPortNo)& 0xFF;
#ifdef USER_DEBUG
			Rprintf("%c", (char)ch);
#endif
			ucRxBuf[iRxCnt & 0x1FFF] = ch;
			iRxCnt++;
			if ((ucRxBuf[iRxCnt-2] == '\r') && (ucRxBuf[iRxCnt-1] == '\n')) {
				if (iRxCnt >= size + 2 && !memcmp((char *)&ucRxBuf[iRxCnt- (size + 2)], data, size)) {
					return (1);
				}
				else if (iRxCnt >= 7 && !memcmp((char *)&ucRxBuf[iRxCnt-7], "ERROR", 5)) {
					return (-1);
				}
				if (CheckRxInput(cDCEPortNo)){
					continue;
				}
				else
					return (1);
			}								
		} 
	} //End of While

	return (0);
}

int HTTPWrite(_api_Setup * pservice){
	int ret;
	unsigned char temp[30];
#ifdef USER_DEBUG
	Rprintf("HTTPWrite: ....\r\n");
#endif
	// set init value for response code
	httpReponseCode = 0;
	
	// set api service address
	ret = ModemWrite(pservice->address);
	if(ret < 0){
		Rprintf("ModemWrite Failed (%d)\r\n", ret);
		return ret;
	}

	sprintf(temp,"at^siss=0,hcContLen,%lu\r\n", strlen(pservice->content));
	ret = ModemWrite(temp);
	if(ret < 0){
		Rprintf("ModemWrite Failed (%d)\r\n", ret);
		return ret;
	}

	// Wait1MS(1300);
	ret = ModemWrite("at^siso=0\r\n");
	if(ret < 0){
		Rprintf("ModemWrite Failed (%d)\r\n", ret);
		return ret;
	}

	ret = ModemReadData("^SISW: 0,1", 6000);
	if(ret <= 0){
		Rprintf("HTTP SISO ERROR (%d)\r\n", ret);
		ModemWrite("at^sisc=0\r\n");
		return ret;
	}
	Rprintf("HTTP READY FOR WRITTING...\r\n");
	sprintf(temp,"at^sisw=0,%lu\r\n", strlen(pservice->content));
	ret = ModemWrite(temp);
	if(ret < 0){
		Rprintf("ModemWrite Failed (%d)\r\n", ret);
		ModemWrite("at^sisc=0\r\n");
		return ret;
	}

	Rprintf("HTTP WRITTING...\r\n");
	ret = ModemWrite(pservice->content);
	if(ret < 0){
		Rprintf("ModemWrite Failed (%d)\r\n", ret);
		ModemWrite("at^sisc=0\r\n");
		return ret;
	}

	ret = ModemReadData("^SISW: 0,2", 1000);
	if(ret <= 0){
		Rprintf("HTTP SISW END ERROR (%d)\r\n", ret);
		ModemWrite("at^sisc=0\r\n");
		return ret;
	}
	// ret = ModemReadData("^SIS: 0,0,2201,\"HTTP/1.1 200 OK\"", 1000);
	ret = ReadHTTPResponse(3000);
	// if(ret <= 0){
	// 	Rprintf("HTTP/1.1 200 OK ERROR (%d)\r\n", ret);
	// 	ModemWrite("at^sisc=0\r\n");
	// 	return ret;
	// }

	// ret = ModemReadData("^SISR: 0,1", 1000);
	if(ret < 0) {
		Rprintf("SISR: 0,1 ERROR (%d)\r\n", ret);
		ModemWrite("at^sisc=0\r\n");
		return ret;
	}
	else if (ret > 0) {
		ret = ReadHTTPBody(6000);
		if(ret < 0){
			Rprintf("ReadHTTPBody ERROR (%d)\r\n", ret);
			ModemWrite("at^sisc=0\r\n");
			return ret;
		}
	}
	else {
		Rprintf("no body\r\n");
		// if ret == 0 means there is no body; so no problem
		ret = 1;
	}
	
	ModemWrite("at^sisc=0\r\n");
	return (ret);
	
}

void HTTPTest(void){
	int ret;
#ifdef USER_DEBUG
	Rprintf("HTTP test\r\n");
#endif
	// strcpy(networktest.sevice, "register");
	sprintf(networktest.address,"%s","AT^SISS=0,\"address\",\"https://128.199.142.102/api/v1/users/register\"\r\n");
	sprintf(networktest.content,"%s", "{\"mobileNumbe\":\"+249964450455\"}");
	ret = HTTPWrite(&networktest);
	if(ret > 0){
		Rprintf("Response code: %d\r\n", httpReponseCode);
		Rprintf("Body Size    : %d \r\n", strlen(RxBody));
		Rprintf("Body         : %s \r\n", RxBody);
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}
}
