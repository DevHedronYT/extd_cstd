#include <stdlib.h>
#include <str.h>

int std_str_length(const str str_one) {
    int len;
    for (len = 0; str_one[len] != '\0'; len++);
    return len;
}

int std_str_compare(const str str_one, const str str_two) {
    if (std_str_length(str_one) != std_str_length(str_two)) {
        return 0;
    }
    
    int i = 0;
    int flag = 0;

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
    int size_str_one = std_str_length(str_one);
    int size_str_two = std_str_length(str_two);
    str new_char = (str) malloc(size_str_one + size_str_two + 1);
    
    for (int i = 0; i < size_str_one; i++) {
	new_char[i] = str_one[i];
    }

    for (int i = 0; i < size_str_two; i++) {
	new_char[i + size_str_one] = str_two[i];
    }

    return new_char;
}

int std_str_starts_with(const str str_one, const str str_two) {
    int len = std_str_length(str_two);
    int flag = 0;

    for (int i = 0; i < len; i++) {
	if (str_one[i] != str_two[i]) {
	    flag = 0;
	    break;
	}
    }

    if (flag == 0) return 1;
    return 0;
}

str std_str_reverse(str str_one) {
    int len = std_str_length(str_one) - 1;
    str new_char = (str) malloc(len + 1); 
    
    for (int i = 0; i < std_str_length(str_one); i++) {
	new_char[i] = str_one[len - i];
    }

    return new_char;
}

int std_str_ends_with(str str_one, str str_two) {
    str new_str = std_str_reverse(str_one);
    str new_str_o = std_str_reverse(str_two);

    return std_str_starts_with(new_str, new_str_o);
}

int std_str_substring(const str str_one, const str str_two) {
    int i = 0;
    int j = 0;

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

str std_str_split(const char * str_one, char c) {
    str new_char = (str) malloc(std_str_length(str_one));

    for (int i = 0; i < std_str_length(str_one); i++) {
	if (str_one[i] == c) {
	    break;
	}

	new_char[i] = str_one[i];
    }

    return new_char;
}
