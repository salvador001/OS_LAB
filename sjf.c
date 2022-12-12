#include<stdio.h>

int main()
{
    int time, bt[10], at[10], smallest, i, n, total_burst_time = 0;;
    int avg_tat = 0, avg_wait = 0;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    for(i=0 ; i<n ; i++){
        printf("Enter the arrival and burst time of process %d", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        total_burst_time += bt[i];
    }

    bt[9] = 9999;
    for(time = 0 ; time<total_burst_time ;){
        smallest = 9;
        for(i=0 ; i<n ; i++){
            if(at[i] <= time && bt[i] > 0 && bt[i] < bt[smallest]){
                smallest = i;
    
            }
        }

        printf("Process[%d]\t\t%d\t\t%d\n", smallest+1, time+bt[smallest]-at[smallest], time-at[smallest]);
        avg_tat += time+bt[smallest]-at[smallest];
        avg_wait += time-at[smallest];
        time += bt[smallest];
        bt[smallest] =0;
    }
                printf("\n\n average waiting time = %f",   avg_wait * 1.0 / n);
  printf("\n\n average turnaround time = %f",  avg_tat * 1.0 / n);
}