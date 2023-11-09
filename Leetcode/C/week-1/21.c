#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL && list2 == NULL) return NULL;
    else if (list1 == NULL) return list2; 
    else if (list2 == NULL) return list1;

    struct ListNode *start = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *end = start;

    //Reading the parameters
    while(list1 != NULL || list2 != NULL){
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));

        if (list1 == NULL) {
            node->val = list2->val;
            list2=list2->next;
        } else if (list2 == NULL) {
            node->val = list1->val;
            list1=list1->next;
        } else if(list1->val<list2->val){
            node->val=list1->val;
            list1 = list1->next;
        }else{
            node->val=list2->val;
            list2=list2->next;
        }
        node->next = NULL;
        end = end->next = node;
    }
    end = start->next;
    free(start);

    //Return the result
    return end;
}