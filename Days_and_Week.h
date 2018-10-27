#ifndef Days_h
#define Days_h

#include "stdafx.h"
#include <string>
#include <limits>
#include <iostream>

using namespace std;

const char _SUMMARY_HEADER_[] = "%-8s %14s %-8s \n";
//const char _SUMMARY_SUM_[] = "%-21s %*u%-.4f \n";//sets back to zero??
//const char _SUMMARY_MIN_MAX_[] = "%-21s %*.4f \n";
//const char _SUMMARY_COUNT_[] = "%-20s %*u%-*u \n";
//const char _SUMMARY_CHANGE_[] = "%-22s %*.4f \n";
const char _USER_INPUT_[] = "%-6s '%1c' %-22s \n";
const char _USER_READINGS_[] = "%-6s '%1c' %25s %1i \n";


class Days
{
public:
	unsigned int returnTotalCount() { return totalCount; }//returns the sum
	float returnSum() { return totalDay; }//returns the total number of inputs
	float returnMax() { return maxDay; }//returns max
	float returnMin() { return minDay; }//returns min
	void lookForMax(float input);//determine if input is the max
	void lookForMin(float input);//determine if input is the min
	void additionInput(float input);//does all the perations with each input
	void summaryDaily();
private:
	unsigned int totalCount = 0, totalCountOverflow = 0, totalDayOverflow = 0, printFloatOverFlow = 0;//total count is the number of input and overflow is to help control overflow
	float totalDay = 0, maxDay = 0, minDay = 5000, temp;//sum of everything as well as the max and min of the day
};

class Week {
public:
	void sumaryWeekly(short startDay, Days week[]);
	float returnMin() { return minWeek; }
	float returnMax() { return maxWeek; }
	float returnSum() { return printWeek; }
private:
	short startDay = 0;
	unsigned int totalCountWeek = 0, printWeekOverflow = 0, totalCountWeekOverflow = 0, intTemp;
	float maxWeek = 0, minWeek = 0, printWeek = 0, temp, biggestChange = 0;
};

#endif // !Days.h