#include "..\pch.h"
#include "ManhuntDiscord.h"

// required vars

int& CApp_ms_currLevelNum = *(int*)0x75A95C;
int& hunKil = *(int*)0x77B444;
int& hunExe = *(int*)0x77B4B4;


const char* GetLevelImage()
{
	switch (CApp_ms_currLevelNum)
	{
	case 0:
		return "0"; break;
	case 1:
		return "1"; break;
	case 2:
		return "2"; break;
	case 3:
		return "3"; break;
	case 4:
		return "4"; break;
	case 5:
		return "5"; break;
	case 6:
		return "6"; break;
	case 7:
		return "7"; break;
	case 8:
		return "8"; break;
	case 9:
		return "9"; break;
	case 10:
		return "10"; break;
	case 11:
		return "11"; break;
	case 12:
		return "12"; break;
	case 13:
		return "13"; break;
	case 14:
		return "14"; break;
	case 15:
		return "15"; break;
	}
}

const char* GetLevelName()
{
	switch (CApp_ms_currLevelNum)
	{
	case 0:
		return "Awakening"; break;
	case 1:
		return "Ghosts"; break;
	case 2:
		return "Sexual Deviants"; break;
	case 3:
		return "Red Light"; break;
	case 4:
		return "Best Friends"; break;
	case 5:
		return "Safe House"; break;
	case 6:
		return "Bees' Honey Pot"; break;
	case 7:
		return "Assassination"; break;
	case 8:
		return "Most Wanted"; break;
	case 9:
		return "Ritual Cleansing"; break;
	case 10:
		return "Origins"; break;
	case 11:
		return "Broadcast Interrupted"; break;
	case 12:
		return "Altered State"; break;
	case 13:
		return "Domestic Disturbance"; break;
	case 14:
		return "Personality Clash"; break;
	case 15:
		return "Release Therapy"; break;
	}
}

const char * GetStatus()
{
	char tmpBuffer[512];
	float health = *(float*)(*(int*)0x789490 + 0x7C);
	sprintf(tmpBuffer, "Health: %.1f", health);
	return tmpBuffer;
}

