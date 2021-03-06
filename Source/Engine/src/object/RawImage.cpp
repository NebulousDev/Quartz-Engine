#include "RawImage.h"

namespace Quartz
{
	RawImage::RawImage(UInt32 width, UInt32 height,
		UInt32 channels, UInt32 bitsPerChannel, Byte* data) :
		mWidth(width),
		mHeight(height),
		mChannels(channels),
		mBitsPerChannel(bitsPerChannel),
		mpData(data)
	{
		mSizeBytes = (width * height * channels * bitsPerChannel) / 8;
	}

	UInt32 RawImage::GetWidth() const
	{
		return mWidth;
	}

	UInt32 RawImage::GetHeight() const
	{
		return mHeight;
	}

	UInt32 RawImage::GetChannels() const
	{
		return mChannels;
	}

	UInt32 RawImage::GetBitsPerChannel() const
	{
		return mBitsPerChannel;
	}

	Byte* RawImage::GetData() const
	{
		return mpData;
	}

	UInt32 RawImage::GetSizeBytes() const
	{
		return mSizeBytes;
	}
}
