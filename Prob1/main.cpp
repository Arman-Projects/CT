#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Custom comparator for the priority queue
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // Compare by distance (min-heap)
    }
};

// Dijkstra's Algorithm to find shortest path from source to target
int dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[source] = 0;

    // Min-heap: (distance, node) with the custom comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curDist > dist[node]) continue; // Skip if we've already found a shorter path

        // If target is reached, return the distance
        if (node == target) return dist[node];

        for (auto& edge : graph[node]) {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist[target];
}
int main() {
    // Number of nodes in the graph
    int numNodes = 7;

    // Random number generator initialization
    srand(time(0));

    // Graph representation: graph[node] = {{neighbor, weight}, ...}
    vector<vector<pair<int, int>>> graph(numNodes);

    // Randomly add edges with random weights between nodes
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            // Randomly decide if an edge should exist between nodes i and j
            if (rand() % 2) {  // 50% chance of creating an edge
                int weight = rand() % 20 + 1; // Random weight between 1 and 20
                graph[i].push_back({j, weight});
                graph[j].push_back({i, weight});
            }
        }
    }

    // Print the graph for verification
    cout << "Graph (node: {neighbor, weight}):" << endl;
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": ";
        for (auto& edge : graph[i]) {
            cout << "{" << edge.first << ", " << edge.second << "} ";
        }
        cout << endl;
    }

    // Select source and target nodes for Dijkstra's algorithm
    int source = 0; // A
    int target = 6; // G

    int shortestDistance = dijkstra(graph, source, target);

    cout << "Shortest path from node " << source << " to node " << target << ": " << shortestDistance << endl;

    return 0;
}
