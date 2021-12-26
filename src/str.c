#include <stdlib.h>
#include <str.h>
#include <stdio.h>

i32 str_length(const char * str_one) {
    i32 len;
    for (len = 0; str_one[len] != '\0'; len++);
    return len;
}

i32 str_compare(const char * str_one, const char * str_second) {
    if (str_length(str_one) != str_length(str_second)) {
        return 0;
    }
    
    i32 i = 0;
    i32 flag = 0;

    while (str_one[i] != '\0' && str_second[i] != '\0') {
        if (str_one[i] != str_second[i]) {
            flag = 1;
            break;
        }

        i++;
    }

    if (flag == 0 && str_one[i] == '\0' && str_second[i] == '\0') {
        return 1;
    }

    else {
        return 0;
    }
} 
char * str_concat(const char * str_one, const char * str_second) {    
    i32 size_str_one = str_length(str_one);
    i32 size_str_second = str_length(str_second);
    char * new_char = malloc(size_str_one + size_str_second + 1);
    
    for (i32 i = 0; i < size_str_one; i++) {
        new_char[i] = str_one[i];
    }

    for (i32 i = 0; i < size_str_second; i++) {
        new_char[i + size_str_one] = str_second[i];
    }
    new_char[size_str_one + size_str_second] = '\0';

    return new_char;
}
i32 str_starts_with(const char * str_one, const char * str_second) {
    i32 len = str_length(str_second);
    i32 flag = 0;

    for (i32 i = 0; i < len; i++) {
        if (str_one[i] != str_second[i]) {
            flag = 0;
            break;
        }
    }

    if (flag == 0) return 1;
    return 0;
}
char * str_reverse(char * str_one) {
    i32 len = str_length(str_one) - 1;
    char * new_char = malloc(len + 1); 
    
    for (i32 i = 0; i < str_length(str_one); i++) {
        new_char[i] = str_one[len - i];
    }

    return new_char;
}
i32 str_ends_with(char * str_one, char * str_second) {
    char * new_str = str_reverse(str_one);
    char * new_str_o = str_reverse(str_second);

    return str_starts_with(new_str, new_str_o);
}
i32 str_substring(const char * str_one, const char * str_second) {
    i32 i = 0;
    i32 j = 0;

    while (str_one[j] != '\0' && str_second[i] != '\0') {
        if (str_second[i] != str_one[j]) {
            j++;
            i = 0;
        }

        else {
            i++;
            j++;
        }
    }

    if (str_second[i] == '\0') {
        return 1;
    }

    else {
        return 0;
    }
}
char * str_split(const char * str_one, char c) {
    char * new_char = malloc(str_length(str_one));

    for (i32 i = 0; i < str_length(str_one); i++) {
        if (str_one[i] == c) {
            break;
        }

        new_char[i] = str_one[i];
    }

    return new_char;
}
char * i32_to_str(i32 num) {
    char * string = malloc(41); 
    snprintf(string, 39, "%d", num); 
    string[40] = '\0';
    return string;
}
// From: https://github.com/TheAlgorithms/C
i32 str_to_i32(char * string) {
    int i;
    int sign;
    long value;
    long prev;

    i = 0;
    sign = 1;
    value = 0;

    while (((string[i] <= 13 && string[i] >= 9) || string[i] == 32) && string[i] != '\0')
        i++;

    if (string[i] == '-') {
        sign = -1;
	    i++;
	}

    else if (string[i] == '+') {
        sign = 1;
	    i++;
	}

    while (string[i] >= 48 && string[i] <= 57 && string[i] != '\0') {
        prev = value;
        value = value * 10 + sign * (string[i] - '0');

        if (sign == 1 && prev > value)
            return (-1);
        else if (sign == -1 && prev < value)
            return (0);
        i++;
    }
    return (value); 
}
char * f64_to_str(f64 num) {
    char * string = malloc(40); 
    snprintf(string, 39, "%f", num); 
    string[40] = '\0';
    return string;   
}

