#include "system.h"
#include "extern.h"

#define USER_DEBUG 1
//#define	TEST_DATA_ADDRESS	0x40100000;
int Tindex, Fpos, ScrProcess;
char tmpnbuf[32];
int sz = 0;
int L = 0;
int result1, result2;
int A = 0;
int E = 1;
int X = 1;
char *stringg;
const unsigned short tbl_MainService[][16] = {
/* Initial Status										- MSS_INITIAL */
{ 0x0000, 0x0001, 0x0002, },
/* Main Menu        									- MSS_MAIN_MENU */
{ 0x0100, },
/* login     											- MSS_LOGIN */
{ 0x0200, 0x0201, 0x0202, 0x0203, 0x0204, 0x0205, }, { 0x0210, 0x0211, 0x0212,
		0x0213, 0x0214, 0x0215, }, { 0x0220, 0x0221, 0x0222, 0x0223, 0x0224,
		0x0225, }, { 0x0230, 0x0231, 0x0232, 0x0233, 0x0234, 0x0235, }, {
		0x0240, 0x0241, 0x0242, 0x0243, 0x0244, 0x0245, }, { 0x0250, 0x0251,
		0x0252, 0x0253, 0x0254, 0x0255, }, { 0x0260, 0x0261, 0x0262, 0x0263,
		0x0264, 0x0265, }, { 0x0270, 0x0271, 0x0272, 0x0273, 0x0274, 0x0275, },
		{ 0x0280, 0x0281, 0x0282, 0x0283, 0x0284, 0x0285, }, { 0x0290, 0x0291,
				0x0292, 0x0293, 0x0294, 0x0295, },

		/* ENTER PASSWORD     									- MSS_FMODE */
		{ 0x0300, 0x0301, 0x0302, 0x0303, 0x0304, 0x0305 }, { 0x0310, 0x0311,
				0x0312, 0x0313, 0x0314, 0x0315, }, { 0x0320, 0x0321, 0x0322,
				0x0323, 0x0324, 0x0325, }, { 0x0330, 0x0331, 0x0332, 0x0333,
				0x0334, 0x0335, }, { 0x0340, 0x0341, 0x0342, 0x0343, 0x0344,
				0x0345, }, { 0x0350, 0x0351, 0x0352, 0x0353, 0x0354, 0x0355, },
		{ 0x0360, 0x0361, 0x0362, 0x0363, 0x0364, 0x0365, }, { 0x0370, 0x0371,
				0x0372, 0x0373, 0x0374, 0x0375, }, { 0x0380, 0x0381, 0x0382,
				0x0383, 0x0384, 0x0385, }, { 0x0390, 0x0391, 0x0392, 0x0393,
				0x0394, 0x0395, },

		/* Language 											- MSS_LANGUAGE */
		{ 0x0400, 0x0401 },
		{ 0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, }, { 0x0420, 0x0421,
				0x0422, 0x0423, 0x0424, 0x0425, }, { 0x0430, 0x0431, 0x0432,
				0x0433, 0x0434, 0x0435, }, { 0x0440, 0x0441, 0x0442, 0x0443,
				0x0444, 0x0445, }, { 0x0450, 0x0451, 0x0452, 0x0453, 0x0454,
				0x0455, }, { 0x0460, 0x0461, 0x0462, 0x0463, 0x0464, 0x0465, },
		{ 0x0470, 0x0471, 0x0472, 0x0473, 0x0474, 0x0475, }, { 0x0480, 0x0481,
				0x0482, 0x0483, 0x0484, 0x0485, }, { 0x0490, 0x0491, 0x0492,
				0x0493, 0x0494, 0x0495, },

		/* Settings 											- MSS_SETTING */
		{ 0x0500, 0x0501, 0x0502, 0x0503, 0x0504, 0x0505, }, { 0x0510, 0x0511,
				0x0512, 0x0513, 0x0514, 0x0515, }, { 0x0520, 0x0521, 0x0522,
				0x0523, 0x0524, 0x0525, }, { 0x0530, 0x0531, 0x0532, 0x0533,
				0x0534, 0x0535, }, { 0x0540, 0x0541, 0x0542, 0x0543, 0x0544,
				0x0545, }, { 0x0550, 0x0551, 0x0552, 0x0553, 0x0554, 0x0555, },
		{ 0x0560, 0x0561, 0x0562, 0x0563, 0x0564, 0x0565, }, { 0x0570, 0x0571,
				0x0572, 0x0573, 0x0574, 0x0575, }, { 0x0580, 0x0581, 0x0582,
				0x0583, 0x0584, 0x0585, }, { 0x0590, 0x0591, 0x0592, 0x0593,
				0x0594, 0x0595, },

		/* Online Receipt										- MSS_ORECEIPT */
		{ 0x0600, 0x0601, 0x0602, 0x0603, }, { 0x0610, 0x0611, 0x0612, 0x0613,
				0x0614, 0x0615, }, { 0x0620, 0x0621, 0x0622, 0x0623, 0x0624,
				0x0625, }, { 0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, },
		{ 0x0640, 0x0641, 0x0642, 0x0643, 0x0644, 0x0645, }, { 0x0650, 0x0651,
				0x0652, 0x0653, 0x0654, 0x0655, }, { 0x0660, 0x0661, 0x0662,
				0x0663, 0x0664, 0x0665, }, { 0x0670, 0x0671, 0x0672, 0x0673,
				0x0674, 0x0675, }, { 0x0680, 0x0681, 0x0682, 0x0683, 0x0684,
				0x0685, }, { 0x0690, 0x0691, 0x0692, 0x0693, 0x0694, 0x0695, },
		/* Online Invoice										- MSS_OINVOICE */
		{ 0x0700, 0x0701, 0x0702, 0x0703, }, { 0x0710, 0x0711, 0x0712, 0x0713,
				0x0714, 0x0715, }, { 0x0720, 0x0721, 0x0722, 0x0723, 0x0724,
				0x0725, }, { 0x0730, 0x0731, 0x0732, 0x0733, 0x0734, 0x0735, },
		{ 0x0740, 0x0741, 0x0742, 0x0743, 0x0744, 0x0745, }, { 0x0750, 0x0751,
				0x0752, 0x0753, 0x0754, 0x0755, }, { 0x0760, 0x0761, 0x0762,
				0x0763, 0x0764, 0x0765, }, { 0x0770, 0x0771, 0x0772, 0x0773,
				0x0774, 0x0775, }, { 0x0780, 0x0781, 0x0782, 0x0783, 0x0784,
				0x0785, }, { 0x0790, 0x0791, 0x0792, 0x0793, 0x0794, 0x0795, },
		/* E-Payment 											- MSS_EPAYMENT */
		{ 0x0800, 0x0801, 0x0802, 0x0803 }, { 0x0810, 0x0811, 0x0812, 0x0813,
				0x0814, 0x0815, }, { 0x0820, 0x0821, 0x0822, 0x0823, 0x0824,
				0x0825, }, { 0x0830, 0x0831, 0x0832, 0x0833, 0x0834, 0x0835, },
		{ 0x0840, 0x0841, 0x0842, 0x0843, 0x0844, 0x0845, }, { 0x0850, 0x0851,
				0x0852, 0x0853, 0x0854, 0x0855, }, { 0x0860, 0x0861, 0x0862,
				0x0863, 0x0864, 0x0865, }, { 0x0870, 0x0871, 0x0872, 0x0873,
				0x0874, 0x0875, }, { 0x0880, 0x0881, 0x0882, 0x0883, 0x0884,
				0x0885, }, { 0x0890, 0x0891, 0x0892, 0x0893, 0x0894, 0x0895, },
		/* Offline Receipt 										- MSS_FRECEIPT */
		{ 0x0900, 0x0901, 0x0902, 0x0903, 0x0904, 0x0905, 0x0906, }, { 0x0910,
				0x0911, 0x0912, 0x0913, 0x0914, 0x0915, }, { 0x0920, 0x0921,
				0x0922, 0x0923, 0x0924, 0x0925, }, { 0x0930, 0x0931, 0x0932,
				0x0933, 0x0934, 0x0935, }, { 0x0940, 0x0941, 0x0942, 0x0943,
				0x0944, 0x0945, }, { 0x0950, 0x0951, 0x0952, 0x0953, 0x0954,
				0x0955, }, { 0x0960, 0x0961, 0x0962, 0x0963, 0x0964, 0x0965, },
		{ 0x0970, 0x0971, 0x0972, 0x0973, 0x0974, 0x0975, }, { 0x0980, 0x0981,
				0x0982, 0x0983, 0x0984, 0x0985, }, { 0x0990, 0x0991, 0x0992,
				0x0993, 0x0994, 0x0995, },
		/* GPRS Providers										- MSS_GPRS */
		{ 0x0A00, 0x0A01, 0x0A02, 0x0A03, }, { 0x0A10, 0x0A11, 0x0A12, 0x0A13,
				0x0A14, 0x0A15, }, { 0x0A20, 0x0A21, 0x0A22, 0x0A23, 0x0A24,
				0x0A25, }, { 0x0A30, 0x0A31, 0x0A32, 0x0A33, 0x0A34, 0x0A35, },
		{ 0x0A40, 0x0A41, 0x0A42, 0x0A43, 0x0A44, 0x0A45, }, { 0x0A50, 0x0A51,
				0x0A52, 0x0A53, 0x0A54, 0x0A55, }, { 0x0A60, 0x0A61, 0x0A62,
				0x0A63, 0x0A64, 0x0A65, }, { 0x0A70, 0x0A71, 0x0A72, 0x0A73,
				0x0A74, 0x0A75, }, { 0x0A80, 0x0A81, 0x0A82, 0x0A83, 0x0A84,
				0x0A85, }, { 0x0A90, 0x0A91, 0x0A92, 0x0A93, 0x0A94, 0x0A95, },
		/*Online Login											- MSS_OLOGIN */
		{ 0x0B00, 0x0B01, 0x0B02, 0x0B03, }, { 0x0B10, 0x0B11, 0x0B12, 0x0B13,
				0x0B14, 0x0B15, }, { 0x0B20, 0x0B21, 0x0B22, 0x0B23, 0x0B24,
				0x0B25, }, { 0x0B30, 0x0B31, 0x0B32, 0x0B33, 0x0B34, 0x0B35, },
		{ 0x0B40, 0x0B41, 0x0B42, 0x0B43, 0x0B44, 0x0B45, }, { 0x0B50, 0x0B51,
				0x0B52, 0x0B53, 0x0B54, 0x0B55, }, { 0x0B60, 0x0B61, 0x0B62,
				0x0B63, 0x0B64, 0x0B65, }, { 0x0B70, 0x0B71, 0x0B72, 0x0B73,
				0x0B74, 0x0B75, }, { 0x0B80, 0x0B81, 0x0B82, 0x0B83, 0x0B84,
				0x0B85, }, { 0x0B90, 0x0B91, 0x0B92, 0x0B93, 0x0B94, 0x0B95, },
		/*Offline Login											- MSS_FLOGIN */
		{ 0x0C00, 0x0C01, 0x0C02, 0x0C03, }, { 0x0C10, 0x0C11, 0x0C12, 0x0C13,
				0x0C14, 0x0C15, }, { 0x0C20, 0x0C21, 0x0C22, 0x0C23, 0x0C24,
				0x0C25, }, { 0x0C30, 0x0C31, 0x0C32, 0x0C33, 0x0C34, 0x0C35, },
		{ 0x0C40, 0x0C41, 0x0C42, 0x0C43, 0x0C44, 0x0C45, }, { 0x0C50, 0x0C51,
				0x0C52, 0x0C53, 0x0C54, 0x0C55, }, { 0x0C60, 0x0C61, 0x0C62,
				0x0C63, 0x0C64, 0x0C65, }, { 0x0C70, 0x0C71, 0x0C72, 0x0C73,
				0x0C74, 0x0C75, }, { 0x0C80, 0x0C81, 0x0C82, 0x0C83, 0x0C84,
				0x0C85, }, { 0x0C90, 0x0C91, 0x0C92, 0x0C93, 0x0C94, 0x0C95, },
		//N
		{ 0x0D00, 0x0D01, 0x0D02, 0x0D03, }, { 0x0D10, 0x0D11, 0x0D12, 0x0D13,
				0x0D14, 0x0D15, }, { 0x0D20, 0x0D21, 0x0D22, 0x0D23, 0x0D24,
				0x0D25, }, { 0x0D30, 0x0D31, 0x0D32, 0x0D33, 0x0D34, 0x0D35, },
		{ 0x0D40, 0x0D41, 0x0D42, 0x0D43, 0x0D44, 0x0D45, }, { 0x0D50, 0x0D51,
				0x0D52, 0x0D53, 0x0D54, 0x0D55, }, { 0x0D60, 0x0D61, 0x0D62,
				0x0D63, 0x0D64, 0x0D65, }, { 0x0D70, 0x0D71, 0x0D72, 0x0D73,
				0x0D74, 0x0D75, }, { 0x0D80, 0x0D81, 0x0D82, 0x0D83, 0x0D84,
				0x0D85, }, { 0x0D90, 0x0D91, 0x0D92, 0x0D93, 0x0D94, 0x0D95, },
		//P
		{ 0x0E00, 0x0E01, 0x0E02, 0x0E03, }, { 0x0E10, 0x0E11, 0x0E12, 0x0E13,
				0x0E14, 0x0E15, }, { 0x0E20, 0x0E21, 0x0E22, 0x0E23, 0x0E24,
				0x0E25, }, { 0x0E30, 0x0E31, 0x0E32, 0x0E33, 0x0E34, 0x0E35, },
		{ 0x0E40, 0x0E41, 0x0E42, 0x0E43, 0x0E44, 0x0E45, },

		{ 0x0E50, 0x0E51, 0x0E52, 0x0E53, 0x0E54, 0x0E55, }, { 0x0E60, 0x0E61,
				0x0E62, 0x0B63, 0x0E64, 0x0E65, }, { 0x0E70, 0x0E71, 0x0E72,
				0x0B73, 0x0E74, 0x0E75, }, { 0x0E80, 0x0E81, 0x0E82, 0x0B83,
				0x0E84, 0x0E85, }, { 0x0E90, 0x0E91, 0x0E92, 0x0B93, 0x0E94,
				0x0E95, },
		//K
		{ 0x0F00, 0x0F01, 0x0F02, 0x0F03, }, { 0x0F10, 0x0F11, 0x0F12, 0x0F13,
				0x0F14, 0x0F15, }, { 0x0F20, 0x0F21, 0x0F22, 0x0F23, 0x0F24,
				0x0F25, }, { 0x0F30, 0x0F31, 0x0F32, 0x0F33, 0x0F34, 0x0F35, },
		{ 0x0F40, 0x0F41, 0x0F42, 0x0F43, 0x0F44, 0x0F45, }, { 0x0F50, 0x0F51,
				0x0F52, 0x0F53, 0x0F54, 0x0F55, }, { 0x0F60, 0x0F61, 0x0F62,
				0x0F63, 0x0F64, 0x0F65, }, { 0x0F70, 0x0F71, 0x0F72, 0x0F73,
				0x0F74, 0x0F75, }, { 0x0F80, 0x0F81, 0x0F82, 0x0F83, 0x0F84,
				0x0F85, }, { 0x0F90, 0x0F91, 0x0F92, 0x0F93, 0x0F94, 0x0F95, },
		{ 0x0FE00, },
//

		};

