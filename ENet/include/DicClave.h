#pragma once
#include <string>

struct DicClave
{
  DicClave();
  DicClave(std::string unHost, std::string unaClave);
  DicClave(std::string unHost, std::string unaClave, std::string unaSubClave);

  std::string Host;
  std::string Clave;
  std::string SubClave;

  bool operator<(const DicClave& other) const { return ((Host < other.Host) && (Clave < other.Clave) && (SubClave < other.SubClave)); }
};

