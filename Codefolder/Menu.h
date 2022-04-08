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

struct timeTable{
	int week[4][7];//contain courses's ID
};

struct courses{
			string name;
			string teacher;
			string startDate;
			string endDate;
			int numberStu;
			int StuID[60];  //the course can contain 60students ! 
			int ID;//course ID
			int credits;
			int nums;//nums of lessons

			courses *jump; //pointer fo linked list
};

struct aSchoolYear{
	struct semester{
		string startDate;
		string endDate;
		int coursesID[30];// an array of courses's ID which will refer to -> struct courses
		
	}Fall1,Summer2,Autumm3;
}year1;

struct classes{
	string className;
	int number;
	int student[60];
	classes *pDoor;
};

struct score{
	string stuName;
	int subject; //number of courses that student learn
	int final[20][2];//contain courses's ID;
						//contain final point
	score *paper;
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

void viewTeacherPro(staff *&pHead_t,string uses)
{
	staff *pT2=pHead_t;
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
	cout<<"Real name: "<<pT2->name<<endl;
	cout<<"Major: "<<pT2->majors;
	cout<<"Age: "<<pT2->age<<endl;
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
		OutputStaff(pHead_t);
	}
	cout<<"Press any to continue: ";
	_getch();
	
}

void inputCourse(courses *&head,int &courseAllow,timeTable &time)
{
		courses *pC=head;
		int ok=1;
	FILE *file = fopen("Courses.CSV", "r");
	char content[1024];

	while(fgets(content, 1024, file))
	{
			char *v = strtok(content, ",");
			while(v and ok==1)
			{
			
					if(ok==1)
			{

			courseAllow=atoi(v);
			ok=0;	
			}
			v = strtok(NULL, ",");
			}
		while(v)
		{			
	
			pC->name=v;
			v = strtok(NULL, ",");
			pC->teacher=v;
			v = strtok(NULL, ",");
			pC->startDate=v;
			v = strtok(NULL, ",");
			pC->endDate=v;
			v = strtok(NULL, ",");
			pC->numberStu=atoi(v);
			v = strtok(NULL, ",");
			for(int a=0;a<pC->numberStu;a++)
			{
				pC->StuID[a]=atoi(v);
				v = strtok(NULL, ",");
			}
			pC->ID=atoi(v);
			v = strtok(NULL, ",");
			pC->credits=atoi(v);
			v = strtok(NULL, ",");
			pC->nums=atoi(v);
			v = strtok(NULL, ",");
			cout<<"ok";
			for(int i=0;i<=1;i++){
			int day=atoi(v);	
			v = strtok(NULL, ",");
			int sess=atoi(v);
			time.week[sess-1][day-2]=pC->ID;
			v = strtok(NULL, ",");
			}
		}
		if(ok==2)
		{
		pC->jump=new courses;
		pC=pC->jump;	
		}
		ok=2;

	}
	pC=head;
	while(pC->jump->jump!=NULL)
	{
		pC=pC->jump;
	}
	courses *pDel=pC->jump;
	pC->jump=NULL;
	delete pDel;
	fclose(file);
}

void viewCourses(courses *&head,student *&pHead_s)
{
	
						courses *pc=head;
						student *ps=pHead_s;
						while(pc!=NULL)
						{
							cout<<"Name: "<<pc->name<<endl;
							cout<<"Course ID: "<<pc->ID<<endl;
							cout<<"Number of credits: "<<pc->credits<<endl;
							cout<<"Taught by: "<<pc->teacher<<endl<<endl;
							cout<<"Number of student: "<<pc->numberStu<<endl;
							for(int z=0;z<pc->numberStu;z++)
							{
								cout<<z+1<<".|";
								ps=pHead_s;
								while(ps!=NULL)
								{
									if(ps->social_ID==pc->StuID[z])
									{
										break;
									}
									ps=ps->pNext;
								}
								cout<<pc->StuID[z]<<" | "<<ps->lastName<<endl;
							}
							pc=pc->jump;
							cout<<"_____________________________"<<endl;
						}
						cout<<"Press any key to back..."<<endl;
						_getch();
}

