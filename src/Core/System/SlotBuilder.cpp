#include "Core\System\SlotBuilder.hpp"

namespace ece
{
	std::shared_ptr<Slot> SlotBuilder::makeSlot(const std::function<void()>& action)
	{
		return std::shared_ptr<Slot>(new Slot(action));
	}
}
