
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
}
