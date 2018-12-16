#include "concordance.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cctype>


Concordance::Concordance(std::string filename)
{
    m_filename = filename;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    std::string sentence;
    int line_count = 1;
    while(std::getline(file, sentence))
    {
        std::istringstream stream(sentence);
        std::string word;
        while(stream >> word)
        {
            int word_index = find_word(word);
            if(word_index != -1)
            {
                m_word_stats[word_index].add_count(1);
                m_word_stats[word_index].add_line(line_count);
            }
            else
            {
                word new_word(word);
                new_word.add_line(line_count);
                m_word_stats.push_ack(new_word);
            }
        }
        line_count += 1;
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
    for(int = 0; i < m_word_stats.size(); i++)
    {
        std::cout << m_word_stats[i] << std::endl; 
    }// print out the concordance
}
