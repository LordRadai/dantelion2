#pragma once

namespace DLUT
{
	class DLNonCopyable
	{
	public:
		virtual ~DLNonCopyable() {}

		typedef void(_fastcall* Destructor_t)(DLNonCopyable*);
	};
}