/*
 *	$Id:$
 *
 *		Contains code for simple Exponential Smoothing statistics class
 *
 */

 #include "expsmooth.hpp"

void EXPSMOOTH::Reset(double alpha) {
	// function should check that 0 < alpha  < 1
	Alpha = alpha;
	Init = 0;
	ExpSmooth = 0.0;
}
 
void EXPSMOOTH::AddData(double data) {
	if (!Init) {
		ExpSmooth = data;
		Init = 1;
	}
	else {
		ExpSmooth *= 1.0 - Alpha;
		ExpSmooth += Alpha*data;
	}
}

double Read(void);