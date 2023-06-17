#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
//pre:null
//post: checks if user input is in array
void check(int arr[200]);
//pre:null
//post: removes value at user specified index
void remove(int arr[200]);
//pre:null
//post: adds user value at the end of array
void addition(int arr[200]);
//pre:null
//post: replaces a user chosen value with a value of their own
void modify(int arr[200]);
//pre:null
//post: inserts integers from file into array
void read();
