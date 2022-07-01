#include <iostream>

#include "Rectangulo.h"
#include "TrianguloRectangulo.h"

#ifndef TRAPECIO_H
#define TRAPECIO_H

using namespace std;

class Trapecio {
private:
  Rectangulo rec;
  TrianguloRectangulo triaIzq, triaDer;
  
public:
  // como rectangulo ya tengo base y altura
  float cresta, base, altura;
  
  Trapecio(float cresta, float base, float altura, float baseTrianguloDerecho = 0);
  
  ~Trapecio();
  
  float area();
  
  float perimetro();
  
  void status();
};

#endif