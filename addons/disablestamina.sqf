waitUntil {(!isNull Player) and (alive Player)};
player enableStamina false;
_index = player addMPEventHandler ["MPKilled", { _this execVM "addons\disablestamina.sqf"; }];