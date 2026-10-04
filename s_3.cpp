#include <iostream>
using namespace std;


int main()
{
    double m;
    double L;
    double D;
    double T;
    double a;
    double ay;
    double g = 9.8;

    cout << "Введите массу: ";
    cin >> m;
    cout << "Введите подъемную силу: ";
    cin >> L;
    cout << "Введите сопротивление: ";
    cin >> D;
    cout << "Введите тягу двигателя: ";
    cin >> T;
    
    a = (T - D)/m;
    ay = (L - m*g)/m;
   

    cout << "Ускорение по направлению движения a = " << a << endl;
    cout << "Ускорение вертикальное ay = " << ay << endl;

    return 0;
}