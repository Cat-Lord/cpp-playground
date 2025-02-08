#include <iostream>
#include <vector>

// insert a word into the message counter. Returns true if word is new, false otherwise
bool insert_word(std::vector<std::vector<std::string>> &messages, std::string message)
{
  for (int i = 0; i < messages.size(); i++)
  {
    if (messages[i][0] == message)
    {
      std::cout << "++" << message << std::endl;
      messages[i].push_back(message);
      return true;
    }
  }
  std::vector<std::string> new_word_counter(1, message);
  messages.push_back(new_word_counter);
  std::cout << "+" << message << std::endl;
  return false;
}

// There is an option to use hash maps for this, but since we encounter this
// problem during vectors chapter, we will implement a little inefficient solution
int main()
{
  std::vector<std::vector<std::string>> words_count;

  std::cout << "Enter your message: ";

  std::string current_word;
  while (std::cin >> current_word)
  {
    insert_word(words_count, current_word);
  }

  std::cout << std::endl
            << "Thanks, here are the stats: " << std::endl;
  std::cout << "Found " << words_count.size() << " words" << std::endl;

  for (int i = 0; i < words_count.size(); i++)
  {
    std::cout << "\t" << words_count[i][0] << " " << words_count[i].size() << "x" << std::endl;
  }

  return 0;
}