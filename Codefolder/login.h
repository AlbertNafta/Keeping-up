#include <iostream>
#include<thread>
#include <conio.h>
#include <windows.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<windows.h>
#include <windows.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
void txtColor(int color);
void gotoxy(int x, int y);
void drawF(int col, int row, int x, int y);
void DisplayGeneral(int &r);
void DisplayLogin(string *roles);
void DisplayUser(string *roles,string *userName );
void DisplayNotFound(string *roles,string *userName );
void DisplayTypePass(string *userName,string *passWord );
void DisplayTypeWrongPass(string *userName,string *passWord );


struct student{
	string userName;
	string passWord;
	string firstName;
	string lastName;
	string gender;
	string birth;
	int social_ID;
	
	student *pNext;
};

struct staff{
	string userName;
	string passWord;
	string name;
	int age;
	string majors;
	staff *pNext;
};

void inputUserProfile(student *&pHead_s) // user = student
{
	student *pC = pHead_s;
	FILE *file = fopen("User.CSV", "r");
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			pC->userName=v;
			v = strtok(NULL, ",");
			pC->passWord=v;
			v = strtok(NULL, ",");
			pC->lastName=v;
			v = strtok(NULL, ",");
			pC->firstName=v;
			v = strtok(NULL, ",");
			pC->gender=v; 
			v = strtok(NULL, ",");
			pC->birth=v;
			v = strtok(NULL, ",");
			pC->social_ID=atoi(v);
			v = strtok(NULL, ",");
		}

		pC->pNext=new student;
		pC=pC->pNext;
	}
	pC=pHead_s;
	while(pC->pNext->pNext!=NULL)
	{
		pC=pC->pNext;
	}
	student *pDel=pC->pNext;
	pC->pNext=NULL;
	delete pDel;


	fclose(file);

}


void inputTeacherProfile(staff *&pHead_t)
{
	staff *pC = pHead_t;
	FILE *file = fopen("Teacher.CSV", "r");
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			pC->userName=v;
			v = strtok(NULL, ",");
			pC->passWord=v;
			v = strtok(NULL, ",");
			pC->name=v;
			v = strtok(NULL, ",");
			pC->age=atoi(v);
			v = strtok(NULL, ",");
			pC->majors=v;
			v = strtok(NULL, ",");
		}
		pC->pNext=new staff;
		pC=pC->pNext;
	}
	pC=pHead_t;
	while(pC->pNext->pNext!=NULL)
	{
		pC=pC->pNext;
	}
	staff *pDel=pC->pNext;
	pC->pNext=NULL;
	delete pDel;
	fclose(file);
}

void OutputUser(student *&pHead_s)
{
fstream fout;
  
    // opens an existing csv file or creates a new file.

  
    // opens an existing csv file or creates a new file.
    fout.open("User.CSV", ios::out );

  	
  	student *pC=pHead_s;
    // Read the input
    while(pC!=NULL) 
	{
		if(pC!=pHead_s)fout<<endl;
	
        fout <<pC->userName<<","
			<<pC->passWord<<","
			<<pC->lastName<<","
			<<pC->firstName<<","
			<<pC->gender<<","
			<<pC->birth<<","
			<<pC->social_ID;
	pC=pC->pNext;
	}
		
		
    
}

void OutputStaff(staff *&pHead_t)
{
fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("Teacher.CSV", ios::out );

  	
  	staff *pC=pHead_t;
    // Read the input
    while(pC!=NULL) 
	{
		if(pC!=pHead_t)fout<<"";
		if(pC->pNext==NULL)fout<<endl;
        fout <<pC->userName<<","
			<<pC->passWord<<","
			<<pC->name<<","
			<<pC->age<<","
			<<pC->majors;
	pC=pC->pNext;
	}
	
}

