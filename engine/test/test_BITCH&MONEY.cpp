#include <gtest/gtest.h>
#include <BITCH&MONEY.hpp>
#include <unistd.h>
#include <spdlog/spdlog.h>

class MockPlayer{
    public:
        uint8_t tableNull[208];
        int32_t money = 100;
        int32_t visibleMoney = 100;
};

TEST(cheatBITCHANDMONEY,ActivateFunction){
    MockPlayer player = MockPlayer();
    mach_vm_address_t addrPlayer = reinterpret_cast<mach_vm_address_t>(&player);
    pid_t pid = getpid();

    BitchAndMoney cheat = BitchAndMoney("test");
    bool act = cheat.Activate(pid,addrPlayer);

    ASSERT_TRUE(act);
    ASSERT_TRUE(player.money == 250100);
    ASSERT_TRUE(player.visibleMoney == 250100);
}