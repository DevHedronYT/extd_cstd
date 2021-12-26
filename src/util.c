#include <stdio.h>
#include <util.h>
#include <stdarg.h>
#include <time.h>

time_t current_time;
struct tm * m_time; 

void print(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        vfprintf(stdout, fmt, args);
    va_end(args);
}

void print_n(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        vfprintf(stdout, fmt, args);
        printf("\n");
    va_end(args);
}


void print_t(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        print_n(fmt, args); 
    va_end(args);
}

void print_i(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("%s", GREEN); 
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        printf("[INFO]: ");
        print(fmt, args);
        printf("%s", DEFAULT); 
        printf("\n"); 
    
    va_end(args);
} 


void print_e(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("%s", RED); 
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        printf("[ERROR]: ");
        print(fmt, args);
        printf("%s", DEFAULT); 
        printf("\n"); 
    
    va_end(args);
} 

void print_w(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("%s", YELLOW); 
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        printf("[WARNING]: ");
        print(fmt, args);
        printf("%s", DEFAULT); 
        printf("\n"); 
    
    va_end(args);
}

void print_fe(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("%s", BOLD); 
        printf("%s", RED); 
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        printf("[FATAL ERROR]: ");
        print(fmt, args);
        printf("%s", DEFAULT); 
        printf("\n"); 
    
    va_end(args);   
}

void print_s(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        time(&current_time);
        m_time = localtime(&current_time);
        printf("%s", UNDERLINE); 
        printf("%s", BLUE); 
        printf("[%d/%d/%d -> %d:%d]: ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min); 
        printf("[IMPORTANT]: ");
        print(fmt, args);
        printf("%s", DEFAULT); 
        printf("\n"); 
    
    va_end(args);   
}

