
#include "system.h"
#include "extern.h"


void HexEncode(unsigned char *data, int data_length, unsigned char *result){
	int i = 0;
	for(i=0;i<data_length;i++){
		sprintf(result+strlen(result),"%02x",data[i]);
	}
}

void HexDecode(unsigned char *data,unsigned char *result){
	int i;
	for(i = 0; i < (int)(strlen(data)/2)+ (int)strlen(data)%2;i++){
		char data_part[3] = {0};
		sprintf(data_part,"%.2s",data+(2*i));
		result[i] = strtol(data_part,NULL,16);
	}
}


char *Get_PIN_BLOCK(const char *clear_pin, const char *clear_pan){
	int i, len;

	BYTE HEX_TMK[8] = {0};
	BYTE HEX_TWK[8] = {0};
	BYTE PIN_RESULT[8] = {0};
	static unsigned char RET_RESULT[100] = {0};
	unsigned char P1[17], P2[17], HEX_P1[8],HEX_P2[8],XOR_P[8];
	memset(P1,0x0,17);
	memset(P2,0x0,17);
	Rprintf("EBS TWK: %s\r\nEBS TMK: %s\r\n", E15_CONFIGURATION.EBS_TWK,E15_CONFIGURATION.EBS_TMK);
	HexDecode(E15_CONFIGURATION.EBS_TWK,HEX_TWK);
	HexDecode(E15_CONFIGURATION.EBS_TMK,HEX_TMK);

	P1[0] = '0';
	P1[1] = strlen(clear_pin) + '0';

	len = strlen(clear_pin);
	for(i = 0; i<len;i++){
		P1[i+2] = clear_pin[i];
	}

	for(i=2+strlen(clear_pin); i < 16; i++){
		P1[i] = 'F';
	}


	memset(P2,'0',4);
	unsigned char *P2_sp;
	
	P2_sp = &P2[4];
	int pan_len = strlen(clear_pan);
	for(i=pan_len - 12; i<pan_len; i++)
	{
		*(P2_sp++) = clear_pan[i-1];
	}

	HexDecode(P1,HEX_P1);
	HexDecode(P2,HEX_P2);

	for(i=0; i<8; ++i)
		XOR_P[i] = HEX_P1[i] ^ HEX_P2[i];

    des(HEX_TWK , HEX_TMK, DEAmoDecS);
    des(XOR_P , HEX_TWK, DEAmoEncS);
	memset(RET_RESULT,0x0,sizeof(RET_RESULT));

	HexEncode(XOR_P,8,RET_RESULT);

	return (char *)RET_RESULT;
}



