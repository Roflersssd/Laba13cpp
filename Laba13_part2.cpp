#include <iostream>
#include <math.h>
#include <locale.h>

const double pi = 4*atan(1);//Число пи


double F(double x);//Заданная функция

double Integral(double(*f)(double), double a, double b, double eps);//Функция поиска интеграла

double CalculateMamber(double(*f)(double), double a, double b, int n);//Функция вычисления очередного приближения

int main()
{
    setlocale(LC_ALL, "rus");
    double a = pi / 2;
    double b = pi;
    const double eps = 0.005;
    printf("Интервал [%.2f;%.2f]\n", a, b);
    printf("Погрешность eps=%.3f\n", eps);
    double res = Integral(F, a, b,eps);
    printf("Интеграл f(x)=cos(x)/x на отрезке [%.2f,%.2f]= %f\n", a, b, res);
    
}//main

double F(double x) {
    return cos(x) / x;
}//F


double Integral(double(*f)(double), double a, double b, double eps) {
    int n = 10;//количество на которое делится отрезок 
    int k = 5;//Увеличение разбиения отрезка за одну итерацию
    double h;//шаг
    double s0, s1;
    do {
        s0 = CalculateMamber(f, a, b, n);
        n += k;
        s1 = CalculateMamber(f, a, b, n);

    } while (abs(s0 - s1) > eps);
    return s1;
}//Integral

double CalculateMamber(double(*f)(double), double a, double b, int n) {
    double s = 0;
    double h = (b - a) / n;
    for (int i = 0; i < n; i++) {
        s += f(a + h * i) * h;
    }//for
    s += ((f(a) + f(b)) / 2) * h;
    return s;
}//CalculateMamber
