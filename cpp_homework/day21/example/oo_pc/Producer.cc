///
/// @file    Producer.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2019-07-15 11:31:58
///

#include "Producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

void Producer::run()
{
	::srand(::time(nullptr));
	int cnt = 10;
	// 先放1个数据，消费者才能消费1个数据
	while (cnt--)
	{
		int number = ::rand() % 100;
		_que.push(number);
		cout << "cnt = " << cnt << "producer thread " << pthread_self()
			 << ": produce a number = " << number << endl;
		// 消费者等待生产者的状态
		::sleep(1);
	}
}
} //end of namespace wd
