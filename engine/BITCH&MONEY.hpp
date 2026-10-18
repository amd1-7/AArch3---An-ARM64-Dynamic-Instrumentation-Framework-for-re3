#ifndef BITCH_AND_MONEY_CPP
    #define BITCH_AND_MONEY_CPP
    #include "class/ONCE.hpp"

    class BitchAndMoney: public Once{
        public:
            BitchAndMoney(std::string n) noexcept : Once(n){};
            ~BitchAndMoney() = default;

            bool Activate() noexcept override {return false;}
            bool Activate(pid_t p,mach_vm_address_t addrPlayerInfo);
    };
#endif