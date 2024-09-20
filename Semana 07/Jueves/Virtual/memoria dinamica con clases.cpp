#include <iostream>
using namespace std;

class MyString{
private:
   char *_buffer;
public:
   MyString(int cantidad){
      _buffer = new char[cantidad];
   }
   
   ~MyString(){
      delete _buffer; 
   }
};

class A{
public:
   A(){
      _pValor = new int;
   }
   
   void setValor(int valor){
      *_pValor = valor;
   }
      
   int getValor(){
      return *_pValor;
   }
    
   /// operador de copia
   void operator=(const A &objeto){
      *_pValor = *objeto._pValor;
   }
   
   ~A(){
      if(_pValor != nullptr){ /// safe delete
         delete _pValor;
      }
   }
private:
   int *_pValor;
};

class B {
   int _valor;
public:
   void setValor(int valor){
      _valor = valor;
   }
   int getValor(){
      return _valor;
   }
};

int main() {
   // 0x33 0x34
   A ob1, ob2;   
   
   //0x34
   ob1 = ob2;
     
   ob1.setValor(1000);
   ob2.setValor(2000);
      
   cout << "ob1: " << ob1.getValor() << endl;
   cout << "ob2: " << ob2.getValor() << endl;
   
   ob1.setValor(500);
   cout << "ob1: " << ob1.getValor() << endl;
   cout << "ob2: " << ob2.getValor() << endl;
   
   ob2.setValor(200);
   cout << "ob1: " << ob1.getValor() << endl;
   cout << "ob2: " << ob2.getValor() << endl;
   
   
   /*
   
   MyString variable3(10), variable4(100);
   
   cout << sizeof(variable3) << endl;
   cout << sizeof(variable4) << endl;
   
   */
   
   
   /*
   string variable1; /// objeto
   
   char variable2[100]; /// array - buffer
   
   int *pNumeros;
   
   pNumeros = new int [10]; /// buffer de 10 numeros
   */
   
   
	
	return 0;
}

