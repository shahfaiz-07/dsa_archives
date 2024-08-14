import java.util.ArrayList;
import java.util.Iterator;

public class LearnArrayList {
    public static void main(String[] args) {
        //------------------------------------------------------------------------------
        // # add(ele) OR add(index, ele)
        ArrayList<String> cars = new ArrayList<String>();
        cars.add("Volvo");
        cars.add("BMW");
        cars.add("Ford");

        // - insert at given position
        cars.add(1, "Mazda");
        System.out.println(cars);

        //------------------------------------------------------------------------------
        // # addAll(Collection) OR addAll(index, Collection)
        ArrayList<String> newCars = new ArrayList<String>();
        newCars.add("Ferari");
        newCars.add("Lambo");
        cars.addAll(3, newCars);

        //------------------------------------------------------------------------------
        // # get(index)
        System.out.println(cars.get(2));

        //------------------------------------------------------------------------------
        // # remove(index) OR remove(Object or ele);
        System.out.println(cars);
        cars.remove(1);
        System.out.println(cars);
        cars.remove("Ford");
        System.out.println(cars);
        // NOTE: For 'int' data type to avoid confusion between index and element we can use the wrapper class Integer.valueOf(ele)

        //------------------------------------------------------------------------------
        // # clear()

        //------------------------------------------------------------------------------
        // # set(index, ele)
        cars.set(0, "What");
        System.out.println(cars);

        //------------------------------------------------------------------------------
        // # contains(ele)
        System.out.println(cars.contains("What"));

        //------------------------------------------------------------------------------
        // # size()

        //------------------------------------------------------------------------------
        // # forEach loop in java
        ArrayList<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        for(int ele: nums) { // for(Integer ele: nums)
            System.out.println(ele);
        }

        //------------------------------------------------------------------------------
        // # Iterators
        Iterator<Integer> it = nums.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
