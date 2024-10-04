#include <iostream>
#include "HttpClient.h"
#include "json.hpp"
#include "Fruta.h"
using namespace std;

/*
  mapa 
  diccionario
  array asociativo
*/

int main()
{
    HttpClient cliente;
    string response;
    nlohmann::json data;
    Fruta fruta;
    
    response = cliente.get("https://www.fruityvice.com/api/fruit/all");

    data = nlohmann::json::parse(response);
    
    Fruta *frutas= new Fruta[data.size()];
    
    for(int i=0; i<data.size(); i++){
      frutas[i] = Fruta(data[i]);  
    }
    
    Fruta frutaMaxima;
    for(int i=0; i<data.size(); i++){
      if(frutas[i].getProtein() > frutaMaxima.getProtein()){
      frutaMaxima = frutas[i];      
      }
    }

    cout << "La fruta con mas proteinas es: " << frutaMaxima.getName() << endl;
    
    delete [] frutas;
    
    //fruta = Fruta(data["id"].get<int>(), data["name"].get<string>(), data["nutritions"]["protein"].get<float>());
    /*
    fruta = Fruta(data);
    
    cout << fruta.toCSV() << endl;
    */
    /*
    string nombre = data["name"].get<string>();
    
    cout << nombre << endl;
    cout << data["family"].get<string>() << endl;
    */
    
    return 0;
}