void logIn(student *&pHead_s,staff *&pHead_t,string *use,int *role,int &log)
{
	string roles1;
	string roles2;
	int r;
	int choose=0,granted=0;
	
	string userName;	
	do{
		staff *pT=pHead_t;
		student *pS=pHead_s;
		DisplayGeneral(r);
		if(r==24)choose=2;
		if(r==20)choose=1;
		if(r==28)choose=0;
		switch (choose)
		{
			case 1:
				{
					system("cls");
					DisplayLogin(&roles1);
					system("cls");
					if(roles1.compare("teacher")==0){
						DisplayUser(&roles1,&userName);//----------------------------------------
					
					while(pT->userName.compare(userName)!=0){
						if(userName.compare("/esc")==0)break;

						pT=pT->pNext;
						if(pT==NULL)
						{
							system("cls");
							DisplayNotFound(&roles1,&userName);
							pT=pHead_t;	
						}
						
					}
					if(userName.compare("/esc")==0)
					{
						system("cls");
						break;
					}
					system("cls");
					string passWord;
					
					DisplayTypePass(&userName,&passWord );
					while(pT->passWord.compare(passWord)!=0){
							system("cls");
							DisplayTypeWrongPass(&userName,&passWord );
					}
					system("cls");
					cout<<"ACCESS GRANTED !"<<endl;
					sleep(1);
					*use=pT->userName;
					granted=1;
					system("cls");
					txtColor(7);
					break;
				}
				if(roles1.compare("student")==0)
				{
					DisplayUser(&roles1,&userName);//----------------------------------------
					
					while(pS->userName.compare(userName)!=0){
						if(userName.compare("/esc")==0)break;
						pS=pS->pNext;
						if(pS==NULL)
						{
							system("cls");
							DisplayNotFound(&roles1,&userName);
							pS=pHead_s;	
						}
						
					}
					if(userName.compare("/esc")==0)
					{
						system("cls");
						break;
					}
					system("cls");
					string passWord;
					DisplayTypePass(&userName,&passWord );
					while(pS->passWord.compare(passWord)!=0){
							system("cls");
							DisplayTypeWrongPass(&userName,&passWord );
					}
					system("cls");
					cout<<"ACCESS GRANTED !"<<endl;
					sleep(1);
					*use=pS->userName;
					granted=1;
					system("cls");
					txtColor(7);
					break;
				}
				}
			case 2:
				{
				system("cls");
				cout<<"Are you REALLY want to sign up?"<<endl;
				cout<<"There is no turning back and the given information must be right !"<<endl;
				cout<<"Sign up ? (y/n): ";
				cin>>roles2;
				system("cls");
				if(roles2.compare("n")==0)break;
				cout<<"Sign up as (student or teacher): ";
				cin>>roles2;
				if(roles2.compare("student")==0){
				pS=pHead_s;
				while(pS->pNext!=NULL){
				pS=pS->pNext;
				}
					pS->pNext=new student;
					pS=pS->pNext;
					cout<<"Username: ";
					cin>>pS->userName;
					student *pS2=pHead_s;
					while(pS2!=pS)
					{
						if(pS2->userName.compare(pS->userName)==0)
						{
							cout<<"Username taken! "<<endl;
							cout<<"Username: ";
							cin>>pS->userName;
							pS2=pHead_s;
						}
						pS2=pS2->pNext;
					}
					cout<<"Last name: ";
					cin>>pS->lastName;
					cout<<"First name: ";
					cin>>pS->firstName;
					cout<<"Gender: ";
					cin>>pS->gender;
					cout<<"Birthdate: ";
					cin>>pS->birth;
					cout<<"Social ID (8nums): ";
					cin>>pS->social_ID;
					cout<<"And password is: ";
					cin>>pS->passWord;

					system("cls");
					cout<<"DONE !!!";
					sleep(2);
					system("cls");
					pS->pNext=NULL;
					OutputUser(pHead_s);
					
					break;
					
				}
				if(roles2.compare("teacher")==0)
				{
					pT=pHead_t;
				while(pT->pNext!=NULL)
				{
					pT=pT->pNext;
				}
					pT->pNext=new staff;
					pT=pT->pNext;
					cout<<"Username: ";
					cin>>pT->userName;
					staff *pT2=pHead_t;
					while(pT2!=pT)
					{
						if(pT2->userName.compare(pT->userName)==0)
						{
							cout<<"Username taken! "<<endl;
							cout<<"Username: ";
							cin>>pT->userName;
							pT2=pHead_t;
							
						}
						pT2=pT2->pNext;
					}
					cout<<"Real name: ";
					cin>>pT->name;
					cout<<"Age: ";
					cin>>pT->age;
					cout<<"Major: ";
					cin>>pT->majors;

					cout<<"And password is: ";
					cin>>pT->passWord;
					pT->pNext=NULL;
					OutputStaff(pHead_t);
					system("cls");
					cout<<"DONE !!!";
					sleep(2);
					system("cls");
					
					
					
					break;
				}
			}
		}
	}while(granted!=1 and choose!=0) ;
	if(choose==0)
	{
		log=0;
		return;
	}
	
	if(roles1.compare("teacher")==0){*role=1;}
	if(roles1.compare("student")==0){*role=0;}
	}

