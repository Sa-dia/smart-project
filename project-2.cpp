#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef enum {FIRST_NAME,LAST_NAME,SCHOOL_NAME,BLOOD_GROUP,MOBILE_NUMBER,MAIL_ADRESS} search_t;
#define MAX_SIZE 100
struct student
{   int id;
	char firstname[10];
	char lastname[10];
	char mobilenumber[10];
	char bloodgroup[10];
	char schoolname[20];
	char mailadress[30];
};

struct student s[MAX_SIZE];
int i=0;
int currentSize=0;
void addEntry();
void display();
void displayall(int);
void displaySingle(int);
void deleteEntry();
void search(char key[],search_t type);
void headlines();
void savetodatabase();
void readfromfile();
char fdata[]={"student.dtb"};
char mygetch();
char key[15];

int main()
{
	int ch,k,p;

	while(1){
		system("cls");
	printf("\n 1.addEntry \n 2.display \n 3.display all \n 4.delete Entry \n 5.search by first name \n 6.search by last name \n 7.search by school name \n 8.search by blood group \n 9. search by mobile number \n 10.search by mail adress  \n 11.read from file \n 12.save to database \n 13.exit");
	printf("\nEnter U`r Choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:addEntry();
		break;
		case 2:display();
		break;
		case 3:displayall(k);
		break;
		case 4:deleteEntry();
		break;
		
		case 5:printf("\nEnter U`r first name:");
		scanf("%s",key);
		search(key,FIRST_NAME);
		break;
		
		
		case 6:printf("\nEnter U`r last name:");
		scanf("%s",key);
		search(key,LAST_NAME);
		break;
		
		
		case 7:printf("\nEnter the school name:");
		scanf("%s",key);
		search(key,SCHOOL_NAME);
		break;
		
		case 8:printf("\nEnter blood group:");
		scanf("%s",key);   
		search (key,BLOOD_GROUP);
		break;
		
		case 9:printf("\nEnter mobile number: ");
		scanf("%s",key);
		search(key,MOBILE_NUMBER);
		break;
		
		
		case 10:printf("\nEnter mail adress:");
		scanf("%s",key);
		search(key,MAIL_ADRESS);
		break;
		
		case 11:readfromfile();
		break;
		case 12:savetodatabase();
		break;
		case 13:exit(0);}
		mygetch();
}
return 0;
}
void addEntry()
{
	printf("\nEnter the ID:");
	scanf("%d",&s[i].id);
	printf("\nEnter the first name:");
	scanf("%s",s[i].firstname);
	printf("\nEnter the last name:");
	scanf("%s",s[i].lastname);
	printf("\nEnter the mobile number:");
	scanf("%s",s[i].mobilenumber);
	printf("\nEnter the blood group:");
	scanf("%s",s[i].bloodgroup);
	printf("\nEnter the school name:");
	scanf("%s",s[i].schoolname);
	printf("\nEnter the mail adress:");
	scanf("%s",s[i].mailadress);
	++i;
	++currentSize;
	printf("\nStudent information is sucessfully added");
	{
		if(currentSize==100)
		printf("\nDatabase is full\n\n Sorry no student can be admitted");
	}
}
void headlines()
{   
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\nId   first name     last name      school name    mobile number  blood group    mail adress\n");
printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void display()
{
	int j,id;
	printf("\nEnter the ID:");
	scanf("%d",&id);
	for(j=0;j<currentSize;j++)
	{
	headlines();
	if(id==s[j].id)
	printf("%-5d%-15s%-15s%-15s%-15s%-15s%-15s",s[j].id,s[j].firstname,s[j].lastname,s[j].schoolname,s[j].mobilenumber,s[j].bloodgroup,s[j].mailadress);
	  else
	printf("\nSorry No record found~~~~~");
	 break;}
	
if(j<0||j>=currentSize)  
printf("\nthe Id is invalid\n");
}


void displaySingle(int j)
{
	printf("%-5d%-15s%-15s%-15s%-15s%-15s%-15s\n",s[j].id,s[j].firstname,s[j].lastname,s[j].schoolname,s[j].mobilenumber,s[j].bloodgroup,s[j].mailadress);
}


void displayall(int k)
{         
if(currentSize==0){
printf("\nNo student is admitted~~~~~");
return;}
headlines();
for(k=0;k<currentSize;k++)
displaySingle(k);
}

void search(char key[],search_t type)
{
	int c ,found=0;
	if(type==FIRST_NAME)
	{
   for(c=0;c<currentSize;c++)
   {
   	
   	if(strcmp(s[c].firstname,key)==0)
   	{
   		headlines();
   	displaySingle(c);
   	found=1;
	   }
   }
	    
}
	  else if(type==LAST_NAME)
	 {
   for(c=0;c<currentSize;c++)
   {
   	if(strcmp(key,s[c].lastname)==0)
   	{
   			headlines();
   	displaySingle(c);
   	found=1;}
	
	   } }
	   else if(type==SCHOOL_NAME)
	   {
      for(c=0;c<currentSize;c++)
   {
   	if(strcmp(key,s[c].schoolname)==0)
   	{	headlines();
	displaySingle(c);
   	found=1;}
	
	    }}
else if(type==BLOOD_GROUP)
{
   for(c=0;c<currentSize;c++)
   {
   	if(strcmp(key,s[c].bloodgroup)==0)
   	{
   	headlines();
   	displaySingle(c);
   	found=1;}
	
	   } }
      else if(type==MOBILE_NUMBER)
      {
   for(c=0;c<currentSize;c++)
   {
   	if(strcmp(key,s[c].mobilenumber)==0)
   	{
   	headlines();
   	displaySingle(c);
   	found=1;}
	
	   } }
else if(type==MAIL_ADRESS)
{
   for(c=0;c<currentSize;c++)
   {
   	if(strcmp(key,s[c].mailadress)==0)
   	{
   	headlines();
   	displaySingle(c);
   	found=1;}
	
	   } }
	   else
	   printf("\nSorry no record found~~~~");
	   {
	   	if(!found)
	   	printf("\nRecord is not in the database~~~~ ");
	   }

}


void savetodatabase()
{
	FILE *fp;
if((fp=fopen(fdata,"wb"))==NULL)
printf("\nNEw file is not created");

if((fwrite(&currentSize,sizeof(currentSize),1,fp))!=1)
printf("\nFile cannot be saved");	

if((fwrite(s,sizeof(s),1,fp))!=1)
printf("\nFile cannot be saved");
else
{
	printf("\nFile is saved sicessfully!!!");
}

fclose(fp);

	
}
void deleteEntry()
{
	int m,Id,n,count=0;
	if(currentSize==0)
	{
	printf("\nNo student admitted yet~~~~~~");}
	
	printf("\nEnter the student ID U want to delete:");
	scanf("%d",&Id);
	
	for(m=0;m<currentSize;m++)
	{
	if(Id==s[m].id)
	{
	for(n=m;n<currentSize;n++)
	{
	s[n].id=s[n+1].id;}
	
	currentSize-=1;
	count=1;	
	}}
	if(count==1)
	printf("\nThe student information is succesfully delete~~~~");
	
}










void readfromfile()
{
		FILE *fp;
if((fp=fopen(fdata,"rb"))==NULL)
printf("\nNEw file is not created");

if((fread(&currentSize,sizeof(currentSize),1,fp))!=1)
printf("\nFile cannot be saved");	

if((fread(s,sizeof(s),1,fp))!=1)
printf("\nFile cannot be saved");

fclose(fp);


}
char mygetch()
{
	char val;
	char rel;
	
	scanf("%c",&val);
	scanf("%c",&rel);
	return (val);
}

