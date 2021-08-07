#ifndef _C_STD_TIMER
    
    #define _C_STD_TIMER

    #include <types.h>
    #include <time.h>

    typedef struct {
        f64     m_time_passed;
        clock_t m_last_time;
    } std_timer_t;
    
    emp init_std_timer_t(std_timer_t * timer);
    emp start           (std_timer_t * timer);
    emp tick            (std_timer_t * timer);

#endif
