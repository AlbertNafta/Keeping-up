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
#include "Schoolyear.h"

using namespace std;


struct classes{
	string className;
	int number;
	int student[60];
	classes *pDoor;
};

void createClass(classes *&pHead_c)
{
	system("cls");
	cout<<"This work only for input CSV"<<endl;
	classes *pC=pHead_c;
	cout<<"Enter file name: ";
	char fname[1024];
	scanf ("%s", fname);
	FILE *file = fopen(fname, "r");
	while(pC->pDoor!=NULL)pC=pC->pDoor;
	pC->pDoor=new classes;
	pC=pC->pDoor;
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			pC->className=v;
			v = strtok(NULL, ",");
			pC->number=atoi(v);
			v = strtok(NULL, ",");
			for(int a=0;a<pC->number;a++)
			{
				pC->student[a]=atoi(v);
				v = strtok(NULL, ",");
			}
		}
		pC->pDoor=new classes;
		pC=pC->pDoor;
	}
	pC=pHead_c;
	while(pC->pDoor->pDoor!=NULL)
	{
		pC=pC->pDoor;
	}
	classes *pDel=pC->pDoor;
	pC->pDoor=NULL;
	delete pDel;
	fclose(file);
}

void addStudentToClass(classes *&pHead_c,student *&pHead_s)
{
		string className;
		cout<<"Class name: ";
		cin>>className;
		classes *pS=pHead_c;
		while(className.compare(pS->className)!=0)
			{
				pS=pS->pDoor;
				if(pS==NULL)
				{
					cout<<"No such class!!! Type again: ";
					cin>>className;
					pS=pHead_c;
				}
			}
		cout<<"Enter student's social ID to add: ";
		int ID;
		cin>>ID;
		student *pC=pHead_s;
		int granted=0;
		while(granted==0){
		
			while(ID!=pC->social_ID)
				{
					pC=pC->pNext;
					if(pC==NULL)
					{
						cout<<"No such student!!! Type again: ";
						cin>>ID;
						pC=pHead_s;
					}
				}
			int no=0;
			for(int a=0;a<pS->number;a++)
			{
				if(pS->student[a]==ID)
				{
					cout<<"This student is in class !!!Type again: ";
					cin>>ID;
					no=1;
					break;
				}
				
			}
			if(no==0)granted=1;
			
		}
		pS->student[pS->number]=ID;
		pS->number+=1;
		
		cout<<"Done !!!";
		_getch();
}

void removeStudentFromClass(classes *&pHead_c,student *&pHead_s)
{
	string className;
		cout<<"Class name: ";
		cin>>className;
		classes *pS=pHead_c;
		while(className.compare(pS->className)!=0)
			{
				pS=pS->pDoor;
				if(pS==NULL)
				{
					cout<<"No such class!!! Type again: ";
					cin>>className;
					pS=pHead_c;
				}
			}
	cout<<"Enter student's social ID to remove: ";
		int ID,here;
		cin>>ID;
		student *pC=pHead_s;
		int granted=0;
		while(granted==0){
		
			while(ID!=pC->social_ID)
				{
					pC=pC->pNext;
					if(pC==NULL)
					{
						cout<<"No such student!!! Type again: ";
						cin>>ID;
						pC=pHead_s;
					}
				}
			int no=0;
			for(int a=0;a<pS->number;a++)
			{
				if(pS->student[a]==ID)
				{
					no=0;
					here=a;
					break;
				}
				if(a==pS->number-1)
				{
				
					cout<<"This student is not in class !!!Type again: ";
					cin>>ID;
					no=1;
					a=0;
					break;
				}
				

			}
			if(no==0)granted=1;
			
		}
		pS->number-=1;
		for(int n=0;n<70;n++)
		{
			pS->student[here+n]=pS->student[here+n+1];
			if(pS->student[here+n+2]=='\0'){
				pS->student[here+n+1]=='\0';
				break;
			}
		}
		cout<<"DONE !!!";
		sleep(2);
}

