#include "DLFileInputStream.h"
#include "Call.h"

namespace
{
	typedef void* (_fastcall* DLFileInputStreamCtor_t)(DLIO::DLFileInputStream*, DLIO::DLFile&, dl_bool);
	typedef void* (_fastcall* DLFileInputStreamDefaultCtor_t)(DLIO::DLFileInputStream*);
	typedef void(_fastcall* DLFileInputStreamDtor_t)(DLIO::DLFileInputStream*);
	typedef dl_bool(_fastcall* Open_t)(DLIO::DLFileInputStream*, DLIO::DLFile&, dl_bool);
}

namespace DLIO
{
	DLFileInputStream::DLFileInputStream(DLFile& file, bool isAsync)
	{
		CALL(DLFileInputStreamCtor_t, 0x8765E0, this, file, isAsync);
	}

	DLFileInputStream::DLFileInputStream()
	{
		CALL(DLFileInputStreamDefaultCtor_t, 0x876620, this);
	}

	DLFileInputStream::~DLFileInputStream()
	{
		CALL(DLFileInputStreamDtor_t, 0x876650, this);
	}

	dl_bool DLFileInputStream::Open(DLFile& file, bool isAsync)
	{
		return CALL(Open_t, 0x8766C0, this, file, isAsync);
	}

	void DLFileInputStream::SetLastError(IO_ERROR_CODE error)
	{
		CALL(SetLastError_t, 0x8765D0, this, error);
	}

	IO_ERROR_CODE DLFileInputStream::GetLastError() const
	{
		return CALL(GetLastError_t, 0x876CB0, this);
	}

	dl_int32 DLFileInputStream::Read(void* buf, dl_size size)
	{
		return CALL(Read_t, 0x8767A0, this, buf, size);
	}

	dl_bool DLFileInputStream::IsAvailable(void)
	{
		return CALL(IsAvailable_t, 0x876850, this);
	}

	dl_size DLFileInputStream::GetReadSize(void)
	{
		return CALL(GetReadSize_t, 0x8768A0, this);
	}

	dl_size DLFileInputStream::Skip(dl_size length)
	{
		return CALL(Skip_t, 0x8768E0, this, length);
	}

	void DLFileInputStream::Close(void)
	{
		CALL(Close_t, 0x876970, this);
	}

	dl_bool DLFileInputStream::IsOpen(void) const
	{
		return CALL(IsOpen_t, 0x8769C0, this);
	}

	dl_size DLFileInputStream::GetAsyncBlockSize(void) const
	{
		return CALL(GetAsyncBlockSize_t, 0x876B20, this);
	}

	dl_size DLFileInputStream::GetAsyncBufferAlignmentSize(void) const
	{
		return CALL(GetAsyncBufferAlignmentSize_t, 0x876B60, this);
	}

	dl_bool DLFileInputStream::QueryAsyncStatus(dl_size* remain, dl_size* total)
	{
		return CALL(QueryAsyncStatus_t, 0x876BA0, this, remain, total);
	}

	dl_bool DLFileInputStream::StartAsyncRead(dl_int8* buffer, dl_size len)
	{
		return CALL(StartAsyncRead_t, 0x876C20, this, buffer, len);
	}

	dl_bool DLFileInputStream::SeekPosition(dl_pointer_int pos, DLSeekDirection direction)
	{
		return CALL(SeekPosition_t, 0x876A00, this, pos, direction);
	}

	dl_pointer_int DLFileInputStream::GetPosition(void)
	{
		return CALL(GetPosition_t, 0x876A90, this);
	}

	dl_bool DLFileInputStream::IsEOS(void)
	{
		return CALL(IsEOS_t, 0x876AD0, this);
	}
}