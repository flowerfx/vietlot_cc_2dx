#include "ListVietLot.h"
#include "DetailVietlot.h"
namespace jsmessage
{
	//#define _CRT_NO_VA_START_VALIDATION 
	ListVietLot::ListVietLot() {
		details.clear();
	}

	ListVietLot::~ListVietLot() {
		SAFE_DELETE_VECTOR(details)
	}

	rapidjson::Document ListVietLot::toJson()
	{
		rapidjson::Document document;
		document.SetObject();
		rapidjson::Document::AllocatorType& locator = document.GetAllocator();

		rapidjson::Value arrList(rapidjson::kArrayType);
		for (size_t i = 0; i < details.size(); i++)
		{
			arrList.PushBack(details[i]->toJson(), locator);
		}
		document.AddMember("details", arrList, locator);

		finishToJson(document);
		return document;
	}

	void ListVietLot::toData(rapidjson::Document & document)
	{
		if (document.HasMember("details") && !document["details"].IsNull() && document["details"].IsArray())
		{
			const rapidjson::Value& arrlist = document["details"];
			for (rapidjson::SizeType i = 0; i < arrlist.Size(); i++)
			{
				const rapidjson::Value& c = arrlist[i];
				rapidjson::StringBuffer buffer;
				buffer.Clear();
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				c.Accept(writer);
				const char* json = buffer.GetString();

				DetailVietlot * d = new DetailVietlot();
				d->toDataStr(json);
				details.push_back(d);
			}
		}
	}

	std::vector<DetailVietlot*> ListVietLot::getListItemInTime(
		const u32 & day_from, const u32 & month_from, const u32 & year_from,
		const u32 & day_to, const u32 & month_to, const u32 & year_to, std::vector<DetailVietlot*> ref)
	{
		std::vector<DetailVietlot*> list_res;
		auto time_from = Utils::getTime64(day_from, month_from, year_from);
		auto time_to = Utils::getTime64(day_to, month_to, year_to);

		for (auto d : ref)
		{
			if (d->getTime() >= time_from && d->getTime() <= time_to)
			{
				list_res.push_back(d);
			}
		}
		return list_res;
	}

	std::vector<DetailVietlot*> ListVietLot::getListItemInMonth(const u32 & month_from, const u32 & year_from,
		const u32 & month_to, const u32 & year_to, std::vector<DetailVietlot*> ref)
	{
		return getListItemInTime(1, month_from, year_from, Utils::getMaxDayInMonth(month_to, year_to), month_to, year_to , ref);
	}

	std::vector<DetailVietlot*> ListVietLot::getListItemInYear(const u32 & year_from, const u32 & year_to , std::vector<DetailVietlot*> ref)
	{
		return getListItemInTime(1, 1, year_from, 31, 12, year_to, ref);
	}

	std::vector<DetailVietlot*> ListVietLot::getListItemArgNumber(std::vector<DetailVietlot*> ref, u32 & number, va_list args)
	{
		std::vector<u32> list_num;
		u32 num = number;
		u32 * to_number = &num;

		
		while (to_number != 0)
		{
			list_num.push_back(num);
			num = va_arg(args, u32);
		}

		u32 * ptr_num = new u32[list_num.size()];
		for (int i = 0; i < list_num.size(); i++)
		{
			ptr_num[i] = list_num[i];
		}


		std::vector<DetailVietlot*> ret;
		for (auto d : ref)
		{
			if (d->containNumber(ptr_num, list_num.size()))
			{
				ret.push_back(d);
			}
		}

		SAFE_DELETE_ARRAY(ptr_num);
		return ret;
	}

	std::vector<DetailVietlot*> ListVietLot::getListItemHaveNumber( std::vector<DetailVietlot*> ref, u32 & number, ...)
	{
		va_list args;
		va_start(args, number);

		auto list = getListItemArgNumber(ref, number, args);

		va_end(args);

		return list;
	}

	float ListVietLot::getThePercentAppear(std::vector<DetailVietlot*> ref, u32 & number, ...)
	{
		va_list args;
		va_start(args, number);

		auto list = getListItemArgNumber(ref, number, args);

		va_end(args);

		float size_of_list = list.size();
		float size_of_ref = ref.size();

		return ((float)size_of_list / (float)size_of_ref) * 100.f;
	}

	std::map<std::vector<u32>, float> ListVietLot::getListPercentAppear(std::vector<DetailVietlot*> ref, const u32 & number)
	{
		std::map<std::vector<u32>, float> list;

		if (number >= 1 && number <= 3)
		{
			if (number == 1)
			{
				u32 begin_number = MIN_NUM;
				while (begin_number <= MAX_NUM)
				{
					std::vector<u32> ch;
					ch.push_back(begin_number);
					auto percent = getThePercentAppear(ref, begin_number, 0);
					list.insert({ ch ,percent });
					begin_number++;
				}
			}
			else if (number == 2)
			{
				for (u32 i = MIN_NUM; i <= MAX_NUM - 1; i++)
				{
					for (u32 j = i + 1; j <= MAX_NUM; j++)
					{
						std::vector<u32> ch;
						ch.push_back(i);
						ch.push_back(j);
						auto percent = getThePercentAppear(ref, i,j, 0);
						list.insert({ ch ,percent });
					}
				}
			}
			else if (number == 3)
			{
				for (u32 i = MIN_NUM; i <= MAX_NUM - 2; i++)
				{
					for (u32 j = i + 1; j <= MAX_NUM - 1; j++)
					{
						for (u32 k = j + 1; i <= MAX_NUM ; k++)
						{
							std::vector<u32> ch;
							ch.push_back(i);
							ch.push_back(j);
							ch.push_back(k);
							auto percent = getThePercentAppear(ref, i, j , k, 0);
							list.insert({ ch ,percent });
						}
					}
				}
			}
		}

		return list;
	}
}
