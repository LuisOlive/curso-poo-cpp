#include<iostream>

using namespace std;

class Complejo {
  public:
  float real, imaginaria;
  string nombre;
  
  // # este es un constructor
  // crea un numero complejo
  Complejo(string _nombre, float _real, float _imaginaria) {
    real = _real;
    imaginaria = _imaginaria;
    nombre = _nombre;
  }
  
  // # este es un destructor
  ~Complejo() {// ~ es con alt 126
    real = 8624184286426;
    imaginaria = -86426728268;
  }
  
  // # estos son metodos
  
  void status() {
    cout << nombre << " = " << real << " + " << imaginaria << "i\n";
  }
  
  // podemos hacer interactuar nuestros objetos unos con otros
  void sumar(Complejo otro) { // otro por que en ingles acostumbramos llamarlo other
    real += otro.real;
    imaginaria += otro.imaginaria;
  }
  
  // podemos retornar objetos 
  Complejo mas(Complejo otro) {
    Complejo respuesta("", real + otro.real, imaginaria + otro.imaginaria);
    return respuesta;
  }
  
  Complejo menos(Complejo otro) {
    Complejo respuesta("", real - otro.real, imaginaria - otro.imaginaria);
    return respuesta;
  }
  
  Complejo por(Complejo otro) {
    // z = a + bi, w = c + di -> zw = ac - bd + (ad + bc)i
    float a = real, b = imaginaria,
          c = otro.real, d = otro.imaginaria;
    
    Complejo respuesta("", a*c - b*d, a*d + b*c);
    return respuesta;
  }
};

int main(){
  // estas son dos instancias
  Complejo z("z", 3, 4), w("w", 5,-7); // z = 3 + 4i, w = 5 - 7i
  
  z.status(); // estos son llamados a metodos
  w.status(); // estos son llamados a metodos
  
  Complejo q = z.mas(w);
  q.nombre = "q";
  q.status();
  
  Complejo p = z.menos(w);
  p.nombre = "p";
  p.status();
  
  z = p.por(q);
  z.nombre = "z";
  z.status();
  
  // w = p.entre(z); // reto 
  
  return 0;
}
