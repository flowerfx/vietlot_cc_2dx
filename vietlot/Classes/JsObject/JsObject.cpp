#include "JsObject.h"
#include "json/writer.h"
namespace jsmessage
{

	JsObject::JsObject()
	{

	}

	JsObject::~JsObject()
	{

	}

	void JsObject::finishToJson(rapidjson::Document & document)
	{
		rapidjson::StringBuffer buffer;
		buffer.Clear();
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
	}

	void JsObject::toDataStr(const std::string & json)
	{
		rapidjson::Document document;
		document.Parse(json.c_str());
		toData(document);
	}
}
