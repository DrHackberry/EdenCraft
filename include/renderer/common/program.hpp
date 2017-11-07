#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "renderer/opengl/opengl.hpp"
#include "renderer/common/shader.hpp"

namespace ece
{
	class Program
	{
	public:
		Program();
		Program(const Program & copy) = default;
		Program(Program && move) = default;

		~Program() = default;

		Program & operator=(const Program & copy) = default;
		Program & operator=(Program && move) = default;

		inline ProgramHandle getHandle() const;

		void addShader(Shader & shader);
		void link();
		void use();

		template<class T> void uniform(const std::string & uniform, const T & value);

	private:
		ProgramHandle handle;
	};
}

#include "renderer/common/program.inl"

#endif // PROGRAM_HPP
