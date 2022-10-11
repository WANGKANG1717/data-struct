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

#include <ostream>
#include <string.h>
using namespace std;
class String {
  private:
    char *ch;
    int size;

  public:
    String();
    String(const char *init);
    String(const String &s);
    ~String();
    friend istream &operator>>(istream &in, const String &s);
    friend ostream &operator<<(ostream &out, const String &s);
    // istream &operator>>(istream &in);
    // ostream &operator<<(ostream &out);
    int operator==(String &op) const;
    int operator!=(String &op) const;
    int operator!() const;
    int operator<(String &op) const;
    int operator>(String &op) const;
    String &operator=(String &s);
    String &operator=(char *ch);
    String &operator+=(String &s);
    char &operator[](int index) const;
    int BF_find(const String &s) const;
    int KMP_find(const String &s);
    void getNext(int *next) const;
    int getSize() const;
};
String::String() { size = 0; }

String::String(const char *init) {
    size = strlen(init);
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = init[i];
    }
}

String::String(const String &s) {
    size = s.size;
    ch = new char[size];
    for (int i = 0; i < size; i++) {
        ch[i] = s[i];
    }
}

String::~String() {
    if (ch)
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

int String::operator!() const { return !(size == 0); }

int String::operator<(String &op) const {
    if (size < op.size)
        return 1;
    else if (size > op.size)
        return 0;
    else {
        for (int i = 0; i < size; i++) {
            if (ch[i] < op[i])
                return 1;
        }
    }
    return 0;
}
int String::operator>(String &op) const { return !((*this) < op); }

String &String::operator=(String &s) {
    String p(s);
    return p;
}

String &String::operator=(char *ch) {
    String p(ch);
    return p;
}

String &String::operator+=(String &s) { size += s.getSize(); }
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
        return i;
    } else {
        return -1;
    }
}

int String::KMP_find(const String &s) {
    if (s.getSize() > size) {
        return false;
    }
    int slen = s.getSize();
    int next[slen];
    s.getNext(next);
    int i = 0;
    int j = 0;
    while (i < size && j < slen) {
        if (ch[i] == s[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == slen) {
        return i;
    } else {
        return -1;
    }
}

void String::getNext(int *next) const {
    for (int i = 0; i < size; i++) {
        next[i] = 0;
    }
    int i = 0, j = 0;
    while (i < size) {
        if (j == 0 || ch[i] == ch[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

#endif