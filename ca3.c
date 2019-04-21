#include<stdio.h>
void main()
{
    int n,pro[20],pri[20],prio[20],bt[20],q1[20],q2[20],q3[20],b1[20],b2[20],b3[20],tat[20],wt[20],i;
	int m=0,h=0,g=0,p=0;
	//Considering arrival time=0 for all processes
	printf("Enter the number of processes");
    scanf("%d",&n);
	printf("Enter the process with their priority & burst time");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pri[i]);
		scanf("%d",&bt[i]);
		pro[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
	if(pri[i]>=1 && pri[i]<=3)
	{
		q1[m]=pro[i];
		b3[m]=bt[i];
		m++;
	}
	else if(pri[i]>3 && pri[i]<=6)
	{
		q2[h]=pro[i];
		b2[h]=bt[i];
		prio[h]=pri[i];
		h++;
	}
	else
	{
		q3[g]=pro[i];
		b1[g]=bt[i];
		g++;
	}
    }
	printf("Processes in queue 3 for Round Robin Scheduling\n");
	for(i=0;i<g;i++)
	{
		printf("p%d\n",q3[i]);
	}
	printf("\n");
	printf("Processes in queue 2 for Priority Scheduling\n");
	for(i=0;i<h;i++)
	{
		printf("p%d\n",q2[i]);
	}
	printf("\n");
	printf("Processes in queue 1 for First Come First Serve\n");
	for(i=0;i<m;i++)
	{
		printf("p%d\n",q1[i]);
	}
	printf("\n");
	int tq=4,rem[20];
	printf("Processes\tTurnAroundTime\t\tWaitingTime\n");
	for(i=0;i<g;i++)
	{
		rem[i]=b1[i];
	}
   //printf("for q3:\n");
   A:
    	while(1)
    	{
    		int flag=0;
	for(i=0;i<g;i++)
	{	
	if(p>10)
	goto B;
	else
		if(rem[i]>0)
		{
			flag=1;
				if(rem[i]>tq)
				{
				 p=p+tq;
				 rem[i]=rem[i]-tq;
				}
				else
				{
					p=p+rem[i];
					rem[i]=0;
					wt[i]=p-b1[i];
				}
    }
    }
   
    if(flag==0)
    {
     for(i=0;i<g;i++)
{
	tat[i]=b1[i]+wt[i];
	printf("p%d\t\t\t%d\t\t\t%d\n",q3[i],tat[i],wt[i]);
}
    break;
}
}
   //printf("for q2:\n");
    int j,tp,ts;
   B:
    for(i=0;i<h;i++)
    {
    	for(j=i+1;j<m;j++)
    	{
    	if(prio[j]>prio[i])
    	{
            tp=b2[j];
    		b2[j]=b2[i];
    		b2[i]=tp;
    		
    		ts=q2[j];
    		q2[j]=q2[i];
    		q2[i]=ts;		
		}
        }
	}
	//printf("for q1:\n");
	for(i=0;i<h;i++)
    {
    	if(p>20)
    	goto C;
    	else
    	{
    	p+=b2[i];
		printf("p%d\t\t\t%d\t\t\t%d\n",q2[i],p,(p-b2[i]));
     	}
    }
   C:
    for(i=0;i<m;i++)
    { 
    	p=p+b3[i];
    	printf("p%d\t\t\t%d\t\t\t%d\n",q1[i],p,(p-b3[i]));
        }
	}
