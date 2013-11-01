/* 
 * File:   menu.h
 * Author: Per
 *
 * Created on den 30 oktober 2013, 16.05
 */
#include <stdio.h>
#include "queue.h"

person queueHolder;
void show_menu(){
    printf("***Queue menu***\n"
            "1. Add a person to the queue\n" 
            "2. Remove person from queue\n"
            "3. Print queue\n"
            "4. Exit\n");
}

int get_selection(){
    int select;
    scanf("%d", &select);
    return select;
}

void run_selection(int getVal){
    switch(getVal){
        case 1:
            add_to_queue();
            break;
        case 2:
            remove_from_queue();
            break;
        case 3:
            print_queue();
            break;
        case 4:
            exit(0);                
    }
}

int pause(){
    int c;
    printf("\n\nPress enter to continue...");
    /*Tömmer inmatningsströmmen*/
    while((c=getchar())!= '\n' && c != EOF);
    getchar();
    return 1;
}

/*
 * If the queue isn't full the program receives
 * person input and puts it in the queue at 
 * the tail index.*/
void add_to_queue(){
    if(!full()){
        printf("Enter first name:");
        scanf("%s",&queueHolder.first_name);
        printf("Enter last name:");
        scanf("%s",&queueHolder.last_name);
        printf("Enter social security number:");
        scanf("%s",&queueHolder.pers_nr);
        enqueue(queueHolder);
        printf("%d elements in list", get_number_of_pers());
    }
    else{
        printf("Queue is full");
    }
}

/*
 * If the queue isn't empty the program
 * removes the oldest object by
 * calling dequeue. The removed person info
 * is printed in the console
 */
void remove_from_queue(){
    if(!empty()){
        dequeue(&queueHolder);
        printf("Removed person:");
        printf("%s, %s\n", queueHolder.first_name, queueHolder.last_name);
        printf("Social security number: %s", queueHolder.pers_nr);
    }
    else{
        printf("Queue is empty.");
    }
}

/*
 * Prints all persons in the current queue
 */
void print_queue(){
    if(!empty()){
        int i = 0;
        int items = get_number_of_pers();
        for(i = 0; i<items;i++){
            get_person(&queueHolder, i);
            printf("\nPerson at index %d:\n", i);
            printf("%s, %s\n", queueHolder.first_name, queueHolder.last_name);
            printf("Social security number: %s\n", queueHolder.pers_nr);
        }
    }
    else{
        printf("Queue is empty.");
        }
}
