//
//  accumulate.hpp
//  itertools-cfar-a
//
//  Created by Lee Fingerhut on 08/06/2020.
//  Copyright © 2020 Lee Fingerhut. All rights reserved.
//
#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace itertools {
typedef struct {
    template <typename C>
    C operator ()(C a, C b) const{
        return a + b;
    }
} plus;
 
template <typename C,typename F = plus>
class accumulate {
public:
    C container;
    F function;
    
    accumulate(C cont,F func =plus()) :container(cont),function(func) {}
    
    class iterator {
    public:
        typename C::iterator iter;
        typename C::iterator end;
        decltype(*(container.begin())) data;
        F function;
    public:
        explicit iterator(typename C::iterator iter, typename C::iterator end, F func)
        : iter(iter), end(end), function(func), data(*iter){};
        //==
        bool operator ==(const iterator& other) const {
            return (iter == other.iter);
        }
        //!=
        bool operator !=(const iterator& other) const {
            return other.iter != iter;
        }
        iterator &operator=(const iterator &other) {
            if (*this != other){
                this->iter = other.iter;
                this->end = other.end;
                this->data = other.data;
                this->function = other.function;
            }
            return *this;
        }
        //*
        auto operator *() {
            return data;
        }
        //++
        iterator& operator++() {
            ++iter;
            if(iter != end){
                data=function(data, *iter);
            }
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++iter;
            if (iter != end)
                data = function(data, *iter);
            return temp;
        }
    };
    iterator begin() {
        return iterator(container.begin(), container.end(), function);
    }
    iterator end() {
        return iterator(container.end(), container.end(), function);
    }
};
}
