#pragma once
#include "Core/Assert/DLAssert.h"

namespace DLSY
{
	class DLAssertEventListener
	{
	public:
		virtual void HandleAssertEvent(const DLPF::DLAssertEvent& event) = 0;
		virtual ~DLAssertEventListener() {}

		typedef void(_fastcall* HandleAssertEvent_t)(DLAssertEventListener*, const DLPF::DLAssertEvent&);
		typedef void(_fastcall* Destructor_t)(DLAssertEventListener*);
	};
}
