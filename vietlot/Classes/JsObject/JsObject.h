#ifndef __JSON_OBJECT_H__
#define __JSON_OBJECT_H__
#include "platform/CCPlatformMacros.h"
#include "json/document.h"
#include "json/writer.h"
#include "Utils.h"
#include <vector>
#include <string>
namespace jsmessage
{
	class JsObject
	{

	protected:
		void finishToJson(rapidjson::Document & json);
	public:

		JsObject();
		virtual ~JsObject();
		virtual rapidjson::Document toJson() = 0;
		virtual void toData(rapidjson::Document & json) = 0;

		virtual void toDataStr(const std::string & json);
	};
}
#endif//__JSON_OBJECT_H__
