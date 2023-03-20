/*
	Copyright (c) 2023 Tikhon Kozyrev (tikhon.kozyrev@gmail.com)
*/
#include "metricspace/metricspace.hpp"

#include <cmath>

namespace MetricSpace {
	namespace Math {
		template <> double Abs(double const &v) {
			return fabs(v);
		}
		template <> long double Abs(long double const &v) {
			return fabsl(v);
		}
		template <> float Abs(float const &v) {
			return fabsf(v);
		}

		template <> double Pow(const double &base, double power) {
			return pow(base, power);
		}
		template <> long double Pow(const long double &base, double power) {
			return powl(base, power);
		}
		template <> float Pow(const float &base, double power) {
			return powf(base, power);
		}

		template <> double Sqrt(double const &v) {
			return sqrt(v);
		}
		template <> long double Sqrt(long double const &v) {
			return sqrtl(v);
		}
		template <> float Sqrt(float const &v) {
			return sqrtf(v);
		}
	}
}
