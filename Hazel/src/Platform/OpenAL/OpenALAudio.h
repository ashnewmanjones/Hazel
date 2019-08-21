#pragma once

#include "Hazel/Audio/Audio.h"
#include "alc.h"
#include "al.h"

namespace Hazel {

	class OpenALAudio : public Audio
	{
	public:
		OpenALAudio();
		virtual ~OpenALAudio();
		virtual void Init() override;

		virtual void Bind() override;
		virtual void Unbind() override;
	private:
		ALCdevice* m_Device;
		ALCcontext* m_Context;
		ALuint m_Buffers;
	};
}