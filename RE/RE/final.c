#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	HMODULE hm = NULL;
	int(__stdcall *func_0)(char*) = NULL;
	int(__stdcall *func_1)(char*) = NULL;
	int(__stdcall *func_2)(char*) = NULL;
	int(__stdcall *func_3)(char*, int) = NULL;
	char*(__stdcall *func_4)(char*, int) = NULL;
	int(__stdcall *func_Bonus)(char*, char*) = NULL;
	int result = 0;
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	int result4 = 0;
	int resultBonus = 0;

	if (NULL == (hm = LoadLibraryA("C:\\Users\\DOTlaptop\\Desktop\\Test\\test_x86.dll")))
	{
		return -1;
	}

	func_0 = (int(__stdcall*)(char*))GetProcAddress(hm, (char*)1);
	if (NULL == func_0)
	{
		return -2;
	}

	func_1 = (int(__stdcall*)(char*))GetProcAddress(hm, (char*)2);
	if (NULL == func_1)
	{
		return -2;
	}

	func_2 = (int(__stdcall*)(char*))GetProcAddress(hm, (char*)3);
	if (NULL == func_2)
	{
		return -2;
	}

	func_3 = (int(__stdcall*)(char*, int))GetProcAddress(hm, (char*)4);
	if (NULL == func_3)
	{
		return -2;
	}

	func_4 = (char*(__stdcall*)(char*, int))GetProcAddress(hm, (char*)5);
	if (NULL == func_4)
	{
		return -2;
	}

	func_Bonus = (int(__stdcall*)(char*, char*))GetProcAddress(hm, (char*)6);
	if (NULL == func_Bonus)
	{
		return -2;
	}
	
	//__debugbreak();
	result = func_0("C:\\Users\\DOTlaptop\\Desktop\\test\\test.txt");
	printf("%s\n", result);
	
	char string1[23] = "Guvf vf n ebg13 fgevat";
	printf("String before: %s\n", string1);
	//__debugbreak();
	result1 = func_1(string1);
	printf("Result returns: %d\n", result1);
	printf("String after: %s\n", string1);
	
	char * chr = "A";
	printf("string: %s\n", chr);
	//__debugbreak();
	result2 = func_2(chr);
	printf("Result: %d\n", result2);
	
	char buf3[13] = { "one two three" };
	//__debugbreak();
	result3 = func_3(buf3, 13);
	printf("%d\n", result3);
	
	char string4[] = "VGVzdCBzdHJpbmc="; // base64 encoded "Test string"
	printf("string4: %s\n", string4);
	//__debugbreak();
	result4 = func_4(string4, 17);
	printf("%s\n", result4);
	
	char * num1 = "1";
	char * num2 = "1";
	__debugbreak();
	resultBonus = func_Bonus("", "");
	
	getchar();
	return 0;
}