short sVirtualKey, sTempKey;
short sLCDContrast, sPRTDensity;
short sAutoTestMode, sMainTestMenu, sDeviceTestMenu, sLCDKEYTestMenu,
		sAutoCOMMenu;
unsigned short usCOMTotalCnt, usCOMSuccessCnt;
unsigned short usAutoComTimer;
unsigned short usMainStatus;
unsigned short *uspServiceAddr;
char cDTEPortNo, cDTEBaudrate, cDCEPortNo, cDCEBaudrate, cSIMSlotNo;
char c65TempKeyBuf[65];
char *ptrCountryName;
char *stringg;
char *out = '\0';
char *label;
unsigned int buff_size;
unsigned char buffer[1024];
int test_issue_22(void);

void KeyTask(void);
void KeyService(int key);
void EnterKeyService(void);
void CancelKeyService(void);
void SetInitialStatus(void);
void MainStatusSetting(unsigned short Status, short ServiceTableNo,
		short DisplayMsgNo);
void ErrorDisplaySetting(unsigned short Status, short ServiceTableNo,
		short DisplayMsgNo);
void ErrorDisplayAndGoInitialStatus(unsigned short MsgNo);
void ErrorDisplayAndGoErrorStatus(unsigned short MsgNo);
void DisplayCenterString(char YPos, char *str, int size);
char* convertEncoding(char *label);
void hmac_sha256_get(unsigned char digest[32], const unsigned char *message,
		int message_length, const unsigned char *key, int key_length);
void Dispaly2PullDownMenu(void);
void Dispaly3PullDownMenu(void);
void Dispaly4PullDownMenu(void);
void Dispaly6PullDownMenu(void);
void DispalySelfTestMainMenu(int menu);
int GetCountryName(int country_code, char **country_name);
int GetCountryCode(char *str);
char* convertEncoding(char *label);
void HyperTerminalMode(void);
int key_ypos, Updown;
char user_id[65];
char id_num[65];
char id_type[65];
char *write_f;
char *url;
char *serverip;
char HTTP_REQUEST[8192];
char name_e[65];
char num_rec[65];
char num_rec1[65];
//char num_rec2[65];
char num_rec2[65];
char num_rec3[65];
char num_rec4[129];
char num_rec5[65];
char num_rec6[65];
char num_rec7[65];
char num_rec8[65];
char num_rec9[65];
char num_rec10[65];
char num_rec11[65];
char num_rec12[65];
char num_rec13[65];
char num_rec14[65];
char num_rec15[65];
char num_rec16[65];
char num_rec17[65];
char note_rec[65];
char user_id[65];
char pay_way[65];
char service_id[65];
char service_name[65];
char *editable;
char service_fees[65];
char currency_name[65];
char currency_fraction[65];
char currency_code[65];
char currency_id[65];
//classes:
char *classes_no;
char class_id[65];
char class_name[65];
char class_fees[65];
char percentage[65];

