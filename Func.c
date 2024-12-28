#include<stdio.h>
#include<stdlib.h>

//Structure for customer detail
typedef struct customer
{
    int c_no;//for card number
    int pass;//for password of the user
    int balance;//for account balance of the user
    struct customer *next;//to link profile one by one
}customer;

//Function to check card user is existing customer or not
customer *check_user(customer **start,int temp_no)
{
    customer *ptr;
    ptr = *start;
    if((*start) == NULL){
        return NULL;
    }

    while(ptr!=NULL){
        if(ptr->c_no == temp_no){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

//Function to check password count
int check_count(int temp_pass)
{
    int count = 0;
    while(temp_pass>0){
        temp_pass = temp_pass/10;
        count++;
    }
    return count;
}

//Function to create new account for new card user
customer *create(int temp_no)
{
    int n,temp_pass;
    customer *temp;
    temp = (customer*)malloc(sizeof(customer));
    printf("\nDO YOU WANT TO ACTIVATE YOUR CARD (IF YES PRESS 1 OTHERWISE 2 ) :- ");
    scanf("%d",&n);
    if(n==1){
        temp->c_no = temp_no;
        temp->balance = 10000;//lets every user has account balance 10k
        printf("ENTER THE PASSWORD(4 digit) :- ");
        scanf("%d",&temp_pass);
        //loop to check the entered password exactly 4 digit and when it 4 digit then only saved
        while(check_count(temp_pass) != 4){
            printf("ENTER THE PASSWORD CORRECTLY !!\nRE-ENTER PASSWORD EXACTLY IN 4 DIGIT :- ");
            scanf("%d",&temp_pass);
        }
        temp->pass = temp_pass;
        printf("PASSWORD SAVED SUCEESSFULLY\n");
        temp->next = NULL;
        return temp;
    }
    else{
        printf("REMOVE YOUR CARD , THANK YOU !!");
        return NULL;
    }
}

//Function to insertion of new card user to the atm service
void insert(customer **start,int temp_no)
{
    customer *temp,*ptr;
    temp = create(temp_no);
    if(*start == NULL){
        *start = temp;
    }
    else{
        ptr = *start;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

//Function to withdrawl amount
void withdrawl(customer **ptr)
{
    int amt,x = 0,pass;
    printf("ENTER THE WITHDRAWAL AMOUNT :- ");
    scanf("%d",&amt);
    if(amt<(*ptr)->balance){
        //loop to get chance users to entry the password only two times
        while(x!=2){
            printf("ENTER THE PASSWORD :- ");
            scanf("%d",&pass);
            if((*ptr)->pass == pass){
                break;
            }
            printf("WRONG PASSWORD!! RETRY\n");
            x++;
        }
        if(x == 2){
            printf("SORRY REMOVE YOUR CARD\n");
            return;
        }
        (*ptr)->balance = (*ptr)->balance - amt;
        printf("COLLLECT YOUR %d AMOUNT RUPEES\nTHANK YOU VISIT AGAIN\n",amt);
    }
    else{
        printf("\nYOUR WITHDRAWABLE AMOUNT IS NOT PRESENT IN YOUR ACCOUNT");
    }
}

//Function to change pin of the card
void pin_reset(customer **ptr)
{
    int pass;
    printf("ENTER YOUR PASSWORD :- ");
    scanf("%d",&pass);
    if((*ptr)->pass == pass){
        printf("ENTER YOUR NEW PASSWORD :- ");
        scanf("%d",&(*ptr)->pass);
        printf("THANK YOU VISIT AGAIN\n");
    }
    else{
        printf("SORRY REQUEST CANCELLED DUE TO WRONG PASSWORD\nCOLLECT YOUR CARD\n");
    }
}

//Function to balance check of customer
void check_balance(customer **ptr)
{
    int pass,x = 0;
    //loop to get chance users to entry the password only two times
    while(x!=2){
        printf("ENTER THE PASSWORD :- ");
        scanf("%d",&pass);
        if((*ptr)->pass == pass){
            printf("YOUR ACCOUNT BALANCE = %d",(*ptr)->balance);
            printf("THANK YOU VISIT AGAIN\n");
            return;
        }
        printf("WRONG PASSWORD!! RETRY\n");
        x++;
    }
    if(x == 2){
        printf("SORRY REMOVE YOUR CARD\n");
        return;
    }
}

//Function to cash deposit
void cash_deposit(customer **ptr)
{
    int dep,x = 0,pass;
    printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT :- ");
    scanf("%d",&dep);
    //loop to get chance users to entry the password only two times
     while(x!=2){
        printf("ENTER THE PASSWORD :- ");
        scanf("%d",&pass);
        if((*ptr)->pass == pass){
            (*ptr)->balance = (*ptr)->balance + dep;
            printf("THANK YOU VISIT AGAIN\n");
            return;
        }
        printf("WRONG PASSWORD!! RETRY\n");
        x++;
    }
    if(x == 2){
        printf("SORRY REMOVE YOUR CARD\n");
        return;
    }
}

int main()
{
    customer *start = NULL,*temp;
    int n,temp_no;
    while(1)
    {
        printf("\nWelcome To Our ATM\nINSERT YOUR CARD NO :- ");
        scanf("%d",&temp_no);
        temp = check_user(&start,temp_no);
        if(temp==NULL){
            insert(&start,temp_no);
        }
        else{
            printf("PRESS 1 FOR CASH WITHDRAWAL\nPRESS 2 FOR PIN RESET\nPRESS 3 FOR CHECK BALANCE\nPRESS 4 FOR CASH DEPOSIT\nENTER YOUR CHOICE :- ");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                withdrawl(&temp);
                break;
            case 2:
                pin_reset(&temp);
                break;
            case 3:
                check_balance(&temp);
                break;
            case 4:
                cash_deposit(&temp);
                break;
            default:
                printf("ENTER THE CORRECT OPTION !!!");
            }
        }
    }
}
