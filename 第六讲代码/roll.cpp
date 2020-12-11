#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

auto random_1ton(unsigned n)
{
	std::vector<unsigned> v;
	for(int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	std::random_device rd;
	std::mt19937 g(rd());
	
	std::shuffle(v.begin(), v.end(), g);
	return v;
}

int main(int argc, char *argv[])
{
	std::cout << "输入 n: ";
	unsigned n;
	std::cin >> n;
	std::vector<unsigned> v = random_1ton(n);
	
	std::cout << "获奖顺序:" << std::endl;
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
	return 0;
}