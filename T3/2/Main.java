import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Graph and visited array as global variables
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>(n + 1);
        boolean[] visited = new boolean[n + 1];

        // Initialize the graph
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        // Read graph input
        for (int i = 1; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        // Check for the highest valid root
        for (int root = n; root >= 1; root--) {
            // Reset visited array
            Arrays.fill(visited, false);

            // Start BFS
            Queue<Integer> q = new LinkedList<>();
            q.offer(root);
            visited[root] = true;
            boolean valid = true;

            while (!q.isEmpty() && valid) {
                int current_size = q.size();
                int degree = graph.get(q.peek()).size();  // Degree of the first node at this level

                for (int i = 0; i < current_size; i++) {
                    int node = q.poll();

                    // Check if all nodes at this level have the same degree
                    if (graph.get(node).size() != degree) {
                        valid = false;
                        break;
                    }

                    // Process neighbors
                    for (int neighbor : graph.get(node)) {
                        if (!visited[neighbor]) {
                            q.offer(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }

            if (valid) {
                System.out.println(root);
                return;
            }
        }

        System.out.println(-1);
    }
}
