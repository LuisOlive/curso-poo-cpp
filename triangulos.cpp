#include<iostream>
#include<cmath>

const double PI = 3.141592653589793; // PI
const double RAD_2_DEG = 180 / PI;

using namespace std;

class Triangulo {
public:
  float ladoA, ladoB, ladoC; // B es la base
  
  Triangulo(float _ladoA, float _ladoB, float _ladoC) {
    ladoA = _ladoA;
    ladoB = _ladoB;
    ladoC = _ladoC;
  }
  
  ~Triangulo() {
    ladoA = ladoB = ladoC = 0;
  }
  
  float perimetro() {
    return ladoA + ladoB + ladoC;
  }
  
  float anguloA() {
    return leyCosenos(ladoB, ladoC, ladoA);
  }
  float anguloB() {
    return leyCosenos(ladoA, ladoC, ladoB);
  }
  float anguloC() {
    return leyCosenos(ladoA, ladoB, ladoC);
  }
  
  void status() {
    cout << "Perimetro: " << perimetro() << endl;
    cout << "Base: " << base() << endl;
    cout << "Altura: " << altura() << endl;
    cout << "Area: " << area() << endl;
    cout << "Angulo A: " << anguloA() * RAD_2_DEG << endl;
    cout << "Angulo B: " << anguloB() * RAD_2_DEG << endl;
    cout << "Angulo C: " << anguloC() * RAD_2_DEG << endl;
  }
  
  float leyCosenos(float a, float b, float c) {
    // https://www.universoformulas.com/matematicas/trigonometria/teorema-coseno/#:~:text=Mediante%20el%20teorema%20del%20coseno,producto%20de%20los%20lados%20contiguos.
  
    return acos((a*a + b*b - c*c) / (2*a*b));
  }
  
  float base() {
    return ladoB;
  }
  
  float altura() {
    // http://serbal.pntic.mec.es/lbac0014/Trigonometria/area.htm#:~:text=El%20%C3%A1rea%20de%20un%20tri%C3%A1ngulo,el%20seno%20del%20%C3%A1ngulo%20comprendido.
    return ladoA * sin(anguloC());
  }
  
  float area() {
    return base() * altura() / 2;
  }
};

int main(){
  Triangulo t(3,4,5), t2(6,4,6.92);
  
  t.status();
  
  cout << endl;
  
  t2.status();
  
  return 0;
}