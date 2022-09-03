#include<bits/stdc++.h>
using namespace std;

// project working on turbo C++
//~~~~~~~~~~~~~~~~~~~~~
//      CLASS NAME: DATE
//      DETAILS: IT CONTROLS OVER ALL THE DATE FNS.
//~~~~~~~~~~~~~~~~~~~~~
class DATE
{
public :
void EXTEND_DATE(int,int,int) ;//declaration of fn
void CURRENT_DATE() ;	   //EXTEND_DATE() &
//CURRENT_DATE().
int  day, month, year ;
} ;


 
//~~~~~~~~~~~~~~~~~~~~~
//      CLASS NAME: TRAIN
//	DETAILS: IT GIVES TRAIN REPORTS.
//~~~~~~~~~~~~~~~~~~~~~

class TRAIN
{
public :
void full() ;            //declaration of fn full()
void background();  	    //& background()
void ADD_TRAIN(char[], char[]) ;//DISPLAY_TRAIN(),
void ADDITION() ;          //ADD_TRAIN(),ADDITION(),
void TRAIN_LIST() ;        //TRAIN_LIST(),
int  FOUND_TRAIN(char[]) ; //& FOUND_TRAIN.

char train_no[5], train_name[20] ;

} ;


 
//~~~~~~~~~~~~~~~~~~~~~~
//	CLASS NAME: TICKET
//      DETAILS: IT GIVES INFORMATION ABT RESERVING TICKETS.
//~~~~~~~~~~~~~~~~~~~~~

class TICKET
{
public :
void RESERVATION() ;  //declaration of fn
void CANCELLATION() ; //RESERVATION(),CANCELLATION(),
void WAITING_LIST() ; //WAITING_LIST(),PASS_INFO(),
void PASS_INFO() ;    //WAITING_REC(),RESERVED_LIST().
void WAITING_REC(char*,int,int,int,int);
void RESERVED_LIST();
private :
int  seat_no, kms ;
char name[26], sex, tr_no[5] ;
int  age, fair ;
int  dd, mm, yy ;
char from[15], to[15] ;
} t ;
 
//~~~~~~~~~~~~~~~~~~~~~~
//   FUNCTION NAME: FULL()
//   CLASS:TRAIN.
//   DETAILS:IT CHANGES BACKGROUND & TEXT COLOR.
//~~~~~~~~~~~~~~~~~~~~~~
void TRAIN::full()
{
window(1,1,85,25);
textbackground(BLACK);
textcolor(BLUE);
}
void TRAIN::background()
{
const char o=' ' ;
int x=0;
for(int m=6;m<75;m++)
{
delay(x);
gotoxy(m,3);
cout<<o;
gotoxy(m,22);
cout<<o<<o;
}
for(m=4;m<23;m++)
{
delay(x);
gotoxy(6,m);
cout<<o<<o;
gotoxy(73,m);
cout<<o<<o;
}
for(int w=2;w<=79;w=w+2)
{
delay(x);
gotoxy(w,1);
cout<<"ßÜ";
gotoxy(w,25);
cout<<"ßÜ";
}
for(w=2;w<=24;w=w+1)
{
delay(x);
gotoxy(2,w);
cout<<"ßÜ";
gotoxy(78,w);
cout<<"ßÜ";
}

}


 
//~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION NAME: CURRENT_DATE()
//	CLASS: DATE
//	DETAILS:IT GIVES INFORMATION ABOUT THR CURRENT DATES
//	              AVAILABLE FOR RESERVATION.
//~~~~~~~~~~~~~~~~~~~~~~

void DATE :: CURRENT_DATE()
{
struct date d;
getdate(&d);         //inbuild fn getdate(&obj)-gives recent date.
day = d.da_day ;     //inbuild variable da_day,da_mon,da_year.
month = d.da_mon ;
year = d.da_year ;
}


 
//~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION NAME: EXTEND_DATE()
//	CLASS: DATE
//	DETAILS: IT GIVES INFORMATION ABOUT THE NEW DATES
//			AVAILABLE FOR RESERVATION.
//~~~~~~~~~~~~~~~~~~~~~

