#include "Trapecio.h"

Trapecio::Trapecio(float cresta, float base, float altura, float baseTrianguloDerecho) {
  Trapecio::cresta = cresta;
  Trapecio::base = base;
  Trapecio::altura = altura;
  
  /*
    .        cresta
    .     _____________
    .   /||          \\\    
    .  / ||          \\ \    
    . --------------------
    . \---\---------\-----\
    .   x'  cresta     x'
    . |--------------------|
    .         base
  */
  
  rec.base = cresta;
  rec.altura = altura;
  
  triaIzq.setAltura(altura);
  triaDer.setAltura(altura);
  
  if(baseTrianguloDerecho == 0) {
    triaDer.setBase((base - cresta) / 2);
  } else {
    triaDer.setBase(baseTrianguloDerecho);
  }
  
  triaIzq.setBase(base - cresta - triaDer.base());
}

Trapecio::~Trapecio() {
  cresta =  -1;
  base = -1;
  altura =  -1;
}

float Trapecio::area() {
  return triaDer.area() + triaIzq.area() + rec.area();
}

float Trapecio::perimetro() {
  return base + cresta + triaDer.hipotenusa() + triaIzq.hipotenusa();
}

void Trapecio::status() {
  cout << "Cresta: " << cresta << endl;
  cout << "Base: " << base << endl;
  cout << "Altura: " << altura << endl;
  cout << "Area: " << area() << endl;
  cout << "Perimetro: " << perimetro() << endl;
}
