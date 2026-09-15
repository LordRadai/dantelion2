#include "CustomDynamicInitializerRegistry.h"

CustomDynamicInitializerRegistry* CustomDynamicInitializerRegistry::s_pInstance = nullptr;

CustomDynamicInitializerRegistry* CustomDynamicInitializerRegistry::GetInstance()
{
	if (!s_pInstance)
		s_pInstance = new CustomDynamicInitializerRegistry();

	return s_pInstance;
}

void CustomDynamicInitializerRegistry::RunDynamicInitializers()
{
	for (auto& fn : m_DynamicInitializers)
	{
		fn();
	}
}

void CustomDynamicInitializerRegistry::RegisterStaticInitializer(DynamicInitFn pFn)
{
	m_DynamicInitializers.push_back(pFn);
}