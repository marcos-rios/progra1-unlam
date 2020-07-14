#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

/**
    Escriba una funci�n que permita desplegar un men� de opciones, devolviendo una opci�n v�lida.
*/
char mostrar_menu(const char *menu, const char *opciones) {
    char opc;
    fflush(stdin);
    printf("%s> ", menu);
    scanf("%c", &opc);
    while(strchr(opciones, opc) == NULL) {
        printf("%s\n%s\n> ", "Opci�n no valida!", menu);
        fflush(stdin);
        scanf("%c", &opc);
    }
    return opc;
}
