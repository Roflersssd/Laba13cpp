#include <iostream>
#include<cstdlib>
#include <math.h>
using namespace std;

const double Q = 0.001;//Погрешность
const double a =0.5;//Начало отрезка
const double b = 0.6;//Конец отрезка

double f(double x);
//Функция поиска корня:
double FindRoot(double(*f)(double), double a, double b, double Q);

int main() {
    //Интервал, погрешность и корень:
    double x;
    cout << "interval:["<<a<<':'<<b<<"]\n";
    //Проверка корректности интервала:
    cout << "epsilon: "<<Q<<endl;
    //Поиск решения:
    x = FindRoot(f,a, b, Q);
    cout << "x = " << x << endl;
    return 0;
}

double f(double x) {
    return x * x - sin(5 * x);
}
//Функция поиска корня:
double FindRoot(double(*f)(double), double a, double b, double Q) {
    double x;
    if (a == b) {
        cout << "Error. Root can`t be found\n";
        return -1;
    }
    else if (b - a < Q) {
        return a;
    }
    else {
        do {
            x = (a * f(b) - b * f(a)) / (f(b) - f(a));
            if (f((a + x) / 2) > 0) {
                b = x;
            }
            else a = x;

        } while (fabs(f(x)) > Q);
    }
    return x;
}
