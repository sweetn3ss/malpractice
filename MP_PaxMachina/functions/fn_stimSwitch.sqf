#define MP_stimFallback 0;

private _weapon = currentWeapon _shooter;
private _mag = currentMagazine _shooter;
private _ammo = getText(configFile>>"CfgMagazines">>_mag>>"ammo");
switch (_ammo) {
    case "MP_Dart_Bandage": {hint "Bandage Round Detected";};
    default {
        hint "[ERROR] MALPRACTICE - MP_PaxMachina | Invalid Ammunition Type Fired";
    };
};