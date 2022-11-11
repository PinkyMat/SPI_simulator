#include <spi.h>

void delay(int milli_seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

void drive_high_spi_signal(uint8_t spi_signal)
{
    spi_signal = 1;
}

void drive_low_spi_signal(uint8_t spi_signal)
{
    spi_signal = 0;
}

void spi_master_transfer(spi_mode_e mode, uint64_t freq, bool msb_first, uint8_t BitsPerWord, uint64_t data)
{
    int milli_seconds =  FREQ_TO_MS(freq) / 2;
    
    switch(mode)
    {
        case mode0:
            drive_low_spi_signal(spi1.cs);
            
            if (!msb_first)
            {
                for (int i = 0; i < BitsPerWord; ++i)
                {
                    drive_high_spi_signal(spi1.sclk);
                    spi1.mosi = (data >> i) & 0x01;
                    
                    delay(milli_seconds);
                    
                    drive_low_spi_signal(spi1.sclk);
                    
                    delay(milli_seconds);
                }
            }
            else
            {
                for (int i = BitsPerWord-1; i >= 0; --i)
                {
                    drive_high_spi_signal(spi1.sclk);
                    spi1.mosi = (data >> i) & 0x01;
                    delay(milli_seconds);
                    
                    drive_low_spi_signal(spi1.sclk);
                    delay(milli_seconds);
                }
            }
            spi1.cs = 0;
            break;
        
        case mode1:
        case mode2:
        case mode3:
        default: printf("Mode not supported!\n");
    }
}

