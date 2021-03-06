/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef PARSER_OBJ_HPP
#define PARSER_OBJ_HPP

#include "utility/file_system/parser.hpp"

#include <vector>

namespace ece
{
	// TODO add parser MKL

	/**
	 * @class ParserOBJ
	 * @extends Parser
	 * @brief A parser to load/save OBJ Wavefront structure from/to memory, file, or string.
	 * @remark The OBJ Wavefront structure is so much more complexe and should be refactored.
	 * @see Parser
	 */
	class ParserOBJ: public Parser
	{
	public:
		/**
		 * @fn ParserOBJ()
		 * @brief Unique constructor for a ParserOBJ. No OBJ is loaded.
		 * @throw
		 */
		inline ParserOBJ();

		/**
		 * @fn void loadFromFile(const std::string & filename)
		 * @param[in] filename The name of the file to load data from.
		 * @brief Load and parse data from a file.
		 * @see Parser::loadFromFile(const std::string & filename)
		 * @throw
		 */
		virtual void loadFromFile(const std::string & filename) override;

		/**
		 * @fn void loadFromString(const std::string & content)
		 * @param[in] content The string content to load data from.
		 * @brief Load and parse data from a string.
		 * @see Parser::loadFromString(const std::string & content)
		 * @throw
		 */
		virtual void loadFromString(const std::string & content) override;

		/**
		 * @fn void loadFromMemory(const void * content)
		 * @param[in] content The memory buffer to load data from.
		 * @brief Load and parse data from memory.
		 * @see Parser::loadFromMemory(const void * content)
		 * @throw
		 */
		virtual void loadFromMemory(const void * content) override;

		/**
		 * @fn void saveToFile(const std::string & filename)
		 * @param[out] filename The name of the file to save into.
		 * @brief Formate and save data into a file.
		 * @see Parser::saveToFile(const std::string & filename)
		 * @throw
		 */
		virtual void saveToFile(const std::string & filename) override;

		/**
		 * @fn void saveToString(std::string & content)
		 * @param[out] content The string buffer to save into.
		 * @brief Formate and save data into a string buffer.
		 * @see saveToString(std::string & content)
		 * @throw
		 */
		virtual void saveToString(std::string & content) override;

		/**
		 * @fn void saveToMemory(void * content)
		 * @param[out] content The memory to save into.
		 * @brief Formate and save data into memory.
		 * @see Parser::saveToMemory(void * content)
		 * @throw
		 */
		virtual void saveToMemory(void * content) override;

		/**
		 * @fn const std::vector<float> & getVertices()
		 * @return The list of vertices of the current OBJ loaded.
		 * @brief An accessor for the list of vertices of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this method will be changed.
		 * @throw
		 */
		inline const std::vector<float> & getVertices();

		/**
		 * @fn const std::vector<float> & getTextures()
		 * @return The texture mapping of the current OBJ loaded.
		 * @brief An accessor for the texture mapping of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this method will be changed.
		 * @throw
		 */
		inline const std::vector<float> & getTextures();

		/**
		 * @fn const std::vector<float> & getNormales()
		 * @return The list of normales of the current OBJ loaded.
		 * @brief An accessor for the list of normales of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this method will be changed.
		 * @throw
		 */
		inline const std::vector<float> & getNormales();

		/**
		 * @fn const std::vector<int> & getFaces()
		 * @return The list of faces of the current OBJ loaded.
		 * @brief An accessor for the list of faces of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this method will be changed.
		 * @throw
		 */
		inline const std::vector<int> & getFaces();

	private:
		/**
		 * @property _vertices
		 * @brief The list of vertices of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this property will be changed.
		 */
		std::vector<float> _vertices;

		/**
		 * @property _textures
		 * @brief The texture mapping of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this property will be changed.
		 */
		std::vector<float> _textures;

		/**
		 * @property _normales
		 * @brief The list of normales of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this property will be changed.
		 */
		std::vector<float> _normales;

		/**
		 * @property _faces
		 * @brief The list of faces of the current OBJ loaded.
		 * @remark As the structure of an OBJ Wavefront file is so much more complex, this property will be changed.
		 */
		std::vector<int> _faces;
	};
}

#include "utility/file_system/parser_obj.inl"

#endif // PARSER_OBJ_HPP
