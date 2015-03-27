#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);

    setStyleSheet("\
        QWidget {background-image: url(:/resources/BKG_tablero.png);}\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };\
        QDial::handle { image: url(:/resources/BKG_tablero.png); };");

    Doors_Controller * doors = new Doors_Controller(ui->panel_buttons3_left,
                                                    ui->panel_buttons3_right,
                                                    ui->dial);

    SpeedGauge_Controller * speedGauge = new SpeedGauge_Controller(ui->speedGauge);    
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),speedGauge,SLOT(updateNeedle(double)));

    // Configuracion connect de Maquina de Estados Hombre Vivo Muerto
    //HombreVivoHombreMuerto_Controller * deviceHombreVivoHombreMuerto = new HombreVivoHombreMuerto_Controller(ui->widget_3);
    connect(ui->dial_HombreVivoHombreMuerto,SIGNAL(valueChanged(int)),this,SLOT(activateHombreVivoHombreMuerto(int)));


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
}
