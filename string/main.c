#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

my_atoi (char *PassStr) {
    int i;
    int number = 0;
    for (i= 0; PassStr[i] == ' '; i++) {}
    while ((47<PassStr[i])&&(PassStr[i]<58)&&(PassStr != '\n')) {
        number = number*10 + (PassStr[i] - 48);
        i++;
    }
    return number;
}

char *my_itoa( int value, char * string, int radix ) {
    char alphabet[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    int leng = 0;
    int part;
    char unconvertedString[MAX_LENGTH];
    while (value != 0 ) {
        part = value % radix;
        value = value / radix;
        unconvertedString[leng] = alphabet[part];
        leng++;
    }
    int i;
    for (i = 0; i < leng; i++ ) {
        string[i] = unconvertedString[leng - 1 - i];
    }
    string[i] = '\0';
    return string;
}

size_t my_strlen( const char * string ) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

char * my_strcat( char* destptr, const char * srcptr ) {
    int i, leng_dest, leng_src;
    leng_dest = my_strlen(destptr);
    leng_src = my_strlen(srcptr);
    for (i = leng_dest; i < leng_dest+leng_src; i++) {
        destptr[i] = srcptr[i - leng_dest];
    }
    destptr[i] = '\0';
    return destptr;
}

int my_strcmp( const char * string1, const char * string2 ) {
    int code = 0;
    int i = 0;
    while ((i < my_strlen(string1))&&(i < my_strlen(string2))) {
        if (string1[i] < string2[i]) {
            code = -i;
            break;
        }
        if (string1[i] > string2[i]) {
            code = i;
            break;
        }
    i++;
    }
    return code;
}
char * my_strstr( const char * string1, const char * string2 ) {
    int i;
    int code;
    for (i = 0; i < my_strlen(string1); i++) {
        int j = 0;
        code = i;
        while ((i+j < my_strlen(string1))&&(j < my_strlen(string2))) {
            if (string1[i+j] != string2[j]) {
                code = -1;
                break;
            }
        j++;
        }
        if (code != -1) {
            break;
        }
    }
    if ( code == -1 ) {
        return NULL;
    } else {
        return &string1[code];
    }
}
char * my_strcpy( char * destptr, const char * srcptr ) {
    int i, leng_src;
    leng_src = my_strlen(srcptr);
    for (i = 0; i < leng_src; i++) {
        destptr[i] = srcptr[i];
    }
    destptr[i] = '\0';
    return destptr;
}

int main()
{
    char str[MAX_LENGTH];
    char letter = getchar();
    int length = 0;
    char string[MAX_LENGTH];
    while (letter != '\n') {
        str[length] = letter;
        length++;
        letter = getchar();
    }
    str[length] = '\0';
    printf("itoa:\t %s\n", my_itoa(1234, string, 8));
    printf("atoi:\t %i\n", my_atoi(str));
    printf("strlen:\t %i\n", my_strlen(str));

    char str1[30] = {'1','2','1','2','3','4'};
    printf("strcmp:\t %i\n", my_strcmp(str1,str));
    printf("strstr:\t %i\n", my_strstr(str1,str));
    printf("strcat:\t %s\n", my_strcat(str,str));
    printf("strcpy:\t %s\n", my_strcpy(str,str1));

    return 0;
}
