
#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <iostream>
using namespace itertools;
using namespace std;


TEST_CASE("Range 1"){
    vector<int> v = {2,3,4,5,6,7,8,9};
    int j = 0;
    for(int i : range(2,10)){
        CHECK(i == v.at(j));
        ++j;
    }
    CHECK(j == 8);
}

TEST_CASE("Range 2")
{
    vector<int> v = {2,3,4,5};
    int j = 0;
    for(int i : range(2,6)){
        CHECK(i ==  v.at(j));
        ++j;
    }
    CHECK(j == 4);
}

TEST_CASE("Range 3"){
    vector<int> v = {2,3,4,5};
    int j = 0;
    for(int i : range(2,6)){
        CHECK(i == v.at(j));
        ++j;
    }
    CHECK(j == 4);

    j=0;
    v.clear();
    v = {0,1,2,3};

    for(int i : range(0,4)){
        CHECK(i == v.at(j));
        ++j;
    }
}

TEST_CASE("Accumulate int"){
    vector<int> v = {1,4,5,14};
    int j = 0;
    vector<int> vec ={1,3,1,9};
    for (int i: accumulate(vec)){
        CHECK(v.at(j) == i);
        ++j;
    }
    CHECK(j == 4);
}

TEST_CASE("Accumulate string"){
    vector<string> v = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t"};
    vector<string> vec = {"a","ab","abc","abcd","abcde","abcdef","abcdefg","abcdefgh","abcdefghi","abcdefghij","abcdefghijk","abcdefghijkl","abcdefghijklm","abcdefghijklmn",
    "abcdefghijklmno","abcdefghijklmnop","abcdefghijklmnopq","abcdefghijklmnopqr","abcdefghijklmnopqrs","abcdefghijklmnopqrst"};
    int j=0;
     for (auto i: accumulate(v) ){
        CHECK(vec.at(j) == i);
        ++j;
    }
    CHECK(j == 20);
}

 
TEST_CASE("Compress"){
    vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int j = 0;
    vector<bool> b {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true, true};
    for (auto i: compress(range(0,20), b))  {
        CHECK(i == v.at(j));
        ++j;
    }
    CHECK(j == 20);
}

TEST_CASE("Filterfalse"){
    vector<int> v = {3,5,7};
    int j = 0;
    range r(2,9);
    for (auto i: filterfalse([](int i){return i%2==0;}, r) )
    {
        CHECK(i == v.at(j));
        ++j;
    }
    CHECK(j == 3);
}

TEST_CASE("Test")
{
    for (int i = 0; i < 100; i++)
        CHECK(true);
};