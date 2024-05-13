#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Структура для представления графа списковой структурой
struct Graph {
    int V; // Количество вершин
    list<int>* adj; // Списки смежности

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Функция для добавления ребра в граф
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Рекурсивная функция для поиска всех простых путей между src и dst
    void findAllSimplePathsUtil(int src, int dst, vector<bool>& visited, vector<int>& path) {
        // Добавляем текущую вершину к пути
        path.push_back(src);
        // Отмечаем текущую вершину как посещенную
        visited[src] = true;
        // Если текущая вершина - конечная вершина, выводим путь
        if (src == dst) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
        else {
            // Продолжаем поиск в глубину для всех соседних вершин
            for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
                if (!visited[*it]) {
                    findAllSimplePathsUtil(*it, dst, visited, path);
                }
            }
        }
        // Убираем текущую вершину из пути и отмечаем ее как непосещенную
        path.pop_back();
        visited[src] = false;
    }

    // Функция для поиска всех простых путей между src и dst
    void findAllSimplePaths(int src, int dst) {
        // Массив для отслеживания посещенных вершин
        vector<bool> visited(V, false);
        // Вектор для хранения текущего пути
        vector<int> path;
        // Вызываем рекурсивную функцию для поиска всех простых путей
        findAllSimplePathsUtil(src, dst, visited, path);
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int V, E;
    cout << "Введите количество вершин и ребер в графе: ";
    cin >> V >> E;

    // Создаем граф с заданным количеством вершин
    Graph g(V);

    cout << "Введите ребра графа (вершины должны быть от 0 до " << V - 1 << "):\n";
    for (int i = 0; i < E; ++i) {
        int v, w;
        cout << "Введите ребро " << i + 1 << ": ";
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int src, dst;
    cout << "Введите начальную и конечную вершины: ";
    cin >> src >> dst;

    cout << "Простые пути от вершины " << src << " к вершине " << dst << ":\n";
    // Находим все простые пути между заданными вершинами
    g.findAllSimplePaths(src, dst);

    return 0;
}
