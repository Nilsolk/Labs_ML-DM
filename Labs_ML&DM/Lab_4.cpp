#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    char from;
    char to;
    int weight;
};

bool in_edges(vector<Edge> edges, Edge e) {
    bool edgeExists = false;
    for (Edge existing : edges) {
        if (existing.from == e.from && existing.to == e.to) {
            edgeExists = true;
            break;
        }
    }
    return edgeExists;
}

void enter_edges(vector<Edge>& edges) {
    int numEdges;
    cout << "Введите количество рёбер: ";
    cin >> numEdges;

    cout << "Введите рёбра в формате (начало конец вес):\n";
    for (int i = 0; i < numEdges; i++) {
        Edge e;
        cin >> e.from >> e.to >> e.weight;

        if (in_edges(edges, e)) {
            cout << "Ошибка: Ребро " << e.from << " -> " << e.to << " уже существует. Введите снова\n";
            i--;
            continue;
        }
        edges.push_back(e);
    }
}

void get_unique_tops(const vector<Edge>& edges, vector<char>& tops) {
    for (Edge edge : edges) {
        if (find(tops.begin(), tops.end(), edge.from) == tops.end()) {
            tops.push_back(edge.from);
        }
        if (find(tops.begin(), tops.end(), edge.to) == tops.end()) {
            tops.push_back(edge.to);
        }
    }
}

int find_top_index(vector<char> tops, char top) {
    for (int i = 0; i < tops.size(); i++) {
        if (tops[i] == top) {
            return i;
        }
    }
    return -1;
}

void dijkstra(vector<Edge> edges, char start, char end) {
    vector<char> tops;
    get_unique_tops(edges, tops);

    int n = tops.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<char> prev(n, '-');


    int startIndex = find_top_index(tops, start);
    int endIndex = find_top_index(tops, end);

    if (startIndex == -1 || endIndex == -1) {
        cout << "Одна из вершин не найдена в графе.\n";
        return;
    }

    dist[startIndex] = 0;

    while (true) {
        int minDist = INT_MAX;
        int currentTopIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                currentTopIndex = i;
            }
        }

        if (currentTopIndex == -1) {
            break;
        }

        visited[currentTopIndex] = true;
        char currentTop = tops[currentTopIndex];

        for (Edge edge : edges) {
            if (edge.from == currentTop) {
                int neighborIndex = find_top_index(tops, edge.to);
                if (neighborIndex != -1 && !visited[neighborIndex]) {
                    int newDist = dist[currentTopIndex] + edge.weight;
                    if (newDist < dist[neighborIndex]) {
                        dist[neighborIndex] = newDist;
                        prev[neighborIndex] = currentTop;
                    }
                }
            }
        }

        if (visited[endIndex]) {
            break;
        }
    }

    if (dist[endIndex] == INT_MAX) {
        cout << "Путь от " << start << " до " << end << " не существует.\n";
        return;
    }

    cout << "Кратчайший путь: ";
    string path = "";
    char at = end;
    while (at != start) {
        path = at + path;
        int id = find_top_index(tops, at);
        at = prev[id];
    }
    path = start + path;
    cout << path << endl;
    cout << "Суммарная стоимость: " << dist[endIndex] << endl;
}

void start_lab4() {
    vector<Edge> edges;
    enter_edges(edges);

    char start, end;
    cout << "Введите начальную вершину: ";
    cin >> start;
    cout << "Введите конечную вершину: ";
    cin >> end;
    dijkstra(edges, start, end);
}