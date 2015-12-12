#pragma once

#include <string>
#include <map>
#include "ErrorClave.h"
#include "DicClave.h"

class AdmClaves
{
  protected:
    bool FUsarDiccionario;
    std::map<std::string, std::map<std::string, std::string>> _fValClaves1;
    std::map<DicClave, std::string> _fValClaves;

  public:
    AdmClaves(void);
    ~AdmClaves(void);

    bool UsarDiccionario() {return FUsarDiccionario;}
    void Set_UsarDiccionario(bool usarDiccionario) { FUsarDiccionario = usarDiccionario;}

    ErrorClave AgregarClave(DicClave unaClave, std::string unValor);
    ErrorClave AgregarClave(std::string unHost, std::string unaClave, std::string unaSubClave, std::string unValor);
    ErrorClave AgregarClave(std::string unHost, std::string unaClave, std::string unValor);
    ErrorClave ValorClave(std::string unHost, std::string unaClave);
    ErrorClave ValorClave(std::string unHost, std::string unaClave, std::string unaSubClave);
    ErrorClave AltaClave(std::string unHost, std::string unaClave);
    ErrorClave ClavesDeHost(std::string unHost);
    ErrorClave ClavesDeClave(std::string unHost, std::string unaClave);
};

