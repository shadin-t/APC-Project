#include "apc.h"

int multiplication (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR1 , Dlist **tailR1 , Dlist **headR2 , Dlist **tailR2)
{
    Dlist *temp1 = *tail1 ;
    Dlist *temp2 = *tail2 ;
    Dlist *backup_head = NULL ;
    Dlist *backup_tail = NULL ;
    int num1 , num2 , carry = 0 , mul , res , count = 0;
    if(temp1 ->prev == NULL && temp2 -> prev == NULL)
    {
        num1 = temp1 ->data;
        num2 = temp2 -> data ;
        mul = (num1 * num2) + carry ;
        if(insert_before(headR1 , tailR1 , mul) == FAILURE)
        {
            return FAILURE;
        } 
        print_res(*headR1 , 0);
        return SUCCESS;  

    }
    while(temp2 != NULL)
    {
        carry = 0;
        while(temp1 != NULL)
        {
            num1 = temp1 ->data;
            num2 = temp2 -> data ;
            mul = (num1 * num2) + carry ;
            res = mul % 10 ;
            carry = mul / 10 ;
            if(temp1 ->prev == NULL )
            {
                res = mul ;
            }
            //printf("%d x %d = %d\n",num1,num2,mul);
            
            if(temp2 == *tail2)
            {
                if(insert_before(headR1 , tailR1 , res) == FAILURE)
                {
                    return FAILURE;
                }
            }
            else
            {
                if(insert_before(headR2 , tailR2 , res) == FAILURE)
                {
                    return FAILURE;
                }   
            }
            temp1 = temp1 ->prev ;
        }
        if(count != 0)
        {
            for(int i = 0 ; i < count ; i++)
            {
                    insert_after(headR2 , tailR2 , 0);
            }
        }
        //print_list(*headR1);
        //print_list(*headR2);

        if(addition(headR1 , tailR1 , headR2 , tailR2 ,&backup_head , &backup_tail) == SUCCESS)
        {
            if(delete_list(headR1 , tailR1) == SUCCESS)
            {
                *headR1 = backup_head;
                *tailR1 = backup_tail;
                backup_head = NULL ;
                backup_tail = NULL ;
                delete_list(headR2 , tailR2);
            }

        }
        temp1 = *tail1 ;
        temp2 = temp2 -> prev ;
        count++ ;
    }
    print_res(*headR1 , 0);
    return SUCCESS;
}