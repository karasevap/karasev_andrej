#include <iostream>
#include <cmath>
using namespace std;


int main()
{
   double ay;
   double h;
   double t;
   cout  << "Введите ускорение ay; " << endl;
   cin >> ay;
   cout  << "Введите высоту h; " << endl; 
   cin >> h;
   if ((ay >= 0) && (h >= 0)){
       t = sqrt(2*h/ay);
       cout << "Время для набора заданной высоты t:" << t <<endl;
   }else{
       cout << "Вы ввели ускорение и высоту, меньшие нуля" <<endl;
   }
    return 0;
}