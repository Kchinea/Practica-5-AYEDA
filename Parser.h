#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
 public:
  Parser(int argc, char** argv);
  ~Parser();
  void Parse();
  std::string GetTypeOrdenation() const;
  std::string GetFormIntroduction() const;
  std::string GetFileName() const;
  int GetSize() const;
  bool GetTrace() const;
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