#include <prof.h>
#include <time.h>
#include <str.h>

clock_t time_start;
clock_t time_end;

emp_t start_profiling(prof_t * profiler, str_t name) {
    profiler -> name = name;
    profiler -> elapsed = 0.0f;
    time_start = clock();
}

emp_t end_profiling(prof_t * profiler) {
    time_end = clock();
    profiler -> elapsed = (f64_t)(time_end - time_start) / CLOCKS_PER_SEC;
    str_t number = f64_to_str(profiler -> elapsed); 
    str_t stats = "TIME TOOK FOR ";
    str_t concat_stats = str_concat(stats, profiler -> name);
    str_t concat_stats_sp = str_concat(concat_stats, ": ");
    str_t concatted_final = str_concat(concat_stats_sp, number);
    str_t concatted_finale = str_concat(concatted_final, "s");
    
    profiler -> elapsed_string = concatted_finale; 
}
