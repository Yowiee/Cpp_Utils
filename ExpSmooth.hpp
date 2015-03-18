/*
 *	$Id:$
 *
 *		Contains definition of simple Exponential Smoothing statistics class
 *
 */

#ifndef _EXPSMOOTH_HPP_
#define _EXPSMOOTH_HPP_

class EXPSMOOTH {
public:
	void AddData(double);

	double Read(void) { return(ExpSmooth); }

	void Reset(double);

	EXPSMOOTH(double alpha) { Reset(alpha); }
	EXPSMOOTH(double alpha, double init_val) { Reset(alpha); AddData(init_val); }
	~EXPSMOOTH() {}

private:
	double ExpSmooth;
	double Alpha;
	bool Init;
}; // EXPSMOOTH

#endif
