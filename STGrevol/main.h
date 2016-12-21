#pragma once
#include <memory>
#include "DxLib.h"
#include "title.h"
#include "define_srsize.h"
#include "depicyion_loadgr.h"

Define_srsize define_srsize("data");
Depiction_loadgr depiction_loadgr(&define_srsize.enlargement_factor);
Title title(&define_srsize.enlargement_factor, &depiction_loadgr.titlegr);