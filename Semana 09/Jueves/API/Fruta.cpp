#include "Fruta.h"
using namespace std;

Fruta::Fruta()
{
  _id = 0;
  _name = "";
  _protein = 0.0f;
}

Fruta::Fruta(int id, string name, float protein)
{
  _id = id;
  _name = name;
  _protein = protein;
}

Fruta::Fruta(const nlohmann::json &data){
  _id = data["id"].get<int>();
  _name = data["name"].get<string>();
  if(!data["nutritions"]["protein"].is_null())
  {
    _protein = data["nutritions"]["protein"].get<float>();
  }
  else{
    _protein  = 0.0f;
  }
}

void Fruta::setID(int id)
{
  _id = id;
}

int Fruta::getID()
{
  return _id;
}

void Fruta::setName(string name)
{
  _name = name;
}

string Fruta::getName()
{
  return _name;
}

void Fruta::setProtein(float protein)
{
  _protein = protein;
}

float Fruta::getProtein()
{
  return _protein;
}

string Fruta::toCSV()
{
  string texto;

  texto = to_string(_id) + ", " + _name + ", " + to_string(_protein);

  return texto;
}
