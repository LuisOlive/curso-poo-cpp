#include<iostream>
#include<cmath>

#include "includes/Complejo.h"

using namespace std;

int main(){
  // estas son cuatro instancias
  const Complejo i("i", 0, 1);
  Complejo a("a", 3,4), b("b", 5,-7), c("c",2,9), d("d", 3,-1), e("e"), f("f"), g("g");
  
  e = pow(a, 2);
  f = sqrt(a);
  
  g = 3 + a;
  
  // g = c;
  // a += c;
  // b++;
  
  cout << "Mi complejo a es " << a << endl;
  
  a.status();
  b.status();
  // c.status();
  // d.status();
  g.status();
  
  if(a > b)
    cout << "a es mayor que b\n";
  else
    cout << "a no es mayor que b\n";
  
  return 0;
}
