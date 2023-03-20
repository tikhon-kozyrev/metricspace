/*
	Copyright (c) 2023 Tikhon Kozyrev (tikhon.kozyrev@gmail.com)
*/
#include <iostream>

#include "metricspace/metricspace.hpp"

using MyMetricSpace = MetricSpace::TMetricSpace<double, 3>;

static MyMetricSpace::Metric Weighted(const MyMetricSpace::Point &weights) {
	return [weights] (MyMetricSpace::Point const& A, MyMetricSpace::Point const& B) -> MyMetricSpace::Number{
		MyMetricSpace::Number sum = 0;
		for (size_t i = 0; i < A.size(); i++) {
			sum += MetricSpace::Math::Abs(A[i] - B[i]) * weights[i];
		}
		return sum;
	};
}


int main() {
	MyMetricSpace::Point p1{1, 4, 8};
	MyMetricSpace::Point p2{-1, -4, 8};

	MyMetricSpace::Metric euclidian = MyMetricSpace::Euclidian();
	MyMetricSpace::Metric squaredeuclidian = MyMetricSpace::SquaredEuclidian();
	MyMetricSpace::Metric manhattan = MyMetricSpace::Manhattan();
	MyMetricSpace::Metric chebyshev = MyMetricSpace::Chebyshev();
	MyMetricSpace::Metric weighted = Weighted({3, 0, 1});

	std::cout << "Distances:" << std::endl;
	std::cout << "Euclidian = " << euclidian(p1, p2) << std::endl;
	std::cout << "SquaredEuclidian = " << squaredeuclidian(p1, p2) << std::endl;
	std::cout << "Manhattan = " << manhattan(p1, p2) << std::endl;
	std::cout << "Chebyshev = " << chebyshev(p1, p2) << std::endl;
	std::cout << "Weighted = " << weighted(p1, p2) << std::endl;

	std::cout << "Done." << std::endl;
	return 0;
}
