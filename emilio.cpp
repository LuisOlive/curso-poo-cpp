#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Arreglo
{
private:
    int n; // yo la cambiaria por una variable con un nombre más claro como "longitud"
    float *a; // localización, loc
public: //Atributos
    Arreglo(); //Constructor
    void leerLista();
    void imprimirLista();

    ~Arreglo();  //Destructor
};

int main()
{
    // ! no se puede hacer nada de esto sin una instancia
    Arreglo a;
    
    a.leerLista();
    a.imprimirLista();

    delete[] &a;

    getch();
    return 0;
}

// ! las estabas trabajando como funciones, ahora son metodos
void Arreglo::leerLista(){
    cout<<"Digite la lista: "<<endl;
    cin>>n;

    a = new float[n]; //Crear arreglo

    for(int i=0; i<n; i++){
        cout<<"Ingrese cuantos elementos en la lista: ";
        cin>>a[i];
    }
}

void Arreglo::imprimirLista(){
    cout<<"\n\nMostrando la lista: \n";
    
    for(int i=0; i<n; i++)
      cout << a[i] << endl;
}

// ! nunca escribiste un destructor
Arreglo::~Arreglo() {
    cout << "limpiando\n";
}

Arreglo::Arreglo() {
    cout << "limpiando\n";
}