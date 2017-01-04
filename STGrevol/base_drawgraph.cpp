#include "base_drawgraph.h"

Base_drawgraph::Base_drawgraph(double *define_srsize_, int *gr_, int draw_x_, int draw_y_, int rota_cx_, int rota_cy_, double rota_radian_) {
	p_define_srsize = define_srsize_;
	p_gr = gr_;
	draw_x = draw_x_;
	draw_y = draw_y_;
	rota_cx = rota_cx_;
	rota_cy = rota_cy_;
	rota_radian = rota_radian_;
}

void Base_drawgraph::Drawgr() {
	DrawRotaGraph2(draw_x, draw_y, rota_cx, rota_cy, *p_define_srsize, rota_radian, *p_gr, true, false);
}