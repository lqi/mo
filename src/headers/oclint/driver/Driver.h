#ifndef OCLINT_DRIVER_DRIVER_H
#define OCLINT_DRIVER_DRIVER_H

#include <dlfcn.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ClangInstance;
class Reporter;
class Benchmark;

class Driver {
public:
  int main(int argc, char* argv[]);

private:
  Benchmark *_benchmark;
  string _executablePath;
  vector<string> _compilerArguments;

private:
  int dynamicLoadRules(string ruleDirPath);
  int loadRulesFromDefaultRulePath();
  int loadRulesFromCustomRulePaths();
  void pushClangHeadersPath();
  int consumeArgRulesPath();
  void consumeOptArgument(string argKey, string argValue);
  void consumeListArgument(string argKey, vector<string> argValues);
  void consumeOptArguments();
  void consumeListArguments();
  void consumeRuleConfigurations();

  void getCompilerArguments();
  Reporter* reporter();
  int reportSmells(ClangInstance& instance, ostream& out);
  int executeFile(int argc, char** argv, ostream& out);
  int execute(ostream& out);
  ostream* outStream();
  void disposeOutStream(ostream* out);
  void dumpBenchmarks();
};

#endif

