// MuteToggle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>

void Usage(){
	printf("\n\n\nThis program will toggle the mute status of the system\nDepending on the current state\n\n");
	printf("Usage: MuteToggle <volume level>");
	printf("<volume level> should be a number between 0 and 100\n\tThis is used for the volume level to set when the system is unmuted\n\n\n");
}


int main(int argc, char* argv[])
{

	HRESULT hr;
	BOOL IsMute = false;
	double newVolume = 0.25;
	int vol = 0;
	
	//Validate the program is being used correctly
	//Checks if argument(desired volume) is used, within limit, and is a valid digit
	if (argc != 2){
		Usage(); return 0;
	}
	else if (sscanf(argv[1], "%i", &vol) != 1){
		Usage(); return 0;
	}else if (vol < 0 || vol > 100){
		Usage(); return 0;
	}else{
		vol = atoi(argv[1]);
		newVolume = (double)vol / 100;
	}


	CoInitialize(NULL);
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);

	IMMDevice *defaultDevice = NULL;
	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	defaultDevice = NULL;

	//Get mute state for default device
	endpointVolume->GetMute(&IsMute);
	printf("Mute status: %d\n", IsMute);

	if(!IsMute){
		//Set mute state to true
		hr = endpointVolume->SetMute(true, NULL);
		printf("MUTED\n");
	}else if(IsMute){
		//Set mute state to false and set volume to 25
		hr = endpointVolume->SetMute(false, NULL);
		printf("UNMUTED and volume set\n");
		hr = endpointVolume->SetMasterVolumeLevelScalar((float)newVolume, NULL);
	}

	endpointVolume->Release();

	CoUninitialize();

	return 0;
}

