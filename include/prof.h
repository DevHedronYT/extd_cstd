#ifndef _PROF_H 
    
    #define _PROF_H

    #include "./types.h"

    typedef struct {
        str_t name;
        f64_t elapsed;
        str_t elapsed_string;
    } prof_t;
    
    emp_t start_profiling(prof_t * profiler, str_t name);
    emp_t end_profiling  (prof_t * profiler);


#endif
