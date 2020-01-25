
#include <algorithm>
#include <iterator>

#include <functional>
#include <vector>
#include <iostream>

class A
{
public:
	void print();
};


class postcondition
{

public:
	postcondition(std::function<bool()> check)
		: check_(check)
	{

	}
	
	~postcondition()
	{
		if (!check_())
			std::cerr << "Postcondition failed!\n";
	}

private:
	std::function<bool()> check_;
};

template<typename T>
std::vector<T> get_values(int n, std::function<T(T)> generator)
{
	std::vector<T> v;

	auto is_increasing =
		[&v]()
		{
			return std::is_sorted(v.begin(), v.end());
		};

	T j = 0;
	for (int i = 0; i != n; ++i)
	{
		j = generator(j);
		v.push_back(j);
	}

	{
		postcondition _(is_increasing);
	}

	return v;
}

template <typename T>
void sequence()
{
	auto const & result =
		get_values<T>(10,
			          [](T i) { return i + 1; }
	                  );

	std::copy(result.begin(), result.end(), 
				std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;
}

template <typename T>
void triangular()
{
	T i{};
	auto const & result = 
		get_values<T>(10,
					  [&i](T j) { return j + ++i; }
					  );
	std::copy(result.begin(), result.end(),
		std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;
}

template <typename T>
void fibonacci()
{
	T i{ 1 };
	auto const & result = 
		get_values<T>(10,
					 [&i](T k) { std::swap(i, k); return i + k; }
					 );
	std::copy(result.begin(), result.end(),
		std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;
}

template <typename T>
void sum_squares()
{
	T i{ 1 };
	auto const & result = 
		get_values<T>(10,
					  [&i](T j) { return j + i * i++; }
					  );
	std::copy(result.begin(), result.end(),
		std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;
}

