#include<stdio.h>
unsigned char CRC8(unsigned char T[]);

int main(void)
{
	unsigned char T[] = {0x44, 0x61, 0x6e, 0x00};
	CRC8(T);
	return 0;
}

unsigned char CRC8(unsigned char T[])
{
	unsigned char i,j;
	unsigned char CRC = 0x00;
	unsigned char doxor = 0;
	unsigned char p = 0x1B;

	for(i = 0; i < sizeof(T)/(sizeof(unsigned char)*2); i++)
	{
		for(j = 0x80; j > 0; j = j>>1)
		{
			if(CRC & 0x80)
				doxor = 1;

			CRC = CRC << 1;

			if(T[i] & j)
				CRC = CRC | 1;

			if(doxor == 1)
			{
				CRC = CRC ^ p;
				doxor = 0;
			}
		}
	}

	printf("En hexadecimal: 0x%x\n",CRC);
	printf("En decimal: %d\n",CRC);
}
