#include <spi.h>

int main()
{
    spi_master_transfer(mode0, 5000000, true, 8, 0x58);
    return 0;
}
