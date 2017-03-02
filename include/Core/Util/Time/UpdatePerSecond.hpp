#ifndef UPDATEPERSECOND_HPP
#define UPDATEPERSECOND_HPP

#include "Util\Time\Chrono.hpp"

namespace ece
{
	class UpdatePerSecond
	{
	public:
		inline UpdatePerSecond(const int UPS);

		const bool isReadyToUpdate();

		inline const double getUPS() const;

	private:
		Chrono chrono;

		float rate;
		long int nbFrames;
		double average;
	};

}

#include "Util\Time\UpdatePerSecond.inl"

#endif // UPDATEPERSECOND_HPP