#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "SwitchBus.h"

#ifndef NetworkController_h
#define NetworkController_h

class NetworkController
{
    private:
        static const unsigned int Port = 2807;
        static const unsigned int BufferLength = UDP_TX_PACKET_MAX_SIZE;
        byte* _buffer;
        EthernetUDP* _udp;
        EthernetServer* _tcpServer;
        SwitchBus* _switchBus;

    public:
        NetworkController(SwitchBus* switchBus);
        void Setup();
        void Loop();
        void TryProcessUdp();
        void TryProcessTcp();
        void ProcessPacket(byte* buffer, int length);
};

#endif