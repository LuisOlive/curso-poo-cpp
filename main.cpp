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

class Persona {
public:
  string nombre, email;
  long telefono;
  int edad;
  
  Persona(string _nombre, string _email, int _edad, long _numeroTarjeta, long _telefono) {
    nombre = _nombre;
    email = _email;
    edad = _edad;
    telefono = _telefono;
  }
  
  ~Persona() {
    nombre = "";
    telefono = 0;
    edad = -1;
  }
};

int main() {
  cout << "Programa aadministrativo\n";
  
  
  return 0;
}