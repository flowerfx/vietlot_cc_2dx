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


		std::vector<DetailVietlot*> getListItemInTime(const u32 & day_from, const u32 & month_from, const u32 & year_from,
			const u32 & day_to, const u32 & month_to, const u32 & year_to , std::vector<DetailVietlot*> ref);

		std::vector<DetailVietlot*> getListItemInMonth(const u32 & month_from, const u32 & year_from,
			const u32 & month_to, const u32 & year_to, std::vector<DetailVietlot*> ref);

		std::vector<DetailVietlot*> getListItemInYear( const u32 & year_from,const u32 & year_to, std::vector<DetailVietlot*> ref);

		std::vector<DetailVietlot*> getListItemArgNumber(std::vector<DetailVietlot*> ref, u32 & number, va_list args);

		std::vector<DetailVietlot*> getListItemHaveNumber(std::vector<DetailVietlot*> ref , u32 & number ,...);

		//list arg of number
		float getThePercentAppear(std::vector<DetailVietlot*> ref, u32 & number, ...);

		//size number is 1 , 2, or 3
		std::map<std::vector<u32> , float> getListPercentAppear(std::vector<DetailVietlot*> ref, const u32 & size_of_number);


	};
}
#endif //__LIST_VIETLOT_H__