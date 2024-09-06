#include <iostream>
using namespace std;

class Base
{
public:
   int x;

protected:
   int y;

private:
   int z;
};

// Herencia pública
class PublicaDerivada : public Base
{
    // x es public
    // y es protected
    // z no es accesible desde PublicaDerivada
};

// Herencia protegida
class ProtegidaDerivada: protected Base
{
    // x es protected
    // y es protected
    // z no es accesible desde ProtegidaDerivada
};

// Herencia privada
class PrivadaDerivada: private Base
{
    // x es privada
    // y es privada
    // z no es accesible desde PrivadaDerivada
};

int main(){

}
