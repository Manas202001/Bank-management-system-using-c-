#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<process.h>
using namespace std;
//void gotoxy(short x, short y);
void gotoxy(short x, short y)           //definition of gotoxy function//
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
class account
{
protected:
    double loan_amount,interest_rate,number_of_years,total_amount,monthly_amount,loan_paid,pl;
	int acno,icheck;
	int d[10],b;


public:
    char name[50],mob_no[50],dob[50];
void create_account(int n)
{
	system("CLS");
	Sleep(1000);
	gotoxy(80,14);
	cout<<"-) Account number generated : "<<n;
	Sleep(1000);
	gotoxy(80,17);
	cout<<"-) Enter the Name of the Account holder :  ";
	cin.ignore();
	cin.getline(name,sizeof(name));
	//cout<<"Enter age of account holder : ";
	//cin>>age;
	Sleep(1000);
	gotoxy(80,20);
	cout<<"-) Enter mobile number of account holder : ";
	cin.getline(mob_no,10);
	Sleep(1000);
	gotoxy(80,23);
	cout<<"-) Enter date of birth of account holder : ";
	cin.getline(dob,10);
	Sleep(1000);
	gotoxy(80,26);
	cout<<"-) Enter The Initial amount : ";
	cin>>b;
	Sleep(1000);
	gotoxy(77,32);
	cout<<"--------------------Account Created--------------------";
	Sleep(1000);
}

void show_account(int c,int type)
{
    int abc;
    abc=strcmp(name,"none");
    if(abc==0)
    {
		gotoxy(77,20);
		Sleep(1000);
        cout<<"Your account has already been deleted from our bank";
    }
    else
    {
		system("Cls");
		gotoxy(80,10);
		Sleep(1000);
	cout<<"Account No. : "<<c;
		gotoxy(80,12);
		Sleep(1000);
	cout<<"Account Holder Name : ";
	cout<<name;
	if(type==1)
		{
			gotoxy(80,14);
			Sleep(1000);
			cout<<"Type of Account : Saving";
		}
	else if(type==0)
		{
			gotoxy(80,16);
			Sleep(1000);
			cout<<"Type of Account : Current ";
		}
			gotoxy(80,18);
			Sleep(1000);
			cout<<"Balance amount : "<<b;
			gotoxy(80,20);
			Sleep(1000);
			cout<<"Date of birth: "<<dob;
			gotoxy(80,22);
			Sleep(1000);
			cout<<"Mobile no.: "<<mob_no;

    }
	getch();
}
        void modify()
                     {

                     	system("CLS");
                     	int num;
                     	gotoxy(80,14);
						Sleep(1000);
                        cout<<"Enter 1 for modify account holder name:";
                        
                        gotoxy(80,17);
						Sleep(1000);
                        cout<<"Enter 2 for modify mobile no.:";
                        
                        gotoxy(80,20);
						Sleep(1000);
                        cout<<"Enter 3 for modify date of birth :";
                        cin>>num;
                        switch(num)
                        {
                            case 1:system("Cls");
								gotoxy(80,14);
								Sleep(1000);
                                cout<<"Enter the changed Name of the Account holder : ";
                                cin.ignore();
                                cin.getline(name,sizeof(name));
                                break;
                            case 2:system("Cls");
								gotoxy(80,17);
								Sleep(1000);
                                cout<<"Enter  the changed mobile number of account holder : ";
                                cin.getline(mob_no,11);
                                break;
                            case 3:system("Cls");
								gotoxy(80,20);
								Sleep(1000);
                                cout<<"Enter  changed date of birth of account holder : ";
                                cin.getline(dob,10);
                                break;
                            default:
                                cout<<"Enter valid option";

                        }

}
 void del()
 {
     system("CLS");
     strcpy(name,"none");
     strcpy(dob,"none");
     strcpy(mob_no,"none");
	 gotoxy(80,14);
	 Sleep(1000);
     cout<<"Your account  is deleted successfully";
     getch();
 }
};

