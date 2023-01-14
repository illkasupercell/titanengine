AddCSLua("cl_init.lua")
if istable( xdestore ) then if xdestore.Menu then xdestore.Menu:Remove() end  if xdestore.Unlock then xdestore.Unlock:Remove() end
if xdestore.Namer then xdestore.Namer:Remove() end  if xdestore.Lock then xdestore.Lock:Remove() end end xdestore = {} xdestore.Players = {}

	util.AddNetworkString( "XDEST_MenuS2COpen" ) util.AddNetworkString( "XDEST_MenuS2CClose" ) util.AddNetworkString( "XDEST_SendRes" )
	util.AddNetworkString( "XDEST_MenuS2CUpdate" ) util.AddNetworkString( "XDEST_MenuS2CResult" ) util.AddNetworkString( "XDEST_MenuC2SClose" )
	util.AddNetworkString( "XDEST_LockReset" ) util.AddNetworkString( "XDEST_MenuC2SAction" ) util.AddNetworkString( "XDEST_SendSnd" ) util.AddNetworkString( "XDEST_SendHint" )

xdestore.AmmoMdl = {
	[ "AR2" ] = "models/items/combine_rifle_cartridge01.mdl",
	[ "AR2AltFire" ] = "models/items/combine_rifle_ammo01.mdl",
	[ "Pistol" ] = "models/items/boxsrounds.mdl",
	[ "SMG1" ] = "models/items/boxmrounds.mdl",
	[ "357" ] = "models/items/357ammo.mdl",
	[ "XBowBolt" ] = "models/items/crossbowrounds.mdl",
	[ "Buckshot" ] = "models/items/boxbuckshot.mdl",
	[ "RPG_Round" ] = "models/weapons/w_missile_closed.mdl",
	[ "SMG1_Grenade" ] = "models/items/ar2_grenade.mdl",
	[ "Grenade" ] = "models/items/grenadeammo.mdl",
	[ "slam" ] = "models/weapons/w_slam.mdl"
}
xdestore.NonSWEP = {
	[ "weapon_357" ] = "models/weapons/w_357.mdl",
	[ "weapon_pistol" ] = "models/weapons/w_pistol.mdl",
	[ "weapon_bugbait" ] = "models/weapons/w_bugbait.mdl",
	[ "weapon_crossbow" ] = "models/weapons/w_crossbow.mdl",
	[ "weapon_crowbar" ] = "models/weapons/w_crowbar.mdl",
	[ "weapon_frag" ] = "models/weapons/w_grenade.mdl",
	[ "weapon_physcannon" ] = "models/weapons/w_physics.mdl",
	[ "weapon_ar2" ] = "models/weapons/w_irifle.mdl",
	[ "weapon_rpg" ] = "models/weapons/w_rocket_launcher.mdl",
	[ "weapon_slam" ] = "models/weapons/w_slam.mdl",
	[ "weapon_shotgun" ] = "models/weapons/w_shotgun.mdl",
	[ "weapon_smg1" ] = "models/weapons/w_smg1.mdl",
	[ "weapon_stunstick" ] = "models/weapons/w_stunbaton.mdl",
	[ "weapon_alyxgun" ] = "models/weapons/w_alyx_gun.mdl",
	[ "weapon_annabelle" ] = "models/weapons/w_annabelle.mdl",
	[ "weapon_physgun" ] = "models/weapons/w_physics.mdl"
}
xdestore.ValidAct = { [ "Take" ] = true, [ "Move" ] = true, [ "Store" ] = true, [ "Rename" ] = true, [ "TakeAll" ] = true, [ "Split" ] = true, [ "Lock" ] = true, [ "Unlock" ] = true }
xdestore.ActToNum = { "Take", "Move", "Store", "TakeAll", "Rename", "Split", "Lock", "Unlock" }
xdestore.LockType = { "Simple", "Complex", "Question", "Key Weapon", "Group", "Personal" }
net.Receive( "XDEST_MenuS2COpen", function() local int = net.ReadFloat()  local tab = net.ReadString()  local con = net.ReadString()
local ent = net.ReadEntity() xdestore:OpenMenu( ply, int, tab, con, ent ) end )
net.Receive( "XDEST_MenuS2CClose", function() if xdestore.Menu then xdestore.Menu:Remove() end  if xdestore.Namer then xdestore.Namer:Remove() end
if xdestore.Lock then xdestore.Lock:Remove() end  if xdestore.Unlock then xdestore.Unlock:Remove() end end )
net.Receive( "XDEST_MenuS2CUpdate", function()
	local tab = util.JSONToTable( net.ReadString() )  local con = util.JSONToTable( net.ReadString() )  local aa = net.ReadBool()  local bb = net.ReadBool()
	if IsValid( xdestore.Menu ) then xdestore.Menu.V_DataStat = tab  xdestore.Menu.V_DataCont = con  xdestore.Menu:UpdateItems( aa, bb ) end
end )
net.Receive( "XDEST_MenuC2SClose", function( len, ply ) if len > 32 or !IsValid( ply ) then return end
	local int = net.ReadFloat() if IsValid( ply ) and ply:IsPlayer() and !ply:IsBot() and isnumber( int ) then xdestore:CloseMenu( ply, int ) end
end )
net.Receive( "XDEST_MenuC2SAction", function( len, ply ) if len >= 4096 or !IsValid( ply ) then return end
	if isnumber( ply.XDEST_Cool ) and ply.XDEST_Cool > CurTime() then xdestore:SendHint( ply, "You are doing too fast!", "resource/warning.wav", 0 ) end
	ply.XDEST_Cool = CurTime()+0.25  if !IsValid( ply:GetNWEntity( "XDEST_Ent" ) ) or ply:GetNWEntity( "XDEST_Ent" ) == Entity( 0 ) then return end local self = ply:GetNWEntity( "XDEST_Ent" )
	if ( ( !isstring( self.Base ) or self.Base != "xdest_base" ) and self:GetClass() != "xdest_base" and self:GetClass() != "weapon_xdest" )
	or !isstring( self.XDEST_Data ) or !isstring( self.XDEST_Contain ) then return end
	local act = net.ReadFloat()  local str = net.ReadString() if !isnumber( act ) then return end act = math.Round( act )
	if !isstring( str ) then str = "_" end if isstring( xdestore.ActToNum[ act ] ) then act = xdestore.ActToNum[ act ] else return end  xdestore:SlotAction( ply, self, act, str )
end )
net.Receive( "XDEST_MenuS2CResult", function() local ply = LocalPlayer() local yes = net.ReadBool()  if IsValid( xdestore.Unlock ) then xdestore.Unlock:XDE_Result( yes ) end end )
net.Receive( "XDEST_LockReset", function() local ent = net.ReadEntity() if IsValid( ent ) and ent != Entity( 0 ) then ent.XDE_Pass = nil end end )
net.Receive( "XDEST_SendSnd", function() local str = net.ReadString() if !isstring( str ) or str == "!V" then return end surface.PlaySound( str ) end )
net.Receive( "XDEST_SendRes", function() local str = net.ReadString()  local ply = LocalPlayer()  local ent = net.ReadEntity() if !IsValid( ent )
or ent == Entity( 0 ) or !isstring( str ) or str == "" then return end if !isstring( ent.XDE_Pass ) then xdestore:SendHint( nil, "Access granted.", "", 0 ) end ent.XDE_Pass = str end )
net.Receive( "XDEST_SendHint", function() local txt = net.ReadString()  local snd = net.ReadString()  local typ = net.ReadFloat()  xdestore:SendHint( nil, txt, snd, typ ) end )
