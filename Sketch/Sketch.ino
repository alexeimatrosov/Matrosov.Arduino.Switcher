#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "SwitchBus.h"
#include "NetworkController.h"

const int LOOP_DELAY = 5;
int PINS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int PINS_COUNT = 14;
SwitchBus _switchBus(PINS, PINS_COUNT);
NetworkController _controller(&_switchBus);

void setup()
{
    _controller.Setup();

    Serial.begin(9600);
    Serial.print("IP Address: ");
    Serial.println(Ethernet.localIP());
}

void loop()
{
    _controller.Loop();
    delay(LOOP_DELAY);
}
