#include <unistd.h>

void put_nbr(int nbr) {
    char digits[20];
    int i = 0;
    char *hex = "0123456789abcdef";
    
    // Handle negative numbers
    unsigned int num;
    if (nbr < 0) {
        write(1, "-", 1);
        num = -nbr;
    } else {
        num = nbr;
    }
    
    // Handle 0 case
    if (num == 0) {
        write(1, "0", 1);
        return;
    }
    
    // Convert to hex digits in reverse order
    while (num > 0) {
        digits[i++] = hex[num % 16];
        num /= 16;
    }
    
    // Print digits in correct order
    while (i > 0) {
        write(1, &digits[--i], 1);
    }
}

int ft_atoi(char *av) {
    int i = 0;
    int result = 0;
    int sign = 1;  // Changed initial sign to 1
    
    // Skip whitespace
    while (av[i] == ' ') 
        i++;
    
    // Handle sign
    if (av[i] == '-' || av[i] == '+') {
        if (av[i] == '-') 
            sign = -1;
        i++;
    }
    
    // Build number
    while (av[i] >= '0' && av[i] <= '9') {
        result = result * 10 + (av[i] - '0');
        i++;
    }
    
    return sign * result;
}

int main(int argc, char **argv) {
    if (argc == 2)
        put_nbr(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return 0;
}
