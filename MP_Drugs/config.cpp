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
            class chocolatemilk {}; // MP_fnc_chocolatemilk;
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
    class MP_ChocolateMilk: ACE_morphine
    {
        displayName="Chocolate Milk";
        author="Gray";
        descriptionShort="Your epic.";
        descriptionUse="I don't know how to cause this text to appear.";
        model = "MP_Drugs\data\choccymilk.p3d";
    };
};

class Ace_Medical_Treatment_Actions
{
    class Morphine;
    class Painkillers;
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
    class ChocolateMilk: Painkillers {
        displayName = "Drink Chocolate Milk";
        displayNameProgress="Drinking Chocolate Milk...";
        medicRequired = 0;
        allowedSelections[]={"Head"};
        category="medication";
        items[]={"MP_ChocolateMilk"};
        condition="";
        treatmentTime=3;
        callbackSuccess="MP_fnc_chocolatemilk";
        animationMedic="AinvPknlMstpSnonWnonDnon_medic1";
        sounds[]={{"\z\ace\addons\field_rations\sounds\drink2.ogg",1,1,50}};
        litter[]={{"MP_Litter_ChocolateMilk"}};
    };
};
class cfgVehicles {
    class ACE_MedicalLitter_morphine;
    class MP_Litter_ChocolateMilk: ACE_MedicalLitter_morphine {
        displayName = "";
        simulation = "thing";
        model = "\MP_Drugs\data\choccymilk.p3d";
    };
};