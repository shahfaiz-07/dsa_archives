import java.util.ArrayDeque;
import java.util.Deque;
class Pair<T, U> {

    T first;
    U second;

    Pair() {
        first = null;
        second = null;
    }

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }
}
public class RottenOranges {
    public int orangesRotting(int[][] grid) {
        int diffs[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Deque<Pair<Integer, Integer>> q = new ArrayDeque<>();
        int c = 0, oneCount = 0;
        for(int i=0; i<grid.length; i++) {
            for(int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == 2) {
                    q.offer(new Pair<>(i, j));
                } else if(grid[i][j] == 1) {
                    oneCount++;
                }
            }
        }
        if(q.size() == 0) {
            if(oneCount > 0) {
                return -1;
            } else {
                return 0;
            }
        }
        int level = -1;
        while(!q.isEmpty()) {
            level++;
            int size = q.size();
            for(int i=1; i<=size; i++) {
                Pair<Integer, Integer> curr = q.poll();
                for(int[] diff: diffs) {
                    int x = curr.first + diff[0], y = curr.second + diff[1];
                    if(x >= 0 && x < grid.length && y >=0 && y < grid[0].length && grid[x][y] == 1) {
                        oneCount--;
                        grid[x][y] = 2;
                        q.offer(new Pair<>(x, y));
                    }
                }
            }
        }
        return (oneCount == 0) ? level : -1;
    }
}
