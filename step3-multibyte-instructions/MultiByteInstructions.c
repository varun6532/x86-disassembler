#include <stdio.h>
int main()
{
	FILE* file = fopen("test.bin", "rb");
	if (file == NULL)
	{
		printf("Error Opening the file!");
		return 1;
	}
	unsigned char byte;
	while (fread(&byte, 1, 1, file) == 1)
	{
		if (byte == 0xB8)
		{
			unsigned char arr[4];
			fread(&arr, 1, 4, file);
			int value = arr[0] + (arr[1] << 8) + (arr[2] << 16) + (arr[3] << 24);
			printf("0xB8:MOV EAX , %d\n", value);
		}
	}
	fclose(file);
	return 0;
}