//
// Created by Ivo Georgiev on 5/3/16.
//

#ifndef UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
#define UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H

// Naive partial implementation of a custom iterator.
// After Jeet Sukumaran https://github.com/jeetsukumaran

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <initializer_list>

namespace CS2312 {

    template <typename T>
    class fixed_array {

    public:

        typedef std::size_t size_type;

        class iterator {

        public:

            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            iterator(pointer ptr);
            self_type operator++();
            self_type operator++(int junk);
            reference operator*();
            pointer operator->();
            bool operator==(const self_type& rhs) const;
            bool operator!=(const self_type& rhs) const;

        private:

            pointer __ptr;

        };

        class const_iterator {

        public:

            typedef const_iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef size_type difference_type;

            const_iterator(pointer ptr);
            self_type operator++();
            self_type operator++(int junk);
            const value_type& operator*() const;
            const value_type* operator->() const;
            bool operator==(const self_type& rhs) const;
            bool operator!=(const self_type& rhs) const;

        private:

            pointer __ptr;

        };


        fixed_array(size_type size);

        fixed_array(std::initializer_list<T> list);

        ~fixed_array();

        size_type size() const;

        T& operator[](size_type index);

        const T& operator[](size_type index) const;

        iterator begin();

        iterator end();

        const_iterator begin() const;

        const_iterator end() const;

    private:

        T* __data;
        size_type __size;

    };

    template<typename T>
    fixed_array<T>::const_iterator::const_iterator(fixed_array::const_iterator::pointer ptr) : __ptr(ptr) { }

    template<typename T>
    typename fixed_array<T>::const_iterator::self_type fixed_array<T>::const_iterator::operator++() {
        return ++__ptr;
    }

    template<typename T>
    typename fixed_array<T>::const_iterator::self_type fixed_array<T>::const_iterator::operator++(int junk) {
        return __ptr++;
    }

    template<typename T>
    const typename fixed_array<T>::const_iterator::value_type &fixed_array<T>::const_iterator::operator*() const {
        return *__ptr;
    }

    template<typename T>
    const typename fixed_array<T>::const_iterator::value_type *fixed_array<T>::const_iterator::operator->() const {
        return __ptr;
    }

    template<typename T>
    bool fixed_array<T>::const_iterator::operator==(const self_type &rhs) const {
        return __ptr == rhs.__ptr;
    }

    template<typename T>
    bool fixed_array<T>::const_iterator::operator!=(const self_type &rhs) const {
        return __ptr != rhs.__ptr;
    }

    template<typename T>
    fixed_array<T>::iterator::iterator(fixed_array::iterator::pointer ptr) : __ptr(ptr) { }

    template<typename T>
    typename fixed_array<T>::iterator::self_type fixed_array<T>::iterator::operator++() {
        return ++__ptr;
    }

    template<typename T>
    typename fixed_array<T>::iterator::self_type fixed_array<T>::iterator::operator++(int junk) {
        return __ptr++;
    }

    template<typename T>
    typename fixed_array<T>::iterator::reference fixed_array<T>::iterator::operator*() {
        return *__ptr;
    }

    template<typename T>
    typename fixed_array<T>::iterator::pointer fixed_array<T>::iterator::operator->() {
        return __ptr;
    }

    template<typename T>
    bool fixed_array<T>::iterator::operator==(const self_type &rhs) const {
        return __ptr == rhs.__ptr;
    }

    template<typename T>
    bool fixed_array<T>::iterator::operator!=(const self_type &rhs) const {
        return __ptr != rhs.__ptr;
    }


    template<typename T>
    fixed_array<T>::fixed_array(fixed_array::size_type size) : __data(new T[size]), __size(size) {
        for(int i = 0; i < size; ++i)
            __data[i] = T();
    }

    template<typename T>
    fixed_array<T>::fixed_array(std::initializer_list<T> list) : __data(new T[(int)list.size()]), __size((int)list.size()){
        int i = 0;
        for(auto ptr = list.begin(); ptr != list.end(); ++ptr, ++i)
            __data[i] = *ptr;
    }

    template<typename T>
    fixed_array<T>::~fixed_array() {
        delete [] __data;
    }

    template<typename T>
    typename fixed_array<T>::size_type fixed_array<T>::size() const {
        return __size;
    }

    template<typename T>
    T &fixed_array<T>::operator[](typename fixed_array<T>::size_type index) {
        return __data[index];
    }

    template<typename T>
    const T &fixed_array<T>::operator[](typename fixed_array<T>::size_type index) const {
        return __data[index];
    }

    template<typename T>
    typename fixed_array<T>::iterator fixed_array<T>::begin() {
        return iterator(__data);
    }

    template<typename T>
    typename fixed_array<T>::iterator fixed_array<T>::end() {
        return iterator(__data + __size);
    }

    template<typename T>
    typename fixed_array<T>::const_iterator fixed_array<T>::begin() const {
        return const_iterator(__data);
    }

    template<typename T>
    typename fixed_array<T>::const_iterator fixed_array<T>::end() const {
        return const_iterator(__data + __size);
    }
}

#endif //UCD_CSCI2312_PA5_IMPL_CUSTOM_ITERATOR_H
