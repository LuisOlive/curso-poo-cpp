#include <iostream>
#include <cmath>

#include "../constantesMatematicas.h"

#ifndef TRIANGULO_H
#define TRIANGULO_H

using namespace std;

class Triangulo {
public:
  float ladoAB, ladoAC, ladoBC;
  
  Triangulo(float ladoAB, float ladoAC, float ladoBC);
  
  ~Triangulo();
  
  float anguloA();
  float anguloB();
  float anguloC();
  
  void status();
  
  float leyCosenos(float a, float b, float c);
  
  float perimetro();
  float area();
  float semiPerimetro();
};

#endif
