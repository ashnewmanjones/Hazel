#include "hzpch.h"

#include "OpenALAudio.h"
#include "alc.h"

namespace Hazel
{
	OpenALAudio::OpenALAudio()
	{
		this->Init();
	}

	OpenALAudio::~OpenALAudio()
	{
		alDeleteBuffers(1, &m_Buffers);
		this->Unbind();
		alcDestroyContext(m_Context);
		alcCloseDevice(m_Device);
	}

	void OpenALAudio::Bind()
	{
		alcMakeContextCurrent(m_Context);
	}

	void OpenALAudio::Unbind()
	{
		alcMakeContextCurrent(NULL);
	}

	void OpenALAudio::Init()
	{
		ALenum error;
		m_Device = alcOpenDevice(NULL);

		if (m_Device) {
			m_Context = alcCreateContext(m_Device, NULL);
			alcMakeContextCurrent(m_Context);
		}

		alGenBuffers(1, &m_Buffers);

		if (error = alGetError() != AL_NO_ERROR)
		{
			alDeleteBuffers(1, &m_Buffers);
			HZ_CORE_ASSERT(error, "Error creating buffer {0}");
		}
		
		HZ_CORE_INFO("Buffer Created");
	}
}