#include <iostream>

/*
Este programa implementa un sencillo compresor
de Huffman, que podria usarse para un programa
de mayor envergadura.
Simple Huffman compressor that can be used with other programs
comprimir: huf C entrada salida
descompr.: huf D entrada salida
info:      huf I entrada
*/

#include <stdio.h>
#include <malloc.h>
#include <string>
#include <cstring>

class Huffman
{
  private:
    struct nodo
    {
        struct nodo *der,*izq,*arr;  /* forma el nodo *//* Creates node*/
        int cuenta;                  /* apariciones del carÃ¡cter *//* Counts character repetition*/
        char bit;                    /* 0 o 1 */ /*assigns 1 or 0*/
        unsigned char karacter;      /* el carÃ¡cter (para la descompresiÃ³n */ /*Original character*/
        char *codigo;                /* cadena de ceros y unos con la codificaciÃ³n *//* code for compressed code*/
        char nbits;                  /* me apunto el numero de bits que codifican el carÃ¡cter *//*Number of bits that make the code up*/
    }HOJAS[256],*TELAR[256],*MENOR,*SEGUNDO;

    int NSIMB=0,nsimb;
    FILE *f,*g;
    int NBYTES=0;

  public:
    /*--------------------------------
    preparar las hojas
    Leaves are prepared
    --------------------------------*/
    int preparar_hojas(char *archivo);
    /*--------------------------------
    preparar telar
    Prepares the weaver for the tree
    --------------------------------*/
    void preparar_telar();
    /*--------------------------------
    tejer el Arbol
    Weaves the tree
    --------------------------------*/
    void tejer();
    /*--------------------------------
    Una vez construido el Ã¡rbol, puedo codificar
    cada carÃ¡cter. Para eso recorro desde la hoja
    a la raÃ­z, apunto 0 o 1 en una pila y luego
    paso la pila a una cadena. Un 2 determina el
    fin de la cadena.
    With the tree made, an iterator makes the code.
    --------------------------------*/
    void codificar();
    /*--------------------------------
    debug. Imprime la info sobre cada
    carÃ¡cter, como nÃºmero de apariciones
    y cadena con que se codifica
    Prints data related to the characters.
    --------------------------------*/
    void debug();
    /*--------------------------------
    Escribe la cabecera del archivo de
    destino. La cabecera contiene: el
    nÃºmero de bytes del archivo origen,
    el nÃºmero de caracteres distintos
    en ese archivo y una lista de parejas
    nÃºmero de carÃ¡cter-cuenta de ese
    carÃ¡cter. Eso es suficiente para la
    descompresiÃ³n
    Prints the information of the original file
    and the ammount of different characters.
    --------------------------------*/
    int escribe_cabecera(char *destino);
    /*--------------------------------
    Una vez construido el Ã¡rbol y codificado
    cada carÃ¡cter se puede proceder a la
    compresiÃ³n: se tomarÃ¡ carÃ¡cter a carÃ¡cter
    del archivo origen y se usarÃ¡ la cadena
    de codificaciÃ³n para ir escribiendo
    bits en un buffer de un carÃ¡cter, que
    cada vez que quede lleno se pasarÃ¡ al
    archivo de destino
    Each character, is turned into the respective bit code to the
    destiny file.
    --------------------------------*/
    int comprimir(char *origen, char *destino);
    /*--------------------------------
    Descomprime el archivo. El primer paso
    es leer la cabecera, paso previo a la
    descompresiÃ³n. Recuerdo formato de
    la cabecera:
    NBYTES|NSIMB|(char,cuenta)*
    Decompresses the file.
    --------------------------------*/
    int descomprimir(char *origen, char *destino);
    /*Turns the input address into the output adress file needed*/

    std::string addressInputToOutput( std::string addressInput );
    /* Figures if the file is to be compressed or decompressed*/
    char compressionFlow( std::string addressInput );
    /*Starts the compression or decompression process by creating
    every needed part*/
    void start( std::string addressInput );
    /*Converts a given file in a path to the opposite extension*/
    void convert(int argc, char *argv[]);

};
