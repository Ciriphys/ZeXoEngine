#pragma once

#include "Macro.h"

#include "Events/Event.h"

namespace ZeXo
{
	class ZX_API Layer
	{
	public:
		Layer(const char * layerName) : m_LayerName(layerName) {}

		virtual void Event(Event& e) = 0;
		virtual void BeginLayer() = 0;
		virtual void EndLayer() = 0;
		virtual void Tick() = 0; // Todo : Add time

		inline const char* GetLayerName() const { return m_LayerName; }

	private:
		const char* m_LayerName;
	};

}