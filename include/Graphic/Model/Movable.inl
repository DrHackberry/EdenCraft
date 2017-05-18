namespace ece
{
	inline Movable::Movable() : position{ 0.0f, 0.0f, 0.0f } {}

	inline Movable::~Movable() {}

	inline const FloatVertex3D & Movable::getPosition() const { return this->position; }
}