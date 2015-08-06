// UniversalVariantTest.cpp : Defines the entry point for the console application.
//

#include <iostream>

#define MACRO_MAX(x, y) (x > y ? x : y)

typedef unsigned int uint;

#define DOGEVARIANT_SUPPORT_64_BASE_TYPES 1

enum ETypeSemantic {
	e_typesemantic_scalar,
	e_typesemantic_vector,
	e_typesemantic_color,
	e_typesemantic_euler_angle,
	e_typesemantic_string_const,
	e_typesemantic_string_mutable
};

enum EFundamentalScalarTypes {
#if DOGEVARIANT_SUPPORT_64_BASE_TYPES
	e_fundamentalscalartype_double,
#endif
	e_fundamentalscalartype_float,
	e_fundamentalscalartype_int,
	e_fundamentalscalartype_uint,
	e_fundamentalscalartype_bool
};

template <EFundamentalScalarTypes ETYPE>
struct FundamentalTypeSize {};

#if DOGEVARIANT_SUPPORT_64_BASE_TYPES
template <> struct FundamentalTypeSize<e_fundamentalscalartype_double> {
	static const size_t size = sizeof(double);
};
#endif
template <> struct FundamentalTypeSize<e_fundamentalscalartype_float> {
	static const size_t size = sizeof(float);
};
template <> struct FundamentalTypeSize<e_fundamentalscalartype_int> {
	static const size_t size = sizeof(int);
};
template <> struct FundamentalTypeSize<e_fundamentalscalartype_uint> {
	static const size_t size = sizeof(uint);
};
template <> struct FundamentalTypeSize<e_fundamentalscalartype_bool> {
	static const size_t size = sizeof(bool);
};

// X(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)

