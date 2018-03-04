#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct sjfprocess
{
    int processid,arrivaltime,bursttime;
};

main()
{   int completiontime[30];
    struct sjfprocess pro[50];
    int arrivaltime,bursttime;

    int i,n;
	printf("Enter no. of process\n");
    scanf("%d",&n);
    int turnaroundtime[n],waitingtime[n];

    printf("Enter Arrival time & Burst time for every process\n");

    for(i=0;i<n;i++)
    {
        printf("Enter process ID for process %d : ", i+1);
        scanf("%d",&pro[i].processid);
        printf("\n Arrival time for P%d : ",i+1);
        scanf("%d",&pro[i].arrivaltime);
        printf("\n Burst time for P%d   : ",i+1);
        scanf("%d",&pro[i].bursttime);
    }
