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
struct schoolYear {
	string YearStart;
	string YearEnd;
	schoolYear* pNext = nullptr;
};

bool checkFileWithFstream(string path) {
	ifstream isf(path);
	return isf.good();
}

void creatSchoolYear()
{	// ch? có giáo viên m?i có th? t?o

		schoolYear schoolY;
		cout << "Input a school year:" << endl;
		cout << "Input start date: ";
		cin >> schoolY.YearStart;
		cout << "Input end date: ";
		cin >> schoolY.YearEnd;
		string SchoolYear = schoolY.YearStart + "-" + schoolY.YearEnd;

		if (checkFileWithFstream(SchoolYear + ".txt") == false) {
			// N?u nam h?c chua du?c t?o, t?o m?t file m?i
			ofstream SchoolYearFile;
			SchoolYearFile.open(SchoolYear + ".txt");
			SchoolYearFile << SchoolYear << endl;
			// g?i hàm t?o
			SchoolYearFile.close();
		}
		else return; // không thì thôi :))
	
}