#define X_LIST_OF_VARIANT_TYPES \
	X(e_type_float,		1,	e_fundamentalscalartype_float,	e_typesemantic_scalar) \
	X(e_type_int,		1,	e_fundamentalscalartype_int,	e_typesemantic_scalar) \
	X(e_type_uint,		1,	e_fundamentalscalartype_uint,	e_typesemantic_scalar) \
	X(e_type_bool,		1,	e_fundamentalscalartype_bool,	e_typesemantic_scalar) \
	\
	X(e_type_float4,	4,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float3,	3,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float2,	2,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float1,	1,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	\
	X(e_type_int4,		4,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int3,		3,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int2,		2,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int1,		1,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	\
	X(e_type_uint4,		4,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint3,		3,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint2,		2,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint1,		1,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	\
	X(e_type_bool4,		4,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool3,		3,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool2,		2,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool1,		1,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	\
	X(e_type_float4x4,	16,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float3x3,	9,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float2x2,	4,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	X(e_type_float1x1,	1,	e_fundamentalscalartype_float,	e_typesemantic_vector) \
	\
	X(e_type_int4x4,	16,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int3x3,	9,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int2x2,	4,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	X(e_type_int1x1,	1,	e_fundamentalscalartype_int,	e_typesemantic_vector) \
	\
	X(e_type_uint4x4,	16,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint3x3,	9,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint2x2,	4,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	X(e_type_uint1x1,	1,	e_fundamentalscalartype_uint,	e_typesemantic_vector) \
	\
	X(e_type_bool4x4,	16,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool3x3,	9,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool2x2,	4,	e_fundamentalscalartype_bool,	e_typesemantic_vector) \
	X(e_type_bool1x1,	1,	e_fundamentalscalartype_bool,	e_typesemantic_vector)


#if DOGEVARIANT_SUPPORT_64_BASE_TYPES
#define X_LIST_OF_VARIANT_TYPES_64 \
	X(e_type_double, 1, e_fundamentalscalartype_double, e_typesemantic_scalar) \
	\
	X(e_type_double4, 4, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double3, 3, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double2, 2, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double1, 1, e_fundamentalscalartype_double, e_typesemantic_vector) \
	\
	X(e_type_double4x4, 16, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double3x3, 9, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double2x2, 4, e_fundamentalscalartype_double, e_typesemantic_vector) \
	X(e_type_double1x1, 1, e_fundamentalscalartype_double, e_typesemantic_vector)
#else
#define X_LIST_OF_VARIANT_TYPES_64
#endif


#define X(_1, _2, _3, _4)
	X_LIST_OF_VARIANT_TYPES \
	X_LIST_OF_VARIANT_TYPES_64
#undef X

enum DogeVariantEType {
#define X(eType, _2, _3, _4) eType, 
		X_LIST_OF_VARIANT_TYPES \
		X_LIST_OF_VARIANT_TYPES_64
#undef X
};

namespace DogeDetail {
	namespace DogeVariant {

		template <size_t lsize, size_t rsize>
		struct MaxSizeof {
			static const size_t size = MACRO_MAX(lsize, rsize);
		};

		const size_t max_variant_size =
#define X(_1, nComponents, eScalar, _4) MaxSizeof<FundamentalTypeSize<eScalar>::size * nComponents,
			X_LIST_OF_VARIANT_TYPES \
			X_LIST_OF_VARIANT_TYPES_64
#undef X
			static_cast<size_t>(0)
#define X(_1, _2, _3, _4) >::size
			X_LIST_OF_VARIANT_TYPES \
			X_LIST_OF_VARIANT_TYPES_64
#undef X
			;

	static const char* LUT_ETypeToName[] = {
#define X(eType, _2, _3, _4) #eType,
		X_LIST_OF_VARIANT_TYPES \
		X_LIST_OF_VARIANT_TYPES_64
#undef X
	};

	static const size_t LUT_ETypeToByteSize[] = {
#define X(_1, nComponents, eScalar, _4) FundamentalTypeSize<eScalar>::size * nComponents,
		X_LIST_OF_VARIANT_TYPES \
		X_LIST_OF_VARIANT_TYPES_64
#undef X
	};


	}
}

struct BasicFloat4 {
	float m_[4];
};

#define X_LIST_OF_TYPE_TO_VARIANT_ETYPE \
	X(float,		e_type_float) \
	X(int,			e_type_int) \
	X(uint,			e_type_uint) \
	X(bool,			e_type_bool) \
	X(BasicFloat4,	e_type_float4)

#if DOGEVARIANT_SUPPORT_64_BASE_TYPES
#define X_LIST_OF_TYPE_TO_VARIANT_ETYPE_64 \
	X(double, e_type_double)
#else
#define X_LIST_OF_TYPE_TO_VARIANT_ETYPE_64
#endif

template <class CTYPE>
struct CTypeToVariantEType {
	const DogeVariantEType eType = e_type_float;
};

#define X(cType, enumType) template <> struct CTypeToVariantEType<cType> { static const DogeVariantEType eType = enumType; }; 
	X_LIST_OF_TYPE_TO_VARIANT_ETYPE \
	X_LIST_OF_TYPE_TO_VARIANT_ETYPE_64
#undef X

class DogeVariant {
public:
	template <class T>
	DogeVariant(const T& val)
	{
		m_eType = CTypeToVariantEType<T>::eType;
		memcpy(m_dataBuffer, &val, sizeof(T));
	}

	DogeVariantEType GetEType() const { return m_eType; }
	const char* GetETypeName() const { return DogeDetail::DogeVariant::LUT_ETypeToName[m_eType]; }
	size_t GetByteSize() const { return DogeDetail::DogeVariant::LUT_ETypeToByteSize[m_eType]; }

	const void* GetConstDataBuffer() const { return m_dataBuffer; }

private:
	char m_dataBuffer[DogeDetail::DogeVariant::max_variant_size];

	DogeVariantEType m_eType;
};
	

int main()
{
	DogeVariant dogeVar(static_cast<double>(987654321.123456789));

	std::cout << dogeVar.GetETypeName() << " (" << dogeVar.GetByteSize() << ") = " << *(double*)dogeVar.GetConstDataBuffer() << '\n';
}