class loan :virtual public account
{
	public :
		char Y,N;
		int pk=0;
	void g_loan(int lnat)
{	system("Cls");
    loan_amount=lnat;
	gotoxy(77,10);
	Sleep(1000);
	cout<<"Entered the loan amount: "<<loan_amount;
	gotoxy(77,12);
	Sleep(1000);
	cout<<"Enter the interest rate: ";
	gotoxy(77,14);
	Sleep(1000);
	cin>>interest_rate;
	gotoxy(77,16);
	cout<<"The number of years: ";
	Sleep(1000);
	cin>>number_of_years;


	total_amount=loan_amount+(number_of_years*loan_amount*(interest_rate/100.00));
	monthly_amount=total_amount/(number_of_years*12);
	gotoxy(77,18);
	Sleep(1000);
	cout<<"Total amount to be paid: "<<total_amount;
	gotoxy(77,20);
	Sleep(1000);
	cout<<"Total interest "<<(number_of_years*loan_amount*(interest_rate/100.00));
	gotoxy(77,22);
	Sleep(1000);
	cout<<"Monthly amount to be paid: "<<monthly_amount;
	gotoxy(77,24);
	Sleep(1000);
	cout<<"Press Y/N if you agree/Disagree to take loan ";
	cin>>Y;
	if(Y=='Y')
	{
	b=b+loan_amount;
	system("Cls");
	gotoxy(77,20);
	Sleep(1000);
	cout<<"---------------Loan granted---------------";
	getch();
}
getch();

}

/*void monthly_install()
{
		b=b-monthly_amount;
		loan_paid=monthly_amount+loan_paid;
		pl=total_amount-loan_paid;
		system("CLS");
		gotoxy(77,14);
		Sleep(3000);
		cout<<"Current balance in account after deduction of monthly amount"<<monthly_amount<<"    is   "<<  b;
		Sleep(8000);
		pk++;
}*/
/*void search_loan()
{
	if(pk!=0)
	{
	gotoxy(80,24);
    cout<<"loan paid : "<<loan_paid;
	gotoxy(80,25);
    cout<<"loan pending with Interest: "<<pl;
    }
    else{
	    system("Cls");
		gotoxy(77,20);
    cout<<"-----You haven't paid any monthly installment or have not taken any loan from bank-----";
		}
    getch();
	
}*/
};
class sav_acc :virtual public account,virtual public loan
{
	public :
			int w[10],CI[10],i=1,j=1,l=1,x=1,y=1,z=1;
			void monthly_install()
{
		b=b-monthly_amount;
		loan_paid=monthly_amount+loan_paid;
		pl=total_amount-loan_paid;
		system("CLS");
		gotoxy(77,14);
		Sleep(3000);
		cout<<"Current balance in account after deduction of monthly amount"<<monthly_amount<<"    is   "<<  b;
		Sleep(8000);
		pk++;
}
void search_loan()
{
	if(pk!=0)
	{
	gotoxy(80,24);
    cout<<"loan paid : "<<loan_paid;
	gotoxy(80,25);
    cout<<"loan pending with Interest: "<<pl;
    }
    else{
	    system("Cls");
		gotoxy(77,20);
    cout<<"-----You haven't paid any monthly installment or have not taken any loan from bank-----";
		}
    getch();
	
}
    void deposit()
    {
		gotoxy(80,28);
        cout<<"Enter the amount to be added into an account : ";
        cin>>d[i];
        b=b+d[i];
		Sleep(1000);
		gotoxy(80,30);
        cout<<"Deposited "<<d[i]<<" Rs to your account, your current balance is "<<b<<"";
		Sleep(1000);
        i+=1;
		getch();
    }
   void intrest()
		{
			Sleep(1000);
			gotoxy(80,28);
			double principle = b, rate = 10.25, time;
           cout<<"Enter time for compound interest:";
		   Sleep(1000);
		   gotoxy(80,30);
		   cout<<"->";
		   cin>>time; 
           double CI = principle * (pow((1 + rate / 100), time));
		   gotoxy(80,30);
		   Sleep(1000);
           cout << "-) Compound interest is " <<CI-b;
      	   b=CI;
		   getch();
        }
    void withdraw()
        {
            int k=1;
			gotoxy(80,28);
        cout<<"Enter amount to withdraw from account :";
		Sleep(1000);
        cin>>w[k];
        if (w[k]>b)
        {
			gotoxy(65,30);
            cout<<"----------Entered amount greater than amount in the account----------";
			Sleep(1000);
        }
        else
        {
        b=b-w[l];
		gotoxy(65,34);
        cout<<"-----Withdraw "<<w[l]<<" Rs from your account, your current balance is-----"<<b<<"\n";
		Sleep(1000);
        l+=1;
        }
		getch();
        }
    void transaction()
    {
        while (i-=1)
        {
			Sleep(1000);
            cout<<"Deposited "<<d[i]<<" Rs to your account"<<"\n";
        }
        while(j-=1)
        {
			Sleep(1000);
            cout << "-) Compound interest is " << CI[j];
        }
        while(l-=1)
        {
			Sleep(1000);
            cout<<"-----Withdraw "<<w[l]<<" Rs from your account-----"<<"\n";
        }
		getch();
    }

};
class curr_acc:virtual public account,virtual public loan
{
	public:
			int w[10],CI[10],i=1,j=1,l=1,x=1,y=1,z=1;
			void monthly_install()
{
		b=b-monthly_amount;
		loan_paid=monthly_amount+loan_paid;
		pl=total_amount-loan_paid;
		system("CLS");
		gotoxy(77,14);
		Sleep(3000);
		cout<<"Current balance in account after deduction of monthly amount"<<monthly_amount<<"    is   "<<  b;
		Sleep(8000);
		pk++;
}
void search_loan()
{
	if(pk!=0)
	{
	gotoxy(80,24);
    cout<<"loan paid : "<<loan_paid;
	gotoxy(80,25);
    cout<<"loan pending with Interest: "<<pl;
    }
    else{
	    system("Cls");
		gotoxy(77,20);
    cout<<"-----You haven't paid any monthly installment or have not taken any loan from bank-----";
		}
    //getch();
	
}
	void deposi()
    {
		Sleep(1000);
		gotoxy(80,28);
        cout<<"Enter the amount to be added into an account : ";
		gotoxy(80,30);
		Sleep(1000);
		cout<<"->";
        cin>>d[x];
		Sleep(1000);
        b=b+d[x];
		gotoxy(80,30);
        cout<<"Deposited "<<d[x]<<" Rs to your account, your current balance is "<<b<<"\n";
		Sleep(1000);
        x+=1;	//getch();
    }

