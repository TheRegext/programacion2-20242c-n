///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Base{
protected:
     int p1, p2;
public:
     void setP1(int p){p1=p;}
     void setP2(int p){p2=p;}

     int getP1(){return p1;}
     int getP2(){return p2;}
};


class Derivada1:public Base{
private:
     int p3;
public:
    void setP3(int p){p3=p;}
    int getP3(){return p3;}
    void duplicarP1(){p1*=2;}

};

///propiedades de Derivada1: p1, p2 y p3;
///métodos de Derivada1: sets() y gets() de p1, p2 y p3

///qué propiedades son accesibles para Derivada1
int main(){
    Derivada1 obj;
    obj.setP1(5);
    cout<<obj.getP1();
	cout<<endl;
	obj.duplicarP1();
	cout<<obj.getP1();
	system("pause");
	return 0;
}

 /* si derivamos como private
class Derivada1{
private:
     int p1,p2, p3;
     void setP1(int p){p1=p;}
     void setP2(int p){p2=p;}

     int getP1(){return p1;}
     int getP2(){return p2;}
public:
    void setP3(int p){p3=p;}
    int getP3(){return p3;}

};
*/
/*si derivamos como public
class Derivada1{
private:
     int p1,p2, p3;

public:
    void setP3(int p){p3=p;}
    int getP3(){return p3;}
    void setP1(int p){p1=p;}
     void setP2(int p){p2=p;}

     int getP1(){return p1;}
     int getP2(){return p2;}

};
*/

