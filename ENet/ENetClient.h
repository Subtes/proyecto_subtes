#ifndef ENETCLIENT_H
#define ENETCLIENT_H

#include "enet/enet.h"
#include <string>
#include <memory>
#include <thread>
#include <vector>
#include <future>

class ENetClient
{
public:
  ENetClient(void);
  ~ENetClient(void);

  bool Conectado;

  bool Conectar(std::string unaIP, int unPuerto, std::string unNombre);
  bool Desconectar(void);

  std::function<void(void)> OnConnect;
  std::function<void(void)> OnDisconnect;
  std::function<void(std::string)> OnConnectHost;
  std::function<void(std::string)> OnDisconnectHost;
  std::function<void(std::string, std::string, std::string)> OnCambioValClave;
  std::function<void(std::string, std::string)> OnErrorRecibir;

  bool Suscribirse(std::string unCliente, std::string unaClave);
  bool DeSuscribirse(std::string unCliente, std::string unaClave);
  bool CambiarValorClave(std::string unaClave, std::string unNuevoValor);
  bool CambiarValorClave(std::string unCliente, std::string unaClave, std::string unNuevoValor);
  bool ColocarMiNombre(std::string unNombre);

protected:
  ENetHost* _fCliente;
  ENetPeer* _fServidor;
  ENetEvent _fEvento;
    
  bool Terminar;
  
  std::thread _LosThreads[2];
  //std::future<void> _LosOtros[2];

  bool EnviarMensaje(short idCanal, std::string unTexto);
		
  void ProcesarBuffers(bool continuo);
  void ProcesarEvento();

  std::vector<std::string> StringSplit(std::string str, char delimiter);
  std::vector<std::string> StringSplit2(std::string str, std::string delimiter);

};

#endif // ENETCLIENT_H
