#ifndef _C_STD_TIMER
    
    #define _C_STD_TIMER
 
    #include <time.h>

    typedef struct {
	double  m_time_passed;
	clock_t m_last_time;
    } std_timer_t;
    
    void init_std_timer_t(std_timer_t * timer);
    void start(std_timer_t * timer);
    void tick(std_timer_t * timer);

#endif
