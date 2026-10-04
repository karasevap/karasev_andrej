#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  double a;
  double ax;
  double ay;
  double T;
  double D;
  double L;
  double m;
  double g = 9.81;
  cout << "Введите тягу" <<endl;
  cin >> T;
  cout << "Введите сопротивление" <<endl;
  cin >> D;
  cout << "Введите подъемную силу" <<endl;
  cin >> L
  cout << "Введите массу" <<endl;
  cin >> m;
  ax = (T-D)/m;
  ay = (L - m*g)/m;
  a = sqrt(ax*ax+ay*ay);
  if (a > 0.5){
    cout << "Режим набора высоты" << endl;
  }else if((a>0)&&(a<0.5)){
    cout << "Режим горизонтальный полет" << endl;
  }else if(a < 0){
    cout << "Режим снижение" << endl;
  }

    return 0;
}