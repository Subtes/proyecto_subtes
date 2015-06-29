#ifndef CSCP_H
#define CSCP_H


class CSCP
{

private:
    static const bool OPEN = true;
    static const bool CLOSE = false;

    bool bypass;
    bool m_leftDoors;
    bool m_rightDoors;

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
};

#endif // CSCP_H
