#include <stdio.h>

int showErrors(int num_error) {
	if(num_error == 1) {
		printf("Error #1: Incorrect input!\n"); // Некорректный ввод данных
	}
	if(num_error == 2) {
		printf("Error #2: Value is too large!\n"); // Значение слишком большое
	}
	if(num_error == 3) {
		printf("Error #3: Value is too small!\n"); // Значение слишком маленькое
	}
	if(num_error == 4) {
		printf("Error #4: File was not found!\n"); // Файл не обнаружен
	}
	if(num_error == 5) {
		printf("Error #5: File is not empty!\n"); // Файл пустой!
	}
	if(num_error == 6) {
		printf("Error #6: File contains incorrect data!\n"); // Файл содержит некорректные данные
	}
	if(num_error == 7) {
		printf("Error #7: There is a flag on this cage! Choose another one.\n"); // На этой клетке находится флаг! Выберите другую
	}
	if(num_error == 8) {
		printf("Error #8: Inform the Developer!\n"); // Критическая идентифицированная ошибка, природа которой не ясна
		return -1; // Завершаем выполнение функции, поскольку обычно 7-й ошибкой обозночаются критические
	}
	else {
		printf("Unidentified error: Inform the Developer!\n"); // Критическая неидентифицированная ошибка, природа которой не ясна
		return -1; // Завершаем выполнение функции, поскольку природа ошибки не ясна, а значит продолжать - не самая лучшая идея
	}
	return 0;
}


