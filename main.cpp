#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int distance;
};

class Graph {
private:
    vector<string> locations;
    vector<vector<Edge>> adj;

public:
    Graph() {
        locations = {
            "College", "Railway Station", "Bus Stand",
            "Government Hospital", "City Center", "Shopping Mall"
        };
        adj.resize(locations.size());

        // Predefined undirected roads (distances are sample kilometres).
        addRoad(0, 1, 12);
        addRoad(0, 2, 8);
        addRoad(0, 4, 15);
        addRoad(1, 2, 4);
        addRoad(1, 3, 10);
        addRoad(2, 3, 5);
        addRoad(2, 4, 7);
        addRoad(3, 5, 6);
        addRoad(4, 5, 3);
    }

    void addRoad(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= (int)adj.size() ||
            v >= (int)adj.size() || w <= 0) return;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void displayLocations() const {
        cout << "\nAvailable locations:\n";
        for (int i = 0; i < (int)locations.size(); ++i)
            cout << i << ". " << locations[i] << '\n';
    }

    void shortestPath(int source, int destination) const {
        int n = locations.size();
        vector<int> dist(n, INF), parent(n, -1);

        // Min-priority queue stores {distance, vertex}.
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist != dist[u]) continue;

            for (const Edge &edge : adj[u]) {
                int v = edge.to;
                int newDist = dist[u] + edge.distance;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    parent[v] = u;
                    pq.push({newDist, v});
                }
            }
        }

        if (dist[destination] == INF) {
            cout << "\nNo route is available.\n";
            return;
        }

        vector<int> path;
        for (int v = destination; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "\nShortest route: ";
        for (int i = 0; i < (int)path.size(); ++i) {
            cout << locations[path[i]];
            if (i + 1 < (int)path.size()) cout << " -> ";
        }
        cout << "\nTotal distance: " << dist[destination] << " km\n";
    }
};

int main() {
    Graph city;
    cout << "========================================\n";
    cout << " SMART CITY ROUTE OPTIMIZATION SYSTEM\n";
    cout << "========================================\n";

    city.displayLocations();

    int source, destination;
    cout << "\nEnter source location ID: ";
    if (!(cin >> source)) {
        cout << "Invalid input.\n";
        return 0;
    }

    cout << "Enter destination location ID: ";
    if (!(cin >> destination)) {
        cout << "Invalid input.\n";
        return 0;
    }

    if (source < 0 || destination < 0 ||
        source >= 6 || destination >= 6) {
        cout << "Invalid location ID. Choose an ID from 0 to 5.\n";
        return 0;
    }

    city.shortestPath(source, destination);
    return 0;
}
