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
		weapons[] = {"T_Vector_9mm", "T_NGSW"};
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
			"ace_explosives",
			"VSM_Vests_Config",
			"VSM_Helmets",
			"rhsusf_c_melb",
			"RHS_US_A2_AirImport",
			//"USAF_MQ9",
			"ace_advanced_fatigue",
			"Extended_EventHandlers",
			"rhs_c_weapons",
			"RHSGREF_c_A29",
		};
	};
};
//class Extended_PreStart_EventHandlers
//{
//	class ace_advanced_fatigue
//	{
//		init = "";
//	};
//};
//class Extended_PreInit_EventHandlers
//{
//	RS_Init = "RS_Init_Var = [] execVM ""addons\disablestamina.sqf""";
//	class ace_advanced_fatigue
//	{
//		init = "";
//	};
//};
//class Extended_PostInit_EventHandlers
//{
//	class ace_advanced_fatigue
//	{
//		init = "";
//	};
//};
//class Extended_DisplayLoad_EventHandlers
//{
//	class RscDisplayMission
//	{
//		ace_advanced_fatigue = "";
//	};
//};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot : DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot : DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class asdg_OpticRail;
class asdg_OpticRail1913: asdg_OpticRail
{
	class compatibleItems
	{
		T_XM157 = 1;
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
	class MissileBase;
	class BulletBase;
	class rhs_ammo_LWIRCM : BulletBase
	{
		cost = 1;
		visibleFire = 0;
		audibleFire = 0;
		hit = 1;
		indirectHit = 0;
		indirectHitRange = 0;
		timeToLive = 10;
		thrustTime = 6;
		airFriction = -0.01;
		simulation = "shotCM";
		weaponLockSystem = "1 + 2 + 4 + 8 + 16";
		model = "\A3\weapons_f\empty";
		effectsSmoke = "EmptyEffect";
		maxControlRange = -1;
		initTime = 0;
		aiAmmoUsageFlags = 8;
		soundFly[] = { "A3\sounds_f\dummysound",0.01,0.1 };
		supersonicCrackNear[] = { "A3\sounds_f\dummysound",0,0.1,0 };
		supersonicCrackFar[] = { "A3\sounds_f\dummysound",0,0.1,0 };
	};
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
		minRange = 0.24;
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
		ACE_ammoTempMuzzleVelocityShifts[] = {-27.20, -26.44, -23.76, -21.00, -17.54, -13.10, -7.95, -1.62, 6.24, 15.48, 27.75};//Array of muzzle velocity shifts in m / s with 11 data points from - 15 �C to 35 �C
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
		minRange = 0.24;
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
		ACE_ammoTempMuzzleVelocityShifts[] = {-17.20, -19.44, -13.76, -11.00, -07.54, -03.10, -0.95, 1.62, 6.24, 15.48, 27.75};
		submunitionAmmo = "T_Copper_Hush_HP_Slug";
		submunitionDirectionType = "SubmunitionTargetDirection";
		deleteParentWhenTriggered = 0;
		submunitionInitSpeed = 249;
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
		caliber = 0.26;
		cartridge = "";
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_slug";
		typicalSpeed = 150;
		airFriction = -0.000136;
		minRange = 0.26;
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
		typicalSpeed = 249;
		airFriction = -0.0006;
		ACE_Caliber = 2;
		ACE_bulletLength = 24.4;
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
		aiAmmoUsageFlags = "64 + 128";
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
		hit = 125;
		caliber = 8;
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
		indirectHit = 124;
		indirectHitRange = 0.1;
		directionalExplosion = 1;
		explosionAngle = 12;
		triggerWhenDestroyed = 1;
		caliber = 2.95;
	};
	class T_PLACE_TP_COMMAND : ClaymoreDirectionalMine_Remote_Ammo{};
	class rhs_ammo_46x30_FMJ;
	class rhs_ammo_762x51_M80_Ball;
	class rhs_ammo_762x51_M61_AP;
	class T_68_AP : rhs_ammo_762x51_M61_AP
	{
		typicalSpeed = 950;
	};
	class T_68_HP : rhs_ammo_762x51_M80_Ball
	{
		typicalSpeed = 800;
	};
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
	class T_357_FMJ : rhs_ammo_46x30_AP
	{
		typicalSpeed = 460; // 480m/s
		hit = 15;
	};
	class rhs_ammo_9k38;
	class M_Titan_AA : MissileBase
	{
		class Components;
	};
	class T_Zeus: rhs_ammo_762x51_M61_AP
	{
		hit = 155;
		caliber = 100;
		rhs_cartridge = "\rhsusf\addons\rhsusf_weapons\casings\rhs_casing_12ga_slug";
		typicalSpeed = 5000;
		maxSpeed = 5000;
		ACE_ballisticCoefficients[]={0.361};
		ACE_muzzleVelocities[] = {5000};
		ACE_bulletMass=100;
		ACE_dragModel=7;
		ACE_bulletLength = 100;
	};
	class Tim_HARM : rhs_ammo_9k38
	{
		cmimmunity = 1;
		maxspeed = 800;
		maneuvrability = 34;
		trackoversteer = 0.98;
		sideairfriction = 0.072;
		trackLead = 0.65;

