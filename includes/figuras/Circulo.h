#include <iostream>
#include <cstdlib>

using namespace std;

class Circulo {
public: 
  float radio, area, diametro;
  
  Circulo(float radioInicial = 0);
  ~Circulo();
  void calcularArea();
  void calcularDiametro();
  void status();
};