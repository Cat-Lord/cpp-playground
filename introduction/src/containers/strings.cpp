#include <iostream>
#include <vector>
#include <cctype> // isspace and other utility character functions

std::vector<std::string> split_sentence_into_words(std::string sentence)
{
  std::string::size_type word_start = 0, word_end = 0;
  std::vector<std::string> words;

  while (word_start < sentence.length())
  {
    while (word_start < sentence.length() && isspace(sentence[word_start]))
    {
      word_start++;
    }

    word_end = word_start;
    while (word_end < sentence.length() && isspace(sentence[word_end]) == false)
    {
      word_end++;
    }
    std::string word = sentence.substr(word_start, word_end - word_start);
    words.push_back(word);
    word_start = word_end;
  }

  return words;
}

int main()
{
  std::cout << "Strings are a special type of containers similar to vectors.\n";
  std::string sentence = "Cats are love!";

  std::cout << "Assume a sample sentence: '" << sentence << "'...\n";
  std::cout << "They support indexing as vectors. This is the fourth character: '" << sentence[3] << "'\n";
  std::cout << "This is the last character: '" << sentence[sentence.size() - 1] << "'\n";

  std::vector<std::string> words = split_sentence_into_words(sentence);
  std::cout << "Splitting the sentence into words using indices we get " << words.size() << " word(s).\n";
  std::cout << "Normally, using std::cin we'd only get words and not a complete line, just as with the function we've just seen in action.\n";
  std::cout << "Therefore, we can use the 'getline' to obtain the whole line. Let's see it - type your sentence: ";

  std::string input_line;
  // reading the whole input. Of course, we could cheat by using a while loop with a traditional std::cin
  std::getline(std::cin, input_line);
  std::cout << "Your input line has " << split_sentence_into_words(input_line).size() << " words.\n";
  return 0;
}