#ifndef CSCP_H
#define CSCP_H


class CSCP
{

private:
    static const bool OPEN = true;
    static const bool CLOSE = false;

    bool m_bypass;
    bool m_leftDoors;
    bool m_rightDoors;
    bool m_averia;

    bool m_rightDoorsPanel;
    bool m_leftDoorsPanel;

    bool m_parkingBrake;

public:
    CSCP();
    ~CSCP();
    void reset();
    bool evalCircuit();
    bool getBypass() const;
    void setBypass(bool value);
    bool leftDoors() const;
    bool rightDoors() const;
    void openLeftDoors();
    void openRightDoors();
    void closeLeftDoors();
    void closeRightDoors();
    bool averia() const;
    void setAveria(bool averia);
    bool parkingBrake() const;
    void setParkingBrake(bool parkingBrake);
};

#endif // CSCP_H
