
typedef enum
{
	/* "                ", "                ", "                ", "                " */
	M4__SPACE = 0x0000,
	
	/********************************************/
	/*				System Message				*/
	/********************************************/
	/* 	"Version         ","SUDAN_E15       ", TEST_VERSION, "AUG 21, 2017    " */
	M4SYSCHK1,
	
	/********************************************/
	/*				Initial Status				*/
	/********************************************/
	/* "                ", "Licenced to     ", "                ", "ASHRAFCOM       " */
	M4INITST1,
	/* "                ", "                ", "Configure Port  ", "                " */
	M4INITST2,
	/* "Please Wait...  ", "Select Operator ", "                ", "                " */
	M4INITST3,
	/* "Please Wait...  ", "GPRS            ", "INITIALIZATION  ", "                " */
	M4INITST4,
		
	/********************************************/
	/*				Main Menu        			*/
	/********************************************/
	/* "    MAIN MENU   ", "1 Online Mode   ", "2 Offline Mode  ", "3 Language      " */
	M4MAINM01,
	
	/********************************************/
	/*				ONLINE MODE        			*/
	/********************************************/	
	/* "  ONLINE MODE   ", "1 Login         ", "2 Receipt       ", "3 Invoice       " */
	M4ONLINE1,				
	
	/********************************************/
	/*				OFFLINE MODE        		*/
	/********************************************/		
	/* "  OFFLINE MODE  ", "1 Login         ", "2 Receipt       ", "3 Upload        " */
	M4FFLINE1,				
	
	/********************************************/
	/*				LANGUAGE            		*/
	/********************************************/	
	/* "    LANGUAGE    ", "1 Arabic        ", "2 English       ", "                " */	
	M4LANGAG1,				
	
	/********************************************/
	/*				SETTINGS            		*/
	/********************************************/
	/* "    SETTINGS    ", "1 Date and Time ", "2 Terminal data ", "3 GPRS Providers" */
	M4SETING1,	
	M4NE00000,
	/********************************************/
	/*				ONLINE RECEIPT     			*/
	/********************************************/	
	/* " ONLINE RECEIPT ", "1 Add Receipt   ", "2 Print Receipt ", "3 Summary Report" */
	M4ORECT01,
		
	/********************************************/
	/*				ONLINE INVOICE     			*/
	/********************************************/
	/* " ONLINE INVOICE ", "1 Issue Invoice ", "2 Check Invoice ", "3 Print Invoice " */
	M4OINVC01,				
	
	M4DATET00,
	M4SERIP03,
	
	M4PTNOO03,
	/********************************************/
	/*				ONLINE E-Payment  			*/
	/********************************************/
	/* "ONLINE E-Payment", "1 Check Invoice ", "2 Print Invoice ", "3 Pay Invoice   " */
	M4OSDAD01,
	
	/********************************************/
	/*				OFFLINE RECEIPT    			*/
	/********************************************/	
	/* "OFFLINE RECEIPT ", "1 Add Receipt   ", "2 Print Receipt ", "3 Summary Report" */
	M4FRECT01,
	
	/********************************************/
	/*				GPRS Providers    			*/
	/********************************************/	
	/* "GPRS PROVIDERS  ", "1 Sudani        ", "2 Zain          ", "3 MTN           " */
	M4GPRSPR1,		
	M4GPRSPR2,				
	
	/********************************************/
	/*				LogIn            			*/
	/********************************************/
	/* "User Name       ", "Enter UserName: ", "                ", "                " */
	M4LOGIN01,
	/* "Merchant Password","Enter Password: ", "                ", "                " */
	M4LOGIN02,
	/* "Please Wait...  ", "Connect to      ", "Server          ", "                " */
	M4LOGIN03,
	/* "Please Wait...  ", "RESPONE         ", "                ", "                " */
	M4LOGIN04,
	/* "                ", "Login Failed    ", "                ", "                " */
	M4LOGIN05,
	/* "                ", "Login Successfully", "                ", "                " */
	M4LOGIN06,
	/* "                ", "Please Login    ", "                ", "                " */
	M4LOGIN07,
	/* "Error Code:     ", "AUTHENTICATION  ", "FAILURE         " , "                "*/
	M4LOGIN08,


M4LOGIN14,
M4SET4201,
M4REC0000,	
M4REP0001,
M4PRTN000,
M4PRTN001,
M4PRTN002,
		M4OINVC04,				/* "الخدمات", */
		M4SET1093,				/* "القيمة المضافة  ", */
		M4WAYYY02,				/* "طريقة السداد", */
		M4AAYYY05,				/*اسم المسدد ", */
		M4SET2006,				/* "نوع الهوية    ", */
		M4SET2011,				/* "رقم الهوية ", */
		M4SET4001,				/* " ملاحظات ", */
M4PRINTIN,
M4MONN111,
	M4SERVER_IP,//" SERVER IP     ",
	M4PORT_NO,//" PORT NO       ",
	M4USERNAME,//" USERNAME      ",
	M4PASSWORD,//" PASSWORD      ",
	M4APN,//"    APN        ",
	M4PHONE_NO,//" PHONE NO      ",
	M4SWIPE_CARD,//" SWIPE CARD    ",
	M4ENTER_PIN,///" ENTER PIN     ",
    M4CONNECTING,///	" CONNECTING--> ",
	M4INVOICE_NO,//" INVOICE NO    ",
	M4OLD_PIN,//" OLD PIN       ",
	M4NEW_PIN,//" NEW PIN       ",
	M4TERMIANL_ID,//" TERMIANL ID   ",
	//"         ",

	
	/* " <Modem Setup>  ", "2.PSTN          ", "3.LAN           ", "                " */
	
	
	M4__DUMMY = 0xFFFF
} _eMsg4;

/* */