void DATE :: EXTEND_DATE(int dday, int dmonth, int dyear)
{
static int m[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
dday++ ;
if ((dday > m[dmonth-1]) || (dyear%400 != 0 && dmonth ==2 && dday >28))
{
dday = 1 ;
dmonth++ ;
}
if (dmonth > 12)
{
dmonth = 1 ;
dyear++ ;
}
day  = dday ;
month  = dmonth ;
year = dyear ;
}

 
//~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION : ADD_TRAIN()
//	CLASS: TRAIN
//	DETAILS: IT COPIES train_no,train_name TO THE FILE
//                        TRAIN.DAT.
//~~~~~~~~~~~~~~~~~~~~~

void TRAIN :: ADD_TRAIN(char tno[5], char tname[20])
{
fstream file ;
file.open("TRAIN.DAT", ios::app|ios::binary) ;
strcpy(train_no,tno) ;
strcpy(train_name,tname) ;
file.write((char *) this, sizeof(TRAIN)) ;
file.close() ;
}

 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: ADDITION()
//	CLASS: TRAIN
//	DETAILS: IT CALLS ADD_TRAIN() TO ADD SPECIFIED TRAINS
//			IN THE FILE.
//~~~~~~~~~~~~~~~~~~~~~~

void TRAIN :: ADDITION()
{
fstream file ;
file.open("TRAIN.DAT", ios::in|ios::binary) ;
if (!file.fail())
{ file.close();
return ;}
file.close() ;
ADD_TRAIN("2021","RAJDHANI EXPRESS") ;
ADD_TRAIN("2023","TAJ EXPRESS") ;
ADD_TRAIN("2025","GOMTI EXPRESS") ;
ADD_TRAIN("2027","KALKA MAIL") ;
ADD_TRAIN("2029","KALINDI EXPRESS") ;
}
 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: TRAIN_LIST()
//	CLASS: TRAIN
//	DETAILS: IT DISPLAYS THE AVAILABLE TRAINS IN THE FILE
//			TRAIN.DAT
//~~~~~~~~~~~~~~~~~~~~~~
void TRAIN :: TRAIN_LIST()
{
clrscr() ;
fstream file ;
file.open("TRAIN.DAT", ios::in|ios::binary) ;
gotoxy(30,1) ;
cout <<"LIST OF THE TRAINS" ;
gotoxy(30,2) ;
cout <<"******" ;
gotoxy(2,4) ;
cout <<" TRAIN NO.        TRAIN NAME" ;
gotoxy(1,5) ;
cout <<"****************";
cout <<"***" ;
int row=7 ;
while (file.read((char *) this, sizeof(TRAIN)))
{
gotoxy(4,row) ;
cout <<train_no ;
gotoxy(20,row) ;
cout <<train_name ;
row++ ;
}
file.close() ;
}

 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: FOUND_TRAIN()
//	CLASS: TRAIN
//	DETAILS: IT GIVES INFORMATION ABOUT THE SPECIFIED TRAINS
//~~~~~~~~~~~~~~~~~~~~~

int TRAIN :: FOUND_TRAIN(char tno[5])
{
fstream file ;
file.open("TRAIN.DAT", ios::in|ios::binary) ;
int found=0 ;
while (file.read((char *) this, sizeof(TRAIN)))
{
if (!strcmp(tno,train_no))
{
found = 1 ;
break ;
}
}
file.close() ;
return found ;
}
 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: PASS_INFO()
//	CLASS: TICKET
//	DETAILS: IT GIVES INFORMATION ABOUT THE SPECIFIED
//			PASSENGER.
//~~~~~~~~~~~~~~~~~~~~~~
void TICKET :: PASS_INFO()
{
clrscr() ;
char tno[5] ;
TRAIN train ;
train.TRAIN_LIST() ;//calling of fn TRAIN_LIST()
cout <<"\n\n Enter the train no. " ;
cin >>tno ;
if (!train.FOUND_TRAIN(tno))//calling of fn FOUND_TRAIN()
{
cout <<"\n\nTrain no. is invalid" ;
getch() ;
return ;
}
clrscr() ;
int d1,m1,y1, d2,m2,y2, d3,m3,y3, d4,m4,y4 ;
int d,m,y ;
DATE dt ;
dt.CURRENT_DATE() ;  //calling of fn CURRENT_DATE()
d1 = dt.day ;
m1 = dt.month ;
y1 = dt.year ;
cout <<"1: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
dt.EXTEND_DATE(d1,m1,y1) ;//calling of fn EXTEND_DATE()
d2 = dt.day ;
m2 = dt.month ;
y2 = dt.year ;
cout <<"\t2: " <<d2 <<"/" <<m2 <<"/" <<y2 ;
dt.EXTEND_DATE(d2,m2,y2) ;
d3 = dt.day ;
m3 = dt.month ;
y3 = dt.year ;
cout <<"\t3: " <<d3 <<"/" <<m3 <<"/" <<y3 ;
dt.EXTEND_DATE(d3,m3,y3) ;
d4 = dt.day ;
m4 = dt.month ;
y4 = dt.year ;
cout <<"\t4: " <<d4 <<"/" <<m4 <<"/" <<y4 ;
int sno=0 ;
cout <<"\n\nEnter sno. of the date for Passenger Information - " ;
cin >>sno ;
if (sno < 1 || sno > 4)
{
cout <<"\n\nInvalid data" ;
getch() ;
return ;
}
switch(sno)
{
case 1 :  d = d1 ;
m = m1 ;
y = y1 ;
break ;
case 2 :  d = d2 ;
m = m2 ;
y = y2 ;
break ;
case 3 :  d = d3 ;
m = m3 ;
y = y3 ;
break ;
case 4 :  d = d4 ;
m = m4 ;
y = y4 ;
break ;
default : break ;
}
int seatno=0, found=0 ;
cout <<"\n\n Enter SEAT No. of the Ticket : " ;
cin >>seatno ;
fstream file ;
file.open("TICKET.DAT", ios::in,ios::binary) ;
while (file.read((char *) this, sizeof(TICKET)))
{
if ((dd == d && mm == m && yy == y) &&
!strcmp(tr_no,tno) && seatno == seat_no)
{
found = 1 ;
clrscr() ;
gotoxy(5,5) ;
cout <<"*********"
<<"***********"
<<"****" ;
gotoxy(32,7) ;
cout <<"NORTHERN RAILWAY" ;
gotoxy(10,9) ;
cout <<"SEAT NO. " <<seat_no
<<"\t\t\t\tDate : " <<dd <<"/" <<mm <<"/" <<yy ;
gotoxy(10,10) ;
cout <<"Train no. : " <<tr_no ;
gotoxy(35,12) ;
cout <<"From : " <<from <<"\tTo : " <<to ;
gotoxy(35,13) ;
cout <<"Kms. " <<kms ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<name ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<age <<"\t\tSex : " <<sex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<fair ;
gotoxy(5,20) ;
cout
<<"************************" ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getch() ;
break ;
}
}
file.close() ;
if (!found)
{
cout <<"\n\n Ticket not found" ;
getch() ;
}
}
 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: RESERVATION()
//	CLASS: TICKET
//	DETAILS: IT RESERVES TICKETS FOR PASSENGER AS SPECIFIED.
//~~~~~~~~~~~~~~~~~~~~~~
void TICKET :: RESERVATION()
{
static int seatno[6][6];
int n,trainno;
clrscr() ;
char tno[7] ;
TRAIN train ;
train.TRAIN_LIST() ;   //calling of fn TRAIN_LIST()
cout <<"\n\n Enter the train no. " ;
cin >>tno ;
if (!train.FOUND_TRAIN(tno))//calling of fn FOUND_TRAIN()
{
cout <<"\n\nTrain no. is invalid" ;
getch() ;
return ;
}
clrscr() ;
int d1,m1,y1, d2,m2,y2, d3,m3,y3, d4,m4,y4 ;
int d,m,y ;
DATE dt ;
char ans;
cout <<"You can reserve ticket only for 3 days, following the current date.\n\n" ;
dt.CURRENT_DATE() ;//calling of fn CURRENT_DATE()
d1 = dt.day ;
m1 = dt.month ;
y1 = dt.year ;
cout <<"1: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
dt.EXTEND_DATE(d1,m1,y1) ;//calling of fn EXTEND_DATE()
d2 = dt.day ;
m2 = dt.month ;
y2 = dt.year ;
cout <<"\t2: " <<d2 <<"/" <<m2 <<"/" <<y2 ;
dt.EXTEND_DATE(d2,m2,y2) ;
d3 = dt.day ;
m3 = dt.month ;
y3 = dt.year ;
cout <<"\t3: " <<d3 <<"/" <<m3 <<"/" <<y3 ;
dt.EXTEND_DATE(d3,m3,y3) ;
d4 = dt.day ;
m4 = dt.month ;
y4 = dt.year ;
cout <<"\t4: " <<d4 <<"/" <<m4 <<"/" <<y4 ;
int sno=0 ;
cout <<"\n\nEnter sno. of the date for Reservation - " ;
cin >>sno ;
if (sno < 1 || sno > 4)
{
cout <<"\n\nInvalid data" ;
getch() ;
return ;
}
switch(sno)
{
case 1 :  d = d1 ;
m = m1 ;
y = y1 ;
break ;
case 2 :  d = d2 ;
m = m2 ;
y = y2 ;
break ;
case 3 :  d = d3 ;
m = m3 ;
y = y3 ;
break ;
case 4 :  d = d4 ;
m = m4 ;
y = y4 ;
break ;
default : break ;
}
fstream file ;
char pname[26], psex, pfrom[15], pto[15], ch ;
int  pkms, page, pfair ;
clrscr() ;
cout <<"\n\n Enter name of passenger : " ;
gets(pname) ;
cout <<"\n Enter age : " ;
cin >>page ;
if (page <= 5)
{
cout <<"\n No ticket is required upto age of 5" ;
getch() ;
return ;
}
do
{
cout <<"\n Enter sex (M/F) : " ;
cin >>psex ;
} while (toupper(psex) != 'M' && toupper(psex) != 'F');

int x=0;
if( strcmp(tno,"2021")==0)
{       trainno=1;
cout<<" DELHI-MUMBAI EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO MUMBAI"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO JAIPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO GWALIOR"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: char ch1;
++seatno[sno][trainno];
cout <<"\n No. of  Kms. : 10000" ;
pkms=10000;
strcpy(pfrom,"delhi");
strcpy(pto,"mumbai");
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch1;
if(ch1=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch1=='n')
{
break;
}
}
break;

case 2: char ch2;
cout <<"\n No. of  Kms. : 3528" ;
pkms=3528;
strcpy(pfrom,"delhi");
strcpy(pto,"jaipur");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch2;
if(ch2=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch2=='n')
{
break;
}
}

break;
case 3: char ch3;
cout<<"\n No. of  kms. : 5967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"gwalior");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch3;
if(ch3=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch3=='n')
{
break;
}
}

