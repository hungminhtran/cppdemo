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

  interval_map(V const &val, K sdf) : m_valBegin(val) {}

  void toString() {
    std::cout << std::endl << std::endl << std::endl;
    for (auto it = m_map.begin(); it != m_map.end(); ++it) {
      std::cout << "interval_map key _" << it->first << "_val_" << it->second
                << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
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
      return;
    }

    auto upperBound = m_map.upper_bound(keyEnd);

    if (upperBound == m_map.end()) {
      upperBound = std::prev(upperBound);
      if (upperBound->first < keyEnd) {
        // this->toString();
        m_map.insert(std::prev(m_map.end()),
                     std::pair{keyEnd, upperBound->second});
        // this->toString();
        m_map.erase(std::prev(std::prev(m_map.end())));
        // this->toString();
        upperBound = std::prev(m_map.end());
      }
    }

    auto nearestUpperBoundVal = m_valBegin;
    if (m_map.size() != 1 && upperBound != m_map.begin() &&
        std::prev(upperBound) != m_map.begin()) {
      nearestUpperBoundVal = std::prev(upperBound)->second;
    }

    auto lowerBound = upperBound;
    while (true) {
      if (lowerBound == m_map.begin() || lowerBound->first < keyBegin) {
        break;
      }
      lowerBound--;
    }

    int insertedElement = 0;

    if (m_map.begin() != upperBound) {
      m_map.insert(std::prev(upperBound), std::pair{keyBegin, val});
      insertedElement++;
    }

    if (!(nearestUpperBoundVal == val) && upperBound != m_map.begin()) {
      m_map.insert(std::prev(upperBound),
                   std::pair{keyEnd, nearestUpperBoundVal});
      insertedElement++;
    }

    while (insertedElement > 0 && upperBound != m_map.begin() &&
           std::prev(upperBound) != m_map.begin()) {
      upperBound = std::prev(upperBound, insertedElement);
    }

    auto nextLowerBound = lowerBound;
    if (nextLowerBound->first < keyBegin && lowerBound != m_map.begin()) {
      nextLowerBound = std::next(nextLowerBound);
    }

    if (nextLowerBound != m_map.end() && upperBound != m_map.begin() &&
        nextLowerBound->first < upperBound->first) {
      m_map.erase(nextLowerBound, upperBound);
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
  interval_map<int, char> *map = new interval_map{'h', 111};
  map->assign(-5, 0, 'a');
  map->toString();
  map->assign(10, 15, 'd');
  map->toString();
  map->assign(0, 5, 'b');
  map->toString();
  map->assign(15, 20, 'e');
  map->toString();
  map->assign(5, 10, 'c');
  map->toString();
  map->assign(-10, -5, 'A');
  map->toString();
  return 0;
}
