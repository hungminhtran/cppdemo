#include <map>
template <typename K, typename V> class interval_map {
  friend void IntervalMapTest();
  V m_valBegin; //holds the value that is associated with all keys less than the first key in m_map. 
  std::map<K, V> m_map;

public:
  // constructor associates whole range of K with val
  interval_map(V const &val) : m_valBegin(val) {}

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

    /*
    find the key in map
    lowerBoundKey = previous element of upper_bound of keyBegin
    upperBoundKey = uppper_bound of keyBegin

    if (!(lowerBoundKey < keyBegin) && !(keyBegin < lowerBoundKey)) {
      remove lowerbound element
      if first element
        lowerBoundKey = m_val;
      lowerBoundKey = previous element of current lower bound
    }


    if (!(upperBoundKey < m_map.end.key) 
      && !(m_map.end.key < upperBoundKey)
    {
        upperBoundKey = last element
        remove last element
    }

    if (m_map.end.key < keyBegin) {      
        upperBoundKey = last lement
    }

    insert new value
      map (-inf, m_valBegin), (-5, a), (-2, b), (10, c)

      no overlap, fist element
      insert(-13, -7, x) -> map (-inf, m_valBegin), (-13, x), (-7, m_val_Begin) (-5, a), (-2, b), (10, c)

        upperBoundKey exist + keyEnd < upperBoundKey
          insert(keyEnd, lowerBoundValue ) as previous element of first key
          insert(keyBegin, x) previous element of first key
        


      no overlap, last element
      insert(15, 18, x) -> map (-inf, m_valBegin), (-5, a), (-2, b), (10, c), (15, x), (18, c)
        upperBoundKey not exist -> end interator
          insert(keyBegin, x) as next element of end key
          insert(keyEnd, upperBoundValue) as next element of end key


      overlap with previous element
      insert(4, 7, x) -> map (-inf, m_valBegin), (-5, a), (-2, b), (4, x), (7, b) (10, c)
        upperBoundKey + lowerBoundKey exist
          insert(keyBegin, x) as previous element of upperBound
          insert(keyEnd, lowerBoundValue) as previous element of upperBound

      overlap with next element
      insert(4, 12,x) -> map (-inf, m_valBegin), (-5, a), (-2, b), (4, x), (12, c);
        upperBoundKey + lowerBoundKey exist
          insert(keyBegin, x) as previous element of upperBound
          update(keyEnd, upperBoundValue) as next lement of upperBound




    insert existing value

      map (-inf, m_valBegin), (-5, a), (-2, b), (10, c)
      lowerBound = current value in map
      keyBegin = min(keyBegin, lowerBoundKey);

      no overlap, fist element
      insert(-9, -7,a) -> map (-inf, m_valBegin), (-9,a), (-7, m_valBegin), (-5, a),  (-2, b), (10, c)
        upperBound value exist
          insert(keyBegin, a) as first element
          insert(keyEnd, lowerBoundVAlue) as second element

      no overlap, last element
      insert(15, 18, c) -> map (-inf, m_valBegin),  (-5, a), (-2, b), (10, c)
        upperBoundValue not exist
          do nothing



      overlap with previous element
      insert(-3, 7, b) -> map (-inf, m_valBegin),  (-5, a), (-4, b), (10, c)
        upperBound value exist
          insert(keyBegin, b) as previous element of upper Bound


      overlap with next element
      insert(4, 15, b) -> map  (-inf, m_valBegin), (-5, a), (-2, b), (15, c)
        upperBound value exist
          insert(keyBegin, b);
          insert(keyEnd, upperBound);


    insert valBegin
      map (-5, a), (-2, b), (10, c)

      no overlap, fist element
      insert(-9, -7, valBegin) -> map (-5, a),  (-2, b), (10, c)
        lowerboundKey = -inf
          do nothing

      overlap, first element
        insert(-5, -2, valBegin) -> map (-3, a), (-2, b), (10, c)
          lowerboundKey = -inf

    
    */
  }

  // look-up of the value associated with key
  V const &operator[](K const &key) const {
    auto it = m_map.upper_bound(key);
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

/* happy case
                m_valBegin =x ;
                assign(1, 3, x); -> [1, 3) = x
                (-inf, 1) = x
                [1, 3) = x
                [3, +inf) = x

                assign(5, 8, y); -> [5, 8) = y;

        (-inf, 1) = x
                [3, +5) = x
                [5, 8) = y;
                [8, +inf] = x;


                assign(7, 10, x); -> [7, 10) = x
        (-inf, 1) = x
                [3, 5) = x
                [5, 7) = y;
                [7, +inf] = x;

                assign(-5, -1, z) -> [-5, -1) = z;
        (-inf, -5) = x
        (-5, -1) = z
                [-1, 5) = x
                [5, 7) = y;
                [7, +inf] = x;
 */
#include <iostream>
int main() {
  std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
  std::cout << "hello aaaa aaaa ";
  return 0;
}
