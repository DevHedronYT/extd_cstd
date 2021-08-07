#include <stdlib.h>
#include <str.h>
#include <stdio.h>

i32 std_str_length(const str str_one) {
    i32 len;
    for (len = 0; str_one[len] != '\0'; len++);
    return len;
}

i32 std_str_compare(const str str_one, const str str_two) {
    if (std_str_length(str_one) != std_str_length(str_two)) {
        return 0;
    }
    
    i32 i = 0;
    i32 flag = 0;

    while (str_one[i] != '\0' && str_two[i] != '\0') {
        if (str_one[i] != str_two[i]) {
            flag = 1;
            break;
        }

        i++;
    }

    if (flag == 0 && str_one[i] == '\0' && str_two[i] == '\0') {
        return 1;
    }

    else {
        return 0;
    }
} 

str std_str_concat (const str str_one, const str str_two) {    
    i32 size_str_one = std_str_length(str_one);
    i32 size_str_two = std_str_length(str_two);
    str new_char = (str) malloc(size_str_one + size_str_two + 1);
    
    for (i32 i = 0; i < size_str_one; i++) {
        new_char[i] = str_one[i];
    }

    for (i32 i = 0; i < size_str_two; i++) {
        new_char[i + size_str_one] = str_two[i];
    }

    return new_char;
}

i32 std_str_starts_with(const str str_one, const str str_two) {
    i32 len = std_str_length(str_two);
    i32 flag = 0;

    for (i32 i = 0; i < len; i++) {
        if (str_one[i] != str_two[i]) {
            flag = 0;
            break;
        }
    }

    if (flag == 0) return 1;
    return 0;
}

str std_str_reverse(str str_one) {
    i32 len = std_str_length(str_one) - 1;
    str new_char = (str) malloc(len + 1); 
    
    for (i32 i = 0; i < std_str_length(str_one); i++) {
        new_char[i] = str_one[len - i];
    }

    return new_char;
}

i32 std_str_ends_with(str str_one, str str_two) {
    str new_str = std_str_reverse(str_one);
    str new_str_o = std_str_reverse(str_two);

    return std_str_starts_with(new_str, new_str_o);
}

i32 std_str_substring(const str str_one, const str str_two) {
    i32 i = 0;
    i32 j = 0;

    while (str_one[j] != '\0' && str_two[i] != '\0') {
        if (str_two[i] != str_one[j]) {
            j++;
            i = 0;
        }

        else {
            i++;
            j++;
        }
    }

    if (str_two[i] == '\0') {
        return 1;
    }

    else {
        return 0;
    }
}

str std_str_split(const str str_one, chr c) {
    str new_char = (str) malloc(std_str_length(str_one));

    for (i32 i = 0; i < std_str_length(str_one); i++) {
        if (str_one[i] == c) {
            break;
        }

        new_char[i] = str_one[i];
    }

    return new_char;
}

str std_i32_to_str(i32 num) {
    str string = (str) malloc(41); 
    snprintf(string, 39, "%d", num); 
    string[40] = '\0';
    return string;
}

// From: https://github.com/TheAlgorithms/C
i32 std_str_to_i32(char * string) {
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