void DisplayGeneral(int &r)
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(77, 13);
	cout<<"PRESS / TO CHOOSE ";
	gotoxy(72, 14);
	cout<<"Press w or s to go up or down";
	
//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(78, 20);
	cout << "Log in: ";
	gotoxy(78, 24);
	cout << "Sign up: ";
	txtColor(11);
	drawF(2, 13, 75, 19);
	drawF(2, 13, 75, 23);
	
	txtColor(7);
	drawF(2, 2, 75+16, 19);
	drawF(2, 2, 75+16, 23);
	gotoxy(70, 28);
	
	gotoxy(78, 28);
	txtColor(11);
	cout << "Exit... ";
	drawF(2, 13, 75, 27);
	txtColor(7);
	drawF(2, 2, 75+16, 27);
	
		int i=2;
	r=24;
		gotoxy(92,r);
	while(i!=0)
	{
		char move;
		move=_getch();
		if(move=='s'){r+=4;if(r>28)r=28;gotoxy(92,r);}
		if(move=='w'){r-=4;if(r<20)r=20;gotoxy(92,r);}
		if(move=='/'){return;}
	}
}
void drawF(int col, int row, int x, int y) {
	gotoxy(x, y); cout << char(201);
	for (int i = x + 1; i < x + row ; i++)
		cout << char(205);
	cout << char(187);
	//gotoxy(x + row, y); cout << char(187);
	//gotoxy(x, y + col); cout << char(200);
	
	for (int i = y + 1; i < y + col; i++) {
		gotoxy(x, i);
		cout << char(186);
		gotoxy(x + row, i);
		cout << char(186);
	}
	gotoxy(x, y + col);
	cout << char(200);
	for (int i = x + 1; i < x + row; i++)
		cout << char(205);
	cout << char(188);

}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//color
void txtColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void DisplayLogin(string *roles)
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(70, 10);
	cout << "     __             _       ";
	gotoxy(70, 11);
	cout << "    / /  ___   __ _(_)_ __  ";
	gotoxy(70, 12);
	cout << "   / /  / _ \\ / _` | | '_ \\ ";
	gotoxy(70, 13);
	cout << "  / /__| (_) | (_| | | | | |";
	gotoxy(70, 14);
	cout << "  \\____/\\___/ \\__, |_|_| |_|";
	gotoxy(70, 15);
	cout << "              |___/         ";

//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(72, 20);
	cout<<"You are teacher or student ?";
	gotoxy(72, 24);
	cout << "I am the : ";
	txtColor(11);
	drawF(2, 32, 69, 19);
	drawF(2, 32, 69, 23);
	
	txtColor(7);
	gotoxy(83,24);
	string in;
	cin>>in;
	*roles=in;
	
}

void DisplayUser(string *roles,string *userName )
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(70, 10);
	cout << "     __             _       ";
	gotoxy(70, 11);
	cout << "    / /  ___   __ _(_)_ __  ";
	gotoxy(70, 12);
	cout << "   / /  / _ \\ / _` | | '_ \\ ";
	gotoxy(70, 13);
	cout << "  / /__| (_) | (_| | | | | |";
	gotoxy(70, 14);
	cout << "  \\____/\\___/ \\__, |_|_| |_|";
	gotoxy(70, 15);
	cout << "              |___/         ";

//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(62, 24);
	cout << "Username: ";
	txtColor(11);
	drawF(2, 13, 59, 23);
	
	txtColor(7);
	drawF(2, 41, 65, 19);
	gotoxy(66,20);
	cout<<"! You are currently sign in as "<<*roles<<" !";
	drawF(2, 37, 75, 23);
	gotoxy(70, 28);
	cout << "Press /esc to back to menu... ";
	

	
	string innn;
		gotoxy(77,24);
	cin>>innn;
	*userName=innn;
}

