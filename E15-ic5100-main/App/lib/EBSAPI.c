#include "system.h"
#include "extern.h"

#define USER_DEBUG 1
#define CFG_PREFIX	0x100E

#define JOIN(x,y) x ## y

#define CONCAT(x,y) JOIN(x,y)

_ebs_response  RESPONSE_BODY;

const char err_en_tbl1[][32] =
{
	"                ",
	"Approval        ",		//000
	"Format Error    ", 	//103
	"Invalid format  ", 	//130
	
	"Original request" 		//178
	"not found       ",
	
	"Invalid         ", 	//158
	"processing code ",
	
	"Withdrawal      ",		//161
	"limit exceeded  ",
	
	"Destination     ",		//191
	"not available   ",
		
	"Duplicate       ",		//194
	"transaction     ",
	
	"System error    ",		//196
	
	"Contact Card    ",		//201
	"Issuer          ",
	
	"External decline",		//205
	
	"Insufficient    ",		//251
	"fund            ",
	
	"Wrong customer  ",		//281
	"information     ",
	
	"PIN tries limit ",		//338
	"exceeded        ",		
	
	"Invalid PIN     ",		//355
	
	"PIN Tries Limit ",		//375
	"Reached         ",		
	
	"Encryption error",		//362
	
	"Invalid 		 ",		//389
	"terminal ID     ",
	
	"Invalid         ",		//412
	"transaction     ",
	
	"Merchant limit  ",		//413
	"exceeded        ",
	
	"Invalid amount  ",		//467
	"Invalid track 2 ",		//514
	"Restricted card ",		//536
	"Lost card       ",		//541
	"Stolen card     ",		//543
	"Closed card     ",		//550
	"Declared card   ",		//552
	"Expired card    ",		//554
	
	"Invalid         ",		//600
	"client Id       ",
	
	"Invalid Card    ",		//601
	"Number Format   ",
	
	"Invalid Expiry  ",		//602
	"Date Format     ",
	
	"Format Error    ",		//603
	
	"Invalid Currency ",	//604
	"Code 			  ",
	
	"Invalid Account  ",	//605
	"Format           ",
	
	"Invalid System   ",	//606
	"Trace Audit      ",	
	"Number Format    ",	
	
	"Invalid  		  ",	//607
	"Personal Payment ", 	
	"Information 	  ",	
	"Format		      ",	
	
	"Invalid Payee    ",	//608
	"Identification   ",
	
	"Invalid Phone    ",	//609
	"Number Format    ",
	
	"Invalid voucher  ",	//610
	"number Format    ",
	
	"Invalid          ",	//611
	"Transaction Date ",
	"Format           ",
	
	"Invalid          ",	//615
	"Service Id       ",
	
	"Invalid original ",	//616
	"transaction      ",
	"system trace     ",
	"audit no# Format ",
	
	"MCS Time out     ",	//617
	
	"This service     ",	//618
	"cannot be        ",
	"reversed         ",
	
	"Invalid Terminal ",	//619
	"Id Format        ",
	
	"Invalid          ",	//620
	"PIN Format       ",
	
	"Invalid          ",	//621
	"Amount Format    ",
	
	"Invalid Cash Back",	//622
	"Amount Format    ",
	
	"MCS System Error ",	//696
	
	"MCS Invalid Cash ",	//632
	"out Transaction  ",
	"due to Invalid   ",
	"voucher length   ",
	
	"UNKNOWN ERROR    ",	//UNKNOWN
	
};

