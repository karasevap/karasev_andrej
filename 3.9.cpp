#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void print_columns(const vector<double>& a,
                   const vector<double>& b,
                   const string& title_a,
                   const string& title_b) {
    cout << fixed << setprecision(2);
    cout << setw(8)  << "i"
         << setw(15) << title_a
         << setw(15) << title_b << "\n";
    cout << string(38, '-') << "\n";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << setw(8)  << i
             << setw(15) << a[i]
             << setw(15) << b[i] << "\n";
    }
}

int main() {
    const double v0 = 50.0, g = 9.8, dt = 0.5;
    vector<double> h_clean;
    for (double t = 0.0; t <= 10.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) break;
        h_clean.push_back(h);
    }

    srand(static_cast<unsigned>(time(nullptr)));
    vector<double> h_noisy(h_clean.size());
    for (size_t i = 0; i < h_clean.size(); ++i) {
        double noise = (rand() % 2001 - 1000) / 100.0;
        h_noisy[i] = h_clean[i] + noise;
    }

    const size_t n = h_noisy.size();
    vector<double> smoothed(n);

    smoothed[0]   = h_noisy[0];
    smoothed[n-1] = h_noisy[n-1];

    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h_noisy[i-1] + h_noisy[i] + h_noisy[i+1]) / 3.0;
    }

    print_columns(h_noisy, smoothed, "h_noisy", "smoothed");

    double mse_noisy = 0.0, mse_smooth = 0.0;
    for (size_t i = 0; i < n; ++i) {
        mse_noisy  += pow(h_noisy[i]  - h_clean[i], 2);
        mse_smooth += pow(smoothed[i] - h_clean[i], 2);
    }
    mse_noisy  /= n;
    mse_smooth /= n;

    cout << "" << mse_noisy  << "\n";
    cout << "" << mse_smooth << "\n";
    cout << "Улучшение: "
         << (mse_noisy - mse_smooth) / mse_noisy * 100.0
         << " %\n";

    return 0;
}