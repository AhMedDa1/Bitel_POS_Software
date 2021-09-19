
#include "system.h"
#include "extern.h"


#define PRT_BPL 48L			/* Bytes Per Line = PRT_BPL*8 Pixels Per Line		*/
#define PRT_LPP 36L			/* Lines Per Page[upto 36] : depends on Application	*/
#define PRT_CPL 32L			/* Chars Per Line[upto 32] : depends on Application	*/
/*
Bit information for Printing attribute buffer data  

bit 7 6 5 4 3 2 1 0 
    | | | |
    | | | |-------------- under line required
    | |	|---------------- double width
    | |------------------ graphics prinitng required
    |-------------------- line space adjust required 

0x00=normal, 0x10=under line, 0x20=double width
*/
#define PRF_NON 0x0000		/* Normal 		*/
#define PRF_ALC 0x0100
#define PRF_ALR 0x0200
#define PRF_W2X 0x0400		/* double width */
#define PRF_W2Y 0x0800
#define PRF_BAR 0x1000		/* under line	*/
#define PRF_GRA 0x4000
#define PRF_GAP 0x8000

/*--------------------------------------------------------------------------*/
/* static functions & variables for PRINTER */
/*--------------------------------------------------------------------------*/

static unsigned short swMx, swMy, swPx, swPy;
static char *pGrBuf, *pGrTmp;

short sPrintStep, sPrintPage, sPrintErrFlag;
char gbGrBuf[65536];

unsigned short usEMITestWaitingTimer;


void PrintTask(void);
short SelectPrintPage(void);
void posPrinterInit(void);
void PrintSDKtest(short index,void* parguments);
void PrintReceipt(short index);
short FormatPrtHead(short noLine);
short FormatPrtFoot(short noLine);
void PrintSetFF(short noLine);
short FormatPrtText(short noL, char *msg, char *str, short attr);
extern char* convertEncoding(char *strii);
void PrintSelfTest(short index);
void PrintSDKRECIET(short index);
void PrintEMITest(short index);
 char feesn1[65];
  char feesn1_1[65];
  char feesn1_2[65];
  char feesn2[65];
  char feesn2_1[65];
  char feesn2_2[65];
  char feesn3[65];
  char feesn3_1[65];
  char feesn3_2[65];
  char feesn4[65];
  char feesn4_1[65];
  char feesn4_2[65];
  char feesn5[65];
  char feesn5_1[65];
  char feesn5_2[65];
  char feesn6[65];
  char feesn6_1[65];
  char feesn6_2[65];
  char feesn7[65];
  char feesn7_1[65];
  char feesn7_2[65];
  char feesn8[65];
  char feesn8_1[65];
  char feesn8_2[65];
  char feesn9[65];
  char feesn9_1[65];
  char feesn9_2[65];
  char feesn10[65];
  char feesn10_1[65];
  char feesn10_2[65];
  char feesn11[65];
  char feesn11_1[65];
  char feesn11_2[65];
  char feesn12[65];
  char feesn12_1[65];
  char feesn12_2[65];
  char feesn13[65];
  char feesn13_1[65];
  char feesn13_2[65];
  char feesn14[65];
  char feesn14_1[65];
  char feesn14_2[65];
  char feesn15[65];
  char feesn15_1[65];
  char feesn15_2[65];
  char feesn16[65];
  char feesn16_1[65];
  char feesn16_2[65];
  char feesn17[65];
  char feesn17_1[65];
  char feesn17_2[65];



