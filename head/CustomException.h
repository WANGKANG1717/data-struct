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
    static const string type[10];
    int flag;     //不同的flag表示不同的错误
    int typeFlag; //标识数据结构类型
    int len;      //当前数组的长度
    int index;    //当前使用的数组下标
    int high;
    int low;

  public:
    //默认数组
    OutOfRange(int TypeFlag);
    OutOfRange(int len, int index, int typeFlag);
    OutOfRange(int len, int low, int high, int typeFlag);
    const char *what() const throw();
    ~OutOfRange(){};
};

const string OutOfRange::type[] = {"Array", "LinkList"};

OutOfRange::OutOfRange(int TypeFlag) : flag(1), typeFlag(TypeFlag) {}

OutOfRange::OutOfRange(int len, int index, int typeFlag)
    : flag(2), len(len), index(index), typeFlag(typeFlag) {}

OutOfRange::OutOfRange(int len, int low, int high, int typeFlag)
    : flag(3), len(len), low(low), high(high), typeFlag(typeFlag) {}

const char *OutOfRange::what() const throw() {
    string out;
    stringstream ss;
    switch (flag) {
    case 1:
        ss << "Error: empty " << type[typeFlag] << ".";
        break;
    case 2:
        ss << "Error: out of range( " << type[typeFlag] << " length " << len
           << ", access index " << index << " )";
        break;
    case 3:
        ss << "Error: please check your " << type[typeFlag]
           << " range( len:" << len << " low:" << low << " high:" << high
           << " )";
        break;
    default:
        ss << "Unknown exception.";
        break;
    }
    out = ss.str();
    return out.c_str();
}

#endif