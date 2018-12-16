#include<iostream>
#include"word.h"

Word::Word(std::string word)
{
    std::string lower_case_word = "";
    for(int i = 0; i < word.size(); i++)
    {
        lower_case_word += tolower(word[i]);
    }
    m_word = lower_case_word;
    m_count = 1;
}

std::string Word::get_word()
{
    return m_word;
}

int Word::get_count()
{
    return m_count;
}

void Word::add_count(int count)
{
    m_count++;
}

void Word::add_line(int line)
{
    m_line.push_back(line);
}

void Word::print_lines()
{
    for(int i = 0; i < m_line.size(); i++)
    {
        std::cout << m_line[i];
        if(i < m_line.size() -1)
        {
            std::cout << ", ";
        }
    } 
}
