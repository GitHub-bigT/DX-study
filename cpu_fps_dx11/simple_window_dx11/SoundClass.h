#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>

class SoundClass
{
private:
	struct WaveHeaderType
	{
		char chunkId[4];
		unsigned long chunkSize;
		char format[4];
		char subChunkId[4];
		unsigned long subChunkSize;
		unsigned short audioFormat;
		unsigned short numChannels;
		unsigned long sampleRate;
		unsigned long bytesPerSecond;
		unsigned short blockAlign;
		unsigned short bitsPerSample;
		char dataChunkId[4];
		unsigned long dataSize;
	};
public:
	SoundClass();
	~SoundClass();
	bool init(HWND);
	void stop();

private:
	bool initDirectSound(HWND);
	void stopDirectSound();

	bool loadWaveFile(char*, IDirectSoundBuffer8**);
	void stopWaveFile(IDirectSoundBuffer8**);

	bool playWaveFile();

private:
	IDirectSound8 *m_directSound;
	IDirectSoundBuffer *m_primaryBuffer;
	IDirectSoundBuffer8* m_secondaryBuffer1;
};