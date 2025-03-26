class cfgPatches {
    class MP_PaxMachina {
        name = "Malpractice Pax Machina";
        author = "Gray";
        units[]={};
        weapons[]={};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "MP_Core",
            "A3_Weapons_F"
        };
    };
};
class cfgFunctions {
    class MP_PaxMachina {
        class functions {
            file = "MP_PaxMachina\functions";
            class stimSwitch {}; // MP_PaxMachina_fnc_stimSwitch;
            class benadrylBuckshot {}; // MP_PaxMachina_fnc_benadrylBuckshot;
        };
    };
};
class cfgAmmo {
    class B_9x21_Ball_Tracer_Red;
    class MP_Dart_Bandage: B_9x21_Ball_Tracer_Red {
        hit = 0;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class MP_Dart_Cyanide: MP_Dart_Bandage {
        hit = 0;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class MP_Dart_Tranq: MP_Dart_Bandage {
        hit = 0;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class MP_Dart_Painkiller: MP_Dart_Bandage {
        hit = 0;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
};
class cfgMagazines {
    class 16rnd_9x21_Mag;
    class 8Rnd_Aegis_Bandage: 16rnd_9x21_Mag {
        displayName = "8Rnd Bandage Stim";
        author = "Gray";
        count = 8;
        tracersEvery = 1;
        ammo = "MP_Dart_Bandage";
        lastRoundsTracer = 0;
    };
    class 8Rnd_Aegis_Cyanide: 16rnd_9x21_Mag {
        displayName = "8Rnd Cyanide Stim";
        author = "Gray";
        count = 8;
        tracersEvery = 1;
        ammo = "MP_Dart_Cyanide";
        lastRoundsTracer = 0;
    };
    class 8Rnd_Aegis_Tranq: 16rnd_9x21_Mag {
        displayName = "8Rnd Tranquilizer Stim";
        author = "Gray";
        count = 8;
        tracersEvery = 1;
        ammo = "MP_Dart_Tranq";
        lastRoundsTracer = 0;
    };
    class 8Rnd_Aegis_Painkiller: 16rnd_9x21_Mag {
        displayName = "8Rnd Painkiller Stim";
        author = "Gray";
        count = 8;
        tracersEvery = 1;
        ammo = "MP_Dart_Painkiller";
        lastRoundsTracer = 0;
    };
};
class cfgWeapons {
    class hgun_Rook40_F;
    class MP_Aegis : hgun_Rook40_F {
        scope = 2;
        scopeArsenal = 2;
        displayName = "[MP] Aegis Stim Launcher";
        author = "Gray";
        baseWeapon = "MP_Aegis";
        magazines[] = {
            "8Rnd_Aegis_Cyanide",
            "8Rnd_Aegis_Tranq",
            "8Rnd_Aegis_Painkiller"
        };
    };
};
class Extended_HitPart_EventHandlers
{
    class CAManBase
    {
        mpHit = "(_this select 0) call MP_PaxMachina_fnc_stimSwitch";
    };
};