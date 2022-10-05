/**
 * @filename: CustomException.h
 * @author: WangKang
 * @blog: kang17.xyz
 * @email: 1686617586@qq.com
 * @date: 2022-10-05 18:09:40
 * @description: 自定义异常类
 */

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef __CUSTOMEXCEPTION_h__
#define __CUSTOMEXCEPTION_h__

class OutOfRange : public exception {
  private:
    int flag;  //不同的flag表示不同的错误
    int len;   //当前数组的长度
    int index; //当前使用的数组下标
    int high;
    int low;

  public:
    OutOfRange();
    OutOfRange(int len, int index);
    OutOfRange(int len, int low, int high);
    const char *what() const throw();
    ~OutOfRange();
};

OutOfRange::OutOfRange() : flag(1) {}

OutOfRange::OutOfRange(int len, int index) : flag(2), len(len), index(index) {}

OutOfRange::OutOfRange(int len, int low, int high)
    : flag(3), len(len), low(low), high(high) {}

const char *OutOfRange::what() const throw() {
    string out;
    stringstream ss;
    switch (flag) {
    case 1:
        ss << "Error: empty array.";
        break;
    case 2:
        ss << "Error: out of range( array length " << len << ", access index "
           << index << " )";
        break;
    case 3:
        ss << "Error: please check your range( len:" << len << " low:" << low
           << " high:" << high << " )";
        break;
    default:
        ss << "Unknown exception.";
        break;
    }
    out = ss.str();
    return out.c_str();
}

OutOfRange::~OutOfRange() {}

#endif