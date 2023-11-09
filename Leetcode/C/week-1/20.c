#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s){
    int len = strlen(s);
    if (len % 2 != 0){
        return false;
    }
    char* stack = malloc(len * sizeof(char));
    int top = -1;
    for (int i = 0; i < len; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++top] = s[i];
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if (top == -1){
                return false;
            }
            if (s[i] == ')' && stack[top] != '('){
                return false;
            }
            if (s[i] == ']' && stack[top] != '['){
                return false;
            }
            if (s[i] == '}' && stack[top] != '{'){
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

int main(int argc, char** argv){
    if (argc != 2){
        printf("Usage : ./20 arg1\n");
        return EXIT_FAILURE;
    }
    bool flag = isValid(argv[1]);
    printf(flag ? "true\n" : "false\n");
    return EXIT_SUCCESS;
}