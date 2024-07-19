// Written by @sebight
// C# Linq implementation for C++
// July 2024
#pragma once
#include <vector>

#define COND(vars, cond) [](vars) { return cond; }
#define LINQ(vars, cond) COND(vars, cond)

namespace linqc {

	template<typename T>
	class vec : public std::vector<T> {
	public:

		// Internal vec 
		typedef std::vector<T> ivec;
		using ivec::vector;

		typedef T type;
		T& operator[](int i) { return ivec::at(i); }
		const T& operator[](int i) const { return ivec::at(i); }

		template<typename LFunc>
		vec<type> Where(LFunc cond) {
			vec<type> passed;
			for (auto it = this->cbegin(); it != this->cend(); ++it) {
				if (cond(*it)) {
					passed.push_back(*it);
				}
			}
			return passed;
		}

		template<typename LFunc>
		vec<type> Select(LFunc cond) {
			vec<type> res;
			for (auto it = this->cbegin(); it != this->cend(); ++it) {
				res.push_back(cond(*it));
			}
			return res;
		}

		size_t Sum() {
			size_t s = 0;
			for (auto it = this->cbegin(); it != this->cend(); ++it) {
				s += *it;
			}
			return s;
		}

		type Max() {
			type max = INT64_MIN;
			for (auto it = this->cbegin(); it != this->cend(); ++it) {
				if (*it > max) {
					max = *it;
				}
			}
			return max;
		}

		size_t Count() {
			return ivec::size();
		}

		template<typename LFunc>
		vec<type> OrderBy(LFunc cond) {
			// TODO: Finish impl
			return vec<type>;
		}

		template<typename LFunc>
		bool Any(LFunc cond)
		{
			for (auto it = this->cbegin(); it != this->cend(); ++it) {
				if (cond(*it)) {
					return true;
				}
			}

			return false;
		}
	};
}