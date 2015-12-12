#include "stdafx.h"
#include "DicClave.h"

DicClave::DicClave()
{
  Host = "";
  Clave = "";
  SubClave = "";
}

DicClave::DicClave(std::string unHost, std::string unaClave)
{
  Host = unHost;
  Clave = unaClave;
}

DicClave::DicClave(std::string unHost, std::string unaClave, std::string unaSubClave) 
{
  SubClave = unaSubClave;
  Host = unHost;
  Clave = unaClave;
}