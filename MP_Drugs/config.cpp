class cfgPatches {
    class MP_Drugs {
        name = "Malpractice Drugs";
        author = "Gray";
        units[]={};
        weapons[]={};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "MP_Core",
            "ace_medical_treatment"
        };
    };
};
class cfgFunctions {
    class MP {
        class functions {
            file = "MP_Drugs\functions";
            class cyanide {}; // MP_fnc_cyanide;
        };
    };
};

class cfgWeapons
{
    class ACE_morphine;
    class MP_Cyanide: ACE_morphine
    {
        displayName="Cyanide Pill";
        author="Gray";
        descriptionShort="Last Resort.";
        descriptionUse="Neifer told me to.";
    };
};

class Ace_Medical_Treatment_Actions
{
    class Morphine;
    class Cyanide: Morphine {
        displayName="Push Cyanide Tablet";
        displayNameProgress="Dead Men Tell No Tales...";
        allowedSelections[]={"Head"};
        category="medication";
        items[]={"MP_Cyanide"};
        condition="";
        treatmentTime=2;
        callbackSuccess="MP_fnc_cyanide";
        animationMedic="AinvPknlMstpSnonWnonDnon_medic1";
        sounds[]={{QPATHTO_R(sounds\Inject.ogg),1,1,50}};
        litter[]={{"ACE_MedicalLitter_morphine"}};
    };
};