#include "base_draw_startmenue.h"

Base_draw_startmenue::Base_draw_startmenue(double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_, 
		int *menue_var_, int this_menue_var_) {
	p_define_srsize = define_srsize_;
	p_gr = gr_;
	draw_x = draw_x_;
	draw_y = draw_y_;
	rota_cx = rota_cx_;
	rota_cy = rota_cy_;
	rota_radian = rota_radian_;
	menue_var = menue_var_;
	this_menue_var = this_menue_var_;
}

void Base_draw_startmenue::Drawgr() {
	if (*menue_var == this_menue_var) {
		DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize), 
			static_cast<int>(rota_cx * *p_define_srsize), static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
	}
	else if (*menue_var == this_menue_var + 1 || (this_menue_var == 0 && *menue_var == MAX_MENUE_NUMBER - 1)) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize + MOVE_MENUE_DIST), 
			static_cast<int>(rota_cx * *p_define_srsize), static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else if (*menue_var == this_menue_var - 1 || (this_menue_var == MAX_MENUE_NUMBER - 1 && *menue_var == 0)) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize - MOVE_MENUE_DIST), 
			static_cast<int>(rota_cx * *p_define_srsize), static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}