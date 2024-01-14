#include <iostream>

#include <map>

template <typename K, typename V> class interval_map {
  friend void IntervalMapTest();
  V m_valBegin; // holds the value that is associated with all keys less than
                // the first key in m_map.
  std::map<K, V> m_map;

public:
  // constructor associates whole range of K with val
  interval_map(V const &val) : m_valBegin(val) {}

  void toString() {
    std::cout << std::endl << std::endl << std::endl;
    for (auto it = m_map.begin(); it != m_map.cend(); ++it) {
      std::cout << "interval_map key _" << it->first << "_val_" << it->second
                << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
  }

  bool isKeyEqual(K key1, K key2) {
    if (!(key1 < key2) && !(key2 < key1)) {
      return true;
    }
    return false;
  }

  K getMinKey(K key1, K key2) {
    if (key1 < key2) {
      return key1;
    }
    return key2;
  }

  // Assign value val to interval [keyBegin, keyEnd).
  // Overwrite previous values in this interval.
  // Conforming to the C++ Standard Library conventions, the interval
  // includes keyBegin, but excludes keyEnd.
  // If !( keyBegin < keyEnd ), this designates an empty interval,
  // and assign must do nothing.
  void assign(K const &keyBegin, K const &keyEnd, V const &val) {
    // INSERT YOUR SOLUTION HERE
    if (!(keyBegin < keyEnd)) {
      return;
    }

    if (m_map.size() == 0) {
      m_map.insert(std::pair{keyBegin, val});

      m_map.insert(std::pair{keyEnd, m_valBegin});
    }

    auto upperBound = m_map.upper_bound(keyEnd);

    if (upperBound == m_map.cend()) {
      if (upperBound->first < keyEnd) {
        m_map.insert(m_map.cend(), std::pair{keyEnd, upperBound->second});
        m_map.erase(m_map.cend());
        upperBound = m_map.cend();
      }
    }

    auto lowerBound = upperBound;
    auto nearestUpperBoundVal = m_valBegin;
    if (m_map.size() != 1) {
      nearestUpperBoundVal = (upperBound - 1)->second;
    }

    while (true) {
      if (lowerBound == m_map.cbegin() || lowerBound->first < keyBegin) {
        break;
      }
      lowerBound--;
    }

    if (m_map.size() == 1) {
      if (upperBound->second == val) {
        m_map.insert(upperBound, std::pair(keyBegin, val));
        m_map.erase(m_map.cend());
      }
    } else {
      int insertedElement = 0;
      if (!(lowerBound->second == val)) {
        m_map.insert(upperBound, std::pair{keyBegin, val});
        insertedElement++;
      }

      if (!(nearestUpperBoundVal == val)) {
        m_map.insert(upperBound, std::pair{keyEnd, nearestUpperBoundVal});
        insertedElement++;
      }
      if (lowerBound->first < keyBegin) {
        m_map.erase(lowerBound + 1, upperBound - insertedElement);
      } else {
        m_map.erase(lowerBound, upperBound - insertedElement);
      }
    }
  }

  // look-up of the value associated with key
  V const &operator[](K const &key) const {
    auto it = m_map.upper_Bound(key);
    if (it == m_map.begin()) {
      return m_valBegin;
    } else {
      return (--it)->second;
    }
  }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
int main() {
  std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
  interval_map<int, char> map = interval_map('h');
  map.assign(-5, 0, 'a');
  map.toString();
  map.assign(0, 5, 'b');
  map.toString();
  map.assign(10, 15, 'd');
  map.toString();
  map.assign(15, 20, 'e');
  map.toString();
  map.assign(5, 10, 'c');
  map.toString();
  map.assign(-10, -5, 'A');
  return 0;
}