break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2023")==0)

{       trainno=2;
cout<<"\t DELHI-ASSAM EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO DISPUR"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO KANPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO JALPAIGUDI"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: char ch1;
cout <<"\n No. of  Kms. : 16000" ;
pkms=16000;
strcpy(pfrom,"delhi");
strcpy(pto,"dispur");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch1;
if(ch1=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch1=='n')
{
break;
}
}

break;
case 2: char ch2;
cout <<"\n No. of  Kms. : 4566" ;
pkms=4566;
strcpy(pfrom,"delhi");
strcpy(pto,"kanpur");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch2;
if(ch2=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch2=='n')
{
break;
}
}

break;
case 3: char ch3;
cout<<"\n No. of  kms. : 8967" ;
pkms=8967;
strcpy(pfrom,"delhi");
strcpy(pto,"jalpaigudi");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch3;
if(ch3=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch3=='n')
{
break;
}
}

break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2025")==0)

{       trainno=3;
cout<<"\t DELHI-CHENNAI EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO CHENNAI"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO BHOPAL"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO HYDERABAD"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: char ch1;
cout <<"\n No. of  Kms. : 12000" ;
pkms=12000;
strcpy(pfrom,"delhi");
strcpy(pto,"chennai");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch1;
if(ch1=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch1=='n')
{
break;
}
}

