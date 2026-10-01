#include <gtest/gtest.h>
#include "TORTOISE.hpp"
#include <unistd.h>
#include <spdlog/spdlog.h>

class MockPlayer{
    public:
        u_int8_t tableNull[924];
        float m_health = 0;
};

TEST(cheatTORTOISE,ActivateFunction){
    pid_t pid = getpid();
    Tortoise cheat = Tortoise("test");
    MockPlayer player = MockPlayer();

    mach_vm_address_t addrPlayer = reinterpret_cast<mach_vm_address_t>(&player);
    cheat.Activate(pid,addrPlayer);

    ASSERT_TRUE(player.m_health == 100);
}