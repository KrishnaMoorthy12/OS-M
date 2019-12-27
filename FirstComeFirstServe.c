#include <stdio.h>
#include <conio.h>

void main() {
  int numProcess;
  printf("\nFirst Come First Serve");
  printf("\nEnter the total number of processes: ");
  scanf("%d", &numProcess);
  int arrivalTime[numProcess], burstTime[numProcess], completionTime[numProcess], waitingTime[numProcess], turnAround[numProcess];
  if (numProcess <= 0)
    perror("Invalid number");
  for (int i = 0; i < numProcess; i++) {
    printf("\nEnter the arrival time of P%d: ", i + 1);
    scanf("%d", &arrivalTime[i]);
    if (arrivalTime[i] < 0) {
      perror("Invalid number");
      i--;
      continue;
    }
    printf("Enter the burst time of P%d: ", i + 1);
    scanf("%d", &burstTime[i]);
    if (burstTime[i] < 0) {
      perror("Invalid number");
      i--;
      continue;
    }
    scanf("");
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
    printf("\n[TAT]%d, %d\n[WT]%d, %d", sumTAT, turnAround[i], sumWT, waitingTime[i]);
  }
  printf("\n%d\nSumTAT: %d, SumWT: %d", numProcess, sumTAT, sumWT);
  avgTAT = sumTAT / numProcess;
	avgWT = sumWT / numProcess;

  printf("\n==================== RESULTS =====================");
  printf("\nProcess \tAT \t BT \t CT \t TAT \t WT");
	for (int i = 0; i < numProcess; i++) {
		printf("\nP%d\t\t%dms\t %dms\t %dms\t %dms\t %dms", (1 + i), arrivalTime[i], burstTime[i],completionTime[i],turnAround[i], waitingTime[i]);
	}
	printf("\nAverage Turn Around Time: %.2f", avgTAT);
	printf("\nAverage Waiting Time: %.2f", avgWT);
}
