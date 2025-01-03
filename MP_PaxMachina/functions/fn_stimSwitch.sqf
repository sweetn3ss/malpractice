#define MP_stimFallback 0
systemChat str "Line 2, stimSwitch";
params["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"];
private _weapon = currentWeapon _shooter;
private _mag = currentMagazine _shooter;
private _ammo = getText(configFile>>"CfgMagazines">>_mag>>"ammo");
systemChat str "Line 7, stimSwitch";
switch (_ammo) do {
    case "MP_Dart_Bandage": {
        hint "Bandage Round Detected";
        };
    default {
        systemChat "[ERROR] MALPRACTICE - MP_PaxMachina | Invalid Ammunition Type Fired";
    };
};