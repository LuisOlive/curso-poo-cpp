#include<iostream>
#include<cmath>

#include "constantesMatematicas.h"

#ifndef COMPLEJO_H
#define COMPLEJO_H

using namespace std;

class Complejo {
  public:
  float real, imaginaria;
  string nombre;
  
  // Crea una instancia anonima de un complejo, sin paramteros se crea un 0 + 0i
  Complejo(float re = 0, float im = 0);
  
  // Crea una instancia nombrada de complejo, sin paramteros se crea un 0 + 0i
  Complejo(string nombre, float re = 0, float im = 0);
  
  // este es el destructor
  ~Complejo();

  // muestra la info del numero complejo en su forma rectangular
  void status();
  
  // muestra la info del numero complejo en su forma polar
  void statusPolar();
  
  float argumento();
  float modulo();
  Complejo conjugado();
  
  Complejo mas(Complejo otro);
  Complejo mas(float re = 0, float im = 0);
  Complejo menos(Complejo otro);
  Complejo menos(float re = 0, float im = 0);
  Complejo por(Complejo otro);
  Complejo por(float re = 0, float im = 0);
  Complejo entre(Complejo otro);
  Complejo entre(float re = 0, float im = 0);
  
  bool esMayorOIgualQue(Complejo otro);
  bool esMayorQue(Complejo otro);
  bool esMenorQue(Complejo otro);
  
  Complejo operator * (Complejo otro);
  Complejo operator + (Complejo otro);
  Complejo operator + (float re);
  Complejo operator - (Complejo otro);
  Complejo operator / (Complejo otro);
  
  bool operator < (Complejo otro);
  bool operator == (Complejo otro);
  bool operator > (Complejo otro);
  bool operator >= (Complejo otro);
  
  void operator ++ (int _);
  void operator += (Complejo otro);
  void operator = (Complejo otro);
};

Complejo pow(Complejo z, float n);

Complejo sqrt(Complejo z);

Complejo operator + (float x, Complejo z);

ostream& operator << (ostream& _cout,  Complejo z);

#endif