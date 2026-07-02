#pragma once
#include "DLAssertEventListener.h"
#include "DLAssertEventSocket.h"

namespace DLSY
{
	class DLWin32DialogAssertHandler : public DLAssertEventListener, public DLAssertInputEventSocket
	{
		dl_uint m_InputEvent;
	public:
		virtual void HandleAssertEvent(const DLPF::DLAssertEvent& event) override;
		virtual void Startup() override {}
		virtual void Takedown() override {}
		virtual dl_uint CheckInputEvent() override { return m_InputEvent; }
		virtual ~DLWin32DialogAssertHandler() {}

		void SetInputEvent(dl_uint inputEvent) { m_InputEvent = inputEvent; }
	};
}