#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define FREQ_TO_MS(hz) (1000/hz)

typedef enum
{
    mode0 = 0,
    mode1,
    mode2,
    mode3
} spi_mode_e;


typedef struct 
{
    uint8_t sclk;
    uint8_t miso;
    uint8_t mosi;
    uint8_t cs;
} spi_s;

uint64_t test_input[] = {0x54, 0x66, 0x87, 0x33, 0x28, 0x15, 0x41, 0x90, 0x45, 0x78};

void delay(int milli_seconds);
void drive_high_spi_signal(uint8_t spi_signal);
void drive_low_spi_signal(uint8_t spi_signal);
void spi_master_transfer(spi_mode_e mode, uint64_t freq, bool msb_first, uint8_t BitsPerWord, uint64_t data);
