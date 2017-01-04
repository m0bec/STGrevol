#pragma once
#include <memory>
#include "DxLib.h"
#include "title.h"
#include "define_srsize.h"
#include "depiction_loadgr.h"
#include "loadgr.h"

Define_srsize define_srsize("data");
Depiction_loadgr depiction_loadgr(&define_srsize.enlargement_factor);
Loadgr loadgr;
Title title(&define_srsize.enlargement_factor, &loadgr.titlegr, 0, 0, 0, 0, 0.0);