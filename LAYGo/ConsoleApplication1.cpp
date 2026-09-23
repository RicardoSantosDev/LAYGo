
#include <iostream>
#include <ostream>
#include <span>
#include <vector>

#include "RomReader/RomReader.h"
#include "Console/CPU.h"

int main(int argc, char* argv[])
{
    laygo::CPU console_cpu;
    
    std::cout << "Testing CPU registers" << std::endl;
    console_cpu.set_register_a(0x10);
    std::uint8_t register_a = console_cpu.get_register_a();
    if (register_a == 0x10)
        std::cout << "Register a OK" << std::endl;
    else
        std::cout << "Register a error" << std::endl;
    
    console_cpu.set_register_b(0x11);
    std::uint8_t register_b = console_cpu.get_register_b();
    if (register_b == 0x11)
        std::cout << "Register b OK" << std::endl;
    else
        std::cout << "Register b error" << std::endl;
    
    console_cpu.set_register_c(0x12);
    std::uint8_t register_c = console_cpu.get_register_c();
    if (register_c == 0x12)
        std::cout << "Register c OK" << std::endl;
    else
        std::cout << "Register c error" << std::endl;
    
    console_cpu.set_register_d(0x13);
    std::uint8_t register_d = console_cpu.get_register_d();
    if (register_d == 0x13)
        std::cout << "Register d OK" << std::endl;
    else
        std::cout << "Register d error" << std::endl;
    
    console_cpu.set_register_e(0x14);
    std::uint8_t register_e = console_cpu.get_register_e();
    if (register_e == 0x14)
        std::cout << "Register e OK" << std::endl;
    else
        std::cout << "Register e error" << std::endl;
    
    console_cpu.set_register_f(0x15);
    std::uint8_t register_f = console_cpu.get_register_f();
    if (register_f == 0x15)
        std::cout << "Register f OK" << std::endl;
    else
        std::cout << "Register f error" << std::endl;
    
    console_cpu.set_register_h(0x17);
    std::uint8_t register_h = console_cpu.get_register_h();
    if (register_h == 0x17)
        std::cout << "Register h OK" << std::endl;
    else
        std::cout << "Register h error" << std::endl;
    
    console_cpu.set_register_l(0x18);
    std::uint8_t register_l = console_cpu.get_register_l();
    if (register_l == 0x18)
        std::cout << "Register l OK" << std::endl;
    else
        std::cout << "Register l error" << std::endl;
     
    laygo::RomReader rom("roms/Mega Man II (USA).gb");
    auto rom_read = rom.getRomData();
    
    for (char c : rom.getGameName())
        std::cout << c;
    
    return 0;
}
