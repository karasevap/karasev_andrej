#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    vector<double>height = {0.0, 5.0, 2.0, 8.0, 9.0, 10.0, 19.0, 56.0, 38.0, 58.0, 88.0, 2.0, 5.0, 56.0, 57.0};
    cout << "Массив до удаления элементов: " << endl;
    cout << setw(10) << "h(м)" << setw(10) << endl;
    for(size_t i = 0; i < height.size(); i++){
        cout << setw(10) << height[i] << setw(10) << endl;
    }
    height.erase(remove_if(height.begin(), height.end(), [](double h){return h < 10;}),height.end());
    cout << "Новый массив: " << endl;
    for (size_t j = 0;j < height.size(); j++){
        cout << setw(10) << height[j] << setw(10) << endl;
    }
    return 0;

}