#include "enet/enet.h"
#include <string>
#include <thread>
#include <vector>

typedef std::function<void()> Connect;
typedef std::function<void()> DisConnect;
typedef std::function<void(std::string)> ConnectHost;
typedef std::function<void(std::string)> DisconnectHost;
typedef std::function<void(std::string, std::string, std::string)> CambioValClave;
typedef std::function<void(std::string, std::string)> MensajeErroneoRecibido;

class ENetClient
{
public:
  ENetClient(void);
  ~ENetClient(void);

  Connect OnConnect;
  DisConnect OnDisconnect;
  ConnectHost OnConnectHost;
  DisconnectHost OnDisconnectHost;
  CambioValClave OnCambioValClave;
  MensajeErroneoRecibido OnErrorRecibir;

  bool EstaConectado();
  bool Conectar(std::string unaIP, int unPuerto, std::string unNombre);
  bool Desconectar(void);
  void do_work();
  bool Suscribirse(std::string unCliente, std::string unaClave);
  bool DeSuscribirse(std::string unCliente, std::string unaClave);
  bool CambiarValorClave(std::string unaClave, std::string unNuevoValor);
  bool ColocarMiNombre(std::string unNombre);
  
protected:
  ENetHost* _fCliente;
  ENetPeer* _fServidor;
  ENetEvent _fEvento;
    
  bool Terminar;
  bool Inicializado;  
  std::thread _LosThreads[2];
  //std::future<void> _LosOtros[2];
  enet_uint32 FMilisegundosEspera;

  bool EnviarMensaje(short idCanal, std::string unTexto);

  // Cosas todavía no probadas
  bool CambiarValorClave(std::string unCliente, std::string unaClave, std::string unNuevoValor);

  void ProcesarBuffers(bool continuo);
  void ProcesarEvento();
  //void do_work(enet_uint32 miliseg);

  std::vector<std::string> StringSplit(std::string str, char delimiter);
  std::vector<std::string> StringSplit2(std::string str, std::string delimiter);

};
