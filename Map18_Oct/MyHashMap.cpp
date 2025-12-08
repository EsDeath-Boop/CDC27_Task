#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    class MyHashMap {
    public:
        static const int SIZE = 10000;
        vector<pair<int,int>> buckets[SIZE];

        int hash(int key) {
            return key % SIZE;
        }

        MyHashMap() {}

        void put(int key, int value) {
            int h = hash(key);
            for (auto &p : buckets[h]) {
                if (p.first == key) {
                    p.second = value;
                    return;
                }
            }
            buckets[h].push_back({key, value});
        }

        int get(int key) {
            int h = hash(key);
            for (auto &p : buckets[h]) {
                if (p.first == key) return p.second;
            }
            return -1;
        }

        void remove(int key) {
            int h = hash(key);
            for (int i = 0; i < buckets[h].size(); i++) {
                if (buckets[h][i].first == key) {
                    buckets[h].erase(buckets[h].begin() + i);
                    return;
                }
            }
        }
    };
    return 0;
}