#include <iostream>

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona {
private:
  string _nombre, _email;
  long _numeroTelefonico;
  int _edad;
  
public:
  bool estaHerida;

  Persona(); // los nombres de los parametros son opcionales
  Persona(const string nombre, const string email, const int edad, const long numeroTelefonico = 0); // los nombres de los parametros son opcionales
  ~Persona();
  void hablar(string);
  void status();
};

#endif