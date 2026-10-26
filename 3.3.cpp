#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    vector<double> times;
    vector<double> velocities;
    double g = 9.8;
    double v0=50.0;
    double dt = 1.0;
    double t_max = 50.0;
    double v;
    //const int estimated_steps = static_cast<int>(2.0 * v0 / g / dt) + 2;
    //times.reserve(estimated_steps);
    //heights.reserve(estimated_steps);
    for (double t=0.0; t <= t_max; t +=dt){
        v = v0 - g*t;
        if (v<-50.0) break;
        times.push_back(t);
        velocities.push_back(v);
    }
    cout << setw(10) << "t(c)" << setw(15) << "v(м/c)" << endl;
    for(size_t i=0; i<times.size(); i++){
        cout << setw(10) << fixed << setprecision(2) << times[i] << setw(15) << fixed << setprecision(2) << velocities[i] << endl;
    }
    double t_zero = v0 / g;
    cout << "Точный момент v = 0: t = "
              << t_zero << " с";
    return 0;

}