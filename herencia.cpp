#include<iostream>

using namespace std;

/*
  . Hay herencia simple entre A y B
  * Hay herencia multinivel entre A, B y C
  # Hay herencia multiple entre A, E y F
  ! Hay herencia gerarquica entre A, B y F
  % Todavía no hacemos hacemos una herencia híbrida
*/

class A {
public:
  float a;
  
  A(float _a) { 
    a = _a; 
  }
  
  void status() {
    hacerAlgo();
  }
  
  // sin virtual: muestra la de A, con virtual, muestra la de B
  virtual void hacerAlgo() {
    cout << "A hace algo\n";
  }
};

class B: public A {
public:
  float b;

  B(float _a, float _b): A(_a) {
    b = _b;
  }
  
  // como en A ya es virtual, aquí en B no hizo falta
  void hacerAlgo() {
    cout << "B hace algo\n";
  }
};

class C: public B {
public:
  float c;

  C(float _a, float _b): B(_a, _b) {
    c = _a + _b;
  }
  
  void hacerAlgo() {
    B::hacerAlgo();
    cout << "C hace algo\n";
  }
};

class E {
public:
  float e;
  
  E(float _e) {
    e = _e;
  }
  
  virtual void hacerAlgo() {
    cout << "E hace algo\n";
  }
};

class F: public A, E {
public:
  float f;
  
  F(float _f): A(_f + 1), E(_f / 2) {
    f = _f;
  }
  
  void hacerAlgo() {
    A::hacerAlgo();
    E::hacerAlgo();
    cout << "F hace algo\n";
  }
};

int main(){
  A a(4);
  B b(5,2);
  F c(8);
  
  a.status();
  
  cout << endl;
  
  b.status();
  
  cout << endl;
  
  c.status();
  
  return 0;
}