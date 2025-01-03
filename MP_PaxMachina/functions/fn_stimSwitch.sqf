#define MP_stimFallback 0;

params ["_unit","_source","_damage","_instigator"]
private _weapon = currentWeapon _instigator;
private _mag = currentMagazine _instigator;
private _ammo = getText(configFile>>"CfgMagazines">>_mag>>"ammo");
switch (_ammo) {
    case "MP_Dart_Bandage": {
        systemChat "Bandage Round Detected";
        };
    default {
        systemChat "[ERROR] MALPRACTICE - MP_PaxMachina | Invalid Ammunition Type Fired";
    };
};