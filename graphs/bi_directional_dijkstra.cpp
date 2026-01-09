#include <iostream>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

// Structure to represent a priority queue node
struct Node {
    float cost;
    string node;
};

// Comparison function for priority queue
bool compareNodes(const Node& a, const Node& b) {
    return a.cost < b.cost;
}

// Function to perform relaxation and update the shortest distance
float passAndRelaxation(
    const unordered_map<string, vector<pair<string, int>>>& graph,
    string v,
    set<string>& visitedForward,
    set<string>& visited_backward,
    unordered_map<string, float>& cstFwd,
    unordered_map<string, float>& cstBwd,
    priority_queue<Node>& queue,
    unordered_map<string, string>& parent,
    float& shortestDistance) {
    for (const auto& nxt : graph[v]) {
        if (visitedForward.find(nxt.first) != visitedForward.end()) {
            continue;
        }
        float oldCostF = cstFwd.find(nxt.first) != cstFwd.end() ? cstFwd[nxt.first] : numeric_limits<float>::infinity();
        float newCostF = cstFwd[v] + nxt.second;
        if (newCostF < oldCostF) {
            queue.push({newCostF, v});
            cstFwd[nxt.first] = newCostF;
            parent[nxt.first] = v;
        }
        if (visited_backward.find(nxt.first) != visited_backward.end() && cstFwd[v] + nxt.second + cstBwd[nxt.first] < shortestDistance) {
            shortestDistance = cstFwd[v] + nxt.second + cstBwd[nxt.first];
        }
    }
    return shortestDistance;
}

// Bi-directional Dijkstra's algorithm
int bidirectionalDij(
    const string& source,
    const string& destination,
    const unordered_map<string, vector<pair<string, int>>>& graphForward,
    const unordered_map<string, vector<pair<string, int>>>& graph_backward) {
    float shortestPathDistance = -1.0f;
    set<string> visitedForward;
    set<string> visited_backward;

    unordered_map<string, float> cstFwd = {{source, 0}};
    unordered_map<string, float> cstBwd = {{destination, 0}};
    unordered_map<string, string> parentForward = { { source, ""} };
    unordered_map<string, string> parent_backward = { { destination, ""} };

    priority_queue<Node> queue_forward;
    priority_queue<Node> queue_backward;

    float shortestDistance = numeric_limits<float>::infinity();

    if (source == destination) {
        return 0.0f;
    }

    queue_forward.push({0.0f, source});
    queue_backward.push({0.0f, destination});

    while (!queue_forward.empty() && !queue_backward.empty()) {
        string v_fwd = queue_forward.top().node;
        queue_forward.pop();
        visitedForward.insert(v_fwd);

        string v_bwd = queue_backward.top().node;
        queue_backward.pop();
        visited_backward.insert(v_bwd);

        float newDistanceF = passAndRelaxation(
            graphForward,
            v_fwd,
            visitedForward,
            visited_backward,
            cstFwd,
            cstBwd,
            queue_forward,
            parentForward,
            shortestDistance
        );
        float newDistanceB = passAndRelaxation(
            graph_backward,
            v_bwd,
            visited_backward,
            visitedForward,
            cstBwd,
            cstFwd,
            queue_backward,
            parent_backward,
            shortestDistance
        );

        if (cstFwd[v_fwd] + cstBwd[v_bwd] >= shortestDistance) {
            break;
        }

        shortestDistance = min(shortestDistance, newDistanceF);
        shortestDistance = min(shortestDistance, newDistanceB);

    }

    if (shortestDistance != numeric_limits<float>::infinity()) {
        shortestPathDistance = shortestDistance;
    }
    return shortestPathDistance;
}

int main() {
    unordered_map<string, vector<pair<string, int>>> graphForward = {
        {"B", {{"C", 1}}},
        {"C", {{"D", 1}}},
        {"D", {{"F", 1}}},
        {"E", {{"B", 1}, {"G", 2}}},
        {"F", {}},
        {"G", {{"F", 1}}}
    };

    unordered_map<string, vector<pair<string, int>>> graph_backward = {
        {"B", {{"E", 1}}},
        {"C", {{"B", 1}}},
        {"D", {{"C", 1}}},
        {"F", {{"D", 1}, {"G", 1}}},
        {"E", {{None, numeric_limits<float>::infinity()})),
        {"G", {{"E", 2}}
    };

    string source = "B";
    string destination = "F";

    int result = bidirectionalDij(source, destination, graphForward, graph_backward);
    cout << "Shortest path distance: " << result << endl;

    return 0;
}