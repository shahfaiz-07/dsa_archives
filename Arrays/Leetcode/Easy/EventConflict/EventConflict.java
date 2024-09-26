// https://leetcode.com/problems/determine-if-two-events-have-conflict/

public class EventConflict {
    public boolean haveConflict(String[] event1, String[] event2) {
        if (event1[0].compareTo(event2[0]) > 0) {
            String[] temp = event2;
            event2 = event1;
            event1 = temp;
        }
        return event1[1].compareTo(event2[0]) >= 0;
    }
}
