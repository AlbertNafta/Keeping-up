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

void viewYourclass(classes *&pHead_c,student *&pHead_s,string use)
{
						classes *pc=pHead_c;
						student *ps=pHead_s;
						student *ps2;
						while(ps!=NULL)
						{
							if(ps->userName.compare(use)==0)
							{
								ps2=ps;
								break;
							}
							ps=ps->pNext;
						}
						
						int found=0;
						while(pc!=NULL)
						{

							for(int z=0;z<pc->number;z++)
							{
								if(pc->student[z]==ps2->social_ID)
								{
									found=1;
									break;
								}
								
							
							}
						
							if(found==1)break;
							pc=pc->pDoor;
						}
						if(found==0)
						{
							cout<<"You have no class !";
							_getch();
							system("cls");
							return;
						}
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
						cout<<endl<<"Press any key to continue...";
						_getch();
}

void viewStudentPro(student *&pHead_s,string uses)
{
	student *pT2=pHead_s;
					while(pT2!=NULL)
					{
						if(pT2->userName.compare(uses)==0)
						{
							break;
						}
						pT2=pT2->pNext;
					}
	system("cls");
	cout<<"Username: "<<pT2->userName<<endl;
	cout<<"Password: "<<pT2->passWord<<endl;
	cout<<"First name: "<<pT2->firstName<<endl;
	cout<<"Last name: "<<pT2->lastName<<endl;	
	cout<<"Birthday: "<<pT2->birth<<endl;
	cout<<"Gender: "<<pT2->gender<<endl;
	cout<<"Social ID: "<<pT2->social_ID;
	cout<<endl<<"Do you want to change password ? (y/n)";
	char change;
	cin>>change;
	if(change=='y'||change=='Y')
	{
		string pass;
		cout<<"Type new password: ";
		cin>>pass;
		system("cls");
		string pass2;
		cout<<"Rewrite your password: ";
		cin>>pass2;
		while(pass2.compare(pass)!=0)
		{
			cout<<"Not match! Type again: ";
			cin>>pass2;
		}
		pT2->passWord=pass;
		cout<<"DONE !!!";
		sleep(2);
		system("cls");
		OutputUser(pHead_s);
	}
	cout<<"Press any to continue: ";
	_getch();
}

void courseRegistration(courses *&head,string here,student *&pHead_s)
{
	courses *pc=head;
	student *pT2=pHead_s;
	int line,want,no=0;
	do{
		no=0;
					pc=head;
					line=1;
					while(pc!=NULL)
					{
						cout<<line<<":"<<endl;
						cout<<"Name: "<<pc->name<<endl;
							cout<<"Course ID: "<<pc->ID<<endl;
							cout<<"Number of credits: "<<pc->credits<<endl;
							cout<<"Taught by: "<<pc->teacher<<endl<<endl;
							cout<<"Number of student: "<<pc->numberStu<<endl;

							pc=pc->jump;
							cout<<"_____________________________"<<endl;
							line++;
					}
					cout<<"Press 0 to exit"<<endl;
					cout<<"What course you want to sign up ? (1 to "<<line-1<<") "<<endl;
					cout<<"I want course number ";
					cin>>want;
					if(want!=0)
					{
						pc=head;
						for(int a=1;a<want;a++)
						{
							pc=pc->jump;
						}
						
//------------------------------------------student matching
					pT2=pHead_s;
					while(pT2!=NULL)
					{
						if(pT2->userName.compare(here)==0)
						{
							break;
						}
						pT2=pT2->pNext;
					}
//----------------------------------------
					for(int a=0;a<pc->numberStu;a++){
					if(pc->StuID[a]==pT2->social_ID)
					{
						system("cls");
						cout<<"You already in class !!!";
						sleep(1);
						no=1;
						system("cls");
					}
					}
					if(no==1)continue;
						pc->numberStu+=1;
						pc->StuID[pc->numberStu-1]=pT2->social_ID;
					}
					system("cls");
					cout<<"DONE !!!";
					sleep(1);
					system("cls");
	}while(want!=0);
}

