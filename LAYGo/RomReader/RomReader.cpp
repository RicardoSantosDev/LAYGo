#include "RomReader.h"
#include <iostream>
#include <fstream>
#include <iterator>

#include <cstddef>

#include <stdexcept>
#include <string>
#include <vector>

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

    std::span<const char> RomReader::getGameName() const
    {
        return std::span<const char>(rom_data_.data() + 0x134, 16);
    }

    std::vector<char> RomReader::getRomData() const
    {
        return rom_data_;
    }

}