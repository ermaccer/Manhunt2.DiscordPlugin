// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "discord/discord-rpc.h"
#include "MemoryMgr.h"
#include "code/ManhuntDiscord.h"
#include <time.h>
#pragma comment (lib,"discord\\discord-rpc.lib")

using namespace Memory::VP;

DiscordRichPresence drp = {};



void UpdatePresence()
{
	drp.largeImageKey = GetLevelImage();
	drp.largeImageText = GetLevelName();
	std::string kills = "Killed: " + std::to_string(*(int*)0x77B444) + " Executed: "+ std::to_string(*(int*)0x77B4B4);
	drp.details = kills.c_str();
	drp.state = GetStatus();

	Discord_UpdatePresence(&drp);
	((void(__cdecl*)())0x4B1870)();
}

void ShutdownPresence()
{
	Discord_Shutdown();
	((void(__cdecl*)())0x608700)();
}


void CancelInfo()
{
	drp.largeImageKey = "closed";
	drp.largeImageText = 0;
	drp.details = 0;
	drp.state = 0;
	Discord_UpdatePresence(&drp);
	((void(__cdecl*)())0x5F0020)();
	
}

void Init()
{
	Discord_Initialize("738043013166661683",0,0,0);

	drp.largeImageKey = "closed";
	drp.startTimestamp = time(0);
	Discord_UpdatePresence(&drp);
	InjectHook(0x5C4E2B, UpdatePresence, PATCH_CALL);
	InjectHook(0x4B1461, ShutdownPresence, PATCH_CALL);
	InjectHook(0x4B109A, CancelInfo, PATCH_CALL);
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		if (*(int*)0x63BC93 != 'hnaM')
		{
			MessageBoxA(0, "Invalid executable!", 0, 0);
		}
		else Init();
	}
}


