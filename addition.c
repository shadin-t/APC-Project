#include "apc.h"

int addition (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2 ;
    int num1 ;
    int num2 ;
    int carry = 0 , sum , rem ;
    while(temp1 != NULL || temp2 != NULL)
    {
        if(temp2 == NULL)
        {
            num2 = 0 ;
            num1 = temp1 -> data ;
            temp1 = temp1 -> prev ;
        }
        else if(temp1 == NULL)
        {
            num1 = 0 ;
            num2 = temp2 -> data ;
            temp2 = temp2 -> prev ;
        }
        else
        {
            num1 = temp1 -> data ;
            num2 = temp2 -> data ;
            temp1 = temp1 -> prev ;
            temp2 = temp2 -> prev ;
        }
        
        sum = num1 + num2 + carry ;
        rem = sum % 10 ;
        carry = sum / 10 ;
        if(temp1 == NULL && temp2 == NULL)
        {
            rem = sum ;
        }
        if(insert_before(headR , tailR , rem) == FAILURE)
        {
            return FAILURE ;
        }
        //printf("%d + %d  = %d \n",num1 , num2  , rem);
    }
    Dlist *temp3 = *headR ;
    while( temp3 -> next != NULL)
    {
        if(temp3 -> data == 0)
        {
            delete_first(headR , tailR);
        }
        else
        {
            break ;
        }
        temp3 = temp3 ->next ;
    }
    //print_res(*headR , 0);
    return SUCCESS ;
}