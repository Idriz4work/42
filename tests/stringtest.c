int test1(void) {
    char ft_output[MAX_OUTPUT_SIZE] = {0};
    char orig_output[MAX_OUTPUT_SIZE] = {0};
    char s[] = "Za real zorila is here with a anotehr test.";
    
    // Capture ft_printf output
    FILE *ft_file = fmemopen(ft_output, sizeof(ft_output), "w");
    FILE *old_stdout = stdout;
    stdout = ft_file;
    ft_printf("%s", s);
    fflush(stdout);
    fclose(ft_file);
    stdout = old_stdout;
    
    // Capture printf output
    FILE *orig_file = fmemopen(orig_output, sizeof(orig_output), "w");
    stdout = orig_file;
    printf("%s", s);
    fflush(stdout);
    fclose(orig_file);
    stdout = old_stdout;
    
    // Compare outputs
    if (strcmp(ft_output, orig_output) == 0) {
        printf("------ TEST 1 passed -------\n\n");
        return 1;
    } else {
        printf("------ TEST 1 failed -------\n");
        printf("ft_printf output: [%s]\n", ft_output);
        printf("printf output: [%s]\n", orig_output);
        return 0;
    }
}

int test2(void) {
    char ft_output[MAX_OUTPUT_SIZE] = {0};
    char orig_output[MAX_OUTPUT_SIZE] = {0};
    char s[] = "\0";
    
    // Capture ft_printf output
    FILE *ft_file = fmemopen(ft_output, sizeof(ft_output), "w");
    FILE *old_stdout = stdout;
    stdout = ft_file;
    ft_printf("%s", s);
    fflush(stdout);
    fclose(ft_file);
    stdout = old_stdout;
    
    // Capture printf output
    FILE *orig_file = fmemopen(orig_output, sizeof(orig_output), "w");
    stdout = orig_file;
    printf("%s", s);
    fflush(stdout);
    fclose(orig_file);
    stdout = old_stdout;
    
    // Compare outputs
    if (strcmp(ft_output, orig_output) == 0) {
        printf("------ TEST 2 passed -------\n");
        return 1;
    } else {
        printf("------ TEST 2 failed -------\n");
        printf("ft_printf output: [%s]\n", ft_output);
        printf("printf output: [%s]\n", orig_output);
        return 0;
    }
}

#define MAX_OUTPUT_SIZE 1000

int main(void) {
    int total_tests = 2;
    int passed_tests = 0;
    
    passed_tests += test1();
    passed_tests += test2();
    
    printf("Summary: %d/%d tests passed\n", passed_tests, total_tests);
    return passed_tests == total_tests ? 0 : 1;
}