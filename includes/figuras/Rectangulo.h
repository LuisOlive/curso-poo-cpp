#include <iostream>

#ifndef RECTANGULO_H
#define RECTANGULO_H

using namespace std;

struct Rectangulo {
public:
  float base, altura;
  
  // son los valores inciales
  Rectangulo(float base = 1, float altura = 1);
  
  // Devuelve el area del rectangulo
  float area();
  
  // Devuelve el area del rectangulo
  float perimetro();
  
  // imprime los datos del rectangulo
  void status();
};

#endif