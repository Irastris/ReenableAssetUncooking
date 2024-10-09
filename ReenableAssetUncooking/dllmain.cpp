#include "pch.h"

#include "memorymgr.h"
#include "patterns.h"
#include "utils.h"
#include <string>

constexpr const char* ASI_VERSION = "1.0";

const char* pJumpIfCooked = "74 1A 45 8D ? ? 48 8D 15 ? ? ? ? 48 8D 4D ? FF 15 ? ? ? ? E9";

using namespace Memory::VP;

bool DisableCookedDataCheck()
{
	uint64_t* pattern = FindPattern(GetModuleHandleA("UnrealEditor-UnrealEd.dll"), pJumpIfCooked);
	if (!pattern) return false;
	uint64_t address = (uint64_t)pattern;
	Patch<uint8_t>(GetGameAddr(address), 0xEB);
	return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		if (!DisableCookedDataCheck())
		{
			MessageBoxA(NULL, "Instruction to patch was not found in executable memory, patching has been skipped.", "ReenableAssetUncooking", MB_ICONEXCLAMATION);
			return false;
		}
		else
		{
			MessageBoxA(NULL, "Instruction patched, asset uncooking has been reenabled!", "ReenableAssetUncooking", MB_ICONEXCLAMATION);
		}
	}
	return true;
}
