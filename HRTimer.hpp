/*
 *	$Id:$
 *
 *		Contains definition of high resolution timer class
 *
 */

#ifndef _HRTIMER_HPP_
#define _HRTIMER_HPP_

#if defined(_MSC_VER) || defined(WIN32)  || defined(_WIN32) || defined(__WIN32__) \
    || defined(WIN64)    || defined(_WIN64) || defined(__WIN64__) 
	#define _WIN_HRTIMER_
	#include <windows.h>
#endif

#if defined(unix)        || defined(__unix)      || defined(__unix__) \
    || defined(linux)       || defined(__linux)     || defined(__linux__) \
    || defined(sun)         || defined(__sun) \
    || defined(BSD)         || defined(__OpenBSD__) || defined(__NetBSD__) \
    || defined(__FreeBSD__) || defined __DragonFly__ \
    || defined(sgi)         || defined(__sgi) \
    || defined(__MACOSX__)  || defined(__APPLE__) \
    || defined(__CYGWIN__) 
	#define _LINUX_HRTIMER_
	#include <time.h>
#endif

class HRTIMER {
public:
	// starts the timer
	void Start(void);
	
	// returns time since start last called in seconds
	double Stop(void);
	
	// returns time since start last called in seconds, and restarts timer
	double StopStart(void);


	HRTIMER();
	~HRTIMER() {}

private:
#if defined _WIN_HRTIMER_
	double invPCFreq;
	LARGE_INTEGER start_cnt, stop_cnt;
#endif

#if defined _LINUX_HRTIMER_
	struct timespec start_t, stop_t;
#endif
}; // HRTIMER

#endif
