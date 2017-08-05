#ifndef COMPONENTTANK_HPP
#define COMPONENTTANK_HPP

#include "ECS\BaseComponent.hpp"
#include "Indexing\UniqueID.hpp"

#include <memory>
#include <vector>

namespace ece
{
	class ComponentTank
	{
	public:
		inline ComponentTank();
		inline ~ComponentTank();

	private:
		UniqueID nextComponent;
	};
}

#include "ECS\ComponentTank.inl"

#endif // COMPONENTTANK_HPP
