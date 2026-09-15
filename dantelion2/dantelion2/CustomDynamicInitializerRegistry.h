#pragma once
#include <functional>
#include <vector>

class CustomDynamicInitializerRegistry
{
	typedef void(_fastcall* DynamicInitFn)();
public:
	static CustomDynamicInitializerRegistry* GetInstance();
	void RunDynamicInitializers();

	void RegisterStaticInitializer(DynamicInitFn pFn);
private:
	CustomDynamicInitializerRegistry() {};
	~CustomDynamicInitializerRegistry() {};

	std::vector<DynamicInitFn> m_DynamicInitializers;

	static CustomDynamicInitializerRegistry* s_pInstance;
};

#define REGISTER_DYNAMIC_INITIALIZER(fn) CustomDynamicInitializerRegistry::GetInstance()->RegisterStaticInitializer(fn);