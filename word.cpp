#include<iostream>
#include"word.h"

Word::Word(std::string word)
{
    m_word = word;
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

std::string Word::get_line()
{
    std::string lines;
    for(int i = 0; i < m_line.size(); i++)
    {
        lines += (m_line[i] + ", ");
    }
    return lines;
}
void Word::add_count(int count)
{
    m_count++;
}

void Word::add_line(int line)
{
    m_line.push_back(line);
}

void Word::print() const
{
    std::cout << m_word << ":" << m_count << ":";
    for(int i = 0; i < m_line.size(); i++)
    {
        std::count << m_line[i];
        if(i < (m_line.size() - 1))
        {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
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
