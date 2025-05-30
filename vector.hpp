#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {
  /**
   * a data container like std::vector
   * store data in a successive memory and support random access.
   */
  template<typename T>
  class vector {
    std::allocator<T> alloc;

  public:
    T *vct = nullptr;
    size_t size_;
    size_t capacity_;
    /**
     * TODO
     * a type for actions of the elements of a vector, and you should write
     *   a class named const_iterator with same interfaces.
     */
    /**
     * you can see RandomAccessIterator at CppReference for help.
     */
    class const_iterator;

    class iterator {
      // The following code is written for the C++ type_traits library.
      // Type traits is a C++ feature for describing certain properties of a type.
      // For instance, for an iterator, iterator::value_type is the type that the
      // iterator points to.
      // STL algorithms and containers may use these type_traits (e.g. the following
      // typedef) to work properly. In particular, without the following code,
      // @code{std::sort(iter, iter1);} would not compile.
      // See these websites for more information:
      // https://en.cppreference.com/w/cpp/header/type_traits
      // About value_type: https://blog.csdn.net/u014299153/article/details/72419713
      // About iterator_category: https://en.cppreference.com/w/cpp/iterator
    public:
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = T *;
      using reference = T &;
      using iterator_category = std::output_iterator_tag;

    private:
      /**
       * TODO add data members
       *   just add whatever you want.
       */
    public:
      T *p = nullptr;
      vector *v = nullptr;

      iterator() = default;

      iterator(T *p, vector *v) : p(p), v(v) {}

      /**
       * return a new iterator which pointer n-next elements
       * as well as operator-
       */
      iterator operator+(const int &n) const {
        //TODO
        if (v == nullptr) {
          return iterator();
        }
        return iterator(p + n, v);
      }

      iterator operator-(const int &n) const {
        //TODO
        if (v == nullptr) {
          return iterator();
        }
        return iterator(p - n, v);
      }

      // return the distance between two iterators,
      // if these two iterators point to different vectors, throw invalid_iterator.
      int operator-(const iterator &rhs) const {
        //TODO
        if (v != rhs.v) {
          throw invalid_iterator();
        }
        return p - rhs.p;
      }

      iterator &operator+=(const int &n) {
        //TODO
        if (v == nullptr) {
          return *this;
        }
        p += n;
        return *this;
      }

      iterator &operator-=(const int &n) {
        //TODO
        if (v == nullptr) {
          return iterator();
        }
        p -= n;
        return *this;
      }

      /**
       * TODO iter++
       */
      iterator operator++(int) {
        if (v == nullptr) {
          return iterator();
        }
        iterator tmp(p, v);
        p += 1;
        return tmp;
      }

      /**
       * TODO ++iter
       */
      iterator &operator++() {
        if (v == nullptr) {
          return *this;
        }
        p += 1;
        return *this;
      }

      /**
       * TODO iter--
       */
      iterator operator--(int) {
        if (v == nullptr) {
          return iterator();
        }
        iterator tmp(p, v);
        p -= 1;
        return tmp;
      }

      /**
       * TODO --iter
       */
      iterator &operator--() {
        if (v == nullptr) {
          return iterator();
        }
        p -= 1;
        return *this;
      }

      /**
       * TODO *it
       */
      T &operator*() const {
        return *p;
      }

      /**
       * an operator to check whether two iterators are same (pointing to the same memory address).
       */
      bool operator==(const iterator &rhs) const {
        return p == rhs.p;
      }

      bool operator==(const const_iterator &rhs) const {
        return p == rhs.p;
      }

      /**
       * some other operator for iterator.
       */
      bool operator!=(const iterator &rhs) const {
        return p != rhs.p;
      }

      bool operator!=(const const_iterator &rhs) const {
        return p != rhs.p;
      }
    };

    /**
     * TODO
     * has same function as iterator, just for a const object.
     */
    class const_iterator {
    public:
      using difference_type = std::ptrdiff_t;
      using value_type = T;
      using pointer = T *;
      using reference = T &;
      using iterator_category = std::output_iterator_tag;

    private:
      /*TODO*/
    public:
      const T *p = nullptr;
      const vector *v = nullptr;

      const_iterator() = default;

      const_iterator(const T *p, const vector *v) : p(p), v(v) {
      }

      /**
       * return a new iterator which pointer n-next elements
       * as well as operator-
       */
      const_iterator operator+(const int &n) const {
        //TODO
        if (v == nullptr) {
          return const_iterator();
        }
        return const_iterator(p + n, v);
      }

      const_iterator operator-(const int &n) const {
        //TODO
        if (v == nullptr) {
          return const_iterator();
        }
        return const_iterator(p - n, v);
      }

      // return the distance between two iterators,
      // if these two iterators point to different vectors, throw invalid_iterator.
      int operator-(const const_iterator &rhs) const {
        //TODO
        if (v != rhs.v) {
          throw invalid_iterator();
        }
        return p - rhs.p;
      }

      const_iterator &operator+=(const int &n) {
        //TODO
        if (v == nullptr) {
          return *this;
        }
        p += n;
        return *this;
      }

      const_iterator &operator-=(const int &n) {
        //TODO
        if (v == nullptr) {
          return const_iterator();
        }
        p -= n;
        return *this;
      }

      /**
       * TODO iter++
       */
      const_iterator operator++(int) {
        if (v == nullptr) {
          return const_iterator();
        }
        const_iterator tmp(p, v);
        p += 1;
        return tmp;
      }

      /**
       * TODO ++iter
       */
      const_iterator &operator++() {
        if (v == nullptr) {
          return *this;
        }
        p += 1;
        return *this;
      }

      /**
       * TODO iter--
       */
      const_iterator operator--(int) {
        if (v == nullptr) {
          return const_iterator();
        }
        const_iterator tmp(p, v);
        p -= 1;
        return tmp;
      }

      /**
       * TODO --iter
       */
      const_iterator &operator--() {
        if (v == nullptr) {
          return const_iterator();
        }
        p -= 1;
        return *this;
      }

      /**
       * TODO *it
       */
      const T &operator*() const {
        return *p;
      }

      /**
       * an operator to check whether two iterators are same (pointing to the same memory address).
       */
      bool operator==(const iterator &rhs) const {
        return p == rhs.p;
      }

      bool operator==(const const_iterator &rhs) const {
        return p == rhs.p;
      }

      /**
       * some other operator for iterator.
       */
      bool operator!=(const iterator &rhs) const {
        return p != rhs.p;
      }

      bool operator!=(const const_iterator &rhs) const {
        return p != rhs.p;
      }
    };

    /**
     * TODO Constructs
     * At least two: default constructor, copy constructor
     */
    vector() {
      vct = alloc.allocate(256);
      capacity_ = 256;
      size_ = 0;
    }

    vector(const vector &other) {
      capacity_ = other.capacity_;
      vct = alloc.allocate(other.capacity_);
      size_ = other.size_;
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::construct(alloc, vct + i, other[i]);
      }
    }

    /**
     * TODO Destructor
     */
    ~vector() {
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + i);
      }
      alloc.deallocate(vct, capacity_);
    }

    /**
     * TODO Expand space
     */
    void DoubleSpace() {
      T *new_vct = alloc.allocate(capacity_ * 2);
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::construct(alloc, new_vct + i, (*this)[i]);
      }
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + i);
      }
      alloc.deallocate(vct, capacity_);
      capacity_ *= 2;
      vct = new_vct;
    }

    /**
     * TODO Assignment operator
     */
    vector &operator=(const vector &other) {
      if (this == &other) {
        return *this;
      }
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + i);
      }
      alloc.deallocate(vct, capacity_);
      capacity_ = other.capacity_;
      vct = alloc.allocate(capacity_);
      size_ = other.size_;
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::construct(alloc, vct + i, other[i]);
      }
      return *this;
    }

    /**
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     */
    T &at(const size_t &pos) {
      if (pos >= size_) {
        throw index_out_of_bound();
      }
      return *(vct + pos);
    }

    const T &at(const size_t &pos) const {
      if (pos >= size_) {
        throw index_out_of_bound();
      }
      return *(vct + pos);
    }

    /**
     * assigns specified element with bounds checking
     * throw index_out_of_bound if pos is not in [0, size)
     * !!! Pay attentions
     *   In STL this operator does not check the boundary, but I want you to do.
     */
    T &operator[](const size_t &pos) {
      if (pos >= size_) {
        throw index_out_of_bound();
      }
      return *(vct + pos);
    }

    const T &operator[](const size_t &pos) const {
      if (pos >= size_) {
        throw index_out_of_bound();
      }
      return *(vct + pos);
    }

    /**
     * access the first element.
     * throw container_is_empty if size == 0
     */
    const T &front() const {
      if (size_ == 0) {
        throw container_is_empty();
      }
      return *vct;
    }

    /**
     * access the last element.
     * throw container_is_empty if size == 0
     */
    const T &back() const {
      if (size_ == 0) {
        throw container_is_empty();
      }
      return *(vct + size_ - 1);
    }

    /**
     * returns an iterator to the beginning.
     */
    iterator begin() {
      return iterator(vct, this);
    }

    const_iterator begin() const {
      return const_iterator(const_cast<const T *>(vct), const_cast<const vector *>(this));
    }

    const_iterator cbegin() const {
      return const_iterator(const_cast<const T *>(vct), const_cast<const vector *>(this));
    }

    /**
     * returns an iterator to the end.
     */
    iterator end() {
      return iterator(vct + size_, this);
    }

    const_iterator end() const {
      return const_iterator(const_cast<const T *>(vct + size_),
                            const_cast<const vector *>(this));
    }

    const_iterator cend() const {
      return const_iterator(const_cast<const T *>(vct + size_),
                            const_cast<const vector *>(this));
    }

    /**
     * checks whether the container is empty
     */
    bool empty() const {
      return size_ == 0;
    }

    /**
     * returns the number of elements
     */
    size_t size() const {
      return size_;
    }

    /**
     * clears the contents
     */
    void clear() {
      for (size_t i = 0; i < size_; ++i) {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + i);
      }
      size_ = 0;
    }

    /**
     * inserts value at index ind.
     * after inserting, this->at(ind) == value
     * returns an iterator pointing to the inserted value.
     * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
     */
    iterator insert(const size_t &ind, const T &value) {
      if (ind > size_) {
        throw index_out_of_bound();
      }
      if (size_ == capacity_) {
        T *new_vct = nullptr;
        new_vct = alloc.allocate(capacity_ * 2); // T** new_vct = new T*[capacity_ * 2];
        for (size_t i = 0; i < ind; ++i) {
          std::allocator_traits<decltype(alloc)>::construct(alloc, new_vct + i, *(vct + i));
          // new_vct[i] = new T(*vct[(beg_ind + i) % capacity_]);
        }
        std::allocator_traits<decltype(alloc)>::construct(alloc, new_vct + ind, value); // new_vct[ind] = new T(value);
        for (size_t i = ind; i < size_; ++i) {
          std::allocator_traits<decltype(alloc)>::construct(alloc, new_vct + i + 1, *(vct + i));
          // new_vct[i + 1] = new T(*vct[(beg_ind + i) % capacity_]);
        }
        const size_t tmp_size = size_ + 1;
        clear();
        size_ = tmp_size;
        alloc.deallocate(vct, capacity_); // delete[] vct;
        capacity_ *= 2;
        vct = new_vct;
        return iterator(vct + ind, this);
      }

      std::allocator_traits<decltype(alloc)>::construct(alloc, vct + size_, value);
      // vct[(beg_ind + size_) % capacity_] = new T(value);
      for (size_t i = size_; i > ind; --i) {
        vct[i] = vct[i - 1];
      }
      vct[ind] = value;
      ++size_;
      return iterator(vct + ind, this);
    }

    /**
     * inserts value before pos
     * returns an iterator pointing to the inserted value.
     */
    iterator insert(iterator pos, const T &value) {
      const size_t ind = pos - begin();
      if (ind > size_) {
        throw index_out_of_bound();
      }
      return insert(ind, value);
    }

    /**
     * removes the element with index ind.
     * return an iterator pointing to the following element.
     * throw index_out_of_bound if ind >= size
     */
    iterator erase(const size_t &ind) {
      if (ind >= size_) {
        throw index_out_of_bound();
      }
      if (size_ == 1) {
        clear();
        return end();
      }

      for (size_t i = ind + 1; i < size_; ++i) {
        vct[i - 1] = vct[i];
      }
      --size_;
      std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + size_);
      // delete vct[(beg_ind + size_) % capacity_];
      return iterator(vct + ind, this); // todo: originally (vct + size_)
    }

    /**
     * removes the element at pos.
     * return an iterator pointing to the following element.
     * If the iterator pos refers the last element, the end() iterator is returned.
     */
    iterator erase(iterator pos) {
      const size_t ind = pos - begin();
      if (ind >= size_) {
        throw index_out_of_bound();
      }
      if (size_ == 1) {
        clear();
        return end();
      }
      return erase(ind);
    }

    /**
     * adds an element to the end.
     */
    void push_back(const T &value) {
      if (size_ == capacity_) {
        DoubleSpace();
      }
      std::allocator_traits<decltype(alloc)>::construct(alloc, vct + size_, value);
      // vct[(beg_ind + (size_++)) % capacity_] = new T(value);
      ++size_;
    }

    /**
     * remove the last element from the end.
     * throw container_is_empty if size() == 0
     */
    void pop_back() {
      if (size_ == 0) {
        throw container_is_empty();
      }
      if (size_ == 1) {
        clear();
      } else {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, vct + size_ - 1);
        // delete vct[(beg_ind + size_ - 1) % capacity_];
        --size_;
      }
    }
  };
}

#endif
