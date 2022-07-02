#include "Doctor.h"

Doctor::Doctor(string cedula, string nombre, string email, int edad, long numeroTelefonico): 
Persona( nombre,  email,  edad,  numeroTelefonico) {
  Doctor::cedula = cedula;
}

void Doctor::curar(Persona& p) {
  if(p.estaHerida) {
    hablar("curando a " + p._nombre + "...");
    p.estaHerida = false;
    hablar(p._nombre + " esta curado");
  } else {
    hablar(p._nombre + " no esta herido");
  }
}

void Doctor::operar(Persona p) {
  hablar("operando a " + p._nombre);
}