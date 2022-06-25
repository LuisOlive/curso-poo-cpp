/*
  Los objetos tienen distintos comportamientos para una clase que para otra
  % ejemplo:
  Chef.cocinarPastel(Pastel) requiere preparar mezcla, hornear y decorar
  Chef.cocinarCarne(Carne) hay que freir la carne, ponerle salsa y finas hierbas

  * sobrecarga (overloading)
  Sobrecarga es la capacidad de un lenguaje de programación, que permite nombrar con 
  el mismo identificador diferentes variables u operaciones. En programación orientada 
  a objetos la sobrecarga se refiere a la posibilidad de tener dos o más funciones con 
  el mismo nombre pero funcionalidad diferente.
  
  % más fácil
  La sobrecarga es la capacidad del lenguaje de llamar de la misma forma a los comportmaientos
  
  Chef.cocinar(Pastel) 
  Chef.cocinar(Carne)
  
  es más facil de escrbir y C++ lo entiende perfectamente
  
  $ Se puede hacer sobrecarga cambiando el orden de los parametros, cantidad y tipo
  
  > El constructor tambien puede sobrecargarse, de hecho todo puede, menos el destructor
  
  los metodos sobrecargados pueden reescribirse por completo 
  o pueden llamar a sus equivalentes de otros tipos
  ! en tanto no sea el constructor
*/

#include<iostream>

using namespace std;

class Complejo {
  public:
  float real, imaginaria;
  string nombre;
  
  // # este es un constructor
  // crea un numero complejo
  Complejo(float _real, float _imaginaria) {
    real = _real;
    imaginaria = _imaginaria;
  }
  
  /*
    > El constructor tambien puede sobrecargarse, de hecho todo puede, menos el destructor
    
    % La forma más rápida de sobrecargar es colocando valores iniciales a los parametros
    colocando = cuando se definan estos
  */
  Complejo(string _nombre,float _real = 0, float _imaginaria = 0) {
    nombre = _nombre;
    real = _real;
    imaginaria = _imaginaria;
  }
  
  // # este es un destructor
  ~Complejo() {// ~ es con alt 126
    real = 8624184286426;
    imaginaria = -86426728268;
  }
  
  // # estos son metodos
  // muestra toda la info del numero complejo
  void status() {
    cout << nombre << " = " << real << " + " << imaginaria << "i\n";
  }
    
  // podemos retornar objetos 
  Complejo mas(Complejo otro) {
    Complejo ans(
      nombre + "+" + otro.nombre,
      real + otro.real, 
      imaginaria + otro.imaginaria);
    return ans;
  }
  
  // # esto es una sobrecarga
  // el metodo mas() tiene 3 sobrecargas
  
  // se hace una sobrecarga escribiendo un metodo con distintos parametros
  Complejo mas(float _real, float _imaginaria = 0) {
    Complejo nuevo(_real, _imaginaria);
    Complejo ans = mas(nuevo);
    
    return ans;
  }
  
  // se hace una sobrecarga escribiendo un metodo con distintos parametros
  // Complejo mas(float otro) {
  //   Complejo ans(real + otro, imaginaria);
  //   return ans;
  // }
  
  Complejo menos(Complejo otro) {
    Complejo ans(
      nombre + "-" + otro.nombre,
      real - otro.real, 
      imaginaria - otro.imaginaria
    );
    return ans;
  }
  
  // esto es una sobrecarga
  // el metodo menos() tiene 4 sobrecargas
  Complejo menos(float re = 0, float im = 0) {
    Complejo nuevo(re, im);
    return menos(nuevo);
  }
  
  Complejo menos(string s) {}
  
  Complejo por(Complejo otro) {
    // z = a + bi, w = c + di -> zw = ac - bd + (ad + bc)i
    float a = real, b = imaginaria,
          c = otro.real, d = otro.imaginaria;
    
    Complejo ans(
      nombre + "*" + otro.nombre,
      a*c - b*d, 
      a*d + b*c
    );
    return ans;
  }
  
  Complejo por(float re, float im = 0) {
    Complejo nuevo(re, im);
    return por(nuevo);
  }
  
  Complejo entre(Complejo otro) {
    // z = a + bi, w = c + di
    float a = real, b = imaginaria,
          c = otro.real, d = otro.imaginaria;
    
    /* 
      .      ac + bd + (bc - ad)i     ac + bd        bc - ad
     .z/w = ---------------------- = --------- + i ----------- 
      .           c² + d²             c² + d²        c² + d²
    */
    float denom = c * c + d * d; // (c² + d²)
    
    Complejo ans(
      nombre + "+" + otro.nombre,
      (a*c + b*d) / denom,
      (b*c - a*d) / denom
    );
    return ans;
  }

  Complejo entre(float re, float im = 0) {
    Complejo nuevo(re, im);
    return entre(nuevo);
  }
};

int main(){
  // estas son cuatro instancias
  Complejo z("z", 3, 4), w("w"); // z = 3 + 4i, w = 0 + 0i
  
  Complejo q = z.menos(w); // z interactua con un objeto de clase "Complejo"
  Complejo a = z.menos(5); // z interactua con un objeto de clase "float"
  Complejo b = z.mas(7, 6); // z interactua con dos objetos de clase "float"
  Complejo c = b.entre(10);
  
  a.nombre = "a";
  b.nombre = "b";
  c.nombre = "c";
  
  // estos son llamados a metodos
  z.status();
  w.status();
  q.status();
  b.status();
  c.status();
  
  return 0;
}
