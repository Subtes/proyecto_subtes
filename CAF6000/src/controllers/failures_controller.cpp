#include "failures_controller.h"

Failures_Controller::Failures_Controller(SubteStatus *subte)
{
    m_subte = subte;
    m_lastFailure = "sin_averia";
}

Failures_Controller::~Failures_Controller()
{

}

void Failures_Controller::setFailure(std::string f)
{
    QString mensaje = QString(f.c_str());
    QStringList parametros = mensaje.split(";");
    if(parametros.at(1).compare("sin_averia") == 0){
        qDebug() << "sin_averia" ;
        if(!this->inFailure())
        {
            resolveFailure(m_lastFailure);
            qDebug() << "sin_averia" ;
        }
    }

    else if((parametros.at(1).compare("CursoNormalMasCF1")==0) || (parametros.at(1).compare("CursoNormalMasCF1P2")==0)){
        m_lastFailure = "coche_frenado_1";
        m_subte->setTractionFailure();
    }

    else if(parametros.at(1).compare("coche_frenado_2")==0){
        m_lastFailure = "coche_frenado_2";
        m_subte->setTractionFailure();
        m_subte->setBrakeFailure();
        m_subte->setCSCPFailure();
    }

    else if(parametros.at(1).compare("hilo_lazo_1")==0){
        m_lastFailure = "hilo_lazo_1";
        m_subte->setBrakeFailure();
    }

    else if(parametros.at(1).compare("hilo_lazo_2")==0){
        m_lastFailure = "hilo_lazo_2";
        m_subte->setBrakeFailure();
        m_subte->setCSCPFailure();
    }

    else if(parametros.at(1).compare("hilo_lazo_3")==0){
        m_lastFailure = "hilo_lazo_3";
        m_subte->setBrakeFailure();
        m_subte->setCSCPFailure();
    }

    else if(parametros.at(1).compare("hilo_lazo_4")==0){
        m_lastFailure = "hilo_lazo_4";
        m_subte->setTractionFailure();
        m_subte->setBrakeFailure();
        m_subte->setCSCPFailure();
    }

    else if(parametros.at(1).compare("hilo_lazo_5")==0){
        m_lastFailure = "hilo_lazo_5";
        m_subte->setTractionFailure();
        m_subte->setBrakeFailure();
        m_subte->setCSCPFailure();
    }
}

bool Failures_Controller::inFailure(){
    return m_lastFailure.compare("sin_averia") == 0;
}

void Failures_Controller::resolveFailure(std::string f){
    if(f.compare("coche_frenado_1")==0){
        m_subte->resolveTractionFailure();
    }

    else if(f.compare("coche_frenado_2")==0){
        m_subte->resolveTractionFailure();
    }

    else if(f.compare("hilo_lazo_1")==0){
        m_subte->resolveBrakeFailure();
    }

    else if(f.compare("hilo_lazo_2")==0){
        m_subte->resolveBrakeFailure();
        m_subte->resolveCSCPFailure();
    }

    else if(f.compare("hilo_lazo_3")==0){
        m_subte->resolveBrakeFailure();
        m_subte->resolveCSCPFailure();
    }

    else if(f.compare("hilo_lazo_4")==0){
        m_subte->resolveTractionFailure();
    }

    else if(f.compare("hilo_lazo_5")==0){
        m_subte->resolveTractionFailure();
    }

    m_lastFailure = "sin_averia";
}

