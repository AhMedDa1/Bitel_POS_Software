#ifndef E15EBS_H_
#define E15EBS_H_

#define	CONFIG_DATA_ADDRESS						0x30080000 //0x41100000 


typedef enum {
//	OK 												= 200,
	THIS_TRANSACTION_ALREADY_PAID 					= 202,
	SYSTEM_ERROR   									= 500,
	BAD_REQUEST_INSUFFICIENT_PARAMETERS   			= 600,
	BAD_REQUEST_MISSING_VALUE   					= 601,
	AUTHENTICATION_FAILURE   						= 602,
	INVALID_UNIT   									= 603,
	INVALID_APPLICATION_ID   						= 604,
	INCORRECT_TOTAL   								= 605,
	INVALID_SERVICE   								= 606,
	INVALID_CURRENCY   								= 607,
	INVALID_PAYER   								= 608,
	INVALID_TRANSACTION_ID   						= 609,
	INVALID_DISCOUNT_VALUE   						= 610,
	INVALID_PAYMENT_DETAILS   						= 611,
	INVALID_PAYMENT_METHOD   						= 612,
	EMPTY_COMMENT   								= 613,
	INVALID_DATE_FORMAT   							= 614,
	FROM_DATE_SHOULD_BE_BEFORE_TO_DATE   			= 615,
	INVALID_PHONE   								= 616,
	INVALID_TERMINAL_ID   							= 617,
	INVALID_INVOICE_NO   							= 618,
	NEW_PASSWORD_DOES_NOT_MATCH_PATTERN   			= 619,
	MISMATCH_IN_NEW_PASSWORD_AND_CONFIRMATION   	= 620,
	SHORT_PIN   									= 621,
	INSUFFICIENT_PERMISSION   						= 622,
	INVALID_BANK_ID   								= 623,
	MAXIMUM_TOTAL_AMOUNT_DIGITS_LENGTH_IS_10   		= 624,
	STAMP_SERVICE_NOT_FOUND   						= 625,
	FAILURE   										= 626,
	INVALID_DATE   									= 627,
	INCORRECT_AMOUNT   								= 628,
	INVALID_AMOUNT_FORMAT   						= 629,
	INVALID_TOTAL_AMOUNT_FORMAT   					= 630,
	THIS_AMOUNT_EXCEED_AMOUNT_DUE   				= 631,
	REVOKED_USER_OR_TERMINAL   						= 632,
	ACCESS_DENIED   								= 633,
	INVALID_UNIT_ID   								= 634,
	INVALID_DELEGATION 								= 635,
	INVALID_DELEGATE_FOR							= 636,
	VERSION_IS_UP_TO_DATE							= 637,
	SHOULD_UPDATE_VERSION							= 638,
	VERSION_NOT_EXISTS 								= 639,
	INVALID_RECEIPT_ID 								= 650,
	INVALID_RECEIPT_NO 								= 651,
	RECEIPT_ALREADY_MARKED_FOR_DELETION				= 652,
	NO_OF_RECEIPTS_IS_INCORRECT						= 653,
	INVALID_ORNIC67_ID 								= 680,
	ZERO_NEW_E15	   								= 681,
	SOME_RECEITS_MARKED_FOR_DELETION				= 682,
	THIS_INVOICE_ALREADY_CANCELED					= 690,
	THIS_INVOICE_ALREADY_PAID						= 691,
	THE_TERMINAL_UNIT_HAVE_NO_EXPIRATION_DATE		= 692,
	TICKET_COUNT_LARGER_THAN_TOTALAMOUNT			= 693,
	TO_DATE_SHOULD_BE_PASS_DATE						= 694
} E15_API_RESPONSE_CODE;

typedef enum {
	BT_ENCRYPT =0,
	BT_DECRYPT,
}CRYPTO_MODE;

typedef enum {
	HTTP = 0,
	HTTPS = 1
} E15_conn_type;

typedef struct __user_config__{
	char	Apn[64];
	char	Id[64];
	char	Passwd[64];
	char	ServerIP[64];
	char	ServerPort[64];
	int		SimSlot;	// 0: SIM_1, 1:SIM_2
} USER_CONF;

typedef struct  {
	short magiccode;	// magiccode
	//E15_mode c_E15_mode;
	//int is_logged_in;
	//int is_locked;
	//unsigned char shared_key[100];
	//char user_id[50];
	//char user_full_name[265];
	//char user_password[50];
	//char terminal_id[50];
	//char terminal_password[50];
	//int last_generated_uuid;
	char tms_host_url[100];
	E15_conn_type tms_conn_type;
	char tms_port_no[10];
	char tms_file_path[50];
	int tms_chunk_size;
	//char app_id[50];
	int version;
	//int vat;
	//int stamp_duty;
	int is_blocked;
	//int upload_in_progress;
	//int upload_patch_size;
	//int upload_successful_squance;
	//int upload_failer_receipt_count;
	int currect_sim_slot;
	char build_date_time[100];
	//USER_CONF E15_server_sim;
	USER_CONF EBS_server_sim;
	char EBS_APP_NAME[100];
	unsigned char EBS_TMK[20];
	unsigned char EBS_TWK[20];
	char EBS_Client_ID[50];
	char EBS_Terminal_ID[50];
	int EBS_Audit_No;
} E15_config;



