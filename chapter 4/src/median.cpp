/*
 * median.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: fran
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <string>
#include "median.h"
using std::vector;
using std::domain_error;

double median1 (vector<double> vec){
	double median = 0;
	std::sort(vec.begin(), vec.end());

	if (vec.size() == 0){

		throw domain_error("vec is null");

	}

	if ((vec.size()) % 2 != 0){

		median = (vec.size() / 2) + 1;

	}
	else {
		median = vec.size() / 2;

	}
	return vec[median - 1]; // keep in mid for 0
	}

