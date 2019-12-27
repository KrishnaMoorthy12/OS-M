print('First Come First Serve')
num_processes = int(input('Enter total number of processes: '))

arrival_time = []
burst_time = []
for i in range(0, num_processes):
  arrival_time.append(int(input('Enter arrival time of P'+ str(i+1) + ': ')))
  burst_time.append(int(input('Enter burst time of P'+ str(i+1) + ': ')))
  
completion_time = []

for i in range(0, num_processes, 1):
  completion_time.append(0)

for i in range(0, num_processes, 1):
  for j in range(0, i+1, 1):
    completion_time[i] += burst_time[j]

waiting_time = []
turnaround = []
avg_tat = 0
avg_wt = 0

for i in range(0, num_processes, 1):
  turnaround.append(completion_time[i] - arrival_time[i])
  waiting_time.append(turnaround[i] - burst_time[i])
  avg_tat += turnaround[i]
  avg_wt += waiting_time[i]

avg_tat /= num_processes
avg_wt /= num_processes

print('Process \tAT \tBT \tCT \tTAT \tWT')
for i in range(0, num_processes,1):
  print(" P" + str((1 + i)) + "\t\t" + str(arrival_time[i]) + "ms" + "\t" + str(burst_time[i]) + "ms" + "\t" +str (completion_time[i]) + "ms" + "\t" + str(turnaround[i]) + "ms" + "\t" + str(waiting_time[i]) + "ms")

print("Average Turn Around Time: " + str(avg_tat))
print("Average Waiting Time: " + str(avg_wt))