const short err_tbl4[][4] =
{
	{E1__SPACE, E1__SPACE, E1__SPACE, E1__SPACE},
	{E1__SPACE, E000,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E103,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E130,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E1781, E1782,  	  E1__SPACE},
	{E1__SPACE, E1581, E1582, 	  E1__SPACE},
	{E1__SPACE, E1611, E1612,     E1__SPACE},
	{E1__SPACE, E1911, E1912, 	  E1__SPACE},
	{E1__SPACE, E1941, E1942, 	  E1__SPACE},
	{E1__SPACE, E196,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E2011, E2012, 	  E1__SPACE},
	{E1__SPACE, E205,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E2511, E2512, 	  E1__SPACE},
	{E1__SPACE, E2811, E2812, 	  E1__SPACE},
	{E1__SPACE, E3381, E3382, 	  E1__SPACE},
	{E1__SPACE, E355,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E3751, E3752, 	  E1__SPACE},
	{E1__SPACE, E362,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E3891, E3892, 	  E1__SPACE},
	{E1__SPACE, E4121, E4122, 	  E1__SPACE},
	{E1__SPACE, E4131, E4132, 	  E1__SPACE},
	{E1__SPACE, E467,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E514,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E536,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E541,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E543,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E550,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E552,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E554,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E6001, E6002, 	  E1__SPACE},
	{E1__SPACE, E6011, E6012, 	  E1__SPACE},
	{E1__SPACE, E6021, E6022, 	  E1__SPACE},
	{E1__SPACE, E603,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E6041, E6042, 	  E1__SPACE},
	{E1__SPACE, E6051, E6052, 	  E1__SPACE},
	{E1__SPACE, E6061, E6062, 	  	  E6063},
	{E6071, 	E6072, E6073, 	  	  E6074},
	{E1__SPACE, E6081, E6082, 	  E1__SPACE},
	{E1__SPACE, E6091, E6092, 	  E1__SPACE},
	{E1__SPACE, E6101, E6102, 	  E1__SPACE},
	{E1__SPACE, E6111, E6112, 	  	  E6113},
	{E1__SPACE, E6151, E6152, 	  E1__SPACE},
	{E6161, 	E6162, E6163, 	   	  E6164},
	{E1__SPACE, E617,  E1__SPACE, E1__SPACE},
	{E1__SPACE, E6181, E6182, 		  E6183},
	{E1__SPACE, E6191, E6192, 	  E1__SPACE},
	{E1__SPACE, E6201, E6202, 	  E1__SPACE},
	{E1__SPACE, E6211, E6212, 	  E1__SPACE},
	{E1__SPACE, E6221, E6222, 	  E1__SPACE},
	{E1__SPACE, E696,  E1__SPACE, E1__SPACE},
	{E6321, 	E6322, E6323, 	   	  E6324},
	{E1__SPACE, EUNKNOWN,  E1__SPACE, E1__SPACE},
};

char apncmd[50];
char usercmd[50];
char passcmd[50];

_api_Setup networktest, workingkey,changepin, getbill, paybill;

void InitCfg(void);
void LoadCfg(void);
void SaveCfg(char check_mode);
void InitService(void);
void ReadOK(void);
short ErrMap(short ErrNo);
void ErrDisplay(short ErrNo);


void NetworkTest(void);
void GetWorkingKey(void);
int PayBill(char* PAN, char* PIN, char* expDate, double tranAmount, char* tranCurrencyCode, char* invoiceno, char* phone, char* payeeId);
int GetBill(char* PAN, char* PIN, char* expDate, char* invoiceno, char* phone, char* payeeId, char* tranCurrencyCode);
void ChangePIN(char* PAN, char* PIN, char* expDate, char* newPIN);

void ReadOK(void){
	if (iRxCnt >= 4 && !memcmp((char *)&ucRxBuf[iRxCnt-4], "OK", 2)) {
		Rprintf("OK\r\n");
	}
}

void LoadCfg(void)
{
	E15_LoadConfiguration();
	
#ifdef USER_DEBUG
	Rprintf("\r\nLoad Configuration\r\n");
#endif
	if (E15_CONFIGURATION.magiccode != CFG_PREFIX){
		InitCfg();
		
	}
	
	sprintf(apncmd,"%s%s%s","AT^SICS=0,APN,\"",E15_CONFIGURATION.EBS_server_sim.Apn,"\"\r\n");
	sprintf(usercmd,"%s%s%s","AT^SICS=0,USER,\"",E15_CONFIGURATION.EBS_server_sim.Id,"\"\r\n");
	sprintf(passcmd,"%s%s%s","AT^SICS=0,PASSWD,\"",E15_CONFIGURATION.EBS_server_sim.Passwd,"\"\r\n");

}

