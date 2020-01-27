#ifndef SEARCH_H
#define SEARCH_H

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;
#include"prototypes.h"
#include"structure.h"

#define MAX_SIZE 100

struct student s[MAX_SIZE];
int i=0;
int currentSize=0;
char mygetch();
char key[20];
char fname[]={"Management.dat"};
char l_TIME[20];
char l_DATE[20];


/*Serch by name, blood group,scholl,mobile number,mail adress*/

void search(char key[],search_t type)
{
	int c ,found=0;
	strtolower(key);
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
	   cout<<"nSorry no record found~~~~"<<endl;
	   {
	   	if(!found)
	   	cout<<"Record is not in the database~~~~ "<<endl;
	   }

}
#endif //SEARCH_H