typedef struct __user_data__{
	char	TxData[2016];
	int		TxLength;
	char	RxData[2016];
	int		RxLength;
} USER_DATA;

typedef struct {
	char uuid[50];
	char unit_name[256];
	char receipt_no[32];
	char invoice_no[32];
	char invoice_expiry[16];
	int invoice_status;
	char payment_ref_id[16];
	char identity[50];
	char identity_type[50];
	char phone[16];
	int has_vat;
	char received_from[256];
	char date[50];
	char description[200];
	int status;
	int services_count;
	//E15_service services[50];
	double total;
	double amount_due;
	char total_in_word[1024];
	int currency_id;
	int payment_method_id;
	int discount;
	char collector_name[256];
	int is_copy;
	char PAN[19];
	char PIN[16];
	char newPIN[16];
	char card_holder_name[256];
	char card_expiry_date[10];
	char auth_code[50];
	char transaction_id[100];
	int is_successful;
} E15_receipt;

typedef enum{
	GSYS_SUCCESS 		  =  0,
	GSYS_CANCEL			  =  1,
	GSYS_TIMEOUT_IDLE	  =  2,
	GSYS_MOVE_FOCUS		  =  3,
	//--------------------------------
	GSYS_FAIL    		  = -1,
	GSYS_FAIL_NO_PAPER    = -2,
} RESULT_GSYS_ID;

//-----------------------------------------------------------------
/** @brief Return value IDs for GUI operation */
typedef enum{
	GUI_ERROR = 0x100,
	GUI_OK,
	GUI_CANCEL,
	GUI_CONFIRM
} RESULT_GUI_ID;

typedef struct __context_gui__ {
//	GR_FONT_ID		font_id_top;
//	GR_FONT_ID		font_id_title;
//	GR_FONT_ID		font_id_base;
//	GR_FONT_ID		font_id_bottom;
//	GR_FONT_ID		font_id_small;
//	GR_FONT_ID		font_id_big;

/*	unsigned int	font_height_top;		// font size
	unsigned int	font_height_title;		// font size
	unsigned int	font_height_base;		// font size
	unsigned int	font_height_bottom;		// font size
	unsigned int	font_height_small;		// font size
	unsigned int	font_height_big;		// font size

	unsigned int    font_width;
	void*			font_start;
	unsigned int	font_size;

	GR_WINDOW_ID	wnd_top;
	GR_WINDOW_ID	wnd_title;
	GR_WINDOW_ID	wnd_base;
	GR_WINDOW_ID	wnd_bottom;

	GR_TIMER_ID		timer_top;
	GR_TIMER_ID		timer_title;
	GR_TIMER_ID		timer_1sec_periodic;
	GR_TIMER_ID		timer_bottom;

	GR_GC_ID		gc_top;
	GR_GC_ID		gc_title;
	GR_GC_ID		gc_base;
	GR_GC_ID		gc_bottom;
	GR_GC_ID		gc_font_small;
	GR_GC_ID		gc_font_big;

	SCREENDEVICE*	scrdev;
	unsigned int	idle_timeout_counter;
	unsigned int	selected_sim_id;

	//-----component--------
	GR_IMAGE_ID		img_editbox_title;
	GR_IMAGE_ID		img_editbox_body;
	GR_IMAGE_ID		img_msgbox_title;
	GR_IMAGE_ID		img_msgbox_body;
	GR_IMAGE_ID		img_listbox_title;
	GR_IMAGE_ID		img_listbox_body;
	GR_IMAGE_ID		img_listbox_body_end;
*/} CONTEXT_GUI;

//-------------------------------------------------------------------------------------
/*
 ******************************************************************
 *
 * 					EBS API FUNCTION CALLS
 *
 ******************************************************************
 */

int EBS_API_IS_ALIVE(CONTEXT_GUI* cnxt);
int EBS_API_GET_WORKING_KEY(CONTEXT_GUI* cnxt);
int EBS_API_GET_INVOICE_INFO(CONTEXT_GUI* cnxt, E15_receipt *receipt);
int EBS_API_E15_INVOICE_PAYMENT(CONTEXT_GUI* cnxt,E15_receipt *receipt);

extern RESULT_GSYS_ID E15_SaveConfiguration();
extern RESULT_GSYS_ID E15_LoadConfiguration();
extern E15_config *E15_GetConfiguration(void);
extern E15_config E15_CONFIGURATION;
extern E15_config F_E15_CONFIGURATION;
extern E15_config *E15_ConfFactoryDefault;

/*
 ******************************************************************/
 /*
 ******************************************************************
 *
 * 					HTTPS REQUEST FUNCTION
 *
 ******************************************************************
 */

char* SEND_EBS_REQUEST(const char *url, const char* body, CONTEXT_GUI* cnxt );
int PostHttp(const char *request, CONTEXT_GUI* cnxt);

/*
 * ***********************************************************************
 **/
#endif /*E15EBS_H_*/