void viewScore(score *&sco,string name,student *&pHead_s,courses *&head)
{
	score *pc=sco;
	student *pp=pHead_s;
	while(pp!=NULL)
	{
		if(pp->userName.compare(name)==0)break;
		pp=pp->pNext;
	}
						courses *ps=head;
						while(pc!=NULL)
						{
							if(pc->stuName.compare(pp->lastName)==0)break;
							pc=pc->paper;
						}
							cout<<"Name: "<<pc->stuName<<endl;
							
							for(int z=0;z<pc->subject;z++)
							{
								cout<<z+1<<".|";
								ps=head;
								while(ps!=NULL)
								{
									if(ps->ID==pc->final[z][0])
									{
										break;
									}
									ps=ps->jump;
								}
								cout<<ps->name<<": "<<pc->final[z][1]<<endl;
							}
						
							cout<<endl;
						
						cout<<"Press any key to back..."<<endl;
						_getch();
}
void courseScare(courses *&head,string here,student *&pHead_s)
{
	courses *pc=head;
	student *pT2=pHead_s;
	int line,want,no=0;
	do{
		no=0;
					pc=head;
					line=1;
					while(pc!=NULL)
					{
						cout<<line<<":"<<endl;
						cout<<"Name: "<<pc->name<<endl;
							cout<<"Course ID: "<<pc->ID<<endl;
							cout<<"Number of credits: "<<pc->credits<<endl;
							cout<<"Taught by: "<<pc->teacher<<endl<<endl;
							cout<<"Number of student: "<<pc->numberStu<<endl;

							pc=pc->jump;
							cout<<"_____________________________"<<endl;
							line++;
					}
					cout<<"Press 0 to exit"<<endl;
					cout<<"What course you want to get out ? (1 to "<<line-1<<") "<<endl;
					cout<<"I want course number ";
					cin>>want;
					if(want!=0)
					{
						pc=head;
						for(int a=1;a<want;a++)
						{
							pc=pc->jump;
						}
						
//------------------------------------------student matching
					pT2=pHead_s;
					while(pT2!=NULL)
					{
						if(pT2->userName.compare(here)==0)
						{
							break;
						}
						pT2=pT2->pNext;
					}
//----------------------------------------
					for(int a=0;a<pc->numberStu;a++){
						no=1;
					if(pc->StuID[a]==pT2->social_ID)
					{
						pc->StuID[pc->numberStu-1]=0; //can i do '\0'  ???
						pc->numberStu-=1;
						no=0;
					}
					
					}
					if(no==1)
					{
						system("cls");
						cout<<"You are not in there !!!";
						sleep(1);
						system("cls");
					}
					}
					if(no==0){
					system("cls");
					cout<<"DONE !!!";
					sleep(1);
					system("cls");
					}
	}while(want!=0);	
}

void menuStudent(score *& sco,classes *&pHead_c,student *&pHead_s,string *use,int &courseAllow,courses *&head){

int choose,choose2;
string here=*use;
	do{
		cout<<"Press 1: View your class"<<endl;
		cout<<"Press 2: View profile"<<endl;
		cout<<"Press 3: Course registration... "<<endl;
		cout<<"Press 4: Course disregistration..."<<endl;
		cout<<"Press 5: View final mark "<<endl;
		cout<<"Press 6: Exit"<<endl;
		cout<<"I choose: ";
		cin>>choose;
		choose2=0;
		switch(choose)
		{
			case 1:
				system("cls");
				viewYourclass(pHead_c,pHead_s,here);
				system("cls");
				break;
			case 2:
				system("cls");
				viewStudentPro(pHead_s,here);
				system("cls");
				break;				
			case 3:{
				system("cls");
				if(courseAllow==1)
				{
					courseRegistration(head,here,pHead_s);
				}
				if(courseAllow==0)
				{
					cout<<"Not availble !!!";
					sleep(1);
				}
				system("cls");
				break;
			}
			case 4:{
				courseScare(head,here,pHead_s);
				system("cls");
				break;
			}
			case 5:{
				system("cls");
				viewScore(sco,here,pHead_s,head);
				system("cls");
				break;
			}
				
		}
	
		
	}while(choose!=6);

}
