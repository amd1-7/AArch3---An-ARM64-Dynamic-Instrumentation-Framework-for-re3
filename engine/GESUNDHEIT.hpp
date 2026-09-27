#ifndef GESUNDHEIT_HPP
    #define GESUNDHEIT_HPP
    #include "class/ONCE.hpp"

    class GesundHeit : public Once{
        public:
            GesundHeit(std::string n) noexcept : Once(n){};
            ~GesundHeit() = default;

            bool Activate() noexcept override {return false;}
            bool Activate(pid_t p,mach_vm_address_t addrPlayer,float newValue);
    };
#endif