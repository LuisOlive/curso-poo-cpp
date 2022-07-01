#include "Rectangulo.h"

Rectangulo::Rectangulo(float base, float altura) {
  Rectangulo::base = base;
  Rectangulo::altura = altura;
}

float Rectangulo::area() { // get suena "guet" tambien es convencion
  return base * altura;
}

float Rectangulo::perimetro() {
  return base * 2 + altura * 2;
}

void Rectangulo::status() {
  cout << "Base: " << base << endl;
  cout << "Altura: " << altura << endl;
  cout << "Area: " << area() << endl;
  cout << "Perimetro: " << perimetro() << endl;
}