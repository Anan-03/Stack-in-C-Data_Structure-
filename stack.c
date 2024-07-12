#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size],top=-1;

int underflow()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int overflow()
{
    if(top==size-1)
        return 1;
    else
        return 0;
}
void push()
{
    if(overflow())
        printf("\nStack is overflow");
    else
    {
        int x;
        printf("\nEnter item to push:");
        scanf("%d",&x);
        top++;
        arr[top]=x;
        printf("\nItem pushed successfully!!!");
    }
}
void pop()
{
    if(underflow())
        printf("\nStack is underflow");
    else
    {
        printf("\n%d poped successfully",arr[top]);
        top--;
    }
}
void display()
{
    if(underflow())
        printf("\nStack is underflow!!!");
    else
    {
        int i;
        printf("\nStack is- ");
            for(i=top;i>=0;i--)
                printf("%d ",arr[i]);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("\nWrong choice");
        }
    }
    return 0;
}