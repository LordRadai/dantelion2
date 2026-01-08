#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "DLEmptyType.h"
#include "DLNullType.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Kernel/DLSingleThreadingPolicy.h"
#include <memory>

namespace DLUTD
{
	template < class ThreadingPolicy >
	class DLDefaultMemoryObjectModel
	{
	};
}

namespace DLUT
{
	template<typename R, class MemoryObjectModel>
	class DLFunctorImplBase : public MemoryObjectModel
	{
		typedef R ResultType;
		typedef DLEmptyType Parm1;
		typedef DLEmptyType Parm2;
		typedef DLEmptyType Parm3;
		typedef DLEmptyType Parm4;
		typedef DLEmptyType Parm5;
		typedef DLEmptyType Parm6;
		typedef DLEmptyType Parm7;
		typedef DLEmptyType Parm8;
		typedef DLEmptyType Parm9;
		typedef DLEmptyType Parm10;
		typedef DLEmptyType Parm11;
		typedef DLEmptyType Parm12;
		typedef DLEmptyType Parm13;
		typedef DLEmptyType Parm14;
		typedef DLEmptyType Parm15;
	};

	template < typename R, class TList, class MemoryObjectModel
		= DLUTD::DLDefaultMemoryObjectModel<DLKR::DLSingleThreadingPolicy> >
	class DLFunctorImpl;

	template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
	class DLMemFunHandler : public ParentFunctor::Impl
	{
		typedef ParentFunctor::Impl Base;
		typedef typename Base::ResultType ResultType;

		PointerToObj pObj_;
		PointerToMemFn pMemFn_;
	};

	template < typename R, class TList = DLUT::DLNullType, class MemoryObjectModel
		= DLUTD::DLDefaultMemoryObjectModel< DLKR::DLSingleThreadingPolicy > >
	class DLFunctor : public DLFunctorImplBase<R, MemoryObjectModel>
	{
		typedef DLFunctorImpl<R, TList, MemoryObjectModel> Impl;

		Impl* spImpl_;
	};
}
