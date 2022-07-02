#include <iostream>

#include "Persona.h"

#ifndef DOCTOR_H
#define DOCTOR_H

using namespace std;

class Doctor: public Persona {
public:
  string cedula;
  
  Doctor(string cedula, string nombre, string email, int edad, long numeroTelefonico);
  
  void curar(Persona& p);
  
  void operar(Persona p);
};

#endif