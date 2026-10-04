#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  int N = 7;
  int S;
  int Cd;
  cout << "Введите площадь:"<<endl;
  cin >> S;
  cout << "Введите коэффицент подъемной силы:"<<endl;
  cin >> Cd;
  double g = 9.81;
  double v[N] = {150, 151, 155, 156,160,175,180};
  double p[N] = {0.9, 0.8,0.75,0.63,0.6,0.54,0.4};
  double L[N];

    
  for(int i = 0; i<N; i++){
      L[i] = 0.5*p[i]*v[i]*v[i]*S*Cd;
      
    cout <<"| " << i+1 << "|  " << v[i] << "|  " << p[i] << "|  " << L[i] << endl;
  }

    return 0;
}