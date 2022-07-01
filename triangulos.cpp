#include "includes/figuras/Triangulo.h"

int main(){
  Triangulo t(3,4,5), t2(6,4,6.92);
  
  t.status();
  
  cout << endl;
  
  t2.status();
  
  return 0;
}