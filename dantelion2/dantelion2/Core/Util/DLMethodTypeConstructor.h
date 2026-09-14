#pragma once
#include "DLTypeList.h"
#include "Core/Platform/Platform.h"

namespace DLUT
{
    template< class ClassType, typename _ReturnType, typename _ParamList >
    class DLMethodTypeConstructor {

        typedef _ReturnType ReturnType;
        typedef _ParamList ParamList;

        template < dl_int32 i, bool _dummy > struct MethodTypeDefiner;
        template< bool _dummy > struct MethodTypeDefiner<0, _dummy> {
            typedef ReturnType(ClassType::* MethodType)(void);
            typedef ReturnType(ClassType::* ConstMethodType)(void) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<1, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef ReturnType(ClassType::* MethodType)(Param0);
            typedef ReturnType(ClassType::* ConstMethodType)(Param0) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<2, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef ReturnType(ClassType::* MethodType)(Param0, Param1);
            typedef ReturnType(ClassType::* ConstMethodType)(Param0, Param1) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<3, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef ReturnType(ClassType::* MethodType)(Param0, Param1, Param2);
            typedef ReturnType(ClassType::* ConstMethodType)(Param0, Param1, Param2) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<4, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<5, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<6, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<7, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<8, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<9, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<10, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<11, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result Param10;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<12, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result Param10;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result Param11;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<13, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result Param10;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result Param11;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result Param12;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<14, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result Param10;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result Param11;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result Param12;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 13>::Result Param13;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12, Param13);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12, Param13) const;
        };

        template< bool _dummy > struct MethodTypeDefiner<15, _dummy> {
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result Param0;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result Param1;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result Param2;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result Param3;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result Param4;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result Param5;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result Param6;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result Param7;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result Param8;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result Param9;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result Param10;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result Param11;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result Param12;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 13>::Result Param13;
            typedef typename DLUT::TypeList::TypeAtNonStrict<ParamList, 14>::Result Param14;

            typedef ReturnType(ClassType::* MethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12, Param13, Param14);
            typedef ReturnType(ClassType::* ConstMethodType)
                (Param0, Param1, Param2, Param3, Param4,
                    Param5, Param6, Param7, Param8, Param9,
                    Param10, Param11, Param12, Param13, Param14) const;
        };
    public:
        typedef typename MethodTypeDefiner< DLUT::TypeList::Length< ParamList >::Size, true >::MethodType Result;
        typedef typename MethodTypeDefiner< DLUT::TypeList::Length< ParamList >::Size, true >::ConstMethodType ConstResult;
    };
}