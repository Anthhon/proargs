# ProArgs

ProArgs is a lightweight single-header library written in C for parsing command-line arguments. It provides a simple interface for checking the presence of specific arguments in the command-line input without getting in your way.

## Features

- Supports parsing of long and short arguments prefixed with `-` or `--`.
- Provides an intuitive interface for checking argument presence.
- Easy to integrate into existing C projects.

## Usage

To use ProArgs in your project, simply include the `proargs.h` header file in your project folder and link it with your source code.

```c
#include "proargs.h"
```

## Example

```c
#include <stdio.h>
#include "proargs.h"

int main(int argc, char *argv[]) {
    int verbose_flag = 0;

    if (argc < 2) {
        printf("Usage: %s <argument>\n", argv[0]);
        return 1;
    }

    if (pa_arg_check(argv[1], "verbose", PA_LONG_ARG)) {
        verbose_flag = 1;
        printf("Verbose mode enabled.\n");
    }

    return 0;
}
```

In this example, the program checks if the command-line argument is `--verbose`, indicating that verbose mode should be enabled.

## License

This library is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details. Feel free to customize it further to better fit your project's needs or to send improvements PR's!
