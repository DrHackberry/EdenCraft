namespace ece
{
	inline std::weak_ptr<Resource> ResourceHandler::operator->() { return this->resource; }
}