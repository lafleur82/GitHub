
int main() 
{
	char * str = "This is a test string.";
	char * str2;
	int len = strlen(str);

	if (len > 0)
	{
		str2 = malloc(len);

		if (str2) 
		{
			str2 = memset(str2, 0, len);
		}
		else
		{
			printf("Out of memory!\n");
		}
	}
	else
	{
		printf("Failed!");
	}

	printf(str2);
	free(str2);
}