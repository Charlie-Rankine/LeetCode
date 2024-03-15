#include <iostream>
#include <set>

#include <string>
#include <vector>

using namespace std;

class RandomizedSet {
public:
  set<int> s;

  RandomizedSet() {}

  bool insert(int val) { return s.insert(val).second; }

  bool remove(int val) {
    auto element = s.find(val);

    if (element != s.end()) {
      s.erase(element);
      return true;
    }

    return false;
  }

  int getRandom() {
    int random = rand() % s.size();
    auto iter = s.begin();

    while (random--)
      iter++;

    return *iter;
  }
};

int main() {
  RandomizedSet *obj = new RandomizedSet();

  cout << "Insert 1: " << (obj->insert(1) ? "True" : "False") << endl;
  cout << "Insert 2: " << (obj->insert(2) ? "True" : "False") << endl;
  cout << "Insert 3: " << (obj->insert(3) ? "True" : "False") << endl;
  cout << "Insert 3: " << (obj->insert(3) ? "True" : "False") << endl;
  cout << "Insert 4: " << (obj->insert(4) ? "True" : "False") << endl;
  cout << "Insert 5: " << (obj->insert(5) ? "True" : "False") << endl;
  cout << "Delete 2: " << (obj->remove(2) ? "True" : "False") << endl;
  cout << "Delete 6: " << (obj->remove(6) ? "True" : "False") << endl;
  cout << "Random  : " << obj->getRandom() << endl;
}
