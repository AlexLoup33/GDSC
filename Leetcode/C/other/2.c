#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //Check if the parameters are valid
    if (l1 == NULL && l2 == NULL) return NULL;
    else if (l2 == NULL) return l1;
    else if (l1 == NULL) return l2;

    //Init the extern NodeList needed
    struct ListNode *start = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *end = start;
    bool retenue = false;

    //Reading the parameters
    while(l1 != NULL || l2 != NULL){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        int value = retenue;

        if (l1 != NULL) {
            value += l1->val;
            l1=l1->next;
        }
        if (l2 != NULL) {
            value += l2->val;
            l2=l2->next;
        }

        if (value >= 10){
            retenue = true;
            value -= 10;
        }else retenue = false;

        node->val = value;
        node->next = NULL;

        end = end->next = node;
    }
    if (retenue){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = retenue;
        node->next = NULL;
        end->next = node;
    }

    end = start->next;
    free(start);
    //Return the result
    return end;
}