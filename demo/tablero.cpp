#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent, SubteStatus *subte) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{
    if (subte==NULL){
        subte = new SubteStatus(0,false,false);
    }

    //SUBTE Model
    m_subte = subte;

    //Configuration and
    //Configuracion e instanciacion de los componentes en el UI
    ui->setupUi(this);

    setStyleSheet("\
        QWidget {background-image: url(:/resources/BKG_tablero.png);}\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };\
        QDial::handle { image: url(:/resources/BKG_tablero.png); };");

    Doors_Controller * doors = new Doors_Controller(m_subte,ui->panel_buttons3_left,ui->panel_buttons3_right, ui->dial);

    SpeedGauge_Controller * speedGauge = new SpeedGauge_Controller(m_subte,ui->speedGauge);

    TractionLever_Controller * tractionLever = new TractionLever_Controller(m_subte,ui->traction);
    
    // Configuracion del connect del device Maquina de Estados Hombre Vivo Muerto al device de encendido dial_HombreVivoHombreMuerto
    connect(ui->dial_HombreVivoHombreMuerto,SIGNAL(valueChanged(int)),this,SLOT(activateHombreVivoHombreMuerto(int)));

    // Seta Controller: Configuration
    Seta_Controller * setaButton = new Seta_Controller(m_subte, ui->widget_setaButton);

}

void Tablero::activateHombreVivoHombreMuerto(int pos){
    switch ( pos ) {
    case 0:
        if (this->m_deviceHombreVivoHombreMuerto != NULL){
            this->m_deviceHombreVivoHombreMuerto->off_HombreMuertoSystem();
        }
      break;
    case 1:
        if (this->m_deviceHombreVivoHombreMuerto == NULL){
            this->m_deviceHombreVivoHombreMuerto= new HombreVivoHombreMuerto_Controller(ui->widget_3);
            this->m_deviceHombreVivoHombreMuerto->on_HombreMuertoSystem();
        }else{
            this->m_deviceHombreVivoHombreMuerto->on_HombreMuertoSystem();
        }
      break;
    default:
      // Code
        qDebug() << "Error: En Dial activacion sistema hombre vivo muerto esta tomando una valor no contemplado en case del mismo" << pos;
      break;
    }
}

Tablero::~Tablero()
{
    delete ui;
    delete this->m_deviceHombreVivoHombreMuerto;
    delete this->m_deviceSetaController;
}
