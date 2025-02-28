// https://leetcode.com/problems/clone-graph/

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Node {

    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

public class CloneGraph {

    public Node cloneGraph(Node node) {
        // bfs
        if(node == null) return null;
        Node newNode = new Node(node.val);

        Deque<Node> que = new ArrayDeque<>();
        que.offer(node);
        Map<Node, Node> mp = new HashMap<>(); // og and copy
        mp.put(node, newNode);

        while(!que.isEmpty()) {
            Node currOg = que.poll(), currCopy = mp.get(currOg);
            for(Node neighbor: currOg.neighbors) {
                Node existingCopy = mp.getOrDefault(neighbor, null);
                if(existingCopy != null) {
                    currCopy.neighbors.add(existingCopy);
                } else {
                    Node newNeighbor = new Node(neighbor.val);
                    currCopy.neighbors.add(newNeighbor);
                    mp.put(neighbor, newNeighbor);
                    que.offer(neighbor);
                }
            }
        }

        return newNode;
    }
}