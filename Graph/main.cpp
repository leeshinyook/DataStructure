#include <iostream>
using namespace std;

class Graph; // 전방 선언
class ChainNode {
    friend class Graph;
private:
    int data;
    ChainNode *link;
};
typedef ChainNode *ChainNodePointer;

class Graph {
public:
    Graph(int size);
    void InsertEdge(int v, int u);
    void PrintVertex();
    void DFS(const int v);
//    void BFS(const int v);
    void Components();
private:
    ChainNodePointer *HeadNodes;
    int n; // 정점의 수
    bool *visited;
};
Graph::Graph(int size) {
    HeadNodes = new ChainNodePointer[size]; // HeadNode[i]가 i번째 정점 리스트의 first역할을 한다.(첫 노드를 가리킴)
    visited = new bool[size];
    n = size;
    for(int i = 0; i < n; i++) { // 초기화
        HeadNodes[i] = 0;
        visited[i] = false;
    }
}

void Graph::InsertEdge(int v, int u) {
    ChainNode *p = new ChainNode();
    p -> data = v;
    p -> link = HeadNodes[u];
    HeadNodes[u] = p;

    p = new ChainNode();
    p -> data = u;
    p -> link = HeadNodes[v];
    HeadNodes[v] = p;
}

void Graph::PrintVertex() {
    for(int i = 0; i < n; i++) {
        for(ChainNode *p = HeadNodes[i]; p; p = p -> link){
            cout << p -> data << " ";
        }
    }
}

void Graph::DFS(const int v) {
    cout << v << " ";
    visited[v] = true;
    for(ChainNode *p = HeadNodes[v]; p; p = p -> link) {
        int w = p -> data; // 방문한 데이터 w에 삽입
        if (!visited[w]) { // 방문한 적이 없다면
            DFS(w);
        }
    }
}

void Graph::Components() { // 그래프의 연결요소들을 결정한다.
    for(int i = 0; i < n; i++) {
        if (!visited) {
            DFS(i);
        }
    }
}
int main() {
    int n, e; // n - 정점의 수, e - 간선의 수
    int k, u, v;
    cout << "정점의 수와 간선의 수를 입력하시요 : ";
    cin >> n >> e;

    Graph g(n); // Graph 클래스의 객체 g를 생성한다.

    for(int i = 0; i < e; i++) {
        k = i + 1;
        cout << k << "번쨰 간선 (u, v)를 입력 > ";
        cin >> u >> v;
        g.InsertEdge(u, v); // 인접 리스트에 간선 (u, v)를 삽입한다.
    }
    g.PrintVertex(); // 입력된 그래프의 연결리스트 출력
    cout << "\n";
//    g.Components(); // 입력된 그래프의 연결 요소 구하기
    cout << "\n";
    return 0;
}