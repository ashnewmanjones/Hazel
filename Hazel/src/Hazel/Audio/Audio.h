#pragma once

#include "Hazel/Core.h"
#include "al.h"

namespace Hazel {

	class Audio
	{
	public:
		virtual void Init() = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static Audio* Create();
	};
}