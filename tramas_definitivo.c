/* INSTITUTO POLITECNICO NACIONAL
ESCUELA SUPERIOR DE COMPUTO
Redes de Computadoras I
Profesora Cortéz Duarte Nidia Asunción
Ricardo Alcaraz Fraga
2CM6

OBSERVACIONES:
--> Este código únicamente analiza las tramas que se ingresen, no se encarga de
construirlas
--> Que la trama esté bien construida es responsabilidad del usuario
--> Debe seguirse estrictamente el protocolo planteado en clase */
#include <stdio.h>
int CheckSum(unsigned char T[]);
void Codigo_Linea(unsigned char c);
void Medio_CF_CE_Enrut(unsigned char c);
void Origen(unsigned char c);
void Destino(unsigned char c);
void Mensaje(unsigned char c);
void AnalizarTrama(unsigned char T[]);
int ContadordeUnos(unsigned char T[]);
unsigned int CRC(unsigned char T[]);

unsigned char T[] = {0x88,0x1C,0xC9,0x50,0xBD,0x42,0x6F,0x6E,0x6A,0x6F,0x75,0x72,0x4C};
//unsigned char T[] = {0x05,0xC6,0xCF,0XDB,0X48,0X48,0X69,0X21,0x78};
unsigned char g[][5] = {"UTP","OPT","COAX"};
unsigned char ng[][5] = {"","BT","WIFI","SAT"};
unsigned char idioma[][4] = {"ING","ESP","FR","JAP"};
char band;
unsigned char i,j,tam;
int unos = 0;

int main(void)
{
  tam = sizeof(T)/sizeof(unsigned char);
  AnalizarTrama(T);

  return 0;
}

/* Esta función está encargada de Analizar la Trama que recibe, mandando a llamar a
todas las demás funciones que, por byte, analizan la trama
RECIBE: Una trama 'T' -> arreglo de caracteres sin signo
REGRESA: void */
void AnalizarTrama(unsigned char T[])
{
  ContadordeUnos(T);
  Codigo_Linea(T[0]);
  Medio_CF_CE_Enrut(T[1]);
  Origen(T[2]);
  Destino(T[3]);
  Mensaje(T[4]);
}

/* Esta función está encargada de determinar qué codigo de línea sigue la transmisión
de la trama que recibe
RECIBE: Un byte de una trama 'T'
REGRESA: void */
void Codigo_Linea(unsigned char c)
{
  printf("Codigo de Linea: ");
  if(c & 128)
    printf("Unipolar ");
  if(c & 64)
    printf("Bipolar ");
  if(c & 32)
    printf("Polar ");
  if(c & 16)
    printf("NRZ ");
  if(c & 8)
    printf("RZ ");
  if(c & 4)
    printf("Diferencial ");
  if(c & 2)
    printf("No Diferencial ");
  if(c & 1)
    printf("Manchester ");
  printf("\n");
}

/* Esta función determina qué Medio de Transmisión, Control de Flujo, Control de
Errores y Enrutamiento sigue la trama que recibe
RECIBE: Un byte de una trama 'T'
REGRESA: void */
void Medio_CF_CE_Enrut(unsigned char c)
{
  /////////// MEDIO DE TRANSMISION//////////////
  // Si es no guiado
  if(c & 128)
    printf("Medio: %s\n",ng[(c >> 5) & 3]);

  // Si es guiado
  else
    printf("Medio: %s\n",g[(c >> 5) & 3]);

  /////////// CONTROL DE FLUJO //////////////
  switch(c & 16)
  {
    case 1:
    printf("Control de Flujo: Ventana Deslizante\n");
    break;

    case 0:
    printf("Control de Flujo: Parar y Esperar\n");
    break;
  }

  /////////// CONTROL DE ERRORES //////////////
  switch((c >> 2) & 3)
  {
    case 1:
    printf("Control de Errores: Checksum\n");
    printf("CheckSum: %x\n",CheckSum(T));
    break;

    case 2:
    printf("Control de Errores: Bit de Paridad\n");
    switch(T[tam-1] & 1)
    {
      case 0:
      printf("Bit de Paridad 0\n");
      if(unos % 2 == 0)
        printf("Trama Incorrecta :(\n");
      else
        printf("Trama Correcta (:\n");
      break;

      case 1:
      printf("Bit de Paridad 1\n");
      if(unos % 2 == 0)
        printf("Trama Correcta :(\n");
      else
        printf("Trama Incorrecta (:\n");
      break;

    }

    break;

    case 3:
    printf("Control de Errores: CRC\n");
    printf("CRC - 32: %ud\n",CRC(T));
    if(T[tam-1] == unos)
      printf("Conteo de Unos: Correcta :)\n");

    else
      printf("Conteo de Unos: Incorrecta ):\n");

    break;
  }

  /////////// ENRUTAMIENTO //////////////
  if(c & 2)
    printf("Enrutamiento: Estatico\n");
  else
    printf("Enrutamiento: Dinamico\n");
}

