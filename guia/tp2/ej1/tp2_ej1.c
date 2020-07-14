#include <stdio.h>

#include "../../core/menu.h"
#include "tp2_ej1.h"
/**
    * Escriba una funci�n que permita desplegar un men� de opciones, devolviendo una opci�n v�lida.
    * Escriba una funci�n que reciba por argumento la direcci�n de comienzo de un array de float
        y la cantidad m�xima de elementos a ingresar (no utilice sub�ndices).
      La funci�n permitir� terminar el ingreso con una condici�n fijada por el alumno
    * Escriba una funci�n que permita buscar el m�nimo elemento de un array de float.
        y devolver� la cantidad de elementos ingresados (puede ser cero).
    * Escriba una funci�n que determine el promedio de los elementos
        que se encuentran en las posiciones pares de un array de float.
    * Escriba una funci�n que muestre los elementos de un array de float en orden inverso
    * Escriba una funci�n que almacene en un archivo de texto los elementos de un array de float,
        a raz�n de un flotante por l�nea de texto.
    * Haciendo uso de las funciones anteriores, escriba un programa que al comenzar
        permita el ingreso para un array de float, luego de lo cual muestre un men� de opciones para:
        1- Buscar el m�nimo elemento,
        2- Calcular el promedio de los valores de las posiciones pares,
        3- Mostrarlo en orden inverso,
        4- Salir.
    y que antes de terminar la ejecuci�n del programa grabe los elementos del array en un archivo de texto.
    Consulte de qu� modo puede hacer que el programa trabaje con otros tipos de
        datos (double, long double, int, unsigned, etc.), con m�nimas modificaciones
*/

#define MENU_MSJ "\n-- Elija un opci�n --\n"\
                 "1- Buscar el m�nimo elemento\n"\
                 "2- Calcular el promedio de los valores de las posiciones pares\n"\
                 "3- Mostrar arrray en orden inverso\n"\
                 "4- Salir\n"

#define MENU_OPC "1234"

#define TAM 10
#define CORTE_ARRAY -999

int solicitar_array(float *, int);

int buscar_minimo(float *array, float *min);

float calcular_prom_indice_par(const float *array, int array_size);

void mostrar_inverso(const float *array, int);

void almacenar_array(const char *, const float *);

int tp2_ej1() {
    float array[TAM] = {};
    char opc;
    int array_size = solicitar_array(array, TAM);
    do {
        opc = mostrar_menu(MENU_MSJ, MENU_OPC);
        switch(opc) {
        case '1': {
            float min = 0;
            int cant = buscar_minimo(array, &min);
            if(cant != 0) {
                printf("El m�nimo es: %f", min);
            } else {
                printf("No hay elementos en la lista.");
            }
        }
        break;
        case '2': {
            int prom = calcular_prom_indice_par(array, array_size);
            printf("El promedio de los elementos en posiciones pares es: %d", prom);
        }
        break;
        case '3':
            mostrar_inverso(array, array_size);
            break;
        case '4':
            puts("> Nos vemo en Disney..\n");
            break;
        }
    } while(opc != '4');
    almacenar_array("tp2/ej1/floats.txt", array);
    return 0;
}

/**
    Escriba una funci�n que reciba por argumento la direcci�n de comienzo de un array de float
        y la cantidad m�xima de elementos a ingresar (no utilice sub�ndices).
    La funci�n permitir� terminar el ingreso con una condici�n fijada por el alumno
        y devolver� la cantidad de elementos ingresados (puede ser cero).
*/
int solicitar_array(float *array, int max_elem) {
    int cant = 0;
    float actual = 0;
    printf("Ingresa una lista de numeros enteros separados por un espacio (%d termina): ", CORTE_ARRAY);
    for(float *i=array; i < array + max_elem && actual != CORTE_ARRAY; i++) {
        fflush(stdin);
        scanf("%f", &actual);
        *i = actual;
        cant++;
    }
    return cant;
}

/**
    Escriba una funci�n que permita buscar el m�nimo elemento de un array de float
        y devolver� la cantidad de elementos ingresados (puede ser cero).
*/
int buscar_minimo(float *array, float *min) {
    int cant = 0;
    if(*array != CORTE_ARRAY) {
        *min = *array;
        for(float *i=array; *i != CORTE_ARRAY; i++) {
            if(*i < *min) {
                *min = *i;
            }
            cant++;
        }
    }
    return cant;
}

/**
    Escriba una funci�n que determine el promedio de los elementos
        que se encuentran en las posiciones pares de un array de float.
*/
float calcular_prom_indice_par(const float *array, int array_size) {
    const float *i = array;
    int count = 0, sum = 0;
    while(i < array + array_size && *i != CORTE_ARRAY) {
        sum += *i;
        count++;
        i = i + 2;
    }
    return sum / count;
}

/** Escriba una funci�n que muestre los elementos de un array de float en orden inverso */
void mostrar_inverso(const float *array, int array_size) {
    const float *i = array + array_size - 2;
    while(i > array) {
        printf("%.2f, ", *i);
        i--;
    }
    printf("%f", *i);
}

/**
    Escriba una funci�n que almacene en un archivo de texto los elementos de un
    array de float, a raz�n de un flotante por l�nea de texto
*/
void almacenar_array(const char *nombre_archivo, const float *array) {
    FILE *pf = fopen(nombre_archivo, "wt");
    if(!pf) {
        puts("No se pudo generar el archivo.");
    }
    for(const float *i=array; *i != CORTE_ARRAY; i++) {
        fprintf(pf, "%.2f\n", *i);
    }
    fclose(pf);
}
