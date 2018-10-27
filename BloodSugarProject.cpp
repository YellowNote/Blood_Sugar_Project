// BloodSugarProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Days_and_Week.h"

using namespace std;

int main()
{
	Days twoWeeks[13];
	bool programRun = true;
	Week bothWeeks[2];
	int dayIndex = 0;
	char userInput;
	float BSreading;

	while (programRun == true) {
		cout << "Do any of the following" << endl;
		printf(_USER_INPUT_, "Enter", 'D', "for daily summary");
		printf(_USER_INPUT_, "Enter", 'W', "for weekly summary");
		printf(_USER_INPUT_, "Enter", 'N', "to go to the next day");
		printf(_USER_READINGS_, "Enter", 'I', "to input reading for day", dayIndex+1);
		printf(_USER_INPUT_, "Enter", 'Q', "to end the program");
		cin >> userInput;

		switch (userInput)
		{
		case 'D': case 'd'://Daily Summary
			twoWeeks[dayIndex].summaryDaily();
			break;
		case 'W': case 'w' ://Weekly Summary
			if (dayIndex > 6) {
				bothWeeks[1].sumaryWeekly(6, twoWeeks);
			}
			else {
				bothWeeks[0].sumaryWeekly(0, twoWeeks);
			}
			break;
		case 'N': case 'n'://To Next Day
			dayIndex++;
			break;
		case 'I': case 'i'://Input data
			cout << "Enter Blood sugar level reading:" << endl;
			cin >> BSreading;
			twoWeeks[dayIndex].additionInput(BSreading);
			break;
		case 'Q': case 'q'://Quit program maybe put in Total Summary
			programRun = false;
			for (int i = 0; i < 14; i++) {
				cout << "Day: " << i + 1 << endl;
				twoWeeks[i].summaryDaily();
				cout << endl;
				if (i == 6) {
					cout << "Week: 1" << endl;
					bothWeeks[0].sumaryWeekly(0, twoWeeks);
					cout << endl;
				}
				else if (i == 13) {
					cout << "Week: 2" << endl;
					bothWeeks[1].sumaryWeekly(6, twoWeeks);
					cout << endl;
				}
			}
			break;
		default://handles anything else
			break;
		}
	}
	
	//system("pause");
    return 0;
}

