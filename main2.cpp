/*
  .1 Prototipos
  .2 parametros const
  .3 parametros por defecto con prototipo
  .4 plantillas
  template <class T>
  .5 elementos amigos
  dentro de la clase: keyword friend
  .6 separacion de archivos
*/
#include<iostream>

using namespace std;

// # este es un prototipo de clase
class Persona {
private:
  string _nombre, _email;
  long _numeroTelefonico;
  int _edad;
  float dinero;
  
public:  
  // # prototipos de metodo
  Persona(); // los nombres de los parametros son opcionales
  Persona(const string nombre, const string email, const int edad, const long numeroTelefonico = 0); // los nombres de los parametros son opcionales
  ~Persona();
  void hablar(string);
  void status();
  
  friend class CuentaBancaria; // ahora la clase CuentaBancaria tiene acceso a atributos privados de Persona
};

struct CuentaBancaria {
private:
  Persona p;
public:
  CuentaBancaria();
  CuentaBancaria(const Persona p);
  void hacerTransaccion();
};

int main(){
  return 0;
}

CuentaBancaria::CuentaBancaria(const Persona p) {
  CuentaBancaria::p = p;
}

void CuentaBancaria::hacerTransaccion() {
  cout << "transfiriendo dinero a " << p._nombre << endl;
}

Persona::Persona() {}

Persona::Persona(const string nombre, const string email, const int edad, const long numeroTelefonico) { // no es necesario volver a poner el valor por defecto
  _nombre = nombre;
  _email = email;
  _edad = edad;
  _numeroTelefonico = numeroTelefonico;
}
  
Persona::~Persona() {
  _nombre = "";
  _numeroTelefonico = 0;
  _edad = -1;
  _email = "";
}

void Persona::hablar(string mensaje) {
  cout << _nombre << "dice : " << mensaje << endl;
}

void Persona::status() {
  cout << "nombre: " << _nombre << endl;
  cout << "email: " << _email << endl;
  cout << "telefono: " << _numeroTelefonico << endl;
  cout << "edad: " << _edad << endl;
}