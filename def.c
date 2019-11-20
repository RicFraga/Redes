/* INSTITUTO POLITECNICO NACIONAL
ESUCELA SUPERIOR DE COMPUTO
Redes de Computadoras
2CM6
Ricardo Alcaraz Fraga */
#include <stdio.h>
#include <stdlib.h>

char UC[][6] = {"UI", "SIM", "", "SARM", "UP", "", "", "SABM", "DISC", "", "", "SARME", "", "", "", "SARME", "SABME"};
char UR[][4] = {"UI", "RIM", "", "DM", "", "", "", "", "RD", "", "", "", "UA", "", "", "", ""};
char SS[][5] = {"RR", "RNR", "REJ", "SREJ"};
unsigned char i, j, IHL;
unsigned int ToT;

void CabeceraEthernet(unsigned char T[]);

void CabeceraARP(unsigned char T[]);

void CabeceraIP(unsigned char T[]);

void TipoTrama(unsigned char T[]);

int main(void) {
    // Tramas dadas por las maestras
    unsigned char T[][200] = {
            /* Frame (42 bytes) */
            {
                    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
                    0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x04, /* .F...... */
                    0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x23, /* .......# */
                    0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
                    0x39, 0xfe                                      /* 9. */
            },

/* Frame (60 bytes) */
            {
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
                    0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x01, /* E....... */
                    0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1f, /* ........ */
                    0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x39, 0xfe, /* E.....9. */
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
                    0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00                          /* .... */
            },

/* Frame (84 bytes) */
            {
                    0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
                    0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, /* .F....F. */
                    0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, /* .B.U4... */
                    0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
                    0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, /* g....... */
                    0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a, /* .5...|.. */
                    0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, /* ...www.i */
                    0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, /* sc.escom */
                    0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, /* .ipn.mx. */
                    0x00, 0x1c, 0x00, 0x01                          /* .... */
            },

/* Frame (64 bytes) */
            {
                    0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, /* ........ */
                    0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1, /* ........ */
                    0x01, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d  /* .....|.m */
            },

/* Frame (42 bytes) */
            {
                    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
                    0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x10, /* .F...... */
                    0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x23, /* .......# */
                    0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
                    0x3a, 0xe1                                      /* :. */
            },

/* Frame (60 bytes) */
            {
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
                    0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x10, /* E....... */
                    0x08, 0x00, 0x06, 0x04, 0x00, 0x04, 0x00, 0x1f, /* ........ */
                    0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
                    0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00                          /* .... */
            },

/* Frame (125 bytes) */
            {
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
                    0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
                    0x00, 0x6f, 0x90, 0x30, 0x40, 0x00, 0xfb, 0x11, /* .o.0@... */
                    0x24, 0xe7, 0x94, 0xcc, 0x67, 0x02, 0x94, 0xcc, /* $...g... */
                    0x39, 0xcb, 0x00, 0x35, 0x04, 0x0c, 0x00, 0x5b, /* 9..5...[ */
                    0xe8, 0x60, 0xe2, 0x1a, 0x85, 0x80, 0x00, 0x01, /* .`...... */
                    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x77, /* .......w */
                    0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
                    0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
                    0x02, 0x6d, 0x78, 0x00, 0x00, 0x1c, 0x00, 0x01, /* .mx..... */
                    0xc0, 0x14, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, /* ........ */
                    0x0e, 0x10, 0x00, 0x21, 0x04, 0x64, 0x6e, 0x73, /* ...!.dns */
                    0x31, 0xc0, 0x1a, 0x03, 0x74, 0x69, 0x63, 0xc0, /* 1...tic. */
                    0x1a, 0x77, 0xec, 0xdf, 0x29, 0x00, 0x00, 0x2a, /* .w..)..* */
                    0x30, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x12, 0x75, /* 0......u */
                    0x00, 0x00, 0x00, 0x2a, 0x30                    /* ...*0 */
            },

/* Frame (80 bytes) */
            {
                    0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
                    0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
                    0x00, 0x42, 0x04, 0x56, 0x00, 0x00, 0x80, 0x11, /* .B.V.... */
                    0x6b, 0xef, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
                    0x67, 0x02, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, /* g....5.. */
                    0xff, 0x87, 0x68, 0x2a, 0x01, 0x00, 0x00, 0x01, /* ..h*.... */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, /* .......w */
                    0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
                    0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
                    0x02, 0x6d, 0x78, 0x00, 0x00, 0x01, 0x00, 0x01  /* .mx..... */
            },

/* Frame (74 bytes) */
            {
                    0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
                    0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
                    0x00, 0x3c, 0x04, 0x57, 0x00, 0x00, 0x80, 0x01, /* .<.W.... */
                    0x98, 0x25, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* .%..9... */
                    0x3a, 0xe1, 0x08, 0x00, 0x49, 0x5c, 0x03, 0x00, /* :...I\.. */
                    0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
                    0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
                    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
                    0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
                    0x68, 0x69                                      /* hi */
            },

/* Frame (74 bytes) */
            {
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
                    0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
                    0x00, 0x3c, 0x01, 0xb5, 0x00, 0x00, 0x3f, 0x01, /* .<....?. */
                    0xdb, 0xc7, 0x94, 0xcc, 0x3a, 0xe1, 0x94, 0xcc, /* ....:... */
                    0x39, 0xcb, 0x00, 0x00, 0x51, 0x5c, 0x03, 0x00, /* 9...Q\.. */
                    0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
                    0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
                    0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
                    0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
                    0x68, 0x69                                      /* hi */
            },

/* Frame (86 bytes) */
            {
                    0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x1c, /* ..E..... */
                    0xc0, 0x7b, 0x35, 0xa1, 0x08, 0x00, 0x48, 0x00, /* .{5...H. */
                    0x00, 0x48, 0x5c, 0x7d, 0x00, 0x00, 0x80, 0x01, /* .H\}.... */
                    0x6c, 0x88, 0x94, 0xcc, 0x39, 0xc3, 0x94, 0xcc, /* l...9... */
                    0x00, 0x49, 0x07, 0x0b, 0x04, 0x00, 0x00, 0x00, /* .I...... */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, /* ........ */
                    0x3b, 0x5c, 0x02, 0x00, 0x10, 0x00, 0x61, 0x62, /* ;\....ab */
                    0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, /* cdefghij */
                    0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, /* klmnopqr */
                    0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63, /* stuvwabc */
                    0x64, 0x65, 0x66, 0x67, 0x68, 0x69              /* defghi */
            },

/* Frame (64 bytes) */
            {
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
                    0x45, 0x9d, 0x1e, 0xa2, 0x80, 0x35, 0x00, 0x01, /* E....5.. */
                    0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x1f, /* ........ */
                    0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
                    0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
                    0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0xd8, 0xee, 0xdf, 0xb0  /* ........ */
            },

/* Frame (64 bytes) */
            {
                    0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
                    0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0, /* ........ */
                    0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
            },

/* Frame (62 bytes) */
            {
                    0x02, 0xff, 0x53, 0xc3, 0xe9, 0xab, 0x00, 0xff, /* ..S..... */
                    0x66, 0x7f, 0xd4, 0x3c, 0x08, 0x00, 0x45, 0x00, /* f..<..E. */
                    0x00, 0x30, 0x2c, 0x00, 0x40, 0x00, 0x80, 0x06, /* .0,.@... */
                    0x4b, 0x74, 0xc0, 0xa8, 0x01, 0x02, 0xc0, 0xa8, /* Kt...... */
                    0x01, 0x01, 0x04, 0x03, 0x00, 0x15, 0x00, 0x3b, /* .......; */
                    0xcf, 0x44, 0x00, 0x00, 0x00, 0x00, 0x70, 0x02, /* .D....p. */
                    0x20, 0x00, 0x0c, 0x34, 0x00, 0x00, 0x02, 0x04, /*  ..4.... */
                    0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
            },

/* Frame (62 bytes) */
            {
                    0x00, 0xff, 0x66, 0x7f, 0xd4, 0x3c, 0x02, 0xff, /* ..f..<.. */
                    0x53, 0xc3, 0xe9, 0xab, 0x08, 0x00, 0x45, 0x00, /* S.....E. */
                    0x00, 0x30, 0x05, 0xc4, 0x40, 0x00, 0x80, 0x06, /* .0..@... */
                    0x71, 0xb0, 0xc0, 0xa8, 0x01, 0x01, 0xc0, 0xa8, /* q....... */
                    0x01, 0x02, 0x00, 0x15, 0x04, 0x03, 0x21, 0x5d, /* ......!] */
                    0x3a, 0x44, 0x00, 0x3b, 0xcf, 0x45, 0x70, 0x12, /* :D.;.Ep. */
                    0x44, 0x70, 0x8c, 0x11, 0x00, 0x00, 0x02, 0x04, /* Dp...... */
                    0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
            },

/* Frame (64 bytes) */
            {
                    0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
                    0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0, /* ........ */
                    0x0a, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, /* ........ */
                    0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23, /* ..(....# */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
                    0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d  /* .......m */
            }
    };
    printf("\n\n\n-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tRicardo Alcaraz Fraga\n\t\t\t\t# Boleta: 2018630891\n");
    printf("-------------------------------------------------------------------------------------------------\n\n\n");
    // Analizamos cada trama en el arreglo dado
    for (i = 0; i < 20; i++) {
        printf("*************************** TRAMA #%d *********************************************\n", i + 1);
        CabeceraEthernet(T[i]);
    }

    printf("\n\n\n\n");
    return 0;
}