break;
case 2: char ch2;
cout <<"\n No. of  Kms. : 6588" ;
pkms=6588;
strcpy(pfrom,"delhi");
strcpy(pto,"bhopal");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch2;
if(ch2=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch2=='n')
{
break;
}
}

break;
case 3: char ch3;
cout<<"\n No. of  kms. : 8967" ;
pkms=8967;
strcpy(pfrom,"delhi");
strcpy(pto,"hyderabad");
++seatno[sno][trainno];

if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch3;
if(ch3=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch3=='n')
{
break;
}
}

break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2027")==0)

{       trainno=4;
cout<<"\t DELHI-KERALA EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO TRIVANDRUM"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO NAGPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO BHOPAL"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: char ch1;
cout <<"\n No. of  Kms. : 20000" ;
pkms=20000;
strcpy(pfrom,"delhi");
strcpy(pto,"trivandrum");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch1;
if(ch1=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch1=='n')
{
break;
}
}

break;
case 2: char ch2;

cout <<"\n No. of  Kms. : 6789" ;
pkms=6789;
strcpy(pfrom,"delhi");
strcpy(pto,"nagpur");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch2;
if(ch2=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch2=='n')
{
break;
}
}

break;
case 3: char ch3;
cout<<"\n No. of  kms. : 5967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"bhopal");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch3;
if(ch3=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch3=='n')
{
break;
}
}

break;
default:cout<<"Wrong choice!!!";

}
}

if(strcmp(tno,"2029")==0)

{       trainno=5;
cout<<"\t DELHI-JAMMU EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO SRINAGAR"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO CHANDIGARH"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO SHIMLA"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: char ch1;
cout <<"\n No. of  Kms. : 5890" ;
pkms=10000;
strcpy(pfrom,"delhi");
strcpy(pto,"srinagar");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch1;
if(ch1=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch1=='n')
{
break;
}
}

break;
case 2: char ch2;
cout <<"\n No. of  Kms. : 3528" ;
pkms=3528;
strcpy(pfrom,"delhi");
strcpy(pto,"chandigarh");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch2;
if(ch2=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch2=='n')
{
break;
}
}
break;
case 3: char ch3;
cout<<"\n No. of  kms. : 1967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"shimla");
++seatno[sno][trainno];
if(seatno[sno][trainno]>50)
{
cout<<"No more seats available!!!";
cout<<"\n We can reserve tickets on basis of waiting list";
cout<<"\n Do you still want to reserve (y/n): ";
cin>>ch3;
if(ch3=='y')
{
WAITING_REC(tno,d,m,y,seatno[sno][trainno]);
break;

}
if(ch3=='n')
{
break;
}
}

