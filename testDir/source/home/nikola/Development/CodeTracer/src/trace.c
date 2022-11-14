#include <stdio.h>
#include <stdint.h>
#include <string.h>
// #include <time.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// static int trace_file = -1;

// #define MAX 1000000

#define MAX_STACK_SIZE 1048576

int64_t codetracer_id;
int64_t codetracer_id_stack[MAX_STACK_SIZE];
int codetracer_stack_index;
// program

__attribute__((no_instrument_function))
void __attribute__ ((constructor))
trace_begin (void)
{
    memset(codetracer_id_stack , 0, MAX_STACK_SIZE * sizeof(int64_t));
    codetracer_id = -1;
    codetracer_stack_index = -1;
}


 __attribute__((no_instrument_function))
void __attribute__ ((destructor))
trace_end (void)
{
}

__attribute__((no_instrument_function))
void __cyg_profile_func_enter (void *fn, void *call_site) {
    codetracer_id += 1;
    codetracer_stack_index += 1;
    if (codetracer_stack_index < MAX_STACK_SIZE) {
        codetracer_id_stack[codetracer_stack_index] = codetracer_id;
        // printf("> enter %p %d %ld %ld\n", fn, codetracer_stack_index, codetracer_id, codetracer_id_stack[codetracer_stack_index]);
    }
}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit (void *fn, void *call_site) {
    // assume codetracer_stack_index > 0 except in exit from entry call
    // printf("> exit %p %ld\n", fn, codetracer_id);
    codetracer_stack_index -= 1;
}
