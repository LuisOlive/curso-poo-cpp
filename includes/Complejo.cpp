#include "Complejo.h"

Complejo::Complejo(float re, float im) {
  real = re;
  imaginaria = im;
}

Complejo::Complejo(string nombre, float re, float im) {
  Complejo::nombre = nombre;
  real = re;
  imaginaria = im;
}

Complejo::~Complejo() {// ~ es con alt 126
  // valores dañinos para el programa, para eso es el destructor
  real = 8624184286426;
  imaginaria = -86426728268;
}

float Complejo::modulo() {
  // pitagorazo de real e imaginaria
  return sqrt(real * real + imaginaria * imaginaria);
}

float Complejo::argumento() {
  // previniendo division entre 0
  if(real == 0)   
    return PI_2 * (imaginaria < 0) ? -1 : (imaginaria > 0);// pi/2 * signo(im)
  
  return atan(imaginaria / real);
  // return atan(imaginaria / (real + 1e-8)); // otra forma, más fácil, pero menos precisa
}

Complejo Complejo::conjugado() {
  return Complejo(real, - imaginaria);
}

void Complejo::status() {
  cout << nombre << " = " << real << " + " << imaginaria << "i\n";
}

void Complejo::statusPolar() {
  cout 
    << nombre << " = " // nombre = 
    << modulo() // modulo del complejo
    << " | "
    << argumento() * RAD_2_DEG // argumento, transformado a grados
    << (char) -89 // símbolo º
  << endl;
}
  
Complejo Complejo::mas(Complejo otro) {
  return Complejo(real + otro.real, imaginaria + otro.imaginaria);
}

Complejo Complejo::mas(float re, float im) {
  return mas(Complejo(re, im));
}

Complejo Complejo::operator + (Complejo otro) {
  // recomendacion es tener el algoritmo con un metodo normal
  return mas(otro);
}

// estos operadores pueden sobrecargarse también
Complejo Complejo::operator + (float re) { // que solo se puede un parametro, solo puede cambiar el tipo
  // recomendacion es tener el algoritmo con un metodo normal
  return mas(re);
}

Complejo Complejo::menos(Complejo otro) {
  return Complejo(real - otro.real, imaginaria - otro.imaginaria);
}

Complejo Complejo::menos(float re, float im) {
  return menos(Complejo(re, im));
}

// para escribir operadores se usa el keyword operator
Complejo Complejo::operator - (Complejo otro) { // otro solo es una convencion
  // recoemndacion es tener el algoritmo con un metodo en palabras
  return menos(otro);
}

Complejo Complejo::por(Complejo otro) {
  // z = a + bi, w = c + di -> zw = ac - bd + (ad + bc)i
  float a = real, b = imaginaria,
        c = otro.real, d = otro.imaginaria;
  
  return Complejo(a*c - b*d, a*d + b*c);
}

Complejo Complejo::por(float re, float im) {
  return por(Complejo(re, im));
}

Complejo Complejo::operator * (Complejo otro) {
  // recoemndacion es tener el algoritmo con un metodo en palabras
  return por(otro);
}

Complejo Complejo::entre(Complejo otro) {
  // z = a + bi, w = c + di
  float a = real, b = imaginaria,
        c = otro.real, d = otro.imaginaria;
  
  /* 
    .      ac + bd + (bc - ad)i     ac + bd        bc - ad
    .z/w = ---------------------- = --------- + i ----------- 
    .           c² + d²             c² + d²        c² + d²
  */
  float denom = c * c + d * d; // (c² + d²)
  
  return Complejo((a*c + b*d) / denom, (b*c - a*d) / denom);
}

Complejo Complejo::entre(float re, float im) {
  return entre(Complejo(re, im));
}

Complejo Complejo::operator / (Complejo otro) {
  // recoemndacion es tener el algoritmo con un metodo en palabras
  return entre(otro);
}

bool Complejo::esMayorQue(Complejo otro) {
  return modulo() > otro.modulo();
}

// # estas son sobrecargas de operador booleano
// bool es un tipo de dato, que solo puede ser 0 o 1, puede sustituir por int
bool Complejo::operator > (Complejo otro) {
  return esMayorQue(otro);
}

bool Complejo::esMenorQue(Complejo otro) {
  return modulo() < otro.modulo();
}

bool Complejo::operator < (Complejo otro) {
  return esMenorQue(otro);
}

bool Complejo::esMayorOIgualQue(Complejo otro) {
  return modulo() >= otro.modulo();
}

bool Complejo::operator >= (Complejo otro) {
  return esMayorOIgualQue(otro);
}

// si no se desea, puede no crearse un metodo normal e implementarse directo el operador
bool Complejo::operator == (Complejo otro) {
  return real == otro.real && imaginaria == otro.imaginaria;
}

// este operador previene un sobreescritura completa
void Complejo::operator = (Complejo otro) {
  real = otro.real;
  imaginaria = otro.imaginaria;
  // más adelante vemos como hacer que el igual devuelva el nuevo resultado 
}

// este operador previene un sobreescritura completa
void Complejo::operator += (Complejo otro) {
  real += otro.real;
  imaginaria += otro.imaginaria;
  // más adelante vemos como hacer que el igual devuelva el nuevo resultado 
}

// ++ requiere un prametro aunque no se utilize
void Complejo::operator ++ (int _) {
  real++;
  imaginaria++;
}

/*
  . estas ya no pertenecen a la clase
*/

Complejo pow(Complejo z, float n) {
  // las potencias de complejos trabajan mejor con polares
  
  /*
  si en forma polar 
  . z = r ∠ φ
  la potencia de un complejo es 
  . z^n = r^n ∠ nφ
  */
  
  float r = z.modulo(); 
  float phi = z.argumento();
 
  float nueva_r = pow(r, n);
  float nueva_phi = n * phi;

  float re = nueva_r * cos(nueva_phi);
  float im = nueva_r * sin(nueva_phi);
  
  return Complejo(re, im);
}

Complejo sqrt(Complejo z) {
  return pow(z, .5);
}

Complejo operator + (float x, Complejo z) {
  return z + x;
}

ostream& operator << (ostream& _cout,  Complejo z) {
  _cout << z.real << " + " << z.imaginaria << "i";
  return _cout;
}