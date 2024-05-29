# <h1 align="center">Laporan Praktikum Modul 9 - Graph dan Tree</h1>
<p align="center">Mohammad Alfan Naraya - 2311102170</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian
Graf adalah himpunan sisi dan titik yang banyaknya berhingga dan sisisisinya menghubungkan sebagian atau keseluruhan pasangan dari titik-titiknya.
Graf merupakan gambar atau pola dari penghubungan antara himpunan elemenelemen tidak kosong yang disebut titik (vertex) dengan himpunan pasangan tidak
terurut titik-titik tersebut yang disebut sisi (edge). Graf digunakan untuk
merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut.
Representasi visual dari graf adalah dengan menyatakan objek sebagai titik,
sedangkan hubungan antara objek dinyatakan sebagai sisi. [1]

Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen. Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus yang disebut root dan node lainnya. 
Tree juga adalah suatu graph yang acyclic, simple, connected yang tidak mengandung loop. [2]
 
 ### Jenis-jenis Graph
 Graph dapat dibedakan berdasarkan arah jelajahnya dan ada tidaknya label bobot pada relasinya. Berdasarkan arah jelajahnya graph dibagi menjadi Undirected graph dan Directed graph. 
 Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Kebalikan dari undirected graph, pada directed graph simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. 
 
 Selain arah jelajahnya, graph dapat dibagi menjadi 2 berdasarkan ada tidaknya label bobot pada koneksinya, yaitu weighted graph dan unweighted graph. Weighted graph adalah jenis graph yang cabangnya diberi label bobot berupa bilangan numerik. 
 Berbeda dengan jenis sebelumnya, unweighted graph tidak memiliki properti bobot pada koneksinya. [1]
 
 ### Binary Tree
Binary tree adalah suatu tree dengan syarat bahwa tiap node (simpul) hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. Tiap node dalam binary tree boleh memiliki paling banyak dua child (anak simpul), secara khusus anaknya  dinamakan kiri dan kanan. [3]

### Istilah dalam Binary Tree
1. Full Binary Tree, semua simpul (kecuali daun) memiliki dua anak dan tiap cabang memiliki panjang ruas yang sama.
2. Complete Binary Tree, Hampir sama dengan Full Binary Tree, semua simpul (kecuali daun) memiliki dua anak tetapi memiliki panjang ruas berbeda.
3. Similar Binary Tree, dua pohon yang memiliki struktur yang sama tetapi informasinya berbeda.
4. Equivalent binary tree, dua pohon yang memiliki struktur informasi yang sama.
5. Kewed tree, dua pohon yang semua simpulnya mempunyai satu anak atau turunan kecuali daun. [3]

## Guided 

### 1. Guided I

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris <7; baris ++){
        cout <<" " << setiosflags (ios::left)<<setw (15)<< simpul [baris] << " : ";
    for (int kolom = 0; kolom<7; kolom++){
        if (busur[baris][kolom]!=0){
            cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]<< ")";
        }
    }
    cout << endl;
    }
}

int main(){
    tampilGraph();
    return 0;
}
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/df14fcd8-abcd-4d79-a667-dd11509232cd)

Program di atas adalah implementasi dalam bahasa C++ yang menampilkan representasi graf berarah dan berbobot, di mana simpul (node) dan busur (edge) antara simpul-simpul tersebut ditentukan dalam dua array: simpul untuk menyimpan nama-nama kota dan busur untuk menyimpan bobot perjalanan antar kota. 
Fungsi tampilGraph mencetak setiap simpul bersama dengan simpul-simpul lain yang terhubung dengannya, serta bobot busur yang menghubungkan mereka, menggunakan perulangan for untuk iterasi melalui simpul dan busur.

### 2. Guided II

```C++
#include <iostream>

using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon

struct Pohon {
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
            cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!"<< endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!"<< endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
                cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
            cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
    } else {
        if (!node) {
        return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
        return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan) {
            return heightKiri + 1;
            } else {
            return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

int main() {
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}  
```

#### Output :
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/bd17c65c-c6a8-4f1f-b3cf-509614d3d2d3)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/fc41ce6e-bb7c-4fb4-99e4-283787041c10)

Program ini memungkinkan pengguna untuk membuat pohon biner, menambahkan node kiri dan kanan, memperbarui data dalam node, mengambil data node, dan menemukan informasi lengkap tentang suatu node termasuk parent, sibling, dan child-nya. 
Selain itu, program menyediakan metode traversal seperti preOrder, inOrder, dan postOrder untuk menjelajahi pohon. Program juga dilengkapi dengan fungsi untuk menghitung ukuran dan tinggi pohon, menghapus subtree, dan menghapus seluruh pohon.

