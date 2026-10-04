#include <iostream>

using namespace std;

int main() {
    double S;   
    double V;   
    double p; 
    double CL;  


    cout << "Введите площадь крыла S (м^2): " <<endl;
    cin >> S;
    cout << "Введите скорость полета V (м/с): " << endl;
    cin >> V;
    cout << "Введите плотность воздуха rho (кг/м^3): " << endl;
    cin >> p;
    cout << "Введите коэффициент подъемной силы CL: " << endl;
    cin >> CL;

    double L = 0.5 * p * V * V * S * CL;

    cout << "Подъемная сила L = " << L << " Н" << endl;

    return 0;
}