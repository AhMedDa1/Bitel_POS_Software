#include "system.h"
#include "extern.h"

RESULT_GSYS_ID E15_SaveConfiguration();
RESULT_GSYS_ID E15_LoadConfiguration();
E15_config *E15_GetConfiguration(void);

E15_config E15_CONFIGURATION;
E15_config F_E15_CONFIGURATION;

static int last_used_sim_no = -1;

// Parsing HTTP Response Part
typedef struct {
	char* body;
	int code;
} HttpResponse;
//----------------------------------------
//Connection Config

//static cJSON *body, *responseJ;
static char *URL;
static char *body_string;
static char *response;
static char *cJSON_Err;
/*
//************************************************ Re alloc **************/
static void* response_realloc(void* opaque, void* ptr, int size) {
	//return realloc(ptr, size);
}

//*********************************Response parsing ************************/
//static void response_body(void* opaque, const char* data, int size) {
//	HttpResponse* response = (HttpResponse*) opaque;
//	response->body = data;
//}

// ************************* Header Parsing *******************************/
static void response_header(void* opaque, const char* ckey, int nkey,
		const char* cvalue, int nvalue) { /* example doesn't care about headers */
}
//***************************************************************************/

static void response_code(void* opaque, int code) {
	HttpResponse* response = (HttpResponse*) opaque;
	response->code = code;
}
//****************************************************************************/
//static const struct http_funcs responseFuncs = { response_realloc,
//		response_body, response_header, response_code, };

//End of Parsing HTTP Response Part

int send_timeout = 25000;
//E15_config E15_CONFIGURATION;
//E15_config E15_ConfFactoryDefault;

/*
 ******************************************************************
 *
 * 					EBS API FUNCTION CALLS
 *
 ******************************************************************
 */
 E15_config *E15_GetConfiguration(void) {

	E15_config *rv = NULL;

	//_TRACE( "----> %s()\n", __func__ );

	rv = &E15_CONFIGURATION;

	//_TRACE( "<---- %s()\n", __func__ );
	return rv;
}

 int EBS_API_IS_ALIVE(CONTEXT_GUI* cnxt) {
	E15_config *e15_config = E15_GetConfiguration();
	E15_LoadConfiguration(e15_config, sizeof(E15_config));
	
	/*
	char tranDateTime[15];
	struct tm current_time;
	BtGetRealTimeClock(&current_time);
	sprintf(tranDateTime, "%02d%02d%02d%02d%02d%02d",current_time.tm_mday,current_time.tm_mon+1,(current_time.tm_year + 1900)%100,
			current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

	cJSON_Delete(body);
	body = cJSON_CreateObject();
	cJSON_AddItemToObject(body, "clientId",
			cJSON_CreateString(e15_config->EBS_Client_ID));
	cJSON_AddItemToObject(body, "terminalId",
			cJSON_CreateString(e15_config->EBS_Terminal_ID));
	cJSON_AddItemToObject(body, "tranDateTime",
			cJSON_CreateString(tranDateTime));
	cJSON_AddItemToObject(body, "systemTraceAuditNumber",
			cJSON_CreateNumber(GET_NEXT_EBS_AUDIT_Number()));
	URL = calloc(200, sizeof(char));
	sprintf(URL,"/%s/%s",e15_config->EBS_APP_NAME,"isAlive");
	body_string = cJSON_PrintUnformatted(body);

	response = SEND_EBS_REQUEST(URL, body_string, cnxt);

	free(URL);


	cJSON_Delete(responseJ);
	responseJ = cJSON_Parse(response);

	if (cJSON_GetErrorPtr()) {
		cJSON_Err = cJSON_GetErrorPtr();
		return 2;
	}
	int res_code = cJSON_GetObjectItem(responseJ, "responseCode")->valueint;
	char *responseStatus = cJSON_GetObjectItem(responseJ, "responseStatus")->valuestring;
	if(res_code == 0 && strcmp("Successful", responseStatus) == 0){
		return OK;
	} else {
		return 1;
	}
	// TODO : Call HTTP Request function
	 */
	 return OK;
}

