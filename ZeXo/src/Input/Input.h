#pragma once

#include "Core/Macro.h"

#include "Keycodes.h"

namespace ZeXo
{
	class ZX_API Input
	{
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		bool GetKey(int key);
		bool GetKeyPress(int key);
		bool GetKeyRelease(int key);

		bool GetMouseButtonPress(int button);
		bool GetMouseButtonRelease(int button);

		int GetKeyScancode(int key) const;
		const char* GetKeyName(int key);

		static Input * Get();

	private:
		Input();
		static Input * s_InputHandler;
	};

}