#include "DLAllocator.h"
#include "Call.h"

namespace DLKR
{
    typedef DLHeapIdentifier(__fastcall* oGetHeapID)(DLAllocator*);
    typedef DLHeapIdentifier(__fastcall* oGetAllocatorID)(DLAllocator*);
    typedef DLHeapCapability(__fastcall* oGetCapability)(DLAllocator*, DLHeapDirection);
    typedef dl_size(__fastcall* oGetTotalSize)(DLAllocator*);
    typedef dl_size(__fastcall* oGetFreeSize)(DLAllocator*);
    typedef dl_size(__fastcall* oGetMaxSize)(DLAllocator*);
    typedef dl_size(__fastcall* oGetBlockNumber)(DLAllocator*);
    typedef dl_size(__fastcall* oGetBlockSize)(DLAllocator*, const void*);
    typedef void* (__fastcall* oAllocate)(DLAllocator*, dl_size);
    typedef void* (__fastcall* oAllocateAligned)(DLAllocator*, dl_size, dl_uint);
    typedef void* (__fastcall* oReallocate)(DLAllocator*, void*, dl_size);
    typedef void* (__fastcall* oReallocateAligned)(DLAllocator*, void*, dl_size, dl_uint);
    typedef void(__fastcall* oFree)(DLAllocator*, void*);
    typedef void(__fastcall* oFreeAll)(DLAllocator*);
    typedef void* (__fastcall* oBackAllocate)(DLAllocator*, dl_size);
    typedef void* (__fastcall* oBackAllocateAligned)(DLAllocator*, dl_size, dl_uint);
    typedef void* (__fastcall* oBackReallocate)(DLAllocator*, void*, dl_size);
    typedef void* (__fastcall* oBackReallocateAligned)(DLAllocator*, void*, dl_size, dl_uint);
    typedef void(__fastcall* oBackFree)(DLAllocator*, void*);
    typedef dl_bool(__fastcall* oSelfDiagnose)(DLAllocator*);
    typedef dl_bool(__fastcall* oIsValidBlock)(DLAllocator*, const void*);
    typedef void(__fastcall* oDestructor)(DLAllocator*);

    DLAllocator::~DLAllocator() {
        VIRTUAL_CALL(this, 0, oDestructor, this);
    }

    DLHeapIdentifier DLAllocator::GetHeapID() const {
        return VIRTUAL_CALL((DLAllocator*)this, 1, oGetHeapID, (DLAllocator*)this);
    }

    DLHeapIdentifier DLAllocator::GetAllocatorID() const {
        return VIRTUAL_CALL((DLAllocator*)this, 2, oGetAllocatorID, (DLAllocator*)this);
    }

    DLHeapCapability DLAllocator::GetCapability(DLHeapDirection d) const {
        return VIRTUAL_CALL((DLAllocator*)this, 3, oGetCapability, (DLAllocator*)this, d);
    }

    dl_size DLAllocator::GetTotalSize() const {
        return VIRTUAL_CALL((DLAllocator*)this, 4, oGetTotalSize, (DLAllocator*)this);
    }

    dl_size DLAllocator::GetFreeSize() const {
        return VIRTUAL_CALL((DLAllocator*)this, 5, oGetFreeSize, (DLAllocator*)this);
    }

    dl_size DLAllocator::GetMaxSize() const {
        return VIRTUAL_CALL((DLAllocator*)this, 6, oGetMaxSize, (DLAllocator*)this);
    }

    dl_size DLAllocator::GetBlockNumber() const {
        return VIRTUAL_CALL((DLAllocator*)this, 7, oGetBlockNumber, (DLAllocator*)this);
    }

    dl_size DLAllocator::GetBlockSize(const void* block) const {
        return VIRTUAL_CALL((DLAllocator*)this, 8, oGetBlockSize, (DLAllocator*)this, block);
    }

    void* DLAllocator::Allocate(size_type size) {
        return VIRTUAL_CALL(this, 9, oAllocate, this, size);
    }

    void* DLAllocator::AllocateAligned(size_type size, dl_uint align) {
        return VIRTUAL_CALL(this, 10, oAllocateAligned, this, size, align);
    }

    void* DLAllocator::Reallocate(void* old, size_type size) {
        return VIRTUAL_CALL(this, 11, oReallocate, this, old, size);
    }

    void* DLAllocator::ReallocateAligned(void* old, dl_size size, dl_uint align) {
        return VIRTUAL_CALL(this, 12, oReallocateAligned, this, old, size, align);
    }

    void DLAllocator::Free(pointer p) {
        VIRTUAL_CALL(this, 13, oFree, this, p);
    }

    void DLAllocator::FreeAll() {
        VIRTUAL_CALL(this, 14, oFreeAll, this);
    }

    void* DLAllocator::BackAllocate(dl_size size) {
        return VIRTUAL_CALL(this, 15, oBackAllocate, this, size);
    }

    void* DLAllocator::BackAllocateAligned(dl_size size, dl_uint align) {
        return VIRTUAL_CALL(this, 16, oBackAllocateAligned, this, size, align);
    }

    void* DLAllocator::BackReallocate(void* old, dl_size size) {
        return VIRTUAL_CALL(this, 17, oBackReallocate, this, old, size);
    }

    void* DLAllocator::BackReallocateAligned(void* old, dl_size size, dl_uint align) {
        return VIRTUAL_CALL(this, 18, oBackReallocateAligned, this, old, size, align);
    }

    void DLAllocator::BackFree(void* block) {
        VIRTUAL_CALL(this, 19, oBackFree, this, block);
    }

    dl_bool DLAllocator::SelfDiagnose() const {
        return VIRTUAL_CALL((DLAllocator*)this, 20, oSelfDiagnose, (DLAllocator*)this);
    }

    dl_bool DLAllocator::IsValidBlock(const void* block) const {
        return VIRTUAL_CALL((DLAllocator*)this, 21, oIsValidBlock, (DLAllocator*)this, block);
    }
}