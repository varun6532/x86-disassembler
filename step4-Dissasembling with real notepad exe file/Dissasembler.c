#include <stdio.h>
int main()
{
	FILE* file = fopen("notepad.exe", "rb");
	if (file == NULL)
	{
		printf("Error Opening File!");
		return 1;
	}
	unsigned char byte;
	unsigned char arr[4];
	while (fread(&byte, 1, 1, file) == 1)
	{
		if (byte == 0xB8)
		{
			fread(&arr, 1, 4, file);
			int value = arr[0] + (arr[1] << 8) + (arr[2] << 16) + (arr[3] << 24);
			printf("0xB8: MOV EAX , %d ", value);
		}
		else if (byte == 0x55)
		{
			printf("0x55:Push stack base pointer onto stack ,PUSH RBP\n");
		}
		else if (byte == 0x58)
		{
			printf("0x58: Pop Base poiunter off the stack, POP RBP\n");
		}
		else if (byte == 0xC3)
		{
			printf("0xC3: Return , ret\n");
		}
		else if (byte == 0x90)
		{
			printf("0x90: Nothing no statement!\n");
		}
		else if (byte == 0xE8)
		{
			printf("0xE8: Call a function, call\n");
		}
		else if (byte == 0xE9)
		{
			printf("0xE9: Uncoditional Jump , imp\n");

		}
		else if (byte == 0xCC)
		{
			printf("0xCC: Breakpoint Trap!\n");
		}

	}
	fclose(file);
	return 0;

}