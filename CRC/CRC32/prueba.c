#include<stdio.h>
unsigned int crc32b(unsigned char message[]);

int main(void)
{
  //unsigned char T[] = {0xF0,0x00,0x00,0x00,0x00};
  unsigned char T[] = {0xF0,0x00,0x00,0x91,0xB6};
  printf("En decimal: %d\n",crc32b(T));
  printf("En hexadecimal: 0x%x\n",crc32b(T));

  return 0;
}

unsigned int crc32b(unsigned char message[]) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0)
   {
      byte = message[i];
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--)
      {
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }

      i++;
   }

   return ~crc;
}
