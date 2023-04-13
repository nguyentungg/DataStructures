//---------------------------------
// General Informations
//---------------------------------
// - LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.
// - Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.
// - Reversal of elements

#include <Stack>

std::stack<int> s, so;

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Push
s.push(value);

// Emplace
s.emplace (value);

// Size
unsigned int size = s.size();

// Pop
s.pop();

// Top
int top = s.top();

// Iterate
while (!s.empty())
{
  std::cout << s.top() << '\n';
}

// Is Empty
s.empty();

//Swap contents
s.swap(so);

// Exchange contents of stacks
std::stack<int> foo,bar;
swap(foo,bar);
