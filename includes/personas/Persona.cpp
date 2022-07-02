#include "Persona.h"

Persona::Persona() {}

Persona::Persona(const string nombre, const string email, const int edad, const long numeroTelefonico) { // no es necesario volver a poner el valor por defecto
  _nombre = nombre;
  _email = email;
  _edad = edad;
  _numeroTelefonico = numeroTelefonico;
  
  estaHerida = false;
}
  
Persona::~Persona() {
  cout << _nombre << " ha muerto. QEPD\n";
  _nombre = "";
  _numeroTelefonico = 0;
  _edad = -1;
  _email = "";
}

void Persona::hablar(string mensaje) {
  cout << _nombre << " dice: " << mensaje << endl;
}

void Persona::status() {
  cout << "nombre: " << _nombre << endl;
  cout << "email: " << _email << endl;
  cout << "telefono: " << _numeroTelefonico << endl;
  cout << "edad: " << _edad << endl;
}