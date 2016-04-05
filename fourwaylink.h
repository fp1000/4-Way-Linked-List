/*
 * fourwaylink.h
 *
 *  Created on: Oct 30, 2015
 *      Author: frankpultro
 */

#ifndef FOURWAYLINK_H_
#define FOURWAYLINK_H_

typedef struct node
{

  int row;
  int col;
  int status;
  char threatType;
  struct node *up;
  struct node *down;
  struct node *left;
  struct node *right;
} NODE;

NODE * CreateNode(int x, int y,int stat, char type);
void Insert(NODE **headPtr, NODE *newdata);
void LinkList(NODE * head);
void LinkDown(NODE *ptr1, NODE *ptr2);
void LinkUp(NODE *ptr1, NODE *ptr2);
void FreeMem(NODE *head);
#endif /* FOURWAYLINK_H_ */
