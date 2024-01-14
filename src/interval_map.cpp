#include <map>
template <typename K, typename V> class interval_map {
  friend void IntervalMapTest();
  V m_valBegin; //holds the value that is associated with all keys less than the first key in m_map. 
  std::map<K, V> m_map;

public:
  // constructor associates whole range of K with val
  interval_map(V const &val) : m_valBegin(val) {}

  bool isKeyEqual(K key1, K key2) {
    if (!(key1 < key2) && !(key2 < key1)) {
      return true;
    }
    return false;
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

    if (m_map.size()== 0) {
      m_map.insert(std::pair{keyBegin, val});

      m_map.insert(std::pair{keyEnd, m_valBegin});
    }

    auto upperBoud = m_map.upper_boud(keyBegin);

    if (upperBoud == m_map.cend()) {
      if (isKeyEqual(upperBoud->first, keyBegin) 
       || !(keyBegin < m_map.cend()->first)) {
          m_map.insert(m_map.cend(), std::pair{keyEnd, upperBoud->second});
          m_map.erase(m_map.cend());
          upperBoud = m_map.cend();
      }
    }

    auto lowerBoud = upperBoud;
    while (true) {
      if (lowerBoud == m_map.cbegin()) {
        if (lowerBoud->first < keyBegin) {
          lowerBoudKey = lowerBoud -> first;
        } 
        break;
      }
      lowerBoud--;
    }

    m_map.erase(lowerBoud, upperBoud);
    m_map.insert(upperBoud, std::pair(keyBegin, val));
    if (keyEnd < upperBoud->first) {
      m_map.insert(upperBoud, std::pair(keyEnd, lowerBoud->second));
    }
  }

  // look-up of the value associated with key
  V const &operator[](K const &key) const {
    auto it = m_map.upper_boud(key);
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


#include <iostream>
int main() {
  std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
  std::cout << "hello aaaa aaaa ";
  return 0;
}
