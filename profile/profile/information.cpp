#include "InformationStudent.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

struct Record {
	string id;
	// Scores for each subject
	float fifteenMinuteMathScore;
	float oneHourMathScore;
	float averageMathScore;
	float fifteenMinutePhysicsScore;
	float oneHourPhysicsScore;
	float averagePhysicsScore;
	float fifteenMinuteChemistryScore;
	float oneHourChemistryScore;
	float averageChemistryScore;

	void display() {
		cout << "Enter ID: " << id << endl;
		cout << "The mark of 15m: " << fifteenMinuteMathScore << endl;
		cout << "The mark of last semester: " << oneHourMathScore << endl;
		cout << "The average: " << averageMathScore << endl;

		cout << "The mark of 15m: " << fifteenMinutePhysicsScore << endl;
		cout << "The mark of last semester: " << oneHourPhysicsScore << endl;
		cout << "The average: " << averagePhysicsScore << endl;


		cout << "The mark of 15m: " << fifteenMinuteChemistryScore << endl;
		cout << "The mark of last semester: " << oneHourChemistryScore << endl;
		cout << "The average: " << averageChemistryScore << endl;

	}


	friend ostream& operator<<(ostream& os, const Record& record) {
		os << "ID: " << record.id << endl;
		os << "The mark 15m: " << record.fifteenMinuteMathScore << endl;
		os << "The mark of last semester: " << record.oneHourMathScore << endl;
		os << "The average: " << record.averageMathScore << endl;

		os << "The mark 15m: " << record.fifteenMinutePhysicsScore << endl;
		os << "The mark of last semester: " << record.oneHourPhysicsScore << endl;
		os << "The average: " << record.averagePhysicsScore << endl;

		os << "The mark 15m: " << record.fifteenMinuteChemistryScore << endl;
		os << "The mark of last semester: " << record.oneHourChemistryScore << endl;
		os << "The average: " << record.averageChemistryScore << endl;

		return os;
	}
};
vector <Record> records;
void InformationStudent::InsertInformation(string path) {
	fstream inFile(path, ios::app);
	if (inFile.is_open()) {
		cout << "Let's write about information!" << endl;

		inFile << '\n' << "-------------------------------------INFORMATION-------------------------------------" << endl;
		//Write Information of student

		cout << "Full name: ";
		string Nm;
		cin.ignore();
		getline(cin, Nm);
		inFile << "Full name: " << Nm;

		cout << "Class: ";
		string Cl;
		getline(cin, Cl);
		inFile << '\n' << "Class: " << Cl;

		cout << "Department: ";
		string Dp;
		getline(cin, Dp);
		inFile << '\n' << "Department: " << Dp;

		cout << "Id student: ";
		string Id;
		getline(cin, Id);
		inFile << '\n' << "Id student: " << Id;


		inFile << '\n' << "-------------------------------------MARK BOARD-------------------------------------" << endl;
		//Write mark of each subject
		float mark15m, marklm, AvgS;

		//Math
		cout << "Math: " << endl;
		inFile << '\n' << "Math: ";
		float AverageMath = AverageSubject(path, mark15m, marklm, AvgS);

		//Physics
		cout << "Physics: " << endl;
		inFile << '\n' << "Physics: ";
		float AveragePhysics = AverageSubject(path, mark15m, marklm, AvgS);


		//Chemistry
		cout << "Chemistry: " << endl;
		inFile << '\n' << "Chemistry: ";
		float AverageChemistry = AverageSubject(path, mark15m, marklm, AvgS);


		//The average of 3 subjects

		float Avg = (AverageMath + AveragePhysics + AverageChemistry) / 3;
		cout << "The average of 3 subjects: " << Avg << endl;
		inFile << '\n' << "The average of 3 subjects:: " << Avg;

		cout << "Finished of write about information!" << endl;
		inFile.close();

	}
}

