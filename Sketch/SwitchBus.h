#include "Arduino.h"
#include "Switch.h"

#ifndef SwitchBus_h
#define SwitchBus_h

class SwitchBus
{
    private:
        Switch** _switches;
        int _pinsCount;

    public:
        SwitchBus(int* pins, int pinsCount);
        void Set(int pinIndex, int state);
};

#endif