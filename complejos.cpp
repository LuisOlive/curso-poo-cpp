/*
  Sobrecarga de funciones clásicas
  
  Lo mismo que con los métodos, 
  cambias los parametros y les dejas el nombre, el compilador lo va a entender
  
  sobrecarga de operadores
*/

#include<iostream>
#include<cmath>

using namespace std;

const double PI = 3.141592653589793; // PI
const double PI_2 = PI / 2; // PI medios
const double RAD_2_DEG = 180 / PI;
const double DEG_2_RAD = PI / 180;

class Complejo {
  public:
  
  // # estas son las propiedades o atributos
  
  float real, imaginaria;
  string nombre;
  
  // # estos son constructores
  // Crea una instancia anonima de un complejo, sin paramteros se crea un 0 + 0i
  Complejo(float re = 0, float im = 0) {
    real = re;
    imaginaria = im;
  }
  
  // Crea una instancia nombrada de complejo, sin paramteros se crea un 0 + 0i
  Complejo(string _nombre, float re = 0, float im = 0) {
    nombre = _nombre;
    real = re;
    imaginaria = im;
  }
  
  // # este es el destructor
  ~Complejo() {// ~ es con alt 126
    // valores dañinos para el programa, para eso es el destructor
    real = 8624184286426;
    imaginaria = -86426728268;
  }
  
  // # estos son metodos
  // muestra toda la info del numero complejo
  void status() {
    cout << nombre << " = " << real << " + " << imaginaria << "i\n";
  }
  
  void statusPolar() {
    cout 
      << nombre << " = " // nombre = 
      << modulo() // modulo del complejo
      << " | "
      << argumento() * RAD_2_DEG // argumento, transformado a grados
      << (char) -89 // símbolo º
    << endl;
  }
    
  // podemos retornar objetos 
  // devuelve la suma de un complejo con otro
  Complejo mas(Complejo otro) {
    return Complejo(real + otro.real, imaginaria + otro.imaginaria);
  }
  
  // # esto es una sobrecarga de mas()
  // devuelve la suma de un complejo con otro usando flotantes
  Complejo mas(float re, float im = 0) {
    return mas(Complejo(re, im));
  }
  
  // para escribir operadores se usa el keyword operator
  Complejo operator + (Complejo otro) {
    // recoemndacion es tener el algoritmo con un metodo en palabras
    return mas(otro);
  }
  
  Complejo menos(Complejo otro) {
    return Complejo(real - otro.real, imaginaria - otro.imaginaria);
  }
  
  Complejo menos(float re, float im = 0) {
    return menos(Complejo(re, im));
  }
  
  // para escribir operadores se usa el keyword operator
  Complejo operator - (Complejo otro) { // otro solo es una convencion
    // recoemndacion es tener el algoritmo con un metodo en palabras
    return menos(otro);
  }
  
  Complejo por(Complejo otro) {
    // z = a + bi, w = c + di -> zw = ac - bd + (ad + bc)i
    float a = real, b = imaginaria,
          c = otro.real, d = otro.imaginaria;
    
    return Complejo(a*c - b*d, a*d + b*c);
  }
  
  Complejo por(float re, float im = 0) {
    return por(Complejo(re, im));
  }
  
  Complejo operator * (Complejo otro) {
    // recoemndacion es tener el algoritmo con un metodo en palabras
    return por(otro);
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
    
    return Complejo((a*c + b*d) / denom, (b*c - a*d) / denom);
  }

  Complejo entre(float re, float im = 0) {
    return entre(Complejo(re, im));
  }
  
  Complejo operator / (Complejo otro) {
    // recoemndacion es tener el algoritmo con un metodo en palabras
    return entre(otro);
  }

  float modulo() {
    // pitagorazo de real e imaginaria
    return sqrt(real * real + imaginaria * imaginaria);
  }
  
  float argumento() {
    // previniendo division entre 0
    if(real == 0)   
      return PI_2 * (imaginaria < 0) ? -1 : (imaginaria > 0);// pi/2 * signo(im)
    
    return atan(imaginaria / real);
    // return atan(imaginaria / (real + 1e-8)); // otra forma, más fácil, pero menos precisa
  }

