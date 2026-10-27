
#include <iostream>
#include <ostream>
#include <span>
#include <vector>

#include "RomReader/RomReader.h"
#include "Console/cpu.h"

int main(int argc, char* argv[])
{
    laygo::cpu console_cpu;
    
    std::cout << "Testing CPU registers" << '\n';
    console_cpu.set_register("a", 0x10);
    std::uint8_t register_a = console_cpu.get_register("a");
    if (register_a == 0x10)
        std::cout << "Register a OK" << '\n';
    else
        std::cout << "Register a error" << '\n';
    
    console_cpu.set_register("b", 0x11);
    std::uint8_t register_b = console_cpu.get_register("b");
    if (register_b == 0x11)
        std::cout << "Register b OK" << '\n';
    else
        std::cout << "Register b error" << '\n';
    
    console_cpu.set_register("c", 0x12);
    std::uint8_t register_c = console_cpu.get_register("c");
    if (register_c == 0x12)
        std::cout << "Register c OK" << '\n';
    else
        std::cout << "Register c error" << '\n';
    
    console_cpu.set_register("d", 0x13);
    std::uint8_t register_d = console_cpu.get_register("d");
    if (register_d == 0x13)
        std::cout << "Register d OK" << '\n';
    else
        std::cout << "Register d error" << '\n';
    
    console_cpu.set_register("e", 0x14);
    std::uint8_t register_e = console_cpu.get_register("e");
    if (register_e == 0x14)
        std::cout << "Register e OK" << '\n';
    else
        std::cout << "Register e error" << '\n';
    
    console_cpu.set_register("f", 0xF0);
    std::uint8_t register_f = console_cpu.get_register("f");
    if (register_f == 0xF0)
        std::cout << "Register f OK" << '\n';
    else
        std::cout << "Register f error" << '\n';
    
    console_cpu.set_register("h", 0x17);
    if (std::uint8_t register_h = console_cpu.get_register("h"); register_h == 0x17)
        std::cout << "Register h OK" << '\n';
    else
        std::cout << "Register h error" << '\n';
    
    console_cpu.set_register("l", 0x18);
    std::uint8_t register_l = console_cpu.get_register("l");
    if (register_l == 0x18)
        std::cout << "Register l OK" << '\n';
    else
        std::cout << "Register l error" << '\n';
    
    console_cpu.reset_flag_zero();
    if (!console_cpu.is_flag_zero_set())
        std::cout << "Flag zero OK" << '\n';
    else
        std::cout << "Flag zero error" << '\n';
     
    console_cpu.set_flag_carry();
    console_cpu.set_flag_zero();
    if (console_cpu.is_flag_zero_set())
        std::cout << "Flag zero OK" << '\n';
    else
        std::cout << "Flag zero error" << '\n';
    
    laygo::rom_reader rom("roms/Mega Man II (USA).gb");
    auto rom_read = rom.get_rom_data();
    
    for (char c : rom.get_game_name())
        std::cout << c;
    
    return 0;
}
