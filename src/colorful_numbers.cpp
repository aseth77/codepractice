#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution 
{
  public:
  int colorful(int A);

};


int Solution::colorful(int A) {
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
  char numString[20];
  std::map<int, bool> colorMap;
  int len = 0;
    
  memset(numString, sizeof(numString), 0);
  snprintf(numString, 20, "%d", A);
  len = strlen(numString);
    
    
  for(unsigned int i = 0; i < len; i++) {
    int mult = 1;
    for (unsigned int j = i; j < len; j++) {
      mult = mult* (numString[j] - '0');      // getting number from letter. only works for ascii
      if(colorMap.find(mult) != colorMap.end())
	return 0;
                
      colorMap[mult] = true;
    }
  }
    
  return 1;
}

int main(int argc, const char** argv) {
 
  //  cout << argc;

  if(argc != 2)
    return -1;
 
  Solution s;
  int colorful = s.colorful(stoi(argv[1]));

  if(colorful)
    cout << argv[1] << " is colorful\n";
  else
    cout << argv[1] << " is not colorful\n";

  return 0;
}
