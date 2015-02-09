#include "SwitchBus.h"

#ifndef UdpController_h
#define UdpController_h

class UdpController
{
    private:
        static const unsigned int Port = 2807;
        SwitchBus* _switchBus;

    public:
        UdpController(SwitchBus* switchBus);
        void Setup();
        void Loop();
};

#endif