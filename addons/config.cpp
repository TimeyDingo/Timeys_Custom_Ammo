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
		weapons[] = {"T_Vector_9mm"};
		requiredAddons[] =
		{
			"A3_Data_F_AoW_Loadorder",
			"cba_main",
			"rhsusf_weapons",
			"ACE_Common",
			"ace_csw",
			"rhsusf_main_loadorder",
			"rhsusf_sounds",
			"rhsusf_c_weaponsounds",
			"ace_explosives"
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
		mineTriggerMass = 120;
		mineTriggerRange = 0; // 1
		mineWireStart[] = { 0,0,0 };
		mineWireEnd[] = { 0,1,0 };
	};
	class Flash_Trigger : RangeTriggerBounding
	{
		mineTriggerRange = 1.5;
		mineTriggerMass = 1;
		restrictZoneCenter[] = { 0,0,0 };
		restrictZoneRadius = 5;
		mineDelay = 0.01;
	};
};
class CfgAmmo //velocity[m/s] * caliber * penetrability / 1000
{
	class B_12Gauge_Slug;
	class BulletBase;
	class G_40mm_HE;
	class rhs_ammo_12g_00buckshot;
	class rhs_ammo_12g_00buckshot_pellet;
	class APERSBoundingMine_Range_Ammo;
	class ShotDeployBase;
	class T_Copper_HP_Slug: B_12Gauge_Slug// High damage extremely low penetration slug
	{
		hit = 20;
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
	class T_Tungsten_AP_Slug: B_12Gauge_Slug// Armor piercing slug.....600*5.95=3570 3570/370
	{
		hit = 15;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 2.95;
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
		hit = 20;
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
	class T_Flechette : rhs_ammo_12g_00buckshot
	{
		hit = 20; // for AI
		simulation = shotSubmunitions;
		simulationStep = 0.0001;
		triggerTime = 0.0001;
		triggerSpeedCoef[] = { 0.95,1.1 };
		submunitionAmmo = "T_Flechette_Sub";
		submunitionConeType[] = { "poissondisc", 30 };
		submunitionConeAngle = 1.1;
		submunitionConeAngleHorizontal = 1.1;
		cartridge = "";
		model = "\A3\weapons_f\empty";
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_buckshot";
	};
	class T_Flechette_Sub : rhs_ammo_12g_00buckshot_pellet
	{
		hit = 2.5;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 2.75;
		typicalSpeed = 250;
		airFriction = -0.0006;
		ACE_Caliber = 2;
		ACE_bulletLength = 25.4;
		ACE_bulletMass = 5;
		ACE_muzzleVelocityVariationSD = 0.01;
		ACE_dragModel = 7;
		ACE_ballisticCoefficients[] = { 0.083 };
		ACE_standardAtmosphere = "ASM";
		warheadName = AP_Level_3;
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
		indirectHitRange = 0.35;
		directionalExplosion = 1;
		explosionAngle = 8;
		model = "\A3\Weapons_f\Explosives\mine_at";
		mineTrigger = "T_TriggerMag";
		triggerWhenDestroyed = 1;
	};
	class ACE_G_M84;
	class rhs_ammo_m84;
	class T_40mm_FLASH : rhs_ammo_m84
	{
		ace_grenades_flashbang = 1;
		ace_grenades_flashbangBangs = 1;
		fuseDistance = 2.5;
		dangerRadiusHit = -1;
		suppressionRadiusHit = 20;
		typicalSpeed = 22;
		explosive = "1E-7";
		deflecting = 15;
		timeToLive = 20;
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
		aiAmmoUsageFlags = "64";
		smokeColor[] = { 0,0,0,0 };
		effectsSmoke = "ACE_M84FlashbangEffect";
		whistleDist = 0;
		triggerDistance = 0;
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\m84\m84_flash";
		hit = 0.1;
		indirectHit = 0.1;
		indirectHitRange = 8;
		ExplosionEffects = "RHSUSF_flashbang_15";
		craterEffects = "RHSUSF_flashbang_Crater";
		explosionTime = 1.5;
		cost = 10;
	};
	class T_40mm_FLASHMINE : T_40mm_TirePopperDeployer
	{
		typicalspeed = 70;
		fuseDistance = 0;
		submunitionAmmo = "T_40mm_FLASHSUB";
		triggerDistance = 0;
	};
	class T_40mm_FLASHSUB : T_TirePopper
	{
		model = "\A3\Weapons_f\Explosives\mine_AP_bouncing";
		mineTrigger = "Flash_Trigger";
		triggerWhenDestroyed = 1;
		ace_grenades_flashbang = 1;
		ace_grenades_flashbangBangs = 1;
		dangerRadiusHit = -1;
		suppressionRadiusHit = 20;
		typicalSpeed = 22;
		explosive = "1E-7";
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
		aiAmmoUsageFlags = "64";
		smokeColor[] = { 0,0,0,0 };
		effectsSmoke = "ACE_M84FlashbangEffect";
		whistleDist = 0;
		hit = 0.1;
		indirectHit = 0.1;
		indirectHitRange = 8;
		ExplosionEffects = "RHSUSF_flashbang_15";
		craterEffects = "RHSUSF_flashbang_Crater";
		cost = 10;
	};
	class rhsusf_ammo_127x99_mk211;
	class T_SLAP : rhsusf_ammo_127x99_mk211
	{
		hit = 150;
		caliber = 10;
	};
	class T_MV_40mm_TRAINING : T_MV_40mm_HET
	{
		submunitionAmmo = "T_TRAINING_sub";
	};
	class TrainingMine_Ammo;
	class T_TRAINING_sub : TrainingMine_Ammo
	{
		mineTrigger = "T_Trigger";
	};
	class ClaymoreDirectionalMine_Remote_Ammo;
	class SLAMDirectionalMine_Wire_Ammo;
	class T_PLACE_TP : SLAMDirectionalMine_Wire_Ammo
	{
		ace_explosives_magazine = "ClaymoreDirectionalMine_Remote_Mag";
		ace_explosives_Explosive = "ClaymoreDirectionalMine_Remote_Ammo_Scripted";
		ace_explosives_size = 0;
		ace_explosives_defuseObjectPosition[] = { 0,0,0.038 };
		soundActivation[] = { "",0,0,0 };
		soundDeactivation[] = { "",0,0,0 };
		hit = 100;
		indirectHit = 125;
		indirectHitRange = 0.1;
		directionalExplosion = 1;
		explosionAngle = 12;
		triggerWhenDestroyed = 1;
		caliber = 2.95;
	};
	class T_PLACE_TP_COMMAND : ClaymoreDirectionalMine_Remote_Ammo{};
	class rhs_ammo_46x30_FMJ;
	class T_9MM_FMJ : rhs_ammo_46x30_FMJ
	{
		typicalSpeed = 320; // 381 m/s
	};
	class rhs_ammo_46x30_JHP;
	class T_9MM_HP : rhs_ammo_46x30_JHP
	{
		typicalSpeed = 320; // 350 m/s
	};
	class rhs_ammo_46x30_AP;
	class T_9MM_AP : rhs_ammo_46x30_AP
	{
		typicalSpeed = 520; // 560 m/s
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
		descriptionshort = "HP Slugs to cause maximum damage to unarmored targets";
		mass = 2;
		picture = "\addons\UI\copper_slug.paa";
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
		descriptionshort = "Tungsten penetrator sabot to penetrate deep into body armor and through cover";
		mass = 2;
		picture = "\addons\UI\AP_slug.paa";
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
		descriptionshort = "Subsonic HP Slugs to cause maximum damage to unarmored targets";
		mass = 2;
		picture = "\addons\UI\subsonic_slug.paa";
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
		descriptionshort = "HP Slugs to cause maximum damage to unarmored targets";
		mass = 5;
		picture = "\addons\UI\copper_slug.paa";
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
		descriptionshort = "Tungsten penetrator sabot to penetrate deep into body armor and through cover";
		mass = 5;
		picture = "\addons\UI\AP_slug.paa";
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
		descriptionshort = "Subsonic HP Slugs to cause maximum damage to unarmored targets";
		mass = 5;
		picture = "\addons\UI\subsonic_slug.paa";
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
		descriptionshort = "HP Slugs to cause maximum damage to unarmored targets";
		mass = 8;
		picture = "\addons\UI\copper_slug.paa";
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
		descriptionshort = "Tungsten penetrator sabot to penetrate deep into body armor and through cover";
		mass = 8;
		picture = "\addons\UI\AP_slug.paa";
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
		descriptionshort = "Subsonic HP Slugs to cause maximum damage to unarmored targets";
		mass = 8;
		picture = "\addons\UI\subsonic_slug.paa";
	};
	class timey_2rnd_Flechette : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Flechette";
		count = 2;
		initspeed = 370;
		displayName = "2rnd 30 Count Flechette";
		displayNameShort = "30C Flec";
		descriptionshort = "30 small flechettes to cause damage on low level armor of targets";
		mass = 2;
		picture = "\addons\UI\Flechette.paa";
	}
	class timey_5rnd_Flechette : 2Rnd_12Gauge_Slug
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Flechette";
		count = 5;
		initspeed = 370;
		displayName = "5rnd 30 Count Flechette";
		displayNameShort = "30C Flec";
		descriptionshort = "30 small flechettes to cause damage on low level armor of targets";
		mass = 5;
		picture = "\addons\UI\Flechette.paa";
	}
	class timey_8rnd_Flechette : 2Rnd_12Gauge_Slug
	{ 
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_Flechette";
		count = 8;
		initspeed = 370;
		displayName = "8rnd 30 Count Flechette";
		displayNameShort = "30C Flec";
		descriptionshort = "30 small flechettes to cause damage on low level armor of targets";
		mass = 8;
		picture = "\addons\UI\Flechette.paa";
	}
	class 1Rnd_HE_Grenade_shell;
	class timey_6rnd_40mm_HE : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HE";
		initspeed = 100;
		displayName = "6rnd MV 40mm HE";
		displaynameshort = "6xHE/MV";
		descriptionshort = "Medium velocity HE explosive round with a range out to 800M";
		count = 6;
		mass = 30;
		picture = "\addons\UI\HE.paa";
	};
	class timey_6rnd_40mm_HEDP : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HEDP";
		initspeed = 100;
		displayName = "6rnd MV 40mm HEDP";
		displaynameshort = "6xHEDP/MV";
		descriptionshort = "Medium velocity HEDP explosive round with a range out to 800M";
		count = 6;
		mass = 30;
		picture = "\addons\UI\HEDP.paa";
	};
	class timey_6rnd_40mm_HET : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_HET"
		initspeed = 100;
		displayName = "6rnd MV 40mm HET";
		displaynameshort = "6xHET/MV";
		descriptionshort = "Medium velocity HET explosive round with a range out to 800M";
		count = 6;
		mass = 30;
		picture = "\addons\UI\HET.paa";
	};
	class timey_6rnd_40mm_TirePopper : 1Rnd_HE_Grenade_shell
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_40mm_TirePopperDeployer"
		initspeed = 80;
		displayName = "6rnd 40mm T/P";
		displaynameshort = "6xT/P";
		descriptionshort = "Deploys a wheel popping explosive deep into the dirt";
		count = 6;
		mass = 10;
		picture = "\addons\UI\Utility_round.paa";
	};
	class timey_1rnd_40mm_FLASH : 1Rnd_HE_Grenade_shell
	{
		initspeed = 80;
		count = 1;
		ammo = "T_40mm_FLASH"
		displayName = "40mm flashbang";
		displaynameshort = "FLASH";
		descriptionshort = "Shoots a flashbang";
		picture = "\addons\UI\FLASH.paa";
	};
	class timey_6rnd_40mm_FLASH : 1Rnd_HE_Grenade_shell
	{
		initspeed = 80;
		count = 6;
		ammo = "T_40mm_FLASH"
		displayName = "6rnd 40mm flashbang";
		displaynameshort = "6xFLASH";
		descriptionshort = "Shoots a flashbang";
		mass = 30;
		picture = "\addons\UI\FLASH.paa";
	};
	class timey_1rnd_40mm_FLASHMINE : timey_1rnd_40mm_FLASH
	{
		initspeed = 80;
		count = 1;
		ammo = "T_40mm_FLASHMINE"
		displayName = "40mm flashbang mine";
		displaynameshort = "FLASHMINE";
		descriptionshort = "Deploys a flashbang mine deep into the dirt, has an extended IR sensor to detect targets at up to 2M";
		picture = "\addons\UI\Utility_round";
	};
	class timey_6rnd_40mm_FLASHMINE : timey_1rnd_40mm_FLASH
	{
		initspeed = 80;
		count = 6;
		ammo = "T_40mm_FLASHMINE"
		displayName = "6rnd 40mm flashbang mine";
		displaynameshort = "6xFLASHMINE";
		descriptionshort = "Deploys a flashbang mine deep into the dirt, has an extended IR sensor to detect targets at up to 2M";
		picture = "\addons\UI\Utility_round";
	};
	class rhsusf_mag_10Rnd_STD_50BMG_mk211;
	class timey_10rnd_SLAP : rhsusf_mag_10Rnd_STD_50BMG_mk211 //hit = 60 for the default arma round
	{
		ammo = "T_SLAP";
		displayName = "10rnd M107 SLAP";
		displaynameshort = "SLAP";
		descriptionshort = "Semi-explosive highly penetrating round to disable engines, or obliterate single infantry";
		picture = "\addons\UI\SLAP.paa";
	};
	class timey_6rnd_40mm_TRAINING : timey_6rnd_40mm_HET
	{
		scope = 2;
		scopeArsenal = 2;
		ammo = "T_MV_40mm_TRAINING"
		initspeed = 100;
		displayName = "6rnd MV 40mm TRAINING";
		displaynameshort = "6xTRAINING";
		descriptionshort = "Medium velocity training round";
		count = 6;
		mass = 30;
		picture = "\addons\UI\Utility_round";
	};
	class ClaymoreDirectionalMine_Remote_Mag;
	class timey_PLACE_TP_MAG: ClaymoreDirectionalMine_Remote_Mag
	{
		displayName = "Tire popping explosive";
		displaynameshort = "TP explosive";
		ammo = "T_PLACE_TP"
		descriptionshort = "Tire popping modification of the claymore";
		ace_explosives_DelayTime = 0;
		picture = "\addons\UI\SLAM.paa";
		class ACE_Triggers
		{
			SupportedTriggers[] = { "Command","MK16_Transmitter","IRSensor"};
			class Command
			{
				FuseTime = 0;
				ammo = "T_PLACE_TP_COMMAND";
				displayName = "CLAYMORE mode/Command";
			};
			class MK16_Transmitter : Command {};
			class IRSensor
			{
				displayName = "WP mode/IRSENSOR";
			};
		};
	};
	class 30Rnd_45ACP_Mag_SMG_01;
	class timey_33rnd_9mm_FMJ : 30Rnd_45ACP_Mag_SMG_01
	{
		scope = 2;
		displayName = "33rnd 9MM FMJ";
		displaynameshort = "33C 9FMJ";
		descriptionshort = "Low tier armor penetrating/good damage on unarmored targets";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
		ammo = "T_9MM_FMJ";
		count = 33;
		mass = 10;
		initSpeed = 381;
		tracersEvery = 0;
	};
	class timey_50rnd_9mm_FMJ : timey_33rnd_9mm_FMJ
	{
		count = 50;
		mass = 15;
		displayName = "50rnd 9MM FMJ";
		displaynameshort = "50C 9FMJ";
		descriptionshort = "Low tier armor penetrating/good damage on unarmored targets";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
	};
	class timey_33rnd_9mm_HP : timey_33rnd_9mm_FMJ
	{
		scope = 2;
		displayName = "33rnd 9MM HP";
		displaynameshort = "33C 9HP";
		descriptionshort = "Extreme damage on unarmored targets";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
		ammo = "T_9MM_HP";
		count = 33;
		mass = 10;
		initSpeed = 320;
		tracersEvery = 0;
	};
	class timey_50rnd_9mm_HP : timey_33rnd_9mm_HP
	{
		count = 50;
		mass = 15;
		displayName = "50rnd 9MM HP";
		displaynameshort = "50C 9HP";
		descriptionshort = "Extreme damage on unarmored targets";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
	};
	class timey_33rnd_9mm_AP : timey_33rnd_9mm_FMJ
	{
		scope = 2;
		displayName = "33rnd 9MM AP";
		displaynameshort = "33C 9AP";
		descriptionshort = "Extreme penetrating round";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
		ammo = "T_9MM_FMJ";
		count = 33;
		mass = 10;
		initSpeed = 560;
		tracersEvery = 0;
	};
	class timey_50rnd_9mm_AP : timey_33rnd_9mm_AP
	{
		count = 50;
		mass = 15;
		displayName = "50rnd 9MM AP";
		displaynameshort = "50C 9AP";
		descriptionshort = "Extreme penetrating round";
		picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
	};
};
class CfgMagazineWells
{
	class CBA_12g_2rnds
	{
	TimeyCustom[] += {"timey_2rnd_Copper_HP_Slug", "timey_2rnd_Tungsten_AP_Slug", "timey_2rnd_Copper_Hush_HP_Slug", "timey_2rnd_Flechette"};
	};
	class CBA_12g_5rnds
	{
	TimeyCustom[] += {"timey_5rnd_Copper_HP_Slug", "timey_5rnd_Tungsten_AP_Slug", "timey_5rnd_Copper_Hush_HP_Slug", "timey_5rnd_Flechette"};
	};
	class CBA_12g_8rnds
	{
	TimeyCustom[] += {"timey_8rnd_Copper_HP_Slug", "timey_8rnd_Tungsten_AP_Slug", "timey_8rnd_Copper_Hush_HP_Slug", "timey_8rnd_Flechette"};
	};
	class HunterShotgun_01_12GA
	{
	TimeyCustom[] += {"timey_2rnd_Copper_HP_Slug", "timey_2rnd_Tungsten_AP_Slug", "timey_2rnd_Copper_Hush_HP_Slug", "timey_2rnd_Flechette"};
	};
	class CBA_40mm_M203_6rnds
	{
	TimeyCustom[] += {"timey_6rnd_40mm_HE", "timey_6rnd_40mm_HEDP", "timey_6rnd_40mm_HET", "timey_6rnd_40mm_TirePopper", "timey_6rnd_40mm_FLASH", "timey_6rnd_40mm_FLASHMINE", "timey_6rnd_40mm_TRAINING"};
	};
	class CBA_40mm_M203
	{
	TimeyCustom[] += {"timey_1rnd_40mm_FLASH", "timey_1rnd_40mm_FLASHMINE"};
	};
	class UGL_40x36
	{
	TimeyCustom[] += {"timey_1rnd_40mm_FLASH", "timey_1rnd_40mm_FLASHMINE"};
	};
	class CBA_50BMG_M107			// M82, M107, G82
	{
	TimeyCustom[] += {"timey_10rnd_SLAP"};
	};
	class T_9MM_SMG
	{
		TimeyCustom[] += {"timey_33rnd_9mm_FMJ", "timey_33rnd_9mm_HP", "timey_33rnd_9mm_AP", "timey_50rnd_9mm_FMJ", "timey_50rnd_9mm_HP", "timey_50rnd_9mm_AP"};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
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
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 5;
			allowedSlots[] = { 901,701 };
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
		//doesn't work too zoomed in for some reason modelOptics = "rhsusf\addons\rhsusf_weapons3\acc\scopes\RX01\rhs_reflexsight.p3d";
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
		class WeaponSlotsInfo : WeaponSlotsInfo
		{
			mass = 75;
			allowedSlots[] = { 901 };
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = { "rhsusf_acc_m24_silencer_black" }; 				/// A custom made suppressor for this weapon
			};
		};
	};
	class rhs_weap_m32_Base_F : Rifle_Base_F
	{
		magazineWell[] = { CBA_40mm_M203_6rnds, UGL_40x36, CBA_40mm_M203, CBA_40mm_EGLM };
	};
	class Default;
	class Put : Default
	{
		muzzles[] += {"ace_explosives_muzzle"};
		class PutMuzzle : Default {};
		class ace_explosives_muzzle : PutMuzzle
		{
			magazines[] = { "timey_PLACE_TP_MAG" };
		};
	};
	class rhs_weap_m4a1_carryhandle;
	class rhs_weap_m4a1_carryhandle_mstock : rhs_weap_m4a1_carryhandle
	{
		picture = "\addons\UI\copper_slug.paa";
		displayName = "SPAS 15";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_carryhandle_mstock.p3d";
		handAnim[] = { "OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm" };
		rhs_grip1_change = "rhs_weap_m4a1_carryhandle_mstock_grip";
		rhs_grip2_change = "rhs_weap_m4a1_carryhandle_mstock_grip2";
		rhs_grip3_change = "rhs_weap_m4a1_carryhandle_mstock_grip3";
		baseWeapon = "rhs_weap_m4a1_carryhandle_mstock";
		magazines[] = {""};
		magazineWell[] = { "CBA_12g_1rnd","CBA_12g_2rnds","CBA_12g_3rnds","CBA_12g_4rnds","CBA_12g_5rnds", "CBA_12g_8rnds" };
		modes[] = { "Single" };
		recoil = "rhs_recoil_m590";
		reloadSound[] = { "A3\sounds_f\weapons\M320\M320_reload",0.1,1,30 };
		reloadAction = "GestureReloadDMR04"
		scope = 2;
		scopeArsenal = 2;
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
		class WeaponSlotsInfo
		{
			mass = 75;
			allowedSlots[] = { 901 };
			class MuzzleSlot : MuzzleSlot
			{
				compatibleItems[] = { "rhsusf_acc_m24_silencer_black" }; 				/// A custom made suppressor for this weapon
			};
		};
	};
	class SMG_01_Base;
	class SMG_01_F;
	class T_Vector_9mm : SMG_01_F
	{
		scope = 2;
		modes[] = { "Single","FullAuto" };
		displayName = "Vector 9mm";
		magazines[] = { "30Rnd_9x21_Mag","30Rnd_9x21_Red_Mag","30Rnd_9x21_Yellow_Mag","30Rnd_9x21_Green_Mag" };
		magazineWell[] = {"T_9MM_SMG"};
		scopeArsenal = 2;
		baseWeapon = "T_Vector_9mm";
		model = "\A3\Weapons_F_beta\Smgs\SMG_01\SMG_01_F.p3d";
		inertia = 0.3;
		aimTransitionSpeed = 1.4;
		dexterity = 1.7;
		picture = "\A3\Weapons_F_beta\Smgs\SMG_01\data\UI\gear_SMG_01_X_CA.paa";
		UiPicture = "\A3\Weapons_F\data\UI\icon_regular_CA.paa";
		descriptionShort = "$STR_A3_CfgWeapons_SMG_011";
		access = 2;
		initSpeed = -1;
	};
};
class ACE_M84FlashbangEffect {};