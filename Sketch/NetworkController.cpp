#include "NetworkController.h"

byte MacAddress[] = {0x00, 0xAA, 0xBB, 0xCC, 0x28, 0x07};

NetworkController::NetworkController(SwitchBus* switchBus)
{
    _switchBus = switchBus;
    _buffer = new byte[BufferLength];
    _udp = new EthernetUDP();
    _tcpServer = new EthernetServer(Port);
}

void NetworkController::Setup()
{
    if (Ethernet.begin(MacAddress) == 0)
    {
        for(;;);
    }
        
    _udp->begin(Port);
    _tcpServer->begin();
}

void NetworkController::Loop()
{
    TryProcessUdp();
    TryProcessTcp();
}

void NetworkController::TryProcessUdp()
{
    int packetSize = _udp->parsePacket();
    if (packetSize)
    {
        _udp->read(_buffer, BufferLength);
        ProcessPacket(_buffer, packetSize);
    }
}

void NetworkController::TryProcessTcp()
{
    EthernetClient client = _tcpServer->available();
    if (client) {
        int i = 0;
        while (client.connected() && client.available() && i < BufferLength) {
            _buffer[i++] = client.read();
        }
        client.stop();

        ProcessPacket(_buffer, i);
    }
}

void NetworkController::ProcessPacket(byte* buffer, int length)
{
    if (length < 4 || length % 2 == 1) return;
    
    if (buffer[0] == 0x28 && buffer[1] == 0x07)
    {
        for (int i = 2; i < length; i+=2)
        {
            int pinIndex = (int)_buffer[i];
            int state = (int)_buffer[i+1];
            _switchBus->Set(pinIndex, state);
        }
    }
}