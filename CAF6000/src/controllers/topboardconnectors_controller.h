#ifndef TOPBOARDCONNECTORS_CONTROLLER_H
#define TOPBOARDCONNECTORS_CONTROLLER_H

#include <QObject>
#include <singlebutton.h>
#include "src/models/subtestatus.h"

class TopBoardConnectors_Controller : public QObject
{
    Q_OBJECT
public:
    explicit TopBoardConnectors_Controller(SubteStatus *subte);
    ~TopBoardConnectors_Controller();

    void setBattery(SingleButton *batteryCon, SingleButton *batteryDes);
    void setConmutadorPuestaServicio(SingleButton *conmutador, SingleButton *luzLlaveDes, SingleButton *luzLlaveCon, SingleButton *arranqueDes, SingleButton *arranqueCon);
    void setPantograph(SingleButton *pantographCon, SingleButton *pantographDes);
    void setCompressorAux(SingleButton *compressorAuxCon, SingleButton *compressorAuxDes);
    void setConverter(SingleButton *converterCon,SingleButton *converterDes );
    void setMainCompressor(SingleButton *mainCompressorCon, SingleButton *mainCompressorDes);
    void setLighting(SingleButton *lightingCon, SingleButton *lightingDes);
    void setAir(SingleButton *airCon, SingleButton *airDes);
    void setMegaphone(SingleButton *megaphoneCon, SingleButton *megaphoneDes);
    void setRetentionBrake(SingleButton *retentionBrakeCon, SingleButton *retentionBrakeDes);

    void setNivel(int n);
    void reset();

private:
    int m_nivel=0;
    void resetNivel0();
    void resetNivel1();
    void resetNivel2();

    SubteStatus *m_subte;
    SingleButton *m_batteryCon;
    SingleButton *m_conmutador;
    SingleButton *m_luzLlaveDes;
    SingleButton *m_luzLlaveCon;
    bool m_conmutadorPuestaServicioStatus;
    bool m_enMarcha;
    SingleButton *m_arranqueDes;
    SingleButton *m_arranqueCon;
    SingleButton *m_batteryDes;
    SingleButton *m_pantographCon;
    SingleButton *m_pantographDes;
    SingleButton *m_compressorAuxCon;
    SingleButton *m_compressorAuxDes;
    SingleButton *m_converterCon;
    SingleButton *m_converterDes;
    SingleButton *m_mainCompressorCon;
    SingleButton *m_mainCompressorDes;
    SingleButton *m_lightingCon;
    SingleButton *m_lightingDes;
    SingleButton *m_airCon;
    SingleButton *m_airDes;
    SingleButton *m_megaphoneCon;
    SingleButton *m_megaphoneDes;
    SingleButton *m_retentionBrakeCon;
    SingleButton *m_retentionBrakeDes;

private slots:
    void batteryConPressed();
    void batteryDesPressed();
    void conmutadorPuestaServicioPressed();
    void conmutadorPuestaServicioAutomaticaConPressed();
    void conmutadorPuestaServicioAutomaticaDesPressed();
    void pantographConPressed();
    void pantographDesPressed();
    void compressorAuxConPressed();
    void compressorAuxDesPressed();
    void converterConPressed();
    void converterDesPressed();
    void mainCompressorConPressed();
    void mainCompressorDesPressed();
    void lightingConPressed();
    void lightingDesPressed();
    void airConPressed();
    void airDesPressed();
    void megaphoneConPressed();
    void megaphoneDesPressed();
    void retentionBrakeConPressed();
    void retentionBrakeDesPressed();
};

#endif // TOPBOARDCONNECTORS_CONTROLLER_H
