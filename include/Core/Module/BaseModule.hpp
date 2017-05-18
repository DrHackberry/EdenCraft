#ifndef BASEMODULE_HPP
#define BASEMODULE_HPP

#include <functional>

namespace ece
{

	class BaseModule
	{
	public:
		inline BaseModule() = default;
		BaseModule(const BaseModule & copy) = default;
		BaseModule(BaseModule && move) = default;

		~BaseModule() = default;

		BaseModule & operator=(const BaseModule & copy) = default;
		BaseModule & operator=(BaseModule && move) = default;

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void terminate() = 0;

	private:
	};
}

#endif // BASEMODULE_HPP