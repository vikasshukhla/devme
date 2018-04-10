#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


struct sjfprocess
{
    int processid,arrivaltime,bursttime;
};

void swapping1(double *mn,double *op);
void swapping(int *mn, int *op);
void sorting(double array[],int array1[] ,int n);


void sorting1(struct sjfprocess *t,int p)
{
	int i,j;
	struct sjfprocess *q ,s;
	for(i=0;i<p;i++,t++)
	{
		for(j=i+1,q=t+1;j<p;j++,q++)
		{
			if((t->arrivaltime)>(q->arrivaltime))
				{
					s=*t;
					*t=*q;
					*q=s;
				}
		}
	}
}

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
    system("cls");
	int v=n-1;
	sorting1(pro,n);
	int array1[n],array2[n];
	int array3[n];
	int r;

	printf("\n\nProcessId\tArrival time\tBurst time\t\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d\n",pro[i].processid,pro[i].arrivaltime,pro[i].bursttime);//tat and wt
		array1[i]=pro[i].processid;
	}
	for(i=0;i<n-1;i++)
	{
		array2[i]=array1[i+1];
	}
  printf("\n\n\t\t\tGANTT CHART OF THE PROCESS ACCORDING TO GIVEN PRIORITY\n\n\t\t\t");
	int m=n-1;
	int t=0;
	if(0==pro[0].arrivaltime)
	{
	printf(" 0 ");
	}
	else
	{
		printf(" 0  %d",pro[0].arrivaltime);
		t=t+pro[0].arrivaltime;
	}
	t=t+pro[0].bursttime;
	printf("  P%d  %d",pro[0].processid,t);
	completiontime[1]=t;

    do
	{
		int tmp=0,j,u;
		for( j=0;j<m;j++)
		{
			for( u=0;u<n;u++)
			{
				if(array2[j]==pro[u].processid)
				{
					if(pro[u].arrivaltime<=t)
					{
						array3[tmp++]=pro[u].processid;
					}
				}
			}
		}
		int tmp1=tmp+1;
		double array4[tmp1];
		int tmp2=4,k,o;
		for( k=0;k<tmp1-1;k++)
		{
			for( o=0;o<n;o++)
			{
				if(array3[k]==pro[o].processid)
				{
					array4[k]=1+(double)(t-pro[o].arrivaltime)/pro[o].bursttime;
				}
			}
		}
    sorting(array4,array3,tmp1-1);
		int f=array3[0],i;
		for(i=0;i<n;i++)
		{
			if(tmp!=0)
			{
				if(pro[i].processid==f)
				{
					t=t+pro[i].bursttime;
				}
			}
		}
		int flag=5;
		if(tmp==0 && v>0)
		{
			for(i=0;i<n;i++)
			{
				if(t<pro[i].arrivaltime)
				{
     				t=pro[i].arrivaltime+pro[i].bursttime;
					printf("  %d  P%d  %d",pro[i].arrivaltime,pro[i].processid,t);

					break;
					flag=9;
				}
			}
		}
		else
		{
			printf("  P%d  %d",f,t);
			completiontime[f]=t;//2
		//	printf("**%d",ct[f]);//3
			v--;
		}
	      	for(i=0; i<m; i++)
			{
				if(array2[i]==f)
				{
					for(j=i; j<(m-1); j++)
					{
						array2[j]=array2[j+1];
					}
			    	break;
				}
			}
			m=m-1;
	}
	while(m>0);
  float sum1=0,sum2=0;
		for (i=0;i<n;i++)
		{
			turnaroundtime[i]=completiontime[i+1]-pro[i].arrivaltime;
        }

	    for (i=0;i<n;i++)
		{
			waitingtime[i]=turnaroundtime[i]-pro[i].bursttime;
        }

	 for(i=0;i<n;i++)
	 {
	 sum1=sum1+turnaroundtime[i];
	 sum2=sum2+waitingtime[i];
	 }

	 printf("\n\n\nProcessId\tArrival time\tBurst time\tTurnAround Time\t\tWating Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",pro[i].processid,pro[i].arrivaltime,pro[i].bursttime,turnaroundtime[i],waitingtime[i]);
    }

	float avgwaiting,avgturnaround;
	avgturnaround=sum1/n;
	avgwaiting=sum2/n;
	printf("\n\n");
	printf("Average TurnAround Time = %f",avgturnaround);
	printf("\t\t\tAverage Waiting Time = %f",avgwaiting);
	printf("\n\n\n");

}

void swapping1(double *mn,double *op)
{
	double temp = *mn;
	*mn = *op;
	*op = temp;
}

void swapping(int *mn, int *op)
{
	int temp = *mn;
	*mn = *op;
	*mn = temp;
}
}
  void sorting(double array[],int array1[] ,int n)
  {
  	int i, j;
  	int min_idx;
  	for (i = 0; i < n-1; i++)
  	{
  		min_idx = i;
  		for (j = i+1; j < n; j++)
  		if (array[j] < array[min_idx])
  		min_idx = j;
  		swapping(&array[min_idx], &array[i]);
  		swapping1(&array1[min_idx], &array1[i]);
  	}
  }
