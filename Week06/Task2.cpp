#include <iostream>
#include <unordered_map>
#include <type_traits>

using namespace std;

// a) Dictionary template
template <typename K, typename V>
class Dictionary {
private:
    unordered_map<K, V> map;

public:
    void put(K key, V value) {
        map[key] = value;
    }

    V get(K key) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return it->second;
        }
        throw out_of_range("Key not found");
    }

    void remove(K key) {
        map.erase(key);
    }

    size_t size() const {
        return map.size();
    }
};


// b) Partial specialization
template <typename K>
class Dictionary<K, int> {
private:
    unordered_map<K, int> map;

public:
    void put(K key, int value) {
        map[key] = value;
    }

    int get(K key) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return abs(it->second); // Return absolute value
        }
        throw out_of_range("Key not found");
    }

    void remove(K key) {
        map.erase(key);
    }

    int size() const {
        int sum = 0;
        for (const auto& pair : map) {
            sum += pair.second;
        }
        return sum;
    }
};

int main() {
    Dictionary<string, double> d;
    d.put("pi", 3.14159);
    d.put("e", 2.71828);
    cout << "Generic Dictionary:" << endl;
    cout << "Value of pi: " << d.get("pi") << endl;
    cout << "Size: " << d.size() << endl;

    Dictionary<string, int> di;
    di.put("a", -10);
    di.put("b", 20);
    di.put("c", -30);
    cout << "\nSpecialized Dictionary<K, int>:" << endl;
    cout << "Absolute value of a: " << di.get("a") << endl;
    cout << "Sum of all values: " << di.size() << endl;

    return 0;
}
