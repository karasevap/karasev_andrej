#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<double>height1 = {10.0, 5.0, 2.0, 8.0, 95.0, 10.0, 19.0, 56.0, 0.0, -58.0, -88.0, -2.0, -5.0, -57.0};
    vector<double>times1 = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0};
    vector<double>height2 = {7.0, 5.0, 2.0, 8.0, 9.0, 67.0, 79.0, 56.0, 90.0, 88.0, 84.0, 0.0, -5.0, -57.0};
    vector<double>times2 = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0};
    
    
    cout << setw(15) << "h1" << setw(15) << "t1" << setw(15) << "h2" << setw(15) << "t2" << setw(15) << endl;
    for(size_t i=0; i < height1.size(); i++){
        cout << setw(15) << height1[i] << setw(15) << times1[i] << setw(15) << height2[i] << setw(15) << times2[i] << setw(15) << endl;
    }
   
    
    auto max_it1 = max_element(height1.begin(), height1.end());
    auto max_it2 = max_element(height2.begin(), height2.end());
    if (*max_it1 > *max_it2){
        cout << "Поднялась выше ракета 1 на высоту " << *max_it1 << endl;
        cout << "Поднялась на эту высоту за время: " << times1[(max_it1-height1.begin())] << endl;
    }else if(*max_it1 < *max_it2){
        cout << "Поднялась выше ракета 2 на высоту " << *max_it2 << endl;
        cout << "Поднялась на эту высоту за время: " << times2[(max_it2-height2.begin())] << endl;
    }else if (*max_it1 == *max_it2){
        cout << "Поднялась обе ракеты на одинаковую высоту" << *max_it2 << endl;
        cout << "Поднялась 1 на эту высоту за время: " << times1[(max_it1-height1.begin())] << endl;
        cout << "Поднялась 2 на эту высоту за время: " << times2[(max_it2-height2.begin())] << endl;
   }
   
   auto it1 = find_if(height1.begin(), height1.end(), [](double h1){return h1 <= 0;});
   auto it2 = find_if(height2.begin(), height2.end(), [](double h2){return h2 <= 0;});
   double vr1 = it1 - height1.begin();
   double vr2 = it2 - height2.begin();
   if (vr1 < vr2) {
       cout << "Первой упала ракета 1, время падения: " << times1[vr1] << endl;
       cout << "Время падения ракеты 2: " << times2[vr2] << endl;
   }else if(vr2 < vr1){
       cout << "Первой упала ракета 2, время падения: " << times2[vr2] << endl;
       cout << "Время падения ракеты 1: " << times1[vr1] << endl;
   }else if(vr1 == vr2){
       cout << "Ракеты упали одновременно, время их падения: "<< times1[vr1] << endl;
   }
   
    return 0;

}