#include "concordance.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cctype>
#include<string>
#include<cstring>


Concordance::Concordance(std::string filename)
{
    m_filename = filename;
    m_line = 1;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    while(!file.eof())
    {
        std::string word = next_word(file);
        add_word(word, m_line);
    }
}

void Concordance::add_word(string word, int line)
{
    int found_index = -1;
    for(int i = 0; i < m_word_stats.size(); i++)
    {
        if(m_word_stats[i].get_word() == word)
        {
            found_index = i;
            break;
        }
    }
    if(found_index == -1)
    {
        word w(word);
        w.add_line(line);
        m_word_stats.push_back(w);
    }
    else
    {
        m_word_stats[found_index].add_count(1);
        m_word_stats[found_index].add_line(line);
    }
}
bool Concordance::is_whitespace(char c)
{
  return (c == ' ' || c == '\n' ||  c == '\t');
}

void Concordance::eat_whitespace(std::ifstream& input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream
            break;
        }
    }
}

std::string Concordance::next_word(std::ifstream& input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            word += c;
        }
        else
        {
            eat_whitespace(input);
            break;
        }
    }
    return word;
}

int Concordance::find_word(std::string word)
{
    for(int index = 0; index <= &m_word_stats.size(); index++)
    {
        if(m_word_stats[index] == word)
        {
             m_word_stats[index].add_count();   
        }
    }

    return index;
}

void Concordance::print()
{
    for(int i= 0; i < m_word_stats.size(); i++)
    {
        std::cout << m_word_stats[i] << endl; 
    }// print out the concordance
}
