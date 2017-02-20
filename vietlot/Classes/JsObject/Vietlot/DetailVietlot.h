#ifndef __DETAIL_VIETLOT_H__
#define __DETAIL_VIETLOT_H__
#include "JsObject/JsObject.h"
namespace jsmessage
{
	class DetailVietlot : public JsObject
	{
		//id number 
			CC_SYNTHESIZE_PASS_BY_REF(s32, id, ID)
		//string date
			CC_SYNTHESIZE_PASS_BY_REF(std::string, date, Date)
		//detail date
			CC_SYNTHESIZE_PASS_BY_REF(u32, day, Day)
			CC_SYNTHESIZE_PASS_BY_REF(u32, month, Month)
			CC_SYNTHESIZE_PASS_BY_REF(u32, year, Year)
		//string number
			CC_SYNTHESIZE_PASS_BY_REF(std::string, number, Number)
		//detail number
			CC_SYNTHESIZE_PASS_BY_REF(std::vector<u32>, listNumber, ListNumber)
		//result
			CC_SYNTHESIZE_PASS_BY_REF(u32, result0, Result0) //jackpot
			CC_SYNTHESIZE_PASS_BY_REF(u32, result1, Result1) //nhat
			CC_SYNTHESIZE_PASS_BY_REF(u32, result2, Result2) //nhi
			CC_SYNTHESIZE_PASS_BY_REF(u32, result3, Result3) //ba
	public:
		
		DetailVietlot();
		virtual ~DetailVietlot();
		
		virtual rapidjson::Document toJson() override;
		virtual void toData(rapidjson::Document & json)override;
	};
}
#endif //__DETAIL_VIETLOT_H__