//***********************************Get Working Key ******************************
//---------------------------------------------------------------------------
int EBS_API_GET_WORKING_KEY(CONTEXT_GUI* cnxt) {
	E15_config *e15_config = E15_GetConfiguration();
	E15_LoadConfiguration(e15_config, sizeof(E15_config));
	/*char tranDateTime[15];
	struct tm current_time;
	BtGetRealTimeClock(&current_time);
	sprintf(tranDateTime, "%02d%02d%02d%02d%02d%02d",current_time.tm_mday,current_time.tm_mon+1,(current_time.tm_year + 1900)%100,
			current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

	cJSON_Delete(body);
	body = cJSON_CreateObject();
	cJSON_AddItemToObject(body, "clientId",
			cJSON_CreateString(e15_config->EBS_Client_ID));
	cJSON_AddItemToObject(body, "terminalId",
			cJSON_CreateString(e15_config->EBS_Terminal_ID));
	cJSON_AddItemToObject(body, "tranDateTime",
			cJSON_CreateString(tranDateTime));
	cJSON_AddItemToObject(body, "systemTraceAuditNumber",
			cJSON_CreateNumber(GET_NEXT_EBS_AUDIT_Number()));
	URL = calloc(200, sizeof(char));
	sprintf(URL,"/%s/%s",e15_config->EBS_APP_NAME,"getWorkingKey");
	body_string = cJSON_PrintUnformatted(body);

	response = SEND_EBS_REQUEST(URL, body_string, cnxt);

	free(URL);

	cJSON_Delete(responseJ);
	responseJ = cJSON_Parse(response);

	if (cJSON_GetErrorPtr()) {
		cJSON_Err = cJSON_GetErrorPtr();
		return 2;
	}
	int res_code = cJSON_GetObjectItem(responseJ, "responseCode")->valueint;
	char *responseStatus = cJSON_GetObjectItem(responseJ, "responseStatus")->valuestring;

	if(res_code == 0 && strcmp("Successful", responseStatus) == 0){
		strcpy((char *)e15_config->EBS_TWK, cJSON_GetObjectItem(responseJ, "workingKey")->valuestring);
		E15_SaveConfiguration(e15_config, sizeof(E15_config));
		return OK;
	} else {
		return 1;
	}
*/
	// TODO : Call HTTP Request function
	return 1;
}

