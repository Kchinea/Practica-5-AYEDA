#include "Parser.h"

Parser::Parser(int argc, char** argv){
  this->argc_ = argc;
  this->argv_ = argv;
}

void Parser::ParseArgs() {
  for (int i = 1; i < argc_; ++i) {
    std::string arg = argv_[i];
    if (arg == "-size") {
      if (i + 1 < argc_) {
        std::string sizeValue = argv_[++i];
        this->size_ = std::stoi(sizeValue);
        std::cout << "Size: " << sizeValue << std::endl;
        // Process sizeValue
      } else {
        throw std::invalid_argument("Missing value for -size");
      }
    } else if (arg == "-ord") {
      if (i + 1 < argc_) {
        std::string ordValue = argv_[++i];
        this->typeOrdenation_ = ordValue;
        std::cout << "Ord: " << ordValue << std::endl;
        // Process ordValue
      } else {
        throw std::invalid_argument("Missing value for -ord");
      }
    } else if (arg == "-init") {
      if (i + 1 < argc_) {
        std::string initValue = argv_[++i];
        this->formIntroduction_ = initValue;
        if(initValue == "file") this->fileName_ = argv_[++i];
        std::cout << "Init: " << initValue << std::endl;
      } else {
        throw std::invalid_argument("Missing value for -init");
      }
    } else if (arg == "-trace") {
      this->trace_ = true;
      std::cout << "Trace" << std::endl;
    } else {
      throw std::invalid_argument("Unknown argument: " + arg);
    }
  }
}