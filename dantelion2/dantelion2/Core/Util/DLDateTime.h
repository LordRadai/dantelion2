#pragma once
#include "Core/Platform/Platform.h"

namespace DLUT
{
    class DLDateTime 
    {
        dl_uint64 m_time64;
        union 
        {
            dl_uint64 m_date;
            struct 
            {
                dl_uint64 m_year : 12;
                dl_uint64 m_millisecond : 10;
                dl_uint64 m_month : 4;
                dl_uint64 m_dayOfWeek : 3;
                dl_uint64 m_day : 5;
                dl_uint64 m_hour : 5;
                dl_uint64 m_minute : 6;
                dl_uint64 m_second : 6;
                dl_uint64 m_isUTC : 1;
            };
        };
    };
}
