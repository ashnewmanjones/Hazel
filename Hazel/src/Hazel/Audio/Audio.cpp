#include "hzpch.h"

#include "Audio.h"
#include "Platform/OpenAL/OpenALAudio.h"

namespace Hazel {

	Audio* Audio::Create()
	{
		//TODO: Create api to choose platform
		return new OpenALAudio();
	}
}