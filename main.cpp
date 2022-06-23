/*
  * Introducción a los objetos
  
  El universo está hecho de objetos que conviven entre sí: por ejemplo:
  un auto consume gasolina
  un boxeador golpea a otro boxeador
  un autobus transporta personas
  el dinero compra cosas
  
  * conceptos
  ? objeto
  un objeto es todo aquello que existe y que convive con su entorno
  
  ? clase
  una clase es "la clasificacion" de cada objeto; el que és
  
  ? instancia
  es una variable de una clase (un objeto)
  
  ? instanciar
  declara una instancia
  
  ? propiedades
  "variables" que pertenecen al objeto
  
  ? métodos
  "funciones" que pertenecen al objeto
*/
#include <iostream>
#include <cstdlib>

using namespace std;

/* lo primero es siempre definir una clase

  lo primero para determinar quien es la clase es saber que cosas conviven

 las clases se escriben con:*/
class MiCLase { // recomendacion es que empieze el nombre en mayuscula
public: // despues vemos esto
  
}; // es lo unico con llaves que requiere ;

struct Circulo {
public: // despues vemos esto
  // en una clase existen 2 (4) cacteristicas: propiedades y métodos
  
  // propiedades (variables)
  float radio;
  float area;
  float diametro;
  
  // métodos (funciones)
  void calcularArea() {
    area = 3.14159 * radio * radio;
  }
  
  // métodos (funciones)
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
  cout << "Este programa calcula el área de un circulo\n";
  
  // instancia solo es una variable de una clase
  Circulo circulo; // esto es instanciar
  Circulo circulo2; // 2 instancias
  Circulo c; // 3 instancias
  
  // el circulo tiene propiedades que se pueden modificar
  circulo.radio = 15;
  circulo2.radio = 17;
  c.radio = 34.5;
  
  cout << "el radio del circulo 1 es " << circulo.radio << "mm\n";
  cout << "el radio del circulo 2 es " << circulo2.radio << "mm\n";
  
  circulo.calcularArea();
  circulo2.calcularArea();
  
  cout << "el area del circulo 1 es " << circulo.area << "mm2\n";
  cout << "el area del circulo 2 es " << circulo2.area << "mm2\n";
  
  circulo.calcularDiametro();
  circulo2.calcularDiametro();
  
  cout << "el diametro del circulo 1 es " << circulo.diametro << "mm2\n";
  cout << "el diametro del circulo 2 es " << circulo2.diametro << "mm2\n";
  
  /* algunas recomendaciones más
  
  la primera letra en mayuscula apra los nombres de clases
  lpara las instancias
  
  si es la unica, con el mismo nombre de la clase, pero en minusculas
  o incluso la pura inicial
  
  tener un metodo llamado estado (o estatus) para mostrar todas las propiedades en consola
  */
  c.calcularArea();
  c.calcularDiametro();
  c.estatus();
  
  return 0;
}