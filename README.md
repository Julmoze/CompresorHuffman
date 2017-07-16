# Proyecto-Final
Proyecto Final Curso de  Programación 2

Compresor Huffman
Hace un año, dos estudiantes de informática recibieron un curso de Estructuras Discretas. En dicho curso, vieron un metodo de compresión de datos llamado algoritmo de Huffman.Este algoritmo permite la compresión de datos con n cantidad de caracteres distintos y recibe el nombre de su creador. Su implementación, permite asignar valores de peso a los caracteres en un mapa de datos. De esta manera, los codigos para caracteres más frecuentes, tendrá un código más pequeño. Y las infrecuentes un código de mayor longitud. 
Dicho algoritmo se vio teóricamente y no se vió una implementación. Por esa razón, se decide crear un compresor de Huffman como parte de este proyecto final del curso de Programación II. Sin embargo, dicho compresor deberá tener implementado la utilización de una interfaz entre el usuario y el sistema. De esta manera se logra que la aplicación sea amigable con el usuario. Esta permitirá que el usuario pueda ingresar un archivo en la aplicación, la aplicación lo comprima y guarde el archivo resultante en el mismo lugar del archivo original. 
Una vez terminada completamente la aplicación, esta permitirá tanto comprimir como descomprimir archivos, pues es necesario ambas direcciones para poder tener la información apropiada tanto para un emisor como para un receptor. El compresor funcionará de manera automática, por lo cual es posible comprimir un archivo que se le ha aplicado Huffman si se cambia su extensión. Sin embargo, aplicarle Huffman a un archivo ya comprmidio, no otorga una mayor compresión. El archivo tendrá el mismo peso.

Esta aplicación seguirá los siguientes lineamientos: 

- La aplicación utiliza el algoritmo de Huffman implementado en QT

-Esta permite tanto comprimir como descomprimir archivos

-Se puede arrastrar directamente con el mouse un archivo para aplicarle el Algoritmo de Huffman, esto para comprimir o descomprimir.

-El archivo comprimido o descomprimido se guardará en la misma carpeta que el archivo original.