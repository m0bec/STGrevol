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

Define_srsize define_srsize("data");
Depiction_loadgr depiction_loadgr(&define_srsize.enlargement_factor);
Loadgr loadgr;
Titlemenue_system titlemenue_system(&define_srsize.enlargement_factor);
Title title(&define_srsize.enlargement_factor, &loadgr.titlegr, 0, 0, 0, 0, 0.0);
Startmode_select startmode_select(&define_srsize.enlargement_factor, &loadgr.startgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, START_MENUE_NUMBER);
Exitmode_select exitmode_select(&define_srsize.enlargement_factor, &loadgr.exitgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, EXIT_MENUE_NUMBER);
Manualmode_select manualmode_select(&define_srsize.enlargement_factor, &loadgr.keycongr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, KEYCON_MENUE_NUMBER);
Keyconmode_select keyconmode_select(&define_srsize.enlargement_factor, &loadgr.manualgr, TITLEMEN_BASIC_PLACE_X, TITLEMEN_BASIC_PLACE_Y, 0, 0, 0.0, &titlemenue_system.select_menue_var, MANUAL_MENUE_NUMBER);