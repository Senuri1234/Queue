#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue structure definition
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1; // Return -1 if queue is empty
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Queue is empty after dequeue
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return value;
}

// Function to peek at the front element of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 if queue is empty
    }
    return queue->arr[queue->front];
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue->arr[queue->rear]);
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Queue elements: ");
    display(&queue);

    printf("Front element is %d\n", peek(&queue));

    printf("Dequeued element is %d\n", dequeue(&queue));

    printf("Queue elements after dequeue: ");
    display(&queue);

    return 0;
}

