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
#include "login.h"
#include "Menu.h"
#include "Student.h"


using namespace std;






void addStudentToClass(classes *&pHead_c,student *&pHead_s);
bool checkFileWithFstream(string path);
void createClass(classes *&pHead_c);
void creatSchoolYear();
void editClasses(classes *&pHead_c,student *&pHead_s);
void inputClasses(classes *&pHead_c);
void inputTeacherProfile(staff *&pHead_t);
void inputUserProfile(student *&pHead_s) ;
void logIn(student *&pHead_s,staff *&pHead_t,string *use,int *role,int &log);
void MenuTeacher(staff *&pHead_t,student *&pHead_s,string *use,classes *&pHead_c,courses *&head,int &courseAllow);
void outputClass(classes *&pHead_c);
void OutputStaff(staff *&pHead_t);
void OutputUser(student *&pHead_s);
void removeStudentFromClass(classes *&pHead_c,student *&pHead_s);
void viewClass(classes *&pHead_c,student *&pHead_s);
void viewYourclass(classes *&pHead_c,student *&pHead_s,string use);
void MenuTeacher(score *&sco,staff *&pHead_t,student *&pHead_s,string *use,classes *&pHead_c,courses *&head,int &courseAllow);
void viewStudentPro(student *&pHead_s,string uses);
void inputCourse(courses *&head,int &courseAllow);
void createCourse(courses *&head);
void viewCourses(courses *&head,student *&pHead_s);
void courseRegistration(courses *&head,string here,student *&pHead_s);
void createScore(score *&sco,courses *&head);


int main()//this is just a test
{
	student *pHead_s=new student;
	student *pS=pHead_s;
	staff *pHead_t=new staff;
	staff *pT=pHead_t;
	score *sco=new score;
	inputUserProfile(pHead_s);
	inputTeacherProfile(pHead_t);
	classes *pHead_c = new classes;
	courses *head = new courses;
	inputClasses(pHead_c);
	int courseAllow=-1;
	inputCourse(head,courseAllow);
	int roles=-1,log=1;
	string use;//to know who is login
	
	do{
	system("cls");
	logIn(pHead_s,pHead_t,&use,&roles,log);
	if(log==0)break;
	if (roles==1)
	{
		MenuTeacher(sco,pHead_t,pHead_s,&use,pHead_c,head,courseAllow);
	}	
	if(roles==0)
	{
		menuStudent(pHead_c,pHead_s,&use,courseAllow,head);
		outputCourse(head,courseAllow);
	}
	}while(log==1);
//delete []pHead_s;
//delete []pHead_t;
//delete[]head;
	return 0;
}

