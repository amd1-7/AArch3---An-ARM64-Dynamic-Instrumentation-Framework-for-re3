#ifndef CHEAT_HPP
    #define CHEAT_HPP
    #include <string>
    #include <mach/mach.h>

    enum class Type{
        Persistent,
        Once,
    };

    class Cheat{
        private:
            std::string name;
            Type type;
        
        public:
            Cheat(std::string n,Type t) noexcept : name(n),type(t){};
            mach_port_t getTask(pid_t p);
            bool modifyValue(mach_port_t p,mach_vm_address_t addr,float newValue);
            bool modifyValue(mach_port_t p,mach_vm_address_t addr,int newValue);
};
#endif