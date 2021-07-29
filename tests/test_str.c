#include <str.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start_time = clock();

    str string = "n";
    str string2 = "n";

    int len = std_str_length(string);
    printf("%d\n", len);


    int cmp = std_str_compare(string, string2);
    printf("%d\n", cmp);

    str str3 = std_str_concat(string, string2);
    printf("%s\n", str3);

    str str4 = "works_nrdy_bhu1";
    str str5 = std_str_reverse(str4);
    printf("%s\n", str5);

    str str6 = "lol works_nrdy_bhu1";
    printf("n: %d\n", std_str_ends_with(str6, str4));
    printf("n: %d\n", std_str_substring(str6, str4));
    str n = std_str_split(str6, ' ');
    printf("%s\n", n);

    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsed_time);
}

