#include "stdafx.h"
#include "AdmClaves.h"
#include "string"
#include "DicClave.h"

AdmClaves::AdmClaves(void)
{
  _fValClaves.clear();
}

AdmClaves::~AdmClaves(void)
{
  _fValClaves.clear();
}

//ErrorClave AdmClaves::AltaClave(std::string unHost, std::string unaClave)
//{
//  auto result = ErrorClave::CrearOK();
//
//  _fValClaves[unHost][unaClave] = "";
//
//  return result; 
//}

ErrorClave AdmClaves::AgregarClave(DicClave unaClave, std::string unValor)
{
  auto result = ErrorClave::CrearOK();
  _fValClaves[unaClave] = unValor;
  return result;
}

ErrorClave AdmClaves::AgregarClave(std::string unHost, std::string unaClave, std::string unaSubClave, std::string unValor)
{
  return AgregarClave(DicClave(unHost, unaClave, unaSubClave), unValor);
}

ErrorClave AdmClaves::AgregarClave(std::string unHost, std::string unaClave, std::string unValor)
{
  return AgregarClave(DicClave(unHost, unaClave, ""), unValor);
}

ErrorClave AdmClaves::ValorClave(std::string unHost, std::string unaClave)
{
  return ValorClave(unHost, unaClave, "");
  //if (_fValClaves.find(unHost) == _fValClaves.end())
  //  return ErrorClave::CrearHostInexistente();

  //if (_fValClaves[unHost].find(unaClave) == _fValClaves[unaClave].end())
  //  return ErrorClave::CrearClaveInexistente();

  //return ErrorClave::CrearOK(_fValClaves[unHost][unaClave]);
}

ErrorClave AdmClaves::ValorClave(std::string unHost, std::string unaClave, std::string unaSubClave)
{
  DicClave temp = DicClave(unHost, unaClave, unaSubClave);
  if (_fValClaves.find(temp) == _fValClaves.end())
    return ErrorClave::CrearClaveInexistente();
  return ErrorClave::CrearOK(_fValClaves[temp]);
}

ErrorClave AdmClaves::ClavesDeHost(std::string unHost)
{
  auto result = ErrorClave::CrearOK();
  for (auto ii = _fValClaves.begin(); ii != _fValClaves.end(); ++ii)
    if (ii->first.Host == unHost)
      result.Valores.push_back(_fValClaves[ii->first]);

  if (result.Valores.empty()) return ErrorClave::CrearClaveInexistente();
  
  return result;
}

ErrorClave AdmClaves::ClavesDeClave(std::string unHost, std::string unaClave)
{
  auto result = ErrorClave::CrearOK();
  for (auto ii = _fValClaves.begin(); ii != _fValClaves.end(); ++ii)
    if (ii->first.Host == unHost && ii->first.Clave == unaClave)
      result.Valores.push_back(_fValClaves[ii->first]);

  if (result.Valores.empty()) return ErrorClave::CrearClaveInexistente();

  return result;
}