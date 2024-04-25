#include <stdio.h>

int showErrors(int num_error) {
	if(num_error == 1) {
		showErrors(1); // Некорректный ввод данных
	}
	if(num_error == 2) {
		showErrors(2); // Некорректное значение координат
	}
	if(num_error == 3) {
		showErrors(3); // ошибка выделения памяти
	}
	if(num_error == 4) {
		showErrors(4); // Некритическая идентифицированная ошибка
	}
	if(num_error == 5) {
		showErrors(5); // Критическая идентифицированная ошибка
		return -1; // Завершаем выполнение функции
	}
	else {
		showErrors(-1); // Ошибка, которой нет
		return -1; // Завершаем выполнение функции
	}
	return 0;
}