int EBS_API_GET_INVOICE_INFO(CONTEXT_GUI* cnxt, E15_receipt *receipt ) {
	E15_config *e15_config = E15_GetConfiguration();
	E15_LoadConfiguration(e15_config, sizeof(E15_config));
	/*char tranDateTime[15];
	char str_amount[100] ={0};
    char str_dueamount[100] ={0};
	struct tm current_time;
	BtGetRealTimeClock(&current_time);
	sprintf(tranDateTime, "%02d%02d%02d%02d%02d%02d",current_time.tm_mday,current_time.tm_mon+1,(current_time.tm_year + 1900)%100,
			current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

	char personalPaymentInfo[50];
	sprintf(personalPaymentInfo,"2/%s/%s", receipt->invoice_no, receipt->phone);
	cJSON_Delete(body);
	body = cJSON_CreateObject();
	cJSON_AddItemToObject(body, "clientId",
			cJSON_CreateString(e15_config->EBS_Client_ID));
	cJSON_AddItemToObject(body, "terminalId",
			cJSON_CreateString(e15_config->EBS_Terminal_ID));
	cJSON_AddItemToObject(body, "tranDateTime",
			cJSON_CreateString(tranDateTime));
	cJSON_AddItemToObject(body, "systemTraceAuditNumber",
			cJSON_CreateNumber(GET_NEXT_EBS_AUDIT_Number()));
	cJSON_AddItemToObject(body, "PAN",
			cJSON_CreateString(receipt->PAN));
	cJSON_AddItemToObject(body, "PIN",
			cJSON_CreateString(Get_PIN_BLOCK(receipt->PIN,receipt->PAN)));
	cJSON_AddItemToObject(body, "expDate",
			cJSON_CreateString(receipt->card_expiry_date));
	cJSON_AddItemToObject(body, "personalPaymentInfo",
			cJSON_CreateString(personalPaymentInfo));
	cJSON_AddItemToObject(body, "payeeId",
			cJSON_CreateString("0010050001")); //0010050001
	cJSON_AddItemToObject(body, "tranCurrencyCode",
			cJSON_CreateString("SDG"));

	URL = calloc(200, sizeof(char));
	sprintf(URL,"/%s/%s",e15_config->EBS_APP_NAME,"getBill");
	body_string = cJSON_PrintUnformatted(body);

	response = SEND_EBS_REQUEST(URL, body_string, cnxt);

	free(URL);


	cJSON_Delete(responseJ);
	responseJ = cJSON_Parse(response);

	if (cJSON_GetErrorPtr()) {
		cJSON_Err = cJSON_GetErrorPtr();
		return 2;
	}
	int res_code = cJSON_GetObjectItem(responseJ, "responseCode")->valueint;
	char *responseStatus = cJSON_GetObjectItem(responseJ, "responseStatus")->valuestring;
	if(res_code == 0 && strcmp("Successful", responseStatus) == 0){
		char *additionalData = cJSON_GetObjectItem(responseJ, "additionalData")->valuestring;
	    char *slash_pos;
	    Btprintf("Additional Data: %s\n",additionalData);
	    //Reference Number
	    slash_pos = strchr(additionalData,';');
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("1st Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos +1;
	    //Unit Name
	    slash_pos = strchr(additionalData,';');
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("2nd Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos+1;
	    //ServiceName
	    slash_pos = strchr(additionalData,';');
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("3rd Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos+1;
	    //PayerName
	    slash_pos = strchr(additionalData,';');
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("4th Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos+1;
	    //TotalAmount
	    slash_pos = strchr(additionalData,';');

	    char *lb_amount;
	    lb_amount = strstr(additionalData,"TotalAmount=");
	    if(lb_amount != NULL){
		    strncpy(str_amount, additionalData + 12, slash_pos - additionalData - 12);
	    	Btprintf("Amount Has Label: %s\n",str_amount);
	    }else{
		    strncpy(str_amount, additionalData, slash_pos - additionalData);
	    	Btprintf("Amount Has No Label: %s\n", str_amount);
	    }
	    receipt->total = atof(str_amount);
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("5th Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos+1;
	    //DueAmount
	    slash_pos = strchr(additionalData,';');
	    char *lb_due_amount;
	    lb_due_amount = strstr(additionalData,"DueAmount=");
	    if(lb_due_amount != NULL){
		    strncpy(str_dueamount, additionalData + 10, slash_pos - additionalData - 10);
	    	Btprintf("Due Amount Has Label: %s\n", str_dueamount);
	    }else{
		    strncpy(str_dueamount, additionalData, slash_pos - additionalData);
	    	Btprintf("Due Amount Has No Label: %s\n", str_dueamount);
	    }
	    receipt->amount_due = atof(str_dueamount);
	    Btprintf("6th Part: %.*s\n", slash_pos - additionalData, additionalData);

	    additionalData = slash_pos+1;
	    //InvoiceExpiry
	    slash_pos = strchr(additionalData,';');
	    if(slash_pos == NULL){
			return 1;
	    }
	    Btprintf("7th Part: %.*s\n", slash_pos - additionalData, additionalData);
	    additionalData = slash_pos+1;
	    //InvoiceStatus
	    Btprintf("8th Part: %s\n", additionalData);


		return OK;
	}

	// TODO : Call HTTP Request function
	return res_code;
	*/
	return 1 ; // to be removed 
}


