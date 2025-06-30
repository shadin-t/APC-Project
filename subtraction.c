#include "apc.h"

int subtraction (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR ,char *argv[])
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int num1 ;
    int num2 ;
    int borrow = 0 , sub, size1 , size2 , flag = 0 ;
    size1 = strlen(argv[1]);
    size2 = strlen(argv[3]);
    
    if(size1 < size2)
    {
        temp1 = *tail2;
        temp2 = *tail1 ;
        flag = 1 ;
    }
    else if (size1 > size2)
    {
        temp1 = *tail1;
        temp2 = *tail2 ;
    }
    else
    {
        
        if(strcmp(argv[1] , argv[3]) == 0)
        {
            if(insert_before(headR , tailR , 0) == FAILURE)
            {
                return FAILURE ;
            }
            //print_res(*headR , flag);
            return SUCCESS ;
        }
        else if(strcmp(argv[1] , argv[3]) < 0)
        {
            flag = 1 ;
            temp1 = *tail2;
            temp2 = *tail1 ;
        }
        
    }
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
        if (borrow == 1)
        {
            num1 = num1 - 1 ;
        }
        if (num1 < num2)
        {
                num1 = num1 + 10 ;
                borrow = 1 ;
                sub = num1 - num2 ;
                if(insert_before(headR , tailR , sub) == FAILURE)
                {
                    return FAILURE ;
                }
        }
        else
        {
            sub = num1 - num2 ;
            borrow = 0 ;
            if(insert_before(headR , tailR , sub) == FAILURE)
            {
                return FAILURE ;
            }
        }
        //printf("%d - %d = %d \n",num1 , num2 , sub);
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
    //print_res(*headR , flag);
    return flag ;

}