#include <timer.h>
#include <time.h>

emp init_std_timer_t(std_timer_t * timer) {
    timer -> m_time_passed  = 0;
}

emp start(std_timer_t * timer) {
    timer -> m_last_time = clock();
}


emp tick(std_timer_t * timer) {
    timer -> m_time_passed =  (f64)(clock() - timer -> m_last_time) / CLOCKS_PER_SEC; 
}

