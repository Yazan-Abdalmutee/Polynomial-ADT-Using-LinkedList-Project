#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
struct Node
{
    struct Node *next;
    struct Node *previous;
    float factor;
    int pow;
} ;
typedef struct
{
    char op[300];
    char coef[300];
    char power[300];
    char enter[300];
} str;
void printEqyations(str s[]);
void readfile(str s [],FILE *in);
void show(struct Node* node);
void create_node(float x, int y, struct Node** temp);
void add(struct Node *array1,struct Node *array2,struct Node *result);
int fpeek(FILE *in);
void swap(struct Node *a, struct Node *b);
void sorted(struct Node *start);
void removeDuplicates(struct Node* head);
void sub(struct Node *array1,struct Node *array2,struct Node *result);
void showFile(struct Node* node,FILE *out);
void multi(struct Node* num1,struct Node* num2,struct Node* results);
float substitute(struct Node * term,float number);
int main()
{
    float value;
    FILE *out,*in;
    int time=0,time1=0,time2=0,time3=0,time4=0,count=0;
    out = fopen("results.txt", "w");
    in=fopen("equations.txt","r");
    char opeartion=0,ch;
    str s[300];
    //initialize array of nodes
    struct Node   *link[300]= {NULL} ;
    puts("***************************************************************************************");
    puts("Choose the number of the operation you want to perform:");
    puts("1-Read The File ");
    puts("2-Show The Equations:");
    puts("3-Insert the data into linked lists ");
    puts("4-Perform Add");
    puts("5-Perform subtraction ");
    puts("6-Perform multiplication");
    puts("7-Save the results that  user selected to perform in the Results file ");
    puts("8-Exit");
    puts("***************************************************************************************");
    scanf(" %c",&opeartion);

    while(1)
    {
        switch(opeartion)
        {
        case '1' :
        {
            //to read the file 1 time because that enough .since we not write at file during run
            if(time==0)
            {
                readfile(s,in);
                time++;
            }
            puts("\nTHE OPERATION NUMBER 1 DONE \n");
            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);


            break;
        }
        case '2':
        {
            //check if the operation one executed or no
            if(time!=0)
            {
                printEqyations(s);
                puts(" \n\n ----- THE OPERATION NUMBER 2 DONE ------ \n");
            }
            else
            {
                printf("\n(((   You Have to read the file (operation 1)   )))");
            }

            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);

            break;
        }
        case '3':
        {
            //check if the operation one executed or no
            if(time!=0)
            {

                //to insert the data 1 time at linked lists
                if(time1==0)
                {
                    int i=0;
                    int f;
                    float coo;

                    while(s[i].coef[0]!='\0')
                    {
                        //convert string to float
                        coo=(float)strtof(s[i].coef,NULL);
                        //convert string to int
                        f=atoi(s[i].power);
                        if(s[i].op[0]=='-')
                        {
                            coo=coo*-1.0;
                        }
                        create_node(coo,f,&link[count]);
                        if(s[i].enter[0]=='\n')
                        {

                            count++;
                        }
                        i++;
                    }
                    time1++;
                }
                puts(" -----------THE OPERATION NUMBER 3 DONE -----------");
            }
            else
                printf("\n(((   You Have to read the file (operation 1)   )))");



            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");

            scanf(" %c",&ch);


            break;
        }
        case '4':
        {
            //check if the file read and the data inserted in linked lists
            if(time!=0&&time1!=0)
            {

                int size=count;

                int counter1=count;


                for(int i=0; i<size; i++)
                {
                    link[counter1+1] = (struct Node*)malloc(sizeof(struct Node));
                    if(i==0)
                        add(link[i],link[i+1],link[counter1+1]);
                    else
                        add(link[counter1],link[i+1],link[counter1+1]);
                    counter1++;

                }
                printf("\n");
                puts("\nTHE RESULT OF ADDTION IS :- \n");

                show(link[counter1]);

                printf("\n\nEnter a value to substitute x :");
                scanf("%f",&value);
                printf("\nThe result  = %.2f",substitute(link[counter1], value)) ;

                printf("\n");
                if(time2==0)
                {


                    fprintf(out,"Result Of Add ->   " );
                    showFile(link[counter1],out);
                    time2++;
                }

                puts("\nTHE OPERATION NUMBER 4 DONE ");


            }
            else
            {
                if(time==0)
                {
                    printf("\n(((   You Have to read the file (operation 1)   )))");
                }
                else if(time1==0)
                {
                    printf("\n(((   You Have to insert the data into the linked list (operation 3)   )))");
                }
            }

            printf("\n");


            printf("\n ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);

            break;
        }
        case '5':
        {
            //check if the file read and the data inserted in linked lists

            if(time!=0&&time1!=0)

            {

                int size1=count;

                int counter2=count;


                for(int i=0; i<size1; i++)
                {
                    link[counter2+1] = (struct Node*)malloc(sizeof(struct Node));
                    if(i==0)
                        sub(link[i],link[i+1],link[counter2+1]);
                    else
                        sub(link[counter2],link[i+1],link[counter2+1]);
                    counter2++;

                }

                printf("\n");
                puts("\nTHE RESULT OF SUBTRACTION IS :- \n");

                show(link[counter2]);
                printf("\n\nEnter a value to substitute x :");
                scanf("%f",&value);

                printf("\nThe result  = %.2f",substitute(link[counter2], value)) ;

                printf("\n");
                printf("\n");
                if(time3==0)
                {

                    fprintf(out,"Result Of Sub ->   " );
                    showFile(link[counter2],out);
                    time3++;
                }
                puts("\nTHE OPERATION NUMBER 5 DONE ");
            }
            else
            {
                if(time==0)
                {
                    printf("\n(((   You Have to read the file (operation 1)   )))");
                }
                else if(time1==0)
                {
                    printf("\n(((   You Have to insert the data into the linked list (operation 3)   )))");
                }
            }


            printf("\n");

            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);

            break;
        }
        case '6':
        {
            //check if the file read and the data inserted in linked lists

            if(time!=0&&time1!=0)

            {

                int size1=count;

                int counter2=count;


                for(int i=0; i<size1; i++)
                {

                    link[counter2+1] = (struct Node*)malloc(sizeof(struct Node));
                    if(i==0)
                        multi(link[i],link[i+1],link[counter2+1]);
                    else
                        multi(link[counter2],link[i+1],link[counter2+1]);
                    counter2++;

                }

                printf("\n");
                puts("\nTHE RESULT OF multiplication IS :- \n");
                show(link[counter2]);
                printf("\n\nEnter a value to substitute x :");
                scanf("%f",&value);

                printf("\nThe result  = %.2f",substitute(link[counter2], value)) ;
                printf("\n");
                if(time4==0)
                {

                    fprintf(out,"Result Of Mult ->   " );
                    showFile(link[counter2],out);
                    time4++;
                }
                puts("\nTHE OPERATION NUMBER 6 DONE ");
            }
            else
            {
                if(time==0)
                {
                    printf("\n(((   You Have to read the file (operation 1)   )))");
                }
                else if(time1==0)
                {
                    printf("\n(((   You Have to insert the data into the linked list (operation 3)   )))");
                }
            }


            printf("\n");
            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);


            break;
        }
        case '7':
        {
            //if there is no operation performed
            if(time2!=0 ||time3!=0||time4!=0)
            {
                fclose(out);
                puts("\nTHE OUTPUT AT RESULTS FILE \n");
                puts("\nTHE OPERATION NUMBER 7 DONE ");
            }
            else
            {
                puts(" you have to choose at least 1 operation(add,mult,sub) before choosing this operation");
            }
            printf("\n  ___PLEASE ENTER ANY KEY TO CONTINUE___ \n\n");
            scanf(" %c",&ch);


            break;
        }
        case '8':
        {
            printf("\n !!!!! Exit !!!!!");
            exit(0);

        }
        default:
        {
            printf("\nu entered wrong number .. u have to enter from 1 - 8 ...  please try again\n");

        }
        }

        puts("***************************************************************************************");
        puts("Choose the number of the operation you want to perform:");
        puts("1-Read The File ");
        puts("2-Show The Equations:");
        puts("3-Insert the data into linked lists ");
        puts("4-Perform Add");
        puts("5-Perform subtraction ");
        puts("6-Perform multiplication");
        puts("7-Save the results that  user selected to perform in the Results file ");
        puts("8-Exit");
        puts("***************************************************************************************");

        scanf(" %c",&opeartion);
    }

    int size=count;
    int size1=count;

    int counter2=count;

    for(int i=0; i<=size; i++)
    {
        show(link[i]);
        printf("\n");

    }



    for(int i=0; i<size1; i++)
    {

        link[counter2+1] = (struct Node*)malloc(sizeof(struct Node));
        if(i==0)
            sub(link[i],link[i+1],link[counter2+1]);
        else
            sub(link[counter2],link[i+1],link[counter2+1]);
        counter2++;

    }

    printf("\n");
    show(link[counter2]);


    return 0;
}
//function to substitute a value
float substitute(struct Node * term,float number)
{
    float result=0;
    while(term->next!=NULL)
    {
        result=result+(float)pow(number,term->pow)*term->factor;
        term=term->next;
    }
    return result;
}
//function to multi
void multi(struct Node* num1,struct Node* num2,struct Node* results)
{
    removeDuplicates(num1);
    removeDuplicates(num2);
    struct Node* start;
    start=num2;

    while(num1->next!=NULL)
    {
        while(start->next!=NULL)
        {
            results->pow=num1->pow+start->pow;
            results->factor=num1->factor*start->factor;
            results->next=(struct Node*)malloc(sizeof(struct Node));
            results= results->next;
            results->next=NULL;
            start=start->next;

        }
        start=num2;
        num1=num1->next;
    }


}
//function to sub
void sub(struct Node *sub1,struct Node *sub2,struct Node *res)
{
    removeDuplicates(sub1);
    removeDuplicates(sub2);

    while(sub1->next!=NULL &&sub2->next!=NULL)
    {


        if(sub1->pow==sub2->pow)
        {

            res->pow= sub1->pow;
            res->factor=sub1->factor-sub2->factor;
            sub1 = sub1->next;
            sub2 = sub2->next;


        }
        else if(sub1->pow<sub2->pow)
        {

            res->pow = sub1->pow;
            res->factor = sub1->factor;
            sub1 = sub1->next;

        }

        else if(sub1->pow>sub2->pow)
        {


            res->pow = sub2->pow;
            res->factor = sub2->factor*-1;
            sub2 = sub2->next;

        }

        res->next=(struct Node*)malloc(sizeof(struct Node));
        res= res->next;
        res->next=NULL;

    }
    while(sub1->next!=NULL||sub2->next!=NULL)
    {
        if (sub1->next)
        {
            res->pow = sub1->pow;
            res->factor = sub1->factor;
            sub1 = sub1->next;
        }
        else  if (sub2->next)
        {
            res->pow = sub2->pow;
            res->factor = sub2->factor*-1;
            sub2 = sub2->next;
        }
        res->next
            = (struct Node*)malloc(sizeof(struct Node));
        res = res->next;
        res->next = NULL;
    }



}
//function to print the results at output file
void showFile(struct Node* node,FILE *out)
{
    removeDuplicates(node);


    while (node->next != NULL)
    {
        while (node->factor==0&&node->next->next!=NULL)
        {
            node = node->next;
        }
        if(node->pow==0)
        {
            fprintf(out,"%.2f", node->factor);
        }
        else if(node->factor==0)
        {
            fprintf(out,"0.00");
        }
        else
            fprintf(out,"%.2fx^%d", node->factor, node->pow);
        if(node->next->factor<0)
        {
            fprintf(out,"     ");
        }
        node = node->next;
        {

            if (node->next != NULL&&node->factor>=0)
                fprintf(out,"   +   ");
        }
    }
    fprintf(out,"\n");
}
//function to add
void add(struct Node *array1,struct Node *array2,struct Node *result)
{
    removeDuplicates(array1);
    removeDuplicates(array2);

    while(array1->next!=NULL &&array2->next!=NULL)
    {


        if(array1->pow==array2->pow)
        {

            result->pow= array1->pow;
            result->factor=array1->factor+array2->factor;
            array1 = array1->next;
            array2 = array2->next;


        }





        else if(array1->pow<array2->pow)
        {

            result->pow = array1->pow;
            result->factor = array1->factor;
            array1 = array1->next;

        }

        else if(array1->pow>array2->pow)
        {


            result->pow = array2->pow;
            result->factor = array2->factor;
            array2 = array2->next;

        }


        result->next=(struct Node*)malloc(sizeof(struct Node));
        result= result->next;
        result->next=NULL;

    }
    while(array1->next!=NULL||array2->next!=NULL)
    {
        if (array1->next)
        {
            result->pow = array1->pow;
            result->factor = array1->factor;
            array1 = array1->next;
        }
        else  if (array2->next)
        {
            result->pow = array2->pow;
            result->factor = array2->factor;
            array2 = array2->next;
        }

        result->next
            = (struct Node*)malloc(sizeof(struct Node));
        result = result->next;
        result->next = NULL;
    }



}
//function to show the results of operations at console
void show(struct Node* node)
{

    removeDuplicates(node);


    while (node->next != NULL)
    {
        while (node->factor==0&&node->next->next!=NULL)
        {
            node=node->next;
        }
        if(node->pow==0)
        {
            printf("%.2f", node->factor);
        }
        else if(node->factor==0)
        {
            printf("0.00");
        }
        else
            printf("%.2fx^%d", node->factor, node->pow);


        node = node->next;


        if (node->next != NULL)
        {
            printf("   +   ");
        }



    }
}
//function to remove duplicates by adding polynomial which has same power
void removeDuplicates(struct Node* head)
{

    if(head==NULL)
    {
        return;
    }
    //call sorted method
    sorted(head);

    struct Node* current = head;

    struct Node* next_next;

    if (current == NULL)
        return;


    while (current->next->next  != NULL)
    {

        if (current->pow == current->next->pow)
        {
            current->factor=current->factor+current->next->factor;
            next_next = current->next->next;
            next_next->previous=current;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
}
//function to sort the linked lists in Ascending order of the power vlaue
void sorted(struct Node *start)
{
    int swapped;
    struct Node *ptr1;
    struct Node *ptr2 = NULL;



    if (start == NULL)
        return;

    int c=0;
    do
    {
        ptr1 = start;
        swapped=0;
        if(c==0)
        {
            while (ptr1->next->next != ptr2)
            {
                if (ptr1->pow> ptr1->next->pow)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            ptr2 = ptr1;
            c++;
        }
        else
        {
            while (ptr1->next != ptr2)
            {
                if (ptr1->pow> ptr1->next->pow)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            ptr2 = ptr1;
        }


    }
    while(swapped==1);

}
//function to swap the values for two nodes
void swap(struct Node *a, struct Node *b)
{
    int temp = a->pow;
    float temp1=a->factor;

    a->factor = b->factor;
    b->factor = temp1;

    a->pow = b->pow;
    b->pow = temp;
}
//function to create new node
void create_node(float x, int y, struct Node** temp)
{
    struct Node *r, *z;
    z = *temp;
    //if there is no nodes at this index of array
    if (z == NULL)
    {
        r = (struct Node*)malloc(sizeof(struct Node));
        if(r==NULL)
        {
            printf("THE MEMORY IS FULL");
            exit(1);
        }
        r->factor = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        if(r->next==NULL)
        {
            printf("THE MEMORY IS FULL");
            exit(1);
        }
        r->previous=NULL;
        r = r->next;
        r->next = NULL;
        r->previous=*temp;
    }
    //if we has nodes at this index of array
    else
    {
        r->factor = x;
        r->pow = y;
        r->next = (struct Node*)malloc(sizeof(struct Node));
        if(r->next==NULL)
        {
            printf("THE MEMORY IS FULL");
            exit(1);
        }
        r->next->previous=r;
        r = r->next;
        r->next = NULL;
    }
}
//function to read the file
void readfile(str s [],FILE *in)
{

    int b=0;
    int k=0;

    if(in==0)
    {
        printf("the file not exsict");
        exit(0);
    }
    fseek(in,0,SEEK_SET);
    char c=getc(in);

    int i=0,j=0;
    while(!feof(in))
    {
        k=0;
        j=0;
        b=0;

        if(c<='9'&&c>='0')
        {
            while((c<='9'&&c>='0')||c=='.') //read coef
            {


                s[i].coef[j]=c;
                j++;
                c=getc(in);
                while(c==' ')
                {
                    c=getc(in);
                }
            }
            i++;
            j=0;
            b++;

        }
        if((c>='A'&&c<='z')&&((fpeek( in))!='^')&&(s[i].coef[0]=='\0')&&b==0)   //read  x
        {
            s[i].coef[0]='1';
            s[i].power[0]='1';
            k++;
            i++;
        }
        if((c>='A'&&c<='z')&&((fpeek( in))!='^')&&(s[i-1].coef[0]!='\0'))// read 2 x,3 x,...
        {
            s[i-1].power[0]='1';
            k++;
        }

        if((c>='A'&&c<='z')&&((fpeek( in))=='^')&&(s[i].coef[0]=='\0')&&b==0)   //read x^2,x^3
        {
            k++;
            c=getc(in);
            c=getc(in);
            while(c==' ')
            {
                c=getc(in);
            }
            s[i].coef[0]='1';

            while(c>='0'&&c<='9')
            {
                s[i].power[j]=c;
                j++;
                c=getc(in);
                while(c==' ')
                {
                    c=getc(in);
                }
            }
            i++;
            j=0;
        }
        else if((c>='A'&&c<='z')&&k==0)//read 3x^3
        {
            {
                c=getc(in);
                while(c==' ')
                {
                    c=getc(in);
                }
                c=getc(in);
                while(c==' ')
                {
                    c=getc(in);
                }
            }


            if(c>='0'&&c<='9')
            {
                while(c>='0'&&c<='9'&&c!='+'&&c!='-')
                {
                    s[i-1].power[j]=c;
                    j++;
                    c=getc(in);
                    while(c==' ')
                    {
                        c=getc(in);
                    }

                }
            }
        }
        j=0;

        if(s[i-1].power[0]=='\0'&&s[i-1].coef[0]!='\0')// if we don't have  x
        {

            s[i-1].power[0]='0';

        }

        if(c=='+'||c=='-')// read + -
        {
            s[i].op[0]=c;
        }
        if(s[i-1].op[0]=='\0'&&s[i-1].coef[0]!='\0'&&s[i-1].power[0]!='\0')// +1
        {
            s[i-1].op[0]='+';

        }
        while(c=='\n'&&fpeek(in)!=EOF&&fpeek(in)=='\n')//skip \n
        {
            c=getc(in);

        }
        if(c=='\n'&&fpeek(in)!=EOF) //read \n
            s[i-1].enter[0]=c;

        c=getc(in);
        j=0;

    }


}
//function to print the equation in the file
void printEqyations(str s[])
{

    int i=0;


    printf("THE EQUATIONS IN THE FILE ARE :\n\n");
    int count=0;
    printf("%d  ->  ",count+1);
    while(s[i].power[0]!='\0')
    {

        //if there is no pow
        if(s[i].coef[0]=='1'&&s[i].coef[1]=='\0'&&s[i].power[0]=='1'&&s[i].power[1]=='\0')
        {
            printf("%s x ",s[i].op);

        }
        //if there is no coef or coef ==1
        else    if(s[i].coef[0]=='1'&&s[i].coef[1]=='\0')
        {
            if(s[i].power[0]=='0')
            {
                printf("%s ",s[i].op);
                printf("%s ",s[i].coef);
            }
            else
            {
                printf("%s x",s[i].op);
                printf("^%s ",s[i].power);
            }

        }
        // if power =0
        else if(s[i].power[0]=='0')
        {
            printf("%s ",s[i].op);
            printf("%s ",s[i].coef);
        }
        //if power =1
        else  if(s[i].power[0]=='1'&&s[i].power[1]=='\0')
        {
            printf("%s ",s[i].op);

            printf("%sx ",s[i].coef);


        }

        else
        {
            printf("%s ",s[i].op);

            printf("%sx",s[i].coef);

            printf("^%s ",s[i].power);
        }
        printf("%s",s[i].enter);
        //print \n
        if(s[i].enter[0]=='\n')
        {
            count++;
            if(count<9)
                printf("%d  ->  ",count+1);
            else
                printf("%d ->  ",count+1);
        }

        i++;
    }
}
//function to get the value of the next char without changing the pointer
int fpeek(FILE *in)
{
    int c;

    c = fgetc(in);
    ungetc(c, in);

    return c;
}