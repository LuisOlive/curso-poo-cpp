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
  
  / convenciones
  propiedades privadas algunos las nombran con _ al principio
*/
#include<iostream>

using namespace std;

class Persona {
protected:
  string _nombre, _email;
  long _telefono;
  int _edad;

public:
  /*
    otra forma de crear constructores
    para usar la misma palabra, se le indica al codigo que se trata de la propiedad usando ::
  */
  Persona(string nombre, string email, int edad, long telefono) {
    _nombre = nombre;
    _email = email;
    _edad = edad;
    _telefono = telefono;
  }
  
  ~Persona() {
    _nombre = "";
    _telefono = 0;
    _edad = -1;
    _email = "";
  }
  
  // getter y setters
  
  // getter nos permite conocer el valor de una propiedad
  // por convencion, comienzan con la palabra get
  string getNombre(string token = "") {
    if(token == "123456")
      return _nombre;
      
    return "";
  }
  
  void setEdad(int edad) {
    if(edad > 18)
      _edad = edad;
      
    cout << _edad << endl;
  }
};

struct Policia: public Persona {
private:
  string cedula;
  
public: 
  Policia(string cedula, string nombre, string email, int edad, long telefono): 
  Persona( nombre,  email,  edad,  telefono) {
    Policia::cedula = cedula;
  }
  
  string getCedula() {
    return cedula;
  }
  
  void pedirRefuerzos() {
    cout << _nombre << ": habla oficial " << _nombre << ", solicito refuerzos\n";
  }
};

// class Hacker {
// public:
//   void doxear(Persona victima) {
//     cout << "El numero de telefono de " << victima.nombre << " es " << victima.telefono << endl;
//     cout << "El correo electronico de " << victima.nombre << " es " << victima.email << endl;
//     // cout << "El numero de tarjeta de " << victima.nombre << " es " << victima.numeroTarjeta;
//   }
// };

int main(){
  Persona luis("Luis Olivares", "luisolivares@mail.com", 21, 55581144);
  // Hacker anonymous;
  
  // // ! peligroso
  // luis.edad = -1;
  luis.setEdad(-1);
  
  // // ! muy peligroso
  // anonymous.doxear(luis);
  // luis.setNombre("Alejandro")
  
  cout << "nombre seguro: " << luis.getNombre() << endl;
 
  return 0;
}