		//Missile sensors definition
		missileLockMaxDistance = 4800;
		missileLockMinDistance = 200;
		missileLockMaxSpeed = 333;
		missileLockCone = 30;
		missileKeepLockedCone = 70; //Need to play with it for a while

		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent : SensorTemplateIR
					{
						typeRecognitionDistance = -1; // distance how far the target type gets recognized
						angleRangeHorizontal = 45;     // sensor azimuth coverage in degrees
						angleRangeVertical = 45;       // sensor elevation coverage in degrees
						groundNoiseDistanceCoef = 0.02;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = 20;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = 0;        // target speed in km/h above which the target will start to become visible
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold
						maxFogSeeThrough = 0.95;
						minTrackableSpeed = 0;
						maxTrackableSpeed = 333;
						minTrackableATL = 20;
						maxTrackableATL = 4500;
					};
				};
			};
		};
	};
};
class CfgMagazines
{
	class 2Rnd_12Gauge_Slug;
	class rhs_mag_20Rnd_SCAR_762x51_m80_ball;
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
		displayName = "5rnd M107 SLAP";
		displaynameshort = "SLAP";
		count = 5;
		mass = 30;
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
		ammo = "T_9MM_AP";
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
	class 6Rnd_45ACP_Cylinder;
	class timey_6rnd_357_FMJ : 6Rnd_45ACP_Cylinder
	{
		ammo = "T_357_FMJ";
		displayName = "6rnd .357 FMJ";
		displaynameshort = "6C FMJ";
		descriptionshort = "FMJ for the .357 magnum";
		initSpeed = 480;
	};
	class CA_Magazine;
	class rhsusf_mag_LWIRCM : CA_Magazine
	{
		count = 4000;
		ammo = "rhs_ammo_LWIRCM";
		initSpeed = 30;
		weight = 0;
	};
	class rhs_mag_9k38_rocket;
	class Tim_HARM_Mag : rhs_mag_9k38_rocket
	{
		ammo = "Tim_HARM";
		displayname = "HARM";
		descriptionshort = "Anti-jam missile";
		picture = "\rhsafrf\addons\rhs_weapons\icons\m_igla_ca.paa";
	};
	class HandGrenade;
	class rhs_mag_m18_yellow;
	class rhssaf_mag_brd_m83_yellow:rhs_mag_m18_yellow
	{
		displayNameShort = "Yellow Smoke";
		descriptionshort = "Type: Smoke Grenade - Yellow<br />Rounds: 1<br />Used in: Hand";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_yellow_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m18\m18_smoke_yellow";
		scope = 2;
	};
	class rhssaf_mag_brd_m83_red:rhs_mag_m18_yellow
	{
		displayNameShort = "Yellow Smoke2";
		descriptionshort = "Type: Smoke Grenade - Yellow<br />Rounds: 1<br />Used in: Hand";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_yellow_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m18\m18_smoke_yellow";
		scope = 2;
	};
	class rhssaf_mag_brd_m83_white:rhs_mag_m18_yellow
	{
		displayNameShort = "Yellow Smoke3";
		descriptionshort = "Type: Smoke Grenade - Yellow<br />Rounds: 1<br />Used in: Hand";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_yellow_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m18\m18_smoke_yellow";
		scope = 2;
	};
	class rhssaf_mag_br_m84:rhs_mag_m18_yellow
	{
		displayNameShort = "Yellow Smoke4";
		descriptionshort = "Type: Smoke Grenade - Yellow<br />Rounds: 1<br />Used in: Hand";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_yellow_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m18\m18_smoke_yellow";
		scope = 2;
	};
	class timey_20rnd_68mm_AP : rhs_mag_20Rnd_SCAR_762x51_m80_ball
	{
		displayName = "20rnd 6.8 AP";
		displaynameshort = "20C AP";
		descriptionshort = "AP High Presssure for the XM7";
		count = 20;
		ammo = "T_68_AP";
		mass = 16.24;
		initSpeed = 950;
		scope = 2;
		scopeArsenal = 2;
		access = 2;
		modelSpecial = "a3\Weapons_F\MagazineProxies\mag_65x39c_mx_30rnd.p3d";
	};
	class timey_20rnd_68mm_HP : rhs_mag_20Rnd_SCAR_762x51_m80_ball
	{
		displayName = "20rnd 6.8 HP";
		displaynameshort = "20C HP";
		descriptionshort = "HP Low Pressure Ammo for the XM7";
		count = 20;
		ammo = "T_68_HP";
		mass = 16.24;
		initSpeed = 800;
		scope = 2;
		scopeArsenal = 2;
		access = 2;
		modelSpecial = "a3\Weapons_F\MagazineProxies\mag_65x39c_mx_30rnd.p3d";
	};
	class timey_20rnd_68mm_ZEUS : rhs_mag_20Rnd_SCAR_762x51_m80_ball
	{
		displayName = "ZEUS 5C";
		displaynameshort = "ZEUS 5C";
		descriptionshort = "HP Low Pressure Ammo for the XM7";
		count = 5;
		ammo = "T_Zeus";
		mass = 16.24;
		initSpeed = 5000;
		scope = 2;
		scopeArsenal = 2;
		access = 2;
		modelSpecial = "a3\Weapons_F\MagazineProxies\mag_65x39c_mx_30rnd.p3d";
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
	class T_357
	{
		TimeyCustom[] += {"timey_6rnd_357_FMJ"};
	};
	class T_68MM
	{
		TimeyCustom[] += {"timey_20rnd_68mm_HP", "timey_20rnd_68mm_AP", "timey_20rnd_68mm_ZEUS"};
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
	class MGun;
	class rhsusf_weap_LWIRCM : MGun
	{
		magazineReloadTime = 1;
		modes[] = { "Burst1","Burst2" };
		reloadMagazineSound[] = { "A3\sounds_f\dummysound",2,1,5 };
		class Burst1 : Mode_Burst
		{
			displayName = "Missile Jammer";
			reloadTime = 0.1;
			burst = 5000;
			maxRange = 1500;
		};
	};
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
		initSpeed = -1;
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
		initSpeed = -1;
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
	class rhs_weap_m4a1_carryhandle_mstock;
	class T_Spas15 : rhs_weap_m4a1_carryhandle_mstock
	{
		displayName = "SPAS 15";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_carryhandle_mstock.p3d";
		handAnim[] = { "OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm" };
		rhs_grip1_change = "rhs_weap_m4a1_carryhandle_mstock_grip";
		rhs_grip2_change = "rhs_weap_m4a1_carryhandle_mstock_grip2";
		rhs_grip3_change = "rhs_weap_m4a1_carryhandle_mstock_grip3";
		baseWeapon = "T_Spas15";
		magazines[] = {""};
		magazineWell[] = { "CBA_12g_1rnd","CBA_12g_2rnds","CBA_12g_3rnds","CBA_12g_4rnds","CBA_12g_5rnds", "CBA_12g_8rnds" };
		modes[] = { "Single" };
		recoil = "rhs_recoil_m590";
		reloadSound[] = { "A3\sounds_f\weapons\M320\M320_reload",0.1,1,30 };
		reloadAction = "GestureReloadDMR04"
		scope = 2;
		scopeArsenal = 2;
		initSpeed = -1;
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
	class arifle_MX_F;
	class CowsSlot_Rail;
	class T_NGSW : arifle_MX_F
	{
		displayName = "XM7";
		magazines[] = {""};
		magazineWell[] = {"T_68MM"};
		modes[] = { "Single","FullAuto" };
		recoil = "recoil_dmr_03";
		descriptionShort = "$STR_A3_CfgWeapons_SMG_011";
		scope = 2;
		scopeArsenal = 2;
		access = 2;
		baseWeapon = "T_NGSW";
		model = "\A3\Weapons_F\Rifles\MX\MX_F.p3d";
		picture = "\A3\weapons_F\Rifles\MX\data\UI\gear_mx_rifle_X_CA.paa";
		UiPicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";
		handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\MX_afg.rtm"};
		inertia = 0.5;
		aimTransitionSpeed = 1;
		dexterity = 1.5;
	};
	class arifle_MX_GL_F;
	class UGL_F;
	class T_NGSW_GL : arifle_MX_GL_F
	{
		displayName = "XM7 M320";
		magazines[] = {""};
		magazineWell[] = {"T_68MM"};
		modes[] = { "Single","FullAuto" };
		recoil = "recoil_dmr_03";
		descriptionShort = "$STR_A3_CfgWeapons_SMG_011";
		scope = 2;
		scopeArsenal = 2;
		access = 2;
		baseWeapon = "T_NGSW_GL";
		inertia = 0.5;
		aimTransitionSpeed = 1;
		dexterity = 1.5;
		model = "\A3\Weapons_F\Rifles\MX\MX_GL_F.p3d";
		picture = "\A3\weapons_F\Rifles\MX\data\UI\gear_mx_rifle_gl_X_CA.paa";
		UiPicture = "\A3\Weapons_F\Data\UI\icon_gl_CA.paa";
		weaponInfoType = "RscWeaponZeroing";
		handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\MX_gl.rtm"};
		muzzles[] = {"this","GL_3GL_F"};
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
	class hgun_Pistol_heavy_02_F;
	class T_Rhino_357 : hgun_Pistol_heavy_02_F
	{
		scope = 2;
		displayName = "Rhino .357 magnum";
		descriptionShort = "";
		magazines[] = { "" };
		magazineWell[] = { "T_357" };
		scopeArsenal = 2;
		baseWeapon = "T_Rhino_357";
		access = 2;
		initSpeed = -1;
		recoil = "recoil_gm6";
	};
	class T_Judge_12g : hgun_Pistol_heavy_02_F
	{
		scope = 2;
		displayName = "Taurus Judge 12G";
		descriptionShort = "";
		magazines[] = { "" };
		magazineWell[] = { "CBA_12g_5rnds" };
		scopeArsenal = 2;
		baseWeapon = "T_Judge_12g";
		access = 2;
		initSpeed = -1;
		recoil = "recoil_gm6";
	};
	class rhs_weap_strela;
	class rhs_weap_igla : rhs_weap_strela
	{
		magazines[] = { "rhs_mag_9k38_rocket","Tim_HARM_Mag"};
	};
	// VSM VSM VSM VSM I HATE YOU VSM VSM VSM
	class ItemCore;
	class UniformItem;
	class VestItem;
	class InventoryOpticsItem_Base_F;
	class optic_Nightstalker;
	class T_XM157: optic_Nightstalker //todo Can't mount on any rails for some reason?
	{
		displayName = "XM157";
		descriptionShort = "NGSW FCS";
		model = "\A3\weapons_f\acc\acco_Nightstalker_F.p3d";
		picture = "\a3\Weapons_F\acc\Data\UI\icon_optic_Nightstalker_ca.paa";
		scope = 2;
        class CBA_ScriptedOptic 
		{
            bodyTexture = "\z\ace\addons\xm157\data\ace_vector_body_co.paa";
            bodyTextureSize = 1;
            hideMagnification = 1;
            disableTilt = 0;
        };
		ACE_ScopeHeightAboveRail = 6;
		discretedistance[] = {100,200,300,400,500,600,700,800,900,1000};
		weaponInfoType = "ace_xm157_info";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass = 10;
			scope = 2;
			optics = 1;
            modelOptics = "\x\cba\addons\optics\cba_optic_big_100.p3d";
            class OpticsModes 
			{
                class optic 
				{
                    opticsID=1;
                    useModelOptics=1;
                    opticsPPEffects[]={ "OpticsCHAbera1", "OpticsBlur1" };
                    opticsZoomMin = "8 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomMax = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    opticsZoomInit = "1 call (uiNamespace getVariable 'cba_optics_fnc_setOpticMagnificationHelper')";
                    discreteDistance[] = {100};
                    discreteDistanceInitIndex = 0;
                    distanceZoomMin=100;
                    distanceZoomMax=100;
                    memoryPointCamera="opticView";
                    visionMode[] = {"Normal"};
                    opticsFlare=1;
                    opticsDisablePeripherialVision=1;
                    cameraDir="";
                };
				class Iron
				{
					cameraDir = "";
					discreteDistance[] = {200};
					discreteDistanceInitIndex = 0;
					distanceZoomMax = 1000;
					distanceZoomMin = 100;
					memoryPointCamera = "eye";
					opticsDisablePeripherialVision = 0;
					opticsFlare = 0;
					opticsID = 2;
					opticsPPEffects[] = {"",""};
					opticsZoomInit = 0.75;
					opticsZoomMax = 1.25;
					opticsZoomMin = 0.25;
					thermalMode[] = {5,6};
					useModelOptics = 0;
					visionMode[] = {};
				};
            };
        };
    };
	class Vest_Camo_Base : ItemCore
	{
		class ItemInfo;
	};
	class VSM_RAV_operator_MulticamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_MulticamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_boxmag.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_MulticamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_projecthonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_MBSS_Green : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS (Green)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_icon.paa";
		model = "\VSM_Vests\Spectergear_MBSS\MBSS.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_co.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_MBSS\MBSS.p3d";
			containerClass = "Supply70";
			mass = 20;
			passThrough = 1;
			hiddenSelections[] = { "camo" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.4;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.4;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.4;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.4;
				};
			};
		};
	};
	class VSM_MBSS_BLK : VSM_MBSS_Green
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS (Black)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_icon_blk.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_blk_co.paa" };
	};
	class VSM_MBSS_TAN : VSM_MBSS_Green
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS (Tan)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_icon_tan.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_tan_co.paa" };
	};
	class VSM_MBSS_CB : VSM_MBSS_Green
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS (CB)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_icon_cb.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_cb_co.paa" };
	};
	class VSM_MBSS_WTF : VSM_MBSS_Green
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS (WTF???)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_icon_wtf.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_wtf_co.paa" };
	};
	class VSM_MBSS_PACA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS + PACA (Green)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_paca_icon.paa";
		model = "\VSM_Vests\Spectergear_MBSS\MBSS_PACA.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "camo","camo2" };
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_co.paa","\VSM_Vests\Spectergear_MBSS\data\spec_paca_co.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_MBSS\MBSS_PACA.p3d";
			containerClass = "Supply70";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "camo","camo2" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_MBSS_PACA_BLK : VSM_MBSS_PACA
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS + PACA (Black)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_paca_icon_blk.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_blk_co.paa","\VSM_Vests\Spectergear_MBSS\data\spec_paca_co.paa" };
	};
	class VSM_MBSS_PACA_TAN : VSM_MBSS_PACA
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS + PACA (Tan)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_paca_icon_tan.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_tan_co.paa","\VSM_Vests\Spectergear_MBSS\data\spec_paca_co.paa" };
	};
	class VSM_MBSS_PACA_CB : VSM_MBSS_PACA
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS + PACA (CB)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_paca_icon_cb.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_cb_co.paa","\VSM_Vests\Spectergear_MBSS\data\spec_paca_co.paa" };
	};
	class VSM_MBSS_PACA_WTF : VSM_MBSS_PACA
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MBSS + PACA (WTF???)";
		picture = "\VSM_Vests\Spectergear_MBSS\data\mbss_paca_icon_wtf.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_MBSS\data\spec_mbss_wtf_co.paa","\VSM_Vests\Spectergear_MBSS\data\spec_paca_co.paa" };
	};
	class VSM_LBT1961_Black : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] LBT 1961a (BLK+BLK)";
		picture = "\VSM_Vests\Spectergear_LBT\data\icon_blk_blk.paa";
		model = "\VSM_Vests\Spectergear_LBT\carrier_rig.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "camo","camo2","insignia" };
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_LBT\data\carrier_black_co.paa","\VSM_Vests\Spectergear_LBT\data\chestrig_black_co.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\carrier_rig.p3d";
			containerClass = "Supply70";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "camo","camo2","insignia" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_OD_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA_OD.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_OD_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA OD LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_oga_od.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_OD_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_ProjectHonor.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ProjectHonor LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_ProjectHonor.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_multicamtropic_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_multicamtropic.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_multicamtropic_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] MulticamTropic LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_boxmag.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_multicamtropic_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OGA LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OGA_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT1961_CB : VSM_LBT1961_Black
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] LBT 1961a (CB+CB)";
		picture = "\VSM_Vests\Spectergear_LBT\data\icon_cb_cb.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_LBT\data\carrier_coyote_co.paa","\VSM_Vests\Spectergear_LBT\data\chestrig_coyote_co.paa" };
	};
	class VSM_LBT1961_GRN : VSM_LBT1961_Black
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] LBT 1961a (GRN+GRN)";
		picture = "\VSM_Vests\Spectergear_LBT\data\icon_grn_grn.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_LBT\data\carrier_green_co.paa","\VSM_Vests\Spectergear_LBT\data\chestrig_green_co.paa" };
	};
	class VSM_LBT1961_OGA_OD : VSM_LBT1961_Black
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] ODA OD LBT 1961a";
		picture = "\VSM_Vests\Spectergear_LBT\data\icon_grn_grn.paa";
		hiddenSelectionsTextures[] = { "\VSM_Vests\Spectergear_LBT\data\VSM_OGA_OD_Plate.paa","\VSM_Vests\Spectergear_LBT\data\VSM_OGA_OD_Chestrig.paa" };
	};
	class VSM_LBT6094_operator_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] MulticamTropic LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] MulticamTropic LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_boxmag.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_multicamTropic : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] MulticamTropic LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_multicamtropic.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_OGA : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA OD LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\Spectergear_LBT\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA OD LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\Spectergear_LBT\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA_OD.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_OGA_OD : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OGA OD LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\Spectergear_LBT\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA_OD.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] ProjectHonor LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] ProjectHonor LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_ProjectHonor.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_ProjectHonor : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] ProjectHonor LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_ProjectHonor.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_MulticamTropic : ItemCore
	{
		scope = 2;
		displayName = "[VSM] MulticamTropic DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_MulticamTropic : ItemCore
	{
		scope = 2;
		displayName = "[VSM] MulticamTropic DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_multicamtropic_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc.paa","vsm_vests\spectergear_rav\data\vsm_pouches_multicamtropic.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_MulticamTropic : ItemCore
	{
		scope = 2;
		displayName = "[VSM] MulticamTropic DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_MulticamTropic.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_multicamtropic.paa","vsm_vests\spectergear_rav\data\vsm_boxmag.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_multicamtropic_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_multicamtropic.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_OGA_OD : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA OD DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_OGA_OD : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA OD DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_OD_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA_OD.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_OGA_OD : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA OD DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA_OD.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA_OD.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_OGA_OD_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA_OD.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA_OD.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_OGA : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_OGA : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OGA_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OGA.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_OGA : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OGA DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OGA.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OGA.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OGA.paa","vsm_vests\lbt6094\textures\vsm_dropholster_OGA.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_OGA_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OGA.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OGA.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_ProjectHonor : ItemCore
	{
		scope = 2;
		displayName = "[VSM] ProjectHonor DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_ProjectHonor : ItemCore
	{
		scope = 2;
		displayName = "[VSM] ProjectHonor DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_ProjectHonor_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_pouches_ProjectHonor.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_ProjectHonor : ItemCore
	{
		scope = 2;
		displayName = "[VSM] ProjectHonor DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_ProjectHonor.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_ProjectHonor.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa_tan.paa","vsm_vests\spectergear_rav\data\vsm_ProjectHonor_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_ProjectHonor.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_ProjectHonor.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_M81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_M81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_M81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_M81_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_M81.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_M81_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] M81 LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_m81.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_M81_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] M81 LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_M81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] M81 LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_m81.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_M81 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] M81 LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_M81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_M81.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_M81 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] M81 DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_m81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_M81 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] M81 DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_M81_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_m81.paa","vsm_vests\spectergear_rav\data\vsm_pouches_M81.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_M81 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] M81 DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_M81.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_M81.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_m81.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_M81_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_m81.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_M81.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_rav\data\vsm_rav_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_Multicam_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_Multicam.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_Multicam_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] Multicam LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_Multicam.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\spectergear_lbt\data\vsm_Multicam_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] Multicam LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] Multicam LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_Multicam.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_Multicam : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] Multicam LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_Multicam.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_Multicam : ItemCore
	{
		scope = 2;
		displayName = "[VSM] Multicam DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_Multicam : ItemCore
	{
		scope = 2;
		displayName = "[VSM] Multicam DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_Multicam_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_pouches_Multicam.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_Multicam : ItemCore
	{
		scope = 2;
		displayName = "[VSM] Multicam DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_Multicam.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_Multicam.paa","vsm_vests\lbt6094\textures\vsm_dropholster.paa","vsm_vests\spectergear_rav\data\serpa.paa","vsm_vests\spectergear_rav\data\vsm_Multicam_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch_green.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_Multicam.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_Multicam.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_AOR1_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_AOR1.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_AOR1_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] AOR1 LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_AOR1.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_AOR1_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] AOR1 LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] AOR1 LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_AOR1.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_AOR1 : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] AOR1 LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_AOR1.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_AOR1 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] AOR1 DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_AOR1 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] AOR1 DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_AOR1_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_pouches_AOR1.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_AOR1 : ItemCore
	{
		scope = 2;
		displayName = "[VSM] AOR1 DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_AOR1.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_AOR1.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_AOR1_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_AOR1.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_AOR1.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_operator_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP Paraclete RAV(Operator)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_MG_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP Paraclete RAV(Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_RAV_Breacher_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP Paraclete RAV(Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_rav\data\vsm_rav_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_RAV\RAV_Breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Operator_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP LBT Armatus (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_Operator.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OCP_plate.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OCP.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_operator.p3d";
			containerClass = "Supply170";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Breacher_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP LBT Armatus (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OCP_plate.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_breacher.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_CarrierRig_Gunner_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin - Specter";
		displayName = "[VSM] OCP LBT Armatus (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OCP.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\spectergear_lbt\data\vsm_OCP_plate.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\Spectergear_LBT\VSM_CarrierRig_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxmag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_operator_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OCP LBT6094 (Operator)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_operator.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_MG_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OCP LBT6094 (Gunner)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OCP.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_MG.p3d";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_boxMag","_Serpa","_SOTGGear","_SOTGRadio","_vestBase" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_LBT6094_breacher_OCP : Vest_Camo_Base
	{
		scope = 2;
		author = "VanSchmoozin";
		displayName = "[VSM] OCP LBT6094 (Breacher)";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\lbt6094\textures\vsm_lbt6094_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OCP.paa" };
		descriptionShort = "$STR_A3_SP_AL_IV";
		class ItemInfo : VestItem
		{
			uniformModel = "\VSM_Vests\lbt6094\models\VSM_lbt6094_breacher.p3d";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Operator_OCP : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OCP DT FAPC (Operator)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Operator";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_Breacher_OCP : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OCP DT FAPC (Breacher)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
		hiddenSelectionsTextures[] = { "vsm_vests\spectergear_lbt\data\vsm_OCP_chestrig.paa","vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OCP.paa","vsm_vests\spectergear_rav\data\vsm_pouches_OCP.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_Breacher";
			containerClass = "Supply200";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_1961aPouches","_battleBelt","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMPouches" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_FAPC_MG_OCP : ItemCore
	{
		scope = 2;
		displayName = "[VSM] OCP DT FAPC (Gunner)";
		author = "VanSchmoozin - Ardvarkdb";
		picture = "\VSM_Vests\Icons\VSM_OCP.paa";
		model = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
		descriptionShort = "$STR_A3_SP_AL_IV";
		hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
		hiddenSelectionsTextures[] = { "vsm_vests\battlebelt\textures\vsm_battlebelt_OCP.paa","vsm_vests\spectergear_rav\data\vsm_boxmag_OCP.paa","vsm_vests\lbt6094\textures\vsm_dropholster_oga.paa","vsm_vests\spectergear_rav\data\serpa_TAN.paa","vsm_vests\spectergear_rav\data\vsm_OCP_gear_co.paa","vsm_vests\spectergear_rav\data\radio_pouch.paa","vsm_vests\vsm_fapc\textures\vsm_fapc_OCP.paa","vsm_vests\spectergear_rav\data\vsm_buttpouch_OCP.paa" };
		class ItemInfo : VestItem
		{
			uniformModel = "VSM_Vests\VSM_FAPC\Models\VSM_FAPC_MG";
			containerClass = "Supply300";
			mass = 50;
			passThrough = 1;
			hiddenSelections[] = { "_battleBelt","_boxMag","_DropHolster","_Serpa","_SOTGGear","_SOTGRadio","_vestBase","_VSMButtPouch" };
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName = "HitChest";
					armor = 19;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 19;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 19;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class VSM_Mich2000_MulticamTropic : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_M81 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_CamoSprayOD : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_CamoSprayTAN : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_OGA : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_OGA_OD : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_ProjectHonor : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_Multicam : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_AOR1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_ocp : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_MulticamTropic : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_OCP : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_aor1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_M81 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_CamoSprayOD : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_CamoSprayTAN : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_OGA : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_OGA_OD : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_ProjectHonor : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Mich2000_2_Multicam : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	///OPS START
	class VSM_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_multicam : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_ocp : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_aor1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Black_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_oga_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OGA_OD_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_ProjectHonor_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Tan_spray_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OD_spray_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_MulticamTropic_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_M81_OPS : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	///OPS 2 START
	class VSM_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_2_multicam : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_2_ocp : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OPS_2_AOR1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Black_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_oga_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OGA_OD_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_ProjectHonor_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_MulticamTropic_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_M81_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Tan_spray_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OD_Spray_OPS_2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	///BOWMAN HAT START
	class VSM_Bowman : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_Black : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_Green : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_Tan : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_balaclava_Tan : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_balaclava_Olive : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Bowman_cap_balaclava_Black : ItemCore
	{
		ace_hearing_protection = 0.40;
		ace_hearing_lowerVolume = 0;
	};
	///ECH START
	class VSM_OGA_Helmet1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OGA_OD_Helmet1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OGA_Helmet2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_OGA_OD_Helmet2 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	///PELTOR START
	class VSM_Peltor_AOR1 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Peltor_Coyote : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Peltor_M81 : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Peltor_OCP : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
	class VSM_Peltor_OD : ItemCore
	{
		ace_hearing_protection = 0.75;
		ace_hearing_lowerVolume = 0;
	};
};
class RCWSOptics;	// External class reference
class Optics_Armored;	// External class reference
class CommanderOptics;	// External class reference
class CfgVehicles
{
	//class UAV;
	//class USAF_MQ9 : UAV
	//{
	//	weapons[] = { "rhsusf_weap_LWIRCM" };
	//	magazines[] = { "rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM",};
	//};
	//class UAV_02_base_F : UAV
	//{
	//	weapons[] = { "rhsusf_weap_LWIRCM" };
	//	magazines[] = { "rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM"};
	//};
	//class UAV_02_CAS_base_F : UAV_02_base_F
//	{
	//	weapons[] = { "rhsusf_weap_LWIRCM" };
	//	magazines[] = { "rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM"};
	//};
	class Helicopter;
	class Helicopter_Base_F : Helicopter
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_H : Helicopter_Base_F
	{
		class EventHandlers;
		class Turrets : Turrets
		{
			class CopilotTurret;
		};
		class HitPoints : HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitAvionics;
			class HitVRotor;
			class HitHRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class CargoTurret;
		class AnimationSources;
		class ViewOptics;
		class RotorLibHelicopterProperties;
		class Components;
	};
	class RHS_MELB_base : Helicopter_Base_H
	{
		slingLoadMaxCargoMass = 4000;
		LockDetectionSystem = "1 + 2 + 4 + 8 + 16";
		incomingMissileDetectionSystem = 16;
		magazines[] = { "Laserbatteries","rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM"};
		class Components : Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent : SensorTemplateIR
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						maxTrackableSpeed = 75;
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						animDirection = "commanderview";
					};
					class VisualSensorComponent : SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						maxTrackableSpeed = 75;
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						aimDown = 1;
						animDirection = "commanderview";
					};
					class ActiveRadarSensorComponent : SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 7000;
							maxRange = 7000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 4000;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						aimDown = 35;
					};
					class DataLinkSensorComponent : SensorTemplateDataLink {};
					class PassiveRadarSensorComponent : SensorTemplatePassiveRadar {};
					class LaserSensorComponent : SensorTemplateLaser
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
						aimDown = 30;
					};
					class NVSensorComponent : SensorTemplateNV
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
						aimDown = 30;
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft : VehicleSystemsTemplateLeftPilot {};
			class VehicleSystemsDisplayManagerComponentRight : VehicleSystemsTemplateRightPilot {};
		};
	};
	class RHS_MELB_AH6M : RHS_MELB_base
	{
		receiveRemoteTargets = true;
		slingLoadMaxCargoMass = 4000;
		reportRemoteTargets = true;
		LockDetectionSystem = "1 + 2 + 4 + 8 + 16";
		incomingMissileDetectionSystem = 16;
		magazines[] = { "Laserbatteries","rhsusf_mag_LWIRCM","rhsusf_mag_LWIRCM"};
	};
	class Heli_Transport_01_base_F;
	class RHS_UH60_Base : Heli_Transport_01_base_F
	{
		incomingMissileDetectionSystem = "1 + 2 + 4 + 8 + 16";
		countermeasureActivationRadius = 10000;
		receiveRemoteTargets = true;
		reportRemoteTargets = true;
	};
	/*extern*/ class Car;

	class Car_F : Car {
		/*extern*/ class Sounds;

		class HitPoints {
			/*extern*/ class HitBody;
			/*extern*/ class HitEngine;
			/*extern*/ class HitFuel;
			/*extern*/ class HitHull;
			/*extern*/ class HitLFWheel;
			/*extern*/ class HitLBWheel;
			/*extern*/ class HitLMWheel;
			/*extern*/ class HitLF2Wheel;
			/*extern*/ class HitRFWheel;
			/*extern*/ class HitRBWheel;
			/*extern*/ class HitRMWheel;
			/*extern*/ class HitRF2Wheel;
		};
	};

	class Wheeled_APC_F : Car_F {
		/*extern*/ class ViewPilot;
		/*extern*/ class ViewOptics;
		/*extern*/ class ViewCargo;
		/*extern*/ class EventHandlers;
		class Sounds : Sounds {
			/*extern*/ class Engine;
			/*extern*/ class Movement;
		};
		/*extern*/ class NewTurret;

		class Turrets {

			class MainTurret : NewTurret {
				/*extern*/ class ViewOptics;
				/*extern*/ class ViewGunner;

				class Turrets {
					/*extern*/ class CommanderOptics;
				};
			};
		};
		/*extern*/ class AnimationSources;
	};

	class APC_Wheeled_01_base_F : Wheeled_APC_F {
		/*extern*/ class AnimationSources;

		class Turrets : Turrets {
			/*extern*/ class MainTurret;
		};
	};
	class B_APC_Wheeled_01_base_F : APC_Wheeled_01_base_F {};
	class B_APC_Wheeled_01_cannon_F : B_APC_Wheeled_01_base_F
	{
		displayName = "LAV-25";
		armor = 450;
		class TransportWeapons
		{
			class _xx_arifle_MX_F
			{
				weapon = "rhs_weap_fgm148";
				count = 2;
			};
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "ACE_salineIV";
				count = 10;
			};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_65x39_caseless_mag
			{
				magazine = "rhs_fgm148_magazine_AT";
				count = 4;
			};
			class _xx_100Rnd_65x39_caseless_mag
			{
				magazine = "ACE_30Rnd_556x45_Stanag_M995_AP_mag";
				count = 18;
			};
			class _xx_HandGrenade
			{
				magazine = "rhsusf_200Rnd_556x45_soft_pouch_coyote";
				count = 3;
			};
			class _xx_MiniGrenade
			{
				magazine = "rhsusf_100Rnd_762x51_m61_ap";
				count = 3;
			};
			class _xx_1Rnd_HE_Grenade_shell
			{
				magazine = "ACE_20Rnd_762x51_M993_AP_Mag";
				count = 6;
			};
			class _xx_1Rnd_Smoke_Grenade_shell
			{
				magazine = "rhs_mag_an_m8hc";
				count = 8;
			};
			class _xx_1Rnd_SmokeGreen_Grenade_shell
			{
				magazine = "rhs_mag_M433_HEDP";
				count = 8;
			};
		};
	};
	class Air;
	class Plane : Air
	{
		class NewTurret;
		class ViewPilot;
		class HitPoints
		{
			class HitHull;
		};
	};
	class Plane_Base_F : Plane
	{
		class AnimationSources;
		class HitPoints : HitPoints
		{
			class HitHull;
		};
		class Components;
		class Eventhandlers;
	};
	class Plane_Fighter_03_base_F : Plane_Base_F {};
	class RHSGREF_A29_Base : Plane_Fighter_03_base_F {};
	class RHSGREF_A29B_HIDF : RHSGREF_A29_Base
	{
		class Components : Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent : SensorTemplateIR
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						maxTrackableSpeed = 75;
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						animDirection = "TGPTilt";
					};
					class VisualSensorComponent : SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						maxTrackableSpeed = 75;
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						aimDown = 1;
						animDirection = "TGPTilt";
					};
					class ActiveRadarSensorComponent : SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 7000;
							maxRange = 7000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 4000;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						angleRangeHorizontal = 240;
						angleRangeVertical = 110;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						aimDown = 35;
					};
					class DataLinkSensorComponent : SensorTemplateDataLink {};
					class PassiveRadarSensorComponent : SensorTemplatePassiveRadar {};
					class LaserSensorComponent : SensorTemplateLaser
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
						aimDown = 30;
					};
					class NVSensorComponent : SensorTemplateNV
					{
						angleRangeHorizontal = 360;
						angleRangeVertical = 120;
						aimDown = 30;
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft : VehicleSystemsTemplateLeftPilot {};
			class VehicleSystemsDisplayManagerComponentRight : VehicleSystemsTemplateRightPilot {};
			class TransportPylonsComponent
			{
				UIPicture = "\rhsgref\addons\rhsgref_a29\ui\RHS_A29_EDEN_CA.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[] = { "RHS_HP_FFAR_USAF","RHS_HP_Hydra_USAF","RHS_HP_LGB_500","RHS_HP_HELLFIRE_PLANE","RHS_HP_HELLFIRE_PLANE_RACK","O_MISSILE_PYLON" };
						attachment = "rhs_mag_M151_7_USAF_LAU131";
						priority = 1;
						maxweight = 150;
						UIposition[] = { 0.28,0.41 };
						hitpoint = "HitPylon1";
					};
					class pylons2
					{
						hardpoints[] = { "RHS_HP_FFAR_USAF","RHS_HP_Hydra_USAF","RHS_HP_LGB_500","O_MISSILE_PYLON" };
						attachment = "rhs_mag_gbu12";
						priority = 2;
						maxweight = 250;
						UIposition[] = { 0.28,0.35 };
						hitpoint = "HitPylon1";
					};
					class pylons3
					{
						hardpoints[] = { "RHS_HP_BOMB_500","RHS_HP_BOMB_1000" };
						attachment = "rhs_mag_mk82";
						priority = 3;
						maxweight = 500;
						UIposition[] = { 0.31,0.28 };
						hitpoint = "HitPylon3";
					};
					class pylons4 : pylons2
					{
						UIposition[] = { 0.28,0.21 };
						mirroredMissilePos = 2;
						hitpoint = "HitPylon4";
					};
					class pylons5 : pylons1
					{
						UIposition[] = { 0.28,0.15 };
						mirroredMissilePos = 1;
						hitpoint = "HitPylon5";
					};
					class cmDispenser
					{
						hardpoints[] = { "RHSUSF_cm_ANALE40_x2" };
						priority = 1;
						attachment = "rhsusf_ANALE40_CMFlare_Magazine_x2";
						maxweight = 800;
						UIposition[] = { 0.625,0.275 };
					};
				};
				class Presets
				{
					class CAS
					{
						attachment[] = { "rhs_mag_M151_7_USAF_LAU131","rhs_mag_gbu12","rhs_mag_mk82","rhs_mag_gbu12","rhs_mag_M151_7_USAF_LAU131","rhsusf_ANALE40_CMFlare_Magazine_x2" };
						displayname = "Close Air Support";
					};
					class PrecisionStrike
					{
						attachment[] = { "rhs_mag_DAGR_8_plane","rhs_mag_gbu12","rhs_mag_mk82","rhs_mag_gbu12","rhs_mag_DAGR_8_plane","rhsusf_ANALE40_CMFlare_Magazine_x2" };
						displayname = "Precision Strike";
					};
					class AntiTank
					{
						attachment[] = { "rhs_mag_AGM114K_2_plane","rhs_mag_gbu12","rhs_mag_cbu87","rhs_mag_gbu12","rhs_mag_AGM114K_2_plane","rhsusf_ANALE40_CMFlare_Magazine_x2" };
						displayname = "Anti Tank";
					};
					class Cluster
					{
						attachment[] = { "rhs_mag_M151_7_USAF_LAU131","rhs_mag_cbu87","rhs_mag_cbu100","rhs_mag_cbu87","rhs_mag_M151_7_USAF_LAU131","rhsusf_ANALE40_CMFlare_Magazine_x2" };
						displayname = "Cluster";
					};
					class DumbBomb
					{
						attachment[] = { "rhs_mag_M151_7_USAF_LAU131","rhs_mag_mk82","rhs_mag_mk82","rhs_mag_mk82","rhs_mag_M151_7_USAF_LAU131","rhsusf_ANALE40_CMFlare_Magazine_x2" };
						displayname = "Bomb";
					};
				};
			};
		};
	};
};
class ACE_M84FlashbangEffect {};
class CfgMovesFatigue
{
	staminaDuration = 105;
	staminaRestoration = 5;
	staminaCooldown = 4;
	aimPrecisionSpeedCoef = 5;
	terrainDrainSprint = -1;
	terrainDrainRun = -1;
	terrainSpeedCoef = 0.9;
};
class CfgInventoryGlobalVariable
{
	maxSoldierLoad = 1350;
};
class Primary
{
	verticalRadius = 0.2;
	horizontalRadius = 0.04;
};
class Secondary
{
	verticalRadius = 0.04;
	horizontalRadius = 0.2;
};

