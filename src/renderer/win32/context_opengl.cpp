#include "renderer/win32/context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "renderer/common/render_window.hpp"
#include "window/win32/window_adapter.hpp"
#include "utility/log/service_logger.hpp"

#include <iostream>

namespace ece
{
	ContextOpenGL::~ContextOpenGL()
	{
		if (this->context != nullptr) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(this->context);
			this->context = nullptr;
		}
		if (this->device != nullptr) {
			ReleaseDC(this->windowHandle, this->device);
			this->device = nullptr;
		}
		this->windowHandle = nullptr;
	}

	void ContextOpenGL::create(const RenderWindow & window)
	{
		OpenGL::init(COMMAND_EXECUTION | TIMER_QUERIES | SYNCHRONIZATION | ASYNCHRONOUS_QUERIES
			| BUFFER_OBJECTS | SHADERS_AND_PROGRAMS | TEXTURES_AND_SAMPLERS | FRAMEBUFFER_OBJECTS
			| VERTICES | VERTEX_ARRAYS | VERTEX_ATTRIBUTES | VERTEX_POST_PROCESSING | RASTERIZATION
			| FRAGMENT_SHADERS | COMPUTE_SHADERS | PER_FRAGMENT_OPERATIONS | HINTS
			| WHOLE_FRAMEBUFFER | READING_AND_COPYING_PIXELS | DEBUG_OUTPUT | STATE_AND_STATE_REQUESTS
			| PLATFORM);

		// Create real context
		this->windowHandle = std::static_pointer_cast<WindowAdapter>(window.getAdapter().lock())->getWindowHandle();
		this->device = GetDC(windowHandle);
		if (!this->device) {
			throw std::runtime_error("The device associated to that window cannot be used or there is not device.");
		}

		const int pixelAttribs[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, window.getVideoMode().getSamples() > 1 ? GL_TRUE : GL_FALSE, // Enable MSAA or not
			WGL_SAMPLES_ARB, window.getVideoMode().getSamples(), // Number of samples
			0
		};

		INT iPF;
		UINT num_formats_choosen;
		if (!wglChoosePixelFormat(this->device, pixelAttribs, NULL, 1, &iPF, &num_formats_choosen) || !num_formats_choosen) {
			throw std::runtime_error("There is no video mode available for this device.");
		}

		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(pfd));
		DescribePixelFormat(this->device, iPF, sizeof(pfd), &pfd);

		if (!SetPixelFormat(this->device, iPF, &pfd)) {
			std::cout << "PixelFormat: " << iPF << std::endl;
			throw std::runtime_error("The video mode cannot be used.");
		}

		const int glVersion[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
			WGL_CONTEXT_MINOR_VERSION_ARB, 6,
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};
		// TODO: deal with shared context, like for restarting window (MSAA requirements)
		this->context = wglCreateContextAttribs(this->device, nullptr, glVersion);
		if (this->context == nullptr) {
			throw std::runtime_error("The context cannot be created.");
		}
		if (wglMakeCurrent(this->device, this->context) == FALSE) {
			throw std::runtime_error("The created context cannot be used.");
		}
		
		const char * renderer = (char *)glGetString(GL_RENDERER);
		const char * version = (char *)glGetString(GL_VERSION);
		const char * shaderVersion = (char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
		ServiceLoggerLocator::getService().logInfo("Renderer: " + std::string(renderer));
		ServiceLoggerLocator::getService().logInfo("OpenGL version supported " + std::string(version));
		ServiceLoggerLocator::getService().logInfo("GLSL version supported " + std::string(shaderVersion));

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			ServiceLoggerLocator::getService().logError("OpenGL error: " + err);
		}
	}

	void ContextOpenGL::swapBuffers()
	{
		if (!SwapBuffers(this->device)) {
			ServiceLoggerLocator::getService().logError("Buffers not swapped !");
		}
	}
}