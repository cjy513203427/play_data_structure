import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class HuffmanTree {

    public static class Node<E> {
        E data;
        double weight;
        Node leftChild;
        Node rightChild;

        public Node(E data, double weight) {
            super();
            this.data = data;
            this.weight = weight;
        }

        public String toString() {
            return "Node[data=" + data + ", weight=" + weight + "]";
        }
    }

    /**
     * Construct huffman tree
     *
     * @param nodes
     *        nodes list
     * @return constructed root node of huffman tree
     */
    private static Node createTree(List<Node> nodes) {
        // As long as nodes array has more than 1 node
        while (nodes.size() > 1) {
            quickSort(nodes);
            // Get two nodes, whose value is smallest
            Node left = nodes.get(nodes.size()-1);
            Node right = nodes.get(nodes.size()-2);

            // Generate a new node, whose value is equal to the sum of two subnodes
            Node parent = new Node(null, left.weight + right.weight);

            // Let new node to be parent node of two nodes, whose value is smallest
            parent.leftChild = left;
            parent.rightChild = right;

            // Delete two nodes, whose value is smallest
            nodes.remove(nodes.size()-1);
            nodes.remove(nodes.size()-1);

            // Put new node into the list
            nodes.add(parent);
        }

        return nodes.get(0);
    }

    /**
     * Swap element, whose index is i, and element, whose index is j
     *
     * @param nodes
     * @param i
     * @param j
     */
    private static void swap(List<Node> nodes, int i, int j) {
        Node tmp;
        tmp = nodes.get(i);
        nodes.set(i, nodes.get(j));
        nodes.set(j, tmp);
    }

    /**
     * Implement quicksort, in order to sort the nodes
     *
     * @param nodes
     * @param start
     * @param end
     */
    private static void subSort(List<Node> nodes, int start, int end) {
        if (start < end) {
            // Use the first element as boundary value
            Node base = nodes.get(start);
            // i searchs from the left, searchs the index of the element, whose value is bigger than boundary value.
            int i = start;
            // j searchs from the right, searchs the index of the element, whose value is smaller than boundary value.
            int j = end + 1;
            while (true) {
                // Find the index of element, whose value is bigger than boundary value, or i has arrived 'end'
                while (i < end && nodes.get(++i).weight >= base.weight);
                // Find the index of element, whose value is smaller than boundary value, or j has arrived 'start'
                while (j > start && nodes.get(--j).weight <= base.weight);

                if (i < j) {
                    swap(nodes, i, j);
                } else {
                    break;
                }
            }

            swap(nodes, start, j);

            // Recursive left subsequence
            subSort(nodes, start, j - 1);
            // Recursive right subsequence
            subSort(nodes, j + 1, end);
        }
    }

    public static void quickSort(List<Node> nodes){
        subSort(nodes, 0, nodes.size()-1);
    }

    // Breadth first traversal
    public static List<Node> breadthFirst(Node root){
        Queue<Node> queue = new ArrayDeque<Node>();
        List<Node> list = new ArrayList<Node>();

        if(root!=null){
            // Add root element to 'queue'
            queue.offer(root);
        }

        while(!queue.isEmpty()){
            // Add the head of queue to the list
            list.add(queue.peek());
            Node p = queue.poll();

            // If left child node is not null, add it to the queue
            if(p.leftChild != null){
                queue.offer(p.leftChild);
            }

            // If right child node is not null, add it to the queue
            if(p.rightChild != null){
                queue.offer(p.rightChild);
            }
        }

        return list;
    }

    /*
     *           100*
     *         /    \
     *       40     60*
     *             / \
     *           30*  30
     *           /\
     *         10 20*
     *            / \
     *          10*  10
     *          /\
     *         2  8
     **/
    public static void main(String[] args) {
        List<Node> nodes = new ArrayList<Node>();

        nodes.add(new Node("A", 40.0));
        nodes.add(new Node("B", 8.0));
        nodes.add(new Node("C", 10.0));
        nodes.add(new Node("D", 30.0));
        nodes.add(new Node("E", 10.0));
        nodes.add(new Node("F", 2.0));

        Node root = HuffmanTree.createTree(nodes);

        System.out.println(breadthFirst(root));

    }
}