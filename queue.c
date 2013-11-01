#include <string.h>
#include "queue.h"

#define QUEUE_MAX_SIZE 10

static person queue[QUEUE_MAX_SIZE];
static int head = 0, tail = 0, nbr_elem = 0;

/*
 * Enqueues a person and copies the strings
 * to the person array. 
 */
void enqueue(person personIn){
    nbr_elem++;//Increment number of elements
    strcpy(queue[tail].first_name,personIn.first_name);
    strcpy(queue[tail].last_name,personIn.last_name);
    strcpy(queue[tail].pers_nr,personIn.pers_nr);
    /*Check if the tail is at the end of the queue
     * If tail position is the same as queue size it will
     * reset to position zero of the queue*/
    tail = (tail+1) % QUEUE_MAX_SIZE;
    
    //printf("%d MODULUS RESULTAT\n",tail);
}

/*
 * Dequeues the oldest person from the queue and
 * moves the head of the que to the next object
 */
void dequeue(person *personIn){
    nbr_elem--;//Decrement number of elements
    strcpy(personIn->first_name,queue[head].first_name);
    strcpy(personIn->last_name,queue[head].last_name);
    strcpy(personIn->pers_nr,queue[head].pers_nr); 
    
    head = (head+1) % QUEUE_MAX_SIZE;//Checks if the head is att the end
}

/*
 * Gets specified person and handles the indexing.
 * Makes sure index is correct and stays within the
 * queue indexboundaries.
 */
void get_person(person *personIn, int personIndex){
    int index = personIndex + head;
    if(index >= QUEUE_MAX_SIZE){
        //printf("%d is the current head+pInd, over max\n", index);
        index = (head + personIndex) - QUEUE_MAX_SIZE;    
        //printf("Ny head plus pind:%d\n", index);
    }
    else{
        //printf("%d is the current head+pInd\n", index);
    }
    strcpy(personIn->first_name, queue[index].first_name);
    strcpy(personIn->last_name, queue[index].last_name);
    strcpy(personIn->pers_nr, queue[index].pers_nr);
}
//Returns amount of persons in the queue
int get_number_of_pers(){
    return nbr_elem;
}
//Returns yes or no depending on if the queue is empty
int empty(){
    if(nbr_elem == 0){
        return 1;
    }
    else
        return 0;
}
//Returns yes or no depending on if the queue is full
int full(){
    if(nbr_elem == QUEUE_MAX_SIZE){
        return 1;
    }
    else
        return 0;
}