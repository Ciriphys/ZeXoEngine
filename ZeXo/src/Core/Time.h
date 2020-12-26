#pragma once

#include "Macro.h"

namespace ZeXo
{
	class ZX_API Time 
	{
	public:
		Time(float deltaTime) : m_DeltaTime(deltaTime) { }

		inline double GetDeltaTime() const { return m_DeltaTime; }
		inline void SetDeltaTime(double deltaTime) { m_DeltaTime = deltaTime; }
	private:
		double m_DeltaTime;
	};

}