// https://leetcode.com/problems/car-fleet/

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class FleetCount {
    class Pair {
        int position, speed;
        Pair(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }
    }
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        List<Pair> cars = new ArrayList<>();
        for(int i=0; i<n; i++) {
            cars.add(new Pair(position[i], speed[i]));
        }

        Collections.sort(cars, (a, b) -> a.position - b.position);

        double leaderTime = (target - cars.get(n - 1).position)*1.0 / cars.get(n - 1).speed;
        int fleetCount = 1;
        for(int i=n - 2; i>=0; i--) {
            double currTime = (target - cars.get(i).position)*1.0 / cars.get(i).speed;
            if(currTime > leaderTime) {
                leaderTime = currTime;
                fleetCount++;
            }
        }
        return fleetCount;
    }
}
