#include "apc.h"

int read_and_validate_CLA(int argc ,char *argv[])
{
    int i ;
    if(argc != 4)
    {
        return FAILURE ;
    }
    else
    {
        if(argv[2][0] == '+' || argv[2][0] == '-' ||argv[2][0] == 'x' ||argv[2][0] == '/')
        {
            for (i = 0 ; argv[1][i] != '\0' ; i++)
            {
                if(argv[1][i] >= '0' && argv[1][i] <= '9')
                {}
                else
                {
                    return FAILURE ;
                }
            }
            for (i = 0 ; argv[3][i] != '\0'  ; i++)
            {
                if(argv[3][i] >= '0' && argv[3][i] <= '9')
                {}
                else
                {
                    return FAILURE ;
                }
            }
        }
        else
        {
            return FAILURE ;
        }
    }
    return SUCCESS ;
}

int insert_before(Dlist **head, Dlist **tail, int data)
{
     Dlist *new=malloc(sizeof(Dlist));
     
       if(new==NULL)
      {
          return FAILURE;
      }
      new->data=data;
      new->prev=NULL;
    
      
      if(*head==NULL)
      {
          *head=new;
          *tail=new;
          new ->next=NULL;
          return SUCCESS;
      }
      
      (*head)->prev=new;
      new ->next=*head;
      *head=new;
      return SUCCESS;
}

int insert_after(Dlist **head, Dlist **tail, int data)
{
       Dlist *new=malloc(sizeof(Dlist));
      if(new==NULL)
      {
          return FAILURE;
      }
      new->data=data;
      new->prev=*tail;
      new ->next=NULL;
      
      if(*head==NULL)
      {
          *head=new;
          *tail=new;
          return SUCCESS;
      }
      (*tail)->next=new;
      *tail=new;
      return SUCCESS;
}
int delete_first(Dlist **head, Dlist **tail)
{
     if(*head == NULL)
      {
          return FAILURE;
      }
      
      *head=(*head) -> next;
      
      if(*head == NULL)
      {
          free (*tail);
          *tail = NULL;
          return SUCCESS;
      }
      
      free((*head)-> prev);
      (*head) -> prev = NULL;
       
      
      return SUCCESS;
}
int delete_list(Dlist **head, Dlist **tail)
{
      if(*head == NULL)
      {
          return FAILURE;
      }
      
      *tail=(*tail) -> prev;
      
      if((*head) -> next == NULL)
      {
          free (*head);
          *head = NULL;
          return SUCCESS;
      }
      while((*head)!= NULL)
      {
        free((*head));
        *head = (*head) -> next;
      }
      return SUCCESS;

}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}

void print_res(Dlist *head , int flag)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        printf("RESULT = ");
        if(flag == 1 && head ->data != 0)
        {
            printf("-");
        }
        
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		}
        printf("\n");
    	
    }
}

void insert_digit(Dlist **head1 , Dlist **tail1 , Dlist **head2 , Dlist **tail2 , char *argv[])
{
    int i, data1, data2;

    for (i = 0; argv[1][i] != '\0'; i++)
    {

        data1 = argv[1][i] - 48; 
        insert_after(head1 , tail1 , data1) ;
    }

    for (i = 0; argv[3][i] != '\0'; i++)
    {
        data2 = argv[3][i] - 48; 
        insert_after(head2 , tail2 , data2);
        
    }
    print_list(*head1);
    print_list(*head2);
}


