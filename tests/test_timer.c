#include <timer.h>
#include <util.h>

int main(void) {
    
    std_timer_t timer;
    init_std_timer_t(&timer);

    start(&timer);

    for (int i = 0; i < 10000; i++) {
        tick(&timer);
    }

    std_print_n("%f\n", timer.m_time_passed);

}
