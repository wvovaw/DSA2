#ifndef DSA_LIST_HPP
#define DSA_LIST_HPP

template<typename T>
class list {
public:
    list() {
    };
    list(size_t n, T val) {
      head = new Node(val);
      tail = head;
      for(auto i = 0; i < n - 1; ++i)
        push_front(val);
      this->_size = n;
    }
    list(const T arr[], size_t size) {
      for(auto i = 0; i < size; ++i)
        push_front(arr[i]);
      this->_size = size;
    }
    list(const list &l) {
      Node* current = l.back();
      do {
        push_back(current->data);
        current = current->next;
        ++_size;
      } while (current != nullptr);
    }

    void push_back(const T &val) {
      Node *node = new Node(val);
      if(head == nullptr) {
        head = node;
        tail = node;
      }
      else {
        tail->prev = node;
        tail->prev->next = tail;
        tail = tail->prev;
      }
      ++_size;
    }
    void push_front(const T &val) {
      Node *node = new Node(val);
      if(head == nullptr) {
        head = node;
        tail = node;
      }
      else {
        head->next = node;
        head->next->prev = head;
        head = head->next;
      }
      ++_size;
    }
    void pop_front() {
      if (head != nullptr) {
        if (head->prev != nullptr) {
          head = head->prev;
          delete head->next;
          head->next = nullptr;
        }
        else {
          delete head;
          head = nullptr;
        }
        --_size;
      }
    }
    void pop_back() {
      if (tail != nullptr ) {
        if (tail->next != nullptr) {
          tail = tail->next;
          delete tail->prev;
          tail->prev = nullptr;
        }
        else {
          delete tail;
          tail = nullptr;
        }
        --_size;
      }
    }
    auto front() {
      return head;
    }
    auto back() {
      return tail;
    }
    size_t size() {
      return _size;
    }
    void insert(unsigned int pos, const T& val) {
      auto current = tail;
      if (pos == 0) {
        Node *node = new Node(val);
        node->next = tail;
        tail->prev = node;
        tail = node;
        ++_size;
      }
      else if (pos < _size) {
        for (auto i = 0; i < pos; ++i)
          current = current->next;
        Node *node = new Node(val);
        node->prev = current;
        node->next = current->next;
        if (current->next != nullptr) current->next->prev = node;
        current->next = node;
        ++_size;
      }
      else if (pos == _size) {
        Node *node = new Node(val);
        node->prev = head;
        head->next = node;
        head = node;
        ++_size;
      }
      else {
        std::ostringstream ss;
        ss << "List's size is " << _size << ". Max index is " << _size << " for this list.";
        throw std::out_of_range (ss.str());
      }
    }
    void insert(unsigned int pos, unsigned int count, const T& val) {
      auto current = tail;
      if (pos == 0) {
        list sublist(count, val);
        sublist.front()->next = tail;
        tail->prev = sublist.front();
        tail = sublist.back();
        _size += count;
      }
      else if (pos < _size) {
        for (auto i = 0; i < pos; ++i)
          current = current->next;
       list sublist(count, val);
       sublist.front()->next = current->next;
       if (current->next != nullptr)
         current->next->prev = sublist.front();
       sublist.back()->prev = current;
       current->next = sublist.back();
       _size += count;
      }
      else if (pos == _size) {
        list sublist(count, val);
        sublist.back()->prev = head;
        head->next = sublist.back();
        head = sublist.front();
        _size += count;
      }
      else {
        std::ostringstream ss;
        ss << "List's size is " << _size << ". Max index is " << _size << " for this list.";
        throw std::out_of_range (ss.str());
      }
    }
private:
    class Node {
    public:
        Node() = default;
        Node(const T& val) : data(val) {}
        void setData(const T& val) { data = val; }
        auto getData() {
          return data;
        }
    public:
        T data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    size_t _size = 0;
};

#endif //DSA_LIST_HPP
