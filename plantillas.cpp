#include <iostream>
#include "includes/Complejo.h"
#include "includes/figuras/Circulo.h"

using namespace std;

/*
las plantillas las podemos definir como funciones 
o clases capaces de trabajar con cualquier clase desconocidad

g++ plantillas.cpp includes/Complejo.cpp includes/figuras/Circulo.cpp -o plantillas && ./plantillas.exe
*/

template <class TipoX> // muy comun mente se lige una T
void mostrarSuma(TipoX x, TipoX y) {
  cout << x << " + " << y << " = " << (x + y) << endl;
}

// las plantillas se pueden sobreescribir
void mostrarSuma(const int x, const int y) {
  cout << "haciendo algo con enteros\n";
}

template <typename T, class S = void> // puedo usar indistintamente class o typename
class Contenedor {
public:
  T contenido;
  
  T mostrar();
  
  void status();
};

int main(){
  Complejo a("a", 3,4), b("b", 5,-7);
  
  mostrarSuma(2, 2);
  mostrarSuma(2.0, 3.0);
  mostrarSuma<string>("mensaje 1", "mensaje 2"); // así entiende que no con char[] sino strings
  mostrarSuma<Complejo>(a, b);
  
  Contenedor<int> cont;
  cont.contenido = 9;
  cont.mostrar();
  
  Contenedor<Complejo> cont2;
  cont2.contenido = a;
  cont2.contenido.nombre = "a";
  cont2.status();
  
  Contenedor<Circulo> cont3;
  cont3.contenido = Circulo(5);
  cont3.contenido.calcularArea();
  cont3.contenido.calcularDiametro();
  cont3.status();
  
  return 0;
}

// se tienen que reescribir si el metodo va afuera
template <typename R, typename S>
R Contenedor<R, S>::mostrar() {
  R miVariable = contenido;
  
  cout << contenido << endl;
  // return contenido;
}

template <class T, class S>
void Contenedor<T, S>::status() {
  cout << "contenido de este contenedor\n";
  cout << "--------------------------------\n";
  cout << "|                              |\n";
  
  contenido.status();
  
  cout << "|                              |\n";
  cout << "--------------------------------\n";
}