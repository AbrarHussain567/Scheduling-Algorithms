#include<iostream> 
using namespace std; 

struct Process 
{ 
int pid;
int bt;
}; 

void WaitingTime(Process proc[], int n, int wt[]) 
{ 
	wt[0] = 0; 

	for (int i = 1; i < n ; i++ ) 
		wt[i] = proc[i-1].bt + wt[i-1] ; 
} 

void TurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{ 
	for (int i = 0; i < n ; i++) 
		tat[i] = proc[i].bt + wt[i]; 
} 

void AverageTime(Process proc[], int n) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	WaitingTime(proc, n, wt); 

	TurnAroundTime(proc, n, wt, tat); 

	cout << "\nProcesses "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	for (int i = 0; i < n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " P" << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t " << wt[i] 
			<< "\t\t " << tat[i] <<endl; 
	} 

	cout << "Average Waiting Time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage Turn Around Time = "
		<< (float)total_tat / (float)n; 
} 

int main() 
{ 
	int n ; 
	cout<<"Enter Number of Processes: ";
	cin>>n;
    Process proc[n]; 
    cout<<"Enter Processes Burst Time: \n";
    int a,j;
	for(j=0;j<n;j++)
	{
		cout<<"P"<<(j+1)<<": ";
		cin>>a;
		proc[j]={(j+1),a};
	}
	AverageTime(proc, n); 
	return 0; 
} 

