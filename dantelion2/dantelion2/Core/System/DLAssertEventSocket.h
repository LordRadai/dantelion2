#pragma once
#include "Core/Assert/DLAssert.h"

namespace DLSY
{
	class DLAssertInputEventSocket
	{
	public:
		virtual void Startup() = 0;
		virtual void Takedown() = 0;
		virtual dl_uint CheckInputEvent() = 0;
		virtual ~DLAssertInputEventSocket() {}

		typedef void(_fastcall* Startup_t)(DLAssertInputEventSocket*);
		typedef void(_fastcall* Takedown_t)(DLAssertInputEventSocket*);
		typedef dl_uint(_fastcall* CheckInputEvent_t)(DLAssertInputEventSocket*);
		typedef void(_fastcall* Destructor_t)(DLAssertInputEventSocket*);
	};
}