/* Esta función analiza el origen de la trama que recibe, imprimiendo el grupo de
origen y el número de lista de origen
RECIBE: Un byte de una trama 'T'
REGRESA: void */
void Origen(unsigned char c)
{
  /////////// GRUPO DE ORIGEN //////////////
  if(((c >> 6) & 3) == 3)
    printf("Grupo de Origen: 2CM6\n");
  else if(((c >> 6) & 3) == 2)
    printf("Grupo de Origen: 3CM2\n");
  else if(((c >> 6) & 3) == 1)
    printf("Grupo de Origen: 4CM1\n");

  /////////// NUMERO DE LISTA DE ORIGEN //////////////
  printf("Numero de Lista de Origen: %d\n",c & 63);

}
/* Esta función analiza el destino de la trama que recibe, imprimiendo el grupo de
destino y el número de lista de destino
RECIBE: Un byte de una trama 'T'
REGRESA: void*/
void Destino(unsigned char c)
{
  /////////// GRUPO DE DESTINO //////////////
  if(((c >> 6) & 3) == 3)
    printf("Grupo de Destino: 2CM6\n");
  else if(((c >> 6) & 3) == 1)
    printf("Grupo de Destino: 3CM2\n");
  else if(((c >> 6) & 3) == 2)
    printf("Grupo de Destino: 4CM1\n");

  /////////// NUMERO DE LISTA DE ORIGEN //////////////
  printf("Numero de Lista de Destino: %d\n",c & 63);
}

/* Esta función se hace cargo de analizar el byte del mensaje, determina el lenguaje,
el tamaño (tomando en cuenta el padding de la trama), el tamaño del mensaje, si está
o no fragmentado, qué número de secuencia tiene y el mensaje como tal (con el padding)
RECIBE: Un byte de una trama 'T'
REGRESA: void*/
void Mensaje(unsigned char c)
{
  /////////// IDIOMA DEL MENSAJE //////////////
  printf("Idioma del Mensaje: %s\n", idioma[(c >> 6) & 6]);

  /*Para el tamaño del mensaje se toma en cuenta que cada unidad de tamaño establecida
  en el protocolo es de 3 bytes, por lo cual el tamaño del mensaje debe ser múltiplo de 3 */

  // Si el módulo del tamaño con 3 es igual a 0, no se debe añadir padding
  if((tam-6) % 3 == 0)
  {
    printf("Tamano del Mensaje: %d bytes\n", ((c >> 3) & 7) * 3);
    band = -1;
  }

  // Si el módulo del tamaño con 3 es igual a 1, se deben añadir 2 unidades de padding al mensaje
  else if((tam-6) % 3 == 1)
  {
    printf("Tamano del Mensaje: %d bytes\n",(((c >> 3) & 7) + 2) * 3);
    band = 2;
  }

  // Si el módulo del tamaño con 3 es igual a 2, se debe añadir 1 unidad de padding al mensaje
  else if((tam-6) % 3 == 2)
  {
    printf("Tamano del Mensaje: %d bytes\n",(((c >> 3) & 7) + 1) * 3);
    band = 1;
  }

  /////////// FRAGMENTADO //////////////
  if(c & 4)
    printf("Fragmentado: Si\n");

  else
    printf("Fragmentado: No\n");

  /////////// Numero de Secuencia //////////////
  printf("Numero de secuencia: %d\n",c & 3);

  /////////// Contenido del Mensaje //////////////
  printf("Mensaje: ");
  for(i = 0; i < tam-6; i++)
    printf("%c",T[i+5]);

  /* Impresión del Padding con ayuda de la bandera band, que determina cuánto padding
  se debe añadir */
  for(i = 0; i < band; i++)
    printf("_");

  printf("\n");
}

/* Esta función cuenta los 1's totales de una trama
RECIBE: Una trama 'T' -> arreglo de caracteres sin signo
REGRESA: El total de 1's de la trama que recibe */
int ContadordeUnos(unsigned char T[])
{
  for(i = 0; i < tam - 2; i++)
  {
    for(j = 255; j > 0; j = j >> 1)
    {
      if(T[i] & j)
        unos++;
    }
  }

  printf("Cantidad de unos: %d\n",unos);
}

/* Esta función realiza el control de errores por Checksum
RECIBE: Una trama 'T' -> arreglo de caracteres sin signo
REGRESA: El valor del checksum realizado */
int CheckSum(unsigned char T[])
{
  int x = 0;
  for(i = 0; i < tam-2; i++)
    x += (T[i]<<8)+T[i+1];

  return (~((x>>16) + (x & 0xFFFF)) & 0xFFFF);
}

unsigned int CRC(unsigned char T[]) {
   int i, j;
   unsigned int byte, crc, mask;
   i = 0;
   crc = 0xFFFFFFFF;
   while (T[i] != 0)
   {
      byte = T[i];
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
