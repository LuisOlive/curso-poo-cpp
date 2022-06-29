/*
  * Herencia
  La herencia es uno de los mecanismos de los lenguajes de programación orientada a objetos 
  basados en clases, por medio del cual una clase se deriva de otra de manera que extiende su 
  funcionalidad.
  
  - clase Arbol
  una clase hija seria la clase Pino
  otra la clase Abedul
  
  - clase Auto
  clase hija: clase Autobús
  clase hija: clase Moto
  clase hija: clase Camioneta
  
  % En otras palabras
  Herencia es crear una clase nueva con los mismos metodos y props. que su clase padre
  
  * Clase Padre o Superclase
  La clase original la cual se está extendiendo
  - Rectangulo
  
  * Clase Hija, clase derivada o Subclase
  La clase que hereda metodos y props. de la clase Madre
  - Cuadrado
  
  * Heredar
  Compartir metodos y props.
  
  * Herencia simple
  Cuando una clase hereda de una sola clase padre
  
  * Herencia multiple
  Cuando una clase a varias clases padres
  
  * Polmorfismo
  Es la capcidad de los objetos a reaccionar de distintas maneras con un mismo método
  hay dos formas de manejarlo
  - Sobrecargas
  - Sobreescrituras de clases padre
  
  https://e17r5k-datap1.s3-eu-west-1.amazonaws.com/evercorp-empleo-blog/s3fs-public/tipo-herencia.png
*/

#include <iostream>

using namespace std;

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

/*
  Una clase que hereda de otra comparte todas sus caracteristicas

  Ya cunado ser implemmentó la herencia, hay que adaptar el codigo que ya se tenía
  a nuestras necesisdades
*/

// # Aquí se está heredando
// Un cuadrado tambien es un rectangulo
// la herencia se marca colocando : public [nombre de la clase superior]
class Cuadrado: public Rectangulo {
public:
  // al constructor, tambien se le ponen : y la clase superior
  Cuadrado(float lado = 1): Rectangulo(lado, lado) {
    
  }

  void setLados(float longitudLado) {
    base = longitudLado;
    altura = longitudLado;
  }
  
  // # sobreescritura de metodos
  void status() {
    cout << "Soy un cuadrado\n";
    // si quiero utilizar un metodo superior que estoy sobreescribiendo utilizo ::
    // # Polimorfismo
    Rectangulo::status();
  }
};

int main() {
  Rectangulo r(8,5);
  Cuadrado c(9);
  float x;
  
  cout << "Este programa calcula los datos de un cuadrado\n";
  
  // cout << "Ingrese la longitud de los lados cuadrado: ";
  // cin >> x;
  
  // r.setLados(x);
  
  cout << "\nDatos de su rectangulo:\n";
  r.status();
  
  
  cout << "\nDatos de su cuadrado:\n";
  c.status();
  
  // char c;
  
  // cout << (int) 'a' << endl;
  // cout << (int) 'b' << endl;
  // cout << (int) 'A' << endl;
  
  // for(c = 65; c < 123; c++)
  // cout << c << " = " << (int) c << endl;
  
  // return 0;
}