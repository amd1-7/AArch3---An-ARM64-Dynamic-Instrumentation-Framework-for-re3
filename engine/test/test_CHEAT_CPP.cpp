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
int x = 20;
mach_vm_address_t addr2 = (mach_vm_address_t)&x;
TEST(CheatsNativeFonction,ReadValueWithAddr){
    pid_t pid = getpid();
    Cheat cheat = Cheat("test",Type::Once);
    mach_port_t task = cheat.getTask(pid);
    ASSERT_TRUE(task != TASK_NULL);

    int output = 0;
    bool read = cheat.readValue(task,addr2,output);

    ASSERT_TRUE(read);
    ASSERT_TRUE(output == x);
}

