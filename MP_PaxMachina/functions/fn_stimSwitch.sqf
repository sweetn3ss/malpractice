#define MP_stimFallback 0

params["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"];
if (!alive _target) exitWith {};

private _weapon = currentWeapon _shooter;
private _mag = currentMagazine _shooter;
private _ammo = getText(configFile>>"CfgMagazines">>_mag>>"ammo");
_selectionTemp = "Body";
if (_selection find "head" != -1) then {
    _selectionTemp = "Head";
} else {if (_selection find "hand_r" != -1) then {
    _selectionTemp = "RightArm";
} else {if (_selection find "hand_l" != -1) then {
    _selectionTemp = "LeftArm";
} else {if (_selection find "leg_r" != -1) then {
    _selectionTemp = "RightLeg";
} else {if (_selection find "leg_l" != -1) then {
    _selectionTemp = "LeftLeg";
} else {
    _selectionTemp = "Body"
}}}}};

_selection = _selectionTemp;
_medic = _shooter;
_patient = _target;
_bodyPart = _selection;

switch (_ammo) do {
    /*case "MP_Dart_Bandage": {
        systemChat format ["Target: %1",_target];
        systemChat format ["Shooter: %1",_shooter];
        systemChat format ["Selection: %1",_selection];
        [_medic,_patient,_bodyPart,"QuikClot",_medic,"",0] call ace_medical_treatment_fnc_treatmentSuccess;
        [_patient, "activity", "%2 shot %1 with a Bandage", [[_medic ] call ace_common_fnc_getName, [_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
    };*/
    case "MP_Dart_Cyanide": {
        if (_medic == _patient) then {
        [_patient, "activity", "%1 shot themself with Cyanide", [[_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
        [_patient,"Cyanide Dart"] call ace_medical_treatment_fnc_addtotriagecard;
        _patient setDamage 1;
        } else {
            [_patient, "activity", "%1 shot %2 with Cyanide", [[_medic ] call ace_common_fnc_getName, [_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
            [_patient, "Cyanide Dart"] call ace_medical_treatment_fnc_addtotriagecard;
            _patient setDamage 1;
        };
    };
    case "MP_Dart_Tranq": {
        [_patient, "activity", "%1 was Tranquilized for 15 seconds", [[_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
        [_patient, true, 15, true] call ace_medical_fnc_setUnconscious;
    };
    case "MP_Dart_Painkiller": {
        [_patient, "Painkillers", 60, 420, 5, 0.35, 5] call ace_medical_status_fnc_addMedicationAdjustment;
        [_patient, "Painkiller Dart"] call ace_medical_treatment_fnc_addtotriagecard;
    };
    case "MP_Buckshot_Benadryl": {
        //player execVM
    };
};