#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h> 
#include<pthread.h> 
struct solution
{
	int cmpl_time;
	int p_id;
	int btr;
	int a_time;
	int b_time;
}Fnl[100],Faculty[100],Student[100];

void *myThreadFun(void *vargp)  
{
      system("CLS");
      printf(" \n");
	  printf(" \n");
	  printf("\t\t\t\t ================================================= \n");
	  printf("\t\t\t\t||                                               || \n");
	  printf("\t\t\t\t||\t   ___      ____    ____   ______   \t ||\n");
	  printf("\t\t\t\t||\t .'   `.   |_   \\  /   _|.' ____ \\   \t || \n");
	  printf("\t\t\t\t||\t/  .-.  \\    |   \\/   |  | (___ \\_|   \t ||\n");
	  printf("\t\t\t\t||\t| | \\ | |    | |\\  /| |   _.____`.    \t ||\n");
	  printf("\t\t\t\t||\t\\  `-'  \\_  _| |_\\/_| |_ | \\____) |   \t ||\n");
	  printf("\t\t\t\t||\t `.___.\\__||_____||_____| \\______.'   \t ||\n");
	  printf("\t\t\t\t||                                               || \n");
	  sleep(1); 
	  printf(" \t\t\t\t||\t  ___(Query Management System)___\t ||\n");
	  printf("\t\t\t\t ================================================= \n");
	  sleep(1); 
	  system("COLOR 17");
	  sleep(1); 
	  system("COLOR 47");
	  sleep(1); 
	  system("COLOR 70");
	  printf("\n\n\n\n\n\n\n\n\t\t\t                   (Press any key to continue)\n");
	  printf("---------------------------------------------------------------------------------------------------------------------");
	  getch();
	  return NULL;  
}

int n , f_count=0 , s_count=0, fnl_count=0 , quant_time=0;

void f1()
{
	int n,i,t;
	char ts; //teacher or student identification
	printf("\n-------------------------------------------------- Instructions  ----------------------------------------------------\n\n");
	printf("\n 1)The time alloted for solving queries is from 10:00 to 12:00 so enter time from 1000 to 1200. ");
	printf("\n 2)Enter time in  24 hours format. \n\n\n");
	printf("  Please enter the details:  \n\n");
	printf("\n-> How many queries you want to enter(specify in digit)  :\t");
	scanf("%d",&n);
	printf("\n");
	for (i=0;i<n;i++)
	{
		p:
		printf("\n ->Enter T/t if you are a Faculty or Enter S/s if you are a Student :  ");
		scanf("\n");
		scanf("%c",&ts);
		printf("\n");
		if (ts=='T' || ts=='t')
		{
			printf("\n ------>Process ID of Faculty(specify in digit) :\t");
			scanf("%d",&Faculty[f_count].p_id);
			x:
			printf("\n ->Specify Arrival time(in 24 hours format):\t"); 
			scanf("%d",&t);
			if(t<1000 || t>1200){
					printf("\n Query entry is alloted time between 10:00 to 12:00 \n");
					goto x;
				}
			if (t>=1060 && t<1100){
				printf("\n Enter time in  24 hours format \n");
				goto x;
			}
			if(t>=1160 && t<1200){
				printf("\n Enter time in  24 hours format \n");
				goto x;
			}
			if(t==1200){
				printf("\n ***We are no longer taking queries -> Time over*** \n");
				goto x;
			}
			else{Faculty[f_count].a_time= t-1000;}
				printf(" ->Specify Burst time(in digits):\t"); 
				scanf("%d", &Faculty[f_count].b_time);
				printf("---------------------------------------------------------------------------------------------------------------------");	 
				Faculty[f_count].btr = Faculty[f_count].b_time; 
				f_count++;
		}		
		if(ts=='S' || ts=='s')
		{
			printf("\n ------>Process ID of Student(specify in digit):\t");
			scanf("%d",&Student[s_count].p_id);
			y:
			printf("\n ->Specify Arrival time(in 24 hours format):\t"); 
			scanf("%d",&t);
			if(t<1000 || t>1200){
				printf("\n Query entry is alloted time between 10:00 to 12:00  \n");
				goto y;
			}
			if (t>=1060 && t<1100){
				printf("\n Enter time in  24 hours format \n");
				goto y;
			}
			if(t>=1160 && t<1200){
				printf("\n Enter time in  24 hours format \n");
				goto y;
			}
			if(t==1200){
				printf("\n ***We are no longer taking queries -> Time over*** \n");
				goto y;
			}
			else{Student[s_count].a_time= t-1000;}
				printf(" ->Specify Burst time(in digits):\t"); 
				scanf("%d", &Student[s_count].btr);	 
				printf("---------------------------------------------------------------------------------------------------------------------");
				Student[s_count].b_time = Student[s_count].btr; 
				s_count++;
				
		}
		else { printf(" -> Wrong Choice ");  goto p;  }	
	}
	printf("\n\n ->Enter time quantum for round robin scheduling:\t");
	scanf("%d",&quant_time);
	
}
void f2()
{
	int i, exec_ttl=0;
	int trn_ttl=0; 
	double average=0;
	printf("\n\n _______________________________________________________________________________________________________________");
	printf("\n| Process_ID \t| Arrival_Time\t| Burst_Time\t| Completion_Time\t| TurnAround_Time\t| Waiting_Time  |");
    
	for(i=0; i<fnl_count; i++){
		int id = Fnl[i].p_id;
		int art=Fnl[i].a_time+1000;
		int btr=Fnl[i].btr;
		int cpt=Fnl[i].cmpl_time+1000;
		int trn=Fnl[i].cmpl_time-Fnl[i].a_time;
		int wat=(Fnl[i].cmpl_time-Fnl[i].a_time) - Fnl[i].btr;
		printf("\n|_______________|_______________|_______________|_______________________|_______________________|_______________|");
		printf("\n| %d\t\t| %d\t\t| %d\t\t| %d\t\t\t| %d\t\t\t| %d\t\t|",id,art,btr,cpt,trn,wat);
		printf("\n|_______________|_______________|_______________|_______________________|_______________________|_______________|");
	    
		exec_ttl=Fnl[0].cmpl_time;
		if(exec_ttl<Fnl[i].cmpl_time){
			exec_ttl=Fnl[i].cmpl_time;
		}
		trn_ttl+=trn;
	}
	average = (trn_ttl/fnl_count);
	if (exec_ttl>=100){
		exec_ttl=exec_ttl-40;
	}
	if(exec_ttl>=200){
		exec_ttl=exec_ttl-80;
	}
	printf("\n\n\n->TOTAL TIME SPENT TO PROCESS ALL QUERIES: %d min", exec_ttl);
	printf("\n\n->AVERAGE QUERY PROCESSING TIME : %lf min\n\n", average);

}

