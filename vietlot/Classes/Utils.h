#ifndef __UTILS_H__
#define __UTILS_H__

#include "cocos2d.h"
#include <string>
#include <vector>
USING_NS_CC;

typedef unsigned char			ubyte;
typedef unsigned short			u16;
typedef short					s16;
typedef unsigned int			u32;
typedef int						s32;
typedef unsigned long long		u64;
typedef long long			    s64;

#undef SAFE_DELETE  
#define SAFE_DELETE(p)         if(p) { delete (p); (p) = nullptr; }

#undef SAFE_DELETE_ARRAY    
#define SAFE_DELETE_ARRAY(p)   if(p) { delete[] (p); (p) = nullptr; }

#undef SAFE_DELETE_VECTOR
#define SAFE_DELETE_VECTOR(v ) \
for(auto p : v) { \
	delete p ; \
} v.clear(); 

#define SAFE_DELETE_MAP(v ) \
for(auto p : v) { \
	delete p.second ; \
} v.clear(); 

namespace Utils
{
	//convert date time
	void convertToDate(const std::string & date, u32 & day, u32 & month, u32 & year);
	std::string convertToDate1(s64 date);
	u32 getDayWeek(const u32 & day, const u32 & month, const u32 & year);
	//
	std::vector<u32> convertToListNumber(const std::string & number);

};

#endif // __UTILS_H__