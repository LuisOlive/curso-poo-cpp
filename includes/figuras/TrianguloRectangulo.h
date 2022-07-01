#include <iostream>

#include "Triangulo.h"

#ifndef TRIANGULO_RECTANGULO_H
#define TRIANGULO_RECTANGULO_H

using namespace std;

class TrianguloRectangulo: public Triangulo {
public:
  TrianguloRectangulo(float base = 1, float altura = 1);
  
  float base();
  float altura();
  float hipotenusa();
  
  float setBase(float x);
  float setAltura(float x);
};

#endif