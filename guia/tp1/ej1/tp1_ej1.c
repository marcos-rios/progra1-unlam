#include <stdio.h>

#include "tp1_ej1.h"
#include "../../core/utils.h"
#include "../../core/types.h"

long solicitar_numero();
bigint calcular_factorial(long num);

bigint tp1_ej1() {
    imprimir_titulo("TP1 - EJ1");
    long num = solicitar_numero();
    long factorial = calcular_factorial(num);
    printf("Factorial de %ld: %ld\n", num, factorial);
    return factorial;
}

long solicitar_numero() {
    long ingreso;
    printf("Ingresa un n�mero positivo para calcular su factorial: ");
    scanf("%ld", &ingreso);
    fflush(stdin);
    while(ingreso < 0) {
        printf("Por favor ingresa un n�mero v�lido: ");
        scanf("%ld", &ingreso);
        fflush(stdin);
    }
    return ingreso;
}

bigint calcular_factorial(long num) {
    if(num != 0) {
        return calcular_factorial(num - 1) * num;
    } else {
        return 1;
    }
}
