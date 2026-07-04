#include <stdio.h>
int main()
{
	FILE *file = fopen("test.bin","rb");
	if(file == NULL)
	{
		printf("Error Opening file\n");
		return 1;

	}
	unsigned char byte;
	while (fread(&byte, 1, 1, file) == 1)
	{
		printf("0x%02X ", byte);
	}
	fclose(file);
	return 0;
}