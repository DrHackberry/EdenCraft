#ifndef BASE_CONTEXT_OPENGL_HPP
#define BASE_CONTEXT_OPENGL_HPP

namespace ece
{
	class RenderWindow;

	class BaseContextOpenGL
	{
	public:
		BaseContextOpenGL() = default;
		BaseContextOpenGL(const BaseContextOpenGL & copy) = delete;
		BaseContextOpenGL(BaseContextOpenGL && move) = delete;

		inline virtual ~BaseContextOpenGL() = 0;

		BaseContextOpenGL & operator=(const BaseContextOpenGL & copy) = delete;
		BaseContextOpenGL & operator=(BaseContextOpenGL && move) = delete;

		virtual void create(const RenderWindow & window) = 0;
		virtual void swapBuffers() = 0;

		void logInfos();
	};
}

#include "renderer/opengl/base_context_opengl.inl"

#endif // BASE_CONTEXT_OPENGL_HPP
