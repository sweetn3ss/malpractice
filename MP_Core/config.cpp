class cfgPatches {
    class MP_Core {
        name = "Malpractice Core";
        requiredVersion = 0.1;
        requiredAddons[]={
            "A3_Weapons_F_Ammoboxes"
        };
        author = "Gray";
        units[]={};
        weapons[]={};
    };
};
class cfgVehicles {
    class Bag_Base;
    class MP_Satchel: Bag_Base {
        scope=2;
        scopeArsenal=2;
        displayName = "Invisible Backpack";
		model = "\a3\weapons_f\empty.p3d";
        maximumLoad = 500;
    };
};