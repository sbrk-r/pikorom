#include "sw_i2c.h"

static uint8_t pcf8574_addr;

void pcf8574_init(uint8_t address) {
    pcf8574_addr = address & 0x7F;
}

void pcf8574_write(uint8_t data) {
    i2c_start();
    i2c_write_byte(pcf8574_addr << 1);
    i2c_write_byte(data);
    i2c_stop();
}

uint8_t pcf8574_read() {
    uint8_t data;
    i2c_start();
    i2c_write_byte((pcf8574_addr << 1) | 1);
    data = i2c_read_byte(false);
    i2c_stop();
    return data;
}
