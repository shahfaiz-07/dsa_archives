// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Pair {

    int start, end;

    Pair(int start, int end) {
        this.start = start;
        this.end = end;
    }
}
public class NMeetings {

    public int maxMeetings(int start[], int end[]) {
        // add your code here
        List<Pair> meetings = new ArrayList<>();
        for(int i=0; i<start.length; i++) {
            meetings.add(new Pair(start[i], end[i]));
        }
        Collections.sort(meetings, (a,b) -> a.end - b.end);
        int freeTime = -1, count = 0;
        for(Pair meeting: meetings) {
            if(freeTime < meeting.start) {
                freeTime = meeting.end;
                count++;
            }
        }
        return count;
    }
}