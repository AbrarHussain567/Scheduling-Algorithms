#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

struct Process 
{ 
int p_id; 
int burst_time; 
}; 

bool comparison(Process a, Process b) 
{ 
	return (a.burst_time < b.burst_time); 
} 
 
void WaitingTime(Process proc[], int n, int waiting_time[]) 
{ 
	waiting_time[0] = 0; 

	for (int i = 1; i < n ; i++ ) 
		waiting_time[i] = proc[i-1].burst_time + waiting_time[i-1] ; 
} 

void TurnAroundTime(Process proc[], int n, 
						int waiting_time[], int turn_around_time[]) 
{ 
	for (int i = 0; i < n ; i++) 
		turn_around_time[i] = proc[i].burst_time + waiting_time[i]; 
} 
void AverageTime(Process proc[], int n) 
{ 
	int waiting_time[n], turn_around_time[n], total_waiting_time = 0, total_turn_around_time = 0; 
	WaitingTime(proc, n, waiting_time); 
	TurnAroundTime(proc, n, waiting_time, turn_around_time); 
	cout << "\nProcesses "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";  
	for (int i = 0; i < n; i++) 
	{ 
		total_waiting_time = total_waiting_time + waiting_time[i]; 
		total_turn_around_time = total_turn_around_time + turn_around_time[i]; 
		cout << " P" << proc[i].p_id << "\t\t"
			<< proc[i].burst_time << "\t " << waiting_time[i] 
			<< "\t\t " << turn_around_time[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_waiting_time / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_turn_around_time / (float)n; 
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
	sort(proc, proc + n, comparison); 

	cout << "Order in which process gets executed\n"; 
	for (int i = 0 ; i < n; i++) 
		cout << proc[i].p_id <<" "; 

	AverageTime(proc, n); 
	return 0; 
} 

