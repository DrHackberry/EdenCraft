#ifndef SERVICEGL_HPP
#define SERVICEGL_HPP

#include "Service\ServiceFactory.hpp"
#include "Service\ServiceLocator.hpp"
#include "GraphicLibrary\NoneGL.hpp"

namespace ece
{
	typedef ServiceFactory<BaseGL> ServiceGLFactory;
	typedef ServiceLocator<BaseGL, NoneGL> ServiceGLLocator;
}

#endif // SERVICEGL_HPP