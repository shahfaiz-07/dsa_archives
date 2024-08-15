public class Palindrome {
    static boolean isValid(String s, int index) {
        if(index >= s.length()/2) {
            return true;
        }
        if(s.charAt(index) != s.charAt(s.length() - index - 1)) {
            return false;
        }
        return isValid(s, index + 1);
    }
    public static void main(String[] args) {
        System.out.println(isValid("llol", 0));
    }
}
