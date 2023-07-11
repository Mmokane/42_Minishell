char* getEnvVariable(const char* input) {
    const char* dollarSign = strchr(input, '$'); // Find the first occurrence of '$' in the input
    if (dollarSign == NULL) {
        return NULL; // Return NULL if no dollar sign found
    }

    const char* variableStart = dollarSign + 1; // Get the position right after the dollar sign
    const char* variableEnd = strpbrk(variableStart, " \t\n$"); // Find the next space, tab, newline, or dollar sign

    size_t variableLength = variableEnd - variableStart; // Calculate the length of the variable name
    char* variable = malloc(variableLength + 1); // Allocate memory for the variable string
    strncpy(variable, variableStart, variableLength); // Copy the variable name to the allocated memory
    variable[variableLength] = '\0'; // Null-terminate the variable string

    char* envValue = getenv(variable); // Retrieve the environment variable value
    free(variable); // Free the allocated memory for the variable string

    if (envValue == NULL) {
        return NULL; // Return NULL if the environment variable does not exist
    }

    return strdup(envValue); // Duplicate and return the environment variable value
}