void CabeceraEthernet(unsigned char T[]) {
    printf("\n❤ ❤ Cabecera Ethernet ❤ ❤\n");
    printf("MAC Destino: \t");
    for (j = 0; j < 6; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 5)
            printf(":");
    }

    printf("\nMAC Origen: \t");
    for (j = 6; j < 12; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 11)
            printf(":");
    }
    printf("\n");

    ToT = (T[12] << 8) + T[13];
    if (ToT <= 1500) {
        printf("Tamaño: \t%d bytes\n❤ ❤ Protocolo LLC ❤ ❤\n", ToT);
    }

    if (ToT > 1500) {
        printf("Tipo %d\n", ToT);
        TipoTrama(T);
    }

    if (ToT == 2048) {
        printf("Ethertype: IP\n❤ ❤ Protocolo IP ❤ ❤ \n");
        CabeceraIP(T);
    }

    if (ToT == 2054) {
        printf("Ethertype : ARP ❤ ❤\n❤ ❤ Protocolo ARP ❤ ❤\n");
        CabeceraARP(T);
    } else if (ToT > 2054)
        printf("Otro\n");

    printf("\n\n");
}

void TipoTrama(unsigned char T[]) {
    switch (T[16] & 3) {
        case 0:
            if (T[17] & 1) {
                if (T[15] & 1)
                    printf("f\n");

                else
                    printf("p\n");

                printf("Trama de Información:  \tN(S) = %d, N(R) = %d\n", (T[16] >> 1), (T[17] >> 1));
            }

            break;

        case 1:
            if (T[17] & 1) {
                if (T[15] & 1)
                    printf("f\n");

                else
                    printf("p\n");

                printf("Trama de Supervisión: \t N(R) = %d\tSS = %s\n", (T[17] >> 1), SS[T[16 >> 28]]);
            }

            break;

        case 2:
            if (T[17] & 1) {
                if (T[15] & 1)
                    printf("f\n");

                else
                    printf("p\n");

                printf("Trama de Información:  \tN(S) = %d, N(R) = %d\n", (T[16] >> 1), (T[17] >> 1));
            }

            break;

        case 3:
            if (T[16] & 16) {
                if (T[15] & 1) {
                    printf("Trama no Numerada f: %s\n", UR[((T[16] >> 2) & 3) + (T[16] >> 3) & 28]);
                } else
                    printf("Trama no Numerada p: %s\n", UC[((T[16] >> 2) & 3) + (T[16] >> 3) & 28]);
            }
            break;
    }
}

