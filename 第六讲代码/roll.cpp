#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>

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
	using namespace std::chrono_literals;
	unsigned waitTime = 10;
	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << "等待... ";
		std::this_thread::sleep_for(1s);
		for(unsigned i = 0; i < waitTime; i++)
		{
			std::cout << waitTime - i << " " << std::flush;
			std::this_thread::sleep_for(1s);
		}
		std::cout << std::endl;
		std::cout << "第 " << i + 1 << " 名: " << v[i] << std::endl;
	}
	std::cout << "获奖序列生成完毕" << std::endl;
	return 0;
}