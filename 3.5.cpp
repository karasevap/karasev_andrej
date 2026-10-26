#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

struct Point{
  double x, y, z;
};
int main() {
    double g = 9.8;
    double dt = 1.0;
    double t_max = 40.0;
    double vx=30;
    double vy=20;
    double vz=40;
    vector<Point>traj;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    traj.push_back({x,y,z});
    vector<double>times;
    for (double t=0.0; t <= t_max; t +=dt){
        x += vx*dt;
        y += vy*dt;
        z += vz*dt;
        traj.push_back({x,y,z});
        times.push_back(t);
    }
    cout << setw(15) << "t(c)" << setw(15) << "x" << setw(15) << "y" << setw(15) << "z" <<setw(15) << endl;
    for(size_t i=0; i<times.size(); i++){
        cout << setw(15) << times[i] << setw(15) << traj[i].x << setw(15) << traj[i].y << setw(15) << traj[i].z
 << setw(15) << endl;
    }
    
    double t_last = times.size() - 1;
    cout << "Проверка" << endl;
    cout << "Посчитанное последнее значение х:  " << vx*t_last << endl;
    cout << "Значение х из массива: " << traj.back().x - traj[1].x;
    return 0;

}