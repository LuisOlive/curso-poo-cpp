#include <iostream>

using namespace std;

class Cuadrado 
{
public:
  int lado, area, perimetro;
};

int main()
{
    
    
    //Variables rectangulo.
    int baser, alturar, arear, perimetror;

    //Variables triangulo.
    float ladot, alturat, baset, areat, perimetrot;

    cout<<"Emilio"<<endl;
    cout<<"Programa para calcular el area y perimetro de figuras geometricas"<<endl;

    //Desarrollo de cuadrado.
    //Pedir el valor de lado
    Cuadrado cua;
    
    cout<<"Ingrese el lado del cuadro: "<<endl;
    cin>> cua.lado;
    
    cua.area = cua.lado * cua.lado;
    cua.perimetro = cua.lado * 4;
    
    cout<<"El area del cuadro es: "<<cua.area<<endl;
    cout<<"El perimetro del cuadro es: "<<cua.perimetro<<endl;
    cout<<"\n";

    //Desarrollo del rectangulo.

    cout<<"Ingrese la base del rectangulo: "<<endl;
    cin>>baser;
    cout<<"Ingrese la altura del rectangulo: "<<endl;
    cin>>alturar;
    arear = baser*alturar;
    perimetror = (2*baser)+(2*alturar);
    cout<<"El area del rectangulo es: "<<arear<<endl;
    cout<<"El perimetro del rectangulo es: "<<perimetror<<endl;
    cout<<"\n";

    //Desarrollo del rectangulo.

    cout<<"Ingrese el lado del triangulo: "<<endl;
    cin>>ladot;
    cout<<"Ingrese la base del triangulo: "<<endl;
    cin>>baset;
    cout<<"Ingrese la altura del triangulo: "<<endl;
    cin>>alturat;
    areat = (baset*alturat)/2;
    perimetrot = ladot*3;
    cout<<"El area del triangulo es: "<<areat<<endl;
    cout<<"El perimetro del triangulo es: "<<perimetrot<<endl;
    cout<<"\n";

    return 0;
}