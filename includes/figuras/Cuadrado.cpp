#include "Cuadrado.h"

Cuadrado::Cuadrado(float lado): Rectangulo(lado, lado) {
    
}

void Cuadrado::setLados(float longitudLado) {
  base = longitudLado;
  altura = longitudLado;
}

void Cuadrado::status() {
  cout << "Soy un cuadrado\n";
  Rectangulo::status();
}