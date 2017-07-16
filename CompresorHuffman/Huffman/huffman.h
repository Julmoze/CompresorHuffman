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

/*! \class Huffman
    \brief Class in charge of compressing and decompressing files.
*/
class Huffman
{
  private:
    /*! \struct nodo
        \brief Structure representing each tree node.
    */
    struct nodo
    {
        struct nodo *der,*izq,*arr;  /*!< Creates node*/
        int cuenta;                  /*!< Counts character repetition*/
        char bit;                    /*!< Assigns 1 or 0*/
        unsigned char karacter;      /*!< Original character*/
        char *codigo;                /*!< Code for compressed code*/
        char nbits;                  /*!< Number of bits that make the code up*/
    }HOJAS[256],*TELAR[256],*MENOR,*SEGUNDO;

    int NSIMB=0,nsimb;
    FILE *f,*g;
    int NBYTES=0;

  public:

    /*! \fn int preparar_hojas(char *archivo)
        \brief Leaves are prepared.
        \param archivo File address
        \return Returns 0 if the address is valid, 1 if invalid
	*/
    int preparar_hojas(char *archivo);

    /*! \fn void preparar_telar()
        \brief Prepares the weaver for the tree.
	*/
    void preparar_telar();
    
    /*! \fn void tejer()
        \brief Weaves the tree
	*/
    void tejer();
    
    /*! \fn void codificar()
        \brief With the tree made, an iterator makes the code.
	*/
    void codificar();
    
    /*! \fn void debug()
        \brief Prints data related to the characters.
	*/
    void debug();

    /*! \fn int escribe_cabecera(char *destino)
        \brief Prints the information of the original file and the ammount of different characters.
        \param destino Output file address
        \return Returns 0 if the address is valid, 1 if invalid
	*/
    int escribe_cabecera(char *destino);
    
    /*! \fn int comprimir(char *origen, char *destino)
        \brief Compresses the file.
        \param origen Input file address
        \param destino Output file address
        \return Returns 0 if addresses are valid, 1 if the input address is invalid, 2 if the output address is invalid
	*/
    int comprimir(char *origen, char *destino);
    
    /*! \fn int descomprimir(char *origen, char *destino)
        \brief Decompresses the file.
        \param origen Input file address
        \param destino Output file address
        \return Returns 0 if addresses are valid, 1 if the input address is invalid, 2 if the output address is invalid
	*/
    int descomprimir(char *origen, char *destino);
    
    /*! \fn std::string addressInputToOutput( std::string addressInput )
        \brief Turns the input address into the output adress file needed
        \param addressInput Input file address
        \return Returns output file address
	*/
    std::string addressInputToOutput( std::string addressInput );

    /*! \fn char compressionFlow( std::string addressInput )
        \brief Indicates whether to compress or decompress, depending on the input address
        \param addressInput Input file address
        \return Returns 'D' if Decompresses, 'C' if Compresses.
	*/
    char compressionFlow( std::string addressInput );
    
    /*! \fn void start( std::string addressInput )
        \brief Starts the compression or decompression process by creating every needed part.
        \param addressInput Input file address
	*/
    void start( std::string addressInput );

    /*! \fn void convert(int argc, char *argv[])
        \brief Converts a given file in a path to the opposite extension.
        \param argc Size argv[].
        \param argv The [1] is 'C' or 'D', the [2] is address input, the [3] is address output.
	*/
    void convert(int argc, char *argv[]);

};