/*----------------------------------------------------------------------------
	char PRINTER_WORKING(void);
	Output	: return = 0xFF ( No ACTION )
			
			: return = 0x35 - NO PAPER DETECTED
			: return = 0x36 - PRINTING TIMEOUT ERROR 
			: retunr = 0x37 - NO PAPER MARK DETECTION SEEK FINISHED
			: return = 0x61 - ONE PAGE PRINTING FINISH
			: return = 0x60 - ALL PAGE PRINTING FINISH
----------------------------------------------------------------------------*/
void PrintTask(void)
{
	short i, key;
	
	i = PRINTER_WORKING() & 0xFF;
	
	if (sPrintStep == 0)
		return;
	
	switch (i) {
		case 0x60:		/* ALL PAGE PRINTING FINISH */
			sPrintStep = 3;
			break;
	}
	
	switch (sPrintStep) {
		case 1:		/* Print Initial Status */
			sPrintErrFlag = 0;
			/* NO PAPER ? */
			if ((PAPER_READ() & 0xFF) != 0xFF) {
       			if (*uspServiceAddr != 0x3400) {	/* Self Test */
        			sPrintErrFlag = 1;
        			sPrintStep = 3;
        		}
        		else {								/* EMI Test */
        			/* "   <EMI TEST>   ", "   No Paper !   ", "  Insert paper  ", "CANCEL OR ENTER " */
        		//	StrDisplay(M4EMI0003);
        			while (1) {
        				key = KEYSCAN() & 0xFF;
        				if (key == BTKEY_ENTER) {
        					/* "   <EMI TEST>   ", "                ", "Printing Now... ", "                " */
					//		StrDisplay(M4EMI0001);
        					return;
        				}
        				else if (key == BTKEY_CANCEL) {
        					sPrintErrFlag = 1;
        					sPrintStep = 4;
        					return;
        				}
        			}
        		}
 			}
			else {
				/* Printer Off-Line ? */
				if ((ONLINE_READ() & 0xFF) != 0xFF)
					MAKEONLINE();
					
				sPrintPage = SelectPrintPage();
				if (sPrintPage == 0xFF) {
					sPrintErrFlag = 1;
					if (*uspServiceAddr != 0x3400)
						sPrintStep = 3;
					else
						sPrintStep = 4;
					break;
				}
				
				posPrinterInit();
				switch (*uspServiceAddr) {
					case 0x1100:	/* System Test */
					case 0x1211:	/* LCDKEY Test - LCD Dot Test */
					case 0x1212:	/* LCDKEY Test - LCD Contrast Test */
					case 0x1213:	/* LCDKEY Test - LCD BackLinght & Buzzer Test */
					case 0x1214:	/* LCDKEY Test - Key Test */
					case 0x0390:	/* Printer Test */
					case 0x0790:
					case 0x1231:	/* MSR Track Test */
					case 0x1240:	/* IC CARD Test */
						PrintSelfTest(sPrintPage);
						break;
					case 0x1306:	/* COMM Test - Manual Test */
					case 0x130D:	/* COMM Test - Auto Test */
						PrintReceipt(sPrintPage);
						break;
					case 0x3400:	/* EMI Test */
						PrintEMITest(sPrintPage);
						break;
				}
				
				CHAR_FILL1[sPrintPage] = 0xFF;
				PRINTING_NEED = 0xFF;
				sPrintStep = 2;
			}
			break;
		case 2:		/* Printing Status */
			/* NO PAPER ? */
			if ((PAPER_READ() & 0xFF) != 0xFF) {
       			if (*uspServiceAddr != 0x3400) {	/* Self Test */
        			sPrintErrFlag = 2;
        			sPrintStep = 3;
        		}
        		else {								/* EMI Test */
        			/* "   <EMI TEST>   ", "   No Paper !   ", "  Insert paper  ", "CANCEL OR ENTER " */
        	//		StrDisplay(M4EMI0003);
        			while (1) {
        				key = KEYSCAN() & 0xFF;
        				if (key == BTKEY_ENTER) {
        					/* "   <EMI TEST>   ", "                ", "Printing Now... ", "                " */
					//		StrDisplay(M4EMI0001);
							PRINTING_NEED = 0;
    	   					for (i = 0; i < 5; i++)
       							CHAR_FILL1[i] = 0;
       						PRINT_FROM_FIRST();
       						sPrintStep = 1;
        					return;
        				}
        				else if (key == BTKEY_CANCEL) {
        					sPrintErrFlag = 2;
        					sPrintStep = 4;
        					return;
        				}
        			}
        		}
			}
			break;
		case 3:		/* ONE PAGE PRINTING FINISH */
			switch (*uspServiceAddr) {
				case 0x1100:	/* System Test */
					if (!sAutoTestMode) {
						/* "  <Self Test>   ", "Test Menu[0-5] ?", "      [ ]       ", "                " */
						//MainStatusSetting(MSS_SELFTEST_MENU, MST_SELECT_SELFTEST_MENU, M4TMENU01);
						memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
						c65TempKeyBuf[0] = '0';
						Lprint_1(2, 7, c65TempKeyBuf[0]);
						CursorOn(2, 7);
						ucKeyCnt = 0;
						DispalySelfTestMainMenu(c65TempKeyBuf[0]-'0');
					}
					else {
						/* "1.LCD/KEY   Test", "2.Printer   Test", "3.MSR Track Test", "4.IC Card   Test" */
		//				MainStatusSetting(MSS_SELECT_DEVICETEST_MENU, MST_SELECT_DEVICETEST_MENU, M4TDEV001);
						sTempKey = BTKEY_1;
						Dispaly4PullDownMenu();
						sVirtualKey = BTKEY_ENTER;
					}
					break;
				case 0x1211:	/* LCDKEY Test - LCD Dot Test */
				case 0x1212:	/* LCDKEY Test - LCD Contrast Test */
				case 0x1213:	/* LCDKEY Test - LCD BackLinght & Buzzer Test */
				case 0x1214:	/* LCDKEY Test - Key Test */
				case 0x1220:	/* Printer Test */
				case 0x1240:	/* IC CARD Test */
					if (!sAutoTestMode) {
						/* "1.LCD/KEY   Test", "2.Printer   Test", "3.MSR Track Test", "4.IC Card   Test" */
					//	MainStatusSetting(MSS_SELECT_DEVICETEST_MENU, MST_SELECT_DEVICETEST_MENU, M4TDEV001);
						sTempKey = BTKEY_1;
						Dispaly4PullDownMenu();
					}
					else {
						switch (*uspServiceAddr) {
							case 0x1214:	/* LCDKEY Test - Key Test */
								/* "1.LCD/KEY   Test", "2.Printer   Test", "3.MSR Track Test", "4.IC Card   Test" */
					//			MainStatusSetting(MSS_SELECT_DEVICETEST_MENU, MST_SELECT_DEVICETEST_MENU, M4TDEV001);
								sTempKey = BTKEY_2;
								Dispaly4PullDownMenu();
								break;
							case 0x1220:	/* Printer Test */
								/* "1.LCD/KEY   Test", "2.Printer   Test", "3.MSR Track Test", "4.IC Card   Test" */
								//MainStatusSetting(MSS_SELECT_DEVICETEST_MENU, MST_SELECT_DEVICETEST_MENU, M4TDEV001);
								sTempKey = BTKEY_3;
								Dispaly4PullDownMenu();
								break;
							case 0x1240:	/* IC CARD Test */
								/* "COMM Test ?     ", "2.Manual Test   ", "3.Automatic Test", "                " */
			//					MainStatusSetting(MSS_COMM_TEST, MST_COMM_TEST, M4TCOMM01);
								sTempKey = BTKEY_2;
								Dispaly2PullDownMenu();
								break;
						}
						sVirtualKey = BTKEY_ENTER;
					}
					break;
				case 0x1231:	/* MSR Track Test */
					if (!sAutoTestMode) {
						uspServiceAddr--;
					}
					else {
						/* "1.LCD/KEY   Test", "2.Printer   Test", "3.MSR Track Test", "4.IC Card   Test" */
						//MainStatusSetting(MSS_SELECT_DEVICETEST_MENU, MST_SELECT_DEVICETEST_MENU, M4TDEV001);
					//	sTempKey = BTKEY_4;
						Dispaly4PullDownMenu();
					}
					sVirtualKey = BTKEY_ENTER;
					break;
				case 0x1306:	/* COMM Test - Manual Test */
				case 0x130D:	/* COMM Test - Auto Test */
					if (!sAutoTestMode) {
			///			uspServiceAddr = (unsigned short *)&tbl_MainService[MST_COMM_TEST][1];
						sVirtualKey = BTKEY_ENTER;
					}
					else {
						SetInitialStatus();
					}
					break;
				case 0x3400:	/* EMI Test */
					/* "   <EMI TEST>   ", "                ", "                ", "PRESS CANCEL KEY" */
			//		StrDisplay(M4EMI0002);
					usEMITestWaitingTimer = Get10MSTimer();
					while (1) {
						key = KEYSCAN() & 0xFF;
						if (key == BTKEY_CANCEL) {
							sPrintStep = 4;
							return;
						}
						
						if (delta10MS(usEMITestWaitingTimer) >= 100) {
							/* "   <EMI TEST>   ", "                ", "Printing Now... ", "                " */
						//	StrDisplay(M4EMI0001);
							sPrintStep = 1;
							return;
						}
					}
					break;
			}
			
			sPrintStep = 0;
			if (sPrintErrFlag) {
				PRINTING_NEED = 0;
    	   		for (i = 0; i < 5; i++)
       				CHAR_FILL1[i] = 0;
       			PRINT_FROM_FIRST();
       		}
			break;
		case 4:
			sPrintStep = 0;
			if (sPrintErrFlag) {
				PRINTING_NEED = 0;
    	   		for (i = 0; i < 5; i++)
       				CHAR_FILL1[i] = 0;
       			PRINT_FROM_FIRST();
       		}
       		
       		sVirtualKey = BTKEY_CANCEL;
			break;
	}
}
/*
short SelectPrintPage(void)
{
	short i;
	
	for (i = 0; i < 5; i++) {
		if ((CHAR_FILL1[i] & 0xFF) == 0x00)
			break;
	}
	
	if (i < 5) {
		memset((char *)&CHAR_BUFFER1[0], 0x00, 5*PRT_LPP*PRT_CPL);
		memset((char *)&ATTB_BUFFER1[0], 0x00, 5*PRT_LPP*PRT_CPL);
	}
	else
		i = 0xFF;
	
	return i;
}
*/
short SelectPrintPage(void)
{
	short i;
	int u = 63;
	for (i = 0; i < 5; i++)
		CHAR_FILL1[i] = 0x00;
	
	memset((char *)&CHAR_BUFFER1[0], 0x00, 5*PRT_LPP*PRT_CPL);
	memset((char *)&ATTB_BUFFER1[0], 0x00, 5*PRT_LPP*PRT_CPL);
	
	return (0);
}

