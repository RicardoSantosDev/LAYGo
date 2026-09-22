#include "RomReader.h"
#include <iostream>
#include <fstream>
#include <iterator>

namespace laygo
{

    RomReader::RomReader(std::string filename)
    {
        std::ifstream rom(filename, std::ios::binary);

        if (!rom.is_open())
        {
            std::cerr << "Failed to open ROM file." << filename << "\n";
            return;
        }
        
        rom_data_.assign(std::istreambuf_iterator<char>(rom),
                        std::istreambuf_iterator<char>());

    }

    std::vector<char> RomReader::getRomData() const
    {
        return rom_data_;
    }

}