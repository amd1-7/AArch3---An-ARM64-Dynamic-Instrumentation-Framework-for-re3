#ifndef ONCE_HPP
    #define ONCE_HPP
    #include "CHEAT.hpp"

    class Once : public Cheat{
        public:
            Once(std::string n) noexcept : Cheat(n,Type::Once){};
            ~Once() = default;

            virtual bool Activate() = 0;
    };
#endif