void compare() 
{
	int nf=0 , ns=0;
	if(f_count!=0 && s_count!=0){
		while(nf<s_count && nf<f_count ){
			if(Faculty[nf].a_time ==  Student[ns].a_time)
			{
				Fnl[fnl_count] = Faculty[nf];
				fnl_count++;
				nf++;
				Fnl[fnl_count] = Student[ns];
				fnl_count++;
				ns++;
			}
			if(Faculty[nf].a_time<Student[ns].a_time){
				Fnl[fnl_count]=Faculty[nf];
				fnl_count++;
				nf++;
			}
			if(Faculty[nf].a_time>Student[ns].a_time){
				Fnl[fnl_count]=Student[ns];
				fnl_count++;
				ns++;
			}
			
		}
		if (fnl_count != (f_count + s_count)){
			if(f_count!=nf){
				while(nf!=f_count){
					Fnl[fnl_count]=Faculty[nf];
					fnl_count++;
					nf++;
				}
			}
			if (s_count!=ns){
				while(ns!=s_count){
					Fnl[fnl_count]=Student[ns];
					fnl_count++;
					ns++;	
					
				}
			}
		}

	}
	if(f_count==0){
		while(ns!=s_count){
			Fnl[fnl_count]=Student[ns];
			fnl_count++;
			ns++;
		}
	}
	if(s_count==0){
		while(nf!=f_count){
			Fnl[fnl_count]=Faculty[nf];
			fnl_count++;
			nf++;
		}
	}
}
void rr()
{
	int t=Fnl[0].a_time,mk=0, c=0 ,i, rc;
	while(t!=120 && c!=fnl_count){
		for(i=0; i<=mk;i++){
			if(Fnl[i].b_time>quant_time){
				t+=quant_time;
				Fnl[i].b_time-=quant_time;
			}
			if(Fnl[i].b_time<=quant_time && Fnl[i].b_time!=0){
				t+=Fnl[i].b_time;
				Fnl[i].b_time=0;
				Fnl[i].cmpl_time = t;
				c++;
			}
		}
		int st=mk+1;
		for(rc=st;rc<fnl_count;rc++){
			if(Fnl[rc].a_time<=t){
				mk++;
			}
		}
	}
	
}

int main()
{
	pthread_t thread_id; 
 	pthread_create(&thread_id, NULL, myThreadFun, NULL);      
	pthread_join(thread_id, NULL);
	f1();
	compare();
	rr();
	f2();
}
