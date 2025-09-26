#include <stdio.h>
#include <stdlib.h>

long long factorial(int n) {
    if (n < 0) return -1; // error
    long long result = 1;
    while (n > 1) {
        result *= n;
        n = n - 1; // decremento correcto
    }
    return result;
}

int main(void) {
    int n;
    printf("Ingrese un entero no negativo para calcular su factorial: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        return 1;
    }
    if (n < 0) {
        fprintf(stderr, "No se puede calcular factorial de un numero negativo.\n");
        return 1;
    }
    long long fac = factorial(n);
    if (fac < 0) {
        fprintf(stderr, "Error al calcular factorial.\n");
        return 1;
    }
    printf("%d! = %lld\n", n, fac);
    return 0;
}
