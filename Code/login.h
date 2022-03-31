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

void logIn(student *&pHead_s,staff *&pHead_t,string *use,int *role)
{
	string roles1;
	string roles2;

	int choose=0,granted=0;
	
	string userName;	
	do{
		staff *pT=pHead_t;
		student *pS=pHead_s;
		cout<< "Press 1: Log in"<<endl;
		cout<< "Press 2: Sign up"<<endl;
		cout<< "I choose: ";
		cin>>choose;
		switch (choose)
		{
			case 1:
				{
					cout<<"You are teacher or student ?"<<endl;
					cout<<"I am ";
					cin>>roles1;
					system("cls");
					if(roles1.compare("teacher")==0){
					cout<< "Type ""/esc"" to back "<<endl;
					cout<<"Enter username: ";
					cin>>userName;
					while(pT->userName.compare(userName)!=0){
						if(userName.compare("/esc")==0)break;

						pT=pT->pNext;
						if(pT==NULL)
						{
							system("cls");
							cout<<"Not found! Type again: ";
							cin>>userName;
							pT=pHead_t;	
						}
						
					}
					if(userName.compare("/esc")==0)
					{
						system("cls");
						break;
					}
					system("cls");
					cout<<"Username: "<<pT->userName<<endl;
					cout<<"Type password: ";
					string passWord;
					cin>>passWord;
					while(pT->passWord.compare(passWord)!=0){
							system("cls");
							cout<<"Username: "<<pT->userName<<endl;
							cout<<"Wrong! Type again: ";
							cin>>passWord;
					}
					cout<<"Access granted !"<<endl;
					*use=pT->userName;
					granted=1;
					break;
				}
				if(roles1.compare("student")==0)
				{
					system("cls");
					cout<< "Type ""/esc"" to back "<<endl;
					cout<<"Enter username: ";
					cin>>userName;
					while(pS->userName.compare(userName)!=0){
						if(userName.compare("/esc")==0)break;
						pS=pS->pNext;
						if(pS==NULL)
						{
							system("cls");
							cout<<"Not found! Type again: ";
							cin>>userName;
							pS=pHead_s;	
						}
						
					}
					if(userName.compare("/esc")==0)
					{
						system("cls");
						break;
					}
					system("cls");
					cout<<"Username: "<<pS->userName<<endl;
					cout<<"Type password: ";
					string passWord;
					cin>>passWord;
					while(pS->passWord.compare(passWord)!=0){
							system("cls");
							cout<<"Username: "<<pS->userName<<endl;
							cout<<"Wrong! Type again: ";
							cin>>passWord;
					}
					cout<<"Access granted !"<<endl;
					*use=pS->userName;
					granted=1;break;
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
	}while(granted!=1) ;

	if(roles1.compare("teacher")==0){*role=1;}
	if(roles1.compare("student")==0){*role=0;}
	}


