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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

/**
 * @file utility/pattern/pimpl.inl
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 3rd 2017
 * @copyright ----------
 * @brief Implementation of the PIMPL idiom.
 **/

namespace ece
{
	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier>::Pimpl(Impl * impl, Deleter && deleter, Copier && copier) :
		impl(impl, std::forward<Deleter>(deleter)), copier(std::forward<Copier>(copier)) {}

	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier>::Pimpl(const Pimpl & copy) noexcept : Pimpl(copy.clone()) {}

	template <class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier> & Pimpl<Impl, Deleter, Copier>::operator=(const Pimpl & copy)
	{
		if (this != &copy) {
			operator=(copy.clone());
		}
		return *this;
	}

	template<class Impl, class Deleter, class Copier>
	const Impl * Pimpl<Impl, Deleter, Copier>::operator->() const noexcept { return this->impl.get(); }

	template<class Impl, class Deleter, class Copier>
	Impl * Pimpl<Impl, Deleter, Copier>::operator->() noexcept { return this->impl.get(); }

	template<class Impl, class Deleter, class Copier>
	Pimpl<Impl, Deleter, Copier> Pimpl<Impl, Deleter, Copier>::clone() const
	{
		if (this->impl) {
			return Pimpl(this->copier(this->impl.get()), this->impl.get_deleter(), this->copier);
		}
		else {
			return Pimpl(nullptr, this->impl.get_deleter(), this->copier);
		}
	}

	template<class Impl, class ...Args>
	Pimpl<Impl> makePimpl(Args && ...args) { return Pimpl<Impl>(new Impl(std::forward<Args>(args)...), &defaultDelete<Impl>, &defaultCopy<Impl>); }

	template<class Impl>
	void defaultDelete(Impl * impl) noexcept { delete impl; }

	template<class Impl>
	Impl * defaultCopy(Impl * impl) noexcept { return new Impl(*impl); }
}