#include "custom_shell.h"

/**
 * shell_loop - The main loop for the custom shell.
 * @args: Array of command line arguments passed to the shell.
 */
void shell_loop(char **args) {
    ArgumentsInfo info = ARG_INFO_INIT;
    char *line = NULL;
    size_t bufsize = 0;

    if (!args) {
        print_error_message("Failed to allocate memory for arguments.");
        return;
    }

    // Read history from file, if any
    if (read_history_from_file(&info) == -1) {
        print_error_message("Failed to read command history.");
    }

    // Main shell loop
    while (1) {
        if (isatty(STDIN_FILENO)) {
            printf("custom-shell$ ");
        }

        if (get_input(&info) == -1) {
            break; // Handle end-of-file condition (Ctrl+D)
        }

        // Remove leading and trailing white spaces
        char *trimmed_line = string_starts_with(info.arg, " \t\n") ? info.arg + strspn(info.arg, " \t\n") : info.arg;

        if (trimmed_line[0] == '\0') {
            free(trimmed_line);
            continue; // Empty command, prompt again
        }

        if (execute_shell(&info, args) == -1) {
            print_error_message("Failed to execute the shell.");
        }

        if (isatty(STDIN_FILENO)) {
            free(trimmed_line);
        }
    }

    free_arguments_info(&info, 1);
    free(args);
    if (line) {
        free(line);
    }
}

