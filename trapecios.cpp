/*
  * Composición
  la composicion se da cuando un objeto tiene una propiedad o varias que sean de otras clases
  
  * Abstracción
  Tener metodos y propiedades que la hagan pertenecer a un clase, se haya escrito o no
  
  - cumplir con una interfaz
  
  * Interfaz
  interfaz son los metodos y propiedades que debe cumplir un objeto para cosiderarse que 
  son de cierto tipo
  
  interface Carro {
    ruedas
    motor
    correr()
    detenerse()
  }
  
  si un objeto no tiene esto, no lo consiero un carro
  
  mesa: no tiene ruedas -> no es un carro
  silla de ruedas -> no tiene motor -> no es un carro
  silla de ruedas electrica -> sí tiene todo -> es un carro
  moto -> sí tiene todo -> es un carro
  
  % en c++ no hay sintaxis para las interfaces
*/

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
  
  float area() {
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
    return base + altura + hipotenusa();
  }
  
  float hipotenusa() {
    return hypot(base, altura);
  }
};

class Trapecio {
private: 
  // # desde aquí hay composicion
  Rectangulo rec;
  Triangulo triaIzq, triaDer;
  
public:
  // como rectangulo ya tengo base y altura
  float cresta, base, altura;
  
  Trapecio(float cresta, float base, float altura, float baseTrianguloDerecho = 0) {
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
    
    triaIzq.altura = altura;
    triaDer.altura = altura;
    
    // si se queda como 0,guarde ambas bases como el promedio
    triaDer.base = baseTrianguloDerecho || (base - cresta) / 2;
    
    /*
    triaDer.base = baseTrianguloDerecho || (base - cresta) / 2;
    
    es lo mismo que poner:
    
    if(baseTrianguloDerecho == 0) {
      triaDer.base = (base - cresta) / 2;
    } else {
      triaDer.base = baseTrianguloDerecho;
    }
    */
    
    triaIzq.base = base - cresta - triaDer.base;
  }
  
  ~Trapecio() {
    cresta =  -1;
    base = -1;
    altura =  -1;
  }
  
  float area() {
    return triaDer.area() + triaIzq.area() + rec.area();
  }
  
  float perimetro() {
    return base + cresta + triaDer.hipotenusa() + triaIzq.hipotenusa();
  }
  
  void status() {
    cout << "Cresta: " << cresta << endl;
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro() << endl;
  }
};

int main(){
  Trapecio trapecio(4, 10, 4);
  
  trapecio.status();
  
  return 0;
}