void InformationStudent::PrintInformation(string path) {
	ifstream readFile(path);
	if (readFile.is_open()) {
		string data;
		while (getline(readFile, data)) {
			cout << data << endl;
		}
		readFile.close();
	}
}

void InformationStudent::CountinueInformation(string path) {
	ifstream inFile(path);
	int n = 1;
	string Choice;
	if (inFile.is_open()) {
		do {

			cout << "Do you want to countinue write to another information?" << endl;
			cout << "Choose 1 (Countinue) or 2 (Stop): ";
			cin >> Choice;
			if (Choice == "1") {
				cout << "Let's write another infomation." << endl;
				InsertInformation(path);
				break;
			}
			else if (Choice == "2") {
				cout << "Finished of add information." << endl;
				n = 0;
				break;
			}
			else {
				cout << "You typed wrong. Try again!" << endl;
			}
		} while (n >= 1);
	}
}

bool InformationStudent::isAllLetters(const string& str) {
	for (char c : str) {
		if (!isalpha(c)) {
			return false;
		}
	}
	return true;
}

float InformationStudent::AverageSubject(string path, float mark15m, float marklm, float AvgS) {
	ofstream inFile(path, ios::app);
	if (inFile.is_open()) {
		int a = 1;
		string s15m;
		float s15mf;
		do {
			cout << "The mark of 15m: ";
			cin >> s15m;
			if (!isAllLetters(s15m)) {
				s15mf = stof(s15m);
				if (s15mf >= 0 && s15mf <= 10) {
					inFile << '\n' << "The mark of 15m: " << s15mf;
					a = 0;
				}
				else {
					cout << "Please enter the mark from 0 to 10!" << endl;
				}
			}
			else {
				cout << "Please enter the number from 0 to 10!" << endl;
			}
		} while (a >= 1);

		int b = 1;
		string slm;
		float slmf;
		do {
			cout << "The mark of last semester: ";
			cin >> slm;
			slmf = stof(slm);
			if (slmf >= 0 && slmf <= 10) {
				inFile << '\n' << "The mark of last semester: " << slmf;
				b = 0;
			}
			else {
				cout << "Please write the mark from 0 to 10!" << endl;
			}
		} while (b >= 1);


		float AvgS = (s15mf * 2 + slmf * 3) / 5;
		cout << "The average: " << AvgS << endl;
		inFile << '\n' << "The average: " << AvgS;
		return AvgS;
	}
}

void InformationStudent::MenuAfterPrintInformation(string path) {
	fstream inFile(path, ios::app);
	if (inFile.is_open()) {
		int n = 1;
		string Choice;
		do {
			cout << "Do you want to write more academic transcript or close to the program?" << endl;
			cout << "1. Write more \n2. Stop.";
			cout << "What do you choose the menu at above?" << endl;
			cin >> Choice;
			if (Choice == "1") {
				InsertInformation(path);
				break;
			}
			else if (Choice == "2") {
				cout << "Ended the program" << endl;
				n = 0;
				break;
			}
			else {
				cout << "You typed wrong. Try again!" << endl;
			}
		} while (n >= 1);
	}
}



bool InformationStudent::logIn(string fileName) {

	string usernameTmp, passwordTmp;
	fstream acc(fileName);
	cout << "Enter username: "; getline(cin, usernameTmp);
	cout << "Enter your password: "; getline(cin, passwordTmp);
	string fileData;
	while (getline(acc, fileData)) {
		size_t pos = 0;
		pos = fileData.find(",");
		string storeUser = fileData.substr(0, pos);

		fileData.erase(0, pos + 1);
		pos = fileData.find(",");
		string storePassword = fileData.substr(0, pos);




		if (usernameTmp == storeUser && passwordTmp == storePassword) {
			cout << "Login successful. Hello " << usernameTmp << "!" << endl;
			return true;
			break;
		}
	}
	acc.close();
	return false;
}
void InformationStudent::signUp(string fileName) {
	string username, password, rePassword;
	fstream acc(fileName, ios::app);
	cout << "Enter username: "; getline(cin, username);
	cout << "Enter your password: "; getline(cin, password);
	cout << "Re-enter password: "; getline(cin, rePassword);
	if (acc.is_open()) {
		if (password == rePassword) {
			acc << username << "," << password << endl;
		}
		else {
			cout << "Password don't match.";
		}
	}
	acc.close();
}