void outputCourse(courses *&head,int &courseAllow,timeTable &time)
{
	fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("Courses.CSV", ios::out );

  	fout<<courseAllow<<endl;
  	courses *pC=head;
    // Read the input
    while(pC!=NULL) 
	{
		if(pC!=head)fout<<endl;
		
        fout <<pC->name<<","
			<<pC->teacher<<","
			<<pC->startDate<<","
			<<pC->endDate<<","
			<<pC->numberStu<<",";
		for(int a=0;a<pC->numberStu;a++)
		{
			fout<<pC->StuID[a];
			fout<<",";
		}
			fout<<pC->ID<<","
			<<pC->credits<<","
			<<pC->nums;
		for(int x=0;x<7;x++)
		{
			for(int z=0;z<4;z++)
			{
				if(time.week[z][x]==pC->ID)
				{
					fout<<","<<x+2<<","<<z+1;
				}
			}
		}
	pC=pC->jump;
	}
}

void inputScore(score *&sco)
{
	score *pC=sco;
	FILE *file = fopen("FinalMark.CSV", "r");
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v)
		{
			pC->stuName=v;
			v = strtok(NULL, ",");
			pC->subject=atoi(v);
			v = strtok(NULL, ",");
			for(int a=0;a<pC->subject;a++)
			{
				pC->final[a][0]=atoi(v);
				v = strtok(NULL, ",");
				pC->final[a][1]=atoi(v);
				v = strtok(NULL, ",");
			}
		}
		pC->paper=new score;
		pC=pC->paper;
	}
	pC=sco;
	while(pC->paper->paper!=NULL)
	{
		pC=pC->paper;
	}
	score *pDel=pC->paper;
	pC->paper=NULL;
	delete pDel;
	fclose(file);
}


void createCourse(courses *&head,timeTable &time)
{
	courses *pC=head;
	while(pC->jump!=NULL)pC=pC->jump;
	pC->jump=new courses;
	pC=pC->jump;
	cout<<"Course name: ";
	cin>>pC->name;
	cout<<"Course ID: ";
	cin>>pC->ID;
	cout<<"Who will teach ? ";
	cin>>pC->teacher;
	cout<<"Number of lessons: ";
	cin>>pC->nums;
	cout<<"Number of credit: ";
	cin>>pC->credits;
	cout<<"StartDate: ";
	cin>>pC->startDate;
	cout<<"EndDate: ";
	cin>>pC->endDate;
	pC->numberStu=0;
	int day,sess;
			for(int i=0;i<=1;i++){
			cout<<"It will be teach on what day (2->7) ? "	;
			cin>>day;
			cout<<"And on what session (1->4) ? "	;
			cin>>sess;
			time.week[sess-1][day-2]=pC->ID;
			
			}	
}

void createScore(score *&sco,courses *&head)
{
		system("cls");
		int ok=1;
		int first=1,count=0;
	cout<<"This work only for input CSV"<<endl;
	score *pC=sco;
	cout<<"Enter file name: ";
	char fname[1024];
	scanf ("%s", fname);
	FILE *file = fopen(fname, "r");
	int coName;
	int coID;
	score *here;
	char content[1024];
	while(fgets(content, 1024, file))
	{
		char *v = strtok(content, ",");
		while(v and ok==1)
			{
			
			if(ok==1)
				{
	
				coName=atoi(v);
				
				ok=0;	
				}
			courses *co=head;
				while(co!=NULL)
			{
	
				if(co->ID==coName)
				{
					coID=co->ID;break;
				}
				co=co->jump;
			}
			v = strtok(NULL, ",");

			}
		while(v)
		{
			int create=0;
			pC=sco;
			string perName=v;
			
			cout<<perName<<endl;
			getch();
			while(pC!=NULL)
			{
				
				if(pC->stuName.compare(perName)==0)break;
				if(pC->paper==NULL)
				{

					
					
					pC->paper=new score;
					pC=pC->paper;
					pC->paper=NULL;
					
					create=1;
					break;
				}
				
				pC=pC->paper;
			}

			pC->stuName=perName;
			v = strtok(NULL, ",");
			if(create==1)
			pC->subject=0;
			pC->subject+=1;
			pC->final[pC->subject-1][0]=coID;
			pC->final[pC->subject-1][1]=atoi(v);
			v = strtok(NULL, ",");

		}

	}
	pC->paper=NULL;
	fclose(file);
}

void viewScore(score *&sco,courses *&head)
{
	score *pc=sco;
						courses *ps=head;
						while(pc!=NULL)
						{
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
							pc=pc->paper;
							cout<<endl;
						}
						cout<<"Press any key to back..."<<endl;
						_getch();
}

