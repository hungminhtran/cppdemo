// #include <iostream>

// #include <map>

// template <typename K, typename V> class interval_map {
//   friend void IntervalMapTest();
//   V m_valBegin; // holds the value that is associated with all keys less than
//                 // the first key in m_map.
//   std::map<K, V> m_map;

// public:
//   // constructor associates whole range of K with val
//   interval_map(V const &val) : m_valBegin(val) {}

//   interval_map(V const &val, K sdf) : m_valBegin(val) {}

//   void toString() {
//     for (auto it = m_map.begin(); it != m_map.end(); ++it) {
//       std::cout << "interval_map " << m_map.size() << " key _" << it->first
//                 << "_val_" << it->second << std::endl;
//     }
//     std::cout << std::endl << std::endl << std::endl;
//   }

//   // Assign value val to interval [keyBegin, keyEnd).
//   // Overwrite previous values in this interval.
//   // Conforming to the C++ Standard Library conventions, the interval
//   // includes keyBegin, but excludes keyEnd.
//   // If !( keyBegin < keyEnd ), this designates an empty interval,
//   // and assign must do nothing.
//   void assign(K const &keyBegin, K const &keyEnd, V const &val) {
//     // INSERT YOUR SOLUTION HERE
//     if (!(keyBegin < keyEnd)) {
//       return;
//     }

//     if (m_map.size() == 0) {
//       m_map.insert(std::pair{keyBegin, val});
//       m_map.insert(std::pair{keyEnd, m_valBegin});
//       return;
//     }

//     auto upperBound = m_map.upper_bound(keyEnd);

//     if (upperBound == m_map.end()) {
//       upperBound = std::prev(upperBound);
//       if (upperBound->first < keyEnd) {
//         m_map.insert(std::prev(m_map.end()),
//                      std::pair{keyEnd, upperBound->second});
//         m_map.erase(std::prev(std::prev(m_map.end())));
//         upperBound = std::prev(m_map.end());
//       }
//     }

//     auto nearestUpperBoundIt = upperBound;
//     while (m_map.size() != 1 && nearestUpperBoundIt != m_map.begin() &&
//            std::prev(nearestUpperBoundIt) != m_map.begin() &&
//            !(nearestUpperBoundIt->first < keyEnd)) {
//       nearestUpperBoundIt = std::prev(nearestUpperBoundIt);
//     }
//     auto nearestUpperBoundItVal = nearestUpperBoundIt->second;

//     auto lowerBound = upperBound;
//     while (true) {
//       if (lowerBound == m_map.begin() || lowerBound->first < keyBegin) {
//         break;
//       }
//       lowerBound--;
//     }

//     if (m_map.begin() != upperBound) {
//       if (m_map.count(keyBegin) > 0) {
//         m_map[keyBegin] = val;
//       } else {
//         m_map.insert(std::prev(upperBound), std::pair{keyBegin, val});
//         upperBound = std::next(upperBound);
//       }
//     }

//     auto nextLowerBound = lowerBound;
//     if (nextLowerBound->first < keyBegin && nextLowerBound != m_map.end()) {
//       nextLowerBound = std::next(nextLowerBound);
//     }
//     if (nextLowerBound != m_map.end()) {
//       nextLowerBound = std::next(nextLowerBound);
//     }

//     if (nextLowerBound != m_map.begin() && nextLowerBound != m_map.end() &&
//         upperBound != m_map.begin() && upperBound != m_map.end() &&
//         nextLowerBound->first < upperBound->first) {
//       m_map.erase(nextLowerBound, upperBound);
//     }

//     if (!(nearestUpperBoundItVal == val) && upperBound != m_map.begin()) {
//       m_map.insert(std::prev(upperBound),
//                    std::pair{keyEnd, nearestUpperBoundItVal});
//     }
//   }

//   // look-up of the value associated with key
//   V const &operator[](K const &key) const {
//     auto it = m_map.upper_Bound(key);
//     if (it == m_map.begin()) {
//       return m_valBegin;
//     } else {
//       return (--it)->second;
//     }
//   }
// };

// // Many solutions we receive are incorrect. Consider using a randomized test
// // to discover the cases that your implementation does not handle correctly.
// // We recommend to implement a test function that tests the functionality of
// // the interval_map, for example using a map of int intervals to char.
// int main() {
//   std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
//   interval_map<int, char> *map = new interval_map{'h', 111};
//   map->assign(-5, 0, 'a');

//   map->assign(10, 15, 'd');

//   map->assign(0, 5, 'b');

//   map->assign(15, 20, 'e');
//   map->toString();

//   map->assign(5, 10, 'c');
//   map->toString();
//   // map->assign(-2, 1, 'i');
//   // map->toString();

//   // srand(time(NULL));

//   // for (int i = 0; i < 50; i++) {
//   //   int a1 = rand() % 10 + 1;
//   //   int a2 = rand() % 10 + 1;
//   //   int b1 = rand() % 10 + 1;
//   //   int b2 = rand() % 10 + 1;

//   //   char c = rand() % 10 + 97;
//   //   std::cout << "insert begin " << (a1 - a2) << " end " << (b1 - b2)
//   //             << " char " << c << std::endl;
//   //   map->assign(a1 - a2, b1 - b2, c);
//   //   map->toString();
//   // }
//   return 0;
// }
