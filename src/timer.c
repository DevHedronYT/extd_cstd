#include <timer.h>
#include <time.h>

void init_std_timer_t(std_timer_t * timer) {
    timer -> m_time_passed  = 0;
}

void start(std_timer_t * timer) {
    timer -> m_last_time = clock();
}


void tick(std_timer_t * timer) {
    timer -> m_time_passed =  (double)(clock() - timer -> m_last_time) / CLOCKS_PER_SEC; 
}