## Unguided 

### 1. Unguided I

Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
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
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/8d9450fa-4c5a-4858-87a9-6b11d3517a93)

Program meminta pengguna untuk memasukkan jumlah simpul (kota) dan nama-nama kota tersebut, kemudian mengisi bobot (jarak) antara setiap pasangan kota. 
Setelah graf terbentuk, pengguna dapat memasukkan nama kota awal dan kota tujuan, dan program akan menghitung serta menampilkan jarak terpendek antara kedua kota. Jika salah satu kota tidak ditemukan dalam graf, program akan menampilkan pesan bahwa tidak ada jalur antara kedua kota tersebut.

### 2. Unguided II

Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>  
#include <iomanip>   
using namespace std; 

// STRUCT POHON
struct tree170 {
    char char170; 
    tree170 *left, *right, *parent; 
};

tree170 *root, *baru; 

// MENGINISIALISASI POHON
void init() {
    root = NULL; 
}

// MENGECEK POHON APAKAH KOSONG
bool isEmpty() {
    return root == NULL; 
}

// MEMBUAT NODE BARU
void buatNode(char char170) {
    if (isEmpty()) { 
        root = new tree170(); 
        root->char170 = char170; 
        root->left = NULL; 
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << char170 << " berhasil dibuat sebagai root." << endl; 
    } else { 
        cout << "\n Tree sudah ada!" << endl;
    }
}

// MENAMBAH NODE KIRI
tree170* insertLeft(char char170, tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) { 
            cout << "\n Node " << node->char170 << " sudah ada child kiri !" << endl;
            return NULL;
        } else {
            tree170 *baru = new tree170(); 
            baru->char170 = char170; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node;
            node->left = baru; 
            cout << "\n Node " << char170 << " berhasil ditambahkan ke child kiri " << baru->parent->char170 << endl; // Pesan sukses
            return baru; 
        }
    }
}

// MENAMBAH NODE KANAN
tree170* insertRight(char char170, tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) { 
            cout << "\n Node " << node->char170 << " sudah ada child kanan !" << endl; 
            return NULL;
        } else {
            tree170 *baru = new tree170(); 
            baru->char170 = char170; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node; 
            node->right = baru; 
            cout << "\n Node " << char170 << " berhasil ditambahkan ke child kanan " << baru->parent->char170 << endl;
            return baru; 
        }
    }
}

// MENGUBAH DATA NODE
void update(char char170, tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (!node) { 
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; 
        } else {
            char temp = node->char170; 
            node->char170 = char170; 
            cout << "\n Node " << temp << " berhasil diubah menjadi " << char170 << endl; 
        }
    }
}

// MENAMPILKAN DATA NODE
void retrieve(tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data node : " << node->char170 << endl;
        }
    }
}

// MECARI DAN MENAMILKAN DATA NODE
void find(tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) { 
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->char170 << endl; 
            cout << " Root : " << root->char170 << endl; 
            if (!node->parent) 
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->char170 << endl; 
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) 
                cout << " Sibling : " << node->parent->left->char170 << endl; 
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) 
                cout << " Sibling : " << node->parent->right->char170 << endl; 
            else
                cout << " Sibling : (tidak punya sibling)" << endl; 
            if (!node->left) 
                cout << " Child Kiri : (tidak punya Child kiri)" << endl; 
            else
                cout << " Child Kiri : " << node->left->char170 << endl; 
            if (!node->right) 
                cout << " Child Kanan : (tidak punya Child kanan)" << endl; 
            else
                cout << " Child Kanan : " << node->right->char170 << endl; 
        }
    }
}

// TRAVERSAL PREORDER
void preOrder(tree170 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            cout << " " << node->char170 << ", "; 
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// TRAVERSAL INORDER
void inOrder(tree170 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            inOrder(node->left); 
            cout << " " << node->char170 << ", "; 
            inOrder(node->right); 
        }
    }
}

// TRAVERSAL POSTORDER
void postOrder(tree170 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            postOrder(node->left); 
            postOrder(node->right); 
            cout << " " << node->char170 << ", "; 
        }
    }
}

// MENGHAPUS POHON
void deleteTree(tree170 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) { 
            if (node != root) { 
                node->parent->left = NULL; 
                node->parent->right = NULL; 
            }
            deleteTree(node->left); 
            deleteTree(node->right); 
            if (node == root) { 
                delete root; 
                root = NULL; 
            } else {
                delete node; 
            }
        }
    }
}

