params ["_medic", "_patient", "_bodyPart", "_classname", "_itemUser", "_usedItem"];

[_patient, _usedItem] call ace_medical_treatment_fnc_addToTriageCard;
[_patient, "activity", "STR_ace_medical_treatment_Activity_gaveIV", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;

["mugManiacLocal", [_patient, _bodyPart, _classname, _medic, _itemUser, _usedItem], _patient] call CBA_fnc_targetEvent;