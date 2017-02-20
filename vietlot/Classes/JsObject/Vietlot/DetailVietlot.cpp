#include "DetailVietlot.h"
namespace jsmessage
{
	
	DetailVietlot::DetailVietlot() :
		id(0),
		date(""),
		day(1),
		month(1),
		year(2000),
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
		document.AddMember("date", date,locator);
		Utils::convertToDate(date, day, month, year);

		rapidjson::Value vnumber(number.c_str(), number.size());
		document.AddMember("number", number, locator);

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
		if(document.HasMember("code"))
		{
			setCode(document["code"].GetString());
		}

		if(document.HasMember("type"))
		{
			setType(document["type"].GetInt());
		}

		if(document.HasMember("purpose"))
		{
			setPurpose(document["purpose"].GetInt());
		}

		if(document.HasMember("trustDevice"))
		{
			setTrustDevice(document["trustDevice"].GetInt());
		}


	}
}
