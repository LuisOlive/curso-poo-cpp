#include <iostream>
#include "Rectangulo.h"

#ifndef CUADRADO_H
#define CUADRADO_H

using namespace std;

class Cuadrado: public Rectangulo {
public:
  // al constructor, tambien se le ponen : y la clase superior
  Cuadrado(float lado = 1);

  void setLados(float lado = 1);

  void status();
};

#endif