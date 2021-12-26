#include <prof.h>
#include <time.h>
#include <str.h>

clock_t time_start;
clock_t time_end;

void start_profiling(prof_t * profiler, char * name) {
    profiler -> name = name;
    profiler -> elapsed = 0.0f;
    time_start = clock();
}

void end_profiling(prof_t * profiler) {
    time_end = clock();
    profiler -> elapsed = (f64)(time_end - time_start) / CLOCKS_PER_SEC;
    char * number = f64_to_str(profiler -> elapsed); 
    char * stats = "TIME TOOK FOR ";
    char * concat_stats = str_concat(stats, profiler -> name);
    char * concat_stats_sp = str_concat(concat_stats, ": ");
    char * concatted_final = str_concat(concat_stats_sp, number);
    char * concatted_finale = str_concat(concatted_final, "s");
    
    profiler -> elapsed_string = concatted_finale; 
}
