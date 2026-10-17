#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Text/DLString.inl"
#include "Core/Text/DLPathString.h"
#include "DLFile.h"

#undef CreateDirectory

namespace DLIO
{
    class DLFileDevice;

    class DLFileOperator
    {
    protected:
        DLKR::DLAllocator* m_pAllocator;
        IO_ERROR_CODE m_lastError;
        const DLFile* m_pFile;
        dl_uint32 m_bUnk0 : 1;
        dl_uint32 m_bInitFlag1 : 1;
        dl_uint32 m_bInitFlag2 : 1;
        const DLFileDevice* m_pDevice;
        DLTX::DLPathString m_path;

    public:
        typedef void* (_fastcall* DLFileOperatorCtor_t)(DLFileOperator*, const DLTX::DLPathString&, const DLFileDevice*, const DLFile*, DLKR::DLAllocator*);
        typedef void* (_fastcall* DLFileOperatorDtor_t)(DLFileOperator*, dl_uint32);
        typedef dl_bool(_fastcall* InitializeFlags_t)(DLFileOperator*, dl_bool, dl_bool);
        typedef dl_bool(_fastcall* InitializeString_t)(DLFileOperator*, const DLTX::DLString&, dl_bool, dl_bool);
        typedef dl_bool(_fastcall* InitializeTempString_t)(DLFileOperator*, const DLTX::DLTempString&, dl_bool, dl_bool);
        typedef dl_bool(_fastcall* InitializePathString_t)(DLFileOperator*, const DLTX::DLPathString&, dl_bool, dl_bool);
        typedef dl_bool(_fastcall* InitializeCopy_t)(DLFileOperator*, const DLFileOperator&);
        typedef dl_bool(_fastcall* Finalize_t)(DLFileOperator*);
        typedef DLFileOperator* (_fastcall* Replicate_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* EnumerateContents_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* CanRead_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* CanWrite_t)(const DLFileOperator*);
        typedef dl_uint64(_fastcall* GetLastAccessedTime_t)(const DLFileOperator*);
        typedef dl_uint64(_fastcall* GetLastModifiredTime_t)(const DLFileOperator*);
        typedef dl_size(_fastcall* GetFileSize_t)(const DLFileOperator*);
        typedef dl_size(_fastcall* GetReadSize_t)(const DLFileOperator*);
        typedef dl_size(_fastcall* GetWriteSize_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* SetEOF_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* IsEOF_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* IsDirectory_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* IsOpen_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* Open_t)(DLFileOperator*, dl_uint);
        typedef void(_fastcall* Close_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* SetReadOnly_t)(DLFileOperator*, dl_bool);
        typedef dl_bool(_fastcall* SeekPosition_t)(DLFileOperator*, dl_bool, dl_int64, DLSeekDirection);
        typedef dl_int64(_fastcall* GetPosition_t)(const DLFileOperator*);
        typedef dl_int32(_fastcall* Read_t)(DLFileOperator*, dl_int8*, dl_size);
        typedef dl_int32(_fastcall* Write_t)(DLFileOperator*, const dl_int8*, dl_size);
        typedef dl_size(_fastcall* GetAsyncBlockSize_t)(const DLFileOperator*);
        typedef dl_size(_fastcall* GetAsyncBufferAlignmentSize_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* StartAsyncRead_t)(DLFileOperator*, dl_int8*, dl_size);
        typedef dl_bool(_fastcall* StartAsyncWrite_t)(DLFileOperator*, dl_int8*, dl_size);
        typedef dl_bool(_fastcall* QueryAsyncStatus_t)(DLFileOperator*, dl_size*, dl_size*);
        typedef dl_uint(_fastcall* GetOpenFlag_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* Delete_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* Flush_t)(DLFileOperator*);
        typedef dl_bool(_fastcall* DoesExist_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* IsAltered_t)(const DLFileOperator*);
        typedef dl_bool(_fastcall* RenameA_t)(DLFileOperator*, const dl_char*);
        typedef dl_bool(_fastcall* RenameW_t)(DLFileOperator*, const dl_wchar*);
        typedef dl_bool(_fastcall* CreateDirectory_t)(DLFileOperator*);

        DLFileOperator(const DLTX::DLPathString& path, const DLFileDevice* pDevice, const DLFile* pFile, DLKR::DLAllocator* pAllocator);

        virtual ~DLFileOperator();
        virtual dl_bool Initialize(dl_bool flag1, dl_bool flag2);
        virtual dl_bool Initialize(const DLTX::DLString& path, dl_bool flag1, dl_bool flag2);
        virtual dl_bool Initialize(const DLTX::DLTempString& path, dl_bool flag1, dl_bool flag2);
        virtual dl_bool Initialize(const DLTX::DLPathString& path, dl_bool flag1, dl_bool flag2);
        virtual dl_bool Initialize(const DLFileOperator& other);
        virtual dl_bool Finalize();
        virtual DLFileOperator* Replicate() = 0;
        virtual dl_bool EnumerateContents() = 0;
        virtual dl_bool CanRead() const = 0;
        virtual dl_bool CanWrite() const = 0;
        virtual dl_uint64 GetLastAccessedTime() const = 0;
        virtual dl_uint64 GetLastModifiredTime() const = 0;
        virtual dl_size GetFileSize() const = 0;
        virtual dl_size GetReadSize() const = 0;
        virtual dl_size GetWriteSize() const = 0;
        virtual dl_bool SetEOF() = 0;
        virtual dl_bool IsEOF() const = 0;
        virtual dl_bool IsDirectory() const = 0;
        virtual dl_bool IsOpen() const = 0;
        virtual dl_bool Open(dl_uint mode) = 0;
        virtual void Close() = 0;
        virtual dl_bool SetReadOnly(dl_bool readOnly) = 0;
        virtual dl_bool SeekPosition(dl_bool, dl_int64 pos, DLSeekDirection direction) = 0;
        virtual dl_int64 GetPosition() const = 0;
        virtual dl_int32 Read(dl_int8* buf, dl_size size) = 0;
        virtual dl_int32 Write(const dl_int8* buf, dl_size size) = 0;
        virtual dl_size GetAsyncBlockSize() const = 0;
        virtual dl_size GetAsyncBufferAlignmentSize() const = 0;
        virtual dl_bool StartAsyncRead(dl_int8* buf, dl_size len) = 0;
        virtual dl_bool StartAsyncWrite(dl_int8* buf, dl_size len) = 0;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total) = 0;
        virtual dl_uint GetOpenFlag() const = 0;
        virtual dl_bool Delete() = 0;
        virtual dl_bool Flush();
        virtual dl_bool DoesExist() const = 0;
        virtual dl_bool IsAltered() const = 0;
        virtual dl_bool Rename(const dl_char* name) = 0;
        virtual dl_bool Rename(const dl_wchar* name) = 0;
        virtual dl_bool CreateDirectory() = 0;
    };
}