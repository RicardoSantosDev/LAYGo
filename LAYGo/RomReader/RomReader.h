/* rom_reader.h

This class is used to read the rom and to provide access to its contents.
*/

#ifndef ROM_READER_H
#define ROM_READER_H

#pragma once
#include <vector>
#include <string>
#include <span>

namespace laygo
{
    class rom_reader
    {
        std::vector<char> rom_data_;
    public:
        explicit rom_reader(const std::string& filename);
        [[nodiscard]] std::span<const char> get_game_name() const;
        [[nodiscard]] std::vector<char> get_rom_data() const;
    };
}

#endif /*ROM_READER_H*/