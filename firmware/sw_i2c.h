#pragma once

#include <stdint.h>
#include <stdbool.h>

void i2c_init(uint8_t sda_pin, uint8_t scl_pin);
void i2c_start();
void i2c_stop();
bool i2c_write_byte(uint8_t byte);
uint8_t i2c_read_byte(bool ack);
