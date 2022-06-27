#include <iostream>

using namespace std;

/*
  * Herencia
  La herencia es uno de los mecanismos de los lenguajes de programación orientada a objetos 
  basados en clases, por medio del cual una clase se deriva de otra de manera que extiende su 
  funcionalidad.
  
  % En otras palabras
  Herencia es crear una clase nueva con los mismo metodos y props. que su clase madre
  
  * Clase Padre o Superclase
  La clase original la cual se está extendiendo
  
  * Clase Hija, clase derivada o Subclase
  La clase que hereda metodos y props. de la clase Madre
  
  * Heredar
  Compartir metodos y props.
  
  * Herencia simple
  Cuando una clase hereda de una sola clase padre
  
  * Herencia multiple
  Cuando una clase a varias clases padres
  
  https://e17r5k-datap1.s3-eu-west-1.amazonaws.com/evercorp-empleo-blog/s3fs-public/tipo-herencia.png
*/

struct Rectangulo {
public:
  float base, altura;
  
  // son los valores inciales
  Rectangulo(float _base = 1, float _altura = 1) {
    base = _base;
    altura = _altura;
  }
  
  // falta destructor
  // faltan operadores
  
  // Devuelve el area del rectangulo
  float area() { // get suena "guet" tambien es convencion
    return base * altura;
  }
  
  // Devuelve el area del rectangulo
  float perimetro() {
    return base * 2 + altura * 2;
  }
  
  // imprime los datos del rectangulo
  void status() {
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro() << endl;
  }
};

int main() {
  Rectangulo r;
  
  cout << "Este programa calcula los datos de un rectangulo\n";
  
  cout << "Ingrese la base del rectangulo: ";
  cin >> r.base;
  
  cout << "Ingrese la altura del rectangulo: ";
  cin >> r.altura;
  
  cout << "\nDatos de su rectangulo:\n";
  r.status();
  
  // char c;
  
  // cout << (int) 'a' << endl;
  // cout << (int) 'b' << endl;
  // cout << (int) 'A' << endl;
  
  // for(c = 65; c < 123; c++)
  // cout << c << " = " << (int) c << endl;
  
  // return 0;
}