#pragma once
#include "DxLib.h"
#include "base_drawgraph.h"

class Startmode_select : public Base_drawgraph {
public:
	using Base_drawgraph::Base_drawgraph;

	void Draw_start(int *p_select_menue_var);
private:
};