#ifndef CONNECTORS_H
#define CONNECTORS_H


class Connectors
{
private:
    bool batteryConnector;
    bool pantographConnector;
    bool compressorAuxConnector;
    bool converterConnector;
    bool mainCompressorConnector;
    bool lightingConnector;
    bool airConnector;
    bool megaphoneConnector;
    bool retentionBrakeConnector;

public:
    Connectors();
    ~Connectors();
    bool getBatteryConnector() const;
    void setBatteryConnector(bool value);
    bool getPantographConnector() const;
    void setPantographConnector(bool value);
    bool getCompressorAuxConnector() const;
    void setCompressorAuxConnector(bool value);
    bool getConverterConnector() const;
    void setConverterConnector(bool value);
    bool getMainCompressorConnector() const;
    void setMainCompressorConnector(bool value);
    bool getLightingConnector() const;
    void setLightingConnector(bool value);
    bool getAirConnector() const;
    void setAirConnector(bool value);
    bool getMegaphoneConnector() const;
    void setMegaphoneConnector(bool value);
    bool getRetentionBrakeConnector() const;
    void setRetentionBrakeConnector(bool value);
};

#endif // CONNECTORS_H
