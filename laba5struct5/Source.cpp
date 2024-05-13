#include <iostream>
#include <vector>
#include <list>

using namespace std;

// ��������� ��� ������������� ����� ��������� ����������
struct Graph {
    int V; // ���������� ������
    list<int>* adj; // ������ ���������

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // ������� ��� ���������� ����� � ����
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // ����������� ������� ��� ������ ���� ������� ����� ����� src � dst
    void findAllSimplePathsUtil(int src, int dst, vector<bool>& visited, vector<int>& path) {
        // ��������� ������� ������� � ����
        path.push_back(src);
        // �������� ������� ������� ��� ����������
        visited[src] = true;
        // ���� ������� ������� - �������� �������, ������� ����
        if (src == dst) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
        else {
            // ���������� ����� � ������� ��� ���� �������� ������
            for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
                if (!visited[*it]) {
                    findAllSimplePathsUtil(*it, dst, visited, path);
                }
            }
        }
        // ������� ������� ������� �� ���� � �������� �� ��� ������������
        path.pop_back();
        visited[src] = false;
    }

    // ������� ��� ������ ���� ������� ����� ����� src � dst
    void findAllSimplePaths(int src, int dst) {
        // ������ ��� ������������ ���������� ������
        vector<bool> visited(V, false);
        // ������ ��� �������� �������� ����
        vector<int> path;
        // �������� ����������� ������� ��� ������ ���� ������� �����
        findAllSimplePathsUtil(src, dst, visited, path);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int V, E;
    cout << "������� ���������� ������ � ����� � �����: ";
    cin >> V >> E;

    // ������� ���� � �������� ����������� ������
    Graph g(V);

    cout << "������� ����� ����� (������� ������ ���� �� 0 �� " << V - 1 << "):\n";
    for (int i = 0; i < E; ++i) {
        int v, w;
        cout << "������� ����� " << i + 1 << ": ";
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int src, dst;
    cout << "������� ��������� � �������� �������: ";
    cin >> src >> dst;

    cout << "������� ���� �� ������� " << src << " � ������� " << dst << ":\n";
    // ������� ��� ������� ���� ����� ��������� ���������
    g.findAllSimplePaths(src, dst);

    return 0;
}
