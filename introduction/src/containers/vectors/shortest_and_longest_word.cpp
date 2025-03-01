#include <iostream>
#include <vector>

bool contains(std::vector<std::string> &words, std::string word_to_insert)
{
  // TODO: find out more about these below
  // words.reserve
  // words.insert
  // words.swap
  for (int i = 0; i < words.size(); i++)
  {
    if (words[i] == word_to_insert)
    {
      return true;
    }
  }
  return false;
}

bool insert_if_not_present(std::vector<std::string> &words, std::string word)
{
  if (contains(words, word) == false)
  {
    words.push_back(word);
    return true;
  }
  return false;
}

int main()
{
  std::cout << "Enter your message: ";

  std::string current_word;

  std::string shortest_word = "";
  std::string longest_word = "";
  std::string::size_type shortest_word_length;
  shortest_word_length = UINT32_MAX;

  std::vector<std::string> longest_words;
  std::vector<std::string> shortest_words;
  while (std::cin >> current_word)
  {
    std::string::size_type current_word_length = current_word.length();
    if (current_word_length >= longest_word.length())
    {
      if (current_word_length == longest_word.length())
      {
        insert_if_not_present(longest_words, current_word);
      }
      else
      {
        longest_words.clear();
        longest_words.push_back(current_word);
      }
    }
    if (current_word_length <= shortest_word_length)
    {
      if (current_word_length == shortest_word_length)
      {
        insert_if_not_present(shortest_words, current_word);
      }
      else
      {
        shortest_words.clear();
        shortest_words.push_back(current_word);
      }
      shortest_word_length = current_word_length;
    }
  }

  std::cout << std::endl
            << "Thanks, here are the stats: " << std::endl;
  std::cout << "\tThe shortest word(s) of length: " << shortest_words[0].length() << std::endl;
  for (int i = 0; i < shortest_words.size(); i++)
  {
    std::cout << "\t\t" << shortest_words[i] << std::endl;
  }

  std::cout << "\tThe longest word(s) of length: " << longest_words[0].length() << std::endl;
  for (int i = 0; i < longest_words.size(); i++)
  {
    std::cout << "\t\t" << longest_words[i] << std::endl;
  }
  return 0;
}