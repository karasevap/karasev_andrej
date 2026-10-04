#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Aircraft {
    const char* name;
    double mass;
    double thrust;
    double S;
    double CL;
    double CD;
};

int main() {
    const int N = 3;
    const double rho = 1.225;
    const double V = 200.0;
    const double g = 9.81;

    double h;
    cout << "Введите высоту набора h (м): ";
    cin >> h;

    Aircraft planes[N] = {
        {"Boeing-737",  70000.0, 200000.0, 120.0, 0.6,  0.03},
        {"Airbus-A320", 75000.0, 220000.0, 125.0, 0.65, 0.028},
        {"Cessna-172",   1100.0,   5000.0,  16.0, 0.9,  0.045}
    };

    double ay[N];
    double t[N];

    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho * V * V * planes[i].S * planes[i].CL;
        double D = 0.5 * rho * V * V * planes[i].S * planes[i].CD;

        ay[i] = (L - planes[i].mass * g) / planes[i].mass;

        if (ay[i] > 0) {
            t[i] = sqrt(2.0 * h / ay[i]);
        } else {
            t[i] = -1.0;
        }
    }

    int idx[N];
    for (int i = 0; i < N; i++) idx[i] = i;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            bool swapNeeded = false;
            if (t[idx[j]] < 0 && t[idx[j + 1]] >= 0) swapNeeded = true;
            else if (t[idx[j]] >= 0 && t[idx[j + 1]] >= 0 && t[idx[j]] > t[idx[j + 1]]) swapNeeded = true;

            if (swapNeeded) {
                int tmp = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = tmp;
            }
        }
    }

    cout << "Результаты (отсортировано по времени набора высоты)";
    cout << left << setw(15) << "Самолет"
         << right << setw(12) << "ay (м/с^2)"
         << setw(14) << "t (с)" << endl;
    cout << string(41, '-') << endl;

    cout << fixed << setprecision(3);
    for (int k = 0; k < N; k++) {
        int i = idx[k];
        cout << left << setw(15) << planes[i].name
             << right << setw(12) << ay[i];
        if (t[i] >= 0)
            cout << setw(14) << t[i] << endl;
        else
            cout << setw(14) << "не может" << endl;
    }

    return 0;
}