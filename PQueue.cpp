/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */

#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */


/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	struct node* pushNode = (struct node*)malloc(sizeof(struct node));
	pushNode = front;
	while(priority > 1){
		pushNode = this -> front -> link;
		priority--;
	}
	pushNode -> data = item;
	pushNode -> priority = priority;
	/* Your code here */
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if(front != NULL){
		struct node* temp;
		temp = this -> front;
		while(temp -> priority != 1){
			temp = temp -> link;
		}
		free(temp);
	}
	else{
		exit(EXIT_FAILURE);
	}
	/* Your code here */
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	struct node* temp;
	if(front == nullptr){
		exit(EXIT_FAILURE);
	}
	temp = front;
	front = temp -> link;
	free(temp);
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{
	/* Your code here */
	/* Use the following out command for the data */
	struct node* temp;
	if(front == NULL){
		printf("\ncan't print a null can you " );
		exit(1);
	}
	else{
		temp = front;
		while(temp != NULL){
			std::cout<<temp->priority<<" "<<(char*)temp->data<<std::endl;
			temp = temp -> link;
		}
	}
}
