#pragma once

#include "Macro.h"

#include "Layer.h"

namespace ZeXo
{
	class ZX_API LayerContainer
	{
	public:
		LayerContainer();

		LayerContainer(const LayerContainer&) = delete;
		LayerContainer& operator=(const LayerContainer&) = delete;

		void AddLayer		(Layer * layer);
		void AddOverlay		(Layer * overlay);
		void RemoveLayer	(Layer * layer);
		void RemoveOverlay	(Layer * overlay);

		inline std::vector<Layer*>::iterator				 begin()	    { return m_LayerContainer.begin();   }
		inline std::vector<Layer*>::const_iterator			cbegin() const  { return m_LayerContainer.cbegin();  }
		inline std::vector<Layer*>::reverse_iterator		rbegin()		{ return m_LayerContainer.rbegin();  }
		inline std::vector<Layer*>::const_reverse_iterator crbegin() const  { return m_LayerContainer.crbegin(); }

		inline std::vector<Layer*>::iterator				 end()		 { return m_LayerContainer.end();   }
		inline std::vector<Layer*>::const_iterator			cend() const { return m_LayerContainer.cend();  }
		inline std::vector<Layer*>::reverse_iterator		rend()		 { return m_LayerContainer.rend();  }
		inline std::vector<Layer*>::const_reverse_iterator crend() const { return m_LayerContainer.crend(); }

		static LayerContainer * Get();

	private:
		static LayerContainer * s_LayerHandler;

		unsigned int m_LayerIndex;
		std::vector<Layer*> m_LayerContainer;
	};
}