#include <gtest/gtest.h>
#include "GUNSGUNSGUNS.hpp"
#include <unistd.h>
#include <spdlog/spdlog.h>

struct MockWeapon{
    uint32_t m_eWeaponType;   
    uint32_t m_eWeaponState; 
    uint32_t m_nAmmoInClip;   
    uint32_t m_nAmmoTotal;    
    uint32_t m_nTimer;        
    uint32_t m_bAddRotOffset; 
};

class Player{
    public:
        u_int8_t tableNull[1144];
        MockWeapon m_weapon[13];
        void initialisation(){
            for(int i = 0;i<=12;i++){
                this->m_weapon[i].m_eWeaponType = 0;
                this->m_weapon[i].m_nAmmoInClip = 0;
                this->m_weapon[i].m_nAmmoTotal = 0;
                this->m_weapon[i].m_eWeaponState = 1;
                this->m_weapon[i].m_nTimer = 0;
            }
        }
};

TEST(CheatGUNSGUNSGUNS,ActivateFunction){
    pid_t p = getpid();
    Player player = Player();
    player.initialisation();
    mach_vm_address_t playerPtr = reinterpret_cast<mach_vm_address_t>(&player);

    GunsGunsGuns cheat = GunsGunsGuns("test");
    bool modif =cheat.Activate(p,playerPtr);

    if (modif == false)spdlog::error("[test_GUNSGUNSGUNS.cpp] error modify values");
    ASSERT_TRUE(player.m_weapon[7].m_eWeaponType == 7);
    
    spdlog::info("[test_GUNSGUNSGUNS.cpp] success modify values");
    std::cout << "========\n";
    std::cout << player.m_weapon[7].m_eWeaponType << std::endl;
}