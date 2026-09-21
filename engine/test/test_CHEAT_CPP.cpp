#include <gtest/gtest.h>
#include <CHEAT.hpp>
#include <unistd.h>
#include <spdlog/spdlog.h>

int v = 10;
mach_vm_address_t addr = (mach_vm_address_t)&v;
TEST(CheatsNativeFonction,ModifyValueWithAddr){
    pid_t p = getpid();
    Cheat object = Cheat("test",Type::Once);
    mach_port_t task = object.getTask(p);

    ASSERT_TRUE(task != TASK_NULL);

    bool modif = object.modifyValue(task,addr,17);

    if (modif == false)spdlog::info("[test_CHEAT_CPP.cpp] error modify value");
    ASSERT_TRUE(v == 17);

    spdlog::info("[test_CHEAT_CPP.cpp] success modify value");
}

