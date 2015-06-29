#ifndef BRAKE_H
#define BRAKE_H


class Brake
{

private:
    bool m_emergencyBrake;
    bool m_parkingBrake;
    double m_brake;
    double m_lastBrake;


public:
    Brake();
    ~Brake();
    bool braking();

    void reset();
    bool getEmergencyBrake() const;
    void setEmergencyBrake(bool value);
    double getBrake() const;
    void setBrake(double value);
    bool parkingBrake() const;
    void setParkingBrake(bool parkingBrake);
    double lastBrake() const;
    void setLastBrake(double lastBrake);
};

#endif // BRAKE_H
