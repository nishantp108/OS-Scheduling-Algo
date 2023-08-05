#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int p_name;
    float a_time;
    float p_time;
    struct node* next;
};
struct node* head;
struct node1
{
    int p_name1;
    float a_time1;
    float p_time1;
    struct node1* next1;
};
struct node1* head1;
struct node2
{
    int p_name2;
    float a_time2;
    float p_time2;
    float p_n_time2;
    struct node2* next2;
};
struct node2* head2;

void insert()
{
    FILE* fp;
    if(fp == NULL)
        printf("File not Found");
    else
    {
        fp = fopen("input.txt" , "r");
        char  line[255];
        int flag = 0;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            char *ptr = strtok(line," ");
            while(ptr != NULL)
            {
                struct node* ptrt = (struct node*)malloc(sizeof(struct node));
                if(ptr == NULL)
                {
                    printf("Node Not Created\n");
                    break;
                }
                else
                {
                    int pname;
                    float atime,ptime;

                    pname = ((int)atoi(ptr));
                    ptr = strtok(NULL," ");

                    atime = ((float)atoll(ptr));
                    ptr = strtok(NULL," ");

                    ptime = ((float)atoll(ptr));
                    ptr = strtok(NULL," ");

                    int k = (int)atime;

                    if(k != 0 || (k==0 &&flag == 0))
                    {
                        if(k==0 &&flag == 0)
                            flag = 1;
                        ptrt->a_time = atime;
                        ptrt->p_name = pname;
                        ptrt->p_time = ptime;
                        ptrt->next = NULL;

                        if(head == NULL)
                        {
                            head = ptrt;
                        }
                        else
                        {
                            struct node* temp =head;
                            while(temp->next != NULL)
                                temp = temp->next;
                            temp->next = ptrt;
                        }
                    }

                }
            }
        }
        struct node* temp =head;
        struct node* temp2 = NULL;
        while(temp != NULL)
        {
           temp2 = temp->next;
            while(temp2 != NULL)
            {
                if(((int)temp2->a_time) < ((int)temp->a_time))
                {
                    int data1 = temp2->p_name;
                    float data2 = temp2->a_time;
                    float data3 = temp2->p_time;
                    temp2->p_name = temp->p_name;
                    temp2->a_time = temp->a_time;
                    temp2->p_time = temp->p_time;

                    temp->p_name = data1;
                    temp->a_time = data2;
                    temp->p_time = data3;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
}
void show()
{
    if(head == NULL)
        printf("No Node is Inserted\n");
    else
    {
        struct node* temp =head;
        int c=1;
        printf("\n--- Process Table ---");
        printf("\n\nProcess | Arriving Time | Processing Time\n");
        while(temp->next != NULL)
        {
            //printf("%7d%16f%18f\n", c++,temp->a_time,temp->p_time);
            printf("%7d%16f%18f\n", temp->p_name,temp->a_time,temp->p_time);

            temp = temp->next;
        }
         printf("%7d%16f%18f\n", temp->p_name,temp->a_time,temp->p_time);
    }
}
void calculate(float att,float awt, float rt,float ft)
{
    printf("\n\nEnter 1 For Average Turnaround Time");
    printf("\nEnter 2 For Average Waiting Time\n");
    printf("Enter 3 For Average Responce Time\n");
    printf("Enter 4 For Throughput");
    printf("\nEnter 5 For All of the Above");
    int choice=0;
    printf("\n\nEnter your choice :- ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\nAverage Turnaround Time is :- %f",att);
                break;
        case 2:
                printf("\nAverage Waiting Time is :- %f\n",awt);
                break;
        case 3:
                printf("Average Responce Time is :- %f\n",awt);
                break;
        case 4:
                printf("Throughput is :- %f",ft);
                break;
        case 5:
                printf("\nAverage Turnaround Time :- %f",att);
                printf("\nAverage Waiting Time :- %f",awt);
                printf("\nAverage Responce Time :- %f\n",rt);
                printf("Throughput :- %f",ft);
                break;
    }
}
void fcfs()
{
    if(head == NULL)
        printf("No Node is Inserted\n");
    else
    {
        int gchart[500];
        struct node* temp =head;
        int c=0;    //comment
        printf("\n--- First Come First Serve ---");
        printf("\nGann Chart\n");
        float tt=0,ft=0,wt=0,att=0,awt;
        int counter=0;
        while(temp != NULL)
        {
            while(counter < temp->a_time)
            {
                printf("- ");
                counter++;
            }
            ft = (temp->p_time) + counter;
            tt = ft - temp->a_time;
            if(tt<0)
                tt = tt-(tt*2);

            wt = tt - temp->p_time;
            int k =  temp->p_time;
            while(k != 0)
            {
                printf("%d ",temp->p_name);
                counter++;
                k--;
            }
            att = att+tt;
            awt = awt+wt;
            temp = temp->next;
            c++;
        }
         calculate((att/c),(awt/c),(awt/c),(ft/c));
    }
}
//sjf
void copylinklist1()
{
    struct node* temp =head;
    //copy Linklist
    while(temp != NULL)
    {
        struct node1* ptr = (struct node*)malloc(sizeof(struct node));
        if(ptr == NULL)
            printf("Sorry, Operation Not performed");
        else
        {
            ptr->p_name1 = temp->p_name;
            ptr->a_time1 = temp->a_time;
            ptr->p_time1 = temp->p_time;
            ptr->next1 =NULL;
            if(head1 == NULL)
                head1 = ptr;
            else
            {
                struct node1* temp1 = head1;
                while(temp1->next1 != NULL)
                    temp1 = temp1->next1;
                temp1->next1=ptr;
            }
        }
        temp = temp->next;
    }
}
//srtn
void copylinklist2()
{
    struct node* temp =head;
    //copy Linklist
    while(temp != NULL)
    {
        struct node2* ptr = (struct node2*)malloc(sizeof(struct node2));
        if(ptr == NULL)
            printf("Sorry, Operation Not performed");
        else
        {
            ptr->p_name2 = temp->p_name;
            ptr->a_time2 = temp->a_time;
            ptr->p_time2 = temp->p_time;
            ptr->p_n_time2 = temp->p_time;
            ptr->next2 =NULL;
            if(head2 == NULL)
                head2 = ptr;
            else
            {
                struct node2* temp1 = head2;
                while(temp1->next2 != NULL)
                    temp1 = temp1->next2;
                temp1->next2=ptr;
            }
        }
        temp = temp->next;
    }
}
void sjf()
{
    if(head == NULL)
        printf("No Node is Inserted\n");
    else
    {
        copylinklist1();
        printf("\n\n--- Shortest Job First ---");
        printf("\nGann Chart\n");

        struct node1* temp1 = head1;
        float ft=0,tt=0,wt=0,att=0,awt=0,rt=0,art=0;
        int count=0;
        while(1)
        {
            if(head1 == NULL)
                break;
            struct node1* temp2 = head1;
            struct node1* temp3 = NULL;
            int flag = 0;
            while(temp2 != NULL)
            {
                if(temp3 == NULL)
                {
                    temp3 = temp2;
                }
                else if(temp2->a_time1 <= ft)
                {
                    if(temp3->p_time1 > temp2->p_time1)
                    {
                        temp3 = temp2;
                    }
                }
                temp2 = temp2->next1;
            }
            if(temp3->a_time1 > ft)
            {
                while(ft != temp3->a_time1)
                {
                    printf("- ");
                    ft++;
                }
            }
            float temp = ft;
            while(ft != (temp + temp3->p_time1))
            {
                printf("%d ",temp3->p_name1);
                ft++;
            }
            tt = (ft - temp3->a_time1);
            wt = tt - temp3->p_time1;
            rt = wt;
            att = att + tt;
            awt = awt + wt;
            art = art + rt;
            count++;

            if(head1 == temp3)
            {
                head1 = temp3->next1;
            }
            else
            {
                struct node1* temp4 = head1;
                while(temp4->next1 != temp3)
                {
                    temp4 = temp4 -> next1;
                }
                temp4->next1 = temp3->next1;
            }
        }
        att = att / count;
        awt = awt / count;
        art = art / count;
        ft = ft / count;
        calculate(att,awt,art,ft);
    }
}
void srtn()
{
    if(head == NULL)
        printf("No Node is Inserted \n");
    else
    {
        printf("\n\n--- Shortest Remaining Time Next ---");
        printf("\nGann Chart\n");
        float ft=0,tt=0,wt=0,att=0,awt=0,art=0,rt=0;
        int c=0;
        copylinklist2();
        int i=0;
        struct node2* temp5 = head2;

        while(1)
        {
            if(head2 == NULL)
                break;
            struct node2* temp2 = head2;
            struct node2* temp3 = NULL;
            while(temp2 != NULL)
            {
                if(temp3 == NULL)
                {
                    temp3 = temp2;
                }
                else if(temp2->a_time2 <= ft)
                {
                    if(temp3->p_time2 > temp2->p_time2)
                    {
                        temp3 = temp2;
                    }
                }
                temp2 = temp2->next2;
            }
            if(temp3->a_time2 > ft)
            {
                while(ft != temp3->a_time2)
                {
                    printf("- ");
                    ft++;
                    i++;
                }
            }
            if(temp3->p_time2 == temp3->p_n_time2)
            {
                rt = rt + abs(i - temp3->a_time2 );
            }
            printf("%d ",temp3->p_name2);
            temp3->p_n_time2 = temp3->p_n_time2 - 1;
            i++;

            if(temp3->p_n_time2 ==0)
            {
                ft = i;
                tt = ft - temp3->a_time2;
                if(tt<0)
                    tt = tt-(tt*2);
                wt = tt - temp3->p_time2;
                c++;
                if(head2 == temp3)
                {
                    head2 = temp3->next2;
                }
                else
                {
                    struct node2* temp4 = head2;
                    while(temp4->next2 != temp3)
                    {
                        temp4 = temp4 -> next2;
                    }
                    temp4->next2 = temp3->next2;
                }
                att = att+tt;
                awt = awt+wt;
            }
        }
        calculate((att/c),(awt/c),(awt/c),(ft/c));
    }
}
void rr(){
    if(head == NULL )
        printf("No Node is Inserted");
    else
    {
        copylinklist2();
        float total_p_time=0;
        int duration = 0;   //Time Quantum
        printf("\n\n--- Round Robin ---");
        printf("\nEnter Time Quantum :- ");
        scanf("%d",&duration);
        printf("\nGann Chart\n");
        float ft=0,tt=0,wt=0,rt=0,aft=0,att=0,awt=0,art=0;
        int c=0;
        int i= head2->a_time2;
        while(head2 != NULL)
        {
            struct node2* temp2 = head2;
            if(temp2->p_n_time2 == temp2->p_time2)
            {
                rt = i - temp2->a_time2;
                c++;
            }
            if(temp2->p_n_time2 > duration)
            {
                temp2->p_n_time2 = temp2->p_n_time2 - duration;
                int count = duration;

                while(count--)
                {
                    printf("%d ",temp2->p_name2);
                    i++;
                    //printf("%d - ",i);

                }
                struct node2* temp3 = temp2->next2;
                if(temp2->next2 != NULL)
                {
                    //Extra Code
                    int flag = 0;
                    struct node2* temp4 = temp2->next2;
                    int at = (int)temp4->a_time2;
                    while(temp4 != NULL )
                    {
                        if(at == i)
                        {
                            flag == 1;
                            temp3 = temp4;
                        }
                        temp4 = temp4->next2;
                        at = (int) temp3->a_time2;
                            //printf("as :-%d ",at);
                    }
                    if(flag != 1)
                    {
                        while(at < i && temp3->next2 != NULL )
                        {
                            temp3 = temp3->next2;
                            at = (int) temp3->a_time2;
                            //printf("as :-%d ",at);
                        }
                    }

                    //Regular
//                    while(at < i && temp3->next2 != NULL )
//                    {
//                            temp3 = temp3->next2;
//                            at = (int) temp3->a_time2;
//                            //printf("as :-%d ",at);
//                    }
                    if(at == i)
                    {
                        head2 = temp2->next2;
                        temp2->next2 =temp3->next2;
                        temp3->next2 = temp2;
                    }
                    else if(temp3->next2 == NULL && at < i)
                    {
                        temp3->next2 = temp2;
                        head2 = temp2->next2;
                        temp2->next2 = NULL;
                    }
                    else if(temp2->next2 != NULL)
                    {
                        struct node2* temp4 = temp2;
                        while(temp4->next2 != temp3)
                        {
                            temp4 = temp4->next2;
                        }
                        if(temp2->next2 != temp3)
                        {
                            head2 = temp2->next2;
                            temp4->next2 = temp2;
                            temp2->next2 = temp3;
                        }
                    }
                }
            }
            else
            {
                int count = temp2->p_n_time2;
                temp2->p_n_time2 = temp2->p_n_time2 - duration;
                while(count--)
                {
                    printf("%d ",temp2->p_name2);
                    i++;
                    //printf("%d - ",i);
                }
                ft = i; //Finish Time
                tt = ft - temp2->a_time2;
                wt = tt - temp2->p_time2;
                head2 = temp2->next2;
                aft = aft + ft;
                att = att + tt;
                awt = awt + wt;
                art = art + rt;
            }
// Extra Code
                struct node2* temp5 = head2;
                    while(temp5 != NULL)
                    {
                        printf("%d ",temp5->p_name2);
                        temp5 = temp5->next2;
                    }
                    printf("\n");
        }
        calculate((att/c),(awt/c),(art/c),(aft/c));
    }
}
void main()
{
    int ch=0;
    printf("Enter 1 For Show");
    printf("\nEnter 2 For FCFS");
    printf("\nEnter 3 For SJF");
    printf("\nEnter 4 For SRTN");
    printf("\nEnter 5 For RR");
    printf("\nEnter 6 For All 4 Algoritham");
    printf("\n\nFirst Process Start with 0.\n");
    insert();
    printf("\n\nEnter Choice :- ");
    scanf("%d",&ch);
    while(ch!=0)
    {
        switch(ch)
        {
            case 1:show();
                    break;
            case 2:fcfs();
                   break;
            case 3:sjf();
                    break;
            case 4:srtn();
                    break;
            case 5:rr();
                    break;
            case 6:fcfs();
                    sjf();
                    srtn();
                    rr();
                    break;
            default:printf("Enter Valid Choice");
                    break;
        }
        printf("\n\nEnter Choice :- ");
        scanf("%d",&ch);
    }
}
