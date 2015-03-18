/*
 *	$Id:$
 *
 *		Contains code for high resolution timer class
 *
 */

#include "HRTimer.hpp"

#if defined _WIN_HRTIMER_
HRTIMER::HRTIMER() {
	
	if (!QueryPerformanceFrequency(&start_cnt))
	{
//		std::cout << "QueryPerformanceFrequency failed!\n";
	}
	
	invPCFreq = 1.0/double(start_cnt.QuadPart);
	QueryPerformanceCounter(&start_cnt);
	stop_cnt = start_cnt;
}

void HRTIMER::Start() {
	QueryPerformanceCounter(&start_cnt);
}

double HRTIMER::Stop() {
	QueryPerformanceCounter(&stop_cnt);
	
	return (double(stop_cnt.QuadPart - start_cnt.QuadPart)*invPCFreq);
}

double HRTIMER::StopStart() {
	double deltaTime = Stop();
	
	start_cnt = stop_cnt;
	
	return (deltaTime);
}
#endif


#if defined _LINUX_HRTIMER_
HRTIMER::HRTIMER() {}

void HRTIMER::Start() {
	clock_gettime(CLOCK_MONOTONIC, &start_t);
}

double HRTIMER::Stop() {
	clock_gettime(CLOCK_MONOTONIC, &stop_t);
	return (double(stop_t.tv_sec - start_t.tv_sec) + (stop_t.tv_nsec - start_t.tv_nsec)*1e-9);
}

double HRTIMER::StopStart() {
	double deltaTime = Stop();
	
	start_t = stop_t;
	
	return (deltaTime);
}
#endif
