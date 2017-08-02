#ifndef RESOURCEUNLOADER_HPP
#define RESOURCEUNLOADER_HPP

#include "Resource\ResourceHandler.hpp"

namespace ece
{
	class ResourceUnloader
	{
	public:
		ResourceUnloader() = default;
		ResourceUnloader(const ResourceUnloader & copy) = default;
		ResourceUnloader(ResourceUnloader && move) = default;

		inline virtual ~ResourceUnloader() = 0;

		ResourceUnloader & operator=(const ResourceUnloader & copy) = default;
		ResourceUnloader & operator=(ResourceUnloader && move) = default;

		virtual void unload(ResourceHandler & handler) const = 0;
	};
}

#include "Resource\ResourceUnloader.inl"

#endif // RESOURCEUNLOADER_HPP