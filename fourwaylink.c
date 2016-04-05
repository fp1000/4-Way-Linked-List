/*
 * fourwaylink.c
 *
 *  Created on: Oct 30, 2015
 *      Author: frankpultro
 */
#include <inttypes.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fourwaylink.h"

int numNodes = 0;

//Create a new node using malloc and return the pointer to it
NODE * CreateNode(int x, int y, int stat, char type){

  NODE * newnode;
  newnode = (NODE *) malloc (sizeof(NODE));
  if (newnode == NULL){
    printf ("No Memory left !!\n");
    return NULL;

  }
  newnode->row = x;
  newnode->col = y;
  newnode->status = stat; //var used for the game mode for which this code was made
  newnode->threatType = type; //var used for the game mode for which this code was made
  newnode->up=NULL;
  newnode->down=NULL;
  newnode->left=NULL;
  newnode->right=NULL;

  numNodes++;
  return newnode;
}

//Insert a new node (newdata) at the end of the linked list
void Insert(NODE **headPtr, NODE *newdata){
	NODE * curr;
	NODE * tempCurr;

		// Empty list
		if ((*headPtr) == NULL){
			// First item in list
			*headPtr = newdata;
			newdata->right = NULL;
		}
		// Not empty list
		else {

		 curr = (*headPtr);

	     // Traversal of list here
	     while (curr->right != NULL){
	        curr = curr->right;
	        //printf(" %d %d %c \n", curr->row, curr->col, curr->threatType);
	     }
	     if((curr != NULL) && (curr->right == NULL)){ //At the last node
	    	 if((curr->col)==0 && (curr->row)==0){
				 curr->right = newdata;
				 newdata->right = NULL;
	    	 }else{
				 tempCurr = curr;
				 curr->right = newdata;
				 curr->left = tempCurr;
				 newdata->right = NULL;
	    	 }
	     }

	     else{

	       printf("Error inserting!!\n");

	     }
	}
}

void LinkList(NODE * head){
   NODE * tempArr1 = NULL;
   NODE * tempArr2 = NULL;
   int flag = 1;
   NODE * curr;
   if (head == NULL)
   {
      printf ("Empty List !!\n");
   }
   else
   {
      //curr points to the first node in the list
      curr = head;
      //printf("List of nodes: \n");

      while(tempArr1==NULL && tempArr2==NULL){ //looks for first 2 elements
    	  while(flag == 1){
			  if((curr->row) == 0 && (curr->col) == 0){
				  tempArr1 = curr;
				  //printf("1 %d %d \n", curr->row, curr->col);
				  flag=0; //break out of while look
			  }
			  curr = curr->right;

    	  }
    	  flag = 1;
    	  while(flag==1){
			  if((curr->row) == 1){
				  if((curr->col) == 0){
					  tempArr2 = curr;
					  //printf("2 %d %d \n", curr->row, curr->col);
					  flag=0;
				  }
			  }
			  curr = curr->right;
    	  }
      }
      //printf("Pointers found: %d %d %d %d \n", tempArr1->row, tempArr1->col, tempArr2->row, tempArr2->col);
      while ((tempArr2->right) != NULL)
      {
    	  //printf("Pointers found: %d %d %d %d \n", tempArr1->row, tempArr1->col, tempArr2->row, tempArr2->col);
    	  LinkDown(tempArr1, tempArr2);
    	  //printf(" %d %d %d %d \n", tempArr1->row, tempArr1->col, tempArr2->row, tempArr2->col);
  		  LinkUp(tempArr1, tempArr2);
  		  tempArr1 = tempArr1->right;
  		  tempArr2 = tempArr2->right;
  		  numNodes--;
      }

      printf("\n");
   }

}

void LinkDown(NODE *ptr1, NODE *ptr2){
	NODE * curr = ptr1;
	NODE * curr2 = ptr2;

	if((curr->row)<(sendMap+1)){
		curr->down = curr2;
		//printf("linking downward \n");
	}else{
		//dont link down
	}
}

void LinkUp(NODE *ptr1, NODE *ptr2){
	NODE * curr = ptr2 ;
	NODE * curr2 = ptr1;
	//printf("Test");

		if((curr2->row) > 0){
			curr->up = curr2;
			//printf("linking upward \n");
		}
		else{
			//dont link upward
		}
}

void FreeMem(NODE *head)
{
	NODE *curr = head;
    NODE *next = NULL;

    while(curr != NULL)
    {
        next = curr->right;
        free(curr);
        curr = next;
    }
    printf("Freed\n");
}




