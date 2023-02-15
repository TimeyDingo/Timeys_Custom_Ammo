#define _ARMA_
class CfgPatches
{
	class Timey_Custom_Ammo
	{
		name = "Timey's custom ammo";
		author = "Timey";
		url = "https://steamcommunity.com/id/TimeyTheDingo";
		magazines[] = {};
		ammo[] = {};
		units[] = {};
		weapons[] = {};
		requiredAddons[] =
		{
			"A3_Data_F", // replace all with A3 with A3_Data_F_AoW_Loadorder
			"A3_Data_F_Mark",
			"A3_Weapons_F",
			"A3_Data_F_Mark",
			"A3_Data_F",
			"A3Data",
			"A3_Weapons_F_EPA",
			"weapons_f_contact",
			"cba_main",
			"rhsusf_weapons",
			"ACE_Common",
			"ace_csw",
			"rhsusf_main_loadorder",,
			"A3_Weapons_F_EPA",
			"A3_Weapons_F_tank",
			"A3_Weapons_F_orange",
			"A3_Weapons_F_EXP",
			"A3_Weapons_F_enoch",
			"a3_sounds_f",
			"a3_weapons_f",
			"a3_sounds_f_exp",
			"rhsusf_sounds",
			"rhsusf_c_weaponsounds",
			"sounds_f_mark"
		};
	};
};
class CfgMineTriggers
{
	class RangeTriggerBounding;
	class T_Trigger : RangeTriggerBounding
	{
		mineTriggerRange = 1000;
		mineTriggerMass = 1;
		restrictZoneCenter[] = { 0,0,0 };
		restrictZoneRadius = 5;
		mineDelay = 0;
	};
	class TankTriggerMagnetic;
	class T_TriggerMag : TankTriggerMagnetic
	{
		mineMagnetic = 1;
		mineTriggerMass = 20;
		mineTriggerRange = 1;
		mineWireStart[] = { 0,0,0 };
		mineWireEnd[] = { 0,1,0 };
	};
};
class CfgAmmo
{
	class B_12Gauge_Slug;
	class BulletBase;
	class G_40mm_HE;
	class APERSBoundingMine_Range_Ammo;
	class ShotDeployBase;
	class T_Copper_HP_Slug: B_12Gauge_Slug// High damage extremely low penetration slug
	{
		hit = 25;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 0.65;
		cartridge = "";
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_slug";
		typicalSpeed = 200;
		airFriction = -0.001102;
		minRange = 0.25;
		midRange = 50;
		maxRange = 200;
		maxRangeProbab = 0.50;
		ACE_Caliber = 18;// Bullet diameter in mm (diameter is a little different from caliber)
		ACE_bulletLength = 40; // Bullet Length in mm
		ACE_bulletMass = 28; // Mass in grams
		ACE_muzzleVelocityVariationSD = .10;// Standard deviation of the muzzle velocity variation in percent Example: With a muzzle velocity of 850 m/s and a standard deviation of 0.35%, 68% of the shots will be between 847 m/s and 853 m/s
		ACE_standardAtmosphere = "ASM"; // "ASM" or "ICAO"
		ACE_dragModel = 1; // Number that specifies the drag model [1, 2, 5, 6, 7, 8] https://www.thefirearmblog.com/blog/2016/05/13/ballistics-101-ballistic-coefficient/
		ACE_ballisticCoefficients[] = {0.165}; // Array of ballistic coefficients (contains one element more than the velocity boundary array)
		ACE_ammoTempMuzzleVelocityShifts[] = {-27.20, -26.44, -23.76, -21.00, -17.54, -13.10, -7.95, -1.62, 6.24, 15.48, 27.75};//Array of muzzle velocity shifts in m / s with 11 data points from - 15 °C to 35 °C
	};
	class T_Tungsten_AP_Slug: B_12Gauge_Slug// Armor piercing slug
	{
		hit = 21;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 5.95;
		cartridge = "";
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_slug";
		typicalSpeed = 200;
		airFriction = -0.000651;
		minRange = 0.25;
		midRange = 50;
		maxRange = 200;
		maxRangeProbab = 0.50;
		ACE_Caliber = 12.15
		ACE_bulletLength = 50;
		ACE_bulletMass = 32;
		ACE_muzzleVelocityVariationSD = .05;
		ACE_standardAtmosphere = "ASM";
		ACE_dragModel = 7;
		ACE_ballisticCoefficients[] = {0.083};
		ACE_ammoTempMuzzleVelocityShifts[] = {-17.20, -16.44, -13.76, -11.00, -07.54, -03.10, -0.95, 1.62, 6.24, 15.48, 27.75};
		submunitionAmmo = "T_Copper_Hush_HP_Slug";
		submunitionDirectionType = "SubmunitionTargetDirection";
		deleteParentWhenTriggered = 0;
		submunitionInitSpeed = 250;
		submunitionParentSpeedCoef = 1;
		triggerDistance = 2.5;
		submunitionInitialOffset[] = { 0,0,-0.05 };
		triggerOnImpact = 1;
	};
	class T_Copper_Hush_HP_Slug: B_12Gauge_Slug// Subsonic stealthy slug
	{
		hit = 25;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 0.25;
		cartridge = "";
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_slug";
		typicalSpeed = 150;
		airFriction = -0.000136;
		minRange = 0.25;
		midRange = 50;
		maxRange = 120;
		maxRangeProbab = 0.50;
		ACE_Caliber = 18;
		ACE_bulletLength = 40;
		ACE_bulletMass = 28;
		ACE_muzzleVelocityVariationSD = .10;
		ACE_standardAtmosphere = "ASM";
		ACE_dragModel = 1;
		ACE_ballisticCoefficients[] = { 0.165 };
		ACE_ammoTempMuzzleVelocityShifts[] = { -27.20, -26.44, -23.76, -21.00, -17.54, -13.10, -7.95, -1.62, 6.24, 15.48, 27.75 };
	};
	class T_MV_40mm_HE: G_40mm_HE
	{
		aiAmmoUsageFlags = "64 + 128 + 512";
		hit = 60;
		indirectHit = 5;
		indirectHitRange = 10.7;
		model = "\A3\weapons_f\ammo\UGL_slug";
		fuseDistance = 15;
	};
	class T_MV_40mm_HEDP: T_MV_40mm_HE
	{
		aiAmmoUsageFlags = "64 + 128 + 256";
		hit = 95;
		indirectHit = 5;
		indirectHitRange = 3.6;
		model = "\A3\weapons_f\ammo\UGL_slug";
	};
	class T_MV_40mm_HET: ShotDeployBase // can be fixed by possibly using the method for the shotgun, spawning a explosive 2 meters in the air and then blowing it up instantly
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		fuseDistance = 15;
		typicalspeed = 118;
		submunitionDirectionType = "SubmunitionTargetDirection";
		deleteParentWhenTriggered = 1;
		submunitionAmmo = "T_HET_sub";
		submunitionInitSpeed = 0;
		triggerDistance = 1.5;
		submunitionInitialOffset[] = { 0,0,0 };
		submunitionParentSpeedCoef = 0;
	};
	class T_HET_sub : APERSBoundingMine_Range_Ammo
	{
		hit = 20;
		indirectHit = 20;
		indirectHitRange = 20;
		model = "\A3\Weapons_F\explosives\mine_AP_bouncing";
		mineModelDisabled = "\A3\Weapons_F\explosives\mine_AP_bouncing_d";
		defaultMagazine = "APERSBoundingMine_Range_Mag";
		mineBoundingTime = 0.3;
		mineBoundingDist = 2.0;
		mineTrigger = "T_Trigger";
	};
	class T_40mm_TirePopperDeployer : T_MV_40mm_HET
	{
		typicalspeed = 70;
		fuseDistance = 0;
		submunitionAmmo = "T_TirePopper";
		triggerDistance = 0;
	};
	class ATMine_Range_Ammo;
	class T_TirePopper: ATMine_Range_Ammo
	{
		hit = 100;
		indirectHit = 100;
		indirectHitRange = 0.2;
		directionalExplosion = 1;
		explosionAngle = 8;
		model = "\A3\Weapons_f\Explosives\mine_at";
		mineTrigger = "T_TriggerMag";
		triggerWhenDestroyed = 1;
	};
};
class CfgMagazines
{
	class 2Rnd_12Gauge_Slug;
	class timey_2rnd_Copper_HP_Slug: 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_HP_Slug";
		count = 2;
		initspeed = 442;
		displayName = "2rnd Copper HP Slug";
		displayNameShort = "Copper HP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 2;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_2rnd_Tungsten_AP_Slug: 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Tungsten_AP_Slug";
		count = 2;
		initspeed = 600;
		displayName = "2rnd Tungsten AP Slug";
		displayNameShort = "Tungsten AP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 2;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_2rnd_Copper_Hush_HP_Slug: 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_Hush_HP_Slug";
		count = 2;
		initspeed = 330;
		displayName = "2rnd Copper HUSH HP Slug";
		displayNameShort = "HUSH Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 2;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_5rnd_Copper_HP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_HP_Slug";
		count = 5;
		initspeed = 442;
		displayName = "5rnd Copper HP Slug";
		displayNameShort = "Copper HP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 5;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_5rnd_Tungsten_AP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Tungsten_AP_Slug";
		count = 5;
		initspeed = 600;
		displayName = "5rnd Tungsten AP Slug";
		displayNameShort = "Tungsten AP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 5;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_5rnd_Copper_Hush_HP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_Hush_HP_Slug";
		count = 5;
		initspeed = 330;
		displayName = "5rnd Copper HUSH HP Slug";
		displayNameShort = "HUSH Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 5;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_8rnd_Copper_HP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_HP_Slug";
		count = 8;
		initspeed = 442;
		displayName = "8rnd Copper HP Slug";
		displayNameShort = "Copper HP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 8;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_8rnd_Tungsten_AP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Tungsten_AP_Slug";
		count = 8;
		initspeed = 600;
		displayName = "8rnd Tungsten AP Slug";
		displayNameShort = "Tungsten AP Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 8;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_8rnd_Copper_Hush_HP_Slug : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Copper_Hush_HP_Slug";
		count = 8;
		initspeed = 330;
		displayName = "8rnd Copper HUSH HP Slug";
		displayNameShort = "HUSH Slug";
		descriptionshort = "Caliber: 12 gauge<br />Rounds: 2<br />Used in: Kozlice";
		mass = 8;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class 1Rnd_HE_Grenade_shell;
	class timey_1rnd_40mm_HE: 1Rnd_HE_Grenade_shell
	{
		mass = 5;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HE";
		initspeed = 150;
		displayName = "MV 40mm HE";
		displaynameshort = "HE/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 1<br />Used in: M203, M320, M79";
		deleteIfEmpty = 0;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_1rnd_40mm_HEDP: 1Rnd_HE_Grenade_shell
	{
		mass = 5;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HEDP";
		initspeed = 150;
		displayName = "MV 40mm HEDP";
		displaynameshort = "HEDP/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 1<br />Used in: M203, M320, M79";
		deleteIfEmpty = 0;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_1rnd_40mm_HET: 1Rnd_HE_Grenade_shell
	{
		mass = 5;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HET";
		initspeed = 150;
		displayName = "MV 40mm HET";
		displaynameshort = "HET/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 1<br />Used in: M203, M320, M79";
		deleteIfEmpty = 0;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_6rnd_40mm_HE : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HE";
		initspeed = 150;
		displayName = "6rnd MV 40mm HE";
		displaynameshort = "6xHE/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 6<br />Used in: M32";
		count = 6;
		mass = 30;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_6rnd_40mm_HEDP : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HEDP";
		initspeed = 150;
		displayName = "6rnd MV 40mm HEDP";
		displaynameshort = "6xHEDP/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 6<br />Used in: M32";
		count = 6;
		mass = 30;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_6rnd_40mm_HET : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HET"
		initspeed = 150;
		displayName = "6rnd MV 40mm HET";
		displaynameshort = "6xHET/MV";
		descriptionshort = "Type: High Explosive Grenade<br />Caliber: 40 mm<br />Rounds: 6<br />Used in: M32";
		count = 6;
		mass = 30;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
	class timey_6rnd_40mm_TirePopper : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_40mm_TirePopperDeployer"
		initspeed = 80;
		displayName = "6rnd 40mm T/P";
		displaynameshort = "6xT/P";
		descriptionshort = "Type: Deploys a tire popper <br />Caliber: 40 mm<br />Rounds: 6<br />Used in: M32";
		count = 6;
		mass = 10;
		picture = "\addons\UI\12GaugeIcon.paa";
	};
};
class CfgMagazineWells
{
	class CBA_12g_2rnds
	{
	TimeyCustom[] += {"timey_2rnd_Copper_HP_Slug", "timey_2rnd_Tungsten_AP_Slug", "timey_2rnd_Copper_Hush_HP_Slug"};
	};
	class CBA_12g_5rnds
	{
	TimeyCustom[] += {"timey_5rnd_Copper_HP_Slug", "timey_5rnd_Tungsten_AP_Slug", "timey_5rnd_Copper_Hush_HP_Slug"};
	};
	class CBA_12g_8rnds
	{
	TimeyCustom[] += {"timey_8rnd_Copper_HP_Slug", "timey_8rnd_Tungsten_AP_Slug", "timey_8rnd_Copper_Hush_HP_Slug"};
	};
	class HunterShotgun_01_12GA
	{
	TimeyCustom[] += {"timey_2rnd_Copper_HP_Slug", "timey_2rnd_Tungsten_AP_Slug", "timey_2rnd_Copper_Hush_HP_Slug"};
	};
	class CBA_40mm_M203_6rnds
	{
	TimeyCustom[] += {"timey_6rnd_40mm_HE", "timey_6rnd_40mm_HEDP", "timey_6rnd_40mm_HET", "timey_6rnd_40mm_TirePopper"};
	};
	class CBA_40mm_M203
	{
	TimeyCustom[] += {"timey_1rnd_40mm_HE", "timey_1rnd_40mm_HEDP", "timey_1rnd_40mm_HET"};
	};
	class UGL_40x36
	{
	TimeyCustom[] += {"timey_1rnd_40mm_HE", "timey_1rnd_40mm_HEDP", "timey_1rnd_40mm_HET"};
	};
};
class Mode_SemiAuto;
class rhs_western_m24_muzzle_slot;
class MuzzleSlot : rhs_western_m24_muzzle_slot {};
class MuzzleSlot_762 : MuzzleSlot {};
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F : Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
		class Eventhandlers;
	};
	class rhs_weap_M590_5RD : Rifle_Base_F
	{
		ACE_twistDirection = 0;
		ACE_barrelLength = 470;
		rhs_boltActionSound[] = { "rhsusf\addons\rhsusf_c_weapons\sounds\m590_pump.ogg", 0.12, 1, 20 };
		class Single: Mode_SemiAuto
		{
			sounds[] = { StandardSound, SilencedSound };
			class StandardSound
			{
				soundSetShot[] = { "RHSUSF_m590_Shot_SoundSet","RHSUSF_MMG1_Tail_SoundSet" };
			};
			class SilencedSound
			{
				soundSetShot[] = { "DMR04_Shot_SoundSet","DMR04_tail_SoundSet","DMR04_InteriorTail_SoundSet" };
			};
		};
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 5;
			allowedSlots[] = {901,701};
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = { "rhsusf_acc_m24_silencer_black" }; 				/// A custom made suppressor for this weapon
			};
		};
	};
	class rhs_weap_M590_8RD : rhs_weap_M590_5RD
	{
		ACE_twistDirection = 0;
		ACE_barrelLength = 510;
		rhs_boltActionSound[] = { "rhsusf\addons\rhsusf_c_weapons\sounds\m590_pump.ogg", 0.12, 1, 20 };
		class Single : Mode_SemiAuto
		{
			sounds[] = { StandardSound, SilencedSound };
			class StandardSound
			{
				soundSetShot[] = { "RHSUSF_m590_Shot_SoundSet","RHSUSF_MMG1_Tail_SoundSet" };
			};
			class SilencedSound
			{
				soundSetShot[] = { "DMR04_Shot_SoundSet","DMR04_tail_SoundSet","DMR04_InteriorTail_SoundSet" };
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 75;
			allowedSlots[] = {901};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[] = {"rhsusf_acc_m24_silencer_black"}; 				/// A custom made suppressor for this weapon
			};
		};
	};
};