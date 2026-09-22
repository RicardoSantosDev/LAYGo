
#include <iostream>
#include <ostream>

#include "RomReader/RomReader.h"

int main(int argc, char* argv[])
{
    laygo::RomReader rom("roms/Tetris 2 (USA, Europe) (SGB Enhanced).gb");
    auto rom_read = rom.getRomData();
    
    std::cout << rom_read[0x134] << rom_read[0x135] << rom_read[0x136] << rom_read[0x137] << rom_read[0x138] << rom_read[0x139] << rom_read[0x13a] << rom_read[0x13b] << rom_read[0x13c] << rom_read[0x13d];
    
    return 0;
}
