#ifndef WORD_H
#define WORD_H
#include<vector>
#include<string>
#include<iostream>
#include<cctype>

class Word
{
    private:
        std::string m_word;
        int m_count;
        std::vector<int> m_line;

    public:
        Word(std::string word);
        void add_line(int line);
        void add_count(int count);
        void print() const;
        std::string get_word();
        int get_count();
        void print_lines();

};

#endif
