// https://leetcode.com/problems/gas-station/

public class GasStation {

    public int canCompleteCircuit(int[] gas, int[] cost) {
        // total gas should always be more than or equal to the total cost
        int gasSum = 0, costSum = 0;
        for (int i = 0; i < gas.length; i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (gasSum < costSum) {
            return -1;
        }
        // not very intuitive but if the total gas - cost difference becomes less than 0, it means that starting at any previous station, you cannot complete the circle, so the very first index through which you can reach the end with total >= 0 will be your start index
        int start = 0, total = 0;
        for (int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i];

            if (total < 0) {
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
}