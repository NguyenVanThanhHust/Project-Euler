// Wrong answer

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

string week[7] = { "Sunday", "Monday", "Tuesday","Wednesday", "Thursday","Friday","Saturday" };

int main()
{
	
	unsigned int day_in_year[8000];
	day_in_year[0] = 366;
	unsigned long int total_day[8000];
	total_day[0] = day_in_year[0];

	for (int i = 1; i < 8000; i++)
	{
		if (i % 100 == 0)
		{
			if (i % 400 == 0)
			{
				day_in_year[i] = 366;
			}
			else
			{
				day_in_year[i] = 365;
			}
		}
		else
		{
			if (i % 4 == 0)
			{
				day_in_year[i] = 366;
			}
			else
			{
				day_in_year[i] = 365;
			}
		}
		total_day[i] = total_day[i - 1] + day_in_year[i];
	}

	int total_month[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	int total_month_leap[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };	
	
	int numDay;
	cin >> numDay;
	while (numDay != -1)
	{
		if (numDay > 366)
		{
			int year, month, day;
			int isLeap = 0;
			// Check year
			for (int i = 1; i < 8000; i++)
			{
				if (numDay > total_day[i - 1] && numDay <= total_day[i])
				{
					year = i + 2000;
					if (day_in_year[i] == 366)
					{
						isLeap = 1;
					}
					break;
				}
			}

			// Check month
			int remainDay = numDay - total_day[year - 2000 - 1] + 1;
			if (isLeap == 0)
			{
				for (int i = 0; i < 12; i++)
				{
					if (total_month[i] < remainDay && remainDay <= total_month[i + 1])
					{
						month = i + 1;
						day = remainDay - total_month[i];
						break;
					}
				}
			}
			else
			{
				for (int i = 0; i < 12; i++)
				{
					if (total_month_leap[i] < remainDay && remainDay <= total_month_leap[i + 1])
					{
						month = i + 1;
						day = remainDay - total_month_leap[i];
						break;
					}
				}
			}

			int ttk = numDay % 52;
			ttk = ttk % 7;
			cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " << week[ttk] << endl;
		}
		else
		{
			numDay++;
			int month, day;
			for (int i = 0; i < 12; i++)
			{
				if (total_month[i] < numDay && numDay <= total_month[i + 1])
				{
					month = i + 1;
					day = numDay - total_month[i];
					break;
				}
			}
			int	ttk = (numDay - 2) % 7;
			cout << "2000" << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day << " " << week[ttk] << endl;
		}
		cin >> numDay;
	}
	return 0;
}