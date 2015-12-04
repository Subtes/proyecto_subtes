#ifndef AUTOMATICTRAINPROTECTION_H
#define AUTOMATICTRAINPROTECTION_H

#include <QObject>

class AutomaticTrainProtection
{

private:
    double m_allowedSpeed;
    double m_targetSpeed;
    std::string m_code;
    bool m_traction;

public:
    AutomaticTrainProtection();
    ~AutomaticTrainProtection();
    bool tractionReady();
    void reset();

    double allowedSpeed() const;
    void setAllowedSpeed(double allowedSpeed);
    double targetSpeed() const;
    void setTargetSpeed(double targetSpeed);
    std::string code() const;
    void setCode(const std::string &code);
    void cutTraction();
    void enableTraction();
};

#endif // AUTOMATICTRAINPROTECTION_H
