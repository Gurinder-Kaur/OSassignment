#include<stdio.h>
 struct fifo{
   int ts,bt,at,wt,turn,proc_no,id;
 }stu[10],tech[10];
int n,awt=0,att=0,prior,t_size=0,s_size=0;

void sort_arrival(struct fifo *a,int size){
  int temp;
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(a[i].at>a[j].at)
			{
				temp=a[j].at;
				a[j].at=a[i].at;
				a[i].at=temp;
				temp=a[j].bt;
				a[j].bt=a[i].bt;
				a[i].bt=temp;
        temp=a[j].id;
				a[j].id=a[i].id;
				a[i].id=temp;
			}
		}
  }
}

void callprocess(struct fifo *tc, int t,struct fifo *st,int s){
  int i,j=0,k=0,time=0,ct=0;
for(i=0;i<n;i++){
  int f=0;
  if((t==0 && s!=0)||(t!=0 && st[k].at<tc[j].at &&k+1<=s &&time<=st[k].at))
  f=1;
  if(t!=0 && ct<3 && j<t && f==0){
    if(tc[j].at>=time){
      tc[j].wt=0;
    }
    else{
      tc[j].wt=time-tc[j].at;
    }
    awt=awt+tc[j].wt;
    tc[j].turn=tc[j].wt+tc[j].bt+tc[j].at;
    time=tc[j].turn;
    att=att+tc[j].turn;
    tc[j].proc_no=i;
    ct+=1;
    j++;
  }
  else if(s!=0 && k<s){
    if(st[k].at>=time){
      st[k].wt=0;
    }
    else{
      st[k].wt=time-st[k].at;
    }
    awt=awt+st[k].wt;
    st[k].turn=st[k].wt+st[k].bt+st[k].at;
    time=st[k].turn;
    att=att+st[k].turn;
    st[k].proc_no=i;
    ct=0;
    k++;
  }
}
awt=awt/n;
att=att/n;
}

void print_data(struct fifo *tc, int t,struct fifo *st,int s){
  int i,k=0,j=0;
  printf("PROCESS    TEACHER/STUDENT    ArrivalTime   BurstTime   WaitingTime   TurnaroundTime\n");
  for(i=0;i<n;i++){
    if(tc[j].proc_no==i){
    printf("     %d      T - %d                  %d            %d            %d               %d\n",tc[j].proc_no,tc[j].id,tc[j].at,tc[j].bt,tc[j].wt,tc[j].turn);
     j++;
    }
    if(st[k].proc_no==i){
    printf("     %d      S - %d                  %d            %d            %d               %d\n",st[k].proc_no,st[k].id,st[k].at,st[k].bt,st[k].wt,st[k].turn);
     k++;
    }
  }
  printf("\nAverage Waiting Time is %d\n",awt);
  printf("Average Turnaround Time is %d\n",att);
}

int main(){
  printf("\n\n            ---------------Welcome To Library---------------\n");
  printf("    Let 5 unit time is taken by every teacher/student to issue book from library\n");
  printf("                 i.e burst taken for each process is 5 units\n\n");
  printf("\n                      ****** ENTER DETAILS ******\n\n");


  printf("Enter number of processes :");
  scanf("%d",&n );
  int j=0,k=0;
  for(int i=0;i<n;i++){
    printf("Process %d: Teacher/Student(0/1) : ",i+1);
    scanf("%d",&prior);
    if(prior==0){
      printf("Enter Arrival time for Process %d : ",i+1);
      scanf("%d",&tech[t_size].at);
      printf("Enter id : ");
      scanf("%d",&tech[t_size].id);
      tech[t_size].bt=5;
      tech[t_size].ts=0;
      t_size++;
    }
    else if(prior==1){
      printf("Enter Arrival time for Process %d : ",i+1);
      scanf("%d",&stu[s_size].at);
      printf("Enter id : ");
      scanf("%d",&stu[s_size].id);
      stu[s_size].bt=5;
      stu[s_size].ts=1;
      s_size++;
    }
    else
      printf("Invalid choice\n");
    }
 sort_arrival(tech,t_size);
 sort_arrival(stu,s_size);
 callprocess(tech,t_size,stu,s_size);
 print_data(tech,t_size,stu,s_size);

 printf("        ---------------------------------------------\n");
 printf("To minimize waiting time for student \nafter every three consecutive teacher processes student process is called");
}
