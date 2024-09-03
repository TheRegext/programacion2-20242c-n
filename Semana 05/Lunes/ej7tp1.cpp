///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Usuario{
private:

public:



};

void cargarUsuarios(Usuario *vec){
    vec[0].setNombre("Daniel KLOSTER");
    vec[0].setClave("123456");
    vec[0].setRol("admin");

    vec[1].setNombre("Enrique SCHMIDT");
    vec[1].setClave("55555");
    vec[1].setRol("user");

    vec[2].setNombre("Ana PEREZ");
    vec[2].setClave("123456");
    vec[2].setRol("admin");

    vec[3].setNombre("Enriqueta GONZALEZ");
    vec[3].setClave("55555");
    vec[3].setRol("user");
}

int main(){
    Usuario vecUsuarios[4], aux;
    cargarUsuarios(vecUsuarios);
    string nombre, clave;
    cout<<"INGRESAR NOMBRE ";
    cin>>nombre;
    cout<<"INGRESAR CLAVE ";
    cin>>clave;
    int pos=validarUsuario(vecUsuarios, 4, nombre, clave);
    if(pos==-1){
        cout<<"USUARIO NO REGISTRADO"<<endl;
    }
    else{
        mostrarCartelBienvenida(vecUsuarios[pos]);
    }



	cout<<endl;
	system("pause");
	return 0;
}
