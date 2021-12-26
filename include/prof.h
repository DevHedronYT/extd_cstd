#ifndef _PROF_H_ 
    #define _PROF_H_

    #include <types.h>

    typedef struct {
        char * name;
        f64 elapsed;
        char * elapsed_string;
    } prof_t;
    
    void start_profiling(prof_t * profiler, char * name);
    void end_profiling  (prof_t * profiler);


#endif
