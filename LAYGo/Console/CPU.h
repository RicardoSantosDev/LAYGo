#pragma once
#include <cstdint>

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
    class CPU
    {
    public:
        CPU();
        // Return CPU flags
        // Getters and setters for the registers
        std::uint8_t get_register_a() const
        {
            return a;
        }

        std::uint8_t set_register_a(std::uint8_t new_value)
        {
            a = new_value;
            return a;
        }

        std::uint8_t get_register_b() const
        {
            return b;
        }

        std::uint8_t set_register_b(std::uint8_t new_value)
        {
            b = new_value;
            return b;
        }

        std::uint8_t get_register_c() const
        {
            return c;
        }

        std::uint8_t set_register_c(std::uint8_t new_value)
        {
            c = new_value;
            return c;
        }

        std::uint8_t get_register_d() const
        {
            return d;
        }

        std::uint8_t set_register_d(std::uint8_t new_value)
        {
            d = new_value;
            return d;
        }

        std::uint8_t get_register_e() const
        {
            return e;
        }

        std::uint8_t set_register_e(std::uint8_t new_value)
        {
            e = new_value;
            return e;
        }

        std::uint8_t get_register_f() const
        {
            return f;
        }

        std::uint8_t set_register_f(std::uint8_t new_value)
        {
            f = new_value;
            return f;
        }

        std::uint8_t get_register_h() const
        {
            return h;
        }

        std::uint8_t set_register_h(std::uint8_t new_value)
        {
            h = new_value;
            return h;
        }
        
        std::uint8_t get_register_l() const
        {
            return l;
        }

        std::uint8_t set_register_l(std::uint8_t new_value)
        {
            l = new_value;
            return l;
        }

    private:
        // Define CPU registers
        std::uint8_t a{0x00};
        std::uint8_t b{0x00};
        std::uint8_t c{0x00};
        std::uint8_t d{0x00};
        std::uint8_t e{0x00};
        std::uint8_t f{0x00};
        std::uint8_t h{0x00};
        std::uint8_t l{0x00};
        // Define CPU operations
    
    };
}