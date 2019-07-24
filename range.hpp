#ifndef HQRP_RANGE_HPP
#define HQRP_RANGE_HPP

#include <cstddef>
#include <iterator>

template <typename T>
struct range_number_holder {
	using type = T;
	T value;
};

template <typename T>
struct range_wrapper {
   private:
	template <typename U>
	struct range_iterator {
		using value_type = U;
		using difference_type = std::size_t;
		using reference = U &;
		using pointer = U *;

		value_type m_value;

		range_iterator(value_type val = 0) : m_value(val) {
		}

		range_iterator & operator++() {
			++m_value;
			return *this;
		}
		range_iterator operator++(int) {
			range_iterator it = *this;
			++m_value;
			return it;
		}

		bool operator==(range_iterator rhs) {
			return m_value == rhs.m_value;
		}
		bool operator!=(range_iterator rhs) {
			return m_value != rhs.m_value;
		}

		reference operator*() {
			return m_value;
		}
		pointer operator->() {
			return &m_value;
		}
	};

   public:
	using value_type = T;
	using iterator = range_iterator<T>;
	using const_iterator = range_iterator<const T>;

	range_number_holder<T> start_holder;
	range_number_holder<T> end_holder;
	iterator begin() {
		return { start_holder.value };
	}
	const_iterator begin() const {
		return { start_holder.value };
	}
	iterator end() {
		return { end_holder.value + 1 };
	}
	const_iterator end() const {
		return { end_holder.value + 1 };
	}
};

template <typename T>
range_wrapper<T> operator->*(range_number_holder<T> lhs,
							 unsigned long long rhs) {
	static_assert(std::is_integral<T>::value,
				  "Range operator can only be used with integral values.");
	return { lhs, { rhs } };
}

range_number_holder<unsigned long long> operator"" _(unsigned long long value) {
	return { value };
}

#endif
