#include <str.h>
#include <stdio.h>
#include <prof.h>

int main(void) {
    prof_t timer;
    start_profiling(&timer, "main");

    str_t string = "n";
    str_t string2 = "n";

    int len = str_length(string);
    printf("%d\n", len);


    int cmp = str_compare(string, string2);
    printf("%d\n", cmp);

    str_t str3 = str_concat(string, string2);
    printf("%s\n", str3);

    str_t str4 = "works_nrdy_bhu1";
    str_t str5 = str_reverse(str4);
    printf("%s\n", str5);

    str_t str6 = "lol works_nrdy_bhu1";
    printf("n: %d\n", str_ends_with(str6, str4));
    printf("n: %d\n", str_substring(str6, str4));
    str_t n = str_split(str6, ' ');
    printf("%s\n", n);

    end_profiling(&timer);
    printf("%s\n", timer.elapsed_string);
}

