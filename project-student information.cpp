#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

#include"prototypes.h"
#include"structure.h"
#include"functions.h"
#include"search.h"

void addEntry()
{
	char y,n,choice,m,mon;
	int measure,fee=4300;
cout<<"Enter U`r ID:";
cin>>s[i].id;
cout<<"Enter U`r first name:";
cin>>s[i].firstname;
cout<<"Enter U`r last name:";
cin>>s[i].lastname;
cout<<"Do U have nick name(y/n):";
cin>>choice;
if(choice=='y')
{
cout<<"Enter the nick name:";
cin>>s[i].nickname;}
else
strcpy(s[i].nickname,s[i].firstname);

cout<<"Enter U`r school name:";
cin>>s[i].schoolname;
cout<<"Enter U`r SSC year:";
cin>>s[i].sscyear;
cout<<"Enter U`r HSC year:";
cin>>s[i].hscyear;
cout<<"Enter HSC GPA:";
cin>>s[i].hscgpa;
fflush(stdin);
cout<<"Enter U`r blood group:";
cin>>s[i].bloodgroup;
again:
cout<<"Enter the mobile number:"<<endl;
cin>>s[i].mobilenumber;
measure=strlen(s[i].mobilenumber);
if(measure<11)
{
	cout<<"error!! re-entry";
	goto again;
}
cout<<"Enter U`r mail adress:";
cin>>s[i].mailadress;
	cout<<"Do you want to pay for this month(y/n):";
 	cin>>mon;
 	if(mon=='y')
 	{ {
 	cout<<"Enter the month name:";
 	cin>>s[i].month;}
 	cout<<"Do u want payment full(y/n):";
 	cin>>m;
 	if(m=='y')
 	{
 	cout<<"Enter the  payment:";
 	cin>>s[i].payment;}
 	if(m=='n')
 	{
 		cout<<"Enter U`r fee:";
 		cin>>s[i].advance;
 	s[i].dues=(fee-s[i].advance);
	 }}
	 if(mon=='n')
	 {
	 	cout<<"The student fee is pending~~~"<<endl;
	 }
++i;
++currentSize;

cout<<"Student information added sucessfully"<<endl;
{
	if(currentSize==MAX_SIZE)
	
	cout<<"Sorry student database is full"<<endl;
}
}
void headlines()
{
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"ID    First name     Last name     Nick name      School name     SSC year     HSC year     HSC GPA     Mobile number     Blood group     Mail adress"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void headlinespayment()
 {
 	cout<<"ID     First name     last name     MONTH     PAYMENT(tk)     ADVANCE(tk)     DUES(tk)"  <<endl;
 	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 }
 

void lastSaved()
{
	strcpy(l_TIME,__TIME__);
	strcpy(l_DATE,__DATE__);
}


void display()

{	
	int j=0,f_id,found=0;
	

	cout<<"Enter the ID:";
	cin>>f_id;
	for(j=0;j<currentSize;j++)
	{
	if(f_id==s[j].id)
	{
	headlines();
	displaySingle(j);
	found=1;
	break;
	}
}
	if(f_id!=0&&found==0)
	{
	cout<<"Sorry No record found~~~~~"<<endl;
	 }

	 if(j<0 && j>=currentSize)
	 {
	 	cout<<"Invalid ID~~~~~"<<endl;
	 }
	
}

 void displaypayment()
 {
 	int j=0,f_id,found=0;
	

	cout<<"Enter the ID:";
	cin>>f_id;
	for(j=0;j<currentSize;j++)
	{
	if(f_id==s[j].id)
	{
	headlinespayment();
	printf("%-5d%-20s%-15s%-15s%-15d%-15d%-15d\n",s[j].id,s[j].firstname,s[j].lastname,s[j].month,s[j].payment,s[j].advance,s[j].dues);
	found=1;
	break;
	}
}
	if(f_id!=0&&found==0)
	{
	cout<<"Sorry No record found~~~~~"<<endl;
	 }

 }
 


void displaySingle(int j)
{
printf("%-5d%-15s%-15s%-15s%-15s%-13d%-15d%-15f%-15s%-13s%-15s\n",s[j].id,s[j].firstname,s[j].lastname,s[j].nickname,s[j].schoolname,s[j].sscyear,s[j].hscyear,s[j].hscgpa,s[j].mobilenumber,s[j].bloodgroup,s[j].mailadress);
}

void displayAll(int k)
{         
if(currentSize==0){
cout<<"~~~~~~~~~~~~~~~~~~~~~~~No student is admitted~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
return;}

headlines();
for(k=0;k<currentSize;k++)
displaySingle(k);

if(s[k].id==0)
{
	for(k=0;k<currentSize;k++)
	break;
}
}


void strtolower(char *str)
{
	int len =strlen(str);
	int y;
	for(y=0; y<len ;y++)
	{
	str[y] = tolower(str[y]);}
	
	
}



void del()
{
	int m,Id,n,count=0;
	if(currentSize==0)
	{
	cout<<"\nNo student admitted yet~~~~~~"<<endl;}
	
	cout<<"\nEnter the student ID U want to delete:";
	cin>>Id;
	
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
	cout<<"The student information is succesfully delete~~~~"<<endl;
	
}

void remove()
{
	char sel;
	char new_file[20];
cout<<"Do u want make a copy of it(y/n):";
cin>>sel;
if(sel=='y')
{
	cout<<"Enter the new File name:";
	cin>>new_file;
	
	ofstream file(new_file,ios::out|ios::binary);
	
	file.write((char *)   s ,  sizeof(s));
	file.write((char *)  &currentSize , sizeof(currentSize));
	file.write((char *)  l_TIME, sizeof(l_TIME));
	file.write((char *)  l_DATE, sizeof(l_DATE));
	cout<<"The file is coppied sucessfully to "<<new_file;
	file.close();

		
strcpy(fname,new_file);

cout<<"Do u want delete it......(y/n)";
cin>>sel;
if(sel=='y')
{
	remove(fname);
	cout<<"file is deleted sucessfully..."<<endl;}
	else
	return;
}
	else
{
		remove(fname);
	cout<<"file is deleted sucessfully..."<<endl;}
	
		
}

void savetodatabase()
{
	lastSaved();
	ofstream file(fname,ios::out|ios::binary);
	if(file==NULL)
	
	cout<<"File is not created"<<endl;
	else
	file.write((char *)   s ,  sizeof(s));
	file.write((char *)  &currentSize , sizeof(currentSize));
	file.write((char *)  l_TIME,sizeof(l_TIME));
	file.write((char *)  l_DATE,sizeof(l_DATE));
	cout<<"~~~~~~~File added sucessfully~~~~"<<endl;
	
	file.close();
}

void readfromfile()
{
	ifstream file(fname,ios::in|ios::binary);
	if(file==NULL)
	
	cout<<"File is not created"<<endl;
	else
	file.read((char *)   s ,  sizeof(s));
	file.read((char *)  &currentSize , sizeof(currentSize));
	file.read((char *)  l_TIME,sizeof(l_TIME));
	file.read((char *)  l_DATE,sizeof(l_DATE));
	
	file.close();
}


char mygetch()
{
	string val;
	string rel;
	
	getline(cin,val);
	getline(cin,rel);
}



