#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    const double rho = 1.225;
    const double V = 200.0;
    const double g = 9.81;

    double mass, S, CL, CD;
    double h;
    double Tmin, Tmax, dT;

    cout << "Введите массу самолета m (кг): ";
    cin >> mass;
    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;
    cout << "Введите коэффициент подъемной силы CL: ";
    cin >> CL;
    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;
    cout << "Введите высоту набора h (м): ";
    cin >> h;

    cout << "Введите Tmin (Н): ";
    cin >> Tmin;
    cout << "Введите Tmax (Н): ";
    cin >> Tmax;
    cout << "Введите шаг dT (Н): ";
    cin >> dT;

    double L = 0.5 * rho * V * V * S * CL;
    double D = 0.5 * rho * V * V * S * CD;

    double bestT = -1.0;
    double bestTime = -1.0;
    double bestAy = 0.0;

    cout << " Перебор значений тяги";
    cout << setw(12) << "T (Н)"
         << setw(14) << "ay (м/с^2)"
         << setw(14) << "t (с)" << endl;
    cout << string(40, '-') << endl;

    cout << fixed << setprecision(3);

    for (double T = Tmin; T <= Tmax + 1e-9; T += dT) {
        double ay = (L - mass * g) / mass;

        double t;
        if (ay > 0) {
            t = sqrt(2.0 * h / ay);
        } else {
            t = -1.0;
        }

        cout << setw(12) << T
             << setw(14) << ay;
        if (t >= 0)
            cout << setw(14) << t << endl;
        else
            cout << setw(14) << "невозможно" << endl;

        if (t >= 0) {
            if (bestTime < 0 || t < bestTime) {
                bestTime = t;
                bestT = T;
                bestAy = ay;
            }
        }
    }

    cout << " Оптимальное значение ";
    if (bestT >= 0) {
        cout << "Оптимальная тяга T* = " << bestT << " Н";
        cout << "Вертикальное ускорение ay = " << bestAy << " м/с^2";
        cout << "Минимальное время набора высоты " << h << " м = "
             << bestTime << " с";
    } else {
        cout << "Ни при одном значении тяги самолет не может набрать высоту";
    }

    return 0;
}