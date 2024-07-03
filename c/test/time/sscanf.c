#include <stdio.h>  
  
int main() {  
    char *test_strings[] = {"2024-07-13-12:00:01", "01:23:45", "23:59:59", "24:00:00", "1:2:3", "abc"};  
    for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {  
        int h, m, s;  
        if (sscanf(test_strings[i], "%2d:%2d:%2d", &h, &m, &s) &&  
            h < 24 && m < 60 && s < 60) {  
            printf("\"%s\" is a valid HHMMSS format\n", test_strings[i]);  
        } else {  
            printf("\"%s\" is NOT a valid HHMMSS format\n", test_strings[i]);  
        }  
		printf("h is %d, m is %d, s is %d\n", h, s, m);
    }  
  
    return 0;  
}