void InitCfg(void){
	
#ifdef USER_DEBUG
	Rprintf("Initialize Configuration\r\n");
#endif

	//E15_config *e15_config = E15_GetConfiguration();
	//E15_LoadConfiguration(E15_CONFIGURATION, sizeof(E15_config));

	//memset(&cfg, 0x00, sizeof(cfg));
	
//	
//	strcpy(cfg.apn, "zainconnect");
//	strcpy(cfg.user, "zaingprs");
//	strcpy(cfg.passwd, "123456");
//	strcpy(cfg.ip, "172.24.160.55");
//	strcpy(cfg.port, "8888");
//	strcpy(cfg.app, "EBSGateway");
//	strcpy(cfg.clientid, "Ashrafcom");
//	strcpy(cfg.terminalid, "08001051");

	strcpy(E15_CONFIGURATION.EBS_server_sim.Id, "zaingprs");
	strcpy(E15_CONFIGURATION.EBS_server_sim.Apn, "zainconnect");
	strcpy(E15_CONFIGURATION.EBS_server_sim.Passwd, "123456");
	strcpy(E15_CONFIGURATION.EBS_server_sim.ServerIP, "172.24.160.55");
	strcpy(E15_CONFIGURATION.EBS_server_sim.ServerPort, "8888");
	strcpy(E15_CONFIGURATION.EBS_APP_NAME, "EBSGateway");
	strcpy(E15_CONFIGURATION.EBS_Client_ID, "Ashrafcom");
	strcpy(E15_CONFIGURATION.EBS_Terminal_ID, "08001061");
	strcpy(E15_CONFIGURATION.EBS_TMK, "D020855E862F2A4F");
	E15_CONFIGURATION.magiccode = CFG_PREFIX;
	
	E15_SaveConfiguration();
	//Flash4MWrite((unsigned char *)&f_cfg, (unsigned char *)&cfg, sizeof(cfg));
//	memcpy(&f_cfg, &cfg, sizeof(cfg));
//	memcpy(&cfg, &f_cfg, sizeof(cfg));
	
	//InitService();
}


//void SaveCfg(char check_mode)
//{
//	if (!check_mode || memcmp(&cfg, &f_cfg, sizeof(cfg))) {
//#ifdef USER_DEBUG
//	Rprintf("Save Configuration\r\n");
//#endif
//		//Flash4MWrite((unsigned char *)&f_cfg, (unsigned char *)&cfg, sizeof(cfg));
//		memcpy(&f_cfg, &cfg, sizeof(cfg));
//		memcpy(&cfg, &f_cfg, sizeof(cfg));
//	}
//}


