#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  int N = 3;
  int v;
  int p;
  int h;
  int NOM;
  double min = 1000000;
  cout << "Введите скорость самолетов:"<<endl;
  cin >> v;
  cout << "Введите плотность воздуха:"<<endl;
  cin >> p;
  cout << "Введите высоту полета:"<<endl;
  cin >>h;
  double g = 9.81;
  double m[N] = {3000, 5000, 6000};
  double S[N] = {300, 200, 400};
  double tag[N] = {50, 40, 30};
  double Cd[N] = {0.2, 0.4, 0.3};
  double Cp[N] = {0.01, 0.04, 0.06};
  double L[N];
  double D[N];
  double a[N];
  double t[N];
  double ay[N];
    
  for(int i = 0; i<N; i++){
      L[i] = 0.5*p*v*v*S[i]*Cd[i];
      D[i] = 0.5*p*v*v*S[i]*Cp[i];
      a[i] = (tag[i] - D[i])/m[i];
      ay[i] = (L[i] - m[i]*g)/m[i];
    if (ay[i] > 0){
       t[i] = sqrt(2*h/ay[i]);
    }
    else{
        t[i] = 0;
    }
    if(min > t[i]){
        min = t[i];
        NOM = i;
    }
    cout << L[i] << "  " << D[i] << "  " << a[i] << "  " << ay[i] << "  " <<t[i] <<endl;
  }
  cout << "Быстрее самолет под номером:" << NOM + 1 << endl;
    return 0;
}