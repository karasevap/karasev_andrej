#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<double>height = {10.0, 5.0, 2.0, 8.0, 9.0, 10.0, 19.0, 56.0, 0.0, -58.0, -88.0, -2.0, -5.0, -57.0};
    vector<double>times = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0};
    
    auto it = find_if(height.begin(), height.end(), [](double h){return h <= 0;});
    
    cout << setw(15) << "t(c)" << setw(15) << "h(м)" << setw(15) << endl;
    for(size_t i=0; i < height.size(); i++){
        cout << setw(15) << times[i] << setw(15) << height[i] << setw(15) << endl;
    }
    
    if (it != height.end()){
        cout << "Момент падения найден, его высота:" << *it << endl;
        cout << "Время падения: " << times[it - height.begin()] << endl;
    }else{
        cout << "Падения не было" << endl;
    }
    return 0;

}