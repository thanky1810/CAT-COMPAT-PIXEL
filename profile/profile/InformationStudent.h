#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
class InformationStudent {
private:
	string NameStudent;
	string IdStudent;
	string Class;
	string Department;
	float Math;
	float Physics;
	float Chemistry;
	float Average;
	string UserName, Password;
	string fileName;
public:
	//InformationStudent();
	void InsertInformation(string path);
	void PrintInformation(string path);
	void CountinueInformation(string path);
	void MenuAfterPrintInformation(string path);
	bool isAllLetters(const string& str);
	float AverageSubject(string path, float mark15m, float marklm, float AvgS);
	bool logIn(string fileName);
	void signUp(string fileName);
//	InformationStudent(const string& filename) : fileName(filename) {}
	bool readFile();
	bool editRecord(const string& id, float newFifteenMinuteMathScore, float newOneHourMathScore, float newFifteenMinutePhysicsScore, float newOneHourPhysicsScore, float newFifteenMinuteChemistryScore, float newOneHourChemistryScore);
	bool saveToFile();
	int DeleteAccount(const string& fileName, const string& dataDelete);
};