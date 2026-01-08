#pragma once
#include "DLCategoryRepository.h"
#include "DLCategory.h"
#include "dantelion2/Core/Util/DLMap.h"
#include "dantelion2/Core/Util/DLSet.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"

namespace DLLG
{
	class DLHierarchy : public DLCategoryRepository
	{
		class CategoryTree
		{
			typedef DLUT::DLSet<CategoryTree*> CategoryList;

			DLCategory* m_pCategory;
			CategoryTree* m_pParent;
			CategoryList m_children;
			DLTX::DLString m_token;
		};

		class CategoryFindResultCache {
			struct FRCEntry 
			{
				const dl_wchar* key;
				DLCategory* pCategory;
			};

			typedef DLUT::DLVector<FRCEntry> EntryVector;
			EntryVector m_cache;
		};

		typedef DLUT::DLSet<DLAppender*> AppenderList;
		typedef DLUT::DLSet<DLLayout*> LayoutList;
		typedef DLUT::DLSet<const DLCategory*> FlattenTreeList;
		typedef DLKR::DLPlainLightMutex SyncType;

		CategoryTree* m_pRoot;
		DLKR::DLAllocator* m_pA;
		dl_uint32 m_defaultAppenderSize;
		FlattenTreeList m_ftList;
		AppenderList m_appenders;
		LayoutList m_layouts;
		CategoryFindResultCache m_frCache;
		SyncType m_sync;

	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClass() override;
		virtual void SetAllocator(DLKR::DLAllocator* pA) override;
		virtual DLKR::DLAllocator* GetAllocator() override;
		virtual dl_bool DoesExist(const dl_wchar* cName) override;
		virtual dl_bool HasLayout(const dl_wchar* cName) override;
		virtual dl_bool HasAppender(const dl_wchar* cName) override;
		virtual DLCategory& GetCategory(const dl_wchar* cName) override;
		virtual DLCategory& GetCategory2(const dl_wchar* cName) override;
		virtual DLAppender* GetAppender(const dl_wchar* cName) override;
		virtual DLAppender* AddDefaultAppender(const dl_wchar* name = 0) override;
		virtual dl_bool AddAppender(DLAppender* pAppender) override;
		virtual DLAppender* AddAppender(const dl_char* className, const dl_wchar* name = 0) override;
		virtual DLLayout* AddDefaultLayout(const dl_wchar* name = 0) override;
		virtual dl_bool AddLayout(DLLayout* pLayout) override;
		virtual DLLayout* AddLayout(const dl_char* className, const dl_wchar* name = 0) override;
		virtual void RemoveCategory(const dl_wchar* cName) override;
		virtual DLCategory* AddCategory(const dl_wchar* cName) override;
		virtual DLCategory* GetRootCategory() override;
		virtual void ProcessEvent(const DLLogEvent& e) override;
		virtual dl_uint GetDefaultAppenderSize() override;
		virtual void SetDefaultAppenderSize(dl_uint newSize) override;
		virtual void ClearAppenders() override;
		virtual void InitializeAppenders() override;
		virtual ~DLHierarchy() override;
	};
}
