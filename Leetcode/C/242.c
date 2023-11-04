#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char* t){
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t){
        return false;
    }
    int hash[26] = {0};
    for (int i = 0; i < len_s; i++){
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++){
        if (hash[i] != 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv){
    
    if (argc != 3){
        printf("Usage : ./242 arg1 arg2\n");
        return EXIT_FAILURE;
    }
    bool flag = isAnagram(argv[1], argv[2]); 
    printf(flag ? "true\n" : "false\n");
    
    return EXIT_SUCCESS;
}