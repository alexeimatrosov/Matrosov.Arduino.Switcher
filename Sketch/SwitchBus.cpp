#include "Arduino.h"
#include "SwitchBus.h"

SwitchBus::SwitchBus(int* pins, int pinsCount)
{
    _pinsCount = pinsCount;
    _switches = new Switch*[pinsCount];
    for(int i = 0; i < _pinsCount; ++i)
    {
        _switches[i] = new Switch(pins[i]);
    }
}

void SwitchBus::Set(int pinIndex, int state)
{
    if(pinIndex >= _pinsCount) return;

    _switches[pinIndex]->Set(state);
}