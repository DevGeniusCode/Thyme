////////////////////////////////////////////////////////////////////////////////
//                               --  THYME  --                                //
////////////////////////////////////////////////////////////////////////////////
//
//  Project Name:: Thyme
//
//          File:: KINDOF.H
//
//        Author:: OmniBlade
//
//  Contributors:: 
//
//   Description:: KindOf enum and string listings.
//
//       License:: Thyme is free software: you can redistribute it and/or 
//                 modify it under the terms of the GNU General Public License 
//                 as published by the Free Software Foundation, either version 
//                 2 of the License, or (at your option) any later version.
//
//                 A full copy of the GNU General Public License can be found in
//                 LICENSE
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "always.h"
#include "bitflags.h"

enum KindOfType : int32_t
{
    KINDOF_FIRST = 0,
    KINDOF_OBSTACLE = 0,
    KINDOF_SELECTABLE,
    KINDOF_IMMOBILE,
    KINDOF_CAN_ATTACK,
    KINDOF_STICK_TO_TERRAIN_SLOPE,
    KINDOF_CAN_CAST_REFLECTIONS,
    KINDOF_SHRUBBERY,
    KINDOF_STRUCTURE,
    KINDOF_INFANTRY,
    KINDOF_VEHICLE,
    KINDOF_AIRCRAFT,
    KINDOF_HUGE_VEHICLE,
    KINDOF_DOZER,
    KINDOF_HARVESTER,
    KINDOF_COMMANDCENTER,
    KINDOF_LINEBUILD,
    KINDOF_SALVAGER,
    KINDOF_WEAPON_SALVAGER,
    KINDOF_TRANSPORT,
    KINDOF_BRIDGE,
    KINDOF_LANDMARK_BRIDGE,
    KINDOF_BRIDGE_TOWER,
    KINDOF_PROJECTILE,
    KINDOF_PRELOAD,
    KINDOF_NO_GARRISON,
    KINDOF_WAVEGUIDE,
    KINDOF_WAVE_EFFECT,
    KINDOF_NO_COLLIDE,
    KINDOF_REPAIR_PAD,
    KINDOF_HEAL_PAD,
    KINDOF_STEALTH_GARRISON,
    KINDOF_CASH_GENERATOR,
    KINDOF_DRAWABLE_ONLY,
    KINDOF_MP_COUNT_FOR_VICTORY,
    KINDOF_REBUILD_HOLE,
    KINDOF_SCORE,
    KINDOF_SCORE_CREATE,
    KINDOF_SCORE_DESTROY,
    KINDOF_NO_HEAL_ICON,
    KINDOF_CAN_RAPPEL,
    KINDOF_PARACHUTABLE,
    KINDOF_CAN_BE_REPULSED,
    KINDOF_MOB_NEXUS,
    KINDOF_IGNORED_IN_GUI,
    KINDOF_CRATE,
    KINDOF_CAPTURABLE,
    KINDOF_CLEARED_BY_BUILD,
    KINDOF_SMALL_MISSILE,
    KINDOF_ALWAYS_VISIBLE,
    KINDOF_UNATTACKABLE,
    KINDOF_MINE,
    KINDOF_CLEANUP_HAZARD,
    KINDOF_PORTABLE_STRUCTURE,
    KINDOF_ALWAYS_SELECTABLE,
    KINDOF_ATTACK_NEEDS_LINE_OF_SIGHT,
    KINDOF_WALK_ON_TOP_OF_WALL,
    KINDOF_DEFENSIVE_WALL,
    KINDOF_FS_POWER,
    KINDOF_FS_FACTORY,
    KINDOF_FS_BASE_DEFENSE,
    KINDOF_FS_TECHNOLOGY,
    KINDOF_AIRCRAFT_PATH_AROUND,
    KINDOF_LOW_OVERLAPPABLE,
    KINDOF_FORCEATTACKABLE,
    KINDOF_AUTO_RALLYPOINT,
    KINDOF_TECH_BUILDING,
    KINDOF_POWERED,
    KINDOF_PRODUCED_AT_HELIPAD,
    KINDOF_DRONE,
    KINDOF_CAN_SEE_THROUGH_STRUCTURE,
    KINDOF_BALLISTIC_MISSILE,
    KINDOF_CLICK_THROUGH,
    KINDOF_SUPPLY_SOURCE_ON_PREVIEW,
    KINDOF_PARACHUTE,
    KINDOF_GARRISONABLE_UNTIL_DESTROYED,
    KINDOF_BOAT,
    KINDOF_IMMUNE_TO_CAPTURE,
    KINDOF_HULK,
    KINDOF_SHOW_PORTRAIT_WHEN_CONTROLLED,
    KINDOF_SPAWNS_ARE_THE_WEAPONS,
    KINDOF_CANNOT_BUILD_NEAR_SUPPLIES,
    KINDOF_SUPPLY_SOURCE,
    KINDOF_REVEAL_TO_ALL,
    KINDOF_DISGUISER,
    KINDOF_INERT,
    KINDOF_HERO,
    KINDOF_IGNORES_SELECT_ALL,
    KINDOF_DONT_AUTO_CRUSH_INFANTRY,
    KINDOF_CLIFF_JUMPER,
    KINDOF_FS_SUPPLY_DROPZONE,
    KINDOF_FS_SUPERWEAPON,
    KINDOF_FS_BLACK_MARKET,
    KINDOF_FS_SUPPLY_CENTER,
    KINDOF_FS_STRATEGY_CENTER,
    KINDOF_MONEY_HACKER,
    KINDOF_ARMOR_SALVAGER,
    KINDOF_REVEALS_ENEMY_PATHS,
    KINDOF_BOOBY_TRAP,
    KINDOF_FS_FAKE,
    KINDOF_FS_INTERNET_CENTER,
    KINDOF_BLAST_CRATER,
    KINDOF_PROP,
    KINDOF_OPTIMIZED_TREE,
    KINDOF_FS_ADVANCED_TECH,
    KINDOF_FS_BARRACKS,
    KINDOF_FS_WARFACTORY,
    KINDOF_FS_AIRFIELD,
    KINDOF_AIRCRAFT_CARRIER,
    KINDOF_NO_SELECT,
    KINDOF_REJECT_UNMANNED,
    KINDOF_CANNOT_RETALIATE,
    KINDOF_TECH_BASE_DEFENSE,
    KINDOF_EMP_HARDENED,
    KINDOF_DEMOTRAP,
    KINDOF_CONSERVATIVE_BUILDING,
    KINDOF_IGNORE_DOCKING_BONES,
    KINDOF_COUNT,
};