void posPrinterInit(void)
{
	/*
		: Set printing preference for control density or contrast level   
		: accept 0 t0 29 value for control ( default : 15 )
		: 0 1 2 3 -- 8 -- -- -- 15 -- -- -- -- -- 26 27 28 29
		:            <- Used current standard printer ->                       
		: <- special high speed printer in here ->
		: 
		: high speed    < ---------------------- >  slow speed 
		: light quality < ---------------------- >  dark level
	*/
	SET_PRINTING_PREFERENCE(sPRTDensity);
	/*
		: accept 0 to 15 data for line space gap 
		: (default : 4 )
	*/
	SET_LINESPACE(2);
	
	pGrBuf = (char *)&gbGrBuf[0];
	pGrTmp = (char *)&gbGrBuf[sizeof(gbGrBuf)-128];
	swMx = 1;
	swMy = 1;
}

void PrintSDKRECIET(short index)
{
	short i, j, k, n;
	char *pTmp;
	char BiosVer[6], HWInfo[17], str[33];
	
	n = 0;
	n++;
	char *modelel1 ="بسم الله الرحمن الرحيم    ";
	utf8_to_iso_8859_6(modelel1,modelel1, strlen(modelel1));
	fix_connected_chars(modelel1);
	
	right2left(modelel1);
	n = FormatPrtText(n, NULL, modelel1, PRF_BAR);
	right2left(modelel1);
	n++;

		char *modelel2 ="جمهورية السودان         ";
	utf8_to_iso_8859_6(modelel2,modelel2, strlen(modelel2));
	fix_connected_chars(modelel2);
	
	right2left(modelel2);
	n = FormatPrtText(n, NULL, modelel2, PRF_BAR);
	right2left(modelel2);
	n++;

	char *modelel3 ="Ashraf Communication Co.Ltd   ";
	utf8_to_iso_8859_6(modelel3,modelel3, strlen(modelel3));
	fix_connected_chars(modelel3);
	
	right2left(modelel3);
	n = FormatPrtText(n, NULL, modelel3, PRF_BAR);
	right2left(modelel3);
	n++;
	/*------------------------------------------------------------------------
		Title
	------------------------------------------------------------------------*/
	memset((char *)&pGrTmp[0], '*', PRT_CPL);
	n = FormatPrtText(n, NULL, (char *)&pGrTmp[0],  PRT_CPL);
#ifdef BITEL_IC3100PE
	n = FormatPrtText(n, NULL, (char *)&"IC3100-PE",  PRF_W2X);
#else
#ifdef BITEL_IC3100P
	n = FormatPrtText(n, NULL, (char *)&"IC3100-P",  PRF_W2X);
#else
#ifdef BITEL_IC5100P
			char *payment_method_name1 ="بسم الله الرحمن الرحيم";
			utf8_to_iso_8859_6(payment_method_name1,payment_method_name1, strlen(payment_method_name1));
	fix_connected_chars(payment_method_name1);
	
	right2left(payment_method_name1);
	n = FormatPrtText(n, NULL, payment_method_name1, PRF_BAR);
	right2left(payment_method_name1);
#else
	n = FormatPrtText(n, NULL, (char *)&"IC6000-P ",  PRF_W2X);
#endif
#endif
#endif
	n = FormatPrtText(n, NULL, (char *)&pGrTmp[0],  PRT_CPL);
	
	/*------------------------------------------------------------------------
		POS Values
	------------------------------------------------------------------------*/
	GetSystemHWInformation(HWInfo);
	if (HWInfo[9] == 0x33) {
		switch (HWInfo[10]) {
			case 0x31:	strcpy(str, "IC3100"); break;
			case 0x32:	strcpy(str, "IC3200"); break;
			default:	strcpy(str, "Unknown Code"); break;
		}
	}
	else if (HWInfo[9] == 0x35)
		strcpy(str, "IC5100");
	else
		strcpy(str, "Unknown Code");
	
	char *payment_method_name2 ="الموديل";
	utf8_to_iso_8859_6(payment_method_name2,payment_method_name2, strlen(payment_method_name2));
	fix_connected_chars(payment_method_name2);
	right2left(payment_method_name2);
	n = FormatPrtText(n, NULL, payment_method_name2, PRF_BAR);
	right2left(payment_method_name2);
	
	switch (HWInfo[1]) {
		case 0x30:	strcpy(str, " NONE"); break;
		case 0x34:	strcpy(str, " 2 MB"); break;
		case 0x35:	strcpy(str, " 4 MB"); break;
		case 0x36:
		case 0x37:	strcpy(str, " 8 MB"); break;
		case 0x38:	strcpy(str, "16 MB"); break;
		default:	strcpy(str, "Unknown Code"); break;
	}
	n = FormatPrtText(n, (char *)&"SRAM  ", str,  16);
	switch (HWInfo[2]) {
		case 0x30:	strcpy(str, " NONE"); break;
		case 0x34:	strcpy(str, " 2 MB"); break;
		case 0x35:	strcpy(str, " 4 MB"); break;
		case 0x36:
		case 0x37:	strcpy(str, " 8 MB"); break;
		case 0x38:	strcpy(str, "16 MB"); break;
		default:	strcpy(str, "Unknown Code"); break;
	}
	n = FormatPrtText(n, (char *)&"SDRAM ", str,  16);
	switch (HWInfo[3]) {
		case 0x30:	strcpy(str, " NONE"); break;
		case 0x34:	strcpy(str, " 2 MB"); break;
		case 0x35:	strcpy(str, " 4 MB"); break;
		case 0x36:
		case 0x37:	strcpy(str, " 8 MB"); break;
		case 0x38:	strcpy(str, "16 MB"); break;
		default:	strcpy(str, "Unknown Code"); break;
	}
	n = FormatPrtText(n, (char *)&"ROM   ", str,  16);
	
	GetSystemBiosVersion(BiosVer);
	n = FormatPrtText(n, (char *)&"BIOS  ", BiosVer,  16);
	n = FormatPrtText(n, (char *)&"SWV#  ", (char *)&tbl_ProgramVersion,  16);
	
	n = FormatPrtText(n, (char *)&"POS#  ", (char *)&"05090001", 8);
	n = FormatPrtText(n, (char *)&"REV#  ", (char *)&"BITELIC3K_V40", 13);
	n = FormatPrtText(n, (char *)&"TYPE  ", (char *)&"22", 2);
	
	n = FormatPrtText(n, (char *)&"CAPA  ", (char *)&"E0F8C0", 6);
	n = FormatPrtText(n, (char *)&"aCAP  ", (char *)&"E000B0A001", 10);
	
	n = FormatPrtText(n, (char *)&"TCC   ", (char *)&"R", 1);
	n = FormatPrtText(n, (char *)&"IFD   ", (char *)&"BTSC-EMV Ver1.0", 15);
	n = FormatPrtText(n, (char *)&"TEL#  ", (char *)&st_Setup.sz17TelNo, sizeof(st_Setup.sz17TelNo));
	n++;
		//E15_receipt1 *args;
	//	char	stream[64*2];
	//char unit_name[256]="احمد اسماعيل";
	//utf8_to_iso_8859_6(args->unit_name,args->unit_name,strlen(args->unit_name));
	//fix_connected_chars(args->unit_name);
	//	sprintf( stream, "%s", args->unit_name );
	/*------------------------------------------------------------------------
		System Font
	------------------------------------------------------------------------*/
		
			char *payment_method_name ="بسم الله الرحمن الرحيم";
			utf8_to_iso_8859_6(payment_method_name,payment_method_name, strlen(payment_method_name));
	fix_connected_chars(payment_method_name);
	
	right2left(payment_method_name);
	n = FormatPrtText(n, NULL, payment_method_name, 64);
	right2left(payment_method_name);
	j = 0xB1;
	i = n + 8;
	int y = 0;
//	while (n < i) {
	//	for (k = 0; k < PRF_BAR; k++)
		
			CHAR_BUFFER1[index][n][80] = 0xFF;
			CHAR_BUFFER1[index][n][81] = j+80;
			CHAR_BUFFER1[index][n][82] = j+70;
			
			
		n++;
	}
	
