#pragma once
#include "Core/Core.h"
#include "DLGPUResource.h"
#include "Core/Graphics/DLDrawContextDefines.h"

namespace DLGR
{
	class DLTextureBase : public DLGPUResource
	{
	public:
		enum DLTextureType : dl_int
		{
			DLTEXTYPE_2D = 0,
			DLTEXTYPE_CUBE = 1,
			DLTEXTYPE_3D = 2,
		};

        enum DLTextureFormat : uint32_t
        {
            // Block Compressed (DXT/BC)
            DXT1 = 0x00,
            LIN_DXT1 = 0x01,
            DXT2 = 0x02,
            LIN_DXT2 = 0x03,
            DXT3 = 0x04,
            LIN_DXT3 = 0x05,
            DXT4 = 0x06,
            LIN_DXT4 = 0x07,
            DXT5 = 0x08,
            LIN_DXT5 = 0x09,
            DXN = 0x0A,
            LIN_DXN = 0x0B,
            BC4 = 0x0C,
            LIN_BC4 = 0x0D,
            BC6H = 0x0E,
            LIN_BC6H = 0x0F,
            BC7 = 0x10,
            LIN_BC7 = 0x11,

            // 8-bit
            A8 = 0x12,
            LIN_A8 = 0x13,
            L8 = 0x14,
            LIN_L8 = 0x15,

            // 16-bit
            R5G6B5 = 0x18,
            LIN_R5G6B5 = 0x19,
            R6G5B5 = 0x1A,
            LIN_R6G5B5 = 0x1B,
            L6V5U5 = 0x1C,
            LIN_L6V5U5 = 0x1D,
            X1R5G5B5 = 0x1E,
            LIN_X1R5G5B5 = 0x1F,
            A1R5G5B5 = 0x20,
            LIN_A1R5G5B5 = 0x21,
            A4R4G4B4 = 0x22,
            LIN_A4R4G4B4 = 0x23,
            X4R4G4B4 = 0x24,
            LIN_X4R4G4B4 = 0x25,
            Q4W4V4U4 = 0x26,
            LIN_Q4W4V4U4 = 0x27,
            A8L8 = 0x28,
            LIN_A8L8 = 0x29,
            G8R8 = 0x2A,
            LIN_G8R8 = 0x2B,
            V8U8 = 0x2C,
            LIN_V8U8 = 0x2D,
            L16 = 0x2E,
            LIN_L16 = 0x2F,
            R16F = 0x30,
            LIN_R16F = 0x31,
            R16F_EXPAND = 0x32,
            LIN_R16F_EXPAND = 0x33,

            // 24-bit
            R8G8B8 = 0x34,

            // 32-bit
            A8R8G8B8 = 0x35,
            LIN_A8R8G8B8 = 0x36,
            X8R8G8B8 = 0x37,
            LIN_X8R8G8B8 = 0x38,
            A8B8G8R8 = 0x39,
            LIN_A8B8G8R8 = 0x3A,
            X8B8G8R8 = 0x3B,
            LIN_X8B8G8R8 = 0x3C,
            X8L8V8U8 = 0x3D,
            LIN_X8L8V8U8 = 0x3E,
            Q8W8V8U8 = 0x3F,
            LIN_Q8W8V8U8 = 0x40,
            A2R10G10B10 = 0x41,
            LIN_A2R10G10B10 = 0x42,
            X2R10G10B10 = 0x43,
            LIN_X2R10G10B10 = 0x44,
            A2B10G10R10 = 0x45,
            LIN_A2B10G10R10 = 0x46,
            A2W10V10U10 = 0x47,
            LIN_A2W10V10U10 = 0x48,

