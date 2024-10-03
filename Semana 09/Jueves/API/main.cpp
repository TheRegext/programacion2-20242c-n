#include <iostream>
#include "HttpClient.h"
using namespace std;

int main()
{
    HttpClient cliente;
    string response;
    
    response = cliente.get("https://www.fruityvice.com/api/fruit/1");
    
    cout << response << endl;
    
    return 0;
}
