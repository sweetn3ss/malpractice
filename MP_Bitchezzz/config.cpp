class cfgPatches {
    class MP_Bitchezzz {
        name = "Malpractice Female Heads";
        author = "Gray";
        requiredVersion=0.1;
        requiredAddons[]={
            "MP_Core"
        };
    };
};
class Man;
class Custom;
class Default;
class cfgFaces {
    class Default;
    class Man_A3: Default {
        class Default;
        class MP_Female_Faye: Default {
            author = "Indie";
            displayName = "Faye";
            head = "MP_Female_01";
            texture = "MP_Bitchezzz\data\Faye\";
        };
    };
};
class cfgHeads {
    class DefaultHead_A3;
    class MP_Female_01: DefaultHead_A3 {
        model="\A3\characters_f\Heads\m_white_01";
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"A3\Characters_F\Heads\Data\m_white_09.rvmat",
				"A3\characters_f\Heads\Data\m_white_09_injury.rvmat",
				"A3\characters_f\Heads\Data\m_white_09_injury.rvmat"
			};
		};
    };
};