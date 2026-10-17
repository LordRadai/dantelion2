#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLPathString : public DLString
	{
	public:
		DLPathString() : DLString() {}
		DLPathString(const DLPathString& other) : DLString(other) {}
	};
 }