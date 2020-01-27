#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include"search.h"

/*Case to select function*/
int main()
{
	int ch,j,k,dh;
	readfromfile();
	while(1)
     {
	   system("cls");
		cout<<"Last saved Time "<<l_TIME<<endl;
		cout<<"Last saved Date is "<<l_DATE<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STUDENT DATABASE SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"Compile Time "<<__TIME__<<endl;
		cout<<"Recent Date  is "<<__DATE__<<endl;
		cout<<"\n 1.add entry \n 2.display \n 3.displayAll \n 4.delete \n 5.Search mode \n 6.remove \n 7.display payment \n 9.save to database \n 10.exit"<<endl;
		cout<<"Enter U`r choice:";
		cin>>ch;
		switch(ch)
        {
              case 1:addEntry();
			  break;
			  case 2:display();
			  break;
			  case 3:displayAll(k);
			  break;
			  case 4:del();
			  break;
			  case 5:
				cout<<"~~~~Search Mode~~~"<<endl;
			  cout<<" 1.search by first name\n 2.search by last name\n 3.search by school name\n 4.search by blood group\n 5.search by mobile number\n 6.search by mail adress\n  ";
			   cin>>dh;
			   switch(dh)
			   {
			   	case 1:printf("\nEnter U`r first name:");
		scanf("%s",key);
		search(key,FIRST_NAME);
		break;
		
		
		case 2:printf("\nEnter U`r last name:");
		scanf("%s",key);
		search(key,LAST_NAME);
		break;
		
		
		case 3:printf("\nEnter the school name:");
		scanf("%s",key);
		search(key,SCHOOL_NAME);
		break;
		
		case 4:printf("\nEnter blood group:");
		scanf("%s",key);   
		search (key,BLOOD_GROUP);
		break;
		
		case 5:printf("\nEnter mobile number: ");
		scanf("%s",key);
		search(key,MOBILE_NUMBER);
		break;
		
		
		case 6:printf("\nEnter mail adress:");
		scanf("%s",key);
		search(key,MAIL_ADRESS);
		break;
		}
		break;
		case 6:remove();
		break;
		case 7:displaypayment();
 		break;
			  case 9:savetodatabase();
			  break;
			  case 10:exit(0);}
			  mygetch();}
		}
#endif // FUNCTIONS_H			