void InitServices(void){
	
	strcpy(networktest.sevice, "isAlive");
	sprintf(networktest.address,"%s%s%s%s%s%s%s%s%s%s","at^siss=0,address,","\"https://",E15_CONFIGURATION.EBS_server_sim.ServerIP,":",E15_CONFIGURATION.EBS_server_sim.ServerPort,"/",E15_CONFIGURATION.EBS_APP_NAME,"/",networktest.sevice,"\"\r\n");
	
	strcpy(getbill.sevice, "getBill");
	sprintf(getbill.address,"%s%s%s%s%s%s%s%s%s%s","at^siss=0,address,","\"https://",E15_CONFIGURATION.EBS_server_sim.ServerIP,":",E15_CONFIGURATION.EBS_server_sim.ServerPort,"/",E15_CONFIGURATION.EBS_APP_NAME,"/",getbill.sevice,"\"\r\n");
	
	strcpy(paybill.sevice, "payBill");
	sprintf(paybill.address,"%s%s%s%s%s%s%s%s%s%s","at^siss=0,address,","\"https://",E15_CONFIGURATION.EBS_server_sim.ServerIP,":",E15_CONFIGURATION.EBS_server_sim.ServerPort,"/",E15_CONFIGURATION.EBS_APP_NAME,"/",paybill.sevice,"\"\r\n");
	
	strcpy(changepin.sevice, "changePin");
	sprintf(changepin.address,"%s%s%s%s%s%s%s%s%s%s","at^siss=0,address,","\"https://",E15_CONFIGURATION.EBS_server_sim.ServerIP,":",E15_CONFIGURATION.EBS_server_sim.ServerPort,"/",E15_CONFIGURATION.EBS_APP_NAME,"/",changepin.sevice,"\"\r\n");
	
	strcpy(workingkey.sevice, "getWorkingKey");
	sprintf(workingkey.address,"%s%s%s%s%s%s%s%s%s%s","at^siss=0,address,","\"https://",E15_CONFIGURATION.EBS_server_sim.ServerIP,":",E15_CONFIGURATION.EBS_server_sim.ServerPort,"/",E15_CONFIGURATION.EBS_APP_NAME,"/",workingkey.sevice,"\"\r\n");
	
	ModemWrite("at^siss=0,\"srvType\",http\r\n");
	ModemWrite("at^siss=0,\"conId\",0\r\n");
	ModemWrite("AT^siss=0,ALPHABET,1\r\n");
	ModemWrite("at^siss=0,\"hcMethod\",1\r\n");
	ModemWrite("at^siss=0,\"secOpt\",-1\r\n");
	ModemWrite("at^siss=0,hcProp,\"Content-Type: application/json\"\r\n");
	ModemWrite("at^sips=\"service\",\"save\",0\r\n");
	Wait1MS(6000);
	
}
int GET_NEXT_EBS_AUDIT_Number(){
	E15_config *e15_config = E15_GetConfiguration();
	E15_LoadConfiguration(e15_config, sizeof(E15_config));

	e15_config->EBS_Audit_No++;
	int auditNumber = e15_config->EBS_Audit_No;
	E15_SaveConfiguration(e15_config,sizeof(E15_config));
	return auditNumber;
}
void NetworkTest(void){
#ifdef USER_DEBUG
	Rprintf("Call network test\r\n");
#endif
	char time[12];
	unsigned char ch;
	int ret;
	
	sprintf(time,"%02X%02X%02X%02X%02X%02X", RealTime.CLKDATE,RealTime.CLKMONTH,
	RealTime.CLKYEARL,RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
	
	sprintf(networktest.content,"%s%s%s%s%s%s%s%s%s%s%s%s%d%s","{","\"clientId\"",":\"",E15_CONFIGURATION.EBS_Client_ID,"\",\"terminalId\"",":\"",E15_CONFIGURATION.EBS_Terminal_ID,"\",\"tranDateTime\"",":\"",time,"\",\"systemTraceAuditNumber\"",":",159,"}" );

#ifdef USER_DEBUG
	Rprintf(networktest.content);
	Rprintf("\r\n");
#endif
	
	ret = HTTPWrite(&networktest);
	if(ret > 0){
		
		Rprintf("httpReponseCode: %d \r\n", httpReponseCode);
		Rprintf("Body Length    : %d \r\n", strlen(RxBody));
		Rprintf("Body           : %s \r\n", RxBody);
		
		if (httpReponseCode == 200 && strlen(RxBody) > 0) {
			json_parse(RxBody);
			if(RESPONSE_BODY.responseCode != 0){
				//error from EBS
				//TODO print response error in the display by entering error service
				ErrorDisplaySetting(MSS_ERROR, MST_ERROR,atoi(RESPONSE_BODY.responseCode));
				Rprintf("Ther responseCode is %d \r\n", RESPONSE_BODY.responseCode);
				return;
			}
			//TODO print success message in the display	
		}
		else{
			//TODO print error in the display with the httpResponseCode
		}
		
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}

	
}

void GetWorkingKey(void){
#ifdef USER_DEBUG
	Rprintf("#######################Call getworkingkey#######################\r\n");
#endif
	char time[12];
	unsigned char ch;
	int ret;
	
	sprintf(time,"%02X%02X%02X%02X%02X%02X", RealTime.CLKDATE,RealTime.CLKMONTH,
	RealTime.CLKYEARL,RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
	
	sprintf(workingkey.content,"%s%s%s%s%s%s%s%s%s%s%s%s%d%s","{","\"clientId\"",":\"",E15_CONFIGURATION.EBS_Client_ID,"\",\"terminalId\"",":\"",E15_CONFIGURATION.EBS_Terminal_ID,"\",\"tranDateTime\"",":\"",time,"\",\"systemTraceAuditNumber\"",":",74,"}" );
#ifdef USER_DEBUG
	Rprintf(workingkey.content);
	Rprintf("\r\n");
#endif


	ret = HTTPWrite(&workingkey);
	if(ret > 0){
		
		Rprintf("httpReponseCode: %d \r\n", httpReponseCode);
		Rprintf("Body Length    : %d \r\n", strlen(RxBody));
		Rprintf("Body           : %s \r\n", RxBody);
		
		if (httpReponseCode == 200 && strlen(RxBody) > 0) {
			json_parse(RxBody);
			if(RESPONSE_BODY.responseCode != 0){
				//error from EBS
				//TODO print response error in the display by entering error service
				ErrorDisplaySetting(MSS_ERROR, MST_ERROR,atoi(RESPONSE_BODY.responseCode));
				Rprintf("Ther responseCode is %d \r\n", RESPONSE_BODY.responseCode);
				return;
			}
		strcpy( E15_CONFIGURATION.EBS_TWK, RESPONSE_BODY.workingkey);
		//strcpy( E15_CONFIGURATION.EBS_TWK, "c3a9d3656ce40bc0" );
		E15_SaveConfiguration();
	
		}
		else{
			//TODO print error in the display with the httpResponseCode
		}
		
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}
	
	
}
int GetBill(char* PAN, char* PIN, char* expDate, char* invoiceno, char* phone,char* payeeId, char* tranCurrencyCode){
	#ifdef USER_DEBUG
	Rprintf("#######################Get Bill############################\r\n");
#endif
	char time[12];
	char info[52];
	unsigned char ch;
	int ret;
	
	sprintf(time,"%02X%02X%02X%02X%02X%02X", RealTime.CLKDATE,RealTime.CLKMONTH,
	RealTime.CLKYEARL,RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
	
	sprintf(info,"%s%s%s%s","2/",invoiceno,"/",phone);
	Rprintf("invoice Info %s \r\n",info);
	
	Rprintf("PIN Block %s\r\n",Get_PIN_BLOCK(PIN,PAN));
	
	sprintf(getbill.content,"%s%s%s%s%s%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s","{","\"clientId\"",":\"",E15_CONFIGURATION.EBS_Client_ID,"\",\"terminalId\"",":\"",
	E15_CONFIGURATION.EBS_Terminal_ID,"\",\"tranDateTime\"",":\"",time,"\",\"systemTraceAuditNumber\"",":",113,
	",\"PAN\"",":\"",PAN,"\",\"PIN\"",":\"",Get_PIN_BLOCK(PIN,PAN),"\",\"expDate\"",":\"",expDate,
	"\",\"personalPaymentInfo\"",":\"",info,"\",\"payeeId\"",":\"",payeeId,"\",\"tranCurrencyCode\"",":\"",tranCurrencyCode,"\"}" );
#ifdef USER_DEBUG
	Rprintf(getbill.content);
	Rprintf("\r\n");
#endif

	ret = HTTPWrite(&getbill);
	if(ret > 0){
		
		Rprintf("httpReponseCode: %d \r\n", httpReponseCode);
		Rprintf("Body Length    : %d \r\n", strlen(RxBody));
		Rprintf("Body           : %s \r\n", RxBody);
		
		if (httpReponseCode == 200 && strlen(RxBody) > 0) {
			json_parse(RxBody);
			if(RESPONSE_BODY.responseCode != 0){
				//error from EBS
				//TODO print response error in the display by entering error service
				ErrorDisplaySetting(MSS_ERROR, MST_ERROR, atoi(RESPONSE_BODY.responseCode));
				Rprintf("The responseCode is %s \r\n", RESPONSE_BODY.responseCode);
				return;
			}
		}
		else{
			//TODO print error in the display with the httpResponseCode
		}
		
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}
	

}
int PayBill(char* PAN, char* PIN, char* expDate, double tranAmount, char* tranCurrencyCode, char* invoiceno, char* phone, char* payeeId){
#ifdef USER_DEBUG
	Rprintf("#######################Call paybill#######################\r\n");
#endif
	char time[12];
	char info[52];
	unsigned char ch;
	int ret;
	
	sprintf(time,"%02X%02X%02X%02X%02X%02X", RealTime.CLKDATE,RealTime.CLKMONTH,
	RealTime.CLKYEARL,RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
	
	sprintf(info,"%s%s%s%s","6/",invoiceno,"/",phone);
	Rprintf("invoice Info %s \r\n",info);
	
	Rprintf("PIN Block %s\r\n",Get_PIN_BLOCK(PIN,PAN));
	
	sprintf(paybill.content,"%s%s%s%s%s%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s%s%s%s%f%s%s%s%s%s%s%s%s%s%s","{","\"clientId\"",":\"",E15_CONFIGURATION.EBS_Client_ID,"\",\"terminalId\"",":\"",
	E15_CONFIGURATION.EBS_Terminal_ID,"\",\"tranDateTime\"",":\"",time,"\",\"systemTraceAuditNumber\"",":",53,
	",\"PAN\"",":\"",PAN,"\",\"PIN\"",":\"",Get_PIN_BLOCK(PIN,PAN),"\",\"expDate\"",":\"",expDate,"\",\"tranAmount\"",":",tranAmount,
	",\"tranCurrencyCode\"",":\"",tranCurrencyCode,"\",\"personalPaymentInfo\"",":\"",info,"\",\"payeeId\"",":\"",payeeId,"\"}" );
#ifdef USER_DEBUG
	Rprintf(paybill.content);
	Rprintf("\r\n");
#endif

	ret = HTTPWrite(&paybill);
	if(ret > 0){
		
		Rprintf("httpReponseCode: %d \r\n", httpReponseCode);
		Rprintf("Body Length    : %d \r\n", strlen(RxBody));
		Rprintf("Body           : %s \r\n", RxBody);
		
		if (httpReponseCode == 200 && strlen(RxBody) > 0) {
			json_parse(RxBody);
			if(RESPONSE_BODY.responseCode != 0){
				//error from EBS
				//TODO print response error in the display by entering error service
				ErrorDisplaySetting(MSS_ERROR, MST_ERROR, atoi(RESPONSE_BODY.responseCode));
				Rprintf("Ther responseCode is %s \r\n", RESPONSE_BODY.responseCode);
				return atoi(RESPONSE_BODY.responseCode);
			}
		return atoi(RESPONSE_BODY.responseCode);
		}
		
		else{
			//TODO print error in the display with the httpResponseCode
		}
		
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}
return 1;
}


void ChangePIN(char* PAN, char* PIN, char* expDate, char* newPIN){
	#ifdef USER_DEBUG
	Rprintf("#######################Change PIN############################\r\n");
#endif
	char time[12];
	unsigned char ch;
	int ret;
	
	sprintf(time,"%02X%02X%02X%02X%02X%02X", RealTime.CLKDATE,RealTime.CLKMONTH,
	RealTime.CLKYEARL,RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
	
	Rprintf("PIN Block %s\r\n",Get_PIN_BLOCK(PIN,PAN));
	
	sprintf(changepin.content,"%s%s%s%s%s%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s%s%s%s%s%s","{","\"clientId\"",":\"",E15_CONFIGURATION.EBS_Client_ID,"\",\"terminalId\"",":\"",
	E15_CONFIGURATION.EBS_Terminal_ID,"\",\"tranDateTime\"",":\"",time,"\",\"systemTraceAuditNumber\"",":",GET_NEXT_EBS_AUDIT_Number(),
	",\"PAN\"",":\"",PAN,"\",\"PIN\"",":\"",Get_PIN_BLOCK(PIN,PAN),"\",\"expDate\"",":\"",expDate,
	"\",\"newPIN\"",":\"",Get_PIN_BLOCK(newPIN,PAN),"\"}" );
#ifdef USER_DEBUG
	Rprintf(changepin.content);
	Rprintf("\r\n");
#endif

	ret = HTTPWrite(&changepin);
	if(ret > 0){
		
		Rprintf("httpReponseCode: %d \r\n", httpReponseCode);
		Rprintf("Body Length    : %d \r\n", strlen(RxBody));
		Rprintf("Body           : %s \r\n", RxBody);
		
		if (httpReponseCode == 200 && strlen(RxBody) > 0) {
			json_parse(RxBody);
			if(RESPONSE_BODY.responseCode != 0){
				//error from EBS
				//TODO print response error in the display by entering error service
				ErrorDisplaySetting(MSS_ERROR, MST_ERROR, RESPONSE_BODY.responseCode);
				Rprintf("Ther responseCode is %d \r\n", RESPONSE_BODY.responseCode);
				return;
			}
		}
		else{
			//TODO print error in the display with the httpResponseCode
		}
		
	} else {
		Rprintf("HTTPWrite ERROR (%d)\r\n", ret);
	}
}


short ErrMap(short ErrNo){
	if (ErrNo==000) return CONCAT(E4,000);	if (ErrNo==103) return CONCAT(E4,103);	if (ErrNo==130) return CONCAT(E4,130);
	if (ErrNo==178) return CONCAT(E4,178);	if (ErrNo==158) return CONCAT(E4,158);	if (ErrNo==161) return CONCAT(E4,161);
	if (ErrNo==191) return CONCAT(E4,191);	if (ErrNo==194) return CONCAT(E4,194);	if (ErrNo==196) return CONCAT(E4,196);
	if (ErrNo==201) return CONCAT(E4,201);	if (ErrNo==205) return CONCAT(E4,205);	if (ErrNo==251) return CONCAT(E4,251);
	if (ErrNo==281) return CONCAT(E4,281);	if (ErrNo==338) return CONCAT(E4,338);	if (ErrNo==355) return CONCAT(E4,355);
	if (ErrNo==375) return CONCAT(E4,375);	if (ErrNo==362) return CONCAT(E4,362);	if (ErrNo==389) return CONCAT(E4,389);
	if (ErrNo==412) return CONCAT(E4,412);	if (ErrNo==413) return CONCAT(E4,413);	if (ErrNo==467) return CONCAT(E4,467);
	if (ErrNo==514) return CONCAT(E4,514);	if (ErrNo==536) return CONCAT(E4,536);	if (ErrNo==541) return CONCAT(E4,541);
	if (ErrNo==543) return CONCAT(E4,543);	if (ErrNo==550) return CONCAT(E4,550);	if (ErrNo==552) return CONCAT(E4,552);
	if (ErrNo==554) return CONCAT(E4,554);	if (ErrNo==600) return CONCAT(E4,600);	if (ErrNo==601) return CONCAT(E4,601);
	if (ErrNo==602) return CONCAT(E4,602);	if (ErrNo==603) return CONCAT(E4,603);	if (ErrNo==604) return CONCAT(E4,604);
	if (ErrNo==605) return CONCAT(E4,605);	if (ErrNo==606) return CONCAT(E4,606);	if (ErrNo==607) return CONCAT(E4,607);
	if (ErrNo==608) return CONCAT(E4,608);	if (ErrNo==609) return CONCAT(E4,609);	if (ErrNo==610) return CONCAT(E4,610);
	if (ErrNo==611) return CONCAT(E4,611);	if (ErrNo==615) return CONCAT(E4,615);	if (ErrNo==616) return CONCAT(E4,616);
	if (ErrNo==617) return CONCAT(E4,617);	if (ErrNo==618) return CONCAT(E4,618);	if (ErrNo==619) return CONCAT(E4,619);
	if (ErrNo==620) return CONCAT(E4,620);	if (ErrNo==621) return CONCAT(E4,621);	if (ErrNo==622) return CONCAT(E4,622);
	if (ErrNo==696) return CONCAT(E4,696);	if (ErrNo==632) return CONCAT(E4,632);

	
	
	else return E4UNKNOWN;
}


/* Display 4 line error on LCD */
void ErrDisplay(short ErrNo)
{
	short	i, index, en;
	char tmp[16];
	en = 0;
	en = ErrMap(ErrNo);
	CursorOff();
	for (i = 0 ; i < 4 ; i++) {
		index = err_tbl4[en][i];
		if ((index & M1__DUMMY) == M1__DUMMY)
			continue;
//		if(MsgNo == M4MAINM01 && i == 1){
//		utf8_to_farsi(tmp,  (char*)msg_tbl1[index], 16);
//		memcpy(&DSPBUF0[i*16], tmp, 16);
//		else{memcpy(&DSPBUF0[i*16], msg_tbl1[index], 16);}
		memcpy(&DSPBUF0[i*16], err_en_tbl1[index], 16);
		LCD_DISPLAY(4, i, 0, 16);
	}
}