  Complejo conjugado() {
    return Complejo(real, - imaginaria);
  }

  // con excepcion del punto todos los ops. pueden sobrecargarse
  bool esMayorQue(Complejo otro) {
    return modulo() > otro.modulo();
  }
  
  // # esto es la una sobrecarga de operador booleano
  // bool es un tipo de dato, que solo puede ser 0 o 1, puede sustituir por int
  bool operator > (Complejo otro) {
    return esMayorQue(otro);
  }
  
  bool esMenorQue(Complejo otro) {
    return modulo() > otro.modulo();
  }
  
  bool operator < (Complejo otro) {
    return esMenorQue(otro);
  }
  
  bool esMayorOIgualQue(Complejo otro) {
    return modulo() >= otro.modulo();
  }
  
  bool operator >= (Complejo otro) {
    return esMayorOIgualQue(otro);
  }
  
  // si no se desea, puede no crearse un metodo normal e implementarse directo el operador
  bool operator == (Complejo otro) {
    return real == otro.real && imaginaria == otro.imaginaria;
  }
  
  // # mas operadores
  // sobrecarga del paréntsis
  void operator () (string nom, int x = 0) { 
    // con la gran ventaja de que el paréntesis está hecho para mucho paramteros
    nombre = nom;
  }
  
  float operator [] (int i) {
    cout << "no se que hacer con corchetes";
    return 2.5;
  }
  
  // este operador previene un sobreescritura completa
  void operator = (Complejo otro) {
    real = otro.real;
    imaginaria = otro.imaginaria;
    // más adelante vemos como hacer que el igual devuelva el nuevo resultado 
  }
  
  // este operador previene un sobreescritura completa
  void operator += (Complejo otro) {
    real += otro.real;
    imaginaria += otro.imaginaria;
    // más adelante vemos como hacer que el igual devuelva el nuevo resultado 
  }
  
  // ++ requiere un prametro aunque no se utilize
  void operator ++ (int _) {
    real++;
    imaginaria++;
  }
  
  void operator << (string mensaje) {
    cout << nombre << " dice: " << mensaje << endl;
  }
  
  Complejo operator << (int lugares) {
    return Complejo(real << lugares, imaginaria << lugares);
  }
  
  void operator >> (string cual) {
    if(cual == "real") 
      cin >> real;
    if(cual == "imaginaria") 
      cin >> imaginaria;
  }
};

// # esta es una sobrecarga de funcion
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
  return pow(z, 0.5);
}

ostream& operator << (ostream& _cout, Complejo z) {
  _cout << z.real << " + " << z.imaginaria << "i"; // expresion lineal
  return _cout;
}

int main(){
  // estas son cuatro instancias
  Complejo z("z", 3, 4), w("w", 3, 4); // z = 3 + 4i, w = 0 + 0i
  
  Complejo q = z + w; // utilizando operadores sobrecargados
  Complejo a = z - w + q; // utilizando operadores sobrecargados
  Complejo b = z * w; // utilizando operadores sobrecargados
  Complejo c = z / w; // utilizando operadores sobrecargados
  Complejo d = pow(z, 2);
  Complejo e = sqrt(z);
  
  a("a");
  b("b");
  q("q");
  c("c");
  d("d");
  e("e");
  
  a.status();
  a++;
  a << "Ingrese la parte real de a";
  a >> "real";
  
  a << "Ingrese la parte imaginaria de a";
  a >> "imaginaria";
  
  cout << "el numero complejo a es " << a << endl;
  
  if(z == w) {
    cout << "z es igual que w\n";
  } else {
    cout << "z no es igual que w\n";
  }
  // estos son llamados a metodos
  z.status();
  z.statusPolar();
  w.status();
  w.statusPolar();
  q.status();
  // q.statusPolar();
  a.status();
  // a.statusPolar();
  b.status();
  // b.statusPolar();
  c.status();
  // c.statusPolar();
  // d.status();
  // d.statusPolar();
  // e.status();
  // e.statusPolar();
  
  return 0;
}
