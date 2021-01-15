//Let us work on the menu of a library.
//Create a structure containing book information like accession number, name of author, book title and flag to know whether book is issued or not. 
//Create a menu in which the following can be done. 
//1 - Add a new book  
//2 - Display book information        
//3 - Display all the books in the library of a particular author 
//4 - Display the number of books of a particular title 
//5 - Display the total number of books in the library 
//6 - Issue a book (If we issue a book, then its number gets decreased by 1 and if we add a book, its number gets increased by 1)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct library{
	int acc_no;
	char author[40];
	char title[40];
	int flag;
}stype;
void head() {
    printf("\t###########################################################################");
	printf("\n\t############              Library management System            ############");
	printf("\n\t############                (UNDER DEVELOPMENT)                ############");
	printf("\n\t###########################################################################");
}


int login() {
	char us[20],pass[20],ch='\0';
	int i=3,j=0;
	while(i>=1) {
		system("cls");
		head();

		printf("\n\t\t\t\t\t***Login Page***");
		printf("\n\n\n\t\t\tusername => ");
		gets(us);
		printf("\n\t\t\tpassword => ");
		
		while(ch!=13) {
			ch=getch();
	
			if(ch!=13 && ch!=8) {
			putch('*');
			pass[j] = ch;
			j++;
			}
		}
		pass[j] = '\0';	
		
		if((strcmp(us,"sourav saha")==0)&&strcmp(pass,"0272")==0) {
			printf("\n\n\n\t\t\tLOGIN SUCCESSFULL!!!\n\t\t\tPress any key to continue\n\n\n\n");
			getch();
			
			break;	
		}
		else {
			printf("\n\n\n\t\t\t\t\tINVALID CREDENTIALS!!!\n");
			printf("\n\n\t\t\t\t\t%d try remaining!!!\n\n\n",--i);
			getch();
		}	
	}	
	if(i<=0) {
		printf("\n\n\n\t\tYou have entered wrong credentials 3 times, system is exiting...\n\n\n\n");
		exit(-1);
	}
}

int counter=1000;
void enterNewBook(stype *d, int i)
{
	counter++;
	(d+i)->acc_no = counter;
	printf("\n Enter author : ");
	fflush(stdin);
	gets((d+i)->author);
	printf("\n enter title : ");
	fflush(stdin);
	gets((d+i)->title);	
	(d+i)->flag = 1;	  	
}

void displayBooks(stype *d, int n)
{
	int i=0;
	if(i<n)
	{
		printf("\n acc_no is : %d",(d+i)->acc_no);
		printf("\n author is : %s",(d+i)->author);	
		printf("\n title is : %s\n\n",(d+i)->title);
	}
	else{
	
	printf("\n No Book is enter till now");
}
}
void displayBooksByAuthor(stype *d, int n, char author[])
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(strcmp((d+i)->author, author) == 0)
		{
			printf("\n acc_no is : %d",(d+i)->acc_no);
			printf("\n author is : %s",(d+i)->author);	
			printf("\n title is : %s\n\n",(d+i)->title);
			c=1;
		}
	}
	if(c==0){
		printf("\n There is no Book available of this author");
	}
}

void displayBooksByTitle(stype *d, int n, char title[])
{
	int i, c=0;
	for(i=0;i<n;i++)
	{
		if(strcmp((d+i)->title, title) == 0)
		{
			c++;
		}
	}
	if(c==0){
		printf("\n There is no Book available of this title");
	}
	else
		printf("\n Total no. of Book(s) available of this title is %d",c);
}

int getTotalBooks(stype *d, int n){
	int i, c=0;
	for(i=0;i<n;i++)
	{
		if((d+i)->flag == 1)
		{
			c++;
		}
	}
	return c;

}

void issueBook(stype *d, int n, int ano){
	int i, c=0;
	for(i=0;i<n;i++)
	{
		if((d+i)->acc_no == ano && (d+i)->flag == 1)
		{
			(d+i)->flag = 0;
			c++;
		}
		
	}
	if(c==0){
		printf("\n There is no Book available of this acc-no");
	}
	else
		printf("\n The book is issued successfully");
}

void returnBook(stype *d, int n, int ano){
	int i, c=0;
	for(i=0;i<n;i++)
	{
		if((d+i)->acc_no == ano && (d+i)->flag == 0)
		{
			(d+i)->flag = 1;
			c++;
		}
		
	}
	if(c==0){
		printf("\n There is no Book available of this acc-no");
	}
	else
		printf("\n The book is returned successfully");
}


int main()
{
	int i,n,p, x, nob=0, GTB, ano;
	stype *d;
	char author[40], title[40];
		i=login();
		printf("\n\t\t**********MADE BY:*************\n\t\t SOURAV SAHA(JIS/2019/0272/ECE/123190802072)\n\n\t\t SUMAN MODAK(JIS/2019/0290/ECE/123190802080)\n\n\t\t ANIKET KUMAR MONDAL(JIS/2019/0487/ECE/123190802007)\n\n\t\t AYNAVA MANNA(JIS/2019/0677/ECE/123190802015)\n\n\t\tUNDER THE SUPERVISION->MR.BIKASH Sir.\n\n\t\tAssistant Professor Of\n\n\t\tJIS College Of Engineering\n");
	printf("\n Enter the number of books : ");
	scanf("%d",&n);
	d=(stype *)malloc(n*sizeof(stype));
	while (1)
{

	
		printf("\n 1 - Add a new book");
		printf("\n 2 - Display book information");
		printf("\n 3 - Display all the books in the library of a particular author");
		printf("\n 4 - Display the number of books of a particular title");
		printf("\n 5 - Display the total number of books in the library");
		printf("\n 6 - Issue a book ");
		printf("\n 7 - Return a book ");
		printf("\n 8 - Exit ");
		scanf("%d",&x);
		switch(x){
			case 1: if(nob<=n){		
						enterNewBook(d,nob);
						nob++;
				    } 
					break;
					
			case 2: displayBooks(d,nob);
					break;
			case 3: printf("\n Enter name of author:");
					fflush(stdin);
					gets(author);
					displayBooksByAuthor(d,nob,author);
					break;
			case 4: printf("\n Enter title of a book:");
					fflush(stdin);
					gets(title);
					displayBooksByTitle(d,nob,title);
					break;
			case 5: GTB = getTotalBooks(d,nob);
					printf("\n Total number of books available = %d",GTB);
					break;
			case 6: printf("\n Enter acc-no of a book:");
					scanf("%d",&ano);
					issueBook(d,nob, ano);
					break;
			case 7: printf("\n Enter acc-no of a book:");
					scanf("%d",&ano);
					returnBook(d,nob, ano);
					break;
			case 8: {
					printf("\n\n\n\t\t\t\tThank you!!! HAVE A GOOD DAY :-# \n\n\n\n\n");
					exit(0);
				
			}
					
		}
	}
}

