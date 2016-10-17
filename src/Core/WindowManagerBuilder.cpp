#include "Core\WindowManagerBuilder.hpp"

namespace Utils
{
	template<class T, typename std::enable_if<std::is_base_of<WindowManager, T>::value>::type>
	WindowManager * WindowManagerBuilder::makeWindowManager()
	{
		return new T();
	}
}