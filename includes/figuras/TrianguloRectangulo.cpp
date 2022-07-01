#include "TrianguloRectangulo.h"

TrianguloRectangulo::TrianguloRectangulo(float base, float altura):
  Triangulo(base, altura, hypot(base, altura))
{}
  
float TrianguloRectangulo::base() {
  return ladoAB;
}

float TrianguloRectangulo::altura() {
  return ladoAC;
}

float TrianguloRectangulo::hipotenusa() { 
  return ladoBC;
}

float TrianguloRectangulo::setBase(float x) {
  ladoAB = x;
  ladoBC = hypot(ladoAB, ladoAC);
  return ladoAB;
}

float TrianguloRectangulo::setAltura(float x) {
  ladoAC = x;
  ladoBC = hypot(ladoAB, ladoAC);
  return ladoAC;
}