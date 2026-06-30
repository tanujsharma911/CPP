/*

460. LFU Cache

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:
LFUCache(int capacity) Initializes the object with the capacity of the data
structure. int get(int key) Returns the value of the key if the key exists in
the cache, otherwise return -1. void put(int key, int value) Update the value of
the key if present, or insert the key-value pair if not already present. When
the cache reaches its capacity, it should invalidate and remove the least
frequently used key first, or if there is a tie, the least recently used key.
The functions get and put must each run in O(1) average time complexity.

*/

#include <iostream>

using namespace std;

class Node {
public:
  int key;
  Node *prev;
  Node *next;

  Node(int key) {
    this->key = key;
    this->prev = NULL;
    this->next = NULL;
  }
};
class LL {
public:
  Node *head = NULL;
  Node *tail = NULL;
  unordered_map<int, Node *> map;
  int n = 0;

  ~LL() {
    Node *current = head;
    while (current != NULL) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  }
  void add(int key) {
    Node *node = new Node(key);
    node->next = head;

    if (head == NULL) {
      head = node;
      tail = node;
    } else {
      head->prev = node;
      head = node;
    }

    map[key] = node;
    n++;
  }
  void set(int key) {
    if (!map.count(key)) {
      add(key);
    } else {
      move_front(key);
    }
  }
  void move_front(int key) {
    Node *node = map[key];

    if (node == head)
      return;
    if (node == tail) {
      tail = node->prev;
      if (tail)
        tail->next = NULL;
    }

    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;

    node->next = head;
    node->prev = NULL;

    if (head)
      head->prev = node;
    head = node;
  }
  int pop_back() {
    if (tail == NULL)
      return -1;

    int evict_key = -1;

    if (tail->prev) {
      auto temp = tail;
      tail = tail->prev;
      tail->next = NULL;
      map.erase(temp->key);
      evict_key = temp->key;
      delete temp;
      n--;
    } else {
      map.erase(tail->key);
      evict_key = tail->key;
      delete tail;
      tail = NULL;
      head = NULL;
      n--;
    }

    return evict_key;
  }
  void pop(int key) {
    if (!map.count(key))
      return;

    Node *node = map[key];

    // Edge cases
    if (n == 1) {
      head = NULL;
      tail = NULL;
      map.erase(key);
      delete node;
      n--;

      return;
    }
    if (node == head) {
      head = head->next;
      if (head)
        head->prev = NULL;
      map.erase(key);
      delete node;
      n--;

      return;
    }
    if (node == tail) {
      tail = node->prev;
      if (tail)
        tail->next = NULL;
      map.erase(key);
      delete node;
      n--;

      return;
    }

    // pop from node from middle

    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;

    node->next = NULL;
    node->prev = NULL;

    map.erase(key);
    delete node;
    n--;
  }
};
class LFUCache {
public:
  int capacity;
  int lfuCount = 0;
  unordered_map<int, int> valueMap; // Key -> Value
  unordered_map<int, int> countMap; // Key -> Used Frequency
  unordered_map<int, LL> listMap;   // Used Frequency -> Linked List

  LFUCache(int capacity) { this->capacity = capacity; }

  void inc_freq(int key) {
    // Move key to upper freq LL
    int cnt = countMap[key];

    listMap[cnt].pop(key);
    listMap[cnt + 1].set(key);

    if (listMap[cnt].map.size() == 0 && cnt == lfuCount) {
      lfuCount++;
    }

    countMap[key]++;
  }

  int get(int key) {
    // If not present, Return -1
    if (!valueMap.count(key)) {
      return -1;
    }

    inc_freq(key);

    return valueMap[key];
  }

  void put(int key, int value) {
    if (!valueMap.count(key)) {
      if (valueMap.size() == capacity) {
        freeup_space();
      }

      listMap[1].set(key);
      countMap[key] = 1;
      valueMap[key] = value;
      lfuCount = 1;
    } else {
      inc_freq(key);
      valueMap[key] = value;
    }
  }

  void freeup_space() {
    int evict_key = listMap[lfuCount].pop_back();
    valueMap.erase(evict_key);
    countMap.erase(evict_key);
  }
};

int main() {

  cout << endl;
  return 0;
}