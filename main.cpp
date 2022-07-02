#include <iostream>

#include "includes/personas/Persona.h"
#include "includes/personas/Doctor.h"

using namespace std;

void punteroPrimitivo();
void punteroArray();
void punteroMatriz();
void punteroObjeto();

int main(){
  punteroPrimitivo();
  // punteroArray();
  // punteroMatriz();
  // punteroObjeto();
  return 0;
}

// caso 1
void punteroPrimitivo() {
  // .1 un puntero del tipo que buscamos
  float* ptr_float; // dejamos diseñada la ubicaion en la que montaremos nuestro dato
  
  // .2 el operador new
  ptr_float = new float; // reservar la memoria p/ montar el dato
  
  // utilizamos al gusto
  cout << "ingrese el valor de x: ";
  cin >> *ptr_float;
  
  cout << "x vale " << *ptr_float << endl;
  
  // .3 y muy importante: el op. delete
  delete ptr_float; // liberar memoria
}

// caso 2
void punteroArray() {
  float* ptr_arregloFlotantes; //.1
  
  // como es memoria dinamica, el programa la reserva durante ejecucion
  short len;
  cout << "ingrese numero de elementos: ";
  cin >> len;
  
  ptr_arregloFlotantes = new float[len]; //.2
  
  for(short i = 0; i < len; i++) {
    cout << "ingrese el valor del elem. " << i + 1 << ": ";
    // cin >> ptr_arregloFlotantes[i];
    cin >> *(ptr_arregloFlotantes + i);
  }
  
  for(short i = 0; i < len; i++) {
    cout << *(ptr_arregloFlotantes + i);
    cout << ptr_arregloFlotantes[i];
  }
  //.3
  delete[] ptr_arregloFlotantes; // en arrays, delete lleva corchetes
}

// caso 3
void punteroMatriz() {
  float** ptr_matriz; //.1
  
  short lenX, lenY;
  cout << "ingrese numero de filas: ";
  cin >> lenY;
  cout << "ingrese numero de columnas: ";
  cin >> lenX;
  
  ptr_matriz = new float* [lenY]; //.2
  
  for(short i = 0; i < lenY; i++)
    // *(ptr_matriz + i)
    ptr_matriz[i] = new float[lenX]; //.2
    
  for(short i = 0; i < lenY; i++)
    for(short j = 0; j < lenX; j++){
      cout << "ingrese el valor del elem. (" << i + 1 << ", " << j + 1 << "): ";
      // es lo mismo que cin >> ptr_matriz[i][j]; y se puede elegir al gusto
      cin >> *(*(ptr_matriz + i) + j);
    }
    
  for(short i = 0; i < lenY; i++){
    for(short j = 0; j < lenX; j++) 
      cout << ptr_matriz[i][j] << " ";
      
    cout << endl;
  }
    
  for(short i = 0; i < lenY; i++) //.3
    delete[] ptr_matriz[i];
    
  delete[] ptr_matriz;
}

// caso 4
void punteroObjeto() {
  Persona* p;
  
  p = new Persona("Luis", "email@email.com", 20, 19); // en punteros,el new lleva el constructor

  (*p).hablar("Hola, como puntero usando el punto");
  
  p->hablar("Hola, como puntero usando la flecha");
  p->estaHerida = true;

  delete p;
}