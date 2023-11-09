#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Initialize a queue data structure
typedef struct {
    int* data;
    int front, rear, size;
    unsigned int capacity;
} MyQueue;

//Create and allocate memory for a queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100;
    queue->data = (int*)malloc(sizeof(int) * queue->capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

//Add an element to the queue (push)
void myQueuePush(MyQueue* obj, int x) {
    if (obj->size == obj->capacity){
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
    }
    obj->rear = (obj->rear+1) % obj->capacity;
    obj->data[obj->rear] = x;
    obj->size = obj->size+1;
}

//Get the front element (peek)
int myQueuePeek(MyQueue* obj) {
    return obj->data[obj->front];
}

//Check if the queue is empty and return true if it is empty, false otherwise
bool myQueueEmpty(MyQueue* obj) {
    return (obj->size == 0); 
}

//Remove an element from the queue (pop)
int myQueuePop(MyQueue* obj) {
    if (myQueueEmpty(obj)) return EXIT_FAILURE;
    int ret = obj->data[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size = obj->size-1;
    return ret;
}

//Pop all the elements from the queue and free the memory
void myQueueFree(MyQueue* obj) {
    if (obj->data != NULL) free(obj->data);
    if (obj != NULL) free(obj);
}