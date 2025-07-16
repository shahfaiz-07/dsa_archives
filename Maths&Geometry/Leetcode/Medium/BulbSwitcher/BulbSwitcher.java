// https://leetcode.com/problems/bulb-switcher/
public class BulbSwitcher {

    public int bulbSwitch(int n) {
        // observation - perfect square bulbs are on
        return (int)Math.sqrt(n);
    }
}