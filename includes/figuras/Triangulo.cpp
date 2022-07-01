#include "Triangulo.h"

Triangulo::Triangulo(float ladoAB, float ladoAC, float ladoBC) {
  Triangulo::ladoBC = ladoBC;
  Triangulo::ladoAC = ladoAC;
  Triangulo::ladoAB = ladoAB;
}

Triangulo::~Triangulo() {
  ladoBC = ladoAC = ladoAB = 0;
}

float Triangulo::anguloA() {
  return leyCosenos(ladoAC, ladoAB, ladoBC);
}
float Triangulo::anguloB() {
  return leyCosenos(ladoBC, ladoAB, ladoAC);
}
float Triangulo::anguloC() {
  return leyCosenos(ladoBC, ladoAC, ladoAB);
}

void Triangulo::status() {
  cout << "Perimetro: " << perimetro() << endl;
  cout << "Lado AB: " << ladoAB << endl;
  cout << "Lado AC: " << ladoAC << endl;
  cout << "Lado BC: " << ladoBC<< endl;
  cout << "Angulo A: " << anguloA() * RAD_2_DEG << endl;
  cout << "Angulo B: " << anguloB() * RAD_2_DEG << endl;
  cout << "Angulo C: " << anguloC() * RAD_2_DEG << endl;
}

float Triangulo::leyCosenos(float a, float b, float c) {
  // https://www.universoformulas.com/matematicas/trigonometria/teorema-coseno/#:~:text=Mediante%20el%20teorema%20del%20coseno,producto%20de%20los%20lados%20contiguos.

  return acos((a*a + b*b - c*c) / (2*a*b));
}

float Triangulo::area() {
  // formula de heron: https://www.matematicas18.com/es/tutoriales/geometria/figuras-geometricas/triangulo/triangulo-escaleno/
  const float s = semiPerimetro();
  return sqrt(s * (s - ladoAB) * (s - ladoAC) * (s - ladoBC));
}

float Triangulo::semiPerimetro() {
  return perimetro() / 2;
}

float Triangulo::perimetro() {
  return ladoBC + ladoAC + ladoAB;
}