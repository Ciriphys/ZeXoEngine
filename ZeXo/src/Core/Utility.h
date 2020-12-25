#pragma once

#include "zxpch.h"

namespace ZeXo
{
	template <typename T>
	using Unique = std::unique_ptr<T>;

	template<typename T>
	static Unique<T> CreateUnique(T* val)
	{
		return Unique<T>(val);
	}

	template <typename T>
	using Shared = std::shared_ptr<T>;

	template<typename T>
	static Shared<T> CreateShared(T* val)
	{
		return Shared<T>(val);
	}

	template <typename T>
	using Weak = std::weak_ptr<T>;

	template<typename T>
	static Weak<T> CreateWeak(T* val)
	{
		return Weak<T>(val);
	}
}