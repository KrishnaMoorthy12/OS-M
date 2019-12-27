import java.util.Scanner;

class NumberErrorException extends Exception {
	/*
	 * Exception to throw when the input is not possible
	 */
	private static final long serialVersionUID = -2856377272740965184L;

	public String toString() {
		return ("Invalid number.");
	}
}

class FirstComeFirstServe {
	public static void main(String[] args) throws NumberErrorException {
		System.out.println("THE FCFS ALGO");
		Scanner mys = new Scanner(System.in);
		System.out.print("Enter total number of processes: ");
		int numProcess = mys.nextInt();
		if (numProcess <= 0)
			throw new NumberErrorException();
		int arrivalTime[] = new int[numProcess];
		int burstTime[] = new int[numProcess];
		for (int i = 0; i < numProcess; i++) {
			System.out.print("Enter Arrival time of P" + (i + 1) + ": ");
			arrivalTime[i] = mys.nextInt();
			if (arrivalTime[i] < 0)
				throw new NumberErrorException();
			System.out.print("Enter Burst time of P" + (i + 1) + ": ");
			burstTime[i] = mys.nextInt();
			if (burstTime[i] < 0)
				throw new NumberErrorException();
		}

		int completionTime[] = new int[numProcess];
		for (int i = 0; i < numProcess; i++)
			completionTime[i] = 0;
		for (int i = 0; i < numProcess; i++) {
			for (int j = 0; j <= i; j++) {
				completionTime[i] += burstTime[j];
			}
		}

		double avgTAT = 0;
		double avgWT = 0;
		int waitingTime[] = new int[numProcess];
		int turnAround[] = new int[numProcess];
		for (int i = 0; i < numProcess; i++) {
			turnAround[i] = completionTime[i] - arrivalTime[i];
			waitingTime[i] = turnAround[i] - burstTime[i];
			avgTAT += turnAround[i];
			avgWT += waitingTime[i];
		}
		avgTAT /= numProcess;
		avgWT /= numProcess;

		System.out.println("Process \tAT \t BT \t CT \t TAT \t WT");
		for (int i = 0; i < numProcess; i++) {
			System.out.println(" P" + (1 + i) + "\t\t" + arrivalTime[i] + "ms" + "\t" + burstTime[i] + "ms" + "\t"
					+ completionTime[i] + "ms" + "\t" + turnAround[i] + "ms" + "\t" + waitingTime[i] + "ms");
		}
		System.out.println("Average Turn Around Time: " + avgTAT);
		System.out.println("Average Waiting Time: " + avgWT);

	}
}
