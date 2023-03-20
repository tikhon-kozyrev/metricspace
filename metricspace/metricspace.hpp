/*
	Copyright (c) 2023 Tikhon Kozyrev (tikhon.kozyrev@gmail.com)
*/
#ifndef METRICSPACE_METRICSPACE_HPP
#define METRICSPACE_METRICSPACE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <stdexcept>
#include <limits>

namespace MetricSpace {
	namespace Math {
		template <class T> T Abs(T const &) {
			throw std::runtime_error(std::string("template <class T> T Abs(T const&) not defined for type '")+ typeid(T).name()+"'");
		}
		template <> double Abs(double const &);
		template <> long double Abs(long double const &);
		template <> float Abs(float const &);

		template <class T> T Pow(T const &, double) {
			throw std::runtime_error(std::string("template <class T> T Pow(T const &, double) not defined for type '")+ typeid(T).name()+"'");
		}
		template <> double Pow(double const &, double);
		template <> long double Pow(long double const &, double);
		template <> float Pow(float const &, double);

		template <class T> T Sqrt(T const &) {
			throw std::runtime_error(std::string("template <class T> T Sqrt(T const &) not defined for type '")+ typeid(T).name()+"'");
		}
		template <> double Sqrt(double const &);
		template <> long double Sqrt(long double const &);
		template <> float Sqrt(float const &);

	}

	template <class T, size_t SIZE> bool operator == (std::array<T, SIZE> const &a, std::array<T, SIZE> const &b) {
		for (size_t i=0; i<a.size(); ++i)
			if (Abs(a[i] - b[i]) > std::numeric_limits<T>::epsilon()) {
				return false;
			}
		return true;
	}

	template <class T, size_t SIZE> class TMetricSpace {
		public:
			using Number = T;
			using Point = std::array<T, SIZE>;
			using Metric = std::function<T(Point const &, Point const &)>;

			static Metric Euclidian() {
				return [] (Point const& A, Point const& B) -> T{
					T sum = 0;
					for (size_t i = 0; i < A.size(); i++) {
						sum += Math::Pow((A[i] - B[i]), 2);
					}
					return Math::Sqrt(sum);
				};
			}
			static Metric SquaredEuclidian() {
				return [] (Point const& A, Point const& B) -> T{
					T sum = 0;
					for (size_t i = 0; i < A.size(); i++) {
						sum += Math::Pow((A[i] - B[i]), 2);
					}
					return sum;
				};
			}
			static Metric Manhattan() {
				return [] (Point const& A, Point const& B) -> T{
					T sum = 0;
					for (size_t i = 0; i < A.size(); i++) {
						sum += Math::Abs(A[i] - B[i]);
					}
					return sum;
				};
			}
			static Metric Chebyshev() {
				return [] (Point const& A, Point const& B) -> T{
					T last = 0;
					T next = 0;
					for (size_t i = 0; i < A.size(); i++) {
						next = Math::Abs(A[i] - B[i]);
						if (last < next) {
							last = next;
						}
					}
					return last;
				};
			}
	};
}

#endif
