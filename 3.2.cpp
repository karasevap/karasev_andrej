#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


int main() {
    vector<double> times;
    vector<double> heights;
    double g = 9.8;
    double v0=50.0;
    double dt = 1.0;
    double h = 0.0;
    const int estimated_steps = static_cast<int>(2.0 * v0 / g / dt) + 2;
    times.reserve(estimated_steps);
    heights.reserve(estimated_steps);
    for (double t=0.0; t <= 50.0; t +=dt){
        h = v0*t - 0.5*g*t*t;
        if (h<0) break;
        times.push_back(t);
        heights.push_back(h);
    }
    size_t idx_max =0;
    for(size_t i = 1;i < heights.size(); ++i){
        if(heights[i] > heights[idx_max]){
            idx_max = i;
        }
    }
    cout << setw(10) << "t(c)" << setw(15) << "h(м)" << endl;
    for(size_t i=0; i<times.size(); i++){
        cout << setw(10) << fixed << setprecision(2) << times[i] << setw(15) << fixed << setprecision(2) << heights[i] << endl;
    }
    cout << idx_max << endl;
    cout << heights[idx_max] << endl;
    cout << times[idx_max] << endl;
    return 0;

}