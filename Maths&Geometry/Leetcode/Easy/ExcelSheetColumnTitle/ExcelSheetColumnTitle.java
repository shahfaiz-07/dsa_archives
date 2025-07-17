// https://leetcode.com/problems/excel-sheet-column-title/
public class ExcelSheetColumnTitle {

    // RECURSIVE
    StringBuilder convert(int columnNumber) {
        if(columnNumber == 0) return new StringBuilder("");
        return convert((columnNumber - 1)/26).append((char)((columnNumber - 1)%26 + 65));
    }
    public String convertToTitle(int columnNumber) {
        return convert(columnNumber).toString();
    }
    // ITERATIVE
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder("");
        while(columnNumber > 0) {
            ans =  ans.append((char)((columnNumber - 1)%26 + 65));
            columnNumber = (columnNumber - 1)/26;
        }
        return ans.reverse().toString();
    }
}