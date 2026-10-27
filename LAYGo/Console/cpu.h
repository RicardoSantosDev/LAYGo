#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>

/**
 * ---- REGISTERS ----
 * 
 * The LR35902 CPU chip have 8 one-byte long registers. Schematically, the registers can be viewed as follows: 
 * 
 * +-----------+-----------+
 * |     a     |     f     |
 * +-----------+-----------+
 * |     b     |     c     |
 * +-----------+-----------+
 * |     d     |     e     |
 * +-----------+-----------+
 * |     h     |     l     |
 * +-----------+-----------+
 * 
 * The registers are organized in this way, because the CPU can create 16-bit virtual registers, uniting registers:
 *  - a+f, register af. a if for the high byte and f is for the low byte;
 *  - b+c, register bc. b if for the high byte and c is for the low byte;
 *  - d+e, register de. d if for the high byte and e is for the low byte;
 *  - h+l, register hl. h if for the high byte and l is for the low byte.
 * 
 * The f register is the flags register, which functions as such:
 * 
 *      |  bit 7  |  bit 6  |  bit 5  |  bit 4  |  bit 3  |  bit 2  |  bit 1  |  bit 0  |
 *           |         |         |         |         |         |         |         |
 *           F         F         F         F         A         A         A         A         
 *           l         l         l         l         l         l         l         l
 *           a         a         a         a         w         w         w         w
 *           g         g         g         g         a         a         a         a
 *                                                   y         y         y         y
 *           z         s         h         c         s         s         s         s
 *           e         u         a         a                                     
 *           r         b         l         r         0         0         0         0
 *           o         t         f         r
 *                     r                   y
 *                     a         c
 *                     c         a
 *                     t         r
 *                     i         r
 *                     o         y
 *                     n
 */
namespace laygo
{
    struct cpu_registers
    {
        std::uint8_t a{0x00};
        std::uint8_t b{0x00};
        std::uint8_t c{0x00};
        std::uint8_t d{0x00};
        std::uint8_t e{0x00};
        std::uint8_t f{0x00};
        std::uint8_t h{0x00};
        std::uint8_t l{0x00};
    };
    class cpu
    {
    public:
        cpu();
        // Getters and setters for the registers_

        [[nodiscard]] std::uint8_t get_register(const std::string& register_name) const
        {
            return register_map_.at(register_name);
        }
        
        std::uint8_t set_register(const std::string& register_name, std::uint8_t const new_value)
        {
            register_map_.at(register_name) = new_value;
            return register_map_.at(register_name);
        }
        
        // Access CPU flags
        
        void set_flag_zero()
        {
            registers_.f = registers_.f | 0b10000000;
        }
        
        void reset_flag_zero()
        {
            registers_.f = registers_.f & 0b01111111;
        }
        
        void set_flag_subtraction()
        {
            registers_.f = registers_.f | 0b01000000;
        }
        
        void reset_flag_subtraction()
        {
            registers_.f = registers_.f & 0b10111111;
        }
        
        void set_flag_half_carry()
        {
            registers_.f = registers_.f | 0b00100000;
        }
        
        void reset_flag_half_carry()
        {
            registers_.f = registers_.f & 0b11011111;
        }
        
        void set_flag_carry()
        {
            registers_.f = registers_.f | 0b00010000;
        }
        
        void reset_flag_carry()
        {
            registers_.f = registers_.f & 0b11101111;
        }
        
        // Check flags

        [[nodiscard]] bool is_flag_zero_set() const
        {
            return registers_.f & 0b10000000;
        }

        [[nodiscard]] bool is_flag_subtraction_set() const
        {
            return registers_.f & 0b01000000;
        }

        [[nodiscard]] bool is_flag_half_carry_set() const
        {
            return registers_.f & 0b00100000;
        }

        [[nodiscard]] bool is_flag_carry_set() const
        {
            return registers_.f & 0b00010000;
        }

    private:
        // Define CPU registers_
        cpu_registers registers_;
        
        std::unordered_map<std::string, std::uint8_t> register_map_ = 
            {
            { "a", 0x00 },
            { "b", 0x00 },
            { "c", 0x00 },
            { "d", 0x00 },
            { "e", 0x00 },
            { "f", 0x00 },
            { "h", 0x00 },
            { "l", 0x00 }
        };
        // Define cpu operations
    
    };
}