#include <iostream>
// primera regla,usar extencion .h
// #include "Persona.h"
// g++ main.cpp includes/**/* -o main && ./main.exe

// convencion: guardar las consas en una carpeta includes
#include "includes/constantesMatematicas.h"
#include "includes/personas/Persona.h"

#include "includes/figuras/Rectangulo.h"
#include "includes/figuras/Cuadrado.h" // si pido el cuadrado, tengo disponible la clase rectangulo

using namespace std;

int main(){
  Persona p("Luis", "luis@email.com", 21, 55785641);
  
  p.status();
  
  cout << PI * 2 * RAD_2_DEG << endl;
  
  return 0;
}