void editClasses(classes *&pHead_c,student *&pHead_s)
{
	int choose3;
	classes *pS;
	cout<<"Press 1: Add student"<<endl;
	cout<<"Press 2: Remove student from class"<<endl;
	cout<<"Press 3: Back..."<<endl;
	cout<<"I choose: ";
	cin>>choose3;
	if(choose3==1){
			addStudentToClass(pHead_c,pHead_s);
		}
	else if(choose3==2)
	{
		removeStudentFromClass(pHead_c,pHead_s);
	}
	else if(choose3==3)return;
}

void inputClasses(classes *&pHead_c)
{
	
	classes *pC=pHead_c;
	FILE *file = fopen("Class.CSV", "r");
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			pC->className=v;
			v = strtok(NULL, ",");
			pC->number=atoi(v);
			v = strtok(NULL, ",");
			for(int a=0;a<pC->number;a++)
			{
				pC->student[a]=atoi(v);
				v = strtok(NULL, ",");
			}
		}
		pC->pDoor=new classes;
		pC=pC->pDoor;
	}
	pC=pHead_c;
	while(pC->pDoor->pDoor!=NULL)
	{
		pC=pC->pDoor;
	}
	classes *pDel=pC->pDoor;
	pC->pDoor=NULL;
	delete pDel;
	fclose(file);
}

void viewClass(classes *&pHead_c,student *&pHead_s)
{

						classes *pc=pHead_c;
						student *ps=pHead_s;
						while(pc!=NULL)
						{
							cout<<"Name: "<<pc->className<<endl;
							cout<<"Number of student: "<<pc->number<<endl;
							for(int z=0;z<pc->number;z++)
							{
								cout<<z+1<<".|";
								ps=pHead_s;
								while(ps!=NULL)
								{
									if(ps->social_ID==pc->student[z])
									{
										break;
									}
									ps=ps->pNext;
								}
								cout<<pc->student[z]<<" | "<<ps->lastName<<endl;
							}
							pc=pc->pDoor;
							cout<<endl;
						}
						cout<<"Press any key to back..."<<endl;
						_getch();
}

void outputClass(classes *&pHead_c)
{
fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("Class.CSV", ios::out );

  	
  	classes *pC=pHead_c;
    // Read the input
    while(pC!=NULL) 
	{
		if(pC!=pHead_c)fout<<endl;
		
        fout <<pC->className<<","
			<<pC->number<<",";
		for(int a=0;a<pC->number;a++)
		{
			fout<<pC->student[a];
			if(a!=pC->number-1)
			fout<<",";
		}
	pC=pC->pDoor;
	}
		
		
    
}


void MenuTeacher(staff *&pHead_t,staff *&pT,student *&pHead_s)
{
	int choose,choose2;
	classes *pHead_c = new classes;
	inputClasses(pHead_c);
	do{
		cout<<"Press 1: Manage class"<<endl;
		cout<<"Press 2: Manage courses"<<endl;
		cout<<"Press 3: Create school year ? "<<endl;
		cout<<"Press 4: View profile "<<endl;
		cout<<"Press 5: Exit"<<endl;
		cout<<"I choose: ";
		cin>>choose;
		choose2=0;
		switch(choose)
		{
			case 1:
				do{
				system("cls");
				cout<<"Press 1: Create class"<<endl;
				cout<<"Press 2: View class"<<endl;
				cout<<"Press 3: Edit class"<<endl;
				cout<<"Press 4: Exit"<<endl;
				cout<<"I choose: ";
				cin>>choose2;
				switch(choose2)
				{
					case 1:{
						createClass(pHead_c);
						outputClass(pHead_c);
						break;
					}
					case 2:{
						viewClass(pHead_c,pHead_s);
						
						break;
					}
					case 3:
					{
					
						system("cls");
						
						editClasses(pHead_c,pHead_s);
						outputClass(pHead_c);
						sleep(2);system("cls");
						}break;
						
				}
				}while(choose2!=4);system("cls");break;
			
			case 3:{
				creatSchoolYear();
				system("cls");
				break;
			}
				
				
		}
	
		
	}while(choose!=5);
}

