/*======================================================================*/
/*																		*/
/*								E15_API									*/
/*																		*/
/*======================================================================*/
int main1();
extern int json_parse(char* body);
extern char num_rec[65];
extern char num_rec1[65];
extern char num_rec2[65];
//extern char num_rec2[65];
extern char num_rec3[65];
extern char num_rec4[129];
extern char num_rec5[65];
extern char num_rec6[65];
extern char num_rec7[65];
extern char num_rec8[65];
extern char num_rec9[65];
extern char num_rec10[65];
extern char num_rec11[65];
extern char num_rec12[65];
extern char num_rec13[65];
extern char num_rec14[65];
extern char num_rec15[65];
extern char num_rec16[65];
extern char num_rec17[65];
extern char fees[65];
extern char fees1[65];
extern char fees2[65];
extern char fees3[65];
extern char fees4[65];
extern char fees5[65];
extern char fees6[65];
extern char fees7[65];
extern char fees8[65];
extern char fees9[65];
extern char fees10[65];
extern char fees11[65];
extern char fees12[65];
extern char fees13[65];
extern char fees14[65];
extern char fees15[65];
extern char fees16[65];
extern char fees17[65];
extern char classn1[65];
extern char classn1_1[65];
extern char classn1_2[65];
extern char classn2[65];
extern char classn2_1[65];
extern char classn2_2[65];
extern char classn3[65];
extern char classn3_1[65];
extern char classn3_2[65];
extern char classn4[65];
extern char classn4_1[65];
extern char classn4_2[65];
extern char classn5[65];
extern char classn5_1[65];
extern char classn5_2[65];
extern char classn6[65];
extern char classn6_1[65];
extern char classn6_2[65];
extern char classn7[65];
extern char classn7_1[65];
extern char classn7_2[65];
extern char classn8[65];
extern char classn8_1[65];
extern char classn8_2[65];
extern char classn9[65];
extern char classn9_1[65];
extern char classn9_2[65];
extern char classn10[65];
extern char classn10_1[65];
extern char classn10_2[65];
extern char classn11[65];
extern char classn11_1[65];
extern char classn11_2[65];
extern char classn12[65];
extern char classn12_1[65];
extern char classn12_2[65];
extern char classn13[65];
extern char classn13_1[65];
extern char classn13_2[65];
extern char classn14[65];
extern char classn14_1[65];
extern char classn14_2[65];
extern char classn15[65];
extern char classn15_1[65];
extern char classn15_2[65];
extern char classn16[65];
extern char classn16_1[65];
extern char classn16_2[65];
extern char classn17[65];
extern char classn17_1[65];
extern char classn17_2[65];
extern char classn18[65];
extern char classn19[65];
extern char classn1[65];
extern char classn1[65];
extern char classn1[65];
extern char classn1[65];
extern char classn1[65];
extern char classn1[65];
extern char classn1[65];

extern char feesn1[65];
extern char feesn1_1[65];
extern char feesn1_2[65];
extern char feesn2[65];
extern char feesn2_1[65];
extern char feesn2_2[65];
extern char feesn3[65];
extern char feesn3_1[65];
extern char feesn3_2[65];
extern char feesn4[65];
extern char feesn4_1[65];
extern char feesn4_2[65];
extern char feesn5[65];
extern char feesn5_1[65];
extern char feesn5_2[65];
extern char feesn6[65];
extern char feesn6_1[65];
extern char feesn6_2[65];
extern char feesn7[65];
extern char feesn7_1[65];
extern char feesn7_2[65];
extern char feesn8[65];
extern char feesn8_1[65];
extern char feesn8_2[65];
extern char feesn9[65];
extern char feesn9_1[65];
extern char feesn9_2[65];
extern char feesn10[65];
extern char feesn10_1[65];
extern char feesn10_2[65];
extern char feesn11[65];
extern char feesn11_1[65];
extern char feesn11_2[65];
extern char feesn12[65];
extern char feesn12_1[65];
extern char feesn12_2[65];
extern char feesn13[65];
extern char feesn13_1[65];
extern char feesn13_2[65];
extern char feesn14[65];
extern char feesn14_1[65];
extern char feesn14_2[65];
extern char feesn15[65];
extern char feesn15_1[65];
extern char feesn15_2[65];
extern char feesn16[65];
extern char feesn16_1[65];
extern char feesn16_2[65];
extern char feesn17[65];
extern char feesn17_1[65];
extern char feesn17_2[65];
extern char class_no[65];

//extern char fees[65];
int jsoneq(const char *json, jsmntok_t *tok, const char *s);
// extern static int jsoneq(const char *json, jsmntok_t *tok, const char *s);
//extern char details jason[];
//extern int discount;
//extern char identity[];
//extern char identity_type[];
//extern char key[];
//extern char new_password[];
//extern char old_password[];
//extern char payer_name[];
//extern char payment_details jason[];
//extern char payment_methods jason[];
//extern char receipt_no[];
//extern int response_code;
//extern char response_message[];
//extern char service[];
//extern char summary jason[];
//extern char terminal_id[];
//extern double total_amount;
//extern char unit_name[];
//extern char *service ;
extern char user_id[65];
//extern char service1[65];
extern char service2[65];
extern char service3[65];
extern char service4[65];
extern char service5[65];
extern char service6[65];
extern char service7[65];
extern char service8[65];
extern char service9[65];
extern char service10[65];
extern char service11[65];

extern char old_pass[65];
extern char user_password[65];
extern char *user_cpy[65];
//extern char uuid[];
//extern bool has_vat;
//extern double amount;
//extern char authorization[];
//extern date x_e15_date;
//extern char app_id[];
//extern int version;
typedef struct {
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
//	E15_service services1[50];
	double total;
	double amount_due;
	char total_in_word[1024];
	int currency_id;
	int payment_method_id;
	int discount;
	char collector_name[256];
	int is_copy;
	char PAN[30];
	char PIN[30];
	char card_holder_name[256];
	char card_expiry_date[10];
	char auth_code[50];
	char transaction_id[100];
	int is_successful;
} E15_receipt1;
extern void Online_Login(void);
extern void Offline_Login(void);

extern size_t utf8_to_farsi(char * output, char *input, size_t length);
extern unsigned int to_latin9( unsigned int code);
//extern static inline unsigned int to_arabicc(const unsigned int code);
extern int utf8_to_iso_8859_66(char * const output,const char * const input,const int length);
extern int iso_8859_6_to_utf88(char * const output,const char * const input,const int length);
extern int fix_connected_charss(unsigned char* stream);		
char *right2leftt( const char *stream);	
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200
#define OK 200

//jsmntok_t t[65];