	void draw()
    {
		gotoxy(80,28);
        cout<<"Enter amount to withdraw from account :";
        cin>>w[y];
        if (w[y]>b)
        {	
			gotoxy(65,30);
			Sleep(1000);
            cout<<"----------Entered amount greater than amount in the account----------";
        }
        else
        {
        b=b-w[y];
		Sleep(1000);
			gotoxy(77,32);
        	cout<<"---------------MONEY WITHDRAWAL SUCESSFULL---------------";
			Sleep(1000);
			gotoxy(65,34);
        cout<<"-----Withdraw "<<w[y]<<" Rs from your account, your current balance is-----"<<b<<"\n";
		Sleep(1000);
        y+=1;
        }
//		getch();
    }
    void check()
		{
		
	if(b<999&&b>0)
	{
	
		gotoxy(70,32);
		Sleep(1000);
		cout<<"-----Min balance limit is 1000 therefore penalty is imposed of RS.100-----";
		b=b-100;
//		getch();
    }
	   
	   else if(b>0&&b>=1000)
	   {
		   gotoxy(70,32);
		   cout<<"---------------No Penalty Imposed---------------";
		   //getch();
	   }
	   
	
}
       void checkbook()
		{	system("Cls");
			gotoxy(77,20);
			cout<<"----------Your checkbook would be issued shortly----------";
			Sleep(1000);
//			getch();
		}
void transaction()
        {
			system("Cls");
        while (x-=1)
        {
			Sleep(1000);
            cout<<"Deposited "<<d[x]<<" Rs to your account"<<"\n";
			
        }
        while(y-=1)
        {
			Sleep(1000);
            cout<<"Withdraw "<<w[y]<<" Rs from your account"<<"\n";
        }
        }
        getch();
};