break;
default:cout<<"Wrong choice!!!";

}
}
pfair = pkms * 0.75 ;
clrscr() ;
gotoxy(5,5) ;
cout<<"************************" ;
getch();
gotoxy(32,7) ;
cout <<"NORTHERN RAILWAY" ;
gotoxy(10,9) ;
cout <<"SEAT NO. " <<seatno[sno][trainno]<<"\t\t\t\tDate : " <<d <<"/" <<m <<"/"<<y;
gotoxy(10,10) ;
cout <<"Train no. : " <<tno ;
gotoxy(35,12) ;
cout <<"From : " <<pfrom <<"\tTo : " <<pto ;
gotoxy(35,13) ;
cout <<"Kms. " <<pkms ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<pname ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<page <<"\t\tSex : " <<psex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<pfair ;
gotoxy(5,20) ;
cout
<<"************************" ;
cout <<"\n\n\n" ;
do
{
cout <<"Do you want to save ticket (y/n) " ;
cin >>ch ;
} while (toupper(ch) != 'Y' && toupper(ch) != 'N') ;
if (toupper(ch) == 'N')
{    --seatno[sno][trainno];
return ; }
if(toupper(ch)== 'Y')
{
file.open("TICKET.DAT", ios::app|ios::binary) ;
t.seat_no = seatno[sno][trainno] ;
t.kms = pkms ;
strcpy(t.name,pname) ;
strcpy(t.tr_no,tno) ;
strcpy(t.from,pfrom) ;
strcpy(t.to,pto) ;
t.sex = psex ;
t.age = page ;
t.fair = pfair ;
t.dd = d ;
t.mm = m ;
t.yy = y ;
file.write((char *) &t, sizeof(TICKET)) ;
file.close() ;
}

}

 
//~~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: CANCELLATION()
//	CLASS: TICKET
//	DETAILS: IT CANCELS THE TICKET MADE AS SPECIFIED BY
//			THE USER
//~~~~~~~~~~~~~~~~~~~~~~
void TICKET :: CANCELLATION()
{
clrscr() ;
char tno[5] ;
TRAIN train ;
train.TRAIN_LIST() ;//calling of fn TRAIN_LIST()
cout <<"\n\n Enter the train no. " ;
cin >>tno ;
if (!train.FOUND_TRAIN(tno))//calling of fn FOUND_TRAIN()
{
cout <<"\n\nTrain no. is invalid" ;
getch() ;
return ;
}
clrscr() ;
int d1,m1,y1, d2,m2,y2, d3,m3,y3, d4,m4,y4 ;
int d,m,y ;
DATE dt ;
dt.CURRENT_DATE() ;//calling of fn CURRENT_DATE()
d1 = dt.day ;
m1 = dt.month ;
y1 = dt.year ;
cout <<"1: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
dt.EXTEND_DATE(d1,m1,y1) ;//calling of fn EXTEND_DATE()
d2 = dt.day ;
m2 = dt.month ;
y2 = dt.year ;
cout <<"\t2: " <<d2 <<"/" <<m2 <<"/" <<y2 ;
dt.EXTEND_DATE(d2,m2,y2) ;
d3 = dt.day ;
m3 = dt.month ;
y3 = dt.year ;
cout <<"\t3: " <<d3 <<"/" <<m3 <<"/" <<y3 ;
dt.EXTEND_DATE(d3,m3,y3) ;
d4 = dt.day ;
m4 = dt.month ;
y4 = dt.year ;
cout <<"\t4: " <<d4 <<"/" <<m4 <<"/" <<y4 ;
int sno=0 ;
cout <<"\n\nEnter sno. of the date for Ticket Cancellation - " ;
cin >>sno ;
if (sno < 1 || sno > 4)
{
cout <<"\n\nInvalid data" ;
getch() ;
return ;
}
switch(sno)
{
case 1 :  d = d1 ;
m = m1 ;
y = y1 ;
break ;
case 2 :  d = d2 ;
m = m2 ;
y = y2 ;
break ;
case 3 :  d = d3 ;
m = m3 ;
y = y3 ;
break ;
case 4 :  d = d4 ;
m = m4 ;
y = y4 ;
break ;
default : break ;
}
int seatno=0;
int found=0 ;
char ch ;
cout <<"\n\n Enter SEAT No. of the Ticket to be Cancelled : " ;
cin >>seatno ;
fstream file, temp ;
file.open("TICKET.DAT", ios::in|ios::binary) ;
temp.open("TEMP.DAT", ios::out|ios::binary) ;
while (file.read((char *) this, sizeof(TICKET)))
{
if ((dd == d && mm == m && yy == y) && !strcmp(tr_no,tno) && seatno== seat_no)
{
found = 1 ;
clrscr() ;
gotoxy(5,5) ;
cout
<<"************************" ;
gotoxy(32,7) ;
cout <<"NORTHERN RAILWAY" ;
gotoxy(10,9) ;
cout <<"SEAT NO. " <<seat_no <<"\t\t\t\tDate : " <<dd <<"/" <<mm<<"/" <<yy ;
gotoxy(10,10) ;
cout <<"Train no. : " <<tr_no ;
gotoxy(35,12) ;
cout <<"From : " <<from <<"\tTo : " <<to ;
gotoxy(35,13) ;
cout <<"Kms. " <<kms ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<name ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<age <<"\t\tSex : " <<sex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<fair ;
gotoxy(5,20) ;
cout
<<"************************" ;
do
{
gotoxy(1,25) ; //clreol() ;
cout <<"Do you want to Cancel ticket (y/n) " ;
cin >>ch ;
} while (toupper(ch) != 'Y' && toupper(ch) != 'N') ;
}
else
temp.write((char *) this, sizeof(TICKET)) ;
}
file.close() ;
temp.close() ;
if (!found)
{
cout <<"\n\n Ticket not found" ;
getch() ;
return ;
}
if (toupper(ch) == 'N')
return ;
file.open("TICKET.DAT",ios::out|ios::binary) ;
temp.open("TEMP.DAT", ios::in|ios::binary) ;
while (temp.read((char *) this, sizeof(TICKET)))
file.write((char *) this, sizeof(TICKET)) ;
file.close() ;
temp.close() ;
}

