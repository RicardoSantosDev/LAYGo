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
    class RomReader
    {
    private:
        std::vector<char> rom_data_;
    public:
        RomReader(std::string filename);
        std::span<const char> getGameName() const;
        [[nodiscard]] std::vector<char> getRomData() const;
    };
}

#endif /*ROM_READER_H*/