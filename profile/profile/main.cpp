#include "InformationStudent.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main() {
	InformationStudent student;
	char LR,ST;
	int qualify = 0;
	int choose;
	int choice;
	cout << "Who is student or teacher(S/T) : "; cin >> ST;
	if (ST == 'T') {
		cout << "do yout want login or register: "; cin >> LR;
		if(LR == 'L'){
			if (student.logIn("profile.txt")) {
				do {
					cout << "1. Insert information" << endl;
					cout << "2. Modify information" << endl;
					cout << "Enter your option: "; cin >> choose;
					switch (choose) {
						case 1:
							int choice;
							cout << "-------------------------------------MENU OF ACADEMIC TRANSCRIPT-------------------------------------";

							cout << "\n 1.INSERT INFORMATION. \n 2.PRINT INFORMATION." << endl;
							cout << "Choice the number of a menu above: ";cin >> choice;
							int c = 1;
							do {
								if (choice == 1) {
									student.InsertInformation("Information3.txt");
									student.CountinueInformation("Information3.txt");
									c = 0;
								}
								else if (choice == 2) {
									student.PrintInformation("Information3.txt");
									student.MenuAfterPrintInformation("Information3.txt");
									c = 0;
								}
								else {
									cout << "You typed wrong. Please choice 1 or 2 in option!" << endl;
								}
							} while (c >= 1);
							break;
						case 2:
							InformationStudent editor(/*file name*/);

							// Read to file 
							if (!editor.readFile()) {
								return 1;
							}

							string searchID;
							float newFifteenMinuteMathScore, newOneHourMathScore;
							float newFifteenMinutePhysicsScore, newOneHourPhysicsScore;
							float newFifteenMinuteChemistryScore, newOneHourChemistryScore;
							cout << "Enter ID: ";
							cin >> searchID;

							// Enter new score
							cout << "The mark 15m: ";
							cin >> newFifteenMinuteMathScore;
							cout << "The mark of last semester: ";
							cin >> newOneHourMathScore;
							cout << "The mark 15m: ";
							cin >> newFifteenMinutePhysicsScore;
							cout << "The mark of last semester: ";
							cin >> newOneHourPhysicsScore;
							cout << "The mark 15m: ";
							cin >> newFifteenMinuteChemistryScore;
							cout << "The mark of last semester: ";
							cin >> newOneHourChemistryScore;

							// Find ID and record 
							if (editor.editRecord(searchID, newFifteenMinuteMathScore, newOneHourMathScore, newFifteenMinutePhysicsScore, newOneHourPhysicsScore, newFifteenMinuteChemistryScore, newOneHourChemistryScore)) {
								// Save file
								if (!editor.saveToFile()) {
									return 1;
								}
							}
					}
				} while (qualify != 0);
		}
	}
}