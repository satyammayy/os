#include <stdio.h>
#include <stdlib.h>

int mutex = 1;   
int full = 0;     
int empty = 3;  
int itemCount = 0; 

void producer();
void consumer();
int wait(int);
int signal(int);
int main() {
    int choice;
    printf("\n1. Producer\n2. Consumer\n3. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!!");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!!");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.");
        }
    }
    return 0;
}
int wait(int semaphore) {
    return (--semaphore);
}
int signal(int semaphore) {
    return (++semaphore);
}
void producer() {
    mutex = wait(mutex); 
    full = signal(full); 
    empty = wait(empty); 
    itemCount++;
    printf("\nProducer produces item %d", itemCount);
    mutex = signal(mutex); 
}
void consumer() {
    mutex = wait(mutex); 
    full = wait(full); 
    empty = signal(empty); 
    printf("\nConsumer consumes item %d", itemCount);
    itemCount--; 
    mutex = signal(mutex); 
}
