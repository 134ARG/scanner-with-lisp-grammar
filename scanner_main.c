//
// Created by xen134 on 28/3/2021.
// main scanner for source file
//

#include "scanner_main.h"
#include "spredicate.h"
#include "sscanner.h"
#include "stack.h"
#include <string.h>
#include <stdio.h>

extern struct stack token_names;
extern int lineno;

static void scan_error(const char *message) {
    printf("lineno: %d: Error while scanning source: %s\n", lineno, message);
    fprintf(stderr, "lineno: %d: Error while scanning source: %s\n", lineno, message);
}

// main routine for scanner
void scanner_main(const char *input, const char *output) {
    open_file(input);
    FILE *out_file = NULL;
    if (output) {
        out_file = fopen(output, "w");
    }
    char *s = next_unit();
    while(s != NULL) {
        size_t index = 0;
        while (index < strlen(s)) {
            size_t prev = index;
            int token_code = languagep(s, &index);  // find token id
            if (token_code != -1) {
                const char *token = get(&token_names, token_code);
                if (out_file)
                    fprintf(out_file, "%.*s: %s\n", (int) (index - prev), s + prev, token);
                else
                    printf("%.*s: %s\n", (int) (index - prev), s + prev, token);
            } else {    // token not found
                scan_error(s);
                scan_error("Such string doesn't match any pattern.");
                exit(1);
            }

        }
        free(s);
        s = next_unit();
    }
    if (out_file) fclose(out_file);
    clean_scan();
}
