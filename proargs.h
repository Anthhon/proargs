#ifndef PROARGS_H_
#define PROARGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef enum {
    PA_LONG_SHORT_ARG, // Long or short argument prefixed with '-' or '--'
    PA_LONG_ARG,       // Long argument prefixed with '--'
    PA_SHORT_ARG       // Short argument prefixed with '-'
} pa_args_t;

// Macro to retrieve the next element from
// the `argv` array and increment the iterator
#define pa_arg_val(argv, i) (argv)[++(i)]

// Function to check if a given input matches the specified argument type
int pa_arg_check(char *input, char argument[], pa_args_t type)
{
    // Check for null input
    if (!input || !argument) return -1;

    switch (type) {
        case PA_LONG_SHORT_ARG:
            // Check for argument prefixed with '--' or '-'
            if (input[0] == '-' && input[1] == '-') {
                return (strcmp(&input[2], argument) == 0);
            }
            else if (input[0] == '-' && strlen(&input[1]) == 1 ) {
                return (input[1] == argument[0]);
            }
            break;
        case PA_LONG_ARG:
            // Check for argument prefixed with '--'
            if (input[0] == '-' && input[1] == '-') {
                return (strcmp(&input[2], argument) == 0);
            }
            break;
        case PA_SHORT_ARG:
            // Check for argument prefixed with '-'
            if (input[0] == '-' && strlen(&input[1]) == 1) {
                return (input[1] == argument[0]);
            }
            break;
        default:
            // Error handling for invalid argument type
            fprintf(stderr, "pa_check_arg: Invalid argument type.\n");
            exit(EXIT_FAILURE);
    }
    
    return 0;
}

#endif // PROARGS_H_
