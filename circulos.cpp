#include <iostream>

#include "includes/figuras/Circulo.h"

using namespace std;

int main() {
  cout << "Este programa calcula el area de un circulo\n";
  
  Circulo c(3.45), c2(8); // ahora cuando instanciemos, hay que pasarle valores iniciales
  
  c.calcularArea();
  c.calcularDiametro();
  c.estatus();
  
  c2.calcularArea();
  c2.calcularDiametro();
  c2.estatus();
  
  return 0;
}