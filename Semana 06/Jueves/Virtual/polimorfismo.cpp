#include <iostream>
using namespace std;

class IMostrable{
public:
  virtual void mostrar() const = 0;  
};

class ICargable{
public:
  virtual void cargar() = 0;
};

/// clase abstracta
class A: public IMostrable, public ICargable{
private:
  int _numero;
public: 
    A(){
      _numero = 10;
    }
    void setNumero(int num){
      _numero = num;
    }
    
    int getNumero() const{
      return _numero;
    }
    
    void mostrar() const {
      cout << "Soy el metodo de la clase A: "<< getNumero()<<endl;
    }
    
    void cargar() override{
      cout << "Ingrese numero: ";
      cin >> _numero;
    }
};

class B: public A{

public:
  B(){
    setNumero(30);
  }
  
  void mostrar() const override {
    // A::mostrar();
    cout << "Soy el metodo de la clase B" << endl;
  }
  
};

void mostrarObjeto(const IMostrable &obj){
  obj.mostrar();
}

void cargarObjeto(ICargable &obj){
  cout << "CARGAR DATOS: " << endl;
  cout << "----------------" << endl;
  obj.cargar();
}

void mostrarObjeto(IMostrable *pObj){
  pObj->mostrar();
}

int main(){
  IMostrable *objetos[10];
  
  for(int i= 0; i <10; i++){
    if(rand() % 2 == 0){
      objetos[i] = new A;    
    }
    else{
      objetos[i] = new B;    
    }
  }
  
  for(int i= 0; i <10; i++){
    objetos[i]->mostrar();
  }
  
  for(int i= 0; i <10; i++){
    delete objetos[i];
  }
  
  
  /*
  A objA;
  B objB;
  
  cout << "---- OBJETO A: "<<endl;
  mostrarObjeto(objA);
  cout << "---- OBJETO B: "<< endl;
  //((A)objB).mostrar(); /// this -> *A
  mostrarObjeto(objB);  
  
  
  cargarObjeto(objA);
  
  mostrarObjeto(objA);  
  */
  return 0;
}
