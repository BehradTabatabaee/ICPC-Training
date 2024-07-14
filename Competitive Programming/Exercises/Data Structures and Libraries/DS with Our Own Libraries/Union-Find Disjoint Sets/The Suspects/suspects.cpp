#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
    // OOP style
    private:
        vi p, rank, setSize; // vi p is the key part
        int numSets;

    public:
        UnionFind(int N) {
            p.assign(N, 0); 
            for (int i = 0; i < N; ++i) 
                p[i] = i;
            rank.assign(N, 0); // optional speedup
            setSize.assign(N, 1); // optional feature
            numSets = N; // optional feature
        }

        int findSet(int i) { 
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }

        bool isSameSet(int i, int j) { 
            return findSet(i) == findSet(j); 
        }

        int numDisjointSets() { 
            return numSets; 
        } // optional

        int sizeOfSet(int i) { 
            return setSize[findSet(i)]; 
        } // optional

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) 
                return;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                swap(x, y);
            p[x] = y;
            if (rank[x] == rank[y]) 
                ++rank[y];
            setSize[y] += setSize[x];
            --numSets;
        }
};


int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            vector<int> groupStudents;
            for (int j = 0; j < num; j++) {
                int stud;
                cin >> stud;
                groupStudents.push_back(stud);
            }
            for (int j = 1; j < num; j++) {
                uf.unionSet(groupStudents[j - 1], groupStudents[j]);
            }
        }
        cout << uf.sizeOfSet(uf.findSet(0)) << endl;
        cin >> n >> m;
    }
    return 0;
}