char service_id1[65];
char service_name1[65];
char *editable1;
char service_fees1[65];
char currency_name1[65];
char currency_fraction1[65];
char currency_code1[65];
char currency_id1[65];
//classes:
char *classes_no1;
char class_id1[65];
char class_name1[65];
char class_fees1[65];
char percentage1[65];
char user_password[65];
char user_AHMED[65];
char *password99;
char *sha1_user_pass;
int u = 0;
int u1 = 0;
int u2 = 0;
int u3 = 0;
int u4 = 0;
int u5 = 0;
int u6 = 0;
int u7 = 0;
int u8 = 0;
int u9 = 0;
int u10 = 0;
int u11 = 0;
int u12 = 0;
int u13 = 0;
int u14 = 0;
int u15 = 0;
int u16 = 0;
int u17;
int u18;
int u19;
unsigned char digest[32];
const unsigned char *message;
char *key44;
EBS_receipt receipt;
void KeyTask(void) {
	int i, key;

	key = KEYSCAN() & 0xFF;
    
	if (sVirtualKey != BTKEY_NULL) {
		key = sVirtualKey;
		sVirtualKey = BTKEY_NULL;
	}

	if (key == BTKEY_NULL)
		return;

	if (sPrintStep)
		return;

	if (*uspServiceAddr == 0x0000) {

		MainStatusSetting(MSS_MAIN_MENU, MST_MAIN_MENU, M4MAINM01);
		ScrollHilight(M4MAINM01, 1);
		key_ypos = Updown = 1;
	} else {

		switch (key) {
		/* No Paper Error */
		/*
		 case 0x25:
		 break;
		 */
		case BTKEY_SFUNC:
			if (*uspServiceAddr == 0x0000) {
				CARD_DISABLE();
				/* "ENTER PASSWORD ?", "                ", "                ", "                " */
				//MainStatusSetting(MSS_SPECIAL_FUNC, MST_SPECIAL, M4SETUP00);
				memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
				CursorOn(2, 6);
				ucKeyCnt = 0;
			} else
				KeyService(key);
			break;

		case BTKEY_FCN:
			if (*uspServiceAddr == 0x0000) {
				CARD_DISABLE();
				/* "  <Self Test>   ", "Test Menu[0-5] ?", "      [ ]       ", "                " */
				//MainStatusSetting(MSS_SELFTEST_MENU, MST_SELECT_SELFTEST_MENU, M4TMENU01);
				memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
				c65TempKeyBuf[0] = '0';
				Lprint_1(2, 7, c65TempKeyBuf[0]);
				CursorOn(2, 7);
				ucKeyCnt = 0;
				DispalySelfTestMainMenu((int) (c65TempKeyBuf[0] - '0'));
			} else
				KeyService(key);
			break;

		case BTKEY_CANCEL:
			CancelKeyService();
			break;
		case BTKEY_ENTER:
			EnterKeyService();
			break;

		default:
			KeyService(key);
			break;
		}
	}
}

