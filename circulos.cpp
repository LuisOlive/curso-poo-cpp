/*
  * Constructores y destructores
  
  * En el constructor 
  se asignan los valores iniciales del nuevo objeto. 
  
  * Un destructor  
  es una función miembro especial llamadas automáticamente en la ejecución del programa, y por tanto no tienen por qué ser llamadas explícitamente por el programador.

*/
#include <iostream>
#include <cstdlib>

using namespace std;

class Circulo {
public: 
  float radio;
  float area;
  float diametro;
  
  // un constructor da valores iniciales al objeto
  // es una funcion con el mismo nombre de la clase y sin escribirle el tipo de dato de retorno
  Circulo(float radioInicial) {
    radio = radioInicial;
  }
  
  // el destructor se escribe igual que el constructor, pero con una tilde delante ~ (alt 126)
  // los destructores nunca llevan parametros
  ~Circulo() {
    // los destructores se ejecutan solos cuando nuestro programa ya no utiliza los objetos
    cout << "destructor ejecutandose con un radio de " << radio << endl;
    
    // se recomiendan valores que dañen al programa
    radio = -1;
    
    cout << "el destructor se ejecuto con un radio de " << radio << endl;
  }
  
  void calcularArea() {
    area = 3.14159 * radio * radio;
  }
  
  void calcularDiametro() {
    diametro = radio * 2;
  }
  
  void estatus() {
    cout << "el radio es " << radio << "mm\n";
    cout << "el area es " << area << "mm2\n";
    cout << "el diametro es " << diametro << "mm2\n";
  }
};

int main() {
  cout << "Este programa calcula el area de un circulo\n";
  
  Circulo c(3.45), c2(8); // ahora cuando instanciemos, hay que pasarle valores iniciales
  
  c.calcularArea();
  c.calcularDiametro();
  c.estatus();
  
  c2.calcularArea();
  c2.calcularDiametro();
  c2.estatus();
  
  // aquí ya no se usan los objetos.
  // se destruyen del ultimo al primero en instanciarse
  /*
    Este programa calcula el area de un circulo
    el radio es 3.45mm
    el area es 37.3928mm2
    el diametro es 6.9mm2
    el radio es 8mm
    el area es 201.062mm2
    el diametro es 16mm2
    destructor ejecutandose con un radio de 8
    el destructor se ejecuto con un radio de -1
    destructor ejecutandose con un radio de 3.45
    el destructor se ejecuto con un radio de -1
  */
  return 0;
}