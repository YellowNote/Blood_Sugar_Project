#include "stdafx.h"
#include "Days_and_Week.h"

using namespace std;

//Checks to see if the input is the Max
void Days::lookForMax(float input) {
	if (input > returnMax()) {
		maxDay = input;
	}
}
//Checks to see if input is the Min
void Days::lookForMin(float input) {
	if (input < returnMin()) {
		minDay = input;
	}
}
//Adds the next user input
void Days::additionInput(float input) {
	if (input > 0) {
		//Checks for overflow for the sum and the count
		if (totalDay + input == numeric_limits<float>::max() || totalDay + input >  numeric_limits<float>::max()) {
			temp = numeric_limits<float>::max() - totalDay;
			totalDayOverflow++;
			totalDay = input - temp;
		}
		else {
			totalDay += input;
		}
		if (totalCount == numeric_limits<unsigned int>::max()) {
			totalCount = 0;
			totalCountOverflow++;
		}
		else {
			totalCount++;
		}
		Days::lookForMax(input);
		Days::lookForMin(input);
	}
}//work on overflow
//Prints the summary of the current day
void Days::summaryDaily() {
	printf(_SUMMARY_HEADER_,"-------","Daily Summary", "-------");
	//printf(_SUMMARY_SUM_, "Sum of all readings:", totalDayOverflow, totalDay);//displays zero??
	cout << "Sum of all readings: " << totalDayOverflow << totalDay << endl;
	//printf(_SUMMARY_MIN_MAX_, "Max of all readings:", maxDay);
	cout << "Max of all readings: " << maxDay <<endl;
	//printf(_SUMMARY_MIN_MAX_, "Min of all readings:", minDay);
	cout << "Min of all readings: " << minDay << endl;
	//printf(_SUMMARY_COUNT_, "Number of readings:", totalCountOverflow, totalCount);
	cout << "Number of readings:  " << totalCountOverflow << totalCount << endl << endl;
}
//Prints the summary of the specified week
void Week::sumaryWeekly(short startDay, Days week[]) {
		for (int i = startDay; i < startDay + 7; i++) {
			//finding the total sum includes check for overflow
			if (printWeek + week[i].returnSum() > numeric_limits<float>::max() || printWeek + week[i].returnSum() == numeric_limits<float>::max()) {
				temp = numeric_limits<float>::max() - printWeek;
				printWeekOverflow++;
				printWeek = week[i].returnSum() - temp;
			}
			else {
				printWeek += week[i].returnSum();
			}

			//finding the max and min of the week
			if (maxWeek < week[i].returnMax()) {
				maxWeek = week[i].returnMax();
			}
			if (minWeek < week[i].returnMin() || i == 0) {
				minWeek = week[i].returnMin();
			}

			//Finds the total count of readings of the entire week also checks for overflow
			if (totalCountWeek + week[i].returnTotalCount() > numeric_limits<float>::max() || totalCountWeek + week[i].returnTotalCount() == numeric_limits<float>::max()) {
				intTemp = numeric_limits<unsigned int>::max() - totalCountWeek;
				totalCountWeekOverflow++;
				totalCountWeek = week[i].returnTotalCount() - intTemp;
			}
			else {
				totalCountWeek += week[i].returnTotalCount();
			}

			if (i > 0) {
				if (week[i].returnSum() - week[i - 1].returnSum() > biggestChange) {
					biggestChange = week[i].returnSum() - week[i - 1].returnSum();
				}
			}

		}

	printf(_SUMMARY_HEADER_, "---------", "Weekly Summary", "---------");
	//printf(_SUMMARY_SUM_, "Sum of all readings:", printWeekOverflow, printWeek);
	cout << "Sum of all readings: " << printWeekOverflow << printWeek << endl;
	//printf(_SUMMARY_MIN_MAX_, "Max of all readings:", maxWeek);
	cout << "Max of all readings: " << maxWeek << endl;
	//printf(_SUMMARY_MIN_MAX_, "Min of all readings:", minWeek);
	cout << "Min of all readings: " << minWeek << endl;
	//printf(_SUMMARY_COUNT_, "Number of readings:", totalCountWeekOverflow, totalCountWeek);
	cout << "Number of readings:  " << totalCountWeekOverflow << totalCountWeek << endl;
	//printf(_SUMMARY_CHANGE_, "Biggest daily change:", biggestChange);
	cout << "Biggest daily change: " << biggestChange << endl << endl;
}
