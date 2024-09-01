// Pair class in java just like pair in cpp stl - pretty useful
class Pair<T, U> {

    T first;
    U second;

    Pair() {
        this.first = null;
        this.second = null;
    }
    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return "("+this.first+", "+this.second+")";
    }
}
public class ImplementPair {
    public static void main(String[] args) {
        Pair<Integer, Integer> p = new Pair<>(1, 2);
        System.out.println(p);
        Pair<Integer, Integer> p1 = new Pair<>();
        System.out.println(p1);
    }
}
