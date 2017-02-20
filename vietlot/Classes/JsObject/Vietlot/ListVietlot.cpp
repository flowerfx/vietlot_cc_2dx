#include "ListVietLot.h"
#include "DetailVietlot.h"
namespace jsmessage
{
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
}
