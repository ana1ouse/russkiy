#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Выделяет память под массив целых чисел.
 * @param size Размер массива.
 * @return Указатель на выделенную память под массив.
 */
int* initArray(const size_t size);

/**
 * @brief Проверяет корректность ввода размера массива и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
size_t validateArraySize(const char* message);

/**
 * @brief Заполняет массив случайными или введенными с клавиатуры числами.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Проверяет корректность ввода целого числа и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
int validateNumber(const char* message);

/**
 * @brief Выводит массив на экран.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArrayRandom(int* arr, const size_t size);

/**
 * @brief Заполняет массив, считывая значения с клавиатуры.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArrayKeyboard(int* arr, const size_t size);

/**
 * @brief Подсчитывает количество элементов, которые не оканчиваются на 0.
 * @param arr Указатель на исходный массив.
 * @param size Количество элементов в массиве.
 * @return Количество элементов, которые не оканчиваются на 0.
 */
size_t countElementsWithLastDigitZero(const int* arr, const size_t size);

/**
 * @brief Заменяет минимальный по модулю отрицательный элемент массива на первый элемент.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат замены.
 * @param size Размер исходного массива.
 * @return Новый массив после замены минимального по модулю отрицательного элемента.
 */
void replaceMinNegative(const int* arr, int* arr2, const size_t size);

/**
 * @brief Удаляет элементы с последней цифрой, равной 0, из массива.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будут скопированы элементы после удаления.
 * @param size Размер исходного массива.
 * @return Новый массив после удаления элементов с последней цифрой, равной 0.
 */
void removeElementsWithLastDigitZero(const int* arr, int* arr2, const size_t size);

/**
 * @brief Преобразует массив по правилу: если номер четный, то Mi=i*Pi , если нечетный, то Mi=-Pi.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат преобразования.
 * @param size Размер исходного массива.
 * @return Новый массив после преобразования.
 */
void transformArray(const int* arr, int* arr2, const size_t size);

/**
 * @brief Находит индекс минимального по модулю отрицательного элемента в массиве.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 * @return Индекс первого отрицательного элемента или -1, если такого нет.
 */
int findFirstNegativeIndex(const int* arr, const size_t size);

/**
 * @brief Перечисление для выбора способа заполнения массива.
 */
enum TASK {
    RANDOM,
    KEYBOARD
};

/**
 * @brief Освобождает выделенную память для массива.
 * @param arr Указатель на массив.
 */
void freeArray(int** arr);

/**
* @brief Основная функция программы.
* @return Возвращает 0 в случае успешного выполнения программы.
*/
int main() {
    size_t size = validateArraySize("Введите размерность массива: ");

    int* arr = initArray(size);
    fillArray(arr, size);

    printf("Исходный массив: ");
    printArray(arr, size);

    printf("Массив после замены минимального по модулю отрицательного элемента: ");
    int* arr2 = initArray(size);
    replaceMinNegative(arr, arr2, size);
    printArray(arr2, size);

    freeArray(&arr2);

    size_t newSize = countElementsWithLastDigitZero(arr, size);
    printf("Массив после удаления элементов с последней цифрой, равной 0: ");
    int* arr3 = initArray(newSize);
    removeElementsWithLastDigitZero(arr, arr3, size);
    printArray(arr3, newSize);

    freeArray(&arr3);

    printf("Массив M после преобразования: ");
    int* arr4 = initArray(size);
    transformArray(arr, arr4, size);
    printArray(arr4, size);

    freeArray(&arr4);

    freeArray(&arr);

    return 0;
}

int* initArray(const size_t size) {
    int* arr = (int*)malloc(sizeof(int) * size);
    if (arr == NULL) {
        puts("Ошибка выделения памяти\a");
        exit(EXIT_FAILURE);
    }

    return arr;
}

size_t validateArraySize(const char* message) {
    int input;
    printf("%s", message);

    if (scanf_s("%d", &input) != 1 || input <= 0) {
        puts("Размер массива должен быть больше нуля!\a");
        exit(EXIT_FAILURE);
    }

    return input;
}

void fillArray(int* arr, const size_t size) {

    printf("Каким способом вы хотите заполнить массив?\n"
        "Случайные числа - %d\n"
        "Ввод с клавиатуры - %d\n", RANDOM, KEYBOARD);

    int a = validateNumber("");
    enum TASK choice = (enum TASK)a;

    switch (choice) {
    case RANDOM:
        fillArrayRandom(arr, size);
        break;
    case KEYBOARD:
        fillArrayKeyboard(arr, size);
        break;
    default:
        puts("Неправильный номер задания");
        exit(EXIT_FAILURE);
    }
}

int validateNumber(const char* message) {
    int input;
    printf("%s", message);

    if (scanf_s("%d", &input) != 1) {
        puts("Ошибка ввода!");
        exit(EXIT_FAILURE);
    }

    return input;
}

void fillArrayRandom(int* arr, const size_t size) {
    const int lowerBound = validateNumber("\nВведите нижнюю границу случайных чисел: ");
    const int upperBound = validateNumber("Введите верхнюю границу случайных чисел: ");

    if (lowerBound > upperBound) {
        puts("Неправильно введена граница чисел!\a");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (upperBound + 1 - lowerBound) + lowerBound;
    }
}

void printArray(const int* arr, const size_t size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void fillArrayKeyboard(int* arr, const size_t size) {
    printf("Введите %zu элементов массива:\n", size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = validateNumber("");
    }
}

size_t countElementsWithLastDigitZero(const int* arr, const size_t size) {
    size_t newSize = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 10 != 0) {
            newSize++;
        }
    }

    return newSize;
}

void removeElementsWithLastDigitZero(const int* arr, int* arr2, const size_t size) {
    size_t index = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 10 != 0) {
            arr2[index] = arr[i];
            index++;
        }
    }
}

void transformArray(const int* arr, int* arr2, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr2[i] = i * arr[i];
        }
        else {
            arr2[i] = -arr[i];
        }
    }
}

void replaceMinNegative(const int* arr, int* arr2, const size_t size) {
    int minNegativeIndex = findFirstNegativeIndex(arr, size);

    for (size_t i = 0; i < size; i++) {
        arr2[i] = arr[i];
    }

    if (minNegativeIndex != -1) {
        arr2[minNegativeIndex] = arr[0];
    }
}

int findFirstNegativeIndex(const int* arr, const size_t size) {
    int minNegativeValue = INT_MAX;
    int minNegativeIndex = -1;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] < 0 && abs(arr[i]) < minNegativeValue) {
            minNegativeValue = abs(arr[i]);
            minNegativeIndex = i;
        }
    }

    return minNegativeIndex;
}

void freeArray(int** arr) {
    if (*arr != NULL) {
        free(*arr);
    }
    *arr = NULL;
}