            // 32-bit float / wide
            A16L16 = 0x49,
            LIN_A16L16 = 0x4A,
            G16R16 = 0x4B,
            LIN_G16R16 = 0x4C,
            V16U16 = 0x4D,
            LIN_V16U16 = 0x4E,
            R10G11B11 = 0x4F,
            LIN_R10G11B11 = 0x50,
            R11G11B10 = 0x51,
            LIN_R11G11B10 = 0x52,
            W10V11U11 = 0x53,
            LIN_W10V11U11 = 0x54,
            W11V11U10 = 0x55,
            LIN_W11V11U10 = 0x56,
            G16R16F = 0x57,
            LIN_G16R16F = 0x58,
            G16R16F_EXPAND = 0x59,
            LIN_G16R16F_EXPAND = 0x5A,
            L32 = 0x5B,
            LIN_L32 = 0x5C,
            R32F = 0x5D,
            LIN_R32F = 0x5E,
            R11G11B10F = 0x5F,
            LIN_R11G11B10F = 0x60,

            // 64-bit
            A16B16G16R16 = 0x61,
            LIN_A16B16G16R16 = 0x62,
            Q16W16V16U16 = 0x63,
            LIN_Q16W16V16U16 = 0x64,
            A16B16G16R16F = 0x65,
            LIN_A16B16G16R16F = 0x66,
            A16B16G16R16F_EXPAND = 0x67,
            LIN_A16B16G16R16F_EXPAND = 0x68,

            // 64/128-bit wide
            A32L32 = 0x69,
            LIN_A32L32 = 0x6A,
            G32R32 = 0x6B,
            LIN_G32R32 = 0x6C,
            V32U32 = 0x6D,
            LIN_V32U32 = 0x6E,
            G32R32F = 0x6F,
            LIN_G32R32F = 0x70,
            A32B32G32R32 = 0x71,
            LIN_A32B32G32R32 = 0x72,
            Q32W32V32U32 = 0x73,
            LIN_Q32W32V32U32 = 0x74,
            A32B32G32R32F = 0x75,
            LIN_A32B32G32R32F = 0x76,

            // EDRAM / LE (little-endian) special formats
            A2B10G10R10F_EDRAM = 0x77,
            G16R16_EDRAM = 0x78,
            A16B16G16R16_EDRAM = 0x79,
            LE_X8R8G8B8 = 0x7A,
            LE_A8R8G8B8 = 0x7B,
            LE_X2R10G10B10 = 0x7C,
            LE_A2R10G10B10 = 0x7D,

            // DXT variant / special compressed
            DXT3A = 0x7E,
            LIN_DXT3A = 0x7F,
            DXT3A_1111 = 0x80,
            LIN_DXT3A_1111 = 0x81,
            DXT5A = 0x82,
            LIN_DXT5A = 0x83,
            CTX1 = 0x84,
            LIN_CTX1 = 0x85,

            // Depth / stencil
            D24S8 = 0x86,
            D24FS8 = 0x88,
            D24X8 = 0x8A,
            D32 = 0x8C,
            D16 = 0x8E,

            UNKNOWN = 0x90,
        };

		dl_uint GetWidth() const { return this->m_width; }
		dl_uint GetHeight() const { return this->m_height; }
		dl_uint GetMipMapLevelNum() const { return this->m_mipMapLevelNum; }

		dl_int GetType();
		dl_bool IsEnabled();
		dl_int GetFormat();

    protected:
        DLCG2::CGResource* m_pCGTexture;
        DLCG2::CGShaderResourceView* m_pCGShaderResourceView;
        dl_uint m_mipMapLevelNum;
        dl_int m_iVar3C;
        dl_uint m_width;
        dl_uint m_height;
        dl_int m_iVar48;
        dl_bool m_bVar4C;
        dl_pointer m_pVar50;
        dl_pointer m_pVar58;
	};

	class DLTexture2D : public DLTextureBase
	{
		dl_pointer m_pVar60;

	public:
		DLCG2::CGTexture2D* GetTexture() const { return static_cast<DLCG2::CGTexture2D*>(this->m_pCGTexture); }
		DLCG2::CGShaderResourceView* GetShaderResourceView() const { return this->m_pCGShaderResourceView; }
		DLTextureType GetTextureType() const { return DLTEXTYPE_2D; }
		DLTextureFormat GetTextureFormat() const;
	};
}