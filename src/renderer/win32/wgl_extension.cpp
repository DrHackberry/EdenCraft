#include "renderer/win32/wgl_extension.hpp"

#include "window/common/window_adapter.hpp"
#include "utility/log/service_logger.hpp"

#include <string>

namespace ece
{
	std::array<int, 2> WGLExtension::init(const OptionOpenGL options)
	{
		HDC device = nullptr;
		HGLRC tmpContext = nullptr;
		std::array<int, 2> version{ 0, 0 };

		if (!this->isLoaded(PLATFORM)) {
			auto windowHandle = CreateWindow(L"Static", L"", WS_DISABLED, 0, 0, 1, 1, nullptr, nullptr, nullptr, nullptr);
			if (windowHandle) {
				PIXELFORMATDESCRIPTOR pixelFormat;

				if (!wglGetCurrentContext()) {
					device = GetDC(windowHandle);
					if (!device) {
						throw std::runtime_error("OpenGL cannot be initialized beacause no device is currently available.");
					}

					if (!SetPixelFormat(device, 1, &pixelFormat)) {
						throw std::runtime_error("OpenGL cannot be initialized because no video mode fit with.");
					}
					tmpContext = wglCreateContext(device);
					if (!tmpContext) {
						throw std::runtime_error("OpenGL cannot be initialized because it is not possible to create a context.");
					}
					if (!wglMakeCurrent(device, tmpContext)) {
						throw std::runtime_error("OpenGL cannot be initialized because it is not possible to use a context.");
					}
				}
			}

			if (this->_openglLib == nullptr) {
				this->_openglLib = LoadLibrary(L"opengl32.dll");
			}
			if (!this->loadExtensions(options)) {
				ServiceLoggerLocator::getService().logWarning("Not all the GL extensions have been loaded");
			}

			if (glGetString) {
				std::string versionPtr(reinterpret_cast<const char *>(glGetString(GL_VERSION)));
				version[0] = std::stoi(versionPtr.substr(0, 1));
				version[1] = std::stoi(versionPtr.substr(2, 1));
			}

			if (tmpContext != nullptr) {
				wglMakeCurrent(nullptr, nullptr);
				wglDeleteContext(tmpContext);
				tmpContext = nullptr;
				ReleaseDC(windowHandle, device);
				device = nullptr;
				DestroyWindow(windowHandle);
				windowHandle = nullptr;
			}
		}
		else {
			std::runtime_error("A window is required to initialize OpenGL");
		}
		return version;
	}

	WGLExtension::~WGLExtension()
	{
		if (this->_openglLib != nullptr) {
			FreeLibrary(this->_openglLib);
			this->_openglLib = nullptr;
		}
	}

	void * WGLExtension::loadOpenGLProc(const std::string & name)
	{
		auto proc = wglGetProcAddress(name.data());
		if (proc == nullptr) {
			proc = GetProcAddress(this->_openglLib, name.data());
			if (proc == nullptr) {
				ServiceLoggerLocator::getService().logError(name + " cannot be loaded.");
				//throw std::runtime_error(name + " cannot be loaded.");
			}
		}
		return static_cast<void *>(proc);
	}

	void WGLExtension::loadPlatformExtensions()
	{
		wglChoosePixelFormat = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(this->loadOpenGLProc("wglChoosePixelFormatARB"));
		wglCreateContextAttribs = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(this->loadOpenGLProc("wglCreateContextAttribsARB"));
	}
}

// Platform
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs = nullptr;