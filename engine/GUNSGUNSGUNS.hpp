#ifndef GUNS_GUNS_GUNS_CPP
    #define GUNS_GUNS_GUNS_CPP
    #include "class/ONCE.hpp"

    enum class OffsetVariable : uint8_t {
    Weapontype   = 0,
    WeaponState  = 4,
    AmmoClip     = 8,
    AmmoTotal    = 12,
    Timer        = 16,
    AddRotOffset = 20
};

    enum eWeaponType
{
	WEAPONTYPE_UNARMED,
	WEAPONTYPE_BASEBALLBAT,
	WEAPONTYPE_COLT45,
	WEAPONTYPE_UZI,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_AK47,
	WEAPONTYPE_M16,
	WEAPONTYPE_SNIPERRIFLE,
	WEAPONTYPE_ROCKETLAUNCHER,
	WEAPONTYPE_FLAMETHROWER,
	WEAPONTYPE_MOLOTOV,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_DETONATOR,
};
       
    class GunsGunsGuns : public Once{
        public:
            GunsGunsGuns(std::string n) noexcept : Once(n){};
            ~GunsGunsGuns() = default;

            bool Activate() noexcept override { return false; }
            bool Activate(pid_t p,mach_vm_address_t addrPlayer);
            mach_vm_address_t OffsetSlot0 = 1144;
    };
#endif