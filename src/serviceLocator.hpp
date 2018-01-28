#pragma once 

#include "stdafx.hpp"
#include "IAudioProvider.hpp"

class serviceLocator{
public:
	static IAudioProvider* getAudio() { return _audioProvider; } const

	static void registerServiceLocator(IAudioProvider *provider){
		_audioProvider = provider; 
	}

private:
	static IAudioProvider* _audioProvider;
};
