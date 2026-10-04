#include <iostream>
using namespace std;

double cal(double p, double V, double S, double CD)
{
    double D = 0.5 * p * V * V * S * CD;
    return D;
}

int main()
{
    double p;
    double V;
    double S;
    double CD;

    cout << "Введите плотность воздуха p (кг/м^3): ";
    cin >> p;
    cout << "Введите скорость полета V (м/с): ";
    cin >> V;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;

    double dm = cal(p, V, S, CD);

    cout << "Аэродинамическое сопротивление D = " << dm << " Н" << endl;

    return 0;
}