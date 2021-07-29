#include <hash_table.h>
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

sigjmp_buf point;

static void handler(int sig, siginfo_t * dont_care, void * dont_care_either) {
   longjmp(point, 1);
}

int main(void) {
    std_hash_table_t_node_t node;
    std_hash_table_t_node_t node_two;

    init_std_hash_table_t_node_t(&node, (void*) 65, "one");
    init_std_hash_table_t_node_t(&node_two, (void*) 12, "two");

    std_hash_table_t table;

    init_std_hash_table_t(&table);
    add_pair_to_std_hash_table_t(&table, &node);
    add_pair_to_std_hash_table_t(&table, &node_two);
    

    struct sigaction sa;

    memset(&sa, 0, sizeof(sigaction));
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

    return 0;
}

