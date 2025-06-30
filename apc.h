#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1 

typedef struct node
{
    struct node *prev ;
    int data ;
    struct node *next ;
}Dlist;


int read_and_validate_CLA(int argc ,char *argv[]);

int insert_before(Dlist **head, Dlist **tail, int data);

int insert_after(Dlist **head, Dlist **tail, int data);

int delete_first(Dlist **head, Dlist **tail);

int delete_list(Dlist **head, Dlist **tail);

void print_list(Dlist *head);

void print_res(Dlist *head , int flag) ;

void insert_digit(Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , char *argv[]);

int addition (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR);

int subtraction (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR , char *argv[]);

int multiplication (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR1 , Dlist **tailR1 , Dlist **headR2 , Dlist **tailR2);

int division (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR , char *argv[]);

#endif