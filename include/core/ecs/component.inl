namespace ece
{
	template<class T>
	Component<T>::Component() : BaseComponent(), value() {}

	template<class T>
	Component<T>::~Component() {}

	template<class T>
	const T & Component<T>::get() { return this->value; }

	template<class T>
	void Component<T>::set(const T & value) { this->value = value; }
}