//-----------------Sequence Change -----------------------------------------


/*
 ******************************************************************
 *
 * 					FLASH ROM READ/WRITE FUCNTIONS
 *
 ******************************************************************
 */

//------------------E15 -EBS CONFIGURATION DATA-----------------------------
/**
 * @brief	Get runtime Configuration handler(pointer)
 *
 */


/**
 * @brief	Check Configuration is valid or not
 *
 */
//RESULT_GSYS_ID E15_IsValidConfiguration( E15_config *e15config )
//{
//	RESULT_GSYS_ID rv = GSYS_SUCCESS;

//	_TRACE( "----> %s()\n", __func__ );
//	if( e15config->magiccode[0] != 'C' || e15config->magiccode[1] != 'N' ||
//			e15config->magiccode[2] != 'F' || e15config->magiccode[3] != '1'){
//		rv = GSYS_FAIL;
//		_TRACE("      WARNING : !!!! No configuration exists !!!!\n");
//	}
	//char *build_date_time ;//= calloc(100, sizeof(char));
	//sprintf(build_date_time,"%s %s",__DATE__, __TIME__ );
	//if(strcmp(e15config->build_date_time,build_date_time)!=0 ){
//		rv = GSYS_FAIL;
//	}

//	_TRACE( "<---- %s()\n", __func__ );
//	return rv;
//}

/**
 * @brief	Get factory default Configuration handler(pointer)
 *
 */
