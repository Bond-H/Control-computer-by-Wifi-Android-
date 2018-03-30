#pragma hdrstop
#pragma argsused
#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <commctrl.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <string>
#pragma comment(lib, "Winmm.lib")
using namespace std;
int sound(string s){
IAudioEndpointVolume *m_pEndptVolCtrl;
IMMDeviceEnumerator *m_pEnumerator;
IMMDevice *m_pDevice;
	HRESULT hr = S_OK;

    // Initialize COM component
	hr = CoInitialize(NULL);

	if(FAILED(hr)){
		printf("CoInitialize failed");
		return 1;
	}

	// Create instance for MMDevices...
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator),
						NULL, CLSCTX_INPROC_SERVER,
						__uuidof(IMMDeviceEnumerator),
						(void**)&m_pEnumerator);
	if(FAILED(hr)){
		printf("CoCreateInstance failed");
		return 1;
	}

	// Get default Andio Endpoint
    hr = m_pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &m_pDevice);
	if(FAILED(hr)){
		printf("GetDefaultAudioEndpoint failed");
		return 1;
	}

	// Activate devices...
	hr = m_pDevice->Activate(__uuidof(IAudioEndpointVolume),
							CLSCTX_ALL, NULL,
							(void**)&m_pEndptVolCtrl);
	if(FAILED(hr)){
		printf("Activate failed");
		return 1;
	}
	float vol;

	m_pEndptVolCtrl->GetMasterVolumeLevelScalar(&vol);
	if(s=="volumeUp"&&vol<1.001)
	{
		vol+=0.05;
		if(vol<1.001)
			m_pEndptVolCtrl->SetMasterVolumeLevelScalar(vol,&GUID_NULL);
		else
			m_pEndptVolCtrl->SetMasterVolumeLevelScalar(1,&GUID_NULL);
	}
	else if(s=="volumeDown"&&vol>-0.001)
	{
		vol-=0.05;
		if(vol>-0.001)
			m_pEndptVolCtrl->SetMasterVolumeLevelScalar(vol,&GUID_NULL);
		else
			m_pEndptVolCtrl->SetMasterVolumeLevelScalar(0,&GUID_NULL);
	}
	CoUninitialize();
	return 0;
}
