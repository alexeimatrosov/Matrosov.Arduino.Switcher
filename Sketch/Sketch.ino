#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "SwitchBus.h"
#include "UdpController.h"

const int LOOP_DELAY = 100;
int TOGGLE_PINS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int TOGGLE_PINS_COUNT = 14;
SwitchBus _switchBus(TOGGLE_PINS, TOGGLE_PINS_COUNT);
UdpController _controller(&_switchBus);

void setup()
{
    _controller.Setup();
}

void loop()
{
    _controller.Loop();
    delay(LOOP_DELAY);
}
