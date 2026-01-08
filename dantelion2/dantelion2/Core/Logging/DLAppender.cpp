#include "DLAppender.h"
#include "FRPG2Call.h"
#include "DLLogEvent.h"

namespace DLLG
{
	DLAppender::DLAppender()
	{
		FRPG2_CALL(DLAppenderConstructor, 0x8f01e0, this);
	}

	DLRF::DLRuntimeClassImpl<DLAppender>* DLAppender::GetRuntimeClass()
	{
		return FRPG2_CALL(DLAppenderGetRuntimeClass, 0x8f01c0, this);
	}

	dl_bool DLAppender::vfunction1()
	{
		return FRPG2_CALL(DLAppenderVFunc1, 0x8f02f0, this);
	}

	dl_bool DLAppender::vfunction2()
	{
		return FRPG2_CALL(DLAppenderVFunc2, 0x8f0300, this);
	}

	void DLAppender::Append(const DLLogEvent& e)
	{
	}

	DLLayout* DLAppender::GetLayout()
	{
		return FRPG2_CALL(DLAppenderGetLayout, 0x8f0310, this);
	}

	const DLTX::DLString& DLAppender::GetName()
	{
		return FRPG2_CALL(DLAppenderGetName, 0x8f0320, this);
	}

	void DLAppender::SetLayout(const dl_wchar* pLayoutName)
	{
		FRPG2_CALL(DLAppenderSetLayoutByName, 0x8f0340, this, pLayoutName);
	}

	void DLAppender::SetLayout(DLLayout* pLayout)
	{
		FRPG2_CALL(DLAppenderSetLayout, 0x8f0330, this, pLayout);
	}

	void DLAppender::SetName(const dl_wchar* name)
	{
		FRPG2_CALL(DLAppenderSetName, 0x8f0390, this, name);
	}

	DLAppender::~DLAppender()
	{
		FRPG2_CALL(DLAppenderDestructor, 0x8aea30, this);
	}
}