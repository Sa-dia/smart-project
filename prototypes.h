#ifndef PROTOTYPES_H
#define PROTOTYPES_H
/*Enumrator for search option*/
typedef enum {FIRST_NAME,LAST_NAME,SCHOOL_NAME,BLOOD_GROUP,MOBILE_NUMBER,MAIL_ADRESS} search_t;
using namespace std;

/*ALL FUNCTION PROTOTYPES*/


void strtolower(char *str);
void addEntry();
void display();
void displayAll(int);
void headlinespayment();
 void displaypayment();
void headlines();
void lastSaved();
void displaySingle(int);
void del();
void search(char key[],search_t type);
void savetodatabase();
void readfromfile();
void remove();

#endif //PROTOTYPES_H
