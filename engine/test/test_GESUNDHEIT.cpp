#include <gtest/gtest.h>
#include "GESUNDHEIT.hpp"
#include <unistd.h>
#include <spdlog/spdlog.h>

class MockPlayer{
    public:
        u_int8_t tableNull[920];
        float m_health = 0;
};

TEST(cheatGUNSGUNSGUNS,ActivateFunction){
    pid_t pid = getpid();
    MockPlayer player = MockPlayer();
    mach_vm_address_t playerAddress = reinterpret_cast<mach_vm_address_t>(&player);

    GesundHeit cheat = GesundHeit("test");
    bool cheatActivate = cheat.Activate(pid,playerAddress,250.0f);

    ASSERT_TRUE(player.m_health == 250.0f);
    ASSERT_TRUE(cheatActivate);
}

