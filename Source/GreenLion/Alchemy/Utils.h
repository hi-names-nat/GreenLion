#pragma once

namespace Alchemy
{
	DECLARE_LOG_CATEGORY_EXTERN(AlchemyLog, Log, All)
	DECLARE_LOG_CATEGORY_EXTERN(AlchemyWarning, Warning, All)
	DECLARE_LOG_CATEGORY_EXTERN(AlchemyError, Error, All)
	DECLARE_LOG_CATEGORY_EXTERN(AlchemyFatal, Fatal, All)

	inline DEFINE_LOG_CATEGORY(AlchemyLog)
	inline DEFINE_LOG_CATEGORY(AlchemyWarning)
	inline DEFINE_LOG_CATEGORY(AlchemyError)
	inline DEFINE_LOG_CATEGORY(AlchemyFatal)
}
