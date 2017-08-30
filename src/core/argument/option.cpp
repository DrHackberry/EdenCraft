#include "argument/option.hpp"

#include <iostream>

namespace ece
{
	bool Option::apply(const std::string & optionName, const std::string & optionValue)
	{
		if (this->name != optionName.substr(1) || !this->value->isValid(optionValue)) {
			return false;
		}

		this->command(optionValue);
		return true;
	}
}