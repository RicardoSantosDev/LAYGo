#include "RomReader.h"
#include <iostream>
#include <fstream>
#include <iterator>

#include <stdexcept>
#include <string>
#include <vector>

namespace laygo
{

    rom_reader::rom_reader(const std::string& filename)
    {
        std::ifstream rom(filename, std::ios::binary);

        if (!rom.is_open())
        {
            std::cerr << "Failed to open ROM file." << filename << "\n";
            return;
        }
        
        rom_data_.assign(std::istreambuf_iterator(rom),
                        std::istreambuf_iterator<char>());

    }

    std::span<const char> rom_reader::get_game_name() const
    {
        return {rom_data_.data() + 0x134, 16};
    }

    std::vector<char> rom_reader::get_rom_data() const
    {
        return rom_data_;
    }

}