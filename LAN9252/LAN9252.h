#ifndef LAN9252_H_
#define LAN9252_H_

#include "DigitalOut.h"
#include "mbed.h"

class LAN9252 {
private:
    SPI spi;
    DigitalOut cs;  // Chip Select Pin

    void select();
    void deselect();

public:
    LAN9252(PinName miso, PinName mosi, PinName sclk, PinName ssel);
};

#endif