 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-24 11:12:56
 ///
 
#pragma once

#include "Noncopyable.h"

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;
 

namespace wd
{

class MutexLock
: Noncopyable
{
public:
	MutexLock()
	: _isLocking(false)
	{
		if(pthread_mutex_init(&_mutex, nullptr)) {
			perror(">> pthread_mutex_init");
		}
	}

	void lock()
	{
		if(pthread_mutex_lock(&_mutex)) {
			perror(">> pthread_mutex_lock");
		}
		_isLocking = true;
	}

	void unlock()
	{
		if(pthread_mutex_unlock(&_mutex)) {
			perror(">> pthread_mutex_unlock");
		}
		_isLocking = false;
	}

	bool isLocking() const
	{	return _isLocking;	}	

	pthread_mutex_t * getMutexLockPtr()
	{	return &_mutex;	}

	~MutexLock()
	{
		if(pthread_mutex_destroy(&_mutex)) {
			perror(">> pthread_mutex_destroy");
		}
	}

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

//创建对象的时候自动加锁，析构的时候，自动解锁 
class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}

private:
	MutexLock & _mutex;
};

}//end of namespace wd
