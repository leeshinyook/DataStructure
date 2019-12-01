#include <iostream>
using namespace std;
// dijkstraAlgo - 동적생성방식
#define MAX 10000;

class Graph {
private:
    int **length; // 이차원 배열 | 인접행렬 저장
    int *distance; // 일차원 | 배열 최단거리저장
    bool *foundMinPathSet; // 일차원 배열 | 최단경로가 발견된 정점의 집합
    int n; // 정점의 수
public:
    Graph(const int vertices = 0): n(vertices) {
        length =new int *[n]; // 이차원 배열의 동적 생성
        for (int i = 0; i < n; i++) {
            length[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                i == j ? length[i][j] = 0 : length[i][j] = 100000;
            }
        }
        distance = new int[n];
        foundMinPathSet = new bool[n];
    }
        void shortestPath(const int); // 최단 경로 함수
        int findMinDist(const int);
        void printGraph();
        void printDist();
        int printDistSum();
        void insertWeight(const int, const int, const int); // 인접행렬에 가중치를 넣어주는 함

};
void Graph::shortestPath(const int v) {
    // distance[j], 0 <= j < n은 n개의 정점을 가진 방향 그래프 G에서 정점 v로부터 정점 j까지의
    // 최간 경로의 길이로 설정,
    // 간선의 길이는 length[i][j]로 주어진다.
    for(int i = 0; i < n; i++) { // 초기화
        foundMinPathSet[i] = false;
        distance[i] = length[v][i];
    }
    foundMinPathSet[v] = true;
    distance[v] = 0;
    for(int i = 0; i < n - 2; i++) { // 정점 v로부터 n-1개 경로를 결정
        int u = findMinDist(n); // findMinDist는 distance[u] = minimum distance[w]인 u를 반환, s[w] = false;
        foundMinPathSet[u] = true;
        for(int w = 0; w < n; w++) {
            if(!foundMinPathSet[w]) // false
                if(distance[u] + length[u][w] < distance[w])
                    distance[w] = distance[u] + length[u][w];
        }
    }
}
int Graph::findMinDist(const int v) {
    int min_idx = -1, min = MAX;

    for(int i = 0; i < n; i++) {
        if(distance[i] < min && foundMinPathSet[i] == false) {
            min = distance[i];
            min_idx = i;
        }
    }
    return min_idx;
}
void Graph::insertWeight(const int v, const int n, const int w) {
    v == n ? length[v][n] = 0 : length[v][n] = w;
}
void Graph::printGraph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << length[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void Graph::printDist() {
    for(int i = 0; i < n; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}
int Graph::printDistSum() {
    int path_sum = 0;
    for(int i = 0; i < n; i++) {
        path_sum += distance[i];
    }
    cout << path_sum << endl;
    return path_sum;
}
int main() {
    int n, m;
    int start, destination, weight;
    cout << "정점수와 간선 수 입력 : ";
    cin >> n >> m;
    Graph graph(n);
    for(int i = 0; i < m; i++) {
        cout << i + 1 << "번째 간선과 가중치 입력 : ";
        cin >> start >> destination >> weight;
        graph.insertWeight(start, destination, weight);
    }
    graph.printGraph();
    cout << "시작 정점 입력 : ";
    cin >> start;
    graph.shortestPath(start);
    cout << "가중치를 갖는 인접행렬 : ";
    graph.printGraph();
    cout << "최종결과인 배열 dist의 값 : ";
    graph.printDistSum();
    cout << "각 정점까지의 최단 경로 : ";
    graph.printDist();
    return 0;
}