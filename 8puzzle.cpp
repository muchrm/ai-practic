#include<iostream>
#include<stdlib.h>
using namespace std;
struct tract{
	tract* link;
	int arr[3][3];
	int score;
	int level;
};
tract *first=NULL,*last=NULL;
int checkscore(int arr[][3]){
	int  checkarr[3][3]={1,2,3,4,5,6,7,8,0};
	int score = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<3;l++)
				{
					if(arr[i][j]==checkarr[k][l]&&arr[i][j]!=0)
						{
							score += abs(i-k)+abs(j-l);
						}
				}
			}
		}
	}
	return score;
}
void swaparray(int arr[][3],int i,int j,int k,int l)
{
	int temp = arr[i][j];
	arr[i][j]= arr[k][l];
	arr[k][l]= temp;
}

void insert(int arr[][3],int level)
{
    tract *current; //pointer to traverse the list
    tract *trailCurrent; //pointer just before current
    tract *newNode; //pointer to create a node
    bool found;

    newNode = new tract; //create the node
    for(int k = 0;k<3;k++)
		{
			for(int l = 0;l<3;l++)
			{
				newNode->arr[k][l]=arr[k][l];
			}
		}
	int num = checkscore(arr);
	newNode->score = num+level; 
	newNode->score = num+level;
	newNode->level = level;
	newNode->link=NULL;
	newNode->level=level;
    if (first == NULL) //Case 1
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        current = first;
        found = false;

        while (current != NULL && !found) //search the list
            if (current->score >= newNode->score)
                	found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == first) //Case 2
        {
            newNode->link = first;
            first = newNode;
        }
        else //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
                last = newNode;
        }
    }//end else
}//end insert

void check4sign(int arr[][3],int level){
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]==NULL)
			{

				if(i-1>=0){
					swaparray(arr,i,j,i-1,j);
					insert(arr,level);
					swaparray(arr,i,j,i-1,j);
				}
				if(j-1>=0){
					swaparray(arr,i,j,i,j-1);
					insert(arr,level);
					swaparray(arr,i,j,i,j-1);
				}
				if(j+1<=2){
					swaparray(arr,i,j,i,j+1);
					insert(arr,level);
					swaparray(arr,i,j,i,j+1);
				}
				if(i+1<=2){
					swaparray(arr,i,j,i+1,j);
					insert(arr,level);
					swaparray(arr,i,j,i+1,j);
				}
			}
		}
	}
}
void game(int arr[][3])
{
	int count = 0;
	while(checkscore(arr)!=0){
	if(first==NULL)
	{
		check4sign(arr,0);
	}
	else
	{
		int k=1;
		while(checkscore(first->arr)!=0){
		tract *curr = first;
		first=first->link;
		cout<<"Round:"<<count<<endl;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<curr->arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		check4sign(curr->arr,curr->level+1);
		if(count>1000)
		{
			cout<<"Unsolvable puzzle"<<endl;
			return;
		}
		count++;
		}
		cout<<"Round:"<<count<<endl;
		tract *curr = first;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<curr->arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	if(count>1000)
		{
			cout<<"Unsolvable puzzle"<<endl;
			return;
		}
		count++;
	}
}

int main(){

	int  arr[3][3];
	/*
	0 1 3 
	4 2 5 
	7 8 6 
	
	
	*/
	cout<<"Input number 0-8"<<endl;
	for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>arr[i][j];
			}
		}
	game(arr);
}
