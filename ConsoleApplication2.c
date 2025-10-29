#include <stdio.h>
#include <math.h>


/**
 * @brief Расчитывает площадь поверхности грани куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SGrani(double a);

/**
 * @brief Расчитывает площадь поверхности всех граней куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double SVsehGraney(double a);

/**
 * @brief Расчитывает объём куба
 * @param a - значение параметра a
 * @return рассчитанное значение
*/
double V(double a);


/**
 * @brief точка входа в программу
 * @return возвращает 0,если программа выполнена корректно
 */
int main() {
	double a;
	scanf_s("%lf", &a);

	printf("SGrani = %lf\n", SGrani(a) );
	printf("SVsehGraney = %lf\n", SVsehGraney(a) );
	printf("V = %lf\n", V(a) );
	return 0;
}

double SGrani(double a)
{
	return a * a;

}

double SVsehGraney(double a)
{
	return a * a * 6;

}

double V(double a)
{
	return a * a * a;

}