#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_empty(char* s){
    return (strlen(s) != 0);
}

int belongInIndex(char* word, int size, char c){
    if (is_empty(word)) return -1;
    printf("belongInIndex : Word not Empty");
    for (int i = 0; i < size; i++){
        printf("Comparaison entre %s et %sèil:ç ;i,un", word[i], c);
        if (word[i] == c) return i;
    }
    return -1;
}

char* refactorList(char* list, int size, int indexToDelete){
    char* ret;
    for (int i = 0; i < size; i++){
        if (i != indexToDelete){
            ret[i] = list[i];
        }
    }
    return ret;
}

bool canConstruct(char* ransomNote, char* magazine) {
    if (strlen(ransomNote) == strlen(magazine) && strcmp(ransomNote, magazine) != 0) return false;
    int ransomSize = strlen(ransomNote), magazineSize = strlen(magazine);
    for (int i = 0; i < magazineSize; i++){
        char* refactorRansom = ransomNote;
        int sizeTmp = ransomSize;
        int tmp = i;
        int indexToDelete = belongInIndex(refactorRansom, sizeTmp, magazine[tmp]);
        printf("%d-ème occurence de la main boucle, res : %d\n", i, indexToDelete);
        while(indexToDelete != -1){
            refactorRansom = refactorList(refactorRansom, sizeTmp-1, indexToDelete);
            if (is_empty(refactorRansom)) return true;
            else if (tmp+1 == magazineSize) return false;
            
            sizeTmp--;
            tmp++;
            indexToDelete = belongInIndex(refactorRansom, sizeTmp, magazine[tmp]);
        }
    }
    return false;
}

int main(int argc, char** argv){
    char* ransomNote = argv[1];
    char* magazine = argv[2];
    printf("%s", canConstruct(ransomNote, magazine) ? "true\n" : "false\n");
    return EXIT_SUCCESS;
}