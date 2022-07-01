/*
  * Composición
  la composicion se da cuando un objeto tiene una propiedad o varias que sean de otras clases
  
  * Abstracción
  Tener metodos y propiedades que la hagan pertenecer a un clase, se haya escrito o no
  
  - cumplir con una interfaz
  
  * Interfaz
  interfaz son los metodos y propiedades que debe cumplir un objeto para cosiderarse que 
  son de cierto tipo
  
  
  - Persona.escribir(Pluma)
  - class Lapiz {}
  - Persona.escribir(Lapiz) puede usar un lapiz, por que funciona como pluma
  
  si un objeto no tiene esto, no lo consiero un carro
  
  mesa: no tiene ruedas -> no es un carro
  silla de ruedas -> no tiene motor -> no es un carro
  silla de ruedas electrica -> sí tiene todo -> es un carro
  moto -> sí tiene todo -> es un carro
  
  % en c++ no hay sintaxis para las interfaces
*/

#include "includes/figuras/Trapecio.h"

int main(){
  Trapecio trapecio(4, 10, 4);
  
  trapecio.status();
  
  return 0;
}