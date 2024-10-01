#include<iostream>		//INCLUDED HEADER FILES
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;
class book		//CLASS NAME : BOOK
{
public:
    char name[20];
    char author[20];
    int a;		//copies
    void getdata();
    void show();
};
void book::getdata()		//FUNCTIONS TO GET DATA
{
  	cout<<"\n\n\n\t\tEnter Name Of Book:\t";
    cin>>name;
    cout<<"\n\t\tEnter Name Of Author:\t";
    cin>>author;
    cout<<"\n\t\tEnter No. Of Copies  :\t";
    cin>>a;
    cout<<"\t\tSuccessfully!\n";
}
void book::show()		//FUNCTIONS TO SHOW DATA
{
    cout<<"BOOK    :"<<name;
    cout<<"\nAUTHOR  :"<<author;
    cout<<"\nCOPIES  :"<<a;
}

int main()		//MAIN BODY
{
    system("color c");
	char pass[20],password[20]="darshan7754";
    login_try:
	cout<<"\n\n\t\tEnter the password to login:";
    cin>>pass;
    if (strcmp(pass,password)==0)
    {	
		cout<<"\n\nPassword Match!";
    }
	else
	{	system("cls");
		cout<<"\n\nWrong password!!\a\a\a";
       	goto login_try;
	}
	system("cls");
    system("color 9");
	book b1;
	int a;
	z:
    system("cls");
	fstream f;
    f.open("lib.txt",ios::in|ios::out|ios::app);
    cout<<"\n\n\t\t\xB2LIBRARY MANAGEMENT SYSTEM\xB2";
	cout<<"\n\n\n\tWHAT DO YOU WANT TO DO:";
	cout<<"\n\n\t\t1. TO ADD:";
	cout<<"\n\t\t2. TO SHOW ALL BOOKS:";
	cout<<"\n\t\t3. TO CKECK AVAILABILITY:";
	cout<<"\n\t\t4. TO MODIFY:";
	cout<<"\n\t\t5. TO DELETE:";
	cout<<"\n\t\t6. TO EXIT:";
	cout<<"\n\n\tENETR YOU ARE CHOICE:";
	cin>>a;
    
    switch (a)
    {
    case 1:		//DETAILS : TO ADD A BOOKS RECORD
    {
	    system("cls");
        fstream f;
        f.open("lib.txt",ios::in|ios::out|ios::ate|ios::app|ios::binary);
        char ans;
        b1.getdata();
        f.write((char *)&b1,sizeof(b1));
		cout<<"\n\tDo You Want To Continue(Y&y/N&n):";
		cin>>ans;
        if(ans=='Y' || ans=='y')
            goto z;
        else if(ans=='n'||ans=='N')
        	goto x;
	}
	break;
    case 2:		//DETAILS : TO SHOW ALL BOOKS RECORDS
    {
        system("cls");
		cout<<"\n\n";
        fstream f;
        f.open("lib.txt",ios::in|ios::binary);
        char ans;
       	if(!f)
		{
			cout<<"File not Found";
			exit(0);
		}
		else
		{
		f.read((char *)&b1,sizeof(b1));
			while(!f.eof())
			{
				b1.show();
				cout<<"\nPress Any Key....For Next Record"<<endl;
				getch();
				f.read((char *)&b1,sizeof(b1));
			}
		}
		f.close();
        cout<<"\n\tDo You Want To Continue(Y&y/N&n):";
        cin>>ans;
        if(ans=='Y' || ans=='y')
            goto z;
        else if(ans=='n'||ans=='N')
        	goto x;
    }
    break;
    case 3:		//DETAILS : TO CHECK AVAILABILITY
    {
        system("cls");
        char ans;
        ifstream f;
        book b1;
        char name[20];
        char author[20];
        int a;
        f.open("lib.txt",ios::in|ios::binary);
        cout<<"\n\n\n\tEnter book name whose record to be seen  :";
        cin>>name;
        do
        {
            f.read((char *)&b1,sizeof(b1));
            if(f.eof()==1)
            {
                break;
            }
            if(strcmp(b1.name,name)==0)
            {
                cout<<"\n	Name     :"<<b1.name;
                cout<<"\n	Author   :"<<b1.author;
                cout<<"\n	copies   :"<<b1.a;
            }
        }
        while(f);
        f.close();
        cout<<"\n\tDo You Want To Continue(Y&y/N&n):";
        cin>>ans;
		if(ans=='Y' || ans=='y')
            goto z;
        else if(ans=='n'||ans=='N')
        	goto x;
	}
	break;
    case 4:		//DETAILS : TO MODIFY A RECORD
    {
        system("cls");
        char ans;
        fstream f;
        book b1;
        char name[20];
        char author[20];
        int a;
        f.open("lib.txt",ios::in|ios::out|ios::binary);
        cout<<" Enter book name whose record to be changed  :";
        cin>>name;
        do
        {
            f.read((char *)&b1,sizeof(b1));
            if(f.eof()==1)
            {
                break;
            }
            if(strcmp(b1.name,name)==0)
            {
                cout<<"\n\tName     :"<<b1.name;
                cout<<"\n\tAuthor   :"<<b1.author;
                cout<<"\n\tCopies   :" <<b1.a;
                getchar();
                cout<<"\n\tEnter New Values" ;
                cout<<"\n\n\tEnter the book name  :";
                cin>>name;
                cout<<"\tEnter author name    :";
                cin>>author;
                cout<<"\tEnter no. of copies  :";
                cin>>a;
                strcpy(b1.name,name);
                strcpy(b1.author,author);
                b1.a=a;
                int l=f.tellg();
                f.close();
                f.open("book.txt",ios::out|ios::binary|ios::ate);
                f.seekg(l-sizeof(b1));
                f.write((char *)&b1,sizeof(b1));
            }
        }
        while(f);
		f.close();
        cout<<"\n\tDo You Want To Continue(Y&y/N&n):";
        cin>>ans;
		if(ans=='Y' || ans=='y')
            goto z;
        else if(ans=='n'||ans=='N')
        	goto x;
    }
	break;
    case 5:		//DETAILS : TO DELETE A BOOKS RECORD
    {
        system("cls");
		char name[20];
        f.close();
        f.open("lib.txt",ios::in|ios::ate|ios::binary);
        cout<<"DELETING:-";
        cout<<"\n\n\tEnter The  Name U Want To delete:\t";
        fflush(stdin);
        cin>>name;
        f.seekg(0);
        int k=0;
        do
        {
            f.close();
            f.open("lib.txt",ios::in|ios::ate|ios::binary);
            f.seekg(k);
            fflush(stdin);
            f.read((char *)&b1,sizeof(b1));
            if(f.eof())
                break;
            if(strcmp(b1.name,name)==0)
            {
                k+=46;
                continue;
            }
            else
            {
                f.close();
                f.open("lib.txt",ios::out|ios::ate|ios::binary);
                f.write((char*)&b1, sizeof b1);
                k+=46;
            }
        }
        while(f);
        f.close();
        remove ("lib.txt");
        rename ("lib1.txt","lib.txt");
        cout<<"\n\n\n\n\n\tPress Any Key...";
        getch();
        goto z;
    }
	break;
    case 6:		//DETAILS : TO EXIT
    {
    	x:
		cout<<"\n\tTHANKS FOR VISITING";
    }
    break;
    }
}
