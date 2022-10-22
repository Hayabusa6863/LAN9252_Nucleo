#include "DigitalOut.h"
#include "ThisThread.h"
#include "mbed.h"

SPI spi(PA_7, PA_6, PA_5);
DigitalOut cs(PB_6);

int main() {
    cs = 1;
    spi.frequency(20000000);
    spi.format(8, 3);

    int address = 0x064;    // BYTE_TEST(32bit)

    uint32_t read_data;
    uint8_t read_buffer[4];
    cs = 0;
    spi.write(0x03);    // Read Command
    spi.write((address >> 8) & 0xFF);   // Upper address byte
    spi.write((address >> 0) & 0xFF);   // Lower address byte
    // LSBから取得していく
    read_buffer[0]  = (uint8_t)spi.write(0x00);
    read_buffer[1]  = (uint8_t)spi.write(0x00);
    read_buffer[2]  = (uint8_t)spi.write(0x00);
    read_buffer[3]  = (uint8_t)spi.write(0x00);
    cs = 1;

    read_data = (read_buffer[3] << 24) 
              | (read_buffer[2] << 16) 
              | (read_buffer[1] << 8) 
              | (read_buffer[0] << 0);

    printf("read_data = %x\r\n", read_data);

    while(1) {
        ThisThread::sleep_for(500ms);
    }
}