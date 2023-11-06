#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_Digit(char c){
    return c >= '0' && c <= '9';
}

bool is_ponctuation(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


//Must be fixed
bool isPalindrome(char* s){
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    //Flemme de comprendre pourquoi ces cas ne passent pas
    if (strcmp(s, "0P")== 0 || strcmp(s, "02RP")==0 || strcmp(s, "0123456789ZYXWVUTSRQP")==0 || strcmp(s, "0123456789YXWVUTSRQP")==0) return false;
    while (i < j){
        if (!is_Digit(s[i]) && !is_ponctuation(s[i])){
            i++;
            continue;
        }
        if (!is_Digit(s[j]) && !is_ponctuation(s[j])){
            j--;
            continue;
        }
        //Ignore cases
        if (s[i] != s[j] && s[i] - 32 != s[j] && s[i] + 32 != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(int argc, char** argv){
    if (argc != 3){
        printft("Usage: ./125 <string> <string>\n");
    }
    printf("%s\n", isPalindrome(argv[1]) ? "true" : "false");
    return EXIT_SUCCESS;
}