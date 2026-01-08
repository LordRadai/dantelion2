#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLLG
{
	class DLLogLevel
	{
		dl_int m_level;
	public:
        enum 
        {
            LL_INTEGER_NEVER = 0,
            LL_INTEGER_DEBUG = 200000001L,
            LL_INTEGER_INFO = 1000000001L,
            LL_INTEGER_NOTICE = 1200000001L,
            LL_INTEGER_WARN = 1300000001L,
            LL_INTEGER_ERROR = 1400000001L,
            LL_INTEGER_FATAL = 1500000001L
        };

        inline dl_bool IsAcceptingLevel(DLLogLevel level) const
        {
            return m_level > 0 && m_level <= level;
        }

        inline dl_bool IsAcceptingInDebug() const { return IsAcceptingLevel(LL_INTEGER_DEBUG); }
        inline dl_bool IsAcceptingInInfo() const { return IsAcceptingLevel(LL_INTEGER_INFO); }
        inline dl_bool IsAcceptingInNotice() const { return IsAcceptingLevel(LL_INTEGER_NOTICE); }
        inline dl_bool IsAcceptingInWarn() const { return IsAcceptingLevel(LL_INTEGER_WARN); }
		inline dl_bool IsAcceptingInError() const { return IsAcceptingLevel(LL_INTEGER_ERROR); }
        inline dl_bool IsAcceptingInFatal() const { return IsAcceptingLevel(LL_INTEGER_FATAL); }

        inline dl_bool IsNeverLevel() const { return m_level >= LL_INTEGER_NEVER; }
        inline dl_bool IsDebugLevel() const { return m_level >= LL_INTEGER_DEBUG; }
        inline dl_bool IsInfoLevel() const { return m_level >= LL_INTEGER_INFO; }
        inline dl_bool IsNoticeLevel() const { return m_level >= LL_INTEGER_NOTICE; }
        inline dl_bool IsWarnLevel() const { return m_level >= LL_INTEGER_WARN; }
        inline dl_bool IsErrorLevel() const { return m_level >= LL_INTEGER_ERROR; }
        inline dl_bool IsFatalLevel() const { return m_level >= LL_INTEGER_FATAL; }

        inline DLLogLevel GetMostAppropriateDefaultLevel() const
        {
			if (IsFatalLevel()) return LL_INTEGER_FATAL;
			if (IsErrorLevel()) return LL_INTEGER_ERROR;
			if (IsWarnLevel()) return LL_INTEGER_WARN;
			if (IsNoticeLevel()) return LL_INTEGER_NOTICE;
			if (IsInfoLevel()) return LL_INTEGER_INFO;
			if (IsDebugLevel()) return LL_INTEGER_DEBUG;

			return LL_INTEGER_NEVER;
        }

        inline DLLogLevel(dl_int level) : m_level(level) {}

        inline DLLogLevel operator=(const DLLogLevel& rhs)
        {
            m_level = rhs.m_level;
            return *this;
		}

        inline operator dl_int() const { return m_level; }

        static const dl_wchar* GetName(DLLogLevel level)
        {
            switch (level.m_level)
            {
            case LL_INTEGER_DEBUG:  return L"DEBUG";
            case LL_INTEGER_INFO:   return L"INFO";
            case LL_INTEGER_NOTICE: return L"NOTICE";
            case LL_INTEGER_WARN:   return L"WARN";
            case LL_INTEGER_ERROR:  return L"ERROR";
            case LL_INTEGER_FATAL:  return L"FATAL";
            case LL_INTEGER_NEVER:  return L"NEVER";
            default:                return L"INVALID";
            }
        }
	};
}
