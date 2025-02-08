#include <iostream>
#include <thread>
#include <chrono>

// we might prefer only some namespace attributes
using std::cout;

void printMessage()
{
  // but there's more: we can use it in arbitrary scopes
  using std::endl;
  cout << "Hello from a separate thread!" << endl;
}

void namespaces()
{
  // Using the std namespace
  cout << "Hello, World!" << std::endl;

  // Using the std::thread namespace
  std::thread t(printMessage);

  // Using the std::chrono namespace
  cout << "Waiting for 1 second..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  cout << "Done!" << std::endl;

  // Ensure the thread has finished execution
  t.join();
}

int main()
{
  return 0;
}