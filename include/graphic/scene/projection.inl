/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

//#include "glm\gtx\transform.hpp"
#include "utility/mathematics/transform.hpp"

namespace ece
{
	inline Projection::Projection() noexcept: _projection(FloatMatrix4u::Identity())
	{
		//this->projection = glm::perspective(20.0f, static_cast<float>(RATIO_4_3), 0.3f, 30.0f);
		this->_projection = ece::perspective(20.0f, static_cast<float>(RATIO_4_3), 0.3f, 30.0f);
	}

	inline void Projection::setProjection(const double FOV, const Ratio ratio, const double nearClipping, const double farClipping)
	{
		/*this->projection = glm::perspective(static_cast<float>(FOV),
											static_cast<float>(ratio),
											static_cast<float>(nearClipping),
											static_cast<float>(farClipping));*/
		this->_projection = ece::perspective(static_cast<float>(FOV),
											static_cast<float>(ratio),
											static_cast<float>(nearClipping),
											static_cast<float>(farClipping));
	}

	//inline const glm::mat4 & Projection::getProjection() const { return this->projection; }

	inline const FloatMatrix4u & Projection::getProjection() const { return this->_projection; }
}
