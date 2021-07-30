#include <hash_table.h>
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <timer.h>

sigjmp_buf point;


static void handler(int sig, siginfo_t * dont_care, void * dont_care_either) {
   longjmp(point, 1);
}
void  *my_memset(void *b, int c, int len) {
  int           i;
  unsigned char *p = b;
  i = 0;
  while(len > 0)
    {
      *p = c;
      p++;
      len--;
    }
  return(b);
}
int main(void) {
    std_timer_t timer;
    init_std_timer_t(&timer);
    start(&timer);

    std_hash_table_t_node_t node;
    std_hash_table_t_node_t node_two;

    init_std_hash_table_t_node_t(&node, (void*) 65, "one");
    init_std_hash_table_t_node_t(&node_two, (void*) 12, "two");

    std_hash_table_t table;

    init_std_hash_table_t(&table);
    add_pair_to_std_hash_table_t(&table, &node);
    add_pair_to_std_hash_table_t(&table, &node_two);
    
    struct sigaction sa;

    my_memset(&sa, 0, sizeof(sigaction));

    sigemptyset(&sa.sa_mask);

    sa.sa_flags     = SA_NODEFER;
    sa.sa_sigaction = handler;

    sigaction(SIGSEGV, &sa, NULL); /* ignore whether it works or not */ 

    if (setjmp(point) == 0) {
	remove_elem_from_std_hash_table_t_at(&table, "two"); printf("remove successful :) \n");
    }
    else {
	printf("Rather unexpected error\n");
    }


    tick(&timer);
    printf("[Time Took (s)]: %f\n", timer.m_time_passed);
    return 0;
}

