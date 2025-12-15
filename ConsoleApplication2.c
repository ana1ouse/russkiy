#include <stdio.h>
#include <math.h>


/**
 * @brief Расчитывает площадь поверхности грани куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SGrani(const double a);

/**
 * @brief Расчитывает площадь поверхности всех граней куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SVsehGraney(const double a);

/**
 * @brief Расчитывает объём куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double V(const double a);


/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main() {
	double a = 0;
	scanf_s("%lf", &a);
	if (a >= 0) {
		printf("SGrani = %lf\n", SGrani(a));
		printf("SVsehGraney = %lf\n", SVsehGraney(a));
		printf("V = %lf\n", V(a));
	}
	else {
		printf ("NO");
	}
	return 0;
}

double SGrani(const double a)
{
	return a * a;

}

double SVsehGraney(const double a)
{
	return a * a * 6;

}

double V(const double a)
{
	return a * a * a;

}
