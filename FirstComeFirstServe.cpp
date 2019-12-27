#include <iostream>
#include <conio.h>

using namespace std;

int main() {
  int numProcess;
  cout<<"\nFirst Come First Serve";
  cout<<"\nEnter the total number of processes: ";
  cin>>numProcess;
  int arrivalTime[numProcess], burstTime[numProcess], completionTime[numProcess], waitingTime[numProcess], turnAround[numProcess];
  if (numProcess <= 0)
    return 1;
  for (int i = 0; i < numProcess; i++) {
    cout<<"\nEnter the arrival time of P%d: ", i + 1;
    cin>>arrivalTime[i];
    if (arrivalTime[i] < 0) {
      return 1;
      i--;
      continue;
    }
    cout<<"Enter the burst time of P%d: ", i + 1;
    cin>>burstTime[i];
    if (burstTime[i] < 0) {
      return 1;
      i--;
      continue;
    }
  }

  for (int i = 0; i < numProcess; i++) {
    completionTime[i] = 0;
  }

  for (int i = 0; i < numProcess; i++) {
    for (int j = 0; j <= i; j++) {
      completionTime[i] += burstTime[i];
    }
  }

  int sumTAT = 0;
  int sumWT = 0;
  double avgTAT;
  double avgWT;
  for (int i = 0; i < numProcess; i++) {
		turnAround[i] = completionTime[i] - arrivalTime[i];
		waitingTime[i] = turnAround[i] - burstTime[i];
		sumTAT = sumTAT + turnAround[i];
		sumWT = sumWT + waitingTime[i];
    cout<<"\n[TAT]%d, %d\n[WT]%d, %d", sumTAT, turnAround[i], sumWT, waitingTime[i];
  }
  cout<<"\n%d\nSumTAT: %d, SumWT: %d", numProcess, sumTAT, sumWT;
  avgTAT = sumTAT / numProcess;
	avgWT = sumWT / numProcess;

  cout<<"\n==================== RESULTS =====================";
  cout<<"\nProcess \tAT \t BT \t CT \t TAT \t WT";
	for (int i = 0; i < numProcess; i++) {
		cout<<"\nP%d\t\t%dms\t %dms\t %dms\t %dms\t %dms", (1 + i), arrivalTime[i], burstTime[i],completionTime[i],turnAround[i], waitingTime[i];
	}
	cout<<"\nAverage Turn Around Time: %.2f", avgTAT;
	cout<<"\nAverage Waiting Time: %.2f", avgWT;
  return 0;
}
