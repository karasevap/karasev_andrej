#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

struct Point1{
  double x1, y1, z1;
};
struct Point2{
  double x2, y2, z2;
};
struct Point3{
  double x3, y3, z3;
};
struct Point4{
  double x4, y4, z4;
};
struct Point5{
  double x5, y5, z5;
};
int main() {
    double g = 9.8;
    double dt = 1.0;
    double t_max = 10.0;
    double vx1=30;
    double vy1=20;
    double vz1=40;
    
    double vx2=26;
    double vy2=39;
    double vz2=67;
    
    double vx3=52;
    double vy3=20;
    double vz3=48;
    
    double vx4=55;
    double vy4=20;
    double vz4=40;
    
    double vx5=36;
    double vy5=25;
    double vz5=40;
    
    vector<Point1>traj1;
    vector<Point2>traj2;
    vector<Point3>traj3;
    vector<Point4>traj4;
    vector<Point5>traj5;
    
    double x1 = 0.0;
    double y1 = 0.0;
    double z1 = 0.0;
    
    double x2 = 0.0;
    double y2 = 0.0;
    double z2 = 0.0;
    
    double x3 = 0.0;
    double y3 = 0.0;
    double z3 = 0.0;
    
    double x4 = 0.0;
    double y4 = 0.0;
    double z4 = 0.0;
    
    double x5 = 0.0;
    double y5 = 0.0;
    double z5 = 0.0;
    
    traj1.push_back({x1,y1,z1});
    traj2.push_back({x2,y2,z2});
    traj3.push_back({x3,y3,z3});
    traj4.push_back({x4,y4,z4});
    traj5.push_back({x5,y5,z5});
    vector<double>times;
    for (double t=0.0; t <= t_max; t +=dt){
        x1 += vx1*dt;
        y1 += vy1*dt;
        z1 += vz1*dt;
        
        x2 += vx2*dt;
        y2 += vy2*dt;
        z2 += vz2*dt;
        
        x3 += vx3*dt;
        y3 += vy3*dt;
        z3 += vz3*dt;
        
        x4 += vx4*dt;
        y4 += vy4*dt;
        z4 += vz4*dt;
        
        x5 += vx5*dt;
        y5 += vy5*dt;
        z5 += vz5*dt;
        traj1.push_back({x1,y1,z1});
        traj2.push_back({x2,y2,z2});
        traj3.push_back({x3,y3,z3});
        traj4.push_back({x4,y4,z4});
        traj5.push_back({x5,y5,z5});
        times.push_back(t);
    }
    cout << setw(15) << "t(c)" << setw(15) << "x1" << setw(15) << "y1" << setw(15) << "z1" <<setw(15) << setw(15) << "x2" << setw(15) << "y2" << setw(15) << "z2" <<setw(15) <<setw(15) << "x3" << setw(15) << "y3" << setw(15) << "z3" <<setw(15) <<setw(15) << "x4" << setw(15) << "y4" << setw(15) << "z4" <<setw(15) << setw(15) << "x5" << setw(15) << "y5" << setw(15) << "z5" <<setw(15) << endl;
    for(size_t i=0; i<times.size(); i++){
        cout << setw(15) << times[i] << setw(15) << traj1[i].x1 << setw(15) << traj1[i].y1 << setw(15) << traj1[i].z1
 << setw(15) << traj2[i].x2 << setw(15) << traj2[i].y2 << setw(15) << traj2[i].z2
 << setw(15) << traj3[i].x3 << setw(15) << traj3[i].y3 << setw(15) << traj3[i].z3
 << setw(15) << traj4[i].x4 << setw(15) << traj4[i].y4 << setw(15) << traj4[i].z4
 << setw(15) << traj5[i].x5 << setw(15) << traj5[i].y5 << setw(15) << traj5[i].z5
 << setw(15) << endl;
    }
    
   
    return 0;

}