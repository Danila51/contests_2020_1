#include <iostream>
#include <vector>
#include <cmath>
#include <list>
using namespace std;


int hash_function(int data, int range) {

    data = abs(data % range);
    return data;
}


struct str {
    int key;
    int value;
};

class hash_table {
private:
    int size_of_table;
    vector< list<str> > table;
    int free_count;
public:
    hash_table() {
        size_of_table = 0;
        table.resize(size_of_table);
        free_count = 0;
    }
    hash_table(int size) {
        size_of_table = size;
        table.resize(size_of_table);
        free_count = 0;
    }
    void set_size_of_table(int size) {
        size_of_table = size;
        table.resize(size_of_table);
    }
    void add_elem(int key, int value) {
        free_count++;
        int ind = hash_function(key, size_of_table);
        bool flag = false;
        for(auto it = table[ind].begin(); it != table[ind].end(); ++it) {
            if(it->key == key) {
                it->value = value;
                flag = true;
                break;
            }
        }
        if(!flag) {
            str elem;
            elem.value = value;
            elem.key = key;
            table[ind].push_back(elem);
        }
        return;
    }
    void del_el(int key) {
        free_count--;
        int ind = hash_function(key, size_of_table);
        for(auto it = table[ind].begin(); it != table[ind].end(); ++it) {
            if(it->key == key) {
                table[ind].erase(it);
                break;
            }
        }
        return;
    }
    bool print_el(int key) {
        int ind = hash_function(key, size_of_table);
        for(auto it = table[ind].begin(); it != table[ind].end(); ++it) {
            if(it->key == key) {
                cout << it->value << '\n';
                return true;
            }
        }
        return false;
    }
    ~hash_table() {
    }

    bool is_free() {
        if(free_count < size_of_table * 0.75)
            return true;
        return false;
    }

    void resize_table() {
        int new_size_of_table = 2 * size_of_table;
        vector< list<str> > new_table(new_size_of_table);
        for(int i = 0; i < size_of_table; ++i) {
            for(auto it = table[i].begin(); it != table[i].end(); ++it) {
                int ind = hash_function(it->key, new_size_of_table);
                new_table[ind].push_back(*it);
            }
        }
        table = move(new_table);
        size_of_table = new_size_of_table;
    }


};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<hash_table> hash_t(N);
    for(int i = 0; i < N; i++) {
        hash_t[i].set_size_of_table(32);
    }
    int ind, key, value;
    char op;
    for(int i = 0; i < M; ++i) {
        cin >> ind >> op >> key >> value;
        if(op == '+') {
            hash_t[ind].add_elem(key, value);
            if(!hash_t[ind].is_free()) {
                hash_t[ind].resize_table();
            }
        }
        if(op == '-') {
            hash_t[ind].del_el(key);
        }
        if(op == '?') {
            if(!hash_t[ind].print_el(key))
                cout << value << '\n';
        }

    }
    return 0;
}
