#pragma once
#include <memory>
#include "DxLib.h"
#include "title.h"
#include "define_srsize.h"
#include "depiction_loadgr.h"
#include "loadgr.h"
#include "startmode_select.h"
#include "exitmode_select.h"

Define_srsize define_srsize("data");
Depiction_loadgr depiction_loadgr(&define_srsize.enlargement_factor);
Loadgr loadgr;
Title title(&define_srsize.enlargement_factor, &loadgr.titlegr, 0, 0, 0, 0, 0.0);
Startmode_select startmode_select(&define_srsize.enlargement_factor, &loadgr.startgr, 220, 300, 0, 0, 0.0);
Exitmode_select exitmode_selsct(&define_srsize.enlargement_factor, &loadgr.exitgr, 220, 400, 0, 0, 0.0);