// chp11 defiing abstract data types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <vector>
#include <string>;
using namespace std;

template <class T >class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() {
        create();
    }
    explicit Vec(size_type n, const T& t = T()) {
        create(n, t);
    }

    Vec(const Vec& v) {
        create(v.begin(), v.end());
    }

    Vec& operator=(const Vec&);
    ~Vec() {
        uncreate();
    }

    T& operator[](size_type i) {
        return data[i];
    }

    const T& operator[](size_type i) const {
        return data[i];
    }

    void push_back(const T& t) {
        if (avail == limit) {
            grow();
            unchecked_append(t);
        }
    }

    size_type size() const {
        return avail - data;
    }
    iterator begin() {
        return data;
    }

    const_iterator begin() const {
        return data;
    }

    iterator end() {
        return avail;
    }

    const_iterator end() const {
        return avail;
    }

private:
    iterator data;
    iterator avail;
    iterator limit;

    allocator<T> alloc;

    void create();
    void create(size_type, const T& t);
    void create(const_iterator, const_iterator);

    void uncreate();

    void grow();
    void unchecked_append(const T&);

};

template <class T> void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}


template<class T> void Vec <T>::grow() {

    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;

}

template <class T> void Vec<T>::uncreate() {
    if (data) {
        iterator it = avail;
        while (it != data) {
            alloc.destroy(--it);

           


        }

        // check on this
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template<class T> void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

int main()
{
    std::cout << "Hello World!\n";
    Vec<int> hey;

    hey.push_back(12);
    hey.push_back(1);

    cout << "hey[0]: " << hey[0] << " hey[1]: " << hey[1] << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
