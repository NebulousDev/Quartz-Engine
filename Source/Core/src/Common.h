#pragma once

#define INLINE _inline

#ifdef QUARTZ_DEBUG
#define FORCE_INLINE INLINE
#else
#define FORCE_INLINE __forceinline
#endif // QUARTZ_DEBUG

#ifndef NULL
#define NULL 0x0
#endif // !NULL

#ifdef QUARTZ_API_EXPORT
#define QUARTZ_API _declspec(dllexport)
#else
#define QUARTZ_API _declspec(dllimport)
#endif

namespace Quartz
{
	typedef __int64 Int64;
	typedef __int32 Int32;
	typedef __int16 Int16;
	typedef __int8  Int8;

	typedef unsigned __int64 UInt64;
	typedef unsigned __int32 UInt32;
	typedef unsigned __int16 UInt16;
	typedef unsigned __int8  UInt8;

#ifdef QUARTZ_64
	typedef unsigned __int64 USize;
#else
	typedef unsigned __int32 USize;
#endif // QUARTZ_64

	typedef bool   Bool8;	// <- Would really like this to be Bool (but Win32API is dumb)
	typedef float  Float32;
	typedef double Double64;

	typedef UInt8 Byte;

	typedef char Char;
	typedef UInt16 WChar;

	typedef UInt8 Flags8;
	typedef UInt16 Flags16;
	typedef UInt32 Flags32;
	typedef UInt64 Flags64;

	typedef UInt16 Handle16;
	typedef UInt32 Handle32;
	typedef UInt64 Handle64;

	typedef Float32 Time32;
	typedef Double64 Time64;

	template<typename _Type>
	struct RValue
	{
		using Type = _Type;
	};

	template<typename _Type>
	struct RValue<_Type&>
	{
		using Type = _Type;
	};

	template<typename _Type>
	struct RValue<_Type&&>
	{
		using Type = _Type;
	};

	template<typename _Type>
	using RValueType = typename RValue<_Type>::Type;

	template<typename Type>
	constexpr RValueType<Type>&& Move(Type&& value) noexcept
	{ 
		return static_cast<RValueType<Type>&&>(value); 
	}

	template<typename Type>
	constexpr Type&& Forward(RValueType<Type>&& args) noexcept
	{
		return static_cast<Type&&>(args);
	}

	template<typename Type>
	void Swap(Type& t1, Type& t2)
	{
		Type temp = Move(t1);
		t1 = Move(t2);
		t2 = Move(temp);
	}
}