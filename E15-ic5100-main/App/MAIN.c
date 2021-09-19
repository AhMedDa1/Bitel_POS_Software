
#include "system.h"
#include "extern.h"

unsigned char *RxPtr, *rxptr, *txptr, RxStream[2048], TxStream[2048];

#define USER_DEBUG 1

const char tbl_ProgramVersion[17] = {
	TEST_VERSION
};


void HyperClose( void )
{
//if (!HyperProcess) return;

//HyperProcess = 0;
	DTR_HIGH();
	Wait1MS(500);
	DTR_LOW();
	Wait1MS(1000);

	CONTROL_POWER_SAVING_STATUS(P_EXT_SERIAL, OFF);
	CONTROL_POWER_SAVING_STATUS(P_RF_MODULE, OFF);

}



int main(void);

/* Program(C/C++) starts from here. */
int main(void)
{
	int i, j, key;
	char temp[17];
	unsigned char ch;
	char *ptr;
	
	// Set the fonts for LCD and Print
	USE_LCDFONT((char *)&OtherLcdFont[0], ON);
	USE_PRTFONT((char *)&OtherPrtFont[0], ON);
	
	// LCD Contrast
	LCD_CONT(26);
	// LCD Icons off
//	LCDIconAllOnOff(1);
//	Wait1MS(1000);
	LCDIconAllOnOff(0);

	
	/* 	"Version         ","SUDAN_E15       ", TEST_VERSION, "AUG 21, 2017    " */
	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4SYSCHK1);


	i =   (&RealTime, 0);
	if (i == 0) {
#ifdef USER_DEBUG
		Rprintf("RTC date or time is wrong!\r\n");
#endif
		InitializeRTCDateTime();
	}

	DisplayDate(&RealTime);
	ICON_DISPLAY(CLOCK_COLON_ON);
	ICON_CLOCK_DISPLAY(&RealTime.CLKHOUR);
	
	LCD_ON();
	BACK_ONOFF(ON);
	ucLCDBacklightOnFlag = 1;
	usLCDBackLightOnTimer = Get10MSTimer();
	
	BeepEnable();
	BeepDisable();
	Beep(OK_TONE1);
	WaitKeyPress10MS(500);
	
	SET_BUFFER_SIZE_8K();
	SAVE_PRINT_KEY(BTKEY_UPARROW);

	/* for debugging */
#ifdef USER_DEBUG
	EnableDebugOutput();
	SetDebugPort(COM0, BPS19200, NONE8BIT, STOP1BIT);
	Rprintf("main=%08lX\r\n", (long)&main);
#endif
	
	LoadSetup();

	TRACK_SETUP(st_Setup.cMSRTrack3);	/* 0=1&2, else 2&3 */
	
	sHiSpeedModemTaskStep = -1;
	sTcpProcessStep = -1;
	ucCurrencyExp = 0;
	sLCDContrast = 26;
	sPRTDensity = 10;

	//Test_iso8583();
	//KeyCodeTest();
	
	cDTEPortNo = 0;
	cDTEBaudrate = 4;
	cDCEPortNo = 1;
	cDCEBaudrate = 4;
	cSIMSlotNo = 0;
	
	InitFCS16();
	
	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST1);
	WaitKeyPress10MS(200);
	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST2);
	ModemInit(0);
	//ModemWrite("AT+CPIN?\r\n");
	//Wait1MS(2000);
	//MSRTest();
	SelectOperator();
	
	SetInitialStatus();
//		HyperClose();
//	MSRTest();
	while (1) {
		KeyTask();
		ScrollTask();
		RTCTask();
//		ModemTask();
		PrintTask();
	}
	
	return 0;
}

/* */
