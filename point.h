#pragma once

/**
 * @brief Класс, представляющий точку в трёхмерном пространстве.
 * Хранит координаты X, Y, Z и предоставляет доступ к ним,
 */
class Point
{
private:
    /**
     * @brief Координата X
     */
    double x;
    /**
     * @brief Координата Y
     */
    double y;
    /**
     * @brief Координата Z
     */
    double z;

public:
    /**
     * @brief Конструктор точки.
     *
     * @param x Координата X (по умолчанию 0)
     * @param y Координата Y (по умолчанию 0)
     * @param z Координата Z (по умолчанию 0)
     * @code
     * Point p1;              // (0, 0, 0)
     * Point p2(1.0, 2.0);    // (1, 2, 0)
     * Point p3(1.0, 2.0, 3.0);
     * @endcode
     */
    Point(const double x = 0, const double y = 0, const double z = 0);

    /**
     * @brief Получение координаты X.
     * @return Значение координаты X
     */
    double getX() const;

    /**
     * @brief Получение координаты Y.
     * @return Значение координаты Y
     */
    double getY() const;

    /**
     * @brief Получение координаты Z.
     * @return Значение координаты Z
     */
    double getZ() const;

    /**
     * @brief Оператор проверки на равенство.
     * @param p Точка для сравнения
     * @return true, если точки равны; иначе false
     */
    bool operator==(const Point& p) const;

    /**
     * @brief Оператор проверки на неравенство
     * @param p Точка для сравнения
     * @return true, если точки не равны; иначе false
     */
    bool operator!=(const Point& p) const;
};
