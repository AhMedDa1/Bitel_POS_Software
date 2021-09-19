
/*======================================================================*/
/*																		*/
/*								KEY.H									*/
/*																		*/
/*======================================================================*/
typedef struct {
	char SaleAmount[50];
    char Token[50];
    char MeterNumber[50];
    char AccountNumber[50];
    char ReceiptNumber[50];
    char CustomerName[50];
    char ReferenceNumberE[50];
    char OperatorMessagee[50];
    char Units[50];

	char personalPaymentInfo1[50];
    char ApplicationID[50];
    char StudentNameE[50];
    char StudentNameA[50];
    char SERVER_IP[50];
    char PORT_NO[50];
	char APN[50];
	char USERNAME[50];
	char PASSWORD[50];

	char operationCode[50];
	char operationDate[50];
	int operationAmount;

	char operationCode1[50];
	char operationDate1[50];
	int operationAmount1;

    char operationCode2[50];
	char operationDate2[50];
	int operationAmount2;

	char operationCode3[50];
	char operationDate3[50];
	int operationAmount3;

	char operationCode4[50];
	char operationDate4[50];
	int operationAmount4;

	char operationCode5[50];
	char operationDate5[50];
	int operationAmount5;

	char operationCode6[50];
	char operationDate6[50];
	int operationAmount6;

	char operationCode7[50];
	char operationDate7[50];
	int operationAmount7;

	char operationCode8[50];
	char operationDate8[50];
	int operationAmount8;

	char operationCode9[50];
	char operationDate9[50];
	int operationAmount9;

	char operationCode10[50];
	char operationDate10[50];
	int operationAmount10;


	int morsal_status;
	double unBillAmount;
//	double unBillAmount;
	int cash;
	int trans;
	int responseCode;
	int systemTraceAuditNumber;
	double tranFee;
	char approvalCode[50];
	char responseMessage[50];
	char referenceNumber[50];
	char tocard[32];
	char terminal[10];
	char toAccount[32];
	char payeeId[10];
	char personalPaymentInfo[40];
	char personalPayment[30];
	char newPIN[30];
	char voucherNumber[50];
	char tranCurrencyCode[50];
	char tranAmount[50];
	char cashBackAmount[50];
	char uuid[50];
	char unit_name[256];
	char receipt_no[50];
	char invoice_no[50];
	char invoice_expiry[50];
	int invoice_status;
	char payment_ref_id[50];
	char identity[50];
	char identity_type[50];
	char phone[50];
	int has_vat;
	char received_from[256];
	char date[50];
	char description[200];
	int status;
	int services_count;
//	E15_service services[50];
	double total;
	double amount_due;
	char total_in_word[1024];
//	int currency_id;
	int payment_method_id;
	int discount;
	char collector_name[256];
	int is_copy;
	char PAN[30];
	char PIN[30];
	char card_holder_name[256];
	char card_expiry_date[10];
	char totalAmount[64];
	char auth_code[50];
	char transaction_id[100];
	int is_successful;

} EBS_receipt;

typedef struct {
	char magiccode[4];	// magiccode
	int receipts_threshold;
	int time_threshold;
	int money_threshold;
	char last_receipt_offline[50];
	int sequance_no;
	int sequance_month;
	int sequance_year;
	char unit_name[256];
	int unit_id;
//	char full_name[256];
	int user_id;
	long int receipts_total;
	int current_patch_no;
	int current_patch_size;
}E15_offline_mode_data;

extern EBS_receipt receipt;
extern const unsigned short tbl_MainService[][16];

extern short sVirtualKey, sTempKey;
extern short sLCDContrast, sPRTDensity;
extern short sAutoTestMode, sMainTestMenu, sDeviceTestMenu, sLCDKEYTestMenu, sAutoCOMMenu;
extern unsigned short usCOMTotalCnt, usCOMSuccessCnt;
extern unsigned short usAutoComTimer;
extern unsigned short usMainStatus;
extern unsigned short *uspServiceAddr;

extern char cDTEPortNo, cDTEBaudrate, cDCEPortNo, cDCEBaudrate, cSIMSlotNo;
extern char c65TempKeyBuf[65];
extern char *ptrCountryName;
char* convertEncoding(char *label);
extern void KeyTask(void);
extern void KeyService(int key);
extern void EnterKeyService(void);
extern void CancelKeyService(void);
extern void SetInitialStatus(void);
extern void SelectOperator(void);
extern void MainStatusSetting(unsigned short Status, short ServiceTableNo, short DisplayMsgNo);
extern void ErrorDisplaySetting(unsigned short Status, short ServiceTableNo, short DisplayMsgNo);
extern void ErrorDisplayAndGoInitialStatus(unsigned short MsgNo);
extern void ErrorDisplayAndGoErrorStatus(unsigned short MsgNo);
extern void DisplayCenterString(char YPos, char *str, int size);
extern void Dispaly2PullDownMenu(void);
extern void Dispaly3PullDownMenu(void);
extern void Dispaly4PullDownMenu(void);
extern void Dispaly6PullDownMenu(void);
extern void DispalySelfTestMainMenu(int menu);
extern int GetCountryName(int country_code, char **country_name);
extern int GetCountryCode(char *str);
extern void HyperTerminalMode(void);
extern int MainMenuUpDown(int key, int index, int max) ;
char* convertEncoding(char *label);
void utf_to_arabic(char* stringg9);
extern void ScrollStart(int index, int pos);
extern void ScrollStop(void);
extern void ScrollTask(void);
extern void ScrollHilight(int Msgno, int pos);
extern int L;
extern int A;
extern int E;
extern int X;
extern char id_type[65];
extern char id_num[65];
extern char name_e[65];
extern unsigned char digest[32];
extern char note_rec[65];
extern char pay_way[65];
//void test(char servicep);
//typedef struct services {
extern char *sha1_user_pass;
extern int u;
extern int u1;		
extern int u2;		
extern int u3;		
extern int u4;		
extern int u5;		
extern int u6;		
extern int u7;		
extern int u8;		
extern int u9;		
extern int u10;		
extern int u11;		
extern int u12;		
extern int u13;		
extern int u14;		
extern int u15;		
extern int u16;		
extern int u17;		
extern int u18;		
extern int u19;		
															
extern char service_id[65];							
extern char service_name[65];				
	extern char* editable;							
extern	char service_fees[65];						
extern	char currency_name[65];						
	extern char currency_fraction[65];						
	extern char currency_code[65];						
extern 	char currency_id[65];	
	//classes:				
extern	char* classes_no;					
extern	char class_id[65];				
extern	char class_name[65];					
extern	char class_fees[65];					
extern	char percentage[65];

extern char service_id1[65];							
extern char service_name1[65];				
	extern char* editable1;							
extern	char service_fees1[65];						
extern	char currency_name1[65];						
	extern char currency_fraction1[65];						
	extern char currency_code1[65];						
extern 	char currency_id1[65];	
	//classes:				
extern	char* classes_no1;					
extern	char class_id1[65];				
extern	char class_name1[65];					
extern	char class_fees1[65];					
extern	char percentage1[65];	


//} e15_services;
//extern e15_services E15_ser1 , E15_ser2 ,E15_ser3,E15_ser4,E15_ser5,E15_ser6,E15_ser7,E15_ser8,E15_ser9,E15_ser10,E15_ser11,E15_ser12,E15_ser13,E15_ser14,E15_ser15;

/* */
