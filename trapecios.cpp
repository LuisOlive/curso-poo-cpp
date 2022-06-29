#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793; // PI
const double RAD_2_DEG = 180 / PI;

struct Rectangulo {
public:
  float base, altura;
  
  Rectangulo(float _base = 1, float _altura = 1) {
    base = _base;
    altura = _altura;
  }
  
  virtual float area() {
    return base * altura;
  }
  
  float perimetro() {
    return base * 2 + altura * 2;
  }

  void status() {
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro() << endl;
  }
};

class Triangulo {
public:
  float base, altura;
  
  Triangulo(float _base = 1, float _altura = 1) {
    base = _base;
    altura = _altura;
  }
  
  float area() {
    return base * altura / 2;
  }
  
  float perimetro() {
    return base + altura + hypot(base, altura);
  }
};

class Trapecio: public Rectangulo {
public:
  // como rectangulo ya tengo base y altura
  float cresta;
  
  Trapecio(float base, float altura, float _cresta):
    Rectangulo(_cresta, altura)
  {
    cresta = _cresta;
  }
  
  float area() {
    return 2 * Triangulo::area() + Rectangulo::area();
  }
  
  void status() {
    cout << "cresta: " << cresta << endl;
    Rectangulo::status();
  }
};

int main(){
  Trapecio trapecio(15, 6, 12);
  
  trapecio.status();
  
  return 0;
}