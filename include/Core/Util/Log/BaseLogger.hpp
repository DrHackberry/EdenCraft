#ifndef BASELOGGER_HPP
#define BASELOGGER_HPP

#include <string>
#include <iostream>

namespace ece
{
	class BaseLogger
	{
	public:
		inline BaseLogger();
		inline virtual ~BaseLogger() = 0;
		
		virtual void logError(const std::string & data) = 0;
		virtual void logWarning(const std::string & data) = 0;
		virtual void logInfo(const std::string & data) = 0;

	protected:
		std::ostream & target;
	};
}

#include "Util\Log\BaseLogger.inl"

#endif // BASELOGGER_HPP