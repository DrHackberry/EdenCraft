#ifndef VIDEOMODE_HPP
#define VIDEOMODE_HPP

#include "Core\Geom\Vector.hpp"
#include "Core\Window\Window.inl"

namespace ece
{
	class VideoMode
	{
	public:
		VideoMode();
		~VideoMode();

		void setRefreshRate(const unsigned short int refreshRate);
		void setColorBits(const ece::ColorRGBA & colorBits);
		void setDepthBits(const unsigned short int dephtBits);
		void setStencilBits(const unsigned short int stencilBits);
		void setSamples(const unsigned short int samples);
		void setDoubleBuffering(const bool doubleBuffering);
		void setSrgbCapable(const unsigned short int srgbCapable);

		unsigned short int getRefreshRate() const;
		ece::ColorRGBA getColorBits() const;
		unsigned short int getDepthBits() const;
		unsigned short int getStencilBits() const;
		unsigned short int getSamples() const;
		bool isDoubleBufferingActivate() const;
		unsigned short int getSrgbCapable() const;

	private:
		unsigned short int refreshRate;
		ece::ColorRGBA colorBits;
		unsigned short int depthBits;
		unsigned short int stencilBits;
		/* Deprecated
		ece::Vector<unsigned int, 4> accumColorBits;*/
		/* Deprecated
		unsigned short int auxBuffers;*/
		unsigned short int samples;
		bool doubleBuffering;
		unsigned short int srgbCapable;
	};
}

#endif // VIDEOMODE_HPP
