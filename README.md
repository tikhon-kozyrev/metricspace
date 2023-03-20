Simple templated classes for Metric Space representation. 

The main class is template <class T, size_t SIZE> class MetricSpace::TMetricSpace.

It has two parameters:

1. used numeric type
2. space dimension 

and 2 nested classes:

1. MetricSpace::TMetricSpace<>::Point - a [point](https://en.wikipedia.org/wiki/Point_(geometry)).
2. MetricSpace::TMetricSpace<>::Metric - a [metric](https://en.wikipedia.org/wiki/Metric).

and four static functions, each returns one of predefined metrics: 

1.  MetricSpace::TMetricSpace<>::Euclidian() - returns [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance).
2.  MetricSpace::TMetricSpace<>::SquaredEuclidian() - returns [squared Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_space).
3.  MetricSpace::TMetricSpace<>::Manhattan() - returns [Manhattan or taxicab](https://en.wikipedia.org/wiki/Taxicab_geometry).
4.  MetricSpace::TMetricSpace<>::Chebyshev() - returns [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance).
  

The main program (main.cpp) contains a "custom" metric "Weighted", parameterized by vector of "weights" of dimensions. The distance is calculated as a weighted sum of absolute dimensions differences.

The class MetricSpace::TMetricSpace was used to study [cluster analysis](https://en.wikipedia.org/wiki/Cluster_analysis).