void DisplayNotFound(string *roles,string *userName )
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(70, 10);
	cout << "     __             _       ";
	gotoxy(70, 11);
	cout << "    / /  ___   __ _(_)_ __  ";
	gotoxy(70, 12);
	cout << "   / /  / _ \\ / _` | | '_ \\ ";
	gotoxy(70, 13);
	cout << "  / /__| (_) | (_| | | | | |";
	gotoxy(70, 14);
	cout << "  \\____/\\___/ \\__, |_|_| |_|";
	gotoxy(70, 15);
	cout << "              |___/         ";

//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(62, 24);
	cout << "Username: ";
	txtColor(11);
	drawF(2, 13, 59, 23);
	
	txtColor(7);
	drawF(2, 41, 65, 19);
	gotoxy(66,20);
	cout<<"! Cannot found that username, do agian !";
	drawF(2, 37, 75, 23);
	gotoxy(70, 28);
	cout << "Press /esc to back to menu... ";
	

	
	string innn;
		gotoxy(77,24);
	cin>>innn;
	*userName=innn;
}

void DisplayTypePass(string *userName,string *passWord )
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(70, 10);
	cout << "     __             _       ";
	gotoxy(70, 11);
	cout << "    / /  ___   __ _(_)_ __  ";
	gotoxy(70, 12);
	cout << "   / /  / _ \\ / _` | | '_ \\ ";
	gotoxy(70, 13);
	cout << "  / /__| (_) | (_| | | | | |";
	gotoxy(70, 14);
	cout << "  \\____/\\___/ \\__, |_|_| |_|";
	gotoxy(70, 15);
	cout << "              |___/         ";

//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(62, 24);
	cout << "Password: ";
	txtColor(11);
	drawF(2, 13, 59, 23);
	
	txtColor(7);
	drawF(2, 41, 65, 19);
	gotoxy(66,20);
	txtColor(11);
	cout<<" Username: "<<*userName;
	drawF(2, 37, 75, 23);
	gotoxy(70, 28);
	cout << " ";
	

	
	string pass;
		gotoxy(77,24);
	cin>>pass;
	*passWord=pass;
}

void DisplayTypeWrongPass(string *userName,string *passWord )
{
	txtColor(11);
	gotoxy(60, 1);
	cout << "  8888888b.                   888             888 ";
	gotoxy(60, 2);
	cout << "  888   Y88b                  888             888 ";
	txtColor(3);
	gotoxy(60, 3);
	cout << "  888    888                  888             888 ";
	gotoxy(60, 4);
	cout << "  888   d88P  .d88b.  888d888 888888  8888b.  888 ";
	gotoxy(60, 5);
	cout << "  8888888P\"  d88\"\"88b 888P\"   888        \"88b 888 ";
	txtColor(1);
	gotoxy(60, 6);
	cout << "  888        888  888 888     888    .d888888 888 ";
	gotoxy(60, 7);
	cout << "  888        Y88..88P 888     Y88b.  888  888 888 ";
	gotoxy(60, 8);
	cout << "  888         \"Y88P\"  888      \"Y888 \"Y888888 888 ";
	gotoxy(60, 9);
	cout << "                                                  ";  

	txtColor(15);
	gotoxy(70, 10);
	cout << "     __             _       ";
	gotoxy(70, 11);
	cout << "    / /  ___   __ _(_)_ __  ";
	gotoxy(70, 12);
	cout << "   / /  / _ \\ / _` | | '_ \\ ";
	gotoxy(70, 13);
	cout << "  / /__| (_) | (_| | | | | |";
	gotoxy(70, 14);
	cout << "  \\____/\\___/ \\__, |_|_| |_|";
	gotoxy(70, 15);
	cout << "              |___/         ";

//--right here
	drawF(6,35, 68, 10);
	
	txtColor(11);
	gotoxy(62, 24);
	cout << "Password: ";
	txtColor(11);
	drawF(2, 13, 59, 23);
	
	txtColor(7);
	drawF(2, 41, 65, 19);
	gotoxy(66,20);
	txtColor(11);
	cout<<" Username: "<<*userName;
	drawF(2, 37, 75, 23);
	gotoxy(70, 28);
	cout << " ";
	txtColor(7);
	gotoxy(67, 28);
	cout << "Wrong password !!! Please type agian... ";	

	
	string pass;
		gotoxy(77,24);
	cin>>pass;
	*passWord=pass;
}
