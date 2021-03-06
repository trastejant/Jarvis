#ifndef LEDPANELNODE_H
#define LEDPANELNODE_H

#include "jarvisNode.h"
#include "ledMatrixIcons.h"
#include "temperatureSensor.h"

class ledPanelNode : public jarvisNode
{
public:
    ledPanelNode() : jarvisNode() ,m_ledMatrix(0,16,16,&m_ledStrip,true), m_tempSensor(A0)
    {
        m_components.push_back(&m_ledMatrix);
        m_components.push_back(&m_tempSensor);
        m_id = "ledPanel";
    }

    void setup()
    {
        m_ledMatrix.setLeds(ledMatrixIcons::wifiYellowIcon16x16());
        m_ledMatrix.glow();
        jarvisNode::setup();
    }

    void wifiConnected()
    {
        if(connectionStatus() == 3)
        {
            m_ledMatrix.setLeds(ledMatrixIcons::wifiGreenIcon16x16());
            m_ledMatrix.glow();
        }
        else if(connectionStatus() == 0)
        {
            m_ledMatrix.setLeds(ledMatrixIcons::wifiBlueIcon16x16());
        }
    }

    void wifiDisConnected()
    {
        m_ledMatrix.setLeds(ledMatrixIcons::wifiRedIcon16x16());
    }

    void jarvisConnected()
    {
        m_ledMatrix.setLeds(ledMatrixIcons::mMakeSpaceIcon16x16());
        m_ledMatrix.glow();
    }

    void jarvisDisConnected()
    {
        if(connectionStatus() == 3)
        {
            m_ledMatrix.setLeds(ledMatrixIcons::wifiGreenIcon16x16());
            m_ledMatrix.glow();
        }
        else if(connectionStatus() == 0)
        {
            m_ledMatrix.setLeds(ledMatrixIcons::wifiBlueIcon16x16());
        }
    }

protected:
    ledMatrix   m_ledMatrix;
    tmp36Sensor m_tempSensor;
};

#endif // LEDPANELNODE_H
