#include <stdio.h>
int main()
{
	FILE* file = fopen("test.bin", "rb");
	if (file == NULL)
	{
		printf("Error Opening file\n");
		return 1;
	}
	unsigned char byte;
	while ((fread(&byte, 1, 1, file)) == 1)
	{
		printf("0x%02X\n", byte);
		if (byte == 0x55)
		{
			printf("0x55:Push Stack Base Pointer push rbp\n");
		}
		else if (byte == 0x5D)
		{
			printf("0x5D:Pop Stack Base Pointer pop rbp\n");
		}
		else if (byte == 0xC3)
		{
			printf("0xC3:Return from Function ret\n");
		}
		else if (byte == 0x90)
		{
			printf("0x90:No Opreation nop\n");
		}
		else if (byte == 0xE8)
		{
			printf("0xE8:Call a function , call \n");
		}
		else if (byte == 0xE9)
		{
			printf("0xE9:Unconditional Jump , jmp \n ");
		}
	}
}