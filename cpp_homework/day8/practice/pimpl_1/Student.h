#pragma once

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//PIMPL设计模式
//
//作用
//	1. 实现信息隐藏
//	2. 降低编译依赖, 
//	3. 只要接口不变, 头文件不变，实现可以随便改造, 可以以一个最小代价完成库的平滑升级
//
class Student
{
	class StudentImpl;
public:
	Student(int, int, int);
	~Student();

	void printMessage() const;

private:
	StudentImpl * _pimpl;
};

