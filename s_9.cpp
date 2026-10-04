#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  int N;
  int v;
  int p;
  int h;
  int NOM;
  double min = 0;
  cout << "Введите колво самолетов:"<<endl;
  cin >> N;
  cout << "Введите скорость самолетов:"<<endl;
  cin >> v;
  cout << "Введите плотность воздуха:"<<endl;
  cin >> p;
  cout << "Введите высоту полета:"<<endl;
  cin >>h;
  double g = 9.81;
  double m[N];
  double S[N];
  double tag[N];
  double Cd[N];
  double Cp[N];
  double L[N];
  double D[N];
  double ax[N];;
  double ay[N];
  double a[N];  
  for(int j  = 0; j<N; j++){
      cout << "Введите поочередно через пробел все параметры(масса площадь крыла тяга и коэффиценты Cd и Cp)" <<endl;
      cin >> m[j];
      cin >> S[j];
      cin >> tag[j];
      cin >> Cd[j];
      cin >> Cp[j];
  }
    
  for(int i = 0; i<N; i++){
      L[i] = 0.5*p*v*v*S[i]*Cd[i];
      D[i] = 0.5*p*v*v*S[i]*Cp[i];
      ax[i] = (tag[i] - D[i])/m[i];
      ay[i] = (L[i] - m[i]*g)/m[i];
      a[i] = sqrt(ax[i]*ax[i]+ay[i]*ay[i]);
    
    if(min < a[i]){
        min = a[i];
        NOM = i;
    }
    cout << L[i] << "  " << D[i] << "  " << ax[i] << "  " << ay[i] << "  " <<a[i] <<endl;
  }
  cout << "Большее ускорение у самолета под номером:" << NOM + 1 << endl;
    return 0;
}