bool InformationStudent::readFile() {
	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cout << "Can't open file'" << endl;
		return false;
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		Record record;
		getline(ss, record.id, ',');
		ss >> record.fifteenMinuteMathScore;
		ss.ignore();
		ss >> record.oneHourMathScore;
		ss.ignore();
		record.averageMathScore = ((record.fifteenMinuteMathScore * 2) + (record.oneHourMathScore * 3)) / 5;
		ss >> record.fifteenMinutePhysicsScore;
		ss.ignore();
		ss >> record.oneHourPhysicsScore;
		ss.ignore();
		record.averagePhysicsScore = ((record.fifteenMinutePhysicsScore * 2) + (record.oneHourPhysicsScore * 3)) / 5;
		ss >> record.fifteenMinuteChemistryScore;
		ss.ignore();
		ss >> record.oneHourChemistryScore;
		ss.ignore();
		record.averageChemistryScore = ((record.fifteenMinuteChemistryScore * 2) + (record.oneHourChemistryScore * 3)) / 5;


		records.push_back(record);
	}

	inputFile.close();
	return true;
}

bool InformationStudent::editRecord(const string& id, float newFifteenMinuteMathScore, float newOneHourMathScore, float newFifteenMinutePhysicsScore, float newOneHourPhysicsScore, float newFifteenMinuteChemistryScore, float newOneHourChemistryScore) {
	bool found = false;
	for (Record& record : records) {
		if (record.id == id) {
			record.fifteenMinuteMathScore = newFifteenMinuteMathScore;
			record.oneHourMathScore = newOneHourMathScore;
			record.averageMathScore = ((newFifteenMinuteMathScore * 2) + (newOneHourMathScore * 3)) / 5;
			record.fifteenMinutePhysicsScore = newFifteenMinutePhysicsScore;
			record.oneHourPhysicsScore = newOneHourPhysicsScore;
			record.averagePhysicsScore = ((newFifteenMinutePhysicsScore * 2) + (newOneHourPhysicsScore * 3)) / 5;
			record.fifteenMinuteChemistryScore = newFifteenMinuteChemistryScore;
			record.oneHourChemistryScore = newOneHourChemistryScore;
			record.averageChemistryScore = ((newFifteenMinuteChemistryScore * 2) + (newOneHourChemistryScore * 3)) / 5;
		}
	}
	if (!found) {
		cout << "Can't find ID'" << endl;
		return false;
	}
	return true;
}



bool InformationStudent::saveToFile() {
	ofstream outputFile(fileName);
	if (!outputFile.is_open()) {
		cout << "Can't open file'" << endl;
		return false;
	}

	for (const Record& record : records) {
		outputFile << record;
	}

	outputFile.close();
	cout << "Record complete" << endl;
	return true;
}


int InformationStudent::DeleteAccount(const string& fileName, const string& dataDelete) {
	ifstream inFile(fileName);
	if (!inFile) {
		cerr << "File can't open! " << endl;
		return 0;
	}
	vector<string> data;
	string row;
	bool found = false;
	while (getline(inFile, row)) {
		if (row.find(dataDelete) == string::npos) {
			data.push_back(row);
		}
		else {
			found = true;
		}
	}

	inFile.close();
	if (!found) {
		cout << "can't find ID! " << endl;
		return 0;
	}

	ofstream outFile(fileName);
	if (!outFile) {
		cerr << "file can't open for write data!" << endl;
		return 0;
	}
	for (const string& row : data) {
		outFile << row << endl;
	}
	outFile.close();
	cout << "Delete complete!" << endl;
}