#include "startmode_select.h"

void Startmode_select::Draw_start(int *p_select_menue_var) {
	if (*p_select_menue_var == 0) {
		DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize), static_cast<int>(rota_cx * *p_define_srsize),
			static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
	}
	else if (*p_select_menue_var == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawRotaGraph2(static_cast<int>(draw_x * *p_define_srsize), static_cast<int>(draw_y * *p_define_srsize), static_cast<int>(rota_cx * *p_define_srsize),
			static_cast<int>(rota_cy * *p_define_srsize), *p_define_srsize, rota_radian, *p_gr, true, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}