int main()
{
	curr_acc ca[20];
    sav_acc sa[10];
	char u[10],iu[10];
	char c1='p',c2='a',c3='s',c4='s',p1,p2,p3,p4;
	int n,num,q,t,y,a=1,o=10,ti,type;

	strcpy(iu,"project");
l:	system("CLS");
    system("COLOR 8F");
	gotoxy(90,13);
	cout<<"--------------------";
	gotoxy(90,14);
	cout<<"     L O G I N ";
	gotoxy(90,15);
	cout<<"--------------------";
    gotoxy(90,20);
	cout<<"USERNAME--> ";
	cin>>u;
	gotoxy(90,22);
	cout<<"PASSWORD--> ";
	p1=getch();
	cout<<"*";
	p2=getch();
	cout<<"*";
	p3=getch();
	cout<<"*";
	p4=getch();
	cout<<"*";
	n=strcmp(iu,u);
	if(n==0&&c1==p1&&c2==p2&&c3==p3&&c4==p4)
	{
			gotoxy(78,28);
		cout<<"................ACCESS GRANTED...............";
		Sleep(1000);
		 for(int i=1;i<=100;++i)
    {
                       Sleep(20);
                       system("cls");
					   gotoxy(82,12);
                       cout<<"B A N K  M A N A G E M E N T  S Y S T E M ";
					   gotoxy(92,20);
                       cout<<"  LOADING..."<<i<<"%";
                       if(i==100)
                       Sleep(3000);
    }
    system("cls");
	w:	system("CLS");
		system("COLOR 8F");
	    gotoxy(86,7);
		cout<<"--------------------------------";
		gotoxy(86,8);
		cout<<"C  O  D  E  R' S     B  A  N  K ";
		gotoxy(86,9);
		cout<<"--------------------------------";
		gotoxy(60,14);
		cout<<"1-) Create a New account";
		gotoxy(120,14);
		cout<<"2-) Make Transactions in existing account";
		gotoxy(60,17);
		cout<<"3-) Modify an account ";
		gotoxy(120,17);
		cout<<"4-) Mini Statement";
		gotoxy(60,20);
		cout<<"5-) Modify username or password";
		gotoxy(120,20);
		cout<<"6-) Logout";
		gotoxy(60,23);
		cout<<"7-) Loan";
		gotoxy(120,23);
		cout<<"8-) Passbook reciept";
		gotoxy(60,26);
		cout<<"9-) Delete an account ";
		gotoxy(85,30);
		cout<<"Enter a number to make a choice => ";
		cin>>num;
		switch(num)
		{
			case 1:
			y:	system("CLS");
			    system("color 8F");
				Sleep(1000);
			    gotoxy(58,16);
			    cout<<"------------------------Enter the type of account you want to create------------------------";
				Sleep(1000);
			    gotoxy(60,24);
				Sleep(1000);
				cout<<"1. Create a saving account";
				Sleep(1000);
				gotoxy(118,24);
				cout<<"2. Create a current account";
				gotoxy(99,26);
				cin>>t;
				if(t==1)
				{
				sa[a].create_account(a);
	            a++;
	            goto w;
	            }
	            else if(t==2)
	            {
	            		ca[o].create_account(o);
	                    o++;
	                    goto w;
				}
				else
				{
					gotoxy(92,15);
					cout<<" Select a valid option ";
					getch();
					system("CLS");
					goto y;
				}
				break;
			case 2:
				system("CLS");
				system("color 8F");
				Sleep(1000);
				gotoxy(80,14);
				cout<<"Enter your account number : -> ";
				getch();
					cin>>ti;
					if(ti>0&&ti<a)
				a:	{
						system("CLS");
						gotoxy(80,10);
						cout<<"---------------SAVING ACCOUNT---------------";
						gotoxy(80,13);
						cout<<"<-: Choose a Option :->";
						gotoxy(80,16);
						cout<<"-) 1.Deposit ";
						gotoxy(80,19);
						cout<<"-) 2.Withdrawal ";
						gotoxy(80,22);
						cout<<"-) 3.To check how much interest have been given on your account ";
						gotoxy(80,25);
						cout<<"->";
						cin>>num;
						switch(num)
						{
							case 1:
								sa[ti].deposit();
                                break;
                            case 2:
                                sa[ti].withdraw();
                                break;
                            case 3:
								sa[ti].intrest();
								break;

                            default:
                            cout<<"\nEnter a valid option";
                                goto a;
						}
					goto w;
				    }
					else if(ti>0&&ti<o)
				b:	{
						system("CLS");
						gotoxy(80,10);
						cout<<"---------------CURRENT ACCOUNT---------------";
						gotoxy(80,13);
						cout<<"<-: Choose a Option :->";
						gotoxy(80,16);
						cout<<"-) 1.Deposit ";
						gotoxy(80,19);
						cout<<"-) 2.Withdrawal ";
						gotoxy(80,22);
						cout<<"-) 3.Checkbook ";
						gotoxy(80,25);
						cout<<"-) 4.Penalty Conditions";
						gotoxy(80,28);
						cout<<"->";
						cin>>num;
						switch(num)
						{
							case 1:
								ca[ti].deposi();
								getch();
                                break;
                            case 2:
								ca[ti].draw();
								getch();
                                break;
                            case 3:
								ca[ti].checkbook();
								getch();
								break;
							case 4:
								ca[ti].check();
								getch();
								break;
                            default:
                                cout<<"\n \n\n\nEnter a valid option";
                                Sleep(2000);
                                goto b;
                                break;
						}

					goto w;
                    }
					else
					{
						system("CLS");
						gotoxy(77,32);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
				break;
			case 3:
                    system("CLS");
                    gotoxy(80,10);
                    system("color 8F");
	                 cout<<"Enter your account number";
					 gotoxy(80,13);
					 cout<<"->";
					cin>>ti;
					if(ti>0&&ti<a)
					{
					type=1;
					sa[ti].modify();
					goto w;
				    }
					else if(ti>=10&&ti<o)
					{
					  type=0;
					ca[ti].modify();
					goto w;
				}
					else
					{
						system("CLS");
						gotoxy(77,32);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}
			    break;
			case 4:
			    {
					system("Cls");
					Sleep(1000);
					gotoxy(80,14);
			    cout<<"Enter your account number";
				Sleep(1000);
				gotoxy(80,16);
				cout<<"->";
					cin>>ti;
					if(ti>0&&ti<a)
					{
					type=1;
					sa[ti].transaction();
					getch();
					goto w;
				    }
					else if(ti>=10&&ti<o)
					{
					  type=0;
					ca[ti].transaction();
					getch();
					goto w;
				}
			   break;

				 break;
			case 5:
			k:	system("Cls");
				Sleep(1000);
				gotoxy(80,10);
				cout<<"<-: Choose what you want to modify:-> ";
				Sleep(1000);
				gotoxy(80,13);
				cout<<"-) 1.Change password ";
				Sleep(1000);
				gotoxy(80,16);
				cout<<"-) 2.Change username ";
				Sleep(1000);
				gotoxy(80,19);
				cout<<"->";
				cin>>q;
				if(q==1)
				{
					system("ClS");
						Sleep(1000);
						gotoxy(80,10);
					     cout<<"<-: Enter Existing password :->";
						 Sleep(1000);
						 gotoxy(80,13);
						 cout<<"->";
		                    p1=getch();
                            	cout<<"*";
                          	p2=getch();
                             	cout<<"*";
                        	p3=getch();
                               	cout<<"*";
                        	p4=getch();
                               	cout<<"*";
	            	if(c1==p1&&c2==p2&&c3==p3&&c4==p4)
		          {
		          	system("CLS");
					Sleep(1000);
					gotoxy(77,32);
		        	cout<<"---------------Correct Existing password---------------";
		            Sleep(2000);
					system("Cls");
					gotoxy(80,10);
	              	cout<<"<-: Enter new password :->";
					Sleep(1000);
					gotoxy(80,13);
					cout<<"->";
	            	c1=getch();
                  	cout<<"*";
                 	c2=getch();
                  	cout<<"*";
                	c3=getch();
                 	cout<<"*";
	                c4=getch();
	                cout<<"*";
					Sleep(1000);
					gotoxy(70,32);
	                cout<<"---------------Password changed sucessfully---------------";
	                Sleep(3000);
	                goto w;

	            }
	                          else
	                       {
	                     	system("CLS");
							Sleep(1000);
							gotoxy(75,19);
	            	        cout<<"-----Enter Correct existing password-----";
	            	        Sleep(2000);
	            	         goto k;
				          }
				}
				else if(q==2)
				{	 system("Cls");
					 Sleep(1000);
					 gotoxy(80,10);
				     cout<<"<-: Enter Existing username :->";
					 Sleep(1000);
					 gotoxy(80,13);
					 cout<<"->";
				     cin>>u;
				          n=strcmp(iu,u);
                                        	if(n==0)
                                        	{
											  system("Cls");
											  Sleep(1000);
											  gotoxy(77,32);
	                                          cout<<"---------------Username is correct---------------";
	                                          Sleep(3000);
	                                          system("CLS");
											  Sleep(1000);
											  gotoxy(80,10);
	                                          cout<<"-) Enter New Username(Max. word limit is 10)";
											  Sleep(1000);
											  gotoxy(80,13);
											  cout<<"->";
	                                          fflush(stdin);
		                                      gets(u);
		                                      strcpy(iu,u);
											  Sleep(1000);
											  gotoxy(70,32);
											  cout<<"---------------Username Changed Successfully---------------";
											  getch();
		                                      goto w;

           	                                }
	                                          else
	                                          {
									            system("CLS");
												Sleep(1000);
												gotoxy(75,32);
                                            cout<<"Entered username is wrong, Please try Again-";
                                            Sleep(3000);
                                            goto k;
					                       }

				}
				 break;
			
			case 7:
			    int inco,lnat;
			    system("CLS");
				gotoxy(70,14);
				Sleep(1000);
				cout<<"-) 1.To check your loan Eligibility & avail loan Facility";
				gotoxy(70,17);
				Sleep(1000);
			    cout<<"-) 2.To pay monthly Installment";
				gotoxy(70,20);
				Sleep(1000);
				cout<<"-) 3.To check pending loan amount";
				gotoxy(70,23);
				Sleep(1000);
				cout<<"->";
				cin>>num;
				switch(num)
				{
				case 1:
					system("Cls");
					gotoxy(70,14);
					Sleep(1000);
					cout<<"-) Enter your monthly income -> ";
					cin>>inco;
					gotoxy(70,17);
					Sleep(1000);
					cout<<"-) Enter the amount to apply for loan -> ";
					cin>>lnat;
					if(lnat>(inco*30))
					{
						gotoxy(55,30);
						Sleep(1000);
					cout<<"-----Eligibility Rule : the loan granted will not be more than 30 times of your salary-----";
					getch();
					goto w;
				}
					else
					{
						gotoxy(65,25);
						Sleep(1000);
						cout<<"You have cleared the Eligibility check for amount :"<<lnat;
						getch();
						system("Cls");
						gotoxy(80,10);
						Sleep(1000);
				h:	cout<<"-) To apply for Loan Right Now";
						gotoxy(80,13);
						Sleep(1000);
					cout<<"-) TO apply for loan later on";
						gotoxy(80,16);
						Sleep(1000);
					cout<<"->";
					cin>>num;
					if(num==1)
					{
						system("CLS");
						gotoxy(77,10);
						Sleep(1000);
			    	cout<<"---------------LOAN APPLICATION---------------";
						gotoxy(80,14);
						Sleep(1000);
		     		cout<<"Enter your account number -> ";
					cin>>ti;
					if(ti>0&&ti<a)
					{
				type=1;
				sa[ti].g_loan(lnat);
				goto w;
				    }
				else if(ti>=10&&ti<o)
					{
				type=0;
				ca[ti].g_loan(lnat);
				goto w;
				}
				else
					{
						system("CLS");
						gotoxy(77,30);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}
					}
					else if(num==2)
					goto w;
					else
					{
						gotoxy(77,30);
						Sleep(1000);
					cout<<"---------------Enter a valid option--------------- ";
					goto h;
			     	}
				    }
					break;
				case 2:
					system("Cls");
					int arr[10];
					gotoxy(80,14);
					Sleep(1000);
					cout<<"-) Enter your account number -> ";
					cin>>ti;
					if(ti>0&&ti<a)
					{
				type=1;
				sa[ti].monthly_install();
				goto w;
				    }
				   	else if(ti>=10&&ti<o)
					{
				type=0;
				ca[ti].monthly_install();
				goto w;
				}
				else
					{
						system("CLS");
						gotoxy(77,30);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}
					break;
					case 3:
						system("CLS");
						gotoxy(80,14);
						Sleep(1000);
						cout<<"-) Enter account number to check pending loan ->";
						cin>>ti;
						if(ti>0&&ti<a)
					{
					type=1;
					sa[ti].show_account(ti,type);
					sa[ti].search_loan();
					goto w;
				    }
					else if(ti>=10&&ti<o)
					{
					  type=0;
					ca[ti].show_account(ti,type);
					ca[ti].search_loan();
					getch();
					goto w;
				}
					else
					{
						system("CLS");
						gotoxy(77,30);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}
						break;
				}
				break;
			case 8:system("Cls");
					gotoxy(80,10);
					Sleep(1000);
					cout<<"-) Enter your account number ->";
					cin>>ti;
					if(ti>0&&ti<a)
					{
					type=1;
					sa[ti].show_account(ti,type);
					goto w;
				    }
					else if(ti>=10&&ti<o)
					{
					  type=0;
					ca[ti].show_account(ti,type);
					goto w;
				}
					else
					{
						system("CLS");
						gotoxy(77,30);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}
			    break;
			case 9:system("Cls");
						gotoxy(77,14);
						Sleep(1000);
			    cout<<"-) Enter The Account Number You Want To Delete ->";
					cin>>ti;
					if(ti>0&&ti<a)
					{
					type=1;
					sa[ti].del();
					goto w;
				    }
					else if(ti>=10&&ti<o)
					{
					  type=0;
					ca[ti].del();
					goto w;
				}
					else
					{
						system("CLS");
						gotoxy(77,30);
						cout<<"---------------Enter a valid account number---------------";
						Sleep(3000);
						goto w;
					}

			    break;
			case 6:
				goto l;
				break;
			default :
					gotoxy(77,30);
					Sleep(1000);
			   cout<<"---------------Enter a valid option--------------- ";
			   goto w;
			   break;
		}
    }}
	}
	else
	{
	system("CLS");
	gotoxy(77,30);
    cout<<"-----Wrong user name or password-----";
    Sleep(3000);
    system("CLS");
    goto l;
    }
    return 0;
}
/*void gotoxy(short x, short y)           //definition of gotoxy function//
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}*/







