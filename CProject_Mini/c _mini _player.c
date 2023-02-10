#include<stdio.h>
#include<string.h>
typedef struct player
{
    char name[20];
	int Jercy_no;
	int matches,runs,wickets;	
}player;
void storearray(player*,int);
void search_name(player*,int);
void search_jercy_no(player*,int);
void search_max_run(player*,int);
void search_max_wic(player*,int);
void update_rec(player*,int,char*);
void display_rec(player*,int);
void descend(player*,int,player*);
void greater(player*,int,int);
void sec_max_runs(player*,int,player*);
void max_matches(player*,int);
void remove_add_player(player*,int,char*);
void sum_avg_runs(player*,int);
void main()
{
	int n,op;
	char ch;
	char name[20],name2[20];
	printf("How many players record you want to add:- ");
	scanf("%d",&n);
    player p1[n],temp,sec_max;	
    storearray(p1,n);
    do{
    	printf("\n-----------------------------------------\n");
    	printf("**********Menu************\n");
    	printf("1.Search by Player Name");
    	printf("\n2.Search by Player Jercy No.");
    	printf("\n3.Search by Maximum Runs");
    	printf("\n4.Search by Maximum Wickets");
    	printf("\n5.Update data of player");
    	printf("\n6.Display the record of all players");
    	printf("\n7.Arrange Record in Descending order of runs");
    	printf("\n8.Display data of player having runs greater than:-");
    	printf("\n9.Display info of second max runs obtained player");
    	printf("\n10.Search by Maximum matches played");
    	printf("\n11.Remove and add a new players data");
    	printf("\n12.Find sum of runs and its average");
    	printf("\n--------------------------------------------");
    	printf("\n Please enter the choice:-  ");
    	scanf("%d",&op);
    	if(op==1)
    	{
    		search_name(p1,n);
		}
		else if(op==2)
		{
			search_jercy_no(p1,n);
		}
		else if(op==3)
		{
			search_max_run(p1,n);
		}
		else if(op==4)
		{
			search_max_wic(p1,n);
		}
		else if(op==5)
		{
			printf("\nEnter name of player whose data is to be updated:");
			scanf("%s",name);
			update_rec(p1,n,name);
			display_rec(p1,n);
		}
		else if(op==6)
		{
			display_rec(p1,n);
		}
		else if(op==7)
		{
			descend(p1,n,&temp);
		}
		else if(op==8)
		{
			int runs;
			printf("Enter the runs :-");
			scanf("%d",&runs);
			greater(p1,n,runs);
		}
		else if(op==9)
		{
			sec_max_runs(p1,n,&sec_max);
		}
		else if(op==10)
		{
			max_matches(p1,n);
		}
		else if(op==11)
		{
		   printf("\nEnter name of player whose data is to be removed:");
		   scanf("%s",name2);	
		   remove_add_player(p1,n,name2);
		   display_rec(p1,n);
        }
        else if(op==12)
        {
        	sum_avg_runs(p1,n);
		}
		
		else
		printf("\nSorry wrong choice!");
		fflush(stdin);
		printf("\nDo you want to perform again(Y/N)");
		scanf("%c",&ch);
	}while(ch=='Y');
    
} 
void storearray(player* ptr,int t)
{
	int i=0;
	for(i=0;i<t;i++)
	{
	printf("-------------------------------------------");
	printf("\nEnter Details of player:-%d:",i+1);
	printf("\n-----------------------------------------");
	printf("\nName of Player:-                     ");
	scanf("%s",&ptr[i].name);
	printf("Enter Jercy No:-                       ");
	scanf("%d",&ptr[i].Jercy_no);
	printf("Enter the no. of matches played:-      ");
	scanf("%d",&ptr[i].matches);
	printf("Enter runs:-                           ");
	scanf("%d",&ptr[i].runs);
	printf("Enter wickets taken:-                  ");
	scanf("%d",&ptr[i].wickets);
    }
}
void search_name(player* ptr,int t)
{
	int i,flag=0;
	char name[20];
	printf("\nEnter the name of player to be searched:");
	scanf("%s",name);
	printf("\n----------------------------------------\n");
	for(i=0;i<t;i++)
	{
		if(strcmp(ptr[i].name,name)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\n ------The name has been found-------");
		printf("\nDetails are as follows:\n");
		printf("Name of player:              %s",ptr[i].name);
		printf("\nJercy No. of player:       %d",ptr[i].Jercy_no);
		printf("\nMatches played:            %d",ptr[i].matches);
		printf("\nRuns                       %d",ptr[i].runs);
		printf("\nWickets taken:             %d",ptr[i].wickets);
	}
	else
	{
		printf("\nSorry Name of player not found");
	}
}
void search_jercy_no(player* ptr,int t)
{
	int i,jercy_no,flag=0;
	printf("\nEnter the jercy no. to be searched:");
	scanf("%d",&jercy_no);
	printf("\n----------------------------------------\n");
	for(i=0;i<t;i++)
	{
		if(ptr[i].Jercy_no==jercy_no)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\n ------The Jercy No. has been found-------");
		printf("\nDetails are as follows:\n");
		printf("Name of player:              %s",ptr[i].name);
		printf("\nJercy No. of player:       %d",ptr[i].Jercy_no);
		printf("\nMatches played:            %d",ptr[i].matches);
		printf("\nRuns                       %d",ptr[i].runs);
		printf("\nWickets taken:             %d",ptr[i].wickets);
	}
	else
	{
		printf("Sorry Jercy No. not found");
	}
}
void search_max_run(player* ptr,int t)
{
	int i;
	int max_run;
	max_run=ptr[0].runs;
	for(i=0;i<t;i++)
	{
	    if(ptr[i].runs>max_run)
	    { 
	       max_run=ptr[i].runs;
        }
    }
		printf("\nDetails of player with max runs are as follows:-");	
		printf("\n-----------------------------------------------\n");
		for(i=0;i<t;i++)
		{
			if(max_run==ptr[i].runs)
			{
			    printf("\nPlayer No.:%d",i+1);
				printf("\n-----------------------------------------------\n");	
                printf("\nName of player:            %s",ptr[i].name);
		        printf("\nJercy No. of player:       %d",ptr[i].Jercy_no);
		        printf("\nMatches played:            %d",ptr[i].matches);
		        printf("\nRuns                       %d",ptr[i].runs);
		        printf("\nWickets taken:             %d",ptr[i].wickets);
		        printf("\n-----------------------------------------------\n");
			}
		}
}
void search_max_wic(player* ptr,int t)
{
	int i;
	int max_wic;
	max_wic=ptr[0].wickets;
	for(i=0;i<t;i++)
	{
	    if(ptr[i].wickets>max_wic)
    	{
	      max_wic=ptr[i].wickets;
	    }
    }
	    printf("\nDetails of player with max wickets are as follows:-");
		printf("\n----------------------------------------------------\n");	
		for(i=0;i<t;i++)
		{
			if(max_wic==ptr[i].wickets)
			{	
			    printf("\nPlayer No.:%d",i+1);
			    printf("\n-----------------------------------------------\n");
                printf("\nName of player:            %s",ptr[i].name);
		        printf("\nJercy No. of player:       %d",ptr[i].Jercy_no);
		        printf("\nMatches played:            %d",ptr[i].matches);
		        printf("\nRuns                       %d",ptr[i].runs);
		        printf("\nWickets taken:             %d",ptr[i].wickets);
		        printf("\n-----------------------------------------------\n");
			}
		}
}
void update_rec(player* ptr,int t,char* n1)
{
	int i,j,update,new,flag=0;
	char name[20];
	for(i=0;i<t;i++)
	{
		if(strcmp(ptr[i].name,n1)==0)
		{
			flag=1;
			j=i;
			break;			
     	}
    }
        
	if(flag==1)
    {
	printf("\nYes the name has been found");
	printf("\n------------------------------------------------\n");
	printf("\nWhich data you want to update:\n");
	printf("1.Name\n2.Jercy No.\n3.Matches\n4.Runs\n5.Wickets");
	printf("\nEnter your choice:   ");
	scanf("%d",&update);

	if(update==1)
	{
		printf("Enter the new name of player:");
		scanf("%s",name);
		strcpy(ptr[j].name,name);
	
	}
	else if(update==2)
	{
		printf("\nEnter the new Jercey No.:");
		scanf("%d",&new);
		ptr[j].Jercy_no=new;
	}
	else if(update==3)
	{
		printf("\nEnter the new no. of matches played:");
		scanf("%d",&new);
		ptr[j].matches=new;
	}
	else if(update==4)
	{
		printf("\nEnter the new Runs: ");
		scanf("%d",&new);
		ptr[j].runs=new;
	}
	else if(update==5)
	{
		printf("\nEnter the new Wickets:");
		scanf("%d",&new);
		ptr[j].wickets=new;
	}
	else
	{
		printf("\nWrong Choice");
		printf("\nPlease make a valid choice");
	}
}
}
	
void display_rec(player* ptr,int t)
{
	int i;
	printf("\nList of Players records:-");
	printf("\n---------------------------------------------------------");
	printf("\nPlayer Name\tJercey No.\tMatches\tRuns\twickets");
	printf("\n---------------------------------------------------------\n");
	for(i=0;i<t;i++)
	{
		printf("%s\t\t%d\t\t%d\t%d\t%d\n",ptr[i].name,ptr[i].Jercy_no,ptr[i].matches,ptr[i].runs,ptr[i].wickets);
	}
}
void descend(player* ptr,int t,player* t1)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(ptr[i].runs<ptr[j].runs)
			{
				*t1=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=*t1;
			}
		}
	}
	printf("\n--------------------------------------------------------\n");
	printf("Displaying Players record in descending order of runs:\n");
	printf("---------------------------------------------------------\n");
	printf("\nPlayer Name\tJercey No.\tMatches\tRuns\twickets\n");
	for(i=0;i<t;i++)
	{
		printf("%s\t\t%d\t\t%d\t%d\t%d\n",ptr[i].name,ptr[i].Jercy_no,ptr[i].matches,ptr[i].runs,ptr[i].wickets);
	}
}
void greater(player* ptr,int t,int runs)
{
	int i;
	printf("\nDetails of players having runs greater than %d:",runs);
	printf("\n---------------------------------------------------------\n");
	printf("\nPlayer Name\tJercey No.\tMatches\tRuns\twickets\n");
	for(i=0;i<t;i++)
	{
		if(ptr[i].runs>runs)
		{
			printf("%s\t\t%d\t\t%d\t%d\t%d\n",ptr[i].name,ptr[i].Jercy_no,ptr[i].matches,ptr[i].runs,ptr[i].wickets);
		}
	}	
}
void sec_max_runs(player* ptr,int t,player* s2)
{
	int i;
	int max=ptr[0].runs;
	s2->runs=ptr[1].runs;
	s2->Jercy_no=ptr[1].Jercy_no;
	s2->matches=ptr[1].matches;
	s2->wickets=ptr[1].wickets;
	strcpy(s2->name,ptr[1].name);
	for(i=0;i<t;i++)
	{
		if(ptr[i].runs>max)
		{
			s2->runs=max;
		    max=ptr[i].runs;
     	}
     	else if(ptr[i].runs>s2->runs&&ptr[i].runs!=max)
     	{
     		s2->runs=ptr[i].runs;
		}
	}
	printf("\nPlayer Name\tJercey No.\tMatches\tRuns\twickets\n");
	printf("%s\t\t%d\t\t%d\t%d\t%d\n",s2->name,s2->Jercy_no,s2->matches,s2->runs,s2->wickets);
}
void max_matches(player* ptr,int t)
{
	int i,max_matches;
	max_matches=ptr[0].matches;
	for(i=0;i<t;i++)
	{
		if(ptr[i].matches>max_matches)
		{
			max_matches=ptr[i].matches;
		}
	}
	for(i=0;i<t;i++)
	{
		if(max_matches==ptr[i].matches)
		{
			    printf("\nPlayer No.:%d",i+1);
			    printf("\n-----------------------------------------------\n");
                printf("\nName of player:            %s",ptr[i].name);
		        printf("\nJercy No. of player:       %d",ptr[i].Jercy_no);
		        printf("\nMatches played:            %d",ptr[i].matches);
		        printf("\nRuns                       %d",ptr[i].runs);
		        printf("\nWickets taken:             %d",ptr[i].wickets);
		        printf("\n-----------------------------------------------\n");
		}
	}
}
void remove_add_player(player* ptr,int t,char* n2)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		if(strcmp(ptr[i].name,n2)==0)
		{
			printf("\nYes the name has been found");
			printf("\nEnter Details of new player");
		    printf("\nEnter player name:");
		    scanf("%s",ptr[i].name);
		    printf("Enter jercey no.");
		    scanf("%d",&ptr[i].Jercy_no);
		    printf("Enter no. of matches: ");
		    scanf("%d",&ptr[i].matches);
		    printf("Enter runs:");
		    scanf("%d",&ptr[i].runs);
		    printf("Enter wickets:");
		    scanf("%d",&ptr[i].wickets);
     	}
    }	
	
}
void sum_avg_runs(player* ptr,int t)
{
	int i,sum=0,avg;
	for(i=0;i<t;i++)
	{
		sum=sum+ptr[i].runs;
	}
	printf("\nThe sum of runs of all players: %d",sum);
	avg=sum/t;
	printf("\nThe average of runs: %d",avg);
}
