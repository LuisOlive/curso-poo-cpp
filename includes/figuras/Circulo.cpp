#include "Circulo.h"

Circulo::Circulo(float radioInicial) {
  radio = radioInicial;
}
  
// el destructor se escribe igual que el constructor, pero con una tilde delante ~ (alt 126)
// los destructores nunca llevan parametros
Circulo::~Circulo() {
  // los destructores se ejecutan solos cuando nuestro programa ya no utiliza los objetos
  cout << "destructor ejecutandose con un radio de " << radio << endl;
  
  // se recomiendan valores que dañen al programa
  radio = -1;
  
  cout << "el destructor se ejecuto con un radio de " << radio << endl;
}

void Circulo::calcularArea() {
  area = 3.14159 * radio * radio;
}

void Circulo::calcularDiametro() {
  diametro = radio * 2;
}

void Circulo::status() {
  cout << "el radio es " << radio << "mm\n";
  cout << "el area es " << area << "mm2\n";
  cout << "el diametro es " << diametro << "mm2\n";
}