#include<stdio.h>
void countVotes(int votes[], int n, int candidate[]) /*counts the vote for the candidate*/
{
    for(int i=0;i<n;i++)
    {
        candidate[votes[i]-1]++; /*checking which candidate is getting the votes*/
    }
}

int findwinner(int candidate[])
{
    int max_index=0;
    for(int i=1;i<5;i++)  /*i starts from 1 because the candidate liost starts from 1*/
    {
        if(candidate[i]>candidate[max_index])
        {
            max_index=i;
        }
    }
    return max_index+1; 
    
}
void readvotes(int votes[], int n)
{
    printf("enter votes:(1,2,3,4,5)");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&votes[i]);
    }
}

int main()
{
    int n;
    printf("enter the number of votes:");
    scanf("%d",&n);

    int votes[100];
    readvotes(votes,n);

    int candidate[5]={0,0,0,0,0};
    countVotes(votes,n,candidate);
    for(int i=0;i<5;i++)  /*printing for the 5 candidates*/
    {
        printf("candidate %d: %d votes\n",i+1,candidate[i]);
    }
    return 0;
}