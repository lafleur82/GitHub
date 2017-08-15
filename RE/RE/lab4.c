#include <Windows.h>
#include <stdio.h>

int callByName();
int callByOrdinal();

int main()
{
	callByName();
	callByOrdinal();
	getchar();
}

int callByName()
{
	HMODULE hm = NULL;
	int(__stdcall *dynamicFunction)() = NULL;
	int result = 0;

	if (NULL == (hm = LoadLibraryA("REDll_x86.dll")))
	{
		printf("Failed to load library! %d\n", GetLastError());
		return -1;
	}

	dynamicFunction = (int(__stdcall*)())GetProcAddress(hm, "ExportedByName");

	if (NULL == (dynamicFunction))
	{
		printf("Failed to find func %d\n", GetLastError());
		return -2;
	}

	result = dynamicFunction();
	FreeLibrary(hm);
	return result;
}

int callByOrdinal()
{
	HMODULE hm = NULL;
	int(__stdcall *dynamicFunction)() = NULL;
	int result = 0;

	if (NULL == (hm = LoadLibraryA("REDll_x86.dll")))
	{
		printf("Failed to load library! %d\n", GetLastError());
		return -1;
	}

	dynamicFunction = (int(__stdcall*)())GetProcAddress(hm, 1);

	if (NULL == (dynamicFunction))
	{
		printf("Failed to find func %d\n", GetLastError());
		return -2;
	}

	result = dynamicFunction();
	FreeLibrary(hm);
	return result;
}