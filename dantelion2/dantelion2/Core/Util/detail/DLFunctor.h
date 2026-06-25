#pragma once
#include "Core/Platform/Platform.h"
#include "../DLEmptyType.h"
#include "../DLNullType.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLSingleThreadingPolicy.h"
#include <memory>

namespace DLUTD
{
	template < class ThreadingPolicy >
	class DLDefaultMemoryObjectModel
	{};

	template<typename R, class MemoryObjectModel>
	class DLFunctorImplBase : public MemoryObjectModel
	{
		typedef R ResultType;
		typedef DLUT::DLEmptyType Parm1;
		typedef DLUT::DLEmptyType Parm2;
		typedef DLUT::DLEmptyType Parm3;
		typedef DLUT::DLEmptyType Parm4;
		typedef DLUT::DLEmptyType Parm5;
		typedef DLUT::DLEmptyType Parm6;
		typedef DLUT::DLEmptyType Parm7;
		typedef DLUT::DLEmptyType Parm8;
		typedef DLUT::DLEmptyType Parm9;
		typedef DLUT::DLEmptyType Parm10;
		typedef DLUT::DLEmptyType Parm11;
		typedef DLUT::DLEmptyType Parm12;
		typedef DLUT::DLEmptyType Parm13;
		typedef DLUT::DLEmptyType Parm14;
		typedef DLUT::DLEmptyType Parm15;
	};

	template < typename R, class TList, class MemoryObjectModel
		= DLUTD::DLDefaultMemoryObjectModel<DLKR::DLSingleThreadingPolicy> >
	class DLFunctorImpl;

	template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
	class DLMemFunHandler : public ParentFunctor::Impl
	{
		typedef typename ParentFunctor::Impl Base;
		typedef typename Base::ResultType ResultType;

		PointerToObj pObj_;
		PointerToMemFn pMemFn_;
	};

	template < typename R, class TList = DLUT::DLNullType, class MemoryObjectModel
		= DLUTD::DLDefaultMemoryObjectModel< DLKR::DLSingleThreadingPolicy > >
	class DLFunctor : public DLFunctorImplBase<R, MemoryObjectModel>
	{
	public:
		typedef DLFunctorImpl<R, TList, MemoryObjectModel> Impl;

		Impl* spImpl_;
	};
}
