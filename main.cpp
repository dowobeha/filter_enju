#include <iostream>
#include <sstream>
#include "PreprocessEnju.hpp"

int main(int argc, char** argv){

  if (argc != 7) {
    std::cerr << "Usage:\t" << argv[0] << " in.enju in.ja maxSentenceLength out.en out.enju out.ja" << std::endl;
    return -1;
  }
  
  const std::string inEnju(argv[1]);
  const std::string inJa(argv[2]);
  const std::string outEn(argv[4]);
  const std::string outEnju(argv[5]);
  const std::string outJa(argv[6]);

  std::istringstream iss(argv[3]);
  int val;
  if (!(iss >> val)) {
    std::cerr << "Invalid value for maxSentenceLength:\t" << argv[3] << ". Please provide a valid number." << std::endl;
    return -2;
  }
  
  const int threshold = val;

  bool success = PreprocessEnju::extractParsedSentence(inEnju, outEn, outEnju, inJa, outJa, threshold);

  if (success) {
    return 0;
  } else {
    return -3;
  }
   
}
