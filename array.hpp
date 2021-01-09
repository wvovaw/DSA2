#ifndef DSA_ARRAY_HPP
#define DSA_ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <sstream>

template <typename T, size_t N>
class array {
public:
    array() = default;
    explicit array(const T arr[]) {
      for(auto i = 0; i < N; ++i)
        _data[i] = arr[i];
    }
    const T *data() const {
      return _data;
    }
    T &operator[](unsigned int i) {
      if (0 <= i && i < N) return _data[i];
      else {
        std::ostringstream ss;
        ss << "Out of range! _data[" << i << "] is unavailable. Array bounds is [0.." << this->size() - 1 << "]";
        std::string errMsg = ss.str();
        throw std::out_of_range (errMsg);
      }
    }
    T &front() {
      if (!this->empty()) return _data[0];
      else throw std::out_of_range ("Array has size 0!");
    }
    T &back() {
      if (!this->empty()) return _data[N - 1];
      else throw std::out_of_range ("Array has size 0!");
    }
    T &at(unsigned int i) {
      if (this->empty())
        throw std::out_of_range ("Array has size 0!");
      else if (i > N - 1) {
        std::ostringstream ss;
        ss << "Out of range! _data[" << i << "] is unavailable. Array bounds is [0.." << this->size() - 1 << "]";
        std::string errMsg = ss.str();
        throw std::out_of_range (errMsg);
      }
      else return _data[i];
    }
    bool empty() {
      return N == 0;
    }
    size_t size() {
      return N;
    }

private:
    T _data[N];
};

#endif //DSA_ARRAY_HPP
