/*======================================================================*/
/*																		*/
/*								EBS_API									*/
/*																		*/
/*======================================================================*/


extern char apncmd[50];
extern char usercmd[50];
extern char passcmd[50];

extern const char err_ar_tbl1[][32];
extern const char err_en_tbl1[][32];
extern const short err_tbl4[][4];


typedef struct t_Response {
	char PAN[19];	
	char systemTraceAuditNumber[32];
	char clientid[32];
  	char terminalid[32];
  	char responseCode[32];		
  	char tranAmount[32];		
  	char tranFee[32];	
  	char additionalData[1000];
	char responseStatus[12];			
	char responseMessage[200];
  	char approvalCode[32];
  	char workingkey[16];
  	
  	char referenceNumber[32];			
	char ReferenceId[32];
	char UnitName[50];
	char ServiceName[50];
	char PayerName[50];
	char TotalAmount[50];
	double DueAmount;	
	char InvoiceExpiry[12];
	short invoiceStatus;
						

} _ebs_response;

typedef struct t_api_Setup {
		
	char sevice[32];
	char address[255];
	char content[1024];				

} _api_Setup;
int GET_NEXT_EBS_AUDIT_Number();
extern _ebs_response RESPONSE_BODY;
extern _api_Setup networktest, workingkey, changepin, getbill, paybill;

extern void InitCfg(void);
extern void InitServices(void);
extern void LoadCfg(void);
extern void SaveCfg(char check_mode);
extern void ReadOK(void);
extern void ErrDisplay(short ErrNo);

extern void NetworkTest(void);
extern void GetWorkingKey(void);
extern int GetBill(char* PAN, char* PIN, char* expDate, char* invoiceno, char* phone, char* payeeId, char* tranCurrencyCode);
extern int PayBill(char* PAN, char* PIN, char* expDate, double tranAmount, char* tranCurrencyCode, char* invoiceno, char* phone, char* payeeId);
extern void ChangePIN(char* PAN, char* PIN, char* expDate, char* newPIN);

extern char user_id[65];
extern char user_password[65];

typedef enum
{
	E1__SPACE = 0x0000,		/* "                ", */
	
	E000,	E103,	E130,	E1781,E1782,	E1581,E1582,
	E1611,E1612,	E1911,E1912,	E1941,E1942,	E196,
	E2011,E2012,	E205,	E2511,E2512,	E2811,E2812,	
	E3381,E3382,	E355,	E3751,E3752,	E362,	E3891,E3892,
	E4121,E4122,	E4131,E4132,	E467,	E514,	E536,	E541,
	E543,	E550,	E552,	E554,
	E6001,E6002,	E6011,E6012,	E6021,E6022,	E603,
	E6041,E6042,	E6051,E6052,	E6061,E6062,E6063,	
	E6071,E6072,E6073,E6074,	E6081,E6082,	E6091,E6092,	
	E6101,E6102,	E6111,E6112,E6113,	E6151,E6152,
	E6161,E6162,E6163,E6164,	E617,	E6181,E6182,E6183,
	E6191,E6192,	E6201,E6202,	E6211,E6212,	E6221,E6222,
	E696,	E6321,E6322,E6323,E6324,	EUNKNOWN,
	



	
	M1__EDUMMY = 0xFFFF
} _eErr1;

typedef enum
{
	/* "                ", "                ", "                ", "                " */
	E4__SPACE = 0x0000,
	
	E4000,E4103,E4130,E4178,E4158,E4161,E4191,E4194,E4196,E4201,E4205,E4251,
	E4281,E4338,E4355,E4375,E4362,E4389,E4412,E4413,E4467,E4514,E4536,E4541,
	E4543,E4550,E4552,E4554,E4600,E4601,E4602,E4603,E4604,E4605,E4606,E4607,
	E4608,E4609,E4610,E4611,E4615,E4616,E4617,E4618,E4619,E4620,E4621,E4622,
	E4696,E4632,E4UNKNOWN,
	E4__EDUMMY = 0xFFFF
} _eErr4;

