#include <stdio.h>
#include <math.h>
#include "var.h"

// Макроси для мінімізації коду
#define SQR(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) ((x) >= 0 ? (x) : -(x))

// Макрос для перевірки існування трикутника
#define IS_TRIANGLE(a, b, c) (((a) + (b) > (c)) && ((a) + (c) > (b)) && ((b) + (c) > (a)))

// Макрос для обчислення площі трикутника за формулою Герона
#define TRIANGLE_AREA(a, b, c) (sqrt(((a) + (b) + (c)) / 2.0 * (((a) + (b) + (c)) / 2.0 - (a)) * (((a) + (b) + (c)) / 2.0 - (b)) * (((a) + (b) + (c)) / 2.0 - (c))))

// Макрос для перевірки існування трапеції (основи та висота мають бути додатніми)
#define IS_TRAPEZOID(h1, h2, h) ((h1) > 0 && (h2) > 0 && (h) > 0)

// Макрос для обчислення площі трапеції
#define TRAPEZOID_AREA(h1, h2, h) (((h1) + (h2)) * (h) / 2.0)

int main() {
    // Введення значень для сторін трикутника та параметрів трапеції
    printf("Enter the sides of the triangle a, b, c:\n");
    scanf_s("%d %d %d", &a, &b, &c);

    if (IS_TRIANGLE(a, b, c)) {
        // Якщо трикутник існує, обчислюємо його площу
        double area = TRIANGLE_AREA(a, b, c);
        printf("The area of the triangle: %.2f\n", area);
    }
    else {
        printf("A triangle cannot exist.\n");

        // Якщо трикутник не існує, вводимо значення для трапеції
        printf("Enter the bases of the trapezoid h1, h2 and the height h:\n");
        scanf_s("%d %d %d", &h1, &h2, &h);

        if (IS_TRAPEZOID(h1, h2, h)) {
            // Якщо трапеція існує, обчислюємо її площу
            double area = TRAPEZOID_AREA(h1, h2, h);
            printf("The area of the trapezoid: %.2f\n", area);
        }
        else {
            // Якщо трапеція не може існувати, виводимо повідомлення про помилку
            printf("Error: A trapezoid cannot exist with these parameters.\n");
        }
    }

    return 0;
}
