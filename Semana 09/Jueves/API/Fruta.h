#include <string>
#include "json.hpp"

class Fruta{
private:
  int _id;
  std::string _name;
  float _protein;
public:
  Fruta();  
  Fruta(int id, std::string name, float protein);
  Fruta(const nlohmann::json &data);
  void setID(int id);
  int getID();
  void setName(std::string name);
  std::string getName();
  void setProtein(float protein);
  float getProtein();
  std::string toCSV();
};
