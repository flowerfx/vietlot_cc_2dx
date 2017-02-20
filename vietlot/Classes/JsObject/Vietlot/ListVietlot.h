#ifndef __LIST_VIETLOT_H__
#define __LIST_VIETLOT_H__

#include "JsObject/JsObject.h"

namespace jsmessage
{
	class DetailVietlot;
	class ListVietLot : public JsObject
	{
		CC_SYNTHESIZE(std::vector<DetailVietlot*>, details, Details);
	public:
		ListVietLot();
		virtual ~ListVietLot();

		virtual rapidjson::Document toJson() override;
		virtual void toData(rapidjson::Document & json) override;
	};
}
#endif //__LIST_VIETLOT_H__