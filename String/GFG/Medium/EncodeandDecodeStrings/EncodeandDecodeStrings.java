// https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

public class EncodeandDecodeStrings {
    final String separator = "::";

    public String encode(String s[]) {
        // write your logic to encode the strings
        String code = "" + s.length + s[0];

        for (int i = 1; i < s.length; i++) {
            code += separator + s[i];
        }

        code = s.length > 99 ? "3" + code : s.length > 9 ? "2" + code : "1" + code;

        return code;
    }

    public String[] decode(String s) {
        // write your logic to decode the string
        int lengthLength = s.charAt(0) - '0';
        int length = Integer.parseInt(s.substring(1, lengthLength + 1));

        String ans[] = new String[length];
        String word = "";
        int index = 0;
        for (int i = lengthLength + 1; i < s.length(); i++) {
            if (i < s.length() - 2 && s.charAt(i) == ':' && s.charAt(i + 1) == ':') {
                ans[index] = word;
                word = "";
                index += 1;
                i++;
            } else {
                word += s.charAt(i);
            }
        }

        ans[index] = word;
        return ans;
    }
}
