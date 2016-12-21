#include "title.h"

Title::Title(double *define_srsize_, int *titlegr_) {
	define_srsize = define_srsize_;
	titlegr = titlegr_;
}

void Title::Control() {
	Drawtitle();
}

void Title::Drawtitle() {
	DrawRotaGraph2(0, 0, 0, 0, *define_srsize, 0.0, *titlegr, true, false);
}