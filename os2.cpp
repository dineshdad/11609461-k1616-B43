
#include<stdio.h>
int n;
struct process
{
	 char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
}process_queue[10];

int main()
{
	int i;
	  int time = 0, burst_time = 0, largest,x[10];float a,b;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
	printf("enter the no. of processes\n");
scanf("%d",&n);
  for(i = 0, c = 'P'; i < n; i++, c++)
      {
            process_queue[i].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].arrival_time );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].burst_time);
    
            process_queue[i].status = 0;
            burst_time = burst_time + process_queue[i].burst_time;
      }
     struct process temp;
      int j;
      for(i = 0; i < n - 1; i++)
      {
            for(j = i + 1; j < n; j++)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
	  for(int i=0;i<n;i++)
	  {
	  	x[i]=process_queue[i].burst_time;
	  }
	  process_queue[9].burst_time = 9999;
   for(time = process_queue[0].arrival_time; time <= burst_time+1;)
      {
      	 largest = 9;
      	for(i=0;i<n;i++)
      	{
      		
      
      		 if(process_queue[i].arrival_time <= time && process_queue[i].burst_time < process_queue[largest].burst_time && process_queue[i].status != 1)
                  {
                        largest = i;
                   
                  }
                if(process_queue[largest].burst_time==0 && process_queue[i].status != 1)
      		{
      			process_queue[i].status = 1;
      			process_queue[largest].ct=time;process_queue[largest].burst_time=9999;
      	
			  i=-1;
      			
      		}
      	}
      	
      	time++;(process_queue[largest].burst_time)--;
      
      }printf("\n*****************************************************\n");
       for(i=0;i<n;i++)
      {
      	process_queue[i].turnaround_time=(process_queue[i].ct)-(process_queue[i].arrival_time);a=a+process_queue[i].turnaround_time;
      	process_queue[i].waiting_time=((process_queue[i].turnaround_time)-x[i]);b=b+process_queue[i].waiting_time;
      } 
   printf("PNO\tAT\tCT\tTA\t\WTt\n");
        for(i=0;i<n;i++)
      {
  
      	printf("%c\t%d\t%d\t%d\t%d\n",
		  process_queue[i].process_name,
		  process_queue[i].arrival_time,
		  process_queue[i].ct,
		  process_queue[i].turnaround_time,
		  process_queue[i].waiting_time);
		  
      }
      printf("THE AVERAGE TURNAROUND TIME IS \t %f\t\n\n",a/n);
          printf("THE AVERAGE WAITING TIME IS \t %f\t\n\n\n\n",b/n);printf("\n*****************************************************\n");
}








