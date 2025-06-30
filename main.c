/*  DOCUMENTATION
    NAME : Mohammad Shadin
    DATE : 21-12-24
    DES  : APC Project
*/
#include "apc.h"

int main(int argc , char *argv[])
{
    Dlist *head1 = NULL , *tail1 = NULL ;
    Dlist *head2 = NULL , *tail2 = NULL ;
    Dlist *headR = NULL , *tailR = NULL ;
    Dlist *headR1 = NULL , *tailR1 = NULL ;
    Dlist *headR2 = NULL , *tailR2 = NULL ;
    int count , flag;
    if (read_and_validate_CLA(argc , argv) == SUCCESS)
    {
        
        char operator = argv[2][0] ;
        switch(operator)
        {
            case '+' :
                insert_digit(&head1 , &tail1 , &head2 , &tail2 , argv);
                if(addition(&head1 , &tail1 , &head2 , &tail2 , &headR , &tailR) == SUCCESS)
                {
                    print_res(headR , 0);
                    printf("Addition Done\n");
                }
                break ;
            case '-' :
                insert_digit(&head1 , &tail1 , &head2 , &tail2 , argv);
                flag = subtraction(&head1 , &tail1 , &head2 , &tail2 , &headR , &tailR , argv) ;
                print_res(headR , flag);
                printf("Subtraction Done\n");
                
                break ;
            case 'x' :
                insert_digit(&head1 , &tail1 , &head2 , &tail2 , argv);
                if(multiplication(&head1 , &tail1 , &head2 , &tail2 , &headR1 , &tailR1 , &headR2 , &tailR2) == SUCCESS)
                {
                    printf("Multiplication Done\n");
                }
                break ;
            case '/' :
                insert_digit(&head1 , &tail1 , &head2 , &tail2 , argv);
                count = division(&head1 , &tail1 , &head2 , &tail2 , &headR , &tailR , argv);
                if(count >= 0)
                {
                    printf("RESULT = %d\n",count);
                    printf("Division Done\n");
                }
                
                break ;
            default :
                printf("Invalid input:-( Try again...)\n");
        }
    }
    else
    {
        printf("Invalid Arguments\n");
    }
}