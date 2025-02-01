params ["_patient", "_bodyPart", "_treatment", "_medic", "_itemUser", "_item"];
private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find toLowerANSI _bodyPart;

[_patient, "Epinephrine", 60, 420, -40, 0.15, 5] call ace_medical_status_fnc_addMedicationAdjustment;


private _ivBags = _patient getVariable ["ace_medical_ivBags", []];
_ivBags pushBack [_volume, _type, _partIndex, _treatment, _rateCoef, _item];
_patient setVariable ["ace_medical_ivBags", _ivBags, true];