// MEGHAPUS SUBPOHON
void deleteSub(tree170 *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left); 
        deleteTree(node->right); 
        cout << "\n Node subtree " << node->char170 << " berhasil dihapus." << endl;
    }
}

// MENGHAPUS SEMUA NODE POHON
void clear() {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!!" << endl; 
    } else {
        deleteTree(root); 
        cout << "\n Pohon berhasil dihapus." << endl; 
    }
}

// MENGHITUNG UKURAN POHON
int size(tree170 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!!" << endl; 
        return 0;
    } else {
        if (!node) { 
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// MEGHITUNG TINGGI POHON
int height(tree170 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return 0;
    } else {
        if (!node) { 
            return 0;
        } else {
            int heightKiri = height(node->left); 
            int heightKanan = height(node->right); 
            if (heightKiri >= heightKanan) {
                return heightKiri + 1; 
            } else {
                return heightKanan + 1; 
            }
        }
    }
}

// MENAMPILKAN KARAKTERISTIK POHON
void characteristic() {
    cout << "\n Size Tree : " << size() << endl; 
    cout << " Height Tree : " << height() << endl; 
    cout << " Average Node of Tree : " << size() / height() << endl; 
}

// MENAMPILKAN CHILDREN DARI NODE
void displayChildren(tree170 *node) {
    if (node) { 
        cout << "\nChildren of Node " << node->char170 << ": "; 
        if (node->left) 
            cout << "Left: " << node->left->char170 << " "; 
        else
            cout << "Left: NULL "; 
        if (node->right) 
            cout << "Right: " << node->right->char170 << " ";
        else
            cout << "Right: NULL "; 
        cout << endl; 
    } else { 
        cout << "\nNode tidak ditemukan!" << endl; 
    }
}

// MENAMPILKAN KETURUNAN DARI NODE
void displayDescendants(tree170 *node) {
    if (node) { 
        cout << "\nDescendants of Node " << node->char170 << ": "; 
        preOrder(node->left); 
        preOrder(node->right); 
        cout << endl; 
    } else { 
        cout << "\nNode tidak ditemukan!" << endl; 
    }
}

// MENEMUKAN NODE BERDASAR DATA
tree170* findNode(char char170, tree170 *node = root) {
    if (!node)
        return NULL;
    if (node->char170 == char170) 
        return node;
    tree170 *left = findNode(char170, node->left);
    if (left) 
        return left;
    return findNode(char170, node->right); 
}



int main() {
    init(); 
    int pilih170; 
    char char170, parentData; 
    tree170 *parentNode = NULL; 

    do {
        //MENU
        cout << "\n##################\n"; 
        cout << "1. BUAT NODE ROOT\n";
        cout << "2. INSERT NODE KIRI\n";
        cout << "3. INSERT NODE KANAN\n";
        cout << "4. UPDATE NODE\n";
        cout << "5. RETRIEVE NODE\n";
        cout << "6. CARI NODE\n";
        cout << "7. DISPLAY CHILDREN\n";
        cout << "8. DISPLAY DESCENDANT\n";
        cout << "9. TRAVERSAL PRE-ORDER\n";
        cout << "10. TRAVERSAL IN-ORDER\n";
        cout << "11. TRAVERSAL POST-ORDER\n";
        cout << "12. DELETE TREE\n";
        cout << "13. KARAKTERISTIKK TREE\n";
        cout << "0. EXIT\n";
        cout << "SILAHKAN PILIH : ";
        cin >> pilih170;

        //PILIHAN DARI MENU
        switch (pilih170) {
            case 1: 
                cout << "Masukkan data untuk root: ";
                cin >> char170; 
                buatNode(char170); 
                break;
            case 2: 
                cout << "Masukkan data untuk node kiri: ";
                cin >> char170; 
                cout << "Masukkan data parent: ";
                cin >> parentData; 
                parentNode = findNode(parentData); 
                insertLeft(char170, parentNode); 
                break;
            case 3: 
                cout << "Masukkan data untuk node kanan: ";
                cin >> char170; 
                cout << "Masukkan data parent: ";
                cin >> parentData; 
                parentNode = findNode(parentData); 
                insertRight(char170, parentNode); 
                break;
            case 4: 
                cout << "Masukkan data baru: ";
                cin >> char170; 
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parentData;
                parentNode = findNode(parentData); 
                update(char170, parentNode); 
                break;
            case 5:
                cout << "Masukkan data node yang ingin di-retrieve: ";
                cin >> char170; 
                parentNode = findNode(char170); 
                retrieve(parentNode); 
                break;
            case 6: 
                cout << "Masukkan data node yang ingin di-find: ";
                cin >> char170; 
                parentNode = findNode(char170); 
                find(parentNode); 
                break;
            case 7:
                cout << "Masukkan data node untuk menampilkan children: ";
                cin >> char170; 
                parentNode = findNode(char170); 
                displayChildren(parentNode); 
                break;
            case 8: 
                cout << "Masukkan data node untuk menampilkan descendants: ";
                cin >> char170; 
                parentNode = findNode(char170); 
                displayDescendants(parentNode); 
                break;
            case 9: 
                cout << "\nPreOrder :\n ";
                preOrder(root); 
                cout << endl; 
                break;
            case 10: 
                cout << "\nInOrder :\n ";
                inOrder(root); 
                cout << endl;
                break;
            case 11: 
                cout << "\nPostOrder :\n ";
                postOrder(root); 
                cout << endl; 
                break;
            case 12: 
                clear(); 
                break;
            case 13:
                characteristic(); 
                break;
            case 0: 
                cout << "Terima kasih!\n";
                return 0;
                break;
            default: 
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih170 != 0); 
}
```

#### Output:
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/d9fa18ea-5704-41fe-8b06-8514d8be3566)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/775bae8d-dd3a-41b2-9e41-466074906ffb)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/c15de056-b57d-4a66-afe0-1cbaa6bdff95)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/02010e32-204a-4f06-b090-3c0f4a3b8069)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/edb20950-015b-48a6-ad10-5edbe6c8a801)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/a1e5c21c-d1ce-485e-9c29-9232d36859a3)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/29d70f8d-e412-4ca1-b8f7-b71d7dde5ebd)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/87385ea2-cd0a-4310-890c-e4891e870988)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/0e6e2f46-5c24-4c1f-a6d7-699d5fe9ca57)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/c146364d-6c7d-4dcc-a6ff-7c9964810895)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/a1bc7790-0663-4c83-8479-28d08747445a)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/063a1e8a-fd06-4800-bbac-71dc9365c520)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/f67e8441-2e71-4be1-b9b9-c99312afd4a8)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/3ddb9737-a90e-43dd-831c-2692ba71aacf)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/63edc38f-7aec-4c2a-b533-488c877ee409)
![image](https://github.com/NarayaAlfan19/Struktur-Data-Assigment/assets/162522372/42bcd4ee-ef5f-4a3d-9e1a-688b06fa2a68)

Kode di atas dapat menambahkan, membuat, menghapus, mencari, dan traversal node, serta dapat menampilkan karakteristik dari pohon tersebut. Dengan menggunakan init() untuk menginisialisasi pohon dengan mengatur root ke NULL . isEmpty() untuk mengecek pohon kosong atau tidak, buatNode() untuk membuat node root jika pohon kosong. insertLeft() dan insertRight() untuk menambah node baru sebagai anak kiri atau kanan dari node yang diberikan. update() mengubah data dari node yang diberikan. findNode() untuk mencari node berdasarkan data yang diberikan. traversal preorder, postorder, inorder untuk melakukan traversal pada urutan preorder, inorder, post order. deleteTree() untuk menghapus seluruh pohon, deleteSub() untuk menghapus sub pohon. main() merupakan sebuah fungsi utama yang menampilkan menu pada program tersebut.

## Kesimpulan
Graf dan tree adalah struktur data fundamental yang digunakan untuk merepresentasikan hubungan antara objek dalam berbagai konteks. Graf terdiri dari simpul dan sisi yang bisa berarah atau tak berarah serta berbobot, sehingga sangat berguna dalam aplikasi seperti jaringan komputer dan peta jalan. 
Tree adalah bentuk khusus dari graf tanpa siklus yang merepresentasikan hierarki, seperti dalam struktur organisasi atau sistem file. Pemahaman tentang graf dan tree memungkinkan implementasi algoritma yang efisien untuk pencarian, penyortiran, dan analisis data, yang esensial dalam banyak bidang ilmu komputer dan teknik.

## Referensi
[1] Universitas Islam Negeri Sultan Syarif Kasim, "BAB II LANDASAN TEORI - Repository UIN Suska", 2022. http://repository.uin-suska.ac.id/16835/7/7.%20BAB%20II_2018247MT.pdf

[2] Mohammad Andi Triansyah, "Graph dan Tree", scribd.com, 2015. https://www.scribd.com/doc/282997630/Graph-Dan-Tree

[3] ahmadhadari77, "Graf (Graph) dan Pohon (Tree) - Algoritma Pemrograman 2", 2019. https://ahmadhadari77.blogspot.com/2019/05/graph-graf-dan-tree-pohon-algoritma.html
