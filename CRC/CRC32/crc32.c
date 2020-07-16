#include <stdio.h>
unsigned int CRC32(unsigned char T[]);

int main(void)
{
  //unsigned char T[] = {0xF0,0x00,0x00,0x00,0x00};
  unsigned char T[] = {0xF0,0x00,0x00,0x91,0xB6};
  printf("%d\n",0x6FBF1D91);
  printf("%ud\n",0x80000000);
  CRC32(T);
  return 0;
}

unsigned int CRC32(unsigned char T[])
{
  int i,j;
	unsigned int CRC = 0;
	unsigned char doxor = 0;
	unsigned int p = 0x04C11DB7;

	for(i = 0; i < sizeof(T)/sizeof(T[0]); i++)
	{
		for(j = 0x80000000; j > 0; j = j >> 1)
    {
			if(CRC & 0x80000000)
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
	printf("En decimal: %ud\n",CRC);
}