//~~~~~~~~~~~~~~~~~~~~~~
//   FUNCTION NAME: RESERVED_LIST()
//   CLASS: TICKET
//   DETAILS: IT DISPLAYS THE LIST OF RESERVED TICKETS
//~~~~~~~~~~~~~~~~~~~~~~
void TICKET::RESERVED_LIST()
{
clrscr();
fstream file ;    //opening file.
file.open("TICKET.DAT", ios::in|ios::binary) ;
gotoxy(25,1) ;
cout <<"RESERVED LIST OF THE PASSENGERS" ;
gotoxy(25,2) ;
cout <<"**********" ;

gotoxy(2,5) ;
cout <<" SEAT NO. PASSENGER NAME FROM TO DATE TRAIN NO" ;
gotoxy(1,6) ;
cout<<"*****************" ;
int row=8, found=0 ;
while (file.read((char *) this, sizeof(TICKET)))
{               found = 1 ;
gotoxy(4,row) ;
cout <<seat_no ;
gotoxy(15,row) ;
cout <<name ;
gotoxy(29,row) ;
cout <<from ;
gotoxy(38,row) ;
cout <<to ;
gotoxy(49,row) ;
cout<<dd<<"/"<<mm<<"/"<<yy;
gotoxy(65,row) ;
cout<<tr_no;
row++ ;
if (row == 25)
{
getch() ;
for (int i=8; i<=24; i++)
{
gotoxy(1,i) ;
clreol() ;
}
row = 8 ;
}

}
file.close() ;
if (!found)
{
cout <<"\n\n\n\n\n No reservation in this category." ;
getch() ;
return ;
}
cout <<"\n\nPress any key to continue..." ;
getch() ;
}

//~~~~~~~~~~~~~~~~~~~~~~
//   FUNCTION NAME: WAITING_REC(char *tno,int d,int m,int y
//				int pnr)
//   CLASS: TICKET
//   DETAILS: IT ENTERS RECORDS FOR WAITING LIST
//~~~~~~~~~~~~~~~~~~~~~~

