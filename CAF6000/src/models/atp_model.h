#ifndef ATP_MODEL_H
#define ATP_MODEL_H

#include <string>

class ATP_model
{

private:
    double m_allowedSpeed;
    double m_targetSpeed;
    std::string m_code;

public:
    ATP_model();
    ~ATP_model();
    bool tractionReady();
    void reset();

    double allowedSpeed() const;
    void setAllowedSpeed(double allowedSpeed);
    double targetSpeed() const;
    void setTargetSpeed(double targetSpeed);
    std::string code() const;
    void setCode(const std::string &code);
};

#endif // ATP_MODEL_H
