
/*======================================================================*/
/*																		*/
/*								PRINT.H									*/
/*																		*/
/*======================================================================*/

extern short sPrintStep, sPrintPage, sPrintErrFlag;
extern char gbGrBuf[65536];

extern unsigned short usEMITestWaitingTimer;


extern void PrintTask(void);
extern short SelectPrintPage(void);
extern void posPrinterInit(void);
extern void PrintSDKtest(short index,void* parguments);
extern void PrintReceipt(short index);
extern short FormatPrtHead(short noLine);
extern short FormatPrtFoot(short noLine);
extern void PrintSetFF(short noLine);
extern short FormatPrtText(short noL, char *msg, char *str, short attr);
extern char* convertEncoding(char *strii);
extern void PrintSelfTest(short index);
void PrintSDKRECIET(short index);
extern void PrintEMITest(short index);

/* */