void TICKET::WAITING_REC(char *tno,int d,int m,int y,int seatno)
{
int d1,m1,y1, d2,m2,y2, d3,m3,y3, d4,m4,y4 ;
DATE dt ;
fstream file ;     //opening file.
file.open("WLIST.DAT", ios::in|ios::binary) ;
while (file.read((char *) this, sizeof(TICKET)))
{
if ((dd == d && mm == m && yy == y) && !strcmp(tr_no,tno))
seatno = seat_no ;
}
file.close() ;    //closing of file.
seatno++ ;
char pname[26], psex, pfrom[15], pto[15], ch ;
int  pkms, page, pfair ;
clrscr() ;
cout <<"\n\n Enter name of passenger : " ;
gets(pname) ;
cout <<"\n Enter age : " ;
cin >>page ;
if (page <= 5)
{
cout <<"\n No ticket is required upto age of 5" ;
getch() ;
return ;
}
do
{
cout <<"\n Enter sex (M/F) : " ;
cin >>psex ;
} while (toupper(psex) != 'M' && toupper(psex) != 'F') ;
int x;
if(strcmp(tno,"2021")==0)
{
cout<<"\t DELHI-MUMBAI EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO MUMBAI"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO JAIPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO GWALIOR"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: cout <<"\n No. of  Kms. : 10000" ;
pkms=10000;
strcpy(pfrom,"delhi");
strcpy(pto,"mumbai");
break;
case 2: cout <<"\n No. of  Kms. : 3528" ;
pkms=3528;
strcpy(pfrom,"delhi");
strcpy(pto,"jaipur");
break;
case 3: cout<<"\n No. of  kms. : 5967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"gwalior");
break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2023")==0)

{
cout<<"\t DELHI-ASSAM EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO DISPUR"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO KANPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO JALPAIGUDI"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: cout <<"\n No. of  Kms. : 16000" ;
pkms=16000;
strcpy(pfrom,"delhi");
strcpy(pto,"dispur");
break;
case 2: cout <<"\n No. of  Kms. : 4566" ;
pkms=4566;
strcpy(pfrom,"delhi");
strcpy(pto,"kanpur");
break;
case 3: cout<<"\n No. of  kms. : 8967" ;
pkms=8967;
strcpy(pfrom,"delhi");
strcpy(pto,"jalpaigudi");
break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2025")==0)

{
cout<<"\t DELHI-CHENNAI EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO CHENNAI"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO BHOPAL"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO HYDERABAD"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: cout <<"\n No. of  Kms. : 12000" ;
pkms=12000;
strcpy(pfrom,"delhi");
strcpy(pto,"chennai");
break;
case 2: cout <<"\n No. of  Kms. : 6588" ;
pkms=6588;
strcpy(pfrom,"delhi");
strcpy(pto,"bhopal");
break;
case 3: cout<<"\n No. of  kms. : 8967" ;
pkms=8967;
strcpy(pfrom,"delhi");
strcpy(pto,"hyderabad");
break;
default:cout<<"Wrong choice!!!";

}
}
if(strcmp(tno,"2027")==0)

{
cout<<"\t DELHI-KERALA EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO TRIVANDRUM"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO NAGPUR"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO BHOPAL"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: cout <<"\n No. of  Kms. : 20000" ;
pkms=20000;
strcpy(pfrom,"delhi");
strcpy(pto,"trivandrum");
break;
case 2: cout <<"\n No. of  Kms. : 6789" ;
pkms=6789;
strcpy(pfrom,"delhi");
strcpy(pto,"nagpur");
break;
case 3: cout<<"\n No. of  kms. : 5967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"bhopal");
break;
default:cout<<"Wrong choice!!!";

}
}

if(strcmp(tno,"2029")==0)

{
cout<<"\t DELHI-JAMMU EXPRESS"<<endl;
cout<<"\t MAIN MENU"<<endl;
cout<<"ENTER 1 TO TRAVEL FROM DELHI TO SRINAGAR"<<endl;
cout<<"ENTER 2 TO TRAVEL FROM DELHI TO CHANDIGARH"<<endl;
cout<<"ENTER 3 TO TRAVEL FROM DELHI TO SHIMLA"<<endl;
cout<<"ENTER YOUR CHOICE: ";
cin>>x;
switch(x)
{
case 1: cout <<"\n No. of  Kms. : 5890" ;
pkms=10000;
strcpy(pfrom,"delhi");
strcpy(pto,"srinagar");
break;
case 2: cout <<"\n No. of  Kms. : 3528" ;
pkms=3528;
strcpy(pfrom,"delhi");
strcpy(pto,"chandigarh");
break;
case 3: cout<<"\n No. of  kms. : 1967" ;
pkms=5967;
strcpy(pfrom,"delhi");
strcpy(pto,"shimla");
break;
default:cout<<"Wrong choice!!!";

}
}
pfair = pkms * 0.75 ;
clrscr() ;
gotoxy(5,5) ;
cout
<<"************************" ;
gotoxy(32,7) ;
cout <<"NORTHERN RAILWAY" ;
gotoxy(10,9) ;
cout <<"SEAT NO. " <<seatno<<"\t\t\t\tDate : " <<d <<"/" <<m <<"/"<<y ;
gotoxy(10,10) ;
cout <<"Train no. : " <<tno ;
gotoxy(35,12) ;
cout <<"From : " <<pfrom <<"\tTo : " <<pto ;
gotoxy(35,13) ;
cout <<"Kms. " <<pkms ;
gotoxy(10,15) ;
cout <<"Passenger name : " <<pname ;
gotoxy(10,16) ;
cout <<"Passenger age : " <<page <<"\t\tSex : " <<psex ;
gotoxy(10,18) ;
cout <<"Total Fair : " <<pfair ;
gotoxy(5,20) ;
cout
<<"****************" ;
cout <<"\n\n\n" ;
do
{
cout <<"Do you want to save the ticket for waiting list(y/n): " ;
cin >>ch ;
} while (toupper(ch) != 'Y' && toupper(ch) != 'N') ;
if (toupper(ch) == 'N')
return ;

if(toupper(ch)== 'Y')
{
file.open("WLIST.DAT", ios::app|ios::in) ;
t.seat_no = seatno ;
t.kms = pkms ;
strcpy(t.name,pname) ;
strcpy(t.tr_no,tno) ;
strcpy(t.from,pfrom) ;
strcpy(t.to,pto) ;
t.sex = psex ;
t.age = page ;
t.fair = pfair ;
t.dd = d ;
t.mm = m ;
t.yy = y ;
file.write((char *) &t, sizeof(TICKET)) ;
file.close() ;
}
char ans1;
cout<<"Do you want to reserve more tickets(y/n): ";
cin>>ans1;
if(ans1=='y')
{
WAITING_REC(tno,d,m,y,seatno
);
}
if(ans1=='n')
{
return ;
}

}

