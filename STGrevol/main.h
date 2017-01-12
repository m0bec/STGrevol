#pragma once
#include <memory>
#include "DxLib.h"
#include "title.h"
#include "define_srsize.h"
#include "depiction_loadgr.h"
#include "loadgr.h"
#include "startmode_select.h"
#include "exitmode_select.h"
#include "titlemenue_system.h"
#include "keyconmode_select.h"
#include "manualmode_select.h"
#include "joypad_control.h"
#include "system_control.h"


Define_srsize define_srsize("data");
Joypad_control joypad_control("data2");
System_control system_control;
Depiction_loadgr depiction_loadgr(&define_srsize.enlargement_factor);
Loadgr loadgr;
Titlemenue_system titlemenue_system(&define_srsize.enlargement_factor, &joypad_control.upkey_flag, &joypad_control.downkey_flag, &joypad_control.shot_flag);
Title title(&define_srsize.enlargement_factor, &loadgr.titlegr, 0, 0, 0, 0, 0.0);
Startmode_select startmode_select(&define_srsize.enlargement_factor, &loadgr.startgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, START_MENUE_NUMBER);
Exitmode_select exitmode_select(&define_srsize.enlargement_factor, &loadgr.exitgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, EXIT_MENUE_NUMBER, &joypad_control.shot_flag);
Manualmode_select manualmode_select(&define_srsize.enlargement_factor, &loadgr.manualgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, MANUAL_MENUE_NUMBER);
Keyconmode_select keyconmode_select(&system_control.system_var, &define_srsize.enlargement_factor, &loadgr.keycongr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, KEYCON_MENUE_NUMBER, &loadgr.keycon_num, &loadgr.exitgr, &joypad_control.shot_flag);