#pragma once
#include "myinverse.h"
#include <vector>
#include <cmath>

std::vector<double> myInv(const std::vector<double> src) {
	std::vector<double> res;
	int n = std::sqrt(src.size());
	coder::array<double, 2U> src_t;
	coder::array<double, 2U> res_t;
	src_t.set_size(n, n);

	for (int idx0 = 0; idx0 < src_t.size(0); idx0++) {
		for (int idx1 = 0; idx1 < src_t.size(1); idx1++) {
			src_t[idx0 + src_t.size(0) * idx1] = src[idx0 + src_t.size(0) * idx1];
		}
	}

	myinverse(src_t, res_t);

	for (int idx0 = 0; idx0 < res_t.size(0); idx0++) {
		for (int idx1 = 0; idx1 < res_t.size(1); idx1++) {
			res.push_back(res_t[idx1 + res_t.size(1) * idx0]);
		}
	}

	return res;
}
