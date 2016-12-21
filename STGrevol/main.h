#pragma once
#include <memory>
#include "DxLib.h"
#include "title.h"
#include "define_srsize.h"
#include "depicyion_loadgr.h"

//std::unique_ptr<Define_srsize> define_srsize(new Define_srsize("data"));
Define_srsize define_srsize("data");
Depiction_loadgr depiction_loadgr;
Title title(&define_srsize.enlargement_factor, &depiction_loadgr.titlegr);