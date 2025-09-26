#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
#define SIZE 3
#endif

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

int isMagicSquare(int matrix[SIZE][SIZE]) {
    int target = 0;
    // suma de la primera fila
    for (int j = 0; j < SIZE; ++j) target += matrix[0][j];

    // chequear filas
    for (int i = 1; i < SIZE; ++i) {
        int sum = 0;
        for (int j = 0; j < SIZE; ++j) sum += matrix[i][j];
        if (sum != target) return 0;
    }

    // chequear columnas
    for (int j = 0; j < SIZE; ++j) {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) sum += matrix[i][j];
        if (sum != target) return 0;
    }

    // diagonal principal
    int sumDiag = 0;
    for (int i = 0; i < SIZE; ++i) sumDiag += matrix[i][i];
    if (sumDiag != target) return 0;

    // diagonal secundaria
    int sumDiag2 = 0;
    for (int i = 0; i < SIZE; ++i) sumDiag2 += matrix[i][SIZE - 1 - i];
    if (sumDiag2 != target) return 0;

    return 1;
}

void fillRandom(int matrix[SIZE][SIZE], int minVal, int maxVal) {
    // llena con numeros en [minVal, maxVal]
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            matrix[i][j] = minVal + rand() % (maxVal - minVal + 1);
}

int main(void) {
    srand((unsigned) time(NULL));

    // ejemplo con la matriz del enunciado
    int example[SIZE][SIZE] = {
#if SIZE == 3
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
#else
        // para SIZE != 3, rellenamos con ceros (reemplazar si se desea)
#endif
    };

#if SIZE == 3
    printf("Matriz ejemplo:\n");
    printMatrix(example);
    if (isMagicSquare(example))
        printf("La matriz es cuadrado magico.\n\n");
    else
        printf("La matriz NO es cuadrado magico.\n\n");
#endif

    // generar varias matrices aleatorias y verificar
    int tries = 5;
    int matrix[SIZE][SIZE];
    printf("Generando %d matrices aleatorias (valores 1..%d):\n\n", tries, SIZE*SIZE);
    for (int t = 0; t < tries; ++t) {
        fillRandom(matrix, 1, SIZE*SIZE);
        printf("Matriz aleatoria #%d:\n", t+1);
        printMatrix(matrix);
        if (isMagicSquare(matrix))
            printf("Resultado: Es cuadrado magico.\n\n");
        else
            printf("Resultado: NO es cuadrado magico.\n\n");
    }

    return 0;
}
