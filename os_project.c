#include<stdio.h>

//float priority(int ,int []);
main()
{
    int n;
    printf("Enter no. of process\n");
    scanf("%d",&n);
    int arrivaltime[n],bursttime[n],completiontime[n];
    int turnaround[n],waitingtime[n];
    int i;
    printf("Enter Arrival time & Burst time for every process\n");
    for(i=1;i<=n;i++)
    {
        printf("\n Arrival time for P%d : ",i);
        scanf("%d",&arrivaltime[i]);
        printf("\n Burst time for P%d   : ",i);
        scanf("%d",&bursttime[i]);
    }
    printf("\n We following data for each process : \n");
    printf("\n\n");
    printf("\t\tProcess\t\tArrival Time\t\tBurst Time\n\n");
    for(i=1;i<=n;i++)
    {
        printf("\t\tP%d\t\t%d\t\t\t%d",i,arrivaltime[i],bursttime[i]);
        printf("\n");
    }
    int c=0;
    int initialwaiting;
    int time = arrivaltime[1];
    for(i=1;i<=n;i++)
    {
        initialwaiting = bursttime[1]-arrivaltime[i+1];
        if(arrivaltime[i+1]<bursttime[1])
            c++;
        if(c>0)
        {
            priority(initialwaiting,bursttime[i+1]);
        }
    }
    //printf("%d",initialwaiting[3]);


}
