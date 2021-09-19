
typedef enum
{
	M1__SPACE = 0x0000,		/* "                ", */
	
	/********************************************/
	/*				System Message				*/
	/********************************************/
	M1SYSCHK1,				/* "Version         ", */
	M1SYSCHK2,				/* "SUDAN_E15       ", */
	M1SYSCHK3,				/* TEST_VERSION, */
	
	/********************************************/
	/*				Initial Status				*/
	/********************************************/
	M1INITST1,				/* "Licenced to     ", */	
	M1INITST2, 				/* "ASHRAFCOM       ", */
	M1INITST3, 				/* "Configure Port  ", */
	M1INITST4,				/* " Please Wait... ", */
	M1INITST5,				/* "Select Operator ", */
	M1INITST6,				/* "GPRS 			", */
	M1INITST7,				/* "INITIALIZATION  ", */
	
	/********************************************/
	/*				Main Menu        			*/
	/********************************************/
	M1MAINM00,				/* "   MAIN MENU    ", */
	M1MAINM01,				/* "1 LOGIN   ", */
	M1MAINM02,				/* "2 SETTING  ", */
	M1MAINM03,				/* "3 LANGUAGE ", */
	M1MAINM04,				/* "4 operation Mode  ", */
	M1MAINM05,				/* "5 pay invoice", */
	M1MAINM06,				/* "6 Account Type      ", */
			        
	
	/********************************************/
	/*				ONLINE MODE        			*/
	/********************************************/

	M1ONLINE0,				/* "  MAIN MENU  ", */
	M1ONLINE1,				/* "/* "1 issue receipt   ", */
	M1ONLINE2,				/* "2 Get receipt  ", */
	M1ONLINE3,				/* "3 Cancel receipt ", */
	M1ONLINE4,				/* "4 update service  ", */
	M1ONLINE5,				/* "5 upload ", */
	M1ONLINE6,				/* "6 ornic 67      ", */	
	M1ONLINE7,				/* "7 Other Services      ", */
	M1ONLINE8,              /* "8 Log Out" */	

	/********************************************/
	/*				OFFLINE MODE        		*/
	/********************************************/		
	M1FFLINE0,				/* "  OFFLINE MODE  ", */
	M1FFLINE1,				/* "1 Login         ", */
	M1FFLINE2,				/* "2 Receipt       ", */
	M1FFLINE3,				/* "3 Upload        ", */
	M1FFLINE4,				/* "4 Get Updates   ", */
    M1FFLINE5,
    M1FFLINE6,
    M1FFLINE7,
    M1FFLINE8,
	/********************************************/
	/*				LANGUAGE            		*/
	/********************************************/		
	M1LANGAG0,				/* "    LANGUAGE    ", */
	M1LANGAG1,				/* "1 Arabic        ", */
	M1LANGAG2,				/* "2 English        " */
				


	/********************************************/
	/*				SETTINGS            		*/
	/********************************************/		
	M1SETING0,				/* "    SETTINGS    ", */
	M1SETING1,				/* "1 Date and Time ", */
	M1SETING2,				/* "2 Change Password  ", */
	M1SETING3,				/* "3 Working Key", */
	M1SETING4,				/* "4 Terminal ID    ", */
	M1SETING5,				/* "5 E15 Server    ", */
	M1SETING6,				/* "6 EBS Server", */
	M1SETING7,				/* "7 Upload Batch Size ", */
	M1SETING8,              /* "8 fail Receipts    ", */
	M1SETING9,              /* "9 Reset Factory    ", */
	
	
	
	M1NEWPAS0,
	/********************************************/
	/*				ONLINE RECEIPT     			*/
	/********************************************/	
	M1ORECT00,				/* " ONLINE RECEIPT ", */
	M1ORECT01,				/* "1 Add Receipt   ", */
	M1ORECT02,				/* "2 Print Receipt ", */
	M1ORECT03,				/* "3 Summary Report", */
	M1ORECT04,				/* "4 Detail Report ", */
	M1ORECT05,				/* "5 Cancel Receipt", */
	M1ORECT06,				/* "6 Check Ornic67 ", */
	M1ORECT07,				/* "7 Generate Ornic", */		
	M1ORECT08,
	M1ORECT09,
	M1ORECT10,
	M1ORECT11,
	M1ORECT12,
	M1ORECT13,
	M1ORECT14,
	M1ORECT15,
	M1ORECT16,		
	/********************************************/
	/*				ONLINE INVOICE     			*/
	/********************************************/
	M1OINVC00,				/* " ONLINE INVOICE ", */
	M1OINVC01,				/* "1 Issue Invoice ", */
	M1OINVC02,				/* "2 Check Invoice ", */
	M1OINVC03,				/* "3 Print Invoice ", */
	M1OINVC04,				/* "4 Cancel Invoice", */
	M1OINVC05,				/* "5 Pay Invoice   ", */
	
	
	M1DATET00,
	M1DATET02,
	M1DATET03,
	
	M1SERIP03,
	
	M1PTNOO03,
	
	/********************************************/
	/*				ONLINE E-Payment  			*/
	/********************************************/
	M1OSDAD00,				/* "ONLINE E-Payment", */
	M1OSDAD01,				/* "1 Check Invoice ", */
	M1OSDAD02,				/* "2 Print Invoice ", */
	M1OSDAD03,				/* "3 Pay Invoice   ", */
	M1OSDAD04,
	M1OSDAD05,
	M1OSDAD06,
	M1OSDAD07,
	
	
	
	/********************************************/
	/*				OFFLINE RECEIPT    			*/
	/********************************************/	
	M1FRECT00,				/* "OFFLINE RECEIPT ", */
	M1FRECT01,				/* "1 Add Receipt   ", */
	M1FRECT02,				/* "2 Print Receipt ", */
	M1FRECT03,				/* "3 Summary Report", */
	M1FRECT04,				/* "4 Detail Report ", */
	M1FRECT05,				/* "5 Generate Ornic", */	

	/********************************************/
	/*				GPRS PROVIDERS   			*/
	/********************************************/	
	M1GPRSPR0,				/* "GPRS PROVIDERS  ", */
	M1GPRSPR1,				/* "1 Sudani        ", */
	M1GPRSPR2,				/* "2 Zain          ", */
	M1GPRSPR3,				/* "3 MTN           ", */	
	
	/********************************************/
	/*				Login In          			*/
	/********************************************/	
	M1LOGIN01,				/* "User Name       ", */	
	M1LOGIN02,				/* "Enter UserName: ", */
	M1LOGIN03,				/* "Merchant Password", */
	M1LOGIN04,				/* "Enter Password: ", */
	M1LOGIN05,				/* "Connect to      ", */
	M1LOGIN06,				/* "Server          ", */
	M1LOGIN07,				/* "RESPONSE        ", */
	M1LOGIN08,				/* "Login Failed    ", */
	M1LOGIN09,				/* "Login Successfully", */
	M1LOGIN10,				/* "Please Login    ", */
	M1LOGIN11,				/* "Error Code:     ", */
	M1LOGIN12,				/* "AUTHENTICATION  ", */
	M1LOGIN13,				/* "FAILURE         ", */
	
	
    M1LOGIN14,
	M1SET4201,				/* " Set Date&Time  ", */
	M1SET4202,				/* "  YYYYMMDDhhmmss", */
	M1SET4203,
	
	M1REC0000,
	
	M1REP0000,
    M1REP0001,
    M1REP0002,
    
    M1PRTN000,
    M1PRTN001,
    M1PRTN002,

	M1OINVC04,				/* "ØÿÙ„ØÿØÿÙ…ØÿØÿ", */
	M1OINVC05,				/* "ØÿØÿØÿÙØÿ ØÿÙ„Ù…ØÿÙŠØÿ ", */
	M1SET1092,				/* "Ù…ÙˆØÿØÿÙ„Øÿ ØÿÙ„ØÿØÿØÿØÿ ", */
		
	
	M1SET1093,				/* "ØÿÙ„Ù‚ÙŠÙ…Øÿ ØÿÙ„Ù…ØÿØÿÙØÿ  ", */
	M1SET1101,				/* "Ù†ØÿÙ…   ", */
	M1SET2001,				/* "Ù„Øÿ", */
	
	M1WAYYY02,				/* "ØÿØÿÙŠÙ‚Øÿ ØÿÙ„ØÿØÿØÿØÿ", */
	M1WAYYY03,				/* "Ù†Ù‚Øÿ ", */
	M1WAYYY04,				/* "ØÿÙŠÙƒ     ", */
	
	M1AAYYY05,				/*ØÿØÿÙ… ØÿÙ„Ù…ØÿØÿØÿ ", */
	
	M1SET2006,				/* "Ù†ÙˆØÿ ØÿÙ„Ù‡ÙˆÙŠØÿ    ", */
	M1SET2007,				/* "Ø¬ÙˆØÿØÿ ØÿÙØÿ  ", */
	M1SET2008,				/* "ØÿÙ‚Ù… ÙˆØÿÙ†ÙŠ   ", */
	M1SET2009,				/* "ØÿØÿØÿÙ‚Øÿ Ù‚ÙˆÙ…ÙŠØÿ    ", */
	M1SET2010,				/* "ØÿØÿØÿÙ‚Øÿ ØÿØÿØÿÙŠØÿ ", */
	
	
	M1SET2011,				/* "ØÿÙ‚Ù… ØÿÙ„Ù‡ÙˆÙŠØÿ ", */
	
	M1SET4001,				/* " Ù…Ù„ØÿØ­ØÿØÿØÿ ", */
	M1PRINTIN,
	M1MONN111,
	M1SERVER_IP,//" SERVER IP     ",
	M1PORT_NO,//" PORT NO       ",
	M1USERNAME,//" USERNAME      ",
	M1PASSWORD,//" PASSWORD      ",
	M1APN,//"    APN        ",
	M1PHONE_NO,//" PHONE NO      ",
	M1SWIPE_CARD,//" SWIPE CARD    ",
	M1ENTER_PIN,///" ENTER PIN     ",
    M1CONNECTING,///	" CONNECTING--> ",
	M1INVOICE_NO,//" INVOICE NO    ",
	M1OLD_PIN,//" OLD PIN       ",
	M1NEW_PIN,//" NEW PIN       ",
	M1TERMIANL_ID,//" TERMIANL ID   ",
	//"         ",
	M1SET4002,				/* "2.Set MSR Track ", */
	M1SET4003,				/* "3.LCD Contrast  ", */
	M1SET4004,				/* "4.PRT Density   ", */
	
	M1SET4101,				/* "Set MSR Track   ", */
	M1SET4102,				/* "2. Track 1 & 2  ", */
	M1SET4103,				/* "3. Track 2 & 3  ", */
	
	M1SET4201,				/* "LCD Contrast    ", */
	M1SET4202,				/* "     0 - 63     ", */
	M1SET4203,				/* "1.Light 2.Dark  ", */
	
	M1SET4301,				/* "PRT Density     ", */
	M1SET4302,				/* "     0 - 29     ", */
	
	/********************************************/
	/*				Self Test Message			*/
	/********************************************/
	M1TMENU01,				/* "  <Self Test>   ", */
	M1TMENU02,				/* "Test Menu[0-5] ?", */
	M1TMENU03,				/* "      [ ]       ", */
	M1TMENU10,				/* "Auto Self Test  ", */
	M1TMENU11,				/* "System Test     ", */
	M1TMENU12,				/* "Device Test     ", */
	M1TMENU13,				/* "COMM Test       ", */
	M1TMENU14,				/* "Hyper Terminal  ", */
	M1TMENU15,				/* "CE Approval Test", */
	M1TMENU16,				/* "TMS Test        ", */
	
	M1TDEV001,				/* "1.LCD/KEY   Test", */
	M1TDEV002,				/* "2.Printer   Test", */
	M1TDEV003,				/* "3.MSR Track Test", */
	M1TDEV004,				/* "4.IC Card   Test", */
	
	M1TDLCD01,				/* "1.LCD Dot Test  ", */
	M1TDLCD02,				/* "2.LCD Contrast  ", */
	M1TDLCD03,				/* "3.Back Light/BUZ", */
	M1TDLCD04,				/* "4.KEY Test      ", */
	
	M1TDPRT01,				/* " <Printer Test> ", */
	M1TDPRT02,				/* "Printing Now... ", */
	
	M1TDMSR01,				/* "   <MSR Test>   ", */
	M1TDMSR02,				/* "Swipe Your Card ", */
	
	M1TDIC001,				/* " <IC Card Test> ", */
	M1TDIC002,				/* "Read F/W Version", */
	M1TDIC101,				/* " Select SLOT[ ] ", */
	M1TDIC102,				/* "     0 - 5      ", */
	M1TDIC103,				/* " Card Found OK! ", */
	M1TDIC104,				/* " Card Not Found ", */
	M1TDIC105,				/* "   Card Error   ", */
	
	M1TCOM001,				/* "COMM Test ?     ", */
	M1TCOM002,				/* "2.Manual Test   ", */
	M1TCOM003,				/* "3.Automatic Test", */
	M1TCOM101,				/* "Manual COMM Test", */
	M1TCOM102,				/* "  [    /    ]   ", */
	M1TCOM103,				/* "ENTER OR CANCEL ", */
	M1TCOM201,				/* " Auto COMM Test ", */
	
	M1THYP001,				/* "2.Set DTE(PC)   ", */
	M1THYP002,				/* "3.Set DCE(MODEM)", */
	M1THYP003,				/* "4.Hyper Mode    ", */
	M1THYP011,				/* "Set DTE Port    ", */
	M1THYP012,				/* "2.COM0  3.COM1  ", */
	M1THYP013,				/* "4.COM2  5.COM3  ", */
	M1THYP021,				/* "Set DTE Baudrate", */
	M1THYP022,				/* "2.9600  3.19200 ", */
	M1THYP023,				/* "4.38400 5.57600 ", */
	M1THYP024,				/* "6.115200        ", */
	M1THYP031,				/* "Set DCE Port    ", */
	M1THYP041,				/* "Set DCE Baudrate", */
	M1THYP051,				/* "Set SIM Slot    ", */
	M1THYP052,				/* "2.SIM1          ", */
	M1THYP053,				/* "3.SIM2          ", */
	M1THYP101,				/* "Hyper Mode      ", */
	
	/********************************************/
	/*				Communication				*/
	/********************************************/
	M1COMM001,				/* "  DIALING NOW   ", */
	M1COMM002,				/* " LINE CONNECTED ", */
	M1COMM003,				/* " CONNECTED 1200 ", */
	M1COMM004,				/* " CONNECTED 2400 ", */
	M1COMM005,				/* "   COMM START   ", */
	M1COMM006,				/* "SENDING DATA... ", */
	M1COMM007,				/* "RECEIVING DATA..", */
	M1COMM008,				/* "RESENDING DATA..", */
	
	M1COMM100,				/* "TimeOut(S7)     ", */
	M1COMM101,				/* "No Dial Tone    ", */
	M1COMM102,				/* "Busy            ", */
	M1COMM103,				/* "No Carrier      ", */
	M1COMM104,				/* "Line Error      ", */
	M1COMM105,				/* "COMM TimeOut    ", */
	
	/********************************************/
	/*				CE Approval Test			*/
	/********************************************/
	M1CEMEMU1,				/* "CE APPROVAL TEST", */
	M1CEMEMU2,				/* "2.MODEM TEST    ", */
	M1CEMEMU3,				/* "3.EMI   TEST    ", */
	
	/********************************************/
	/*				Modem Test					*/
	/********************************************/
	M1MODEM01,				/* "  <MODEM TEST>  ", */
	M1MODEM02,				/* "2.COUNTRY SETUP ", */
	M1MODEM03,				/* "3.TEST MENU     ", */
	
	M1MODEM20,				/* "COUNTRY CODE ?  ", */
	M1MODEM21,				/* "    [7 - FE]    ", */
	
	M1MODEM40,				/* "1.DTMF TEST     ", */
	M1MODEM41,				/* "2.ANSWER TONE   ", */
	M1MODEM42,				/* "3.OFF/ON HOOK   ", */
	M1MODEM43,				/* "4.RING DETECTION", */
	
	M1MODEM50,				/* "  <DTMF TEST>   ", */
	M1MODEM51,				/* "2.MANUAL MODE   ", */
	M1MODEM52,				/* "3.AUTO MODE     ", */
	M1MODEM53,				/* " (MANUAL MODE)  ", */
	M1MODEM54,				/* "  (AUTO MODE)   ", */
	M1MODEM55,				/* "GENERATING NOW..", */
	
	M1MODEM60,				/* " <ANSWER TONE>  ", */
	M1MODEM61,				/* "2.2100 Hz       ", */
	M1MODEM62,				/* "3.1300 Hz       ", */
	M1MODEM63,				/* " V.25(2100 Hz)  ", */
	M1MODEM64,				/* " V.25(1300 Hz)  ", */
	
	M1MODEM70,				/* " <ON/OFF HOOK>  ", */
	M1MODEM71,				/* "2.ON HOOK       ", */
	M1MODEM72,				/* "3.OFF HOOK      ", */
	M1MODEM73,				/* "ON  HOOK NOW... ", */
	M1MODEM74,				/* "OFF HOOK NOW... ", */
	
	M1MODEM80,				/* "<RING DETECTION>", */
	M1MODEM81,				/* "RING            ", */
	
	/********************************************/
	/*				EMI Test					*/
	/********************************************/
	M1EMI0001,				/* "   <EMI TEST>   ", */
	M1EMI0002,				/* "PRINTING NOW... ", */
	M1EMI0003,				/* "PRESS CANCEL KEY", */
	M1EMI0004,				/* "   NO PAPER !   ", */
	M1EMI0005,				/* "  INSERT PAPER  ", */
	M1EMI0006,				/* "CANCEL OR ENTER ", */
	
	/********************************************/
	/*				TMS Test					*/
	/********************************************/
	M1TMS0001,				/* "   <TMS TEST>   ", */
	M1TMS0002,				/* "2.PROGRAM DOWN  ", */
	M1TMS0003,				/* "3.PARAMETER DOWN", */
	
	M1__DUMMY = 0xFFFF
} _eMsg1;

/* */
