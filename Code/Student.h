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

void menuStudent(classes *&pHead_c,student *&pHead_s,string *use,int &courseAllow){

int choose,choose2;
string here=*use;
	do{
		cout<<"Press 1: View your class"<<endl;
		cout<<"Press 2: View profile"<<endl;
		cout<<"Press 3: Course sign up... "<<endl;
		cout<<"Press 4: ??? "<<endl;
		cout<<"Press 5: Exit"<<endl;
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
			case 3:{//this is not done yet
				if(courseAllow==1)
				{
					cout<<"OK...";
					getch();
				}
				system("cls");
				break;
			}
				
		}
	
		
	}while(choose!=5);

}
