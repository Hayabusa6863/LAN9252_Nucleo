#include "LAN9252.h"

LAN9252::LAN9252(PinName miso, PinName mosi, PinName sclk, PinName ssel)
 : spi(miso, mosi, sclk), cs(ssel) {
    cs = 1;
    spi.frequency(20000000);
    spi.format(8, 3);
 }


void LAN9252::select() {
    cs = 0;
}


void LAN9252::deselect() {
    cs = 1;
}