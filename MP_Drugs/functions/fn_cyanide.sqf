/*
 * Author: Mesa
 * Should just literally kill them.
 *
 * Arguments:
 * 0: The medic <OBJECT>
 * 1: The patient <OBJECT>
 * 2: Selection Name <STRING>
 * 3: Treatment classname <STRING>
 * Return Value:
 * None
 *
 * Public: No
 */
 
// systemChat "Parameters Init";
 
diag_log ["_medic", "_patient"];

// systemChat "Parameters set, calling function";

diag_log [_patient] call ace_medical_status_fnc_setDead;

// systemChat "Function called, running addToLog";

if (_medic == _patient) then {
    [_patient, "activity", "%1 ingested Cyanide", [[_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
    _patient setDamage 1;
} else {
    [_patient, "activity", "%1 gave %2 Cyanide", [[_medic ] call ace_common_fnc_getName, [_patient] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
    _patient setDamage 1;
};

// systemChat "All done, green across the board.";