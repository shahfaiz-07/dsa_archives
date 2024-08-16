// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
import java.util.ArrayList;

public class RatInMaze {
    static void travel(int[][] mat, int i, int j, ArrayList<String> paths, String path) {
        if(i < 0 || i >= mat.length || j < 0 || j >= mat[0].length || mat[i][j] == 0) {
            System.out.println("Reached :" +i+","+j);
            return;
        }
        if(i == mat.length - 1 && j == mat[0].length - 1) {
            paths.add(path);
            return;
        }
        mat[i][j] = 0; // mark visited
        // down
        travel(mat, i+1, j, paths, path+"D");
        // right
        travel(mat, i, j+1, paths, path+"R");
        // left
        travel(mat, i, j-1, paths, path+"L");
        // up
        travel(mat, i-1, j, paths, path+"U");
        
        mat[i][j] = 1; // unmark
    }
    public static ArrayList<String> findPath(int[][] mat) {
        ArrayList<String> paths = new ArrayList<>();
        travel(mat, 0, 0, paths, "");
        return paths;
    }
    public static void main(String[] args) {
        int mat[][] = {{1, 0, 0, 0},
                {1, 1, 0, 1}, 
                {1, 1, 0, 0},
                {0, 1, 1, 1}};
        System.out.println(findPath(mat));
    }
}
