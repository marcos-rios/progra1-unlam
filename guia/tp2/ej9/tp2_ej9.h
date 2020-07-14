#ifndef TP2_EJ9_H_INCLUDED
#define TP2_EJ9_H_INCLUDED

/**
    Escriba un programa que genere un archivo de texto ("datos.txt") a partir del ingreso por teclado de n�meros enteros,
    de modo que en cada l�nea de texto haya una cantidad variable de cadenas de caracteres que representen tales n�meros.
    En el archivo debe haber como m�nimo la representaci�n de un entero y como m�ximo de siete.
    La separaci�n entre estas cadenas que representan n�meros debe ser de al menos un car�cter espacio (' ') o a lo sumo cinco,
     de modo que queden alineados por la derecha al leer el contenido del archivo con un procesador de texto como el �Notepad� o �Bloc de Notas�.
    Ingrese los enteros con una variable short int (note que el rango de las mismas pertenece al intervalo [-32768, 32767]).
    Vea e interprete qu� sucede cuando ingresa n�meros fuera de ese rango.

    Note que:
    - los caracteres de separaci�n s�lo est�n entre n�meros
    - en el archivo debe haber al menos una l�nea con un n�mero y otra con siete
    Utilice el generador de n�meros pseudo aleatorios para determinar cu�ntos n�meros se almacenan por l�nea de texto,
     y adem�s para que determine cu�ntas l�neas se almacenar�n una vez cumplida la condici�n de una l�nea con un n�mero y otra con siete.
*/
int tp2_ej9();

#endif // TP2_EJ9_H_INCLUDED