//~~~~~~~~~~~~~~~~~~~~~
//	FUNCTION: WAITING_LIST()
//	CLASS: TICKET
//	DETAILS: IT DISPLAYS THE WAITING LIST OF RESRVATIONS.
//~~~~~~~~~~~~~~~~~~~~~~
void TICKET :: WAITING_LIST()
{
clrscr();
fstream file ;
file.open("WLIST.DAT", ios::in|ios::binary) ;
gotoxy(25,1) ;
cout <<"WAITING LIST OF THE PASSENGERS" ;
gotoxy(25,2) ;
cout <<"**********" ;
gotoxy(2,5) ;
cout <<" SEAT NO.  PASSENGER NAME FROM TO DATE   TRAIN NO" ;
gotoxy(1,6) ;
cout
<<"******************" ;
int row=8, found=0 ;
while (file.read((char *) this, sizeof(TICKET)))
{
found = 1 ;
gotoxy(4,row) ;
cout <<seat_no ;
gotoxy(15,row) ;
cout <<name ;
gotoxy(29,row) ;
cout <<from ;
gotoxy(38,row) ;
cout <<to ;
gotoxy(49,row) ;
cout<<dd<<"/"<<mm<<"/"<<yy;
gotoxy(65,row) ;
cout<<tr_no;
row++ ;
if (row == 25)
{
getch() ;
for (int i=8; i<=24; i++)
{
gotoxy(1,i) ;
clreol() ;
}
row = 8 ;
}

}

file.close() ;
if (!found)
{
cout <<"\n\n\n\n\n No reservation in this category." ;
getch() ;
return ;
}
cout <<"\n\nPress any key to continue..." ;
getch() ;
}


//~~~~~~~~~~~~~~~~~~~~
//      FUNCTION: MAIN()
//      DETAILS: STARTING OF MAIN PROGRAM.
//~~~~~~~~~~~~~~~~~~~~
void main()
{

TICKET ticket ;			//object of TICKET class
TRAIN train ;			//object of TRAIN class
train.ADDITION() ;              //calling ADDITION() fn
train.full();                   //calling full()
train.background();             //calling background()
clrscr();
char ch, a=30, a1=31 ;
while (1)
{       train.full();                   //calling full()
train.background();             //calling background()
gotoxy(29,6) ;
cout <<"* NORTHERN RAILWAY *" ;

gotoxy(29,7) ;
for (int i=1; i<=22; i++)
{
if (i%2)
cout <<a ;
else
cout <<a1 ;
}
gotoxy(29,10) ;
cout <<"1 :: TRAIN LIST" ;
gotoxy(29,11) ;
cout <<"2 :: RESERVATION" ;
gotoxy(29,12) ;
cout <<"3 :: CANCELLATION" ;
gotoxy(29,13) ;
cout <<"4 :: WAITING LIST" ;
gotoxy(29,14);
cout <<"5 :: RESERVED LIST";
gotoxy(29,15) ;
cout <<"6 :: PASSENGER INFO." ;
gotoxy(29,16) ;
cout <<"7 :: QUIT" ;
gotoxy(29,18) ;
cout <<"Enter your choice :: " ;
ch = getche() ;
if (ch == 27 || ch == '7')
break ;
else
if (ch == '1')
{
train.TRAIN_LIST() ;      //calling TRAIN_LIST()
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getch() ;
clrscr();
train.full();
train.background();
}
else
if (ch == '2')
{
ticket.RESERVATION() ;	  //calling RESERVATION()
clrscr();
train.full();
train.background();
}
else
if (ch == '3')
{
ticket.CANCELLATION() ;	 //calling CANCELLATION()
clrscr();
train.full();
train.background();
}
else
if (ch == '4')
{
ticket.WAITING_LIST() ; //calling WAITING_LIST()
clrscr();
train.full();
train.background();
}
else
if(ch== '5')
{
ticket.RESERVED_LIST();//calling RESERVED_LIST()
clrscr();
train.full();
train.background();
}
else
if (ch == '6')
{
ticket.PASS_INFO() ;    //calling PASS_INFO()
clrscr();
train.full();
train.background();
}
}
}