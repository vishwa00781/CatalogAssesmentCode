#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to decode a number from a given base
int decode_value(int base, const char *value) {
    return (int)strtol(value, NULL, base);
}

// Function to perform Lagrange interpolation to find the polynomial at x=0
double lagrange_interpolation(int *x_values, int *y_values, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y_values[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (0 - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Sample JSON data
    // In practice, you would read this from a file
    const char *json_data = "{"
                            "\"keys\": {"
                            "\"n\": 4,"
                            "\"k\": 3"
                            "},"
                            "\"1\": {"
                            "\"base\": \"10\","
                            "\"value\": \"4\""
                            "},"
                            "\"2\": {"
                            "\"base\": \"2\","
                            "\"value\": \"111\""
                            "},"
                            "\"3\": {"
                            "\"base\": \"10\","
                            "\"value\": \"12\""
                            "},"
                            "\"6\": {"
                            "\"base\": \"4\","
                            "\"value\": \"213\""
                            "}"
                            "}";

    // Variables to store x and y values
    int x_values[4], y_values[4];
    int n = 0; // Count of roots

    // Simulate JSON parsing
    // Note: This is a simplified approach; for full JSON parsing, use a library like cJSON
    char *key;
    char base[3], value[10];
    
    // Manual parsing of the hardcoded JSON data
    sscanf(json_data, "{\"keys\": {\"n\": %d,\"k\": %*d},", &n);

    // Example: Manually extracting the values (this part would ideally be replaced by a JSON library)
    x_values[0] = 1; strcpy(base, "10"); strcpy(value, "4");
    y_values[0] = decode_value(10, value);

    x_values[1] = 2; strcpy(base, "2"); strcpy(value, "111");
    y_values[1] = decode_value(2, value);

    x_values[2] = 3; strcpy(base, "10"); strcpy(value, "12");
    y_values[2] = decode_value(10, value);

    x_values[3] = 6; strcpy(base, "4"); strcpy(value, "213");
    y_values[3] = decode_value(4, value);

    // Calculate the constant term c (f(0))
    double c = lagrange_interpolation(x_values, y_values, n);

    // Output the result
    printf("The constant term c is: %.2f\n", c);

    return 0;
}
