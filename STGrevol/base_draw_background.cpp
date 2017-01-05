#include "base_draw_background.h"

Base_draw_background::Base_draw_background(double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_) {
	p_define_srsize = define_srsize_;
	p_gr = gr_;
	draw_x = draw_x_;
	draw_y = draw_y_;
	rota_cx = rota_cx_;
	rota_cy = rota_cy_;
	rota_radian = rota_radian_;
}

void Base_draw_background::Drawgr() {
	DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize),
		static_cast<int>(rota_cx * *p_define_srsize), static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
}