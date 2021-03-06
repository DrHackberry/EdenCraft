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

#ifndef SERVICE_LOCATOR_HPP
#define SERVICE_LOCATOR_HPP

#include <memory>

namespace ece
{
	/**
	 * @class ServiceLocator
	 * @tparam Base The base class of the service to locate
	 * @tparam Null A default implementation for the service.
	 * @brief Encapsulate a unique instance of a service category.
	 */
	template <class Base, class Null>
	class ServiceLocator
	{
		static_assert(std::is_base_of<Base, Null>::value, "ServiceLocator cannot be instantiate with this template parameters.");

	public:
		/**
		 * @fn void provide(const std::shared_ptr<Base> & service)
		 * @param[in] service The service which has to be provided by the locator.
		 * @brief Set the service provided by the locator.
		 * @throw
		 */
		static inline void provide(const std::shared_ptr<Base> & service);

		/**
		 * @fn Base & getService()
		 * @return The service currently started.
		 * @brief Consume the service provided.
		 * @throw
		 * @remark Should be rename as consume() ?
		 */
		static Base & getService();

		//static std::weak_ptr<Base> getServicePtr();
		
		/**
		 * @fn void stop()
		 * @brief Stop the current service. The locator still exists but provide an empty service (which do nothing).
		 * @throw
		 */
		static inline void stop();

	protected:
		/**
		 * @property _service
		 * @brief The service to expose.
		 */
		static std::shared_ptr<Base> _service;
	};
}

#include "utility/service/service_locator.inl"

#endif // SERVICE_LOCATOR_HPP