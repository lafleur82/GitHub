#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	//variables
	uint8_t octet1 = 0;
	uint8_t octet2 = 0;
	uint8_t octet3 = 0;
	uint8_t octet4 = 0;
	uint32_t fullIP = 0;

	printf("Enter an IP Address in dotted decimal format. \n(e.g. 172.16.142.97)\n");
	scanf("%hhu.%hhu.%hhu.%hhu", &octet1, &octet2, &octet3, &octet4);

	printf("%"PRIu8".%"PRIu8".%"PRIu8".%"PRIu8"\n", octet1, octet2, octet3, octet4);
	
	fullIP = fullIP | octet1;
	fullIP = fullIP << 8;
	printf("%08x \n", fullIP);

	fullIP = fullIP | octet2;
	fullIP = fullIP << 8;
	printf("%08x \n", fullIP);

	fullIP = fullIP | octet3;
	fullIP = fullIP << 8;
	printf("%08x \n", fullIP);

	fullIP = fullIP | octet4;

	printf("%02x%02x%02x%02x \n", octet1, octet2, octet3, octet4);

	printf("%08x \n", fullIP);


	getchar();
	return 0;
}