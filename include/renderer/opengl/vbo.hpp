/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooo.                               .o8                                        
															`888   `Y88.                            "888                                        
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b 
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P 
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888     
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888     
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b   
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef VBO_HPP
#define VBO_HPP

#include "renderer/opengl/opengl.hpp"

namespace ece
{
	/**
	 * @class VBO
	 * @brief A vertex buffer object as defined in OpenGL
	 */
	class VBO
	{
	public:
		inline VBO(const BufferType type);

		/**
		 * @fn VBO()
		 * @brief Default constructor.
		 * @throw
		 */
		VBO();

		/**
		 * @fn VBO(const VBO & copy) noexcept
		 * @param[in] copy The VBO to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		VBO(const VBO & copy) noexcept = default;

		/**
		 * @fn VBO(VBO && move) noexcept
		 * @param[in] move The VBO to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		VBO(VBO && move) noexcept = default;

		/**
		 * @fn ~VBO()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~VBO() noexcept = default;

		/**
		 * @fn VBO & operator=(const VBO & copy) noexcept
		 * @param[in] copy The VBO to copy from.
		 * @return The VBO copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		VBO & operator=(const VBO & copy) noexcept = default;

		/**
		 * @fn VBO & operator=(VBO && move) noexcept
		 * @param[in] move The VBO to move.
		 * @return The VBO moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		VBO & operator=(VBO && move) noexcept = default;

		/**
		 * @fn void bind()
		 * @brief Put the VBO in a buffer to be used.
		 * @throw
		 */
		inline void bind();

		/**
		 * @fn void bufferData(const std::vector<T> & data, const BufferUsage usage)
		 * @tparam T The type of data to set.
		 * @param[in] data The data to set.
		 * @param[in] usage The kind of usage the buffer.
		 * @brief Set data in the VBO.
		 */
		template<class T> void bufferData(const std::vector<T> & data, const BufferUsage usage);

		/**
		 * @fn void setType(const BufferType type)
		 * @param[in] type The type to set.
		 * @brief Change the type of buffer.
		 * @throw
		 */
		inline void setType(const BufferType type);

		/**
		 * @fn Handle getHandle() const
		 * @return The id of the VBO.
		 * @brief Get the id of the VBO.
		 * @throw
		 */
		inline Handle getHandle() const;

	private:
		/**
		 * @property _handle
		 * @brief The id of the VBO.
		 */
		Handle _handle;

		/**
		 * @property _type
		 * @brief The type of VBO to use.
		 */
		BufferType _type;
	};
}

#include "renderer/opengl/vbo.inl"

#endif // VBO_HPP
