#include "apc.h"

int division (Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , Dlist **headR , Dlist **tailR , char *argv[])
{
    if((*head2) ->data == 0 )
    {
        printf("ERROR or Not Defined\n");
        return -1 ;
    }
    int count = 0 ;
    while(1)
    {
        int size1 = 0 , size2 = 0 ;
        Dlist *temp3 = *head1 ;
        Dlist *temp4 = *head2 ;
        while(temp3 != NULL)
        {
            size1++ ;
            temp3 = temp3 ->next ;
        }
        //printf("size1 = %d\n",size1);
        while(temp4 != NULL)
        {
            size2++ ;
            temp4 = temp4 ->next ;
        }
        //printf("size2 = %d\n",size2);
        if((size1 < size2))
        {
            break ;
        }
        else if(size1 > size2)
        {
            
            if(subtraction(head1 , tail1 ,head2 , tail2 ,headR , tailR , argv) == SUCCESS)
            {
                if(delete_list(head1,tail1) == SUCCESS)
                {
                    *head1 = *headR;
                    *tail1 = *tailR ;
                    count++ ;
                    *headR = NULL ;
                    *tailR = NULL ;
                    
                }
                
            }
        }
        else if(size1 == size2)
        {
            Dlist *temp1 = *head1;
            Dlist *temp2 = *head2;
            int i , flag = 0;
            for (i = 0 ; i < size1 ; i++)
            {
                if(temp1 ->data > temp2 ->data)
                {
                    flag = 1;
                    break ;
                }
                else if(temp1 ->data == temp2 ->data)
                {
                    flag = 1 ;
                }
                else
                {
                    flag = 0;
                    break ;
                }
                temp1 = temp1 -> next ;
                temp2 = temp2 -> next ;

            }
            if(flag == 0)
            {
                break ;
            }
            else
            {
                if(subtraction(head1 , tail1 ,head2 , tail2 ,headR , tailR , argv) == SUCCESS)
                {
                    if(delete_list(head1,tail1) == SUCCESS)
                    {
                        *head1 = *headR;
                        *tail1 = *tailR;
                        count++ ;
                        *headR = NULL ;
                        *tailR = NULL ;
                        
                    }
                    
                }
            }
        }

    }
    return count ;
}
