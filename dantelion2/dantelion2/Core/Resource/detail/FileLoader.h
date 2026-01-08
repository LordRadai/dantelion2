#pragma once
#include "Core/Kernel/DLRunnable.h"
#include "TransferTask.h"
#include "Core/Kernel/DLThread.h"
#include "Core/Kernel/DLSemaphore.h"

namespace DLRSD
{
	class FileLoader : public DLKR::DLRunnable
	{
		struct UnkData
		{
			dl_char m_data[55];
			dl_bool m_bVar37;
		};

	public:
		dl_pointer m_pVar8;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		UnkData m_unkData[3];
		DLKR::DLPlainConditionSignal m_conditionSignal;
		DLKR::DLPlainConditionSignal m_conditionSignal2;
		DLKR::DLPlainLightMutex m_mutex;
		DLKR::DLThread* m_pLoaderThread;
		dl_bool m_bVar128;
		dl_bool m_bUseSystemCache;
		dl_bool m_bVar12A;
		dl_bool m_bVar12B;
		dl_int16 m_iVar12C;
		dl_int16 m_iVar12E;
		dl_int m_threadMask;
		dl_size m_onceReadSize;
		DLKR::DLPlainSemaphore* m_pSemaphore;

	private:
		dl_char m_data[119];

	public:
		class FileTransferData
		{
		public:
			enum TransferState
			{
				TRANSFER_START = 3,
				TRANSFER_DCX = 6,
				TRANSFER_IN_PROGRESS = 7,
				TRANSFER_COMPLETED = 11,
			};

		private:
			const dl_wchar* m_pFilePath;
			dl_int m_iVar8;
			dl_int m_iVarC;
			dl_pointer m_pVar10;
			dl_size m_fileSize;
			dl_size m_loadedSize;
			dl_pointer m_pFileInputStream;
			dl_uint* m_pTransferState;
			dl_uint* m_pFileState;
			dl_pointer m_pVar40;
			dl_pointer m_pVar48;
			dl_pointer m_pVar50;
			dl_pointer m_pVar58;
			dl_pointer m_pVar60;
			dl_pointer m_pVar68;
			dl_pointer m_pVar70;
			dl_pointer m_pVar78;
			dl_pointer m_pVar80;
			dl_uint m_iVar88;
			TransferTask* m_pTransferTask;
			TransferTask* m_pDcxTransferTask;
			dl_uint m_iVarA0;
			dl_bool m_bVarA4;
			dl_bool m_bVarA5;
			dl_bool m_bVarA6;
			dl_char* m_pVarA8;

		public:
			const dl_wchar* GetFilePath() const { return m_pFilePath; }
			dl_size GetFileSize() const { return m_fileSize; }
			dl_size GetLoadedSize() const { return m_loadedSize; }
			dl_uint GetTransferState() const { return *m_pTransferState; }
			dl_uint GetFileState() const { return *m_pFileState; }
			TransferTask* GetTransferTask() const { return m_pTransferTask; }
			TransferTask* GetDcxTransferTask() const { return m_pDcxTransferTask; }

			const dl_wchar* GetTransferStateName() const;
		};

		typedef dl_bool(_fastcall* oTransferFile)(FileLoader*, FileTransferData*, dl_pointer);
	};
}
