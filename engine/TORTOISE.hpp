#ifndef TORTOISE_HPP
    #define TORTOISE_HPP
    #include "class/ONCE.hpp"

    class Tortoise : public Once{
        public:
            Tortoise(std::string n) noexcept : Once(n){};
            ~Tortoise() = default;

            bool Activate() noexcept override { return false; }
            bool Activate(pid_t p,mach_vm_address_t addrPlayer);
    };
#endif