void KeyService(int key) {
	int i, x, y;
	switch (*uspServiceAddr) {
	case 0x0100: /* Main Menu */
		MainMenuUpDown(key, M1MAINM00, 4);
		break;
	case 0x0201: /* lOG IN */
	case 0x0202:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0203:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0211:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0221:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0231:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0241:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0251:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0261:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0271:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0281:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0291:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);

	case 0x0301: /* SETTING */
	case 0x0302:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0303:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0311:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0321:
		InputDateTime(3, 2, 14, key, c65TempKeyBuf);
		break;
	case 0x0331:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0341:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0351:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0361:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0371:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0381:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0391:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0401: /* Language */
		MainMenuUpDown(key, M1LANGAG0, 2);
		break;
	case 0x0421:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0431:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0441:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0451:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0461:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0471:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0481:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0491:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0501: /* Settings */
		MainMenuUpDown(key, M1SETING0, 3);
		break;
	case 0x0511:
		InputDateTime(3, 2, 14, key, c65TempKeyBuf);
		break;
	case 0x0521:
		InputDateTime(3, 2, 14, key, c65TempKeyBuf);
		break;
	case 0x0531:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0541:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0551:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0561:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0571:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0581:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0591:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0601: /* BILLPAYMENT MAIN*/
		MainMenuUpDown(key, M1ONLINE0, 6);
		break;
	case 0x0611:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0621:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0631:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0641:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0651:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0661:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0671:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0681:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0691:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0701: /* SETTING MAIN */
		MainMenuUpDown(key, M1SETING0, 3);
		break;
	case 0x0711:
		InputDateTime(3, 2, 14, key, c65TempKeyBuf);
		;
		break;
	case 0x0721:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0731:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0741:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0751:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0761:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0771:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0781:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0791:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;

	case 0x0801: /* E-Payment */
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0811:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0821:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0831:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0841:
		InputPassWord(2, 0, 4, key, c65TempKeyBuf);
		break;
	case 0x0851:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0861:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0871:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0881:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0891:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0901: /* GET INVOICE */
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0911:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0921:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0931:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0941:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0951:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0961:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0971:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0981:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0991:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A01: /* GET KEY1*/
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A11:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0A91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;

	case 0x0B01:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B11:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0B91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;

	case 0x0C01:
		MainMenuUpDown(key, M1LANGAG0, 2);
		break;
	case 0x0C03: /* Login Password */
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C11:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0C91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;

	case 0x0D01: /* SETTING */
	case 0x0D02:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0D03:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0D11:
		MainMenuUpDown(key, M1SETING0, 3);
		break;
	case 0x0D21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0D91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E01:
	case 0x0E02:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0E03:
		InputPassWord(2, 0, 16, key, c65TempKeyBuf);
		break;
	case 0x0E11:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0E91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F01:
		MainMenuUpDown(key, M1FFLINE0, 2);
		break;
	case 0x0F11:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F21:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F31:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F41:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F51:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F61:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F71:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F81:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
	case 0x0F91:
		InputAlpNoString(2, 0, 25, key, c65TempKeyBuf);
		break;
		/* Online Login Username */
	}
}
int testpp() {
	int *a;
	int n;
	//a = (int*)calloc(n, sizeof(int));
}
void EnterKeyService(void) {
	//E15_config *e15_config = E15_GetConfiguration();
	//E15_LoadConfiguration(E15_CONFIGURATION, sizeof(E15_CONFIGURATION));
	EBS_receipt receipt;
	int i, j;
	long ltemp;
	char temp[64];
	char temp_stream[64 * 2];

	switch (*uspServiceAddr) {
	case 0x0100: /* Main Menu */
		switch (Updown) {
		case 0x01: /* log in */
			MainStatusSetting(MSS_LOGIN, MST_LOGIN, M4LOGIN14);
			uspServiceAddr++;
			ScrollHilight(M4LOGIN01, 0);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			CursorOn(2, 15);
			ucKeyCnt = 0;
			cALPKeyInputFlag = 0;
			cALPIndex = 0;
			break;
		case 0x02: /* setting==> Terminal password */
			again: MainStatusSetting(MSS_SETTING_PASSWORD, MST_SETTING_PASSWORD,
					M4LOGIN14);
			uspServiceAddr++;
			ScrollHilight(M4LOGIN01, 0);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			CursorOn(2, 0);
			ucKeyCnt = 0;
			cALPKeyInputFlag = 0;
			cALPIndex = 0;
			break;
		case 0x03: /* Language */
			Lang: MainStatusSetting(MSS_LANGAUGE, MST_LANGAUGE, M4LANGAG1);
			uspServiceAddr++;
			ScrollHilight(M4LANGAG1, 1);
			Updown = key_ypos = 2;
			break;
			break;
		case 0x04: /* GET_KEY */
			MainStatusSetting(MSS_GET_KEY, MST_GET_KEY, M4FFLINE1);
			uspServiceAddr++;
			ScrollHilight(M4FFLINE1, 1);
			Updown = key_ypos = 1;
			Lprint(0, 0, sha1_user_pass);
			break;
		default:
			break;
		}
		break;
	case 0x0201: /* LOGIN==> terminal password */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		//	strcpy(receipt., c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;

		break;
	case 0x0202:
		if (!strcmp(c65TempKeyBuf, "2580")) {
			MainStatusSetting(MSS_ORECEIPT, MST_ORECEIPT, M4ONLINE1);
			uspServiceAddr++;
			ScrollHilight(M4ONLINE1, 1);
			Updown = key_ypos = 1;
		} else {
			Beep(ERROR_TONE1);
			ClearLCDLine(2);
			ClearLCDLine(3);
			CursorOn(3, 0);
			goto again;
		}
		break;
	case 0x0601: /* */
		switch (Updown) {
		case 0x01: /* BILLPAYMENT INVOICE NO */
			MainStatusSetting(MSS_EPAYMENT, MST_EPAYMENT, M4INVOICE_NO);
			uspServiceAddr++;
			ScrollHilight(M4INVOICE_NO, 0);
			Updown = key_ypos = 1;
			break;
		case 0x02:/*GET INVOICE  */
			MainStatusSetting(MSS_FRECEIPT, MST_FRECEIPT, M4INVOICE_NO);
			uspServiceAddr++;
			ScrollHilight(M4INVOICE_NO, 0);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			CursorOn(2, 0);
			ucKeyCnt = 0;
			cALPKeyInputFlag = 0;
			cALPIndex = 0;
			break;
		case 0x03:/*GET_KEY  */
			MainStatusSetting(MSS_GET_KEY1, MST_GET_KEY1, M4ONLINE1);
			uspServiceAddr++;
			ScrollHilight(M4ONLINE1, 1);
			GetWorkingKey();
			Updown = key_ypos = 1;
			break;
		case 0x04:/*CHANGE_PIN  */
			MainStatusSetting(MSS_CHANGE_PIN, MST_CHANGE_PIN, M4ONLINE1);
			uspServiceAddr++;
			ScrollHilight(M4ONLINE1, 1);
			Updown = key_ypos = 1;
			break;
		case 0x05:/* LANGUAGE */
			MainStatusSetting(MSS_LANGAUGE1, MST_LANGAUGE1, M4LANGAG1);
			uspServiceAddr++;
			ScrollHilight(M4LANGAG1, 1);
			Updown = key_ypos = 1;
			break;
		case 0x06:/* SETTING1 */
			MainStatusSetting(MSS_SETTING1, MST_SETTING1, M4ONLINE1);
			uspServiceAddr++;
			ScrollHilight(M4ONLINE1, 1);
			Updown = key_ypos = 1;
			break;
		}
		break;
	case 0x0301: /* LOGIN==> terminal password */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		//strcpy(user_AHMED, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0302:
		if (!strcmp(c65TempKeyBuf, "2580")) {
			MainStatusSetting(MSS_SETTING_MAIN, MST_SETTING_MAIN, M4SETING1);
			uspServiceAddr++;
			ScrollHilight(M4SETING1, 1);
			Updown = key_ypos = 1;
		} else {
			Beep(ERROR_TONE1);
			ClearLCDLine(2);
			ClearLCDLine(3);
			CursorOn(3, 0);
			goto again;
		}
		break;
	case 0x0801: /* EPAYMENT INVOICE NO */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.invoice_no, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0802: /*INVOICE NO*/
		MainStatusSetting(MSS_EMPTY71, MST_EMPTY71, M4INVOICE_NO);
		uspServiceAddr++;
		ScrollHilight(M4INVOICE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0811: /* ENTER PHONE NO */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.invoice_no, c65TempKeyBuf);
		strcpy(id_type, c65TempKeyBuf);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0812: /*PHONE NO*/
		MainStatusSetting(MSS_EMPTY72, MST_EMPTY72, M4PHONE_NO);
		uspServiceAddr++;
		ScrollHilight(M4PHONE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0821: /* DO SWIPE CARD */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.phone, c65TempKeyBuf);
		strcpy(pay_way, c65TempKeyBuf);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0822: /*SWIPE CARD*/
		MainStatusSetting(MSS_EMPTY73, MST_EMPTY73, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0831:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PAN, c65TempKeyBuf);

		strcpy(note_rec, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0832: /*ENTER PIN*/
		MainStatusSetting(MSS_EMPTY74, MST_EMPTY74, M4ENTER_PIN);
		uspServiceAddr++;
		ScrollHilight(M4ENTER_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0841:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		//char* body = "{\"PAN\":\"6280223242060888311\",\"responseCode\":0,\"tranFee\":0,\"referenceNumber\":\"000460198375\",\"approvalCode\":\"704002\",\"systemTraceAuditNumber\":162,\"additionalData\":\"ReferenceId=11;UnitName=??????? ?????? ??????? ?????/???????;ServiceName= ;PayerName=???? ???????;TotalAmount=5\",\"clientId\":\"Ashrafcom\",\"tranDateTime\":\"120418122855\",\"responseMessage\":\"Approval\",\"terminalId\":\"08001051\",\"additionalAmount\":-1,\"tranAmount\":5,\"responseStatus\":\"Successful\",\"payeeId\":\"0010050001\",\"tranCurrencyCode\":\"SDG\",\"personalPaymentInfo\":\"6/124529940000084580/0912452994\"}";

		//	json_parse( body);
		strcpy(receipt.PIN, c65TempKeyBuf);
		sprintf(receipt.personalPaymentInfo, "%s%s%s%s", "6/",
				receipt.invoice_no, "/", receipt.phone);
		strcpy(receipt.payeeId, "0010050001");
		strcpy(receipt.tranCurrencyCode, "SDG");
		strcpy(receipt.card_expiry_date, "2202");
		result2 = PayBill(receipt.PAN, receipt.PIN, receipt.card_expiry_date, 2,
				receipt.tranCurrencyCode, receipt.invoice_no, receipt.phone,
				receipt.payeeId);
		//PayBill(char* PAN, char* PIN, char* expDate, double tranAmount, char* tranCurrencyCode, char* invoiceno, char* phone, char* payeeId)
		Rprintf("result2 === %d \r\n", result2);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0842:
		MainStatusSetting(MSS_E150009, MST_E150009, M4PRINTIN);
		ScrollHilight(M4PRINTIN, 0);
		sPrintStep = 1;
		break;
	case 0x0901: /* GET INVOICE INVOICE NO */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.invoice_no, c65TempKeyBuf);
		strcpy(id_type, c65TempKeyBuf);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0902:
		MainStatusSetting(MSS_EMPTY81, MST_EMPTY81, M4PHONE_NO);
		uspServiceAddr++;
		ScrollHilight(M4PHONE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0911:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.phone, c65TempKeyBuf);
		strcpy(pay_way, c65TempKeyBuf);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0912:
		MainStatusSetting(MSS_EMPTY82, MST_EMPTY82, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0921:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PAN, c65TempKeyBuf);
		strcpy(note_rec, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0922:
		MainStatusSetting(MSS_EMPTY83, MST_EMPTY83, M4ENTER_PIN);
		uspServiceAddr++;
		ScrollHilight(M4ENTER_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0931:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PIN, c65TempKeyBuf);
		Rprintf("invoice number %s \r\n", receipt.invoice_no);
		Rprintf("invoice phone %s \r\n", receipt.phone);
		//sprintf(temp,"%s%s%s%s","2/",receipt.invoice_no,"/",receipt.phone);
		//strcpy(receipt.personalPaymentInfo,temp);
		//Rprintf("invoice Info %s \r\n",receipt.personalPaymentInfo);
		strcpy(receipt.payeeId, "0010050001");
		strcpy(receipt.tranCurrencyCode, "SDG");
		strcpy(receipt.card_expiry_date, "2202");
		result1 = GetBill(receipt.PAN, receipt.PIN, receipt.card_expiry_date,
				receipt.invoice_no, receipt.phone, receipt.payeeId,
				receipt.tranCurrencyCode);
		Rprintf("result1 === %d \r\n", result1);
		goto rr;
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0932: /*PRINTING*/
		//strcpy(receipt.PIN, c65TempKeyBuf);

		//(char* PAN, char* PIN, char* expDate, char* personalPaymentInfo, char* payeeId, char* tranCurrencyCode)
		rr: MainStatusSetting(MSS_E150009, MST_E150009, M4PRINTIN);
		sPrintStep = 1;
		break;
	case 0x0A01:/*GET KEY*/
		break;
	case 0x0B01: /* CHANGE PIN */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PIN, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0B02: /*OLD PIN*/
		MainStatusSetting(MSS_EMPTYA1, MST_EMPTYA1, M4OLD_PIN);
		uspServiceAddr++;
		ScrollHilight(M4OLD_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0B11: /* ENTER OLD PIN */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PIN, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0B12: /*SWIPE CARD*/
		MainStatusSetting(MSS_EMPTYA2, MST_EMPTYA2, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0B21: /* DO SWIPE CARD */
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PAN, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;
	case 0x0B22: /*ENTER NEW PIN*/
		MainStatusSetting(MSS_EMPTYA3, MST_EMPTYA3, M4NEW_PIN);
		uspServiceAddr++;
		ScrollHilight(M4NEW_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;
	case 0x0B31:/*ENTER NEW PIN*/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.newPIN, c65TempKeyBuf);
		Rprintf("invoice number\r\n");
		//Rprintf("invoice number %s \r\n",receipt.invoice_no);
		//Rprintf("invoice phone %s \r\n",receipt.phone);
		//sprintf(receipt.personalPaymentInfo,"%s%s%s%s","2/",receipt.invoice_no,"/",receipt.phone);
		//Rprintf("invoice Info %s \r\n",receipt.personalPaymentInfo);
		//strcpy(receipt.payeeId,"0010050001");
		//strcpy(receipt.tranCurrencyCode,"SDG");
		strcpy(receipt.card_expiry_date, "1906");
		ChangePIN(receipt.PAN, receipt.PIN, receipt.card_expiry_date,
				receipt.newPIN);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;

		break;
	case 0x0B32: /*PRINTING*/
		MainStatusSetting(MSS_E150009, MST_E150009, M4PRINTIN);
		ScrollHilight(M4PRINTIN, 0);
		sPrintStep = 1;
		break;
	case 0x0C01:
		switch (Updown) {
		case 0x01: /* Arabic */
			L = A;
			goto Lang;
			break;
		case 0x02: /* English */
			L = E;
			goto Lang;
			break;
		case 0x03: /* English */
			L = E;
			goto Lang;
			break;
		default:
			break;
		}
		break;
	case 0x0D01:
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(user_AHMED, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;

		break;
	case 0x0D02:

		if (!strcmp(c65TempKeyBuf, "2580")) {

			MainStatusSetting(MSS_EMPTYC1, MST_EMPTYC1, M4ONLINE1);
			uspServiceAddr++;
			ScrollHilight(M4ONLINE1, 1);
			Updown = key_ypos = 1;
		} else {
			Beep(ERROR_TONE1);
			ClearLCDLine(2);
			ClearLCDLine(3);
			CursorOn(3, 0);
			goto again;
		}
		break;
	case 0x0D11:/* SETTING SUB*/
		switch (Updown) {
		case 0x01: /*  */
			MainStatusSetting(MSS_OINVOIC1, MST_OINVOIC1, M4DATET00);
			uspServiceAddr++;
			GetRTCDateTime(&RealTime, 0);
			DisplayYYMMDDhhmmss(&RealTime);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			ucKeyCnt = 0;
			CursorOn(3, 2);
			break;
		case 0x02: /*  */
			MainStatusSetting(MSS_EMPTY11, MST_EMPTY11, M4SERVER_IP);
			uspServiceAddr++;
			ScrollHilight(M4SERVER_IP, 1);
			Updown = key_ypos = 1;

			break;
		case 0x03: /*  */
			MainStatusSetting(MSS_EMPTY21, MST_EMPTY21, M4TERMIANL_ID);
			uspServiceAddr++;
			ScrollHilight(M4TERMIANL_ID, 1);
			Updown = key_ypos = 1;
			break;

		default:
			break;
		}
		break;

	case 0x0701:/* SETTING MAIN*/
		switch (Updown) {
		case 0x01: /*  */
			MainStatusSetting(MSS_OINVOIC1, MST_OINVOIC1, M4DATET00);
			uspServiceAddr++;
			GetRTCDateTime(&RealTime, 0);
			DisplayYYMMDDhhmmss(&RealTime);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			ucKeyCnt = 0;
			CursorOn(3, 2);
			break;
		case 0x02: /*  */
			MainStatusSetting(MSS_EMPTY21, MST_EMPTY21, M4TERMIANL_ID);
			uspServiceAddr++;
			ScrollHilight(M4TERMIANL_ID, 0);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			CursorOn(2, 0);
			ucKeyCnt = 0;
			cALPKeyInputFlag = 0;
			cALPIndex = 0;

			break;
		case 0x03: /*  */
			MainStatusSetting(MSS_EMPTY11, MST_EMPTY11, M4SERVER_IP);
			uspServiceAddr++;
			ScrollHilight(M4SERVER_IP, 0);
			memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
			CursorOn(2, 0);
			ucKeyCnt = 0;
			cALPKeyInputFlag = 0;
			cALPIndex = 0;
			break;

		default:
			break;
		}
		break;
	case 0x0711: /* date&time */
		if (strlen(c65TempKeyBuf) != 0 && strlen(c65TempKeyBuf) != 14) {
			Beep(ERROR_TONE1);
			break;
		}

		if (strlen(c65TempKeyBuf) == 14) {
			SetRTCDateTime(c65TempKeyBuf, 0);
			GetRTCDateTime(&RealTime, 0);
		}
		sVirtualKey = BTKEY_CANCEL;
		break;

	case 0x0211: /**/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.SERVER_IP, c65TempKeyBuf);
		strcpy(E15_CONFIGURATION.EBS_server_sim.ServerIP, receipt.SERVER_IP);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0212: /* SERVER IP*/
		MainStatusSetting(MSS_EMPTY12, MST_EMPTY12, M4PORT_NO);
		uspServiceAddr++;
		ScrollHilight(M4PORT_NO, 0);
		Updown = key_ypos = 1;
		break;

	case 0x0221: /**/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PORT_NO, c65TempKeyBuf);
		strcpy(E15_CONFIGURATION.EBS_server_sim.ServerPort, receipt.PORT_NO);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0222: /*user  */
		MainStatusSetting(MSS_EMPTY13, MST_EMPTY13, M4USERNAME);
		uspServiceAddr++;
		ScrollHilight(M4USERNAME, 0);
		Updown = key_ypos = 1;

		break;
	case 0x0231: /*username*/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.USERNAME, c65TempKeyBuf);
		strcpy(E15_CONFIGURATION.EBS_server_sim.Id, receipt.USERNAME);

		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0232: /*password */
		MainStatusSetting(MSS_EMPTY14, MST_EMPTY14, M4PASSWORD);
		uspServiceAddr++;
		ScrollHilight(M4PASSWORD, 0);
		Updown = key_ypos = 1;

		break;
	case 0x0241: /**/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.PASSWORD, c65TempKeyBuf);
		strcpy(E15_CONFIGURATION.EBS_server_sim.Passwd, receipt.PASSWORD);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0242: /* */
		MainStatusSetting(MSS_EMPTY15, MST_EMPTY15, M4APN);
		uspServiceAddr++;
		ScrollHilight(M4APN, 0);
		Updown = key_ypos = 1;

		break;

	case 0x0251: /*ENTER APN*/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(receipt.APN, c65TempKeyBuf);
		strcpy(E15_CONFIGURATION.EBS_server_sim.Apn, receipt.APN);
		Rprintf("Servier Port: %s \r\n",
				E15_CONFIGURATION.EBS_server_sim.ServerPort);
		Rprintf("APN user: %s \r\n", E15_CONFIGURATION.EBS_server_sim.Id);
		Rprintf("Servier IP: %s \r\n",
				E15_CONFIGURATION.EBS_server_sim.ServerIP);
		Rprintf("apn password: %s \r\n",
				E15_CONFIGURATION.EBS_server_sim.Passwd);
		Rprintf("APN name: %s \r\n", E15_CONFIGURATION.EBS_server_sim.Apn);
		E15_SaveConfiguration(&E15_CONFIGURATION, sizeof(E15_config));
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0252: /* */
		MainStatusSetting(MSS_SETTING_MAIN, MST_SETTING_MAIN, M4SETING1);
		uspServiceAddr++;
		ScrollHilight(M4SETING1, 1);
		Updown = key_ypos = 1;

		break;
	case 0x0311: /**/
		if (!strlen(c65TempKeyBuf)) {
			Beep(ERROR_TONE1);
			break;
		}
		strcpy(user_id, c65TempKeyBuf);
		uspServiceAddr++;
		sVirtualKey = BTKEY_ENTER;
		break;

	case 0x0312: /* TERMINAL ID*/
		MainStatusSetting(MSS_EMPTY12, MST_EMPTY12, M4TERMIANL_ID);
		uspServiceAddr++;
		ScrollHilight(M4TERMIANL_ID, 1);
		Updown = key_ypos = 1;
		break;

	case 0x0401: /* Language */
		switch (Updown) {
		case 0x01: /* Arabic */
			L = A;
			goto Lang;
			break;
		case 0x02: /* English */
			L = E;
			goto Lang;
			break;
		case 0x03: /* English */
			L = E;
			goto Lang;
			break;
		default:
			break;
		}
		break;
	case 0x0501:/*GET KEY MAIN*/

		break;
	}
}
void CancelKeyService(void) {
	switch (usMainStatus) {
	case MSS_INITIAL: /* Initial Status */
	case MSS_MAIN_MENU: /* Main Menu */
		if (*uspServiceAddr != 0x0000)
			SetInitialStatus();
		ScrollStop();
		ICON_DISPLAY(10);
		ICON_DISPLAY(12);
		break;
	case MSS_ERROR:
		MainStatusSetting(MSS_ORECEIPT, MST_ORECEIPT, M4ONLINE1);
		uspServiceAddr++;
		ScrollHilight(M4ONLINE1, 1);
		Updown = key_ypos = 1;
		break;

		break;
	case MSS_LOGIN: /* Main Menu */
	case MSS_SETTING_PASSWORD:
	case MSS_LANGAUGE:
	case MSS_GET_KEY:
	case MSS_SETTING_MAIN:
		MainStatusSetting(MSS_MAIN_MENU, MST_MAIN_MENU, M4MAINM01);
		ScrollHilight(M4MAINM01, 1);
		Updown = key_ypos = 1;
		break;

	case MSS_EPAYMENT: /* main billpayment */
	case MSS_FRECEIPT:
	case MSS_GET_KEY1:
	case MSS_CHANGE_PIN:
	case MSS_LANGAUGE1:
	case MSS_SETTING1:

		MainStatusSetting(MSS_ORECEIPT, MST_ORECEIPT, M4ONLINE1);
		uspServiceAddr++;
		ScrollHilight(M4ONLINE1, 1);
		Updown = key_ypos = 1;

		break;

	case MSS_EMPTY71:/*BillPAYMENT*/

		MainStatusSetting(MSS_EPAYMENT, MST_EPAYMENT, M4INVOICE_NO);
		uspServiceAddr++;
		ScrollHilight(M4INVOICE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY72:

		MainStatusSetting(MSS_EMPTY71, MST_EMPTY71, M4INVOICE_NO);
		uspServiceAddr++;
		ScrollHilight(M4INVOICE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY73:

		MainStatusSetting(MSS_EMPTY72, MST_EMPTY72, M4PHONE_NO);
		uspServiceAddr++;
		ScrollHilight(M4PHONE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY74:

		MainStatusSetting(MSS_EMPTY73, MST_EMPTY73, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY81: /* Get Invoice */

		MainStatusSetting(MSS_FRECEIPT, MST_FRECEIPT, M4INVOICE_NO);
		uspServiceAddr++;
		ScrollHilight(M4INVOICE_NO, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY82:

		MainStatusSetting(MSS_EMPTY81, MST_EMPTY81, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTY83:

		MainStatusSetting(MSS_EMPTY82, MST_EMPTY82, M4ENTER_PIN);
		uspServiceAddr++;
		ScrollHilight(M4ENTER_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;

		break;

	case MSS_EMPTYA1:
		MainStatusSetting(MSS_CHANGE_PIN, MST_CHANGE_PIN, M4NEW_PIN);
		uspServiceAddr++;
		ScrollHilight(M4NEW_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;

	case MSS_EMPTYA2:
		MainStatusSetting(MSS_EMPTYA1, MST_EMPTYA1, M4OLD_PIN);
		uspServiceAddr++;
		ScrollHilight(M4OLD_PIN, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;

	case MSS_EMPTYA3:
		MainStatusSetting(MSS_EMPTYA2, MST_EMPTYA2, M4SWIPE_CARD);
		uspServiceAddr++;
		ScrollHilight(M4SWIPE_CARD, 0);
		memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
		CursorOn(2, 0);
		ucKeyCnt = 0;
		cALPKeyInputFlag = 0;
		cALPIndex = 0;
		break;

	case MSS_OINVOIC1:/* Date & Time */
		MainStatusSetting(MSS_SETTING_MAIN, MST_SETTING_MAIN, M4SETING1);
		uspServiceAddr++;
		ScrollHilight(M4SETING1, 1);
		Updown = key_ypos = 1;
		break;

	case MSS_EMPTY21:/* Terminal Id */
		MainStatusSetting(MSS_SETTING_MAIN, MST_SETTING_MAIN, M4SETING1);
		uspServiceAddr++;
		ScrollHilight(M4SETING1, 1);
		Updown = key_ypos = 1;
		break;

	case MSS_EMPTY11:/* network setting  */
		MainStatusSetting(MSS_SETTING_MAIN, MST_SETTING_MAIN, M4SETING1);
		uspServiceAddr++;
		ScrollHilight(M4SETING1, 1);
		Updown = key_ypos = 1;
		break;

	default:
		SetInitialStatus();
		break;
	}
}

//void SelectOperator(void)
//{
//	int rslt=0,i;
//	unsigned char ch;
//	char buff[500];
//	/* "Please Wait...  ", "Select Operator ","                ", "                " */
//	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST3);
//	HighlightOn(0, 0, 16);
//	
//	rslt = ModemWrite("AT+CPIN?\r\n");
//	if (iRxCnt >= 14 && !memcmp((char *)&ucRxBuf[iRxCnt-14], "+CPIN: READY", 12)) {
//		Rprintf("SIM1 OK\r\n");
//	}
//	else if (iRxCnt >= 16 && !memcmp((char *)&ucRxBuf[iRxCnt-16], "+CME ERROR: 10", 14)) {
//		Rprintf("No SIM1 swicht to SIM2\r\n");
//		CONTROL_POWER_SAVING_STATUS(P_RF_MODULE, OFF);
//		Wait1MS(1000);
//		ModemInit(1);
//		rslt = ModemWrite("AT+CPIN?\r\n");
//		if (iRxCnt >= 14 && !memcmp((char *)&ucRxBuf[iRxCnt-14], "+CPIN: READY", 12)) {
//			Rprintf("SIM2 OK\r\n");
//		}
//		else if (iRxCnt >= 16 && !memcmp((char *)&ucRxBuf[iRxCnt-16], "+CME ERROR: 10", 14)) {
//			Rprintf("No SIM2\r\n");
//			Lprint_n(1, 0, 16, "NO SIM          ");
//			Wait1MS(3000);
//			return;
//		}
//		HDLCParmeterInitialize();
//		//ModemWrite("AT+CSQ\r\n\r\n");
//		ModemWrite("ATD*99#\r\n");
//	//	 "AT+PLIP=%s\r", st_Setup.sz16LocalIP);
//		// "AT+PGIP=%s\r", st_Setup.sz16Gateway);
//		 // "AT+PSM=%s\r", st_Setup.sz16SubnetMask);
//		  // "AT+PLP=%s\r", st_Setup.sz6LocalPort);
//		   //"AT+PTO=%s\r", st_Setup.sz5TimeOut);
//		  //  "AT+PWP\r");
//		Wait1MS(1000);
//		    ModemWrite("AT+PRIP=192.168.101.200");
//		    Wait1MS(1000);
//		   
//		    ModemWrite("AT+PRP=8181");
//		   Wait1MS(1000);
//		      ModemWrite("ATDT\r");
//		  Wait1MS(1000);
//		      /* Open the high speed modem
//	port_no
//	- 0:COM0, 1:COM1, 2:COM2, 3:COM3
//	baudrate
//	- 0:1200, 1:2400, 2:4800, 3:9600, 4:19200, 5:38400, 6:57600, 7:115200
//	parity_data_bit
//	- 0:8 bit none parity, 1:7 bit even parity, 2:7 bit odd parity, 3:7 bit none parity
//	stop_bit
//	- 1:1 stop bit, 2:2 stop bit
//*/
//		      OpenHiSpeedModem(0, 19200, 0,1);
//		      /* Get high speed modem synchronous mode data */
///* stream   : buffer pointer for received host response data or modem status data
//   size     : pointer for received host response data length or modem status data length
//   return values
//    0 : return modem status data
//    1 : return received host response data
//   -1 : waiting for valid data
//*/
///* HI_GET_SYNCMODEDATA(char *stream, int *size);
///* Send high speed modem synchronous mode data */
///* stream   : buffer pointer for request data
//   size     : request data length
//   return values : transfered request data length
//*/
////HI_SEND_SYNCMODEDATA(char *stream, int size);
//	
//	url="https://jsonplaceholder.typicode.com/posts/1";
//	serverip="192.168.101.200";
//sprintf(HTTP_REQUEST, "GET %s HTTP/1.1\r\n"
//			"Host: %s\r\n"
//			"Content-Type: application/json\r\n"
//			, url, serverip);
//    ucRxBuf[0] = '\0';
//
//	ucTxBuf[0] = '\0';
//	
//Rprintf("HTTP_REQUEST: %s",HTTP_REQUEST);
//strcpy(ucTxBuf,HTTP_REQUEST);
//	HI_SEND_SYNCMODEDATA((char *)&ucTxBuf, 8192);
//Wait1MS(1000);
//			 HI_GET_SYNCMODEDATA((char *)&ucRxBuf, (int)8192);
//			 Rprintf("data: %s",ucRxBuf);
//	/* "Please Wait...  ", "GPRS            ","INITIALIZATION  ", "                " */
//	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST4);
//	HighlightOn(0, 0, 16);
//	Wait1MS(1000);
//	}
//	return;
//}

void SelectOperator(void) {
	int rslt = 0, i;
	unsigned char ch;
	char buff[500];

	char PAN[19]; //= "1234567891234567891"; //string(16-19)
	char PIN[16]; //= "1234567891234567"; //string(16)
	char expDate[4]; // = "1910"; //YYMM
	double tranAmount;
	char tranCurrencyCode[3];
	char personalPaymentInfo[30];
	char payeeId[10];

	/* "Please Wait...  ", "Select Operator ","                ", "                " */
	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST3);
	HighlightOn(0, 0, 16);

	rslt = ModemWrite("AT+CPIN?\r\n");
	if (iRxCnt >= 14
			&& !memcmp((char*) &ucRxBuf[iRxCnt - 14], "+CPIN: READY", 12)) {
		Rprintf("SIM1 OK\r\n");
	} else if (iRxCnt >= 16
			&& !memcmp((char*) &ucRxBuf[iRxCnt - 16], "+CME ERROR: 10", 14)) {
		Rprintf("No SIM1 swicht to SIM2\r\n");
		CONTROL_POWER_SAVING_STATUS(P_RF_MODULE, OFF);
		Wait1MS(1000);
		ModemInit(1);
		rslt = ModemWrite("AT+CPIN?\r\n");
		if (iRxCnt >= 14
				&& !memcmp((char*) &ucRxBuf[iRxCnt - 14], "+CPIN: READY", 12)) {
			Rprintf("SIM2 OK\r\n");
		} else if (iRxCnt >= 16
				&& !memcmp((char*) &ucRxBuf[iRxCnt - 16], "+CME ERROR: 10",
						14)) {
			Rprintf("No SIM2\r\n");
			Lprint_n(1, 0, 16, "NO SIM          ");
			Wait1MS(3000);
			return;
		}
	}
	rslt = ModemWrite("AT^SCFG=Tcp/WithURCs, \"on\"\r\n");
	rslt = ModemWrite("AT+CGREG=0\r\n");
	rslt = ModemWrite("AT+CGREG=?\r\n");
	rslt = ModemWrite("AT+COPS=0\r\n");
	rslt = ModemWrite("AT+CMEE=1\r\n");
	rslt = ModemWrite("AT^SICS=0,CONTYPE,GPRS0\r\n");
	rslt = ModemWrite("AT^SICS=0,ALPHABET,1\r\n");
	rslt = ModemWrite(apncmd);
	rslt = ModemWrite(usercmd);
	rslt = ModemWrite(passcmd);
	rslt = ModemWrite("at^sips=\"connection\",\"save\",0\r\n");
	Wait1MS(6000);

	strcpy(PAN, "6280223242056466726"); //string(16-19)
	strcpy(PIN, Get_PIN_BLOCK("3492", "6280223242056466726")); //string(16)
	strcpy(expDate, "2202"); //YYMM 2896db4ecbcff4d4
	tranAmount = 1;
	strcpy(tranCurrencyCode, "SDG");
	strcpy(personalPaymentInfo, "2/110018210000090037/0919005556");
	strcpy(payeeId, "0010050001");
	//Rprintf("This is th pin block\r\n");
	//Rprintf("This is th pin block %s\r\n",Get_PIN_BLOCK("0000","9222060130947022607"));

	//("{\"referenceNumber\":\"000001695734\",\"systemTraceAuditNumber\":881,\"responseMessage\":\"Approval\",\"additionalData\":\"UnitName=osman;ServiceName=ali;PayerName=150.22222;TotalAmount=200.33311;LastInvoiceDate=13-12-2014\",\"personalPaymentInfo\":\"0912345678\",\"tranFee\":0,\"responseStatus\":\"Successful\",\"tranDateTime\":\"060518122558\",\"terminalId\":\"19000019\",\"PAN\":\"9888190017363257\",\"responseCode\":0,\"payeeId\":\"0010010002\",\"approvalCode\":null}");

//	{"clientId":"Ashrafcom","terminalId":"08001055","tranDateTime":"170518135843","systemTraceAuditNumber":37,"PAN":"6280223242008717812","PIN":"2b35f76b54ad326f","expDate":"2202","personalPaymentInfo":"2/180934710000080569/0110102386","payeeId":"0010050001","tranCurrencyCode":"SDG"}
//	{"clientId":"Ashrafcom","terminalId":"08001055","tranDateTime":"170518142315","systemTraceAuditNumber":38,"PAN":"6280223242008717812","PIN":"88b3e87cf861d936","expDate":"2202","personalPaymentInfo":"2/180934710000080569/0110102386","payeeId":"0010050001","tranCurrencyCode":"SDG"}

	InitServices();
	//GetWorkingKey();
	//Rprintf("This is th pin block %s\r\n",Get_PIN_BLOCK("3492","6280223242056466726"));
	//PayBill(PAN, PIN, expDate, tranAmount, tranCurrencyCode, personalPaymentInfo, payeeId);
	//GetBill(PAN, PIN, expDate, "110018210000090037","0919005556",payeeId , tranCurrencyCode);
	//ErrDisplay(103);

	/* "Please Wait...  ", "GPRS            ","INITIALIZATION  ", "                " */
	MainStatusSetting(MSS_INITIAL, MST_INITIAL, M4INITST4);
	HighlightOn(0, 0, 16);
	Wait1MS(1000);

	return;
}

void SetInitialStatus(void) {
	usMainStatus = MSS_INITIAL;
	uspServiceAddr = (unsigned short*) &tbl_MainService[MST_INITIAL][0];
	CursorOff();

	GRA_LOAD((char*) LOGO_SDN, 0, 4); /* Display logo on LCD */
	sVirtualKey = BTKEY_NULL;
	sTempKey = BTKEY_NULL;
	ucKeyCnt = 0;

	if (sHiSpeedModemTaskStep != -1) {
		HiSpeedModemReset();
		sHiSpeedModemTaskStep = -1;
	}
	if (sTcpProcessStep == 27 || sTcpProcessStep >= 100)
		TcpDisconnect();
	else
		sTcpProcessStep = -1;
	ucReqDataReadyFlag = 0;
	ucReqDataSendFlag = 0;

	sAutoCOMMenu = 0;
	usCOMTotalCnt = 0;
	usCOMSuccessCnt = 0;

//	sLCDDotTestedFlag = 0;
//	sLCDContrastTestedFlag = 0;
//	sLCDBackLightTestedFlag = 0;
//	sBuzzerTestedFlag = 0;
//	
//	sKEYTestedFlag = 0;

	memset(c65TempKeyBuf, 0x00, sizeof(c65TempKeyBuf));
	memset(c65DotorCommaString, 0x00, sizeof(c65DotorCommaString));

	CARD_DISABLE();
//#ifdef USER_DEBUG
//	EnableDebugOutput();
//	if (st_Setup.cLANComPort)
//		SetDebugPort(COM0, BPS19200, NONE8BIT, STOP1BIT);
//	else
//		SetDebugPort(COM1, BPS19200, NONE8BIT, STOP1BIT);
//#endif
}

void MainStatusSetting(unsigned short Status, short ServiceTableNo,
		short DisplayMsgNo) {
	usMainStatus = Status;
	StrDisplay(DisplayMsgNo, L);
	uspServiceAddr = (unsigned short*) &tbl_MainService[ServiceTableNo][0];
}

void ErrorDisplaySetting(unsigned short Status, short ServiceTableNo,
		short DisplayMsgNo) {
	usMainStatus = Status;
	ErrDisplay(DisplayMsgNo);
	uspServiceAddr = (unsigned short*) &tbl_MainService[ServiceTableNo][0];
}

void ErrorDisplayAndGoInitialStatus(unsigned short MsgNo) {
	StrDisplay(MsgNo, L);
	Beep(ERROR_TONE1);
	uspServiceAddr = (unsigned short*) &tbl_MainService[MST_INITIAL][1];
	Wait1MS(1500);
	SetInitialStatus();
}

void ErrorDisplayAndGoErrorStatus(unsigned short MsgNo) {
	StrDisplay(MsgNo, L);
	Beep(ERROR_TONE1);
	uspServiceAddr = (unsigned short*) &tbl_MainService[MST_INITIAL][1];
}

void DisplayCenterString(char YPos, char *str, int size) {
	int len;
	char temp[17];

	len = size;
	if (len > 16)
		len = 16;
	memcpy(temp, str, len);
	temp[len] = 0x00;
	Lprint_n(YPos, (16 - strlen(temp)) / 2, strlen(temp), temp);
}

void Dispaly2PullDownMenu(void) {
	if (sTempKey == BTKEY_2)
		HighlightOn(1, 0, 16);
	else
		HighlightOn(2, 0, 16);
}

void Dispaly3PullDownMenu(void) {
	if (sTempKey == BTKEY_2)
		HighlightOn(1, 0, 16);
	else if (sTempKey == BTKEY_3)
		HighlightOn(2, 0, 16);
	else
		HighlightOn(3, 0, 16);
}

void Dispaly4PullDownMenu(void) {
	if (sTempKey == BTKEY_1)
		HighlightOn(0, 0, 16);
	else if (sTempKey == BTKEY_2)
		HighlightOn(1, 0, 16);
	else if (sTempKey == BTKEY_3)
		HighlightOn(2, 0, 16);
	else
		HighlightOn(3, 0, 16);
}

void Dispaly6PullDownMenu(void) {
	if (sTempKey == BTKEY_2)
		HighlightOn(1, 0, 8);
	else if (sTempKey == BTKEY_3)
		HighlightOn(1, 8, 8);
	else if (sTempKey == BTKEY_4)
		HighlightOn(2, 0, 8);
	else if (sTempKey == BTKEY_5)
		HighlightOn(2, 8, 8);
	else
		HighlightOn(3, 0, 8);
}

void DispalySelfTestMainMenu(int menu) {
	if (L == A) {
		Lprint_n(3, 0, 16, (char*) msg_tbl1[M1TMENU10 + menu]);
		HighlightOn(3, 0, 16);
	}
	if (L == E) {
		Lprint_n(3, 0, 16, (char*) msg_en_tbl1[M1TMENU10 + menu]);
		HighlightOn(3, 0, 16);
	}
}

int GetCountryName(int country_code, char **country_name) {
	short i;

	for (i = 0;; i++) {
		if (COUNTRY_CODE[i].ucCountryCode == country_code) {
			*country_name = COUNTRY_CODE[i].CountryName;
			return 1;
		} else if (COUNTRY_CODE[i].ucCountryCode == CC_EOT) {
			*country_name = COUNTRY_CODE[i].CountryName;
			return 0;
		}
	}
}

int GetCountryCode(char *str) {
	int i, len, code;

	code = CC_EOT;
	len = strlen(str);
	if (len > 0) {
		if (len > 2)
			len = 2;

		if (str[0] >= '0' && str[0] <= '9')
			code = str[0] - '0';
		else
			code = str[0] - 'A' + 10;

		if (len == 2) {
			code = (code << 4) & 0xF0;
			if (str[1] >= '0' && str[1] <= '9')
				code |= str[1] - '0';
			else
				code |= str[1] - 'A' + 10;
		}
	}

	return code;
}

void HyperTerminalMode(void) {
	int key;
	unsigned int delayus, speed;
	char baudrate;
	unsigned char ch;

	CONTROL_POWER_SAVING_STATUS(P_EXT_SERIAL, ON);
	CONTROL_POWER_SAVING_STATUS(P_RF_MODULE, ON);
	CONTROL_POWER_SAVING_STATUS(P_SMART_CARD, ON);

	if (cSIMSlotNo == 0)
		SIM_SELECT(0);
	else
		SIM_SELECT(1);

	if (cDTEBaudrate == 0)
		baudrate = BPS9600;
	else if (cDTEBaudrate == 1)
		baudrate = BPS19200;
	else if (cDTEBaudrate == 2)
		baudrate = BPS38400;
	else if (cDTEBaudrate == 3)
		baudrate = BPS57600;
	else
		baudrate = BPS115200;
	OpenRS232Port(cDTEPortNo, baudrate, NONE8BIT, STOP1BIT);

	if (cDCEBaudrate == 0) {
		baudrate = BPS9600;
		speed = 9600;
	} else if (cDCEBaudrate == 1) {
		baudrate = BPS19200;
		speed = 19200;
	} else if (cDCEBaudrate == 2) {
		baudrate = BPS38400;
		speed = 38400;
	} else if (cDCEBaudrate == 3) {
		baudrate = BPS57600;
		speed = 57600;
	} else {
		baudrate = BPS115200;
		speed = 115200;
	}
	OpenRS232Port(cDCEPortNo, baudrate, NONE8BIT, STOP1BIT);

	delayus = (1000000 * 12) / speed;
	SET_TX_TIME_INTERVAL(cDCEPortNo, delayus, 0xff, 0);

	while (1) {
		key = KEYSCAN() & 0xFF;
		if (key == BTKEY_CANCEL)
			return;
		if (CheckRxInput(cDTEPortNo)) {
			ch = RdCom(cDTEPortNo);
			WrCom(cDCEPortNo, &ch, 1);
		}
		if (CheckRxInput(cDCEPortNo)) {
			ch = RdCom(cDCEPortNo);
			WrCom(cDTEPortNo, &ch, 1);
			Wait1MS(2);
		}
	}
}

void ScrollStart(int index, int pos) {
	ScrProcess = 1;
	Tindex = index;
	Fpos = pos;
}

void ScrollStop(void) {
	ScrProcess = 0;
}

void ScrollHilight(int Msgno, int pos) {
	if (L == A) {
		if (strlen(msg_tbl1[msg_tbl4[Msgno][pos]]) > 16)
			ScrollStop();
		LCD_BLINKING(2, pos, 0, 16);
	} else {
		ScrollStop();
		LCD_BLINKING(2, pos, 0, 16);
	}
	if (L == E) {
		if (strlen(msg_en_tbl1[msg_tbl4[Msgno][pos]]) > 16)
			ScrollStart(msg_tbl4[Msgno][pos], pos);
	} else {
		ScrollStop();
		LCD_BLINKING(2, pos, 0, 16);
	}
}

void ScrollTask(void) {
	switch (ScrProcess) {
	case 0:
		break;
	case 1:
		if (L == A) {
			sz = strlen(msg_tbl1[Tindex]);
			strncpy(tmpnbuf, (char*) &msg_tbl1[Tindex][0], 16);
			tmpnbuf[16] = '\0';
		} else if (L == E) {
			sz = strlen(msg_en_tbl1[Tindex]);
			strncpy(tmpnbuf, (char*) &msg_en_tbl1[Tindex][0], 16);
			tmpnbuf[16] = '\0';
		}
		if (L == A) {
			fix_connected_chars(tmpnbuf);
			right2left(tmpnbuf);
			Lprint_n(Fpos, 0, 16, tmpnbuf);
		} else {
			Lprint_n(Fpos, 0, 16, tmpnbuf);
		}
		HighlightOn(Fpos, 0, 16);
		Wait1MS(333);
		ScrProcess++;
		break;
	default:
		if (L == A) {
			if (isdigit(msg_tbl1[Tindex][0])) {
				strncpy(tmpnbuf, (char*) &msg_tbl1[Tindex][1 + ScrProcess], 14);
				tmpnbuf[16] = '\0';
			} else if (L == E) {
				if (isdigit(msg_en_tbl1[Tindex][0])) {
					strncpy(tmpnbuf,
							(char*) &msg_en_tbl1[Tindex][1 + ScrProcess], 14);
					tmpnbuf[16] = '\0';
				}
			}
			if (L == A) {
				fix_connected_chars(tmpnbuf);
				right2left(tmpnbuf);
				Lprint_n(Fpos, 2, 14, tmpnbuf);
			} else if (L == E) {
				Lprint_n(Fpos, 2, 14, tmpnbuf);
			}
		} else {
			if (L == A) {
				strncpy(tmpnbuf, (char*) &msg_tbl1[Tindex][ScrProcess - 1], 16);
				tmpnbuf[16] = '\0';
			} else if (L == E) {
				strncpy(tmpnbuf, (char*) &msg_en_tbl1[Tindex][ScrProcess - 1],
						16);
				tmpnbuf[16] = '\0';
			}
			if (L == A) {
				fix_connected_chars(tmpnbuf);
				right2left(tmpnbuf);
				Lprint_n(Fpos, 0, 16, tmpnbuf);
			} else if (L == E) {
				Lprint_n(Fpos, 0, 16, tmpnbuf);
			}
		}
		HighlightOn(Fpos, 0, 16);
		Wait1MS(333);
		if ((sz - 15 - ScrProcess) == 0)
			ScrProcess = 1;
		else
			ScrProcess++;
		break;
	}
}
//fix_connected_chars(tmpbuf);
//right2left(tmpbuf);
int MainMenuUpDown(int key, int index, int max) {
	int i, imax, j;
	char tmpbuf[20];
	char tmpbuf1[20];

	switch (key) {
	case BTKEY_ASTERISK:
		if (Updown <= 1 && max == 2) {
			LCD_BLINKING(3, key_ypos, 0, 16);
			Updown = key_ypos = 2;
			if (L == E) {
				if (strlen(msg_en_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			if (L == A) {
				if (strlen(msg_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			break;
		}
		if (Updown <= 1) {
			LCD_BLINKING(3, key_ypos, 0, 16);
			Updown = max;
			i = max - 2;
			for (j = 1; i <= max; i++) {
				if (L == E) {
					strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				} else if (L == A) {
					strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				}
				if (L == A) {
					fix_connected_chars(tmpbuf);
					right2left(tmpbuf);
					Lprint_n(j++, 0, 16, tmpbuf);
				} else {
					Lprint_n(j++, 0, 16, tmpbuf);
				}
			}
			key_ypos = 3;
			if (L == A) {
				if (strlen(msg_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			} else if (L == E) {
				if (strlen(msg_en_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			break;
		}
		LCD_BLINKING(3, key_ypos, 0, 16);
		Updown--;

		ICON_DISPLAY(10);
		ICON_DISPLAY(13);

		if (key_ypos == 1) {
			i = Updown;
			if (i >= 1) {
				imax = i + 3;
				for (j = 1; i < imax; i++) {
					if (L == E) {
						strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					} else if (L == A) {
						strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					}

					if (L == A) {
						fix_connected_chars(tmpbuf);
						right2left(tmpbuf);
						Lprint_n(j++, 0, 16, tmpbuf);
					} else {
						Lprint_n(j++, 0, 16, tmpbuf);
					}
				}
			}
		} else {
			key_ypos--;
		}
		if (L == E) {
			if (strlen(msg_en_tbl1[Updown + index]) > 16)
				ScrollStart(Updown + index, key_ypos);
			else {
				ScrollStop();
				LCD_BLINKING(2, key_ypos, 0, 16);
			}
		}
		if (L == A) {
			if (strlen(msg_tbl1[Updown + index]) > 16)
				ScrollStart(Updown + index, key_ypos);
			else {
				ScrollStop();
				LCD_BLINKING(2, key_ypos, 0, 16);
			}
		}
		break;
	case BTKEY_SHARP:
		if (Updown >= max && max == 2) {
			LCD_BLINKING(3, key_ypos, 0, 16);
			Updown = key_ypos = 1;
			if (L == E) {
				if (strlen(msg_en_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			if (L == A) {
				if (strlen(msg_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			break;
		}
		if (Updown >= max) {
			LCD_BLINKING(3, key_ypos, 0, 16);
			Updown = 1;
			i = Updown;
			imax = i + 3;
			for (j = 1; i < imax; i++) {
				if (L == E) {
					strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				} else if (L == A) {
					strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				}
				if (L == A) {
					fix_connected_chars(tmpbuf);
					right2left(tmpbuf);
					Lprint_n(j++, 0, 16, tmpbuf);
				} else {
					Lprint_n(j++, 0, 16, tmpbuf);
				}
			}
			key_ypos = 1;
			if (L == E) {
				if (strlen(msg_en_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			if (L == A) {
				if (strlen(msg_tbl1[Updown + index]) > 16)
					ScrollStart(Updown + index, key_ypos);
				else {
					ScrollStop();
					LCD_BLINKING(2, key_ypos, 0, 16);
				}
			}
			break;
		}
		LCD_BLINKING(3, key_ypos, 0, 16);
		Updown++;

		ICON_DISPLAY(12);
		ICON_DISPLAY(11);

		if (key_ypos == 3) {
			i = Updown - 2;
			imax = i + 3;
			for (j = 1; i < imax; i++) {
				if (L == E) {
					strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				} else if (L == A) {
					strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
					tmpbuf[16] = '\0';
				}

				if (L == A) {
					fix_connected_chars(tmpbuf);
					right2left(tmpbuf);
					Lprint_n(j++, 0, 16, tmpbuf);
				} else {
					Lprint_n(j++, 0, 16, tmpbuf);
				}
			}
		} else {
			key_ypos++;
		}
		if (L == E) {
			if (strlen(msg_en_tbl1[Updown + index]) > 16)
				ScrollStart(Updown + index, key_ypos);
			else {
				ScrollStop();
				LCD_BLINKING(2, key_ypos, 0, 16);
			}
		}
		if (L == A) {
			if (strlen(msg_tbl1[Updown + index]) > 16)
				ScrollStart(Updown + index, key_ypos);
			else {
				ScrollStop();
				LCD_BLINKING(2, key_ypos, 0, 16);
			}
		}
		break;

	default:
		if ((key >= 0x01) && (key <= 0x09)) {
			if (key > max)
				break;
			LCD_BLINKING(3, key_ypos, 0, 16);
			switch (key) {
			case 0x01:
			case 0x02:
			case 0x03:
				i = 1;
				for (j = 1; i <= (max > 3 ? 3 : max); i++) {
					if (L == E) {
						strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					} else if (L == A) {
						strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					}
					if (L == A) {
						fix_connected_chars(tmpbuf);
						right2left(tmpbuf);
						Lprint_n(j++, 0, 16, tmpbuf);
					} else {
						Lprint_n(j++, 0, 16, tmpbuf);
					}
				}
				key_ypos = Updown = key;
				if (L == E) {
					if (strlen(msg_en_tbl1[Updown + index]) > 16)
						ScrollStart(Updown + index, key_ypos);
					else {
						ScrollStop();
						LCD_BLINKING(2, key_ypos, 0, 16);
					}
				}
				if (L == A) {
					if (strlen(msg_tbl1[Updown + index]) > 16)
						ScrollStart(Updown + index, key_ypos);
					else {
						ScrollStop();
						LCD_BLINKING(2, key_ypos, 0, 16);
					}
				}
				break;
			case 0x04:
			case 0x05:
			case 0x06:
			case 0x07:
			case 0x08:
			case 0x09:
				i = key - 2;
				for (j = 1; i <= key; i++) {
					if (L == E) {
						strncpy(tmpbuf, (char*) &msg_en_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					} else if (L == A) {
						strncpy(tmpbuf, (char*) &msg_tbl1[i + index][0], 16);
						tmpbuf[16] = '\0';
					}

					if (L == A) {
						fix_connected_chars(tmpbuf);
						right2left(tmpbuf);
						Lprint_n(j++, 0, 16, tmpbuf);
					} else {
						Lprint_n(j++, 0, 16, tmpbuf);
					}
				}
				key_ypos = 3;
				Updown = key;
				if (L == E) {
					if (strlen(msg_en_tbl1[Updown + index]) > 16)
						ScrollStart(Updown + index, key_ypos);
					else {
						ScrollStop();
						LCD_BLINKING(2, key_ypos, 0, 16);
					}
				}
				if (L == A) {
					if (strlen(msg_tbl1[Updown + index]) > 16)
						ScrollStart(Updown + index, key_ypos);
					else {
						ScrollStop();
						LCD_BLINKING(2, key_ypos, 0, 16);
					}
				}
				break;
			default:
				break;
			}
		}
		break;
	}
	return (Updown);
}

/* */
