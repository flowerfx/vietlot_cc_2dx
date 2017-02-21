
#include "cocos2d.h"
#include "Utils.h"
#include "time.h"
#include <iostream>
#include <clocale>
#include <cctype>
#include "RKString_Code/RKString.h"
namespace Utils
{

	//convert date time
	void convertToDate(const std::string & date, u32 & day, u32 & month, u32 & year)
	{
		RKUtils::RKString str = date;
		RKUtils::RKList<RKUtils::RKString> list_date;
		if (str.Contains("/"))
		{
			list_date = str.Split("/");
		}
		else if (str.Contains("\\"))
		{
			list_date = str.Split("\\");
		}
		else if (str.Contains("_"))
		{
			list_date = str.Split("_");
		}

		if (list_date.Size() == 3)
		{
			day = atoi(list_date[0].GetString());
			month = atoi(list_date[1].GetString());
			year = atoi(list_date[2].GetString());
		}

	}

	std::string convertToDate1(s64 date)
	{
		date /= 1000;
		time_t t = date;
		struct tm *  tstruct;
		tstruct = localtime(&t);
		char buf[80];
		strftime(buf, sizeof(buf), "%Y/%m/%d - %X", tstruct);
		return std::string(buf);
	}

	s64 getTime64(const u32 & day, const u32 & month, const u32 & year)
	{
		time_t rawtime;
		struct tm * timeinfo;
		/* get current timeinfo and modify it to the user's choice */

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		timeinfo->tm_year = year - 1900;
		timeinfo->tm_mon = month - 1;
		timeinfo->tm_mday = day;

		/* call mktime: timeinfo->tm_wday will be set */
		mktime(timeinfo);

		return (s64)rawtime;
	}

	u32 getDayWeek(const u32 & day, const u32 & month, const u32 & year)
	{
		return 1;
	}

	//
	std::vector<u32> convertToListNumber(const std::string & number)
	{
		RKUtils::RKString str = number;
		auto list_date = str.Split("_");

		std::vector<u32> val;
		for (int i = 0; i < list_date.Size(); i++)
		{
			val.push_back(atoi(list_date.GetAt(i).GetString()));
		}

		return val;
	}

	u32 getMaxDayInMonth(const u32 & m, const u32 & y)
	{
		switch (m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
		{
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
		default:
			break;
		}
	}

	bool checkValidTime(u32 & day, u32 & month, u32 & year)
	{
		bool have_valid = true;
		if (year < 1900)
		{
			year = 1900;
			have_valid = false;
		}
		if (month < 1)
		{
			month = 1;
			have_valid = false;
		}
		else if (month > 12)
		{
			month = 12;
			have_valid = false;
		}

		auto max_day = getMaxDayInMonth(month, year);

		if (day < 1)
		{
			day = 1;
			have_valid = false;
		}
		else if (day > max_day)
		{
			day = max_day;
			have_valid = false;
		}

		return have_valid;
	}
}
