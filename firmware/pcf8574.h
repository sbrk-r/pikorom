#pragma once

#include <stdint.h>
#include <stdbool.h>

void pcf8574_init(uint8_t address);
void pcf8574_write(uint8_t data);
uint8_t pcf8574_read();
