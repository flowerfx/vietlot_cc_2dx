#include "DetailVietlot.h"
#include "RKString_Code/RKString.h"
namespace jsmessage
{
	
	DetailVietlot::DetailVietlot() :
		id(0),
		date(""),
		day(1),
		month(1),
		year(2000),
		time(0),
		number(""),
		result0(0),
		result1(0),
		result2(0),
		result3(0)
	{
		listNumber.clear();
	}

	DetailVietlot::~DetailVietlot()
	{
		listNumber.clear();
	}

	rapidjson::Document DetailVietlot::toJson()
	{

		rapidjson::Document document;
		document.SetObject();
		rapidjson::Document::AllocatorType& locator = document.GetAllocator();
		
		document.AddMember("id", id, locator);

		rapidjson::Value vdate(date.c_str(), date.size());
		document.AddMember("date", vdate,locator);
		Utils::convertToDate(date, day, month, year);

		rapidjson::Value vnumber(number.c_str(), number.size());
		document.AddMember("number", vnumber, locator);

		listNumber = Utils::convertToListNumber(number);

		document.AddMember("result0", result0,locator);
		document.AddMember("result1", result1,locator);
		document.AddMember("result2", result2,locator);
		document.AddMember("result3", result3, locator);

		finishToJson(document);
		return document;
	}

	void DetailVietlot::toData(rapidjson::Document & document)
	{
		if(document.HasMember("id"))
		{
			setID(document["id"].GetUint());
		}

		if(document.HasMember("date"))
		{
			setDate(document["date"].GetString());
		}

		if(document.HasMember("number"))
		{
			setNumber(document["number"].GetString());
		}

		if(document.HasMember("result0"))
		{
			setResult0(document["result0"].GetUint());
		}
		if (document.HasMember("result1"))
		{
			setResult1(document["result1"].GetUint());
		}
		if (document.HasMember("result2"))
		{
			setResult2(document["result2"].GetUint());
		}
		if (document.HasMember("result3"))
		{
			setResult3(document["result3"].GetUint());
		}
		time = Utils::getTime64(day, month, year);
		RKUtils::RKString str = number;
		auto list_number = str.Split("_");
		for (int i = 0; i < list_number.Size(); i++)
		{
			listNumber.push_back((u32)atoi(list_number.GetAt(i).GetString()));
		}
	}

	bool DetailVietlot::containNumber(const u32 * nums, const u32 & count)
	{
		bool contain = true;
		for (int i = 0; i < count; i++)
		{
			bool have_number = false;
			for (auto n : listNumber)
			{
				if (n == nums[i])
				{
					have_number = true;
					break;
				}
			}
			contain &= have_number;
		}
		return contain;
	}
}
