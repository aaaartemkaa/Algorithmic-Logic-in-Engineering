#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "ru");//Подключаем русский
    int n, i, j;
    //Получение размера массива от пользователя
    printf("Введите размер квадратного массива: ");
    scanf("%d", &n);

    //Выделение памяти для двумерного массива
    int** matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти!\n");
            //Освобождаем ранее выделенную память
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return 1;
        }
    }

    //Инициализация генератора случайных чисел
    srand(time(NULL));

    //Заполнение массива случайными числами и обеспечение симметричности относительно диагоналей
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 21 - 5;//от -5 до 15
            matrix[j][i] = matrix[i][j];
        }
    }
//Чтобы обход был только 1 раз
    //Вывод массива
    printf("Сгенерированный массив:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    //Освобождение выделенной памяти
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}