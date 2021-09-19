
/* FLASH.H */

typedef struct t_st_Setup {
	short sPrefix;							/* 0 */
	
	char cComDevice;						/* 2 */
	
	char cPABXUse;							/* 3 */
	char sz6PABXCode[6];					/* 4 */
	char sz17TelNo[17];						/* 10 */
	unsigned char ucDialingTimeout;			/* 27 */
	unsigned char ucCommTimeout;			/* 28 */
	char cModemSpeed;						/* 29 */
	char cSyncMode;							/* 30 */
	char cBellMode;							/* 31 */
	char cBlindMode;						/* 32 */
	char cPulseDial;						/* 33 */
	
	char cMSRTrack3;						/* 34 */
	
	char cLANComPort;						/* 35 */
	char sz16LocalIP[16];					/* 36 */
	char sz16SubnetMask[16];				/* 52 */
	char sz16Gateway[16];					/* 68 */
	char sz6LocalPort[6];					/* 84 */
	char sz5TimeOut[5];						/* 90 */
	char sz16ServerIP[16];					/* 95 */
	char sz6ServerPort[6];					/* 111 */
	
	char sz3CountryCode[3];					/* 117 */
	
	char Reserved[120];						/* 120 */
	char c16ProgramVersion[16];				/* 240 */
} _st_Setup;


extern _st_Setup stf_Setup, st_Setup;

extern void LoadSetup(void);
extern void InitializeSetup(void);
extern void SaveSetup(char check_mode);
extern int FlashWrite(U08 *pdst, U08 *psrc, long size);


/* */
