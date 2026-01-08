#include "DLAppender.h"
#include "Call.h"
#include "DLLogEvent.h"

namespace DLLG
{
	DLAppender::DLAppender()
	{
		CALL(DLAppenderConstructor, 0x8f01e0, this);
	}

	DLRF::DLRuntimeClassImpl<DLAppender>* DLAppender::GetRuntimeClass()
	{
		return CALL(DLAppenderGetRuntimeClass, 0x8f01c0, this);
	}

	dl_bool DLAppender::vfunction1()
	{
		return CALL(DLAppenderVFunc1, 0x8f02f0, this);
	}

	dl_bool DLAppender::vfunction2()
	{
		return CALL(DLAppenderVFunc2, 0x8f0300, this);
	}

	void DLAppender::Append(const DLLogEvent& e)
	{
	}

	DLLayout* DLAppender::GetLayout()
	{
		return CALL(DLAppenderGetLayout, 0x8f0310, this);
	}

	const DLTX::DLString& DLAppender::GetName()
	{
		return CALL(DLAppenderGetName, 0x8f0320, this);
	}

	void DLAppender::SetLayout(const dl_wchar* pLayoutName)
	{
		CALL(DLAppenderSetLayoutByName, 0x8f0340, this, pLayoutName);
	}

	void DLAppender::SetLayout(DLLayout* pLayout)
	{
		CALL(DLAppenderSetLayout, 0x8f0330, this, pLayout);
	}

	void DLAppender::SetName(const dl_wchar* name)
	{
		CALL(DLAppenderSetName, 0x8f0390, this, name);
	}

	DLAppender::~DLAppender()
	{
		CALL(DLAppenderDestructor, 0x8aea30, this);
	}
}