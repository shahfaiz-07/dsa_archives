// https://leetcode.com/problems/time-based-key-value-store/
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


class TimeMap {

    class Pair {

        int time;
        String value;

        Pair(int time, String value) {
            this.time = time;
            this.value = value;
        }
    }
    Map<String, List<Pair>> mp;

    public TimeMap() {
        mp = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        mp.computeIfAbsent(key, k -> new ArrayList<>()).add(new Pair(timestamp, value));
    }

    public String get(String key, int timestamp) {
        List<Pair> values = mp.getOrDefault(key, null);
        if (values == null) {
            return "";
        }
        int l = 0, r = values.size() - 1;
        String value = "";
        while (l <= r) {
            int m = r - (r - l) / 2;
            if (values.get(m).time <= timestamp) {
                value = values.get(m).value;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return value;
    }
}
