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
            class mugManiac {}; // MP_fnc_mugManiac;
            class mugManiacLocal {}; // MP_fnc_mugManiacLocal;
        };
    };
};

class cfgWeapons
{
    class ACE_morphine;
    class ACE_elasticBandage;
    class MP_Cyanide: ACE_morphine
    {
        displayName="Cyanide Pill";
        author="Gray";
        descriptionShort="Last Resort.";
        descriptionUse="Neifer told me to.";
        model = "\MP_Drugs\data\cyanide.p3d";
        picture = "\MP_Drugs\data\cyanide.paa";
    };
    class MP_ChocolateMilk: ACE_morphine
    {
        displayName="Chocolate Milk";
        author="Gray";
        descriptionShort="Your epic.";
        descriptionUse="I don't know how to cause this text to appear.";
        model = "\MP_Drugs\data\choccymilky.p3d";
        picture = "\MP_Drugs\data\choccymilky.paa";
    };
    class MP_HelloKitty_Bandages: ACE_elasticBandage
    {
        displayName="Bandage (Hello Kitty)";
        author="Gray";
        descriptionShort="Great for your ouch pouch.";
        descriptionUse="Great for you, your kids, and your Johnson!";
        model = "\MP_Drugs\data\bandages.p3d";
        picture = "\MP_Drugs\data\bandages.paa";
    };
    class ACE_bloodIV;
    class MP_IV_MugManiac: ACE_bloodIV {
        displayName = "Mug IV (1000ml)";
        author = "Gray";
        descriptionShort = "Only true #mugmaniacs can drink this.";
        descriptionUse = "How in god's name do I make this appear???";
        hiddenSelectionsTextures[] = {"MP_Drugs\data\mug_bag.paa"};
    };
};

class Ace_Medical_Treatment_Actions
{
    class Morphine;
    class Painkillers;
    class ElasticBandage;
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
        litter[]={{"MP_Litter_Cyanide"}};
    };
    class ChocolateMilk: Painkillers {
        displayName = "Push Chocolate Milk";
        displayNameProgress="Pushing Chocolate Milk...";
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
    class HKBandages: ElasticBandage {
        displayName = "Hello Kitty Bandage";
        items[]={"MP_HelloKitty_Bandages"};
        litter[]={{"MP_Litter_HKBandages"}};
        /*displayNameProgress="Bandaging...";
        medicRequired = 0;
        allowedSelections[]={"Head"};
        category="medication";
        condition="";
        treatmentTime=3;
        callbackSuccess="MP_fnc_chocolatemilk";
        animationMedic="AinvPknlMstpSnonWnonDnon_medic1";
        sounds[]={{"\z\ace\addons\field_rations\sounds\drink2.ogg",1,1,50}};*/
    };
    class BloodIV;
    class MugIV: BloodIV {
        displayName = "Give Mug IV (1000ml)";
        items[] = {"MP_IV_MugManiac"};
        displayNameProgress = "Conducting Mug Mania...";
        treatmentTime = 6;
    };
};
class Ace_Medical_Treatment {
    class Bandaging {
        class ElasticBandage;
        class HKBandages: ElasticBandage {};
    };
    class IV {
        class MugIV {
            volume = 1000;
            type = "Mug";
            rateCoef = 1;
        };
    };
};
class cfgVehicles {
    class ACE_MedicalLitter_morphine;
    class MP_Litter_ChocolateMilk: ACE_MedicalLitter_morphine {
        displayName = "";
        simulation = "thing";
        model = "\MP_Drugs\data\choccymilky.p3d";
    };
    class MP_Litter_HKBandages: ACE_MedicalLitter_morphine {
        displayName = "";
        simulation = "thing";
        model = "\MP_Drugs\data\bandages_litter.p3d";
    };
    class MP_Litter_Cyanide: ACE_MedicalLitter_morphine {
        displayName = "";
        simulation = "thing";
        model = "\MP_Drugs\data\cyanide_litter.p3d";
    };
};