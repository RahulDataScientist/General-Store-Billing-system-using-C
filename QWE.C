
//2019-2020
//DSA-Project
//Student of B.tech computer Engineering with specialization in Data science
//Project Name-General Store Billing System
//Project By Name:-Rahul Nyati
/*Aim:-In these project we perform diffrent operation like Add and maintain
records of available products. Add and maintain customer details. Add and
maintain description of new products. Add and maintain new entered category
of products.
Provides economic financial reports to the owner monthly or weekly and yearly.
Provides a convenient solute of billing pattern. Make an easy to use environment
for users and customers.
*/
/*. Features:-
A. Point-of-Sale (POS) functionality allows one time invoices to be quickly
generated and presented for payment.
B. Estimates provide the ability to issue quotes for new products and services
while giving operators the choice to make changes to existing estimates and
finally convert estimates to invoices for payment as pending sales are finalized.
C. Account Statements provides customers with a monthly view of the status of
their account showing new payments, charges and account aging.
D. Duplicate payment protection warnings help prevent against accidental
double billing of customers.
E.Billing preview simulates the billing process allowing operators to check
for errors before proceeding to bill customers
*/
/*. Limitations:-
1. Excel export has not been developed for customer, payment due to some
criticality
2. Offline report of transaction history, transaction, and bill cannot
generate due to batch mode exception.
3. The transaction are executed in offline mode hence online data for
transaction history, login capture and modification is not possible.
*/
/*Future scope
A. This project will help the store keeper in fast billing.
B. This project enable store keep to maintain a    great database of all
Customers visited and purchase product from store.
C. Project will enable to see report regarding product and category.
D. It is easy to maintain in future prospect.
*/
/*
Conclusion:- In these way we have make a c program that generate bill that
will help to reduce the manually work And also learnt how to use different
function in c.
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 void output();
  struct date
    {
	int day;
	int month;
	int year;
    };
void login(){
char usr_name[10],passwd[10],temp[10];
int i=0;
FILE *pwd;
clrscr();
textcolor(20);
gotoxy(27,10);
cprintf("USERNAME :");
fflush(stdin);
textcolor(4);
scanf("%s",usr_name);
textcolor(12);
gotoxy(27,11);
cprintf("PASSWORD :");
fflush(stdin);
textcolor(4);
while(i<6){
passwd[i]=getch();
cprintf("*");
i++;}
passwd[i]='\0';
pwd=fopen("password.txt","r");
if(pwd==NULL){exit(0);}
else{fscanf(pwd,"%s",temp);
fclose(pwd);}
if((strcmp(usr_name,"rahul")==0) && (strcmp(passwd,temp)==0)){
clrscr();
    }
else{ textcolor(20);
gotoxy(27,18);
cprintf("LOGIN UNSUCCESSFULL");
sleep(4);
exit(0);}
}


   //first of all create a data structure for manufacturing date

    //then create data structure for item details
    struct details
    {
	char name[20];//It refers to item name
	int price;//It refers to price
	int code; //It refers to item code
	int qty; //It refers to quantity
	struct date mfg;
    };
    struct details item[50];
    int n, i,total=0;

    void drawRectangle(){
int i,j;
textbackground(8);
textcolor(15);


 gotoxy(0,0);
cprintf("%c",201);
 for(i=0;i<78;i++)
 {gotoxy(i,0);
 cprintf("%c",205);
 }

 gotoxy(78,0);
 cprintf("%c",187);
 for(i=2;i<25;i++)
 {gotoxy(80,i);
 if(i==6){cprintf("%c",185);}
 else{cprintf("%c",186);  }
}

 gotoxy(80,24);
 cprintf("%c",188);
 for(i=79;i>0;i--)
 {gotoxy(i,24);
 if(i==35){cprintf("%c",202);}
 else{cprintf("%c",205);}
 }

gotoxy(1,24);
cprintf("%c",200);
for(i=23;i>1;i--){
gotoxy(1,i);
if(i==6){cprintf("%c",204);}
else{cprintf("%c",186);}
}

for(i=1;i<80;i++){
gotoxy(i,6);
if(i==35){cprintf("%c",203);}
else{cprintf("%c",205);}
}

for(i=7;i<24;i++){
gotoxy(35,i);
cprintf("%c",186);
}
gotoxy(1,6);
cprintf("%c",185);
}


    void bill()
    {
    clrscr();
    printf("Enter number of items:");
    scanf("%d", &n);
    //fflush is used beecause do clear old output store and give new output but in some cases we also use for input stream
    //stdin means standard input we use because for input stream
    fflush(stdin);
    for (i = 0; i < n; i++)
    {

	fflush(stdin);
	printf("Item name: \n");
	scanf("%s", item[i].name);
	fflush(stdin);
	printf("Item code: \n");
	scanf("%d", &item[i].code);
	fflush(stdin);
	printf("Quantity: \n");
	scanf("%d", &item[i].qty);
	fflush(stdin);
	printf("price: \n");
	scanf("%d",  &item[i].price);
	fflush(stdin);
	printf("Manufacturing date(dd-mm-yyyy): \n");
	scanf("%d-%d-%d", &item[i].mfg.day,
	&item[i].mfg.month, &item[i].mfg.year);
	clrscr();
    }
    printf("            **  GENRAL STORE BILLING SYSTEM   ** \n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE | MFG.DATE \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
	printf("%d     %-15s        %-d          %-5d     %-5d %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,item[i].price, item[i].mfg.day, item[i].mfg.month,item[i].mfg.year);
    printf("------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
    total=total+item[i].qty * item[i].price;
    }
    printf("-----------------------Total=%d------------------------------------",total);
getch();
}

  struct account {
	int number;
	char name[100];
	int acct_no;
	float mobile_no;
	char street[100];
	char city[100];
	char acct_type;
	float oldbalance;
	float newbalance;
	float payment;
	struct date lastpayment;
  }customer;
  int pos,len,spe;




void input()
	{
	  //first of all file open then write
	  FILE *fp=fopen("demosss.txt","rb");
	  //fseek is basically use because to move
	  //file pointer asssociated with a file to specific poistion
	  //syntax for fseek function:-fseek(file *pointer,offset,position)
	  //seek_end denoted end of file
	  fseek (fp,0,SEEK_END);
	  //ftell is used beacuse to know about the current file poistion
	  pos=ftell(fp);
	  //sizeof returns the size
	  len=sizeof(customer);
	  spe=pos/len;
		fseek(fp,(spe-1)*len,SEEK_SET);
	 // fread is used to read the customer information
	  fread(&customer,sizeof(customer),1,fp);
	  printf("\ncustomer no:%d\n",++customer.number);
	  //fclose is used to close the file
	  fclose(fp);
	  printf("         Account number:");
	  scanf("%d",&customer.acct_no);
	  printf("\n       Name:");
	  scanf("%s",customer.name);
	  printf("\n       mobile no:");
	  scanf("%f",&customer.mobile_no);
	  printf("         Street:");
	  scanf("%s",customer.street);
	  printf("         City:");
	  scanf("%s",customer.city);
	  printf("         Previous balance:");
	  scanf("%f",&customer.oldbalance);
	  printf("         Current payment:");
	  scanf("%f",&customer.payment);
	  printf("         Payment date(mm/dd/yyyy):");
	  scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
	  return;
   }

 void writefile()
   {
	  FILE *fp;
	  fp=fopen("demosss.txt","ab");
	  fwrite(&customer,sizeof(customer),1,fp);
	  fclose(fp);
	  return;
   }

 void search()
   {
	 char ch;
	 char nam[100];
	 int n,i,m=1;
	 FILE *fp;
	 fp=fopen("demosss.txt","rb");
	 do{
		printf("\nenter your choice:");
		ch=getche();
	 }while(ch!='1' && ch!='2');
	 switch(ch){
	      case '1':
		    fseek(fp,0,SEEK_END);
		    pos=ftell(fp);
		    len=sizeof(customer);
		    spe=pos/len;
		    do{
			printf("\nchoose customer number:");
			scanf("%d",&n);
			if(n<=0 || n>spe)
			printf("\nenter correct\n");
			else{
			    fseek(fp,(n-1)*len,SEEK_SET);
			    fread(&customer,len,1,fp);
			    output();
			}
			printf("\n\nagain?(y/n)");
			ch=getche();
		    }while(ch=='y');
		    fclose(fp);
		    break;
	      case '2':
		    fseek(fp,0,SEEK_END);
		    pos=ftell(fp);
		    len=sizeof(customer);
		    spe=pos/len;
		    fseek(fp,(spe-1)*len,SEEK_SET);
		    fread(&customer,sizeof(customer),1,fp);
		    n=customer.number;

		    do{
			printf("\nenter the name:");
			scanf("%s",nam);
			fseek(fp,0,SEEK_SET);
			for(i=1;i<=n;i++)
			{
			     fread(&customer,sizeof(customer),1,fp);
			     if(strcmp(customer.name,nam)==0)
			     {
				output();
				m=0;
				break;
			     }
			}
			if(m!=0)
			printf("\n\ndoesn't exist\n");
			printf("\nanother?(y/n)");
			ch=getche();
		    }while(ch=='y');
		    fclose(fp);
	      }
	      return;
	 }



   void output()

	 {
	   gotoxy(25,5);
	   printf("\n\n    Customer no    :%d\n",customer.number);
	   printf("    Name 	   :%s\n",customer.name);
	   printf("    Mobile no      :%.f\n",customer.mobile_no);
	   printf("    Account number :%d\n",customer.acct_no);
	   printf("    Street         :%s\n",customer.street);
	   printf("    City           :%s\n",customer.city);
	   printf("    Old balance    :%.2f\n",customer.oldbalance);
	   printf("    Current payment:%.2f\n",customer.payment);
	   printf("    New balance    :%.2f\n",customer.newbalance);
	   printf("    Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
	   printf("    Account status :");
	   textcolor(128+RED);
	   switch(customer.acct_type)
	      {
	      case 'C':
		 cprintf("CURRENT\n\n");
		 break;
	      case 'O':
		 //Overdue refers to remaining balance
		 cprintf("OVERDUE\n\n");
		 break;
	      case 'D':
		 //Delinquent means when we pay the payment after the overdue
		 //date
		 cprintf("DELINQUENT\n\n");
		 break;
	      default:
		 cprintf("ERROR\\n\n");
	      }
	      textcolor(WHITE);
	      return;

	   }
void main()
	{
	  int i,n;
	  char ch;
	  login();
	//  drawRectangle();
	  clrscr();

	  _setcursortype(_NOCURSOR);
	  printf("   ----------2019-2020------\n");
	  printf("   ---------C PROJECT-----\n");
	  printf("   ---POORNIMA UNIVERSITY---\n");
	  printf("   ---Name:-Rahul Nyati-----\n");
	  printf("   ---B.tech CS (Data Science)\n");
	  printf("  \n General Store BILLING SYSTEM:\n\n");
	  printf("==================================\n");
	  printf("\n1:    To add account on list\n");
	  printf("2:    To search customer account\n");
	  printf("3:    To Generate bill\n");
	  printf("4:    exit\n");
	  printf("\n===================================\n");
	  do{
	       printf("\nselect what do you want to do?");
	       ch=getche();
	  }while(ch<='0' || ch>'4');
	  switch(ch){
		case '1':
			clrscr();
			//It refers to how many customers
			printf("\nhow many customer accounts?");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				input();
				if(customer.payment>0)
					customer.acct_type=(customer.payment<0.1*customer.oldbalance)? 'O': 'D';
				else
					customer.acct_type=(customer.oldbalance>0)?'D' : 'C';
				customer.newbalance=customer.oldbalance - customer.payment;
				writefile();
			}
			main();
		 case '2':
			clrscr();
			printf("search by what?\n");
			printf("\n1 --- search by customer number\n");
			printf("2 --- search by customer name\n");
			search();
			ch=getche();
			main();
		case '3':
			bill();

		case '4':
			clrscr();
			delay(700);
			textcolor(RED);
			gotoxy(15,10);
			cprintf("\nA PROJECT Made By  Rahul nyati");
			delay(1500);
			exit(1);
	  }
 getch();
}


