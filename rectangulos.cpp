#include "includes/figuras/Cuadrado.h"

int main() {
  Rectangulo r(8,5);
  Cuadrado c(9);
  float x;
  
  cout << "Este programa calcula los datos de un cuadrado\n";
  
  cout << "Ingrese la longitud de los lados cuadrado: ";
  cin >> x;
  
  c.setLados(x);
  
  cout << "\nDatos de su rectangulo:\n";
  r.status();
  
  cout << "\nDatos de su cuadrado:\n";
  c.status();
  
  return 0;
}