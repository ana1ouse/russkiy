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
	const double a = 3;

	printf("A = %lf\n", SGrani(a) );
	printf("B = %lf\n", SVsehGraney(a) );
	printf("C = %lf\n", V(a) );
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