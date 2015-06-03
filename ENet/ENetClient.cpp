#include "stdafx.h"
#include "ENetClient.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

ENetClient::ENetClient()
{
  Conectado = false;
  Terminar = true;
  _fCliente = nullptr;
  _fServidor = nullptr;
}

ENetClient::~ENetClient()
{
  this-> Desconectar();

  if (_fServidor != nullptr)
  {
    Desconectar();
    _fServidor = nullptr;
  }

  if (_fCliente != nullptr)
  {
    enet_host_destroy(_fCliente);
    _fCliente = nullptr;
    _fServidor = nullptr;
  }
  enet_deinitialize();
}

bool ENetClient::Conectar(std::string unaIP, int unPuerto, std::string unNombre)
{
  bool result = false;
  if (_fCliente == nullptr)
  {
    if (enet_initialize() != 0)
      return result;
    _fCliente = enet_host_create(nullptr, 1, 5, 0, 0);

    if (_fCliente == nullptr)
      return result;

    ENetAddress direccionServidor;
    
    enet_address_set_host (&direccionServidor, unaIP.c_str());
    direccionServidor.port = unPuerto;

		_fServidor = enet_host_connect(_fCliente, &direccionServidor, 5, 0);    
    ProcesarBuffers(false);

    if (_fServidor != nullptr)
    {
      //Conectado = true;
      //_LosOtros[0] = std::async (&ENetClient::ProcesarBuffers,this);
      _LosThreads[0] = std::thread(&ENetClient::ProcesarBuffers, this, true);
      //_LosThreads[0].join(); // En teor�a est� andando el thread

      ColocarMiNombre(unNombre);
    }
  }
		
  return result;
}

bool ENetClient::Desconectar()
{
  bool result = false;
  if (_fServidor != nullptr)
  {
    Terminar = true;
    _LosThreads[0].join();
    enet_peer_disconnect_now(_fServidor, 0);
    result = true;
    _fServidor = nullptr;
  }
  return result;
}

void ENetClient::ProcesarBuffers(bool continuo)
{
  if (continuo) Terminar = false;
  while (!Terminar)
  {
    try
    {
      while (enet_host_service (_fCliente, &_fEvento, 75) > 0)
      {
        ProcesarEvento();
      }
    }
    catch (std::exception& e)
    {
      std::cout<<"Hubo un error"<<e.what();
    }
  }
  if (!continuo)
    while (enet_host_service (_fCliente, &_fEvento, 75) > 0)
    {
      ProcesarEvento();
    }

}

void ENetClient::ProcesarEvento()
{
  std::string mensaje;
  std::vector<std::string> partes;
  std::vector<char> myString;
  switch (_fEvento.type)
    {
      case ENET_EVENT_TYPE_CONNECT:
        if(OnConnect != nullptr) OnConnect();
        Conectado = true;
        break;

      case ENET_EVENT_TYPE_RECEIVE:
        myString = std::vector<char>(_fEvento.packet->dataLength + 1);
        myString[_fEvento.packet->dataLength] = '\0';
        memcpy(&myString[0], _fEvento.packet->data, _fEvento.packet->dataLength);
        mensaje = std::string(&myString[0]);

        //mensaje = std::string(reinterpret_cast<const char*>(_fEvento.packet->data));
        partes = StringSplit2(mensaje, "||");

        if (partes.size() <= 1 && OnErrorRecibir != nullptr)
          OnErrorRecibir("Mensaje Erroneo Recibido", mensaje);

        if (partes[0] == "valClave" && OnCambioValClave != nullptr)
            OnCambioValClave(partes[1], partes[2], partes[3]);

        enet_packet_destroy (_fEvento.packet);
        break;
       
      case ENET_EVENT_TYPE_DISCONNECT:
          if (OnDisconnect != nullptr) OnDisconnect();
          Conectado = false;
          _fEvento.peer -> data = nullptr;
        break;

      case ENET_EVENT_TYPE_NONE: 
        break;
      default: break;
    }
}

bool ENetClient::Suscribirse(std::string unCliente, std::string unaClave)
{
  return EnviarMensaje(1, "suscripPeer||"+unCliente+"||"+unaClave);
}

bool ENetClient::DeSuscribirse(std::string unCliente, std::string unaClave)
{
  return EnviarMensaje(1, "dsuscripPeer||"+unCliente+"||"+unaClave);
}

bool ENetClient::CambiarValorClave(std::string unaClave, std::string unNuevoValor)
{
  return EnviarMensaje(1, "valClave||"+unaClave+"||"+unNuevoValor);
}

bool ENetClient::CambiarValorClave(std::string unCliente, std::string unaClave, std::string unNuevoValor)
{
  return EnviarMensaje(1, "valCClave||"+unCliente+"||"+unaClave+"||"+unNuevoValor);
}

bool ENetClient::ColocarMiNombre(std::string unNombre)
{
  return EnviarMensaje(2, "miNombre||"+unNombre);
}

bool ENetClient::EnviarMensaje(short idCanal, std::string unTexto)
{
  bool result = false;
  if (!Conectado) return result;

  const char* mensaje = unTexto.c_str();
  size_t longitud = strlen(mensaje) + 1;
  
  ENetPacket* packet = enet_packet_create (mensaje, longitud, ENET_PACKET_FLAG_RELIABLE);

  try
  {
    enet_peer_send (_fServidor, idCanal, packet);  
    //enet_host_flush (_fCliente);
    result = true;
  }
  catch (std::exception& )
  {
    result = false;
  }
  
  return result;
}

std::vector<std::string> ENetClient::StringSplit2(std::string str, std::string delimiter) 
{
  std::vector<std::string> internal;
     
  size_t pos = 0;
  std::string token;
  while ((pos = str.find(delimiter)) != std::string::npos) 
  {
    token = str.substr(0, pos);
    //std::cout << token << std::endl;
    internal.push_back(token);
    str.erase(0, pos + delimiter.length());
  }
  internal.push_back(str);

  return internal;
}

std::vector<std::string> ENetClient::StringSplit(std::string str, char delimiter) 
{
  std::vector<std::string> internal;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}
