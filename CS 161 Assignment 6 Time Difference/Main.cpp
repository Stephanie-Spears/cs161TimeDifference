#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string.h>
#include <time.h>
#include <iomanip>

using namespace std;



int main()
{
	
void getTime(int hours, int minutes);
int diffTime(int startHours, int startMinutes, int endHours, int endMinutes);
void displayTime(int diff);
int startHours, startMinutes, endHours, endMinutes;
int diff;

	cout << "Enter the starting time: " << endl;
	getTime(startHours, startMinutes);
	cout << "The entered starting time is " << startHours << ":" << setw(2) << setfill('0') << startMinutes << endl;

	cout << "Enter the ending time: " << endl;
	getTime(endHours, endMinutes);
	cout << "The entered ending time is " << endHours << ":" << setw(2) << setfill('0') << endMinutes << endl;

	diff = diffTime(startHours, startMinutes, endHours, endMinutes);
	cout << "The difference between these two times is " << diff << " minutes..." << endl;

	displayTime(diff);
	return(0);
}

void getTime(int& hours, int& minutes)
{
	string UserInput;
	string UserInput2;
	int InputLength;
	int i = 0;
	int p = 1;
	char PositionCheck;
	string CleanUserInput;
	stringstream ss;
	int ValidatedInput;
	string CurrentParameter;



	while (p < 3)
	{
		if (p == 1)
		{
			CurrentParameter = "hour";
		}
		else
		{
			CurrentParameter = "minutes";
		}

		cout << "Enter the " + CurrentParameter + ": ";
		getline(cin, UserInput);
		InputLength = (UserInput.length());
		if (InputLength > 0)
		{
			while (i < (InputLength))
			{
				PositionCheck = UserInput.at(i);
				if (isdigit(PositionCheck))
				{
					CleanUserInput = CleanUserInput + PositionCheck;
					++i;
				}
				else
				{
					cout << "Invalid input, use positive integers only." << endl;
					cin.clear();
					UserInput = "";
					i = 0;
					PositionCheck = 0;
					CleanUserInput = "";
					break;
				}
			}
			if (i == InputLength)
			{
				ss << CleanUserInput;
				ss >> ValidatedInput;
				if (p == 1)
				{
					if ((ValidatedInput < 0) || (ValidatedInput > 23))
					{
						cout << "Error: hour must be between 0 and 23. " << endl;
						i = 0;
						cin.clear();
						ss.clear();
						ss.str("");
						UserInput = "";
						CleanUserInput = "";
						InputLength = 0;
						PositionCheck = 0;
						ValidatedInput = 0;
					}
					else
					{
						hours = ValidatedInput;
						i = 0;
						cin.clear();
						ss.clear();
						ss.str("");
						UserInput = "";
						CleanUserInput = "";
						InputLength = 0;
						PositionCheck = 0;
						ValidatedInput = 0;
						++p;
					}
				}
				else
				{
					if ((ValidatedInput < 0) || (ValidatedInput > 59))
					{
						cout << "Error: minutes must be between 0 and 59. " << endl;
						i = 0;
						cin.clear();
						ss.clear();
						ss.str("");
						UserInput = "";
						CleanUserInput = "";
						InputLength = 0;
						PositionCheck = 0;
						ValidatedInput = 0;
					}
					else
					{
						minutes = ValidatedInput;
						i = 0;
						cin.clear();
						ss.clear();
						ss.str("");
						UserInput = "";
						CleanUserInput = "";
						InputLength = 0;
						PositionCheck = 0;
						ValidatedInput = 0;
						++p;
					}
				}
			}
		}
		else
		{
			cout << "Please enter a " + CurrentParameter + " value." << endl;
			i = 0;
			cin.clear();
			ss.clear();
			ss.str("");
			UserInput = "";
			CleanUserInput = "";
			InputLength = 0;
			PositionCheck = 0;
			ValidatedInput = 0;
		}


	}

}

int diffTime(int startHours, int startMinutes, int endHours, int endMinutes)
{
	int ConvertedStart;
	int ConvertedEnd;

	ConvertedStart = (startHours * 60) + startMinutes;
	ConvertedEnd = (endHours * 60) + endMinutes;

	if ((ConvertedEnd - ConvertedStart) < 0)
	{
		return (ConvertedEnd - ConvertedStart) + 1440;
	}
	else
	{
		return (ConvertedEnd - ConvertedStart);
	}

}

void displayTime(int diff)
{


	char buffer[80];
	time_t t = time(0);
	struct tm *timeinfo = gmtime(&t);
	timeinfo->tm_hour = 0;
	timeinfo->tm_min = 0;
	timeinfo->tm_sec = (diff * 60);
	mktime(timeinfo);
	strftime(buffer, 80, "...or %R hours", timeinfo);
	puts(buffer);

}