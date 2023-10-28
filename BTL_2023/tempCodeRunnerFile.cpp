#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

class Graph {
    int n; // Số đỉnh
    std::vector<std::vector<std::pair<int, int>>> adjacencyList; // Danh sách kề với trọng số

public:
    Graph(int vertices) : n(vertices) {
        adjacencyList.resize(n);
    }

    void addEdge(int u, int v, int weight) {
        adjacencyList[u].push_back({v, weight});
        adjacencyList[v].push_back({u, weight});
    }

    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file." << std::endl;
            return;
        }

        int edges;
        file >> edges;
        for (int i = 0; i < edges; i++) {
            int u, v, weight;
            file >> u >> v >> weight;
            addEdge(u, v, weight);
        }

        file.close();
    }

    void writeToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file." << std::endl;
            return;
        }

        file << n << "\n";
        for (int u = 0; u < n; u++) {
            for (const auto& edge : adjacencyList[u]) {
                int v = edge.first;
                int weight = edge.second;
                file << u << " " << v << " " << weight << "\n";
            }
        }

        file.close();
    }

    std::vector<Graph> getConnectedComponents() {
        std::vector<Graph> components;
        std::vector<bool> visited(n, false);

        for (int u = 0; u < n; u++) {
            if (!visited[u]) {
                Graph component(n);
                component.DFS(u, visited);
                components.push_back(component);
            }
        }

        return components;
    }

    void BFS(int start) {
        std::vector<bool> visited(n, false);
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int u = queue.front();
            std::cout << u << " ";
            queue.pop();

            for (const auto& edge : adjacencyList[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    queue.push(v);
                }
            }
        }

        std::cout << std::endl;
    }

    void DFS(int u, std::vector<bool>& visited) {
        visited[u] = true;
        std::cout << u << " ";

        for (const auto& edge : adjacencyList[u]) {
            int v = edge.first;
            if (!visited[v]) {
                DFS(v, visited);
            }
        }
    }

    // Triển khai thuật toán tìm đường đi ngắn nhất ở đây
};

int main() {
    Graph g(6); // Khởi tạo đồ thị với 6 đỉnh
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 5);
    g.addEdge(4, 5, 1);

    // Đọc đồ thị từ tệp
    g.readFromFile("graph.txt");

    // Ghi đồ thị ra tệp
    g.writeToFile("output.txt");

    // Duyệt đồ thị theo BFS
    std::cout << "BFS traversal: ";
    g.BFS(0);

    // Duyệt đồ thị theo DFS
    std::cout << "DFS traversal: ";
    std::vector<bool> visited(g.n, false);
    g.DFS(0, visited);
    std::cout << std::endl;

    // Tìm đồ thị con của đồ thị g
    std::vector<Graph> components = g.getConnectedComponents();
    std::cout << "Connected Components: " << components.size() << std::endl;

    // Triển khai thuật toán tìm đường đi ngắn nhất ở đây

    return 0;
}