void PrintSDKtest(short index,void* parguments)
{
	int sum = 0;
	short i, j, k, n;
	char *pTmp ;
	char BiosVer[6], HWInfo[17], str[65],str1[65];
	char	temp_stream[64*2];
	char	stream[64*2];
	char time[12];
	char time_date_line[64];
	E15_receipt* args;
	args          = (E15_receipt*)parguments;
	n = 0;
	n++;
	/*strcpy(num_rec,0x30080300);	
	strcpy(num_rec1,0x30080400);	
    strcpy(num_rec2,0x30080500);	
	strcpy(num_rec3,0x30080600);	
	strcpy(num_rec4,0x30080700);	
	strcpy(num_rec5,0x30080800);	
	strcpy(num_rec6,0x30080900);	
	strcpy(num_rec7,0x30080A00);	
	strcpy(num_rec9,0x30080C00);	
	strcpy(num_rec10,0x30080D00);	
	strcpy(num_rec11,0x30080E00);	
	strcpy(num_rec12,0x30080F00);	
	strcpy(num_rec13,0x30081000);	
	strcpy(num_rec14,0x30081100);	
	strcpy(num_rec15,0x30081200);	
	strcpy(fees,0x30081500);
	strcpy(fees1,0x30081510);
 	strcpy(fees2,0x30081520);
  	strcpy(fees3,0x30081530);
	strcpy(fees4,0x30081540);
	strcpy(fees5,0x30081550);
	strcpy(fees6,0x30081560);
	strcpy(fees7,0x30081570);
	strcpy(fees8,0x30081580);
	strcpy(fees9,0x30081590);
	strcpy(fees10,0x300815A0);
	strcpy(fees11,0x300815B0);
	strcpy(fees12,0x300815C0);
	strcpy(fees13,0x300815D0);
	strcpy(fees14,0x300815E0);
	strcpy(fees15,0x300815F0);
				//	strcpy(fees,0x30081500);
			/*		strcpy(classn1,0x30081600);
					strcpy(classn1_1,0x30081610);
					strcpy(classn1_2,0x30081620);
					strcpy(classn2,0x30081563);
					strcpy(classn2_1,0x30081640);
					strcpy(classn2_2,0x30081650);
					strcpy(classn3,0x30081660);
					strcpy(classn3_1,0x30081670);
					strcpy(classn3_2,0x30081680);
					strcpy(classn4,0x30081690);
					strcpy(classn4_1,0x300816A0);
					strcpy(classn4_2,0x300816B0);
					strcpy(classn5,0x300816C0);
					strcpy(classn5_1,0x300816D0);
					strcpy(classn5_2,0x300816E0);
					strcpy(classn6,0x300816F0);
					strcpy(classn6_1,0x3008700);
					strcpy(classn6_2,0x30081710);
					strcpy(classn7,0x30081720);
					strcpy(classn7_1,0x30081730);
					strcpy(classn7_2,0x30081740);
					strcpy(classn8,0x30081750);
					strcpy(classn8_1,0x30081760);
					strcpy(classn8_2,0x30081770);
					strcpy(classn9,0x30081780);
					strcpy(classn9_1,0x30081790);
					strcpy(classn9_2,0x300817A0);
					strcpy(classn10,0x300817B0);
					strcpy(classn10_1,0x300817C0);
					strcpy(classn10_2,0x300817D0);
					strcpy(classn11,0x300817E0);
					strcpy(classn11_1,0x300817F0);
					strcpy(classn11_2,0x30081800);
					strcpy(classn12,0x30081810);
					strcpy(classn12_1,0x30081820);
					strcpy(classn12_2,0x30081830);
					strcpy(classn13,0x30081840);
					strcpy(classn13_1,0x30081850);
					strcpy(classn13_2,0x30081860);
					strcpy(classn14,0x30081870);
					strcpy(classn14_1,0x30081880);
					strcpy(classn14_2,0x30081890);
					strcpy(classn15,0x300818A0);
					strcpy(classn15_1,0x300818B0);
					strcpy(classn15_2,0x300818C0);
						
					strcpy(feesn1,0x30081930);
					strcpy(feesn1_1,0x30081940);
					strcpy(feesn1_2,0x30081950);
					strcpy(feesn2,0x30081960);
					strcpy(feesn2_1,0x30081970);
					strcpy(feesn2_2,0x30081980);
					strcpy(feesn3,0x30081990);
					strcpy(feesn3_1,0x300819A0);
					strcpy(feesn3_2,0x300819B0);
					strcpy(feesn4,0x300819C0);
					strcpy(feesn4_1,0x300819D0);
					strcpy(feesn4_2,0x300819E0);
					strcpy(feesn5,0x300819F0);
					strcpy(feesn5_1,0x30081A00);
					strcpy(feesn5_2,0x30081A10);
					strcpy(feesn6,0x30081A20);
					strcpy(feesn6_1,0x30081A30);
					strcpy(feesn6_2,0x30081A40);
					strcpy(feesn7,0x30081A50);
					strcpy(feesn7_1,0x30081A60);
					strcpy(feesn7_2,0x30081A70);
					strcpy(feesn8,0x30081A80);
					strcpy(feesn8_1,0x30081A90);
					strcpy(feesn8_2,0x30081AA0);
					strcpy(feesn9,0x30081AB0);
					strcpy(feesn9_1,0x30081AC0);
					strcpy(feesn9_2,0x30081AD0);
					strcpy(feesn10,0x30081AE0);
					strcpy(feesn10_1,0x30081AF0);
					strcpy(feesn10_2,0x30081B00);
					strcpy(feesn11,0x30081B10);
					strcpy(feesn11_1,0x30081B20);
					strcpy(feesn11_2,0x30081B30);
					strcpy(feesn12,0x30081B40);
					strcpy(feesn12_1,0x30081B50);
					strcpy(feesn12_2,0x30081B60);
					strcpy(feesn13,0x30081B70);
					strcpy(feesn13_1,0x30081B80);
					strcpy(feesn13_2,0x30081B90);
					strcpy(feesn14,0x30081BA0);
					strcpy(feesn14_1,0x30081BB0);
					strcpy(feesn14_2,0x30081BC0);
					strcpy(feesn15,0x30081BD0);
					strcpy(feesn15_1,0x30081BE0);
					strcpy(feesn15_2,0x30081BF0);*/
	/*------------------------------------------------------------------------
		LOGO Image
	------------------------------------------------------------------------*/
	k = ((unsigned short)SudanLogo[2] << 8) | (unsigned short)SudanLogo[3];	/* Image Height */
	if (sizeof(gbGrBuf) > ((unsigned long)pGrBuf-(unsigned long)&gbGrBuf[0] + k*48)) {
		//n = FormatPrtText(n, NULL, "LOGO Image", 0);
		/*
			void ASSIGN_GRAPHICS(char* , char or int);
			: Address point input for graphics data  
			: assign graphics data to 0 to 4 number to handle for printing
		*/
		ASSIGN_GRAPHICS((char *)&SudanLogo[0] , 3);
		ATTB_BUFFER1[index][n][0] = 0x43;
		n += (k + 23) / 24;
		pGrBuf += sizeof(SudanLogo);
	}
		k = ((unsigned short)SudaPAN[2] << 8) | (unsigned short)SudaPAN[3];	/* Image Height */
	if (sizeof(gbGrBuf) > ((unsigned long)pGrBuf-(unsigned long)&gbGrBuf[0] + k*48)) {
	//	n = FormatPrtText(n, NULL, "LOGO Image", 0);
		/*
			void ASSIGN_GRAPHICS(char* , char or int);
			: Address point input for graphics data  
			: assign graphics data to 0 to 4 number to handle for printing
		*/
		ASSIGN_GRAPHICS((char *)&SudaPAN[0] , 3);
		ATTB_BUFFER1[index][n][0] = 0x43;
		n += (k + 23) / 24;
		
		pGrBuf += sizeof(SudaPAN);
	}
		
		
	
	sprintf( stream, "******** %s ********","سداد الفاتورة");
	utf8_to_iso_8859_6(stream,stream,strlen(stream));
	fix_connected_chars(stream);
	strcpy(temp_stream ,right2left(stream));

	n = FormatPrtText(n, NULL, temp_stream, 0);
	//right2left(modelel1);
	n++;

		
		sprintf( stream, "%s","التاريخ :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		sprintf(time_date_line,"%02X/%02X/%02X", RealTime.CLKDATE,RealTime.CLKMONTH,RealTime.CLKYEARL);
		n = FormatPrtText(n, temp_stream,time_date_line,  16);
	//	right2left(modelel2);
		
		sprintf( stream, "%s","الوقت :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		sprintf(time_date_line,"%02X:%02X:%02X",RealTime.CLKHOUR,RealTime.CLKMIN,RealTime.CLKSEC);
		n = FormatPrtText(n, temp_stream,time_date_line,  16);
		//right2left(modelel3);
		
		
		sprintf( stream, "%s","رقم الجهاز :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,E15_CONFIGURATION.EBS_Terminal_ID,  16);
		//right2left(modelel3);
		
		
		sprintf( stream, "%s","رقم البطاقة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,note_rec ,  19);
		//right2left(modelel3);
		n++;
		/*sprintf( stream, "%s","صاحب البطاقة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.PayerName ,  16);
		//right2left(modelel3);
		n++;*/
		if (atoi(RESPONSE_BODY.responseCode) == 0){
		sprintf( stream, "******** %s ********","المعاملة ناجحة");
		utf8_to_iso_8859_6(stream,stream,strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));

		n = FormatPrtText(n, NULL, temp_stream, 0);
		//right2left(modelel1);
		n++;
		}else{
		sprintf( stream, "******** %s ********","المعاملة فاشلة");
		utf8_to_iso_8859_6(stream,stream,strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));

		n = FormatPrtText(n, NULL, temp_stream, 0);
		//right2left(modelel1);
		n++;}
		
		
		sprintf( stream, "%s","رقم المتابعة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream, RESPONSE_BODY.systemTraceAuditNumber,  16);
		//right2left(modelel3);
		
		sprintf( stream, "%s","رقم الايصال :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,id_type,  19);
		//right2left(modelel3);
		
		sprintf( stream, "%s","رقم التلفون :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,pay_way ,  16);
		//right2left(modelel3);
		
	/*	sprintf( stream, "%s","رقم التعاقد :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,(char *)&"153155165 " ,  16);
		//right2left(modelel3);
		*/
		sprintf( stream, "%s","مبلغ الفاتورة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		//sprintf(str1, "%d",RESPONSE_BODY.tranAmount);
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.tranAmount ,  16);
		//right2left(modelel3);
		
		sprintf( stream, "%s","المبلغ المدفوع :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
	//	sprintf(str1, "%d",RESPONSE_BODY.tranAmount);
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.tranAmount,  16);
		//right2left(modelel3);
		
		sprintf( stream, "%s","رقم المرجع :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream, RESPONSE_BODY.referenceNumber,  16);
		//right2left(modelel3);
		sprintf( stream, "%s","الوحدة الحكومية:");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		sprintf(str1, "%s",RESPONSE_BODY.UnitName);
		utf8_to_iso_8859_6(str1,str1, strlen(str1));
		fix_connected_chars(str1);
		strcpy(str1 ,right2left(str1));
		n = FormatPrtText(n, temp_stream, str1,  16);
		
		sprintf( stream, "%s","نجاح المعاملة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.approvalCode ,  19);
		//right2left(modelel3);
		
		sprintf( stream, "%s","كود الاستجابة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		//sprintf(str1, "%d",RESPONSE_BODY.responseCode);
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.responseCode ,  16);
		//right2left(modelel3);
		
		sprintf( stream, "%s","رسالة الاستجابة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.responseMessage ,  16);
		//right2left(modelel3);
		
		sprintf( stream, "%s","العمولة :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
	//	sprintf(str1, "%d", RESPONSE_BODY.tranFee);
		n = FormatPrtText(n, temp_stream,RESPONSE_BODY.tranFee ,  16);
		//right2left(modelel3);
		
	/*	sprintf( stream, "%s","رقم التحقق :");
		utf8_to_iso_8859_6(stream,stream, strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));
		n = FormatPrtText(n, temp_stream, (char *)&"153155165 ",  16);
		//right2left(modelel3);*/
		sprintf( stream, "********%s********","****************");
		utf8_to_iso_8859_6(stream,stream,strlen(stream));
		fix_connected_chars(stream);
		strcpy(temp_stream ,right2left(stream));

		n = FormatPrtText(n, NULL, temp_stream, 0);
		
	/*------------------------------------------------------------------------
		Title
	------------------------------------------------------------------------*/
//	memset((char *)&pGrTmp[0], '*', PRT_CPL);
	//n = FormatPrtText(n, NULL, (char *)&pGrTmp[0],  PRT_CPL);

		
	
	/*------------------------------------------------------------------------
		POS Values
	------------------------------------------------------------------------*/
	

	
	
	/*	strcpy(str, "رقم الطرفية :"); 
	
	utf8_to_iso_8859_6(str,str, strlen(str));
	fix_connected_chars(str);
	right2left(str);
	n = FormatPrtText(n, str,(char *)&"1111  ",  16);
	
	
	
	
		strcpy(str, "المجموع :"); 
	utf8_to_iso_8859_6(str,str, strlen(str));
	fix_connected_chars(str);
	right2left(str);
	sprintf(str1, "%d", sum);
	n = FormatPrtText(n,  str,str1,  16);
	//if(u==1){strcpy(service_fees, fees);}
	//else if(u==2){strcpy(service_fees, fees1);}
	//else if(u==3){strcpy(service_fees, fees2);}
//	else if(u==4){strcpy(service_fees, fees3);}
	//else if(u==5){strcpy(service_fees, fees4);}
//	else if(u==6){strcpy(service_fees, fees5);}
//	else if(u==7){strcpy(service_fees, fees6);}
//	else if(u==8){strcpy(service_fees, fees7);}
//	else if(u==9){strcpy(service_fees, fees8);}
//	else if(u==10){strcpy(service_fees, fees9);}
//	else if(u==11){strcpy(service_fees, fees10);}
//	else if(u==12){strcpy(service_fees, fees11);}
//	else if(u==13){strcpy(service_fees, fees12);}
//	else if(u==14){strcpy(service_fees, fees13);}
//	else if(u==15){strcpy(service_fees, fees14);}
//	else if(u==16){strcpy(service_fees, fees15);}
	//else if(u==17){strcpy(service_fees, fees16);}
	
	//n = FormatPrtText(n,  str , service_fees,  16);
	
	
	
		strcpy(str, class_name); 
	utf8_to_iso_8859_6(str,str, strlen(str));
	fix_connected_chars(str);
	right2left(str);
	n = FormatPrtText(n,  str,class_fees,  16);
	n++;
		*/
		
	
	

	
	PrintSetFF(n);
}

void PrintReceipt(short index)
{
	short i, j, k, n;
	char temp[41], temp1[41];
	
	n = FormatPrtHead(index*(36*PRT_CPL));
	n++;
	
	n = FormatPrtText(n, NULL, "Sale", 32|PRF_W2X);
	n++;
	
	memset(temp, 0x00, sizeof(temp));
	memcpy(temp, TestCardTrack2_tbl, 16);
	n = FormatPrtText(n, (char *)&"PAN  :", (char *)&temp,  16);
	n = FormatPrtText(n, (char *)&"(MSR):", (char *)&"LEE/KEUNHO",  10);
	n++;
	
	sprintf((char *)&temp[0], "%06ld", lBatchNo);
	n = FormatPrtText(n, (char *)&"Batch:", (char *)&temp[0],  6);
	sprintf((char *)&temp[0], "%06ld", lSTAN);
	n = FormatPrtText(n, (char *)&"Trace:", (char *)&temp[0],  6);
	
	GetRTCDateTime(&RealTime, 0);
	memset(temp1, 0x00, sizeof(temp1));
	memcpy(temp1, iso8583RxMsg.F13n04_uc5TrxnDate, 2);
	i = atoi(temp1);
	temp1[0] = iso8583RxMsg.F12n06_uc7TrxnTime[0];
	temp1[1] = iso8583RxMsg.F12n06_uc7TrxnTime[1];
	temp1[2] = ':';
	temp1[3] = iso8583RxMsg.F12n06_uc7TrxnTime[2];
	temp1[4] = iso8583RxMsg.F12n06_uc7TrxnTime[3];
	temp1[5] = ':';
	temp1[6] = iso8583RxMsg.F12n06_uc7TrxnTime[4];
	temp1[7] = iso8583RxMsg.F12n06_uc7TrxnTime[5];
	temp1[8] = 0x00;
	sprintf(temp, "%s %s,%02X%02X[%s]",
			Month12[i-1], &iso8583RxMsg.F13n04_uc5TrxnDate[2], RealTime.CLKYEARH, RealTime.CLKYEARL, temp1);
	n = FormatPrtText(n, NULL, (char *)&temp,  32);
	
	n = FormatPrtText(n, (char *)&"Ref# :", (char *)&iso8583RxMsg.F37a12_uc13RRN[0],  12);
	n = FormatPrtText(n, (char *)&"App# :", (char *)&iso8583RxMsg.F38a06_uc7AuthCode[0],  6);
	n++;
	
	sprintf((char *)&temp[0], "%.0lf", dAmount);
	InsertDOTorComma((char *)&temp[0], '.', ',');
	n = FormatPrtText(n, (char *)&"Total:", (char *)&c65DotorCommaString[0],  16|PRF_W2X);
	
	n += 2;
	n = FormatPrtText(n, (char *)&"Sign :", (char *)&"X                        ",  25|PRF_BAR);
	n++;
	
	if (!st_Setup.cComDevice) {
		if (st_Setup.cSyncMode)
			n = FormatPrtText(n, NULL, "COMM Mode = Sync", 32);
		else
			n = FormatPrtText(n, NULL, "COMM Mode = Async", 32);
	}
	else
		n = FormatPrtText(n, NULL, "COMM Mode = LAN", 32);
	
	sprintf(temp, "Test OK Count    = %d", usCOMSuccessCnt);
	n = FormatPrtText(n, NULL, temp, 32);
	sprintf(temp, "Total Test Count = %d", usCOMTotalCnt);
	n = FormatPrtText(n, NULL, temp, 32);
	n++;
    
	n = FormatPrtFoot(n);
	
	PrintSetFF(n);
}

short FormatPrtHead(short noLine)
{
	short i, j;
	
	/*
    	: set up 1 to 36 data for form of printing sheet
		: (default : 33 )
		: accept 1 to 150 data for one page basis printing
	*/
	/*
	SET_FORMFEED(PRT_LPP);
	*/
	noLine++;
	noLine = FormatPrtText(noLine, NULL, "3.COMM Test", 32|PRF_W2X);
	noLine++;
	
	noLine = FormatPrtText(noLine, NULL, (char *)&"Credit Card", 16|PRF_W2X);
	noLine++;
	noLine = FormatPrtText(noLine, (char *)&"TID  :", (char *)&iso8583TxMsg.F41a08_uc9TerminalID,  8);
	noLine = FormatPrtText(noLine, (char *)&"MID  :", (char *)&iso8583TxMsg.F42a15_uc16MerchantID, 15);
	
	return (noLine);
}

short FormatPrtFoot(short n)
{
	short i, j;
	
	n++;
	n++;
	
	pGrBuf = (char *)&gbGrBuf[0];
	memset(pGrBuf, 0x00, sizeof(gbGrBuf));
	/*
		void ASSIGN_GRAPHICS(char* , char or int);
		: Address point input for graphics data  
		: assign graphics data to 0 to 4 number to handle for printing
	*/
	ASSIGN_GRAPHICS(pGrBuf , 0);
	ATTB_BUFFER1[0][n][0] = 0x40;
	
	/*  384 Pixels */
	pGrBuf[0] = 0x01;
	pGrBuf[1] = 0x80;
	//pGrBuf[2] = [2];
	pGrBuf[3] = SudanLogo[3];
	pGrBuf += 4;
	j = 0;
	i = 4;
	while (i < sizeof(SudanLogo)) {
		if ((j % PRT_BPL) == 0)
			j += 0x20;
		pGrBuf[j++] = SudanLogo[i++] ^ 0xFF;
	}
	pGrBuf += j;
	
	n = FormatPrtText(n, NULL, (char *)&"http://www.bitel.co.kr", 32);
	
	return (n);
}

void PrintSetFF(short noLine)
{
	short line;
	
	line = noLine + 6;
	SET_FORMFEED(line);
}

short FormatPrtText(short noL, char *msg, char *str, short attr)
{
	short i, j, k;
	char *tPtr;
	
	tPtr = (char *)&CHAR_BUFFER1[0];
	tPtr += (noL*PRT_CPL);
	noL++;
	
	if (msg != NULL) {
		i = strlen(msg);
		if (i > 16)
			i = 16;		/* Max Length of msg_tbl1[][] */
		k = PRT_CPL - i;
		for (j = 0; j < i; j++)
			tPtr[k++] = msg[j];
	}
	
	i = strlen(str);
	if (i <= 0)
		return (noL);
	
	k = attr & 0x00FF;
	if (k) {			/* MAX LEN */
        if (i > k)
        	i = k;
	}
	if ((attr & PRF_W2X) == PRF_W2X) {
		for (k = i, j = 0; k > 0; k--) {
			tPtr[j++] = *str;
			tPtr[j++] = ' ';
			i++;
			str++;
		}
		memset((char *)&tPtr[5*36*32], 0x20, i);
	}
	else {
		memcpy(tPtr, str, i);
		if ((attr & PRF_BAR) == PRF_BAR)
			memset((char *)&tPtr[5*36*32], 0x10, i);
	}
	noL += ((i-1)/PRT_CPL);
	
	return (noL);
}

/*============================================================================================
								Self Test Sub-Routines
============================================================================================*/
void PrintSelfTest(short index)
{
	short i, j, n;
	char str[33], temp[33];
	float ver;
	
	n = 0;
	n++;
	switch (*uspServiceAddr) {
		case 0x1100:	/* System Test */
			n = FormatPrtText(n, NULL, "1. System Test", 32|PRF_W2X);
			n++;
			
			if (!iRTCTestErrFlag)
				n = FormatPrtText(n, NULL, "1.RTC    Test            - OK", 32);
			else
				n = FormatPrtText(n, NULL, "1.RTC    Test              - NG", 32);
			
			n = FormatPrtText(n, NULL, "2.COM Port Test", 32);
			if (!iDownloadComPortTestErrFlag)
				n = FormatPrtText(n, NULL, "  1)Download Port        - OK", 32);
			else
				n = FormatPrtText(n, NULL, "  1)Download Port          - NG", 32);
#ifdef BITEL_IC3100P
			if (!iSerial2ComPortTestErrFlag)
				n = FormatPrtText(n, NULL, "  2)Serial2 Port         - OK", 32);
			else
				n = FormatPrtText(n, NULL, "  2)Serial2 Port           - NG", 32);
#endif
			PrintSetFF(n);
			break;
			
		case 0x1211:	/* LCDKEY Test - LCD Dot Test */
		case 0x1212:	/* LCDKEY Test - LCD Contrast Test */
		case 0x1213:	/* LCDKEY Test - LCD BackLinght & Buzzer Test */
		case 0x1214:	/* LCDKEY Test - Key Test */
			n = FormatPrtText(n, NULL, "2-1.LCD/KEY Test", 32|PRF_W2X);
			n++;
			
			if (!sLCDDotTestErrFlag)
				n = FormatPrtText(n, NULL, "1.LCD Dot Test           - OK", 32);
			else
				n = FormatPrtText(n, NULL, "1.LCD Dot Test             - NG", 32);
				
			if (!sLCDContrastTestErrFlag)
				n = FormatPrtText(n, NULL, "2.LCD Contrast           - OK", 32);
			else
				n = FormatPrtText(n, NULL, "2.LCD Contrast             - NG", 32);
			
			if (!sLCDBackLightTestErrFlag)
				n = FormatPrtText(n, NULL, "3-1.LCD Back Light       - OK", 32);
			else
				n = FormatPrtText(n, NULL, "3-1.LCD Back Light         - NG", 32);
			
			if (!sBuzzerTestErrFlag)
				n = FormatPrtText(n, NULL, "3-2.Buzzer Test          - OK", 32);
			else
				n = FormatPrtText(n, NULL, "3-2.Buzzer Test            - NG", 32);
			
			if (!sKEYTestErrFlag)
				n = FormatPrtText(n, NULL, "4.KEY Test               - OK", 32);
			else
				n = FormatPrtText(n, NULL, "4.KEY Test                 - NG", 32);
			
			PrintSetFF(n);
			break;
			
		case 0x0390:	/* Printer Test */
			PrintSDKtest(sPrintPage,&receipt);
			break;
			case 0x0790:	/* Printer Test */
			PrintSDKtest(sPrintPage,&receipt);
			break;
		case 0x1231:	/* MSR Track Test */
			n = FormatPrtText(n, NULL, "2-3.MSR Test", 32|PRF_W2X);
			n++;
			
			if (sMSRErrFlag) {
				n = FormatPrtText(n, NULL, " MSR Error !!", 32);
				if (!sMSRTrack1or3ErrFlag) {
					if (st_Setup.cMSRTrack3 == 0)
						n = FormatPrtText(n, NULL, " Track 1                   - ?? ", 32);
					else
						n = FormatPrtText(n, NULL, " Track 3                   - ?? ", 32);
					n = FormatPrtText(n, NULL, " Track 2                   - ?? ", 32);
				}
				else {
					if (st_Setup.cMSRTrack3 == 0)
						n = FormatPrtText(n, NULL, " Track 1                   - NG ", 32);
					else
						n = FormatPrtText(n, NULL, " Track 3                   - NG ", 32);
					n = FormatPrtText(n, NULL, " Track 2                   - NG ", 32);
				}
			}
			else {
				if (sMSRTrack1or3ErrFlag) {
					if (st_Setup.cMSRTrack3 == 0)
						n = FormatPrtText(n, NULL, " Track 1                   - NG ", 32);
					else
						n = FormatPrtText(n, NULL, " Track 3                   - NG ", 32);
				}
				else {
					if (st_Setup.cMSRTrack3 == 0)
						n = FormatPrtText(n, NULL, " Track 1                 - OK ", 32);
					else
						n = FormatPrtText(n, NULL, " Track 3                 - OK ", 32);
				}
				
				memset(temp, 0x00, sizeof(temp));
				strncpy(temp, &CardNo1[1], 16);
				sprintf(str, " Card No : %s", temp);
				n = FormatPrtText(n, NULL, str, 32);
				
				if (sMSRTrack2ErrFlag)
					n = FormatPrtText(n, NULL, " Track 2                   - NG ", 32);
				else
					n = FormatPrtText(n, NULL, " Track 2                 - OK ", 32);
					
				memset(temp, 0x00, sizeof(temp));
				strncpy(temp, &CardNo2[1], 16);
				sprintf(str, " Card No : %s", temp);
				n = FormatPrtText(n, NULL, str, 32);
			}
			
			PrintSetFF(n);
			break;
			
		case 0x1240:	/* IC CARD Test */
			n = FormatPrtText(n, NULL, "2-4.IC Card Test", 32|PRF_W2X);
			n++;
			
			if (iICCardModuleTestErrFlag)
				n = FormatPrtText(n, NULL, "1.IC Card Module Test      - NG", 32);
			else {
				n = FormatPrtText(n, NULL, "1.IC Card Module Test    - OK", 32);
				memset(temp, 0x00, sizeof(temp));
				sprintf(temp, "  Ver:%s", BitelTLVer);
				n = FormatPrtText(n, NULL, temp, strlen(temp));
				
				if (iICCardTestErrFlag[0] == 0)
					n = FormatPrtText(n, NULL, "2.Found IC Card          - OK", 32);
				else if (iICCardTestErrFlag[0] == 1)
					n = FormatPrtText(n, NULL, "2.Not Found IC Card        - NG", 32);
				else
					n = FormatPrtText(n, NULL, "2.Error IC Card            - NG", 32);
				
				if (iICCardTestErrFlag[1] == 0)
					n = FormatPrtText(n, NULL, "3.Found SAM1 Card        - OK", 32);
				else if (iICCardTestErrFlag[1] == 1)
					n = FormatPrtText(n, NULL, "3.Not Found SAM1 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "3.Error SAM1 Card          - NG", 32);
					
				if (iICCardTestErrFlag[2] == 0)
					n = FormatPrtText(n, NULL, "4.Found SAM2 Card        - OK", 32);
				else if (iICCardTestErrFlag[2] == 1)
					n = FormatPrtText(n, NULL, "4.Not Found SAM2 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "4.Error SAM2 Card          - NG", 32);
					
#ifndef BITEL_IC5100P
				if (iICCardTestErrFlag[3] == 0)
					n = FormatPrtText(n, NULL, "5.Found SAM3 Card        - OK", 32);
				else if (iICCardTestErrFlag[3] == 1)
					n = FormatPrtText(n, NULL, "5.Not Found SAM3 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "5.Error SAM3 Card          - NG", 32);
					
				if (iICCardTestErrFlag[4] == 0)
					n = FormatPrtText(n, NULL, "6.Found SAM4 Card        - OK", 32);
				else if (iICCardTestErrFlag[4] == 1)
					n = FormatPrtText(n, NULL, "6.Not Found SAM4 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "6.Error SAM4 Card          - NG", 32);
#else
				if (iICCardTestErrFlag[3] == 0)
					n = FormatPrtText(n, NULL, "5.Found SIM1 Card        - OK", 32);
				else if (iICCardTestErrFlag[3] == 1)
					n = FormatPrtText(n, NULL, "5.Not Found SIM1 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "5.Error SIM1 Card          - NG", 32);
					
				if (iICCardTestErrFlag[4] == 0)
					n = FormatPrtText(n, NULL, "6.Found SIM2 Card        - OK", 32);
				else if (iICCardTestErrFlag[4] == 1)
					n = FormatPrtText(n, NULL, "6.Not Found SIM2 Card      - NG", 32);
				else
					n = FormatPrtText(n, NULL, "6.Error SIM2 Card          - NG", 32);
#endif
			}
			
			PrintSetFF(n);
			break;
	}
}

void PrintEMITest(short index)
{
	short i, n;
	
	n = 0;
	n = FormatPrtText(n, NULL, "H H H H H H H H H H H H H H H H ", 32);
	
	SET_FORMFEED(n);
}

/* */