void outputScore(score *&sco)
{
		fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("FinalMark.CSV", ios::out );

  	score *pC=sco;
    // Read the input
    while(pC!=NULL) 
	{
		if(pC!=sco)fout<<endl;
		
        fout <<pC->stuName<<","
			<<pC->subject<<",";
		for(int a=0;a<pC->subject;a++)
		{
			fout<<pC->final[a][0];
			fout<<",";
			fout<<pC->final[a][1];
			if(a<pC->subject-1)fout<<",";
		}

	pC=pC->paper;
	}
}
void viewTime(timeTable &time){
		for(int x=0;x<7;x++) 
		{
			for(int z=0;z<4;z++)
			{
				cout<<time.week[z][x]<<" ";
			}
			cout<<endl;
		}
}

void deleteCourse(courses *&head,timeTable time)
{
	courses *pC=head;
	int fou=0;
	string name;
	
	do{
	cout<<"Enter the name of course to delete: ";
	cin>>name;
	if(head->name.compare(name)==0)
	{
		courses *del=head;
		head=head->jump;
		delete del;
		system("cls");
		cout<<"DONE !!!";
		sleep(1);
		system("cls");
		return;
	}
	while(pC->jump!=NULL)
	{
		if(pC->jump->name.compare(name)==0)
		{
			fou=1;
			break;
		}
		pC=pC->jump;
	}
		if(fou==0)
		{
			system("cls");
			cout<<"No such course !"<<endl;
		}
	}while(fou!=1);
	courses *del=pC->jump;
	pC->jump=del->jump;
			for(int x=0;x<7;x++)
		{
			for(int z=0;z<4;z++)
			{
				if(time.week[z][x]==del->ID)
				{
					time.week[z][x]=0;
				}
			}
		}
	delete del;
		system("cls");
		cout<<"DONE !!!";
		sleep(1);
		system("cls");
}

void MenuTeacher(score *&sco,staff *&pHead_t,student *&pHead_s,string *use,classes *&pHead_c,courses *&head,int &courseAllow,timeTable &time)
{
	int choose,choose2;
	string here=*use;

	do{
		cout<<"Press 1: Manage class"<<endl;
		cout<<"Press 2: Manage courses"<<endl;
		cout<<"Press 3: Create school year ? "<<endl;
		cout<<"Press 4: Manage student's score"<<endl;
		cout<<"Press 5: View profile "<<endl;
		cout<<"Press 6: Exit"<<endl;
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
			case 2:{
				int choose3;
				do{
				system("cls");
				cout<<"Press 1: Create courses"<<endl;
				cout<<"Press 2: View course"<<endl;
				cout<<"Press 3: Course Registration "<<endl;
				cout<<"Press 4: View timetable"<<endl;
				cout<<"Press 5: Delete course"<<endl;
				cout<<"Press 6: Exit"<<endl;
				cout<<"I choose: ";
				cin>>choose3;
				switch(choose3)
				{
					case 1:{
						system("cls");
						createCourse(head,time);
						system("cls");
						cout<<"DONE !!!";
						sleep(1);
						outputCourse(head,courseAllow,time);
						system("cls");
						break;
					}
						
					case 2:{
						system("cls");
						viewCourses(head,pHead_s);
						system("cls");
						break;
					}
					
					case 3:{
						system("cls");
						char allow;
						cout<<"Do you want to allow student to sign up courses ? (y/n) " ;
						cin>>allow;
						if(allow=='y'||allow=='Y')courseAllow=1;
						if(allow=='n'||allow=='N')courseAllow=0;
						outputCourse(head,courseAllow,time);
						system("cls");
						cout<<"OK...";
						sleep(1);
						system("cls");
						break;
					}
					case 4:			
					{
				system("cls");
				viewTime(time);
				getch();
				system("cls");
				break;
					}

				
				case 5:
					{
						system("cls");
						deleteCourse(head,time);
						outputCourse(head,courseAllow,time);
						break;
					}
				}
				}while(choose3!=6);
				system("cls");
				break;
			}
			
			case 3:{
				creatSchoolYear();
				system("cls");
				break;
			}
			case 4:{
				system("cls");
				int pick;
				do{
				cout<<"Press 1: Input score"<<endl;
				cout<<"Press 2: View score"<<endl;
				cout<<"Press 3: Exit"<<endl;
				cout<<"I choose ";
				cin>>pick;
				switch(pick)
				{
					case 1:{
						system("cls");
						createScore(sco,head);
						outputScore(sco);
						system("cls");
						cout<<"DONE !!!";
						sleep(1);
						system("cls");
						break;
					}
					case 2:{
						viewScore(sco,head);
						outputScore(sco);
						system("cls");
						break;
					}
				}			
				}while(pick!=3);system("cls");break;
					}
			
			case 5:
			{
			viewTeacherPro(pHead_t,here);
			system("cls");
			break;	
			}
			

				
		}
	
		
	}while(choose!=6);
}

