#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "sw_i2c.h"

static uint SDA_PIN, SCL_PIN;
#define I2C_DELAY_US 1

static void i2c_delay() {
    sleep_us(I2C_DELAY_US);
}

static void sda_high() {
    gpio_set_dir(SDA_PIN, GPIO_IN);
}

static void sda_low() {
    gpio_set_dir(SDA_PIN, GPIO_OUT);
    gpio_put(SDA_PIN, 0);
}

static void scl_high() {
    gpio_set_dir(SCL_PIN, GPIO_IN);
    i2c_delay();
}

static void scl_low() {
    gpio_set_dir(SCL_PIN, GPIO_OUT);
    gpio_put(SCL_PIN, 0);
    i2c_delay();
}

void i2c_init(uint8_t sda, uint8_t scl) {
    SDA_PIN = sda;
    SCL_PIN = scl;
    gpio_init(SDA_PIN);
    gpio_init(SCL_PIN);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);
    sda_high();
    scl_high();
}

void i2c_start() {
    sda_high();
    scl_high();
    i2c_delay();
    sda_low();
    i2c_delay();
    scl_low();
}

void i2c_stop() {
    sda_low();
    scl_high();
    i2c_delay();
    sda_high();
    i2c_delay();
}

bool i2c_write_byte(uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        if (byte & 0x80) sda_high(); else sda_low();
        byte <<= 1;
        scl_high();
        scl_low();
    }

    sda_high();
    scl_high();
    bool ack = !gpio_get(SDA_PIN);
    scl_low();
    return ack;
}

uint8_t i2c_read_byte(bool ack) {
    uint8_t byte = 0;
    sda_high();
    for (int i = 0; i < 8; i++) {
        byte <<= 1;
        scl_high();
        if (gpio_get(SDA_PIN)) byte |= 1;
        scl_low();
    }

    if (ack) sda_low(); else sda_high();
    scl_high();
    scl_low();
    sda_high();
    return byte;
}
