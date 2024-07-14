// Written by @sebight
// C# Linq implementation for C++
// July 2024
#pragma once
#include <vector>

#define COND(vars, cond) [](vars) { return cond; }

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

		size_t Count() {
			return ivec::size();
		}
	};
}