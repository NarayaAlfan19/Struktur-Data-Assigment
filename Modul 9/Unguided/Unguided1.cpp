#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

struct Vertex {
    string nama_170;
    int jarak_170;
};

vector<vector<int>> createGraph(vector<string>& vertices) {
   
    int numVertices2311102170;
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices2311102170;
 
    vertices.resize(numVertices2311102170);
    for (int i = 0; i < numVertices2311102170; i++) {
        cout << "Masukkan nama simpul " << i + 1 << ": ";
        cin >> vertices[i];
    }

    
    vector<vector<int>> adjacencyMatrix(numVertices2311102170, vector<int>(numVertices2311102170));
    for (int i = 0; i < numVertices2311102170; i++) {
        for (int j = 0; j < numVertices2311102170; j++) {
            if (i == j) {
                
                adjacencyMatrix[i][j] = 0;
            } else {
                cout << "Masukkan bobot " << vertices[i] << "-->" << vertices[j] << ": ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    return adjacencyMatrix;
}


int findDistance(const vector<vector<int>>& adjacencyMatrix, const vector<string>& vertices,
                 const string& startCity, const string& endCity) {
    
    auto startIt = find(vertices.begin(), vertices.end(), startCity);
    auto endIt = find(vertices.begin(), vertices.end(), endCity);

    if (startIt == vertices.end() || endIt == vertices.end()) {
        return -1;
    }

    int startIndex = distance(vertices.begin(), startIt);
    int endIndex = distance(vertices.begin(), endIt);
 
    vector<int> distances(vertices.size(), INT_MAX);
    distances[startIndex] = 0;
  
    set<int> unvisitedVertices;
    for (int i = 0; i < vertices.size(); i++) {
        unvisitedVertices.insert(i);
    }

    
    while (!unvisitedVertices.empty()) {
        
        int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                         [&](int i, int j) { return distances[i] < distances[j]; });

        
        unvisitedVertices.erase(currentVertex);

        
        for (int neighbor = 0; neighbor < vertices.size(); neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor]) {
                distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
            }
        }
    }

    
    return distances[endIndex];
}

int main() {
   
    vector<string> vertices;
    vector<vector<int>> adjacencyMatrix = createGraph(vertices);

    string kotaAwal_169, kotaAkhir_169;
    cout << "Masukkan nama kota awal: ";
    cin >> kotaAwal_169;
    cout << "Masukkan nama kota tujuan: ";
    cin >> kotaAkhir_169;

    int distance = findDistance(adjacencyMatrix, vertices, kotaAwal_169, kotaAkhir_169);

    if (distance == -1) {
        cout << "Tidak ada jalur dari " << kotaAwal_169 << " ke " << kotaAkhir_169 << "." << endl;
    } else {
        cout << "Jarak dari " << kotaAwal_169 << " ke " << kotaAkhir_169 << " adalah " << distance << " kilometer." << endl;
    }

    return 0;
}