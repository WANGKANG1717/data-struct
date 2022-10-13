/**
 * @author: WangKang
 * @blog: kang17.xyz
 * @filename: String.h
 * @filepath: head\String.h
 * @date: 2022-10-10 14:35:21
 * @description: 字符串类
 */
/**
 * @date: 2022-10-11 13:44:54
 * @description:
 * 因为搞同步的原因，花费了相当的多的时间，哎，哭了，最后大仙VSC自带同步
 */

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <ostream>
#include <string.h>
using namespace std;
class String {
  private:
    char *ch;
    int size;

  public:
    String();                                                  //
    String(const char *init);                                  //
    String(const String &s);                                   //
    ~String();                                                 //
    friend istream &operator>>(istream &in, const String &s);  //
    friend ostream &operator<<(ostream &out, const String &s); //
    // istream &operator>>(istream &in);
    // ostream &operator<<(ostream &out);
    int operator==(String &op) const;   //
    int operator!=(String &op) const;   //
    int operator!() const;              //
    int operator<(String &op) const;    //
    int operator>(String &op) const;    //
    String &operator=(const String &s); //
    String &operator=(char *ch);        //
    String operator+(const String &s);  //
    String operator+=(const String &s); //
    char &operator[](int index) const;  //
    int BF_find(const String &s) const; //
    int KMP_find(const String &s);      //
    void getNext(int *next) const;      //
    int getSize() const;                //
    char *c_str() const;                //
    /**
     * @date: 2022-10-12 15:18:05
     * @description: 明天搞完这两个函数，就可以开始树了
     *              工程浩大啊
     */
    void reverse();
    // next修正值
    void getNextVal(int *next);
};
String::String() { size = 0; }

String::String(const char *init) {
    // cout << "String(const char *init)" << endl;
    size = strlen(init);
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = init[i];
    }
}

String::String(const String &s) {
    // cout << "String(const String &s)" << endl;
    size = s.size;
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = s[i];
    }
}

String::~String() {
    if (size > 0)
        delete (ch);
}

istream &operator>>(istream &in, const String &s) {
    for (int i = 0; i < s.getSize(); i++) {
        cin >> s[i];
    }
    return in;
}
ostream &operator<<(ostream &out, const String &s) {
    for (int i = 0; i < s.getSize(); i++) {
        out << s[i];
    }
    return out;
}

int String::operator==(String &op) const {
    if (size != op.getSize())
        return 0;
    for (int i = 0; i < size; i++) {
        if (ch[i] != op[i])
            return 0;
    }
    return 1;
}

int String::operator!=(String &op) const { return !(*this == op); }

int String::operator!() const { return (size == 0); }

int String::operator<(String &op) const {
    if (size < op.size)
        return 1;
    else if (size > op.size)
        return 0;
    else {
        for (int i = 0; i < size; i++) {
            if (ch[i] < op[i])
                return 1;
            else if (ch[i] > op[i])
                return 0;
        }
    }
    return 0;
}
int String::operator>(String &op) const { return !((*this) < op); }

String &String::operator=(const String &s) {
    // cout << "String::operator=(const String &s)" << endl;
    size = s.size;
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = s[i];
    }
    return *this;
}

String &String::operator=(char *init) {
    // cout << "String::operator=(char *init)" << endl;
    size = strlen(init);
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = init[i];
    }
    return *this;
}
String String::operator+(const String &s) {
    int sSize = s.getSize();
    const int newSize = size + sSize + 1;
    // cout << "newSize==" << newSize << endl;
    char *tmp = new char[newSize];
    // strcpy(tmp, ch);
    // strcat(tmp, s.c_str());
    int index = 0;
    for (int i = 0; i < size; i++) {
        tmp[index++] = ch[i];
    }
    for (int i = 0; i < s.getSize(); i++) {
        tmp[index++] = s[i];
    }
    /**
     * @date: 2022-10-12 14:51:19
     * @description:
     * 看来C语言的东西有所遗忘，
     * 连一个字符串数组的基本知识都搞了这么久
     * 这里时len-1
     */
    tmp[newSize - 1] = '\0';
    String Tmp(tmp);
    return Tmp;
}
String String::operator+=(const String &s) {
    *this = *this + s;
    return *this;
}
char &String::operator[](int index) const { return ch[index]; }
int String::getSize() const { return size; }

int String::BF_find(const String &s) const {
    if (s.getSize() > size)
        return -1;
    int slen = s.getSize();
    int i = 0;
    int j = 0;
    while (i < size && j < slen) {
        // if (ch[i + j] == s[j]) {
        //     j++;
        // } else {
        //     j = 0;
        //     i++;
        // }
        if (ch[i] == s[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == slen) {
        return i - j;
    } else {
        return -1;
    }
}

int String::KMP_find(const String &s) {
    if (s.getSize() > size) {
        return false;
    }
    const int slen = s.getSize();
    int *next = new int[slen];
    s.getNext(next);
    int i = 0;
    int j = 0;
    while (i < size && j < slen) {
        if (j == -1 || ch[i] == s[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == slen) {
        return i - j;
    } else {
        return -1;
    }
}

void String::getNext(int *next) const {
    for (int i = 0; i < size; i++) {
        next[i] = 0;
    }
    next[0] = -1;
    int i = 0, j = -1;
    while (i < size - 1) {
        if (j == -1 || ch[i] == ch[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
char *String::c_str() const {
    char *tmp = new char[size + 1];
    for (int i = 0; i < size; i++) {
        tmp[i] = ch[i];
    }
    tmp[size] = '\0';
    return tmp;
}
void String::reverse() {
    if (size == 0) {
        cout << "Empty String!" << endl;
        return;
    }
    int low = 0, high = size - 1;
    while (low < high) {
        swap(ch[low], ch[high]);
        low++;
        high--;
    }
}

void String::getNextVal(int *next) {
    for (int i = 0; i < size; i++) {
        next[i] = 0;
    }
    next[0] = -1;
    int i = 0, j = -1;
    while (i < size - 1) {
        if (j == -1 || ch[i] == ch[j]) {
            i++, j++;
            if (ch[i] == ch[j]) {
                next[i] = next[j];
            } else
                next[i] = j;
        } else {
            j = next[j];
        }
    }
}

#endif