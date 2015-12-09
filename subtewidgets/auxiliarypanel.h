#ifndef AUXILIARYPANEL_H
#define AUXILIARYPANEL_H

#include <QWidget>
#include <QQuickItem>
#include <QJsonArray>

namespace Ui {
class AuxiliaryPanel;
}

class AuxiliaryPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AuxiliaryPanel(QWidget *parent = 0);
    ~AuxiliaryPanel();

    QQuickItem *m_qmlView1;
    QQuickItem *m_qmlView2;
    QQuickItem *m_qmlView3;

signals:
    void switchSelected(QString);
    void processThermalPanel(QString);


public slots:
    bool level1(QString s);
    void level2(QString s);
    void level3(QString s);
    void optionSelected(QString op);
    void setSwitchModel(QString panel, QQuickItem *view3);
    void processLoadThermal(QQuickItem *item, QMap<QString,QVariant> *m_switch);

private:
    Ui::AuxiliaryPanel *ui;

    QString m_config;
    QString m_configModelSubway;
    QFile m_subways;
    QFile m_modelSubway;
    QString m_wagonSelected;
    /**
     * @brief m_paneles
     * Mantiene el estado de los switch leidos desde archivo. <tipoPanel,Vector de Switch con sus datos>
     * Estos datos de switch los va a utilizar en el Nivel 3, segun la opción elejida en N2, por ejemplo:
     * si selecciona panel de termicas, el mismo se instanciara con las termicas segun el archivo.
     * Mas adelante según demanda podria cargarce en función de un modelo con datos en particular según
     * pedido de instrucciones para un ejercicio particular en un momento x.
     */
    QHash<QString,QVariantList> *m_paneles;

    QTimer *m_setingThermal;

    bool m_located;
};

#endif // AUXILIARYPANEL_H
