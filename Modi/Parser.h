#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <stdexcept>
#include <iostream>

class Parser {
 public:
  Parser(int argc, char** argv);
  void Parse();
  std::string GetTypeOrdenation() const { return typeOrdenation_; }
  std::string GetFormIntroduction() const { return formIntroduction_; }
  std::string GetFileName() const { return fileName_; }
  int GetSize() const { return size_; }
  bool GetTrace() const { return trace_; }
  int GetArgc() const;
  char** GetArgv() const;
  void PrintHelp() const;
  void ParseArgs();
 private:
  int argc_;
  char** argv_;
  std::string typeOrdenation_; 
  std::string formIntroduction_; 
  std::string fileName_; 
  int size_;
  bool trace_;
};

#endif