//E15_config *E15_GetConfigurationFactoryDefault(void) {
//	E15_config* rv = NULL;
//
//
//	//_TRACE( "----> %s()\n", __func__ );
//	// factory default configuration info.
////	E15_ConfFactoryDefault.magiccode[0] = 'C';
////	E15_ConfFactoryDefault.magiccode[1] = 'N';
////	E15_ConfFactoryDefault.magiccode[2] = 'F';
////	E15_ConfFactoryDefault.magiccode[3] = '1';
//	//E15_ConfFactoryDefault.c_E15_mode = ONLINE;
//	//E15_ConfFactoryDefault.is_logged_in = 0;
//	//E15_ConfFactoryDefault.is_locked = 1;
//	//memset(E15_ConfFactoryDefault.E15_server_sim.Id, 0x0,sizeof(E15_ConfFactoryDefault.E15_server_sim.Id));
//	//memset(E15_ConfFactoryDefault.E15_server_sim.Passwd, 0x0,sizeof(E15_ConfFactoryDefault.E15_server_sim.Passwd));
//	//strcpy(E15_ConfFactoryDefault.E15_server_sim.ServerIP, "212.0.144.30");
//	//strcpy(E15_ConfFactoryDefault.E15_server_sim.ServerPort, "443");
//	//strcpy(E15_ConfFactoryDefault.E15_server_sim.Apn, "internet");
//	//E15_ConfFactoryDefault.E15_server_sim.SimSlot = 0;
//	strcpy(E15_ConfFactoryDefault.EBS_server_sim.Id, "zaingprs");
//	strcpy(E15_ConfFactoryDefault.EBS_server_sim.Apn, "zaingprs");
//	strcpy(E15_ConfFactoryDefault.EBS_server_sim.Passwd, "123456");
//	strcpy(E15_ConfFactoryDefault.EBS_server_sim.ServerIP, "192.168.101.200");
//	strcpy(E15_ConfFactoryDefault.EBS_server_sim.ServerPort, "8181");
//	memset(E15_ConfFactoryDefault.EBS_server_sim.Apn, 0x0,sizeof(E15_ConfFactoryDefault.EBS_server_sim.Apn));
//	E15_ConfFactoryDefault.EBS_server_sim.SimSlot = 1;
//	//strcpy(E15_ConfFactoryDefault.shared_key,(char *) "8cbd45PcLKBfKzELLAaxjE9bK814JASya6FkSxsOg+w=");
//	                                                      //9BtvX5pPgoA+vrGYrpQT1NbUyzXoXHsgb8JAyfoa3G0=
//	//memset(E15_ConfFactoryDefault.user_id, 0,sizeof(E15_ConfFactoryDefault.user_id));
//	//memset(E15_ConfFactoryDefault.user_password, 0,sizeof(E15_ConfFactoryDefault.user_password));
//	//strcpy(E15_ConfFactoryDefault.user_full_name, "Ashrafcom");
//	//strcpy(E15_ConfFactoryDefault.terminal_id, "888811");
//	//strcpy(E15_ConfFactoryDefault.terminal_password, "123456");
//	//E15_ConfFactoryDefault.last_generated_uuid = 0;
//	strcpy(E15_ConfFactoryDefault.tms_host_url, "zap4all.com");
//	strcpy(E15_ConfFactoryDefault.tms_port_no, "80");
//	strcpy(E15_ConfFactoryDefault.tms_file_path, "figurationFile");
//	E15_ConfFactoryDefault.tms_conn_type = HTTP;
//	E15_ConfFactoryDefault.tms_chunk_size = 2000;
//	//strcpy(E15_ConfFactoryDefault.app_id, "SHRAFCOM-E15-PoS-2.0-1"); //SHRAFCOM-E15-PoS-2.0-1
//	sprintf(E15_ConfFactoryDefault.build_date_time,"%s %s",__DATE__, __TIME__ );
//	E15_ConfFactoryDefault.version = 2;
//	//E15_ConfFactoryDefault.vat = 17;
//	//E15_ConfFactoryDefault.stamp_duty = 2;
//	E15_ConfFactoryDefault.is_blocked = 0;
//	//E15_ConfFactoryDefault.upload_in_progress = 0;
//	//E15_ConfFactoryDefault.upload_patch_size = 10;
//	//E15_ConfFactoryDefault.upload_successful_squance = 0;
//	//E15_ConfFactoryDefault.upload_failer_receipt_count = 0;
//	E15_ConfFactoryDefault.currect_sim_slot = 0;
//	// EBS Parameters
//	strcpy(E15_ConfFactoryDefault.EBS_APP_NAME, "QAEBSGateway");
//	strcpy(E15_ConfFactoryDefault.EBS_TMK, "ABCDEF0123456789");
//	strcpy(E15_ConfFactoryDefault.EBS_Client_ID, "Ashrafcom");
//	strcpy(E15_ConfFactoryDefault.EBS_Terminal_ID, "15000005");
//	strcpy(E15_ConfFactoryDefault.EBS_TWK, "273e74af2a6c02af");
//
//	E15_config *saved_e15_conf = E15_GetConfiguration();
//	E15_LoadConfiguration(saved_e15_conf,sizeof(E15_config));
//
//
//	E15_ConfFactoryDefault.EBS_Audit_No = saved_e15_conf->EBS_Audit_No;
//
//	rv = &E15_ConfFactoryDefault;
//
//	//_TRACE( "<---- %s()\n", __func__ );
//	return rv;
//}

//**************************************************************
/**
 * @brief	Load configuration info. from flash rom
 *
 */
RESULT_GSYS_ID E15_LoadConfiguration() {
	RESULT_GSYS_ID rv = GSYS_SUCCESS;
	int ret;
	// Read from Flash Room
	memcpy((unsigned char *)&E15_CONFIGURATION, (unsigned char *)CONFIG_DATA_ADDRESS, sizeof(E15_config));

	return rv;
}
//********************************************************************************
/**
 * @brief	Save configuration info. to flash rom
 *
 */
RESULT_GSYS_ID E15_SaveConfiguration() {
	RESULT_GSYS_ID rv = GSYS_SUCCESS;
	int ret;

	ret = FlashWrite((unsigned char *)CONFIG_DATA_ADDRESS ,(unsigned char *)&E15_CONFIGURATION, sizeof(E15_config));
	if (ret) {
		rv = GSYS_FAIL;
	}

	return rv;
}
