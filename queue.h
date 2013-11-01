/* 
 * File:   queue.h
 * Author: Per
 *
 * Created on den 30 oktober 2013, 13:36
 */

#ifndef QUEUE_H
#define	QUEUE_H

/*Custom datatype PERSON */
typedef struct{
    char first_name[20];
    char last_name[20];
    char pers_nr[12];
}person;

/*Prototypes*/
void enqueue(person personIn);
void dequeue(person *personIn);
void get_person(person *personIn, int personIndex);
int get_number_of_pers();
int empty();
int full();   
#endif	/* QUEUE_H */