void CabeceraARP(unsigned char T[]) {
    switch ((T[14] << 8) + T[15]) {
        case 1:

            printf("Hardware Address Type: Ethernet\n");

            break;

        case 6:

            printf("Hardware Address Type: IEEE 802 LAN\n");

            break;
    }

    switch ((T[16] << 8) + T[17]) {
        case 2048:

            printf("Protocol Address Type: 2048 IPv4 (0x8000)\n");

            break;
    }

    if (T[18] & 6)
        printf("Hardware Address Length: Ethernet/IEEE 802\n");

    if (T[19] & 4)
        printf("Protocol Address Length: IPv4\n");

    switch ((T[20] << 8) + T[21]) {
        case 1:

            printf("Request\n");

            break;

        case 2:

            printf("Reply\n");

            break;

        case 3:

            printf("Inv Request\n");

            break;

        case 4:

            printf("Inv Reply\n");

            break;

        case 8:

            printf("Inv Request\n");

            break;

        case 9:

            printf("Inv Reply\n");

            break;
    }

    printf("Source Hardware Address: ");
    for (j = 22; j < 28; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 27)
            printf(":");
    }

    printf("\n");


    printf("Source Protocol Address: ");
    for (j = 28; j < 34; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 33)
            printf(":");
    }

    printf("\n");

    printf("Target Hardware Address: ");
    for (j = 34; j < 40; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 39)
            printf(":");
    }

    printf("\n");

    printf("Target Protocol Address: ");
    for (j = 40; j < 46; j++) {
        if (!(T[j] & 240)) {
            printf("0");
            printf("%x", T[j]);
        } else
            printf("%x", T[j]);

        if (j < 45)
            printf(":");
    }

    printf("\n\n");
}

void CabeceraIP(unsigned char T[]) {
    IHL = (T[14] & 15) * 4;     // Ya en bytes    
    if (IHL > 20) {
        printf("El datagrama tiene opciones\n");
        printf("Protocolo: ");
        switch (T[23]) {
            case 1:

                printf("ICMP\n");
                printf("Source Address: \t");
                for (j = 26; j < 30; j++) {
                    if (!(T[j] & 240)) {
                        printf("0");
                        printf("%x", T[j]);
                    } else
                        printf("%x", T[j]);

                    if (j < 29)
                        printf(".");
                }

                printf("\n");

                break;

            case 2:

                printf("IGMP\n");

                break;

            case 6:

                printf("TCP\n");
                printf("Sequence number: %d\n",
                       T[14 + 5 * IHL] >> 24 + T[14 + 6 * IHL] >> 16 + T[14 + 7 * IHL] >> 8 + T[14 + 8 * IHL]);


                switch (T[IHL + 14 + 20] >> 24 + T[IHL + 14 + 21] >> 16 + T[IHL + 14 + 22] >> 8 + T[IHL + 14 + 23]) {
                    printf("\nMAC Origen: \t");
                    for (j = 6; j < 12; j++) {
                        if (!(T[j] & 240)) {
                            printf("0");
                            printf("%x", T[j]);
                        } else
                            printf("%x", T[j]);

                        if (j < 11)
                            printf(":");
                    }
                    printf("\n");


                    case 0:

                        printf("No options\n");

                        break;

                    case 1:

                        printf("No operation (pad)\n");

                        break;

                    case 2:

                        printf("Maximum segment size\n");

                        break;

                    case 3:

                        printf("Window Scale\n");

                        break;

                    case 4:

                        printf("Selective ACK ok\n");

                        break;

                    case 8:

                        printf("Timestamp\n");

                        break;
                }

                break;

            case 9:

                printf("IGRP\n");

                break;

            case 17:

                printf("UDP\n");
                printf("Header Checksum: %x%x\n", T[24], T[25]);

                break;

            case 47:

                printf("GRE\n");

                break;

            case 50:

                printf("ESP\n");

                break;

            case 51:

                printf("AH\n");

                break;

            case 57:

                printf("SKIP\n");

                break;

            case 88:

                printf("EIGRP\n");

                break;

            case 89:

                printf("OSPF\n");

                break;

            case 115:

                printf("L2TP\n");

                break;
        }


    } else if (IHL == 20) {
        printf("La trama tiene costo minimo\n");
        printf("Total Length: %d bytes\n", (T[16] >> 8) + T[17]);
    } else
        printf("El datagrama no tiene opciones\n");

    if (T[23] == 6) {
        printf("Protocol: TCP\n");
        printf("Sequence number: %d\n",
               T[14 + 5 * IHL] >> 24 + T[14 + 6 * IHL] >> 16 + T[14 + 7 * IHL] >> 8 + T[14 + 8 * IHL]);

        switch (T[IHL + 14 + 20] >> 24 + T[IHL + 14 + 21] >> 16 + T[IHL + 14 + 22] >> 8 + T[IHL + 14 + 23]) {

            printf("\nMAC Origen: \t");
            for (j = 6; j < 12; j++) {
                if (!(T[j] & 240)) {
                    printf("0");
                    printf("%x", T[j]);
                } else
                    printf("%x", T[j]);

                if (j < 11)
                    printf(":");
            }

            printf("\n");
            case 0:

                printf("No options\n");

                break;

            case 1:

                printf("No operation (pad)\n");

                break;

            case 2:

                printf("Maximum segment size\n");

                break;

            case 3:

                printf("Window Scale\n");

                break;

            case 4:

                printf("Selective ACK ok\n");

                break;

            case 8:

                printf("Timestamp\n");

                break;
        }
    }

}
