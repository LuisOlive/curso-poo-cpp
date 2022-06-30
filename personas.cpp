/*
  * Encapsulamiento
  En programación modular, y más específicamente en programación orientada a objetos, 
  se denomina encapsulamiento al ocultamiento del estado, es decir, de los datos miembro 
  de un objeto de manera que solo se pueda cambiar mediante las operaciones definidas 
  para ese objeto.
  
  % En otras palabras
  Encapsular es retirar el permiso al programa de maniobrar las propiedades libremente,
  dandole esa libertad solo a los métodos de la clase
  
  para "encapsular" se emplean modificadores de acceso
  
  * modificadores de acceso
  los modificadores de acceso restringen las propiedades 
  existen 3 tipos:
  
  # public
  permite el acceso y edicion de variables libremente 
  se recomienda solo usar con los metodos
  
  # private
  solo permite el acceso para los metodos de la clase y para elementos amigos
  
  # protected
  Lo mismo que protected, pero las propiedades "protejidas" pueden heredarse
*/
#include<iostream>

using namespace std;

class Celular {
public:
  string marca;
  
  void llamar(long numero) {
    cout << "llamando a " << numero << endl;
  }
};

class Carro {
public:
  string marca;
  
  void arrancar() {
    cout << "arrancando\n";
  }
  
  void correr(float velocidad) {
    cout << "corriendo a " << velocidad << endl;
  }
};

// heredar es "ser" y composición es "tener"
class Persona {
public:
  string nombre, email;
  long numeroTelefonico;
  int edad;
  
  // # esto es composición
  Celular celular;
  Persona *familiares;
  Carro carro;
  
  void llamar(long numero) {
    // sacar nuestro celular del bolsillo
    // marcar
    celular.llamar(numero);
  }
  
  void conducir() {
    // sube al carro
    carro.arrancar();
    carro.correr(40);
  }
  
  /*
    otra forma de crear constructores
    para usar la misma palabra, se le indica al codigo que se trata de la propiedad usando ::
  */
  Persona(string nombre, string email, int edad, long numeroTelefonico) {
    Persona::nombre = nombre;
    Persona::email = email;
    Persona::edad = edad;
    Persona::numeroTelefonico = numeroTelefonico;
  }
  
  ~Persona() {
    hablar("muerindo...");
    
    nombre = "";
    numeroTelefonico = 0;
    edad = -1;
    email = "";
  }
  
  void hablar(string mensaje) {
    cout << nombre << ": " << mensaje << endl;
  }
  
  
};

// # hay herencias, cada una es simple

// # estas son clases hijas

struct Policia: public Persona {
public:
  string cedula;
  
  Policia(string cedula, string nombre, string email, int edad, long numeroTelefonico): 
  Persona( nombre,  email,  edad,  numeroTelefonico) {
    Policia::cedula = cedula;
  }
  
  void arrestar(Persona p) {
    hablar("arrestando a " + p.nombre);
  }
  
  void encarcelar(Persona p) {
    hablar("encarcelando a " + p.nombre);
  }
  
  // sobreescritura
  void conducir() {
    Persona::conducir();
    hablar("conduzco muy rapido para agarrar al delincuente");
  }
};

class Doctor: public Persona {
public:
  string cedula;
  
  Doctor(string cedula, string nombre, string email, int edad, long numeroTelefonico): 
  Persona( nombre,  email,  edad,  numeroTelefonico) {
    Doctor::cedula = cedula;
  }
  
  void curar(Persona p) {
    hablar("curando a " + p.nombre);
  }
  
  void operar(Persona p) {
    hablar("operando a " + p.nombre);
  }
};

class Ingeniero: public Persona {
public:
  string cedula, carrera;
  
  Ingeniero(string cedula, string carrera, string nombre, string email, int edad, long numeroTelefonico): 
  Persona( nombre,  email,  edad,  numeroTelefonico) {
    Ingeniero::cedula = cedula;
    Ingeniero::carrera = carrera;
  }
  
  void hacerCalculos() {}
  
  void disenar() {}
};

int main(){
  // 4 instancias: 1 de la clasePersona, 1 de la clase Policia, ...
  Persona luis("Luis Olivares", "luisolivares@mail.com", 21, 55581144);
  Policia jefeGorgory("51B654","Jefe Gorgory", "gorgory@police.gob", 54, 46641187);
  Doctor drGilbert("51A654","Dr Gilbert", "loquesea@mail.com", 58, 231564849);
  Ingeniero juan("51A654", "electrico", "Juan Perez", "juanperez@deseguro.com", 34, 78945612);
  
  // % todos comparten propiedades
  cout << luis.nombre << endl;
  cout << jefeGorgory.nombre << endl;
  cout << drGilbert.nombre << endl;
  cout << juan.nombre << endl;
  
  // % todos comparten ciertas capacidades
  luis.conducir();
  jefeGorgory.conducir(); // polimorfismo
  drGilbert.conducir();
  juan.conducir();
  
  // % como clases hijas, tienen comportamientos particulares
  jefeGorgory.arrestar(luis);
  drGilbert.curar(juan);
  
  return 0;
}

class Hacker {
public:
  void doxear(Persona victima) {
    cout << "El numero de numeroTelefonico de " << victima.nombre << " es " << victima.numeroTelefonico;
    cout << "El correo electronico de " << victima.nombre << " es " << victima.email;
    // cout << "El numero de tarjeta de " << victima.nombre << " es " << victima.numeroTarjeta;
  }
};
