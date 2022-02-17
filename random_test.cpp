#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>

namespace fs = std::filesystem;

const std::string dir_name = "random_test"; // Directory for output file
const std::string code_1 = "sample_1.cpp"; // Path to your C++ code
const std::string code_2 = "sample_2.cpp"; // Path to your C++ code

void make_testfile(int i, int j, std::string testfile) {
  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // File which has same name will be overwritten
  /////////////////////////////////////////////////
  std::ofstream output;
  output.open("./" + dir_name + "/" + testfile, std::ios::out);

  // Write your custom input here
  output << i << " " << j << std::endl;

  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  /////////////////////////////////////////////////
  output.close();
}

void run_code(std::string testfile, std::string code, std::string suffix) {
  // Common part of command to run codes
  std::string compile_command_base = "g++ -o test.out --std c++17 "; // Edit depending on your environment
  std::string run_command_base =
    "./test.out < ./" + dir_name + "/" + testfile +
    " > ./" + dir_name + "/" + testfile.substr(0, testfile.size()-4);

  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // Compile and run code
  /////////////////////////////////////////////////
  std::string compile_command = compile_command_base + code;
  char* c_compile_command = new char[compile_command.size() + 1];
  std::strcpy(c_compile_command, compile_command.c_str());

  std::string run_command = run_command_base + suffix + ".txt";
  char* c_run_command = new char[run_command.size() + 1];
  std::strcpy(c_run_command, run_command.c_str());

  system(c_compile_command);
  system(c_run_command);

  delete[] c_compile_command;
  delete[] c_run_command;
}

void run_test(std::string testfile) {
  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // Check if shell is available
  /////////////////////////////////////////////////
  if(system(nullptr) == 0) {
    std::cout << "ERROR: Shell is not available." << std::endl;
    return;
  }

  // Compile and run codes
  std::string suffix_1 = "__1";
  std::string suffix_2 = "__2";
  run_code(testfile, code_1, suffix_1);
  run_code(testfile, code_2, suffix_2);

  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // Check if output is same
  /////////////////////////////////////////////////
  std::string diff_command =
    "diff -q ./" +
    dir_name + "/" + testfile.substr(0, testfile.size()-4) + suffix_1 + ".txt ./" +
    dir_name + "/" + testfile.substr(0, testfile.size()-4) + suffix_2 + ".txt";
  char* c_diff_command = new char[diff_command.size() + 1];
  std::strcpy(c_diff_command, diff_command.c_str());
  system(c_diff_command);
  delete[] c_diff_command;
}

int main() {
  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // Make directory for test file
  /////////////////////////////////////////////////
  if(!fs::exists(dir_name)) {
    fs::create_directory(dir_name);
  } else if(!fs::is_directory(dir_name)) {
    std::cout << "ERROR: File '" +  dir_name + "' exists." << std::endl;
    std::cout << "Please remove or rename it before run this code." << std::endl;
    return -1;
  }

  // Run making and running test in two code.
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      std::string testfile = "input_" + std::to_string(i) + "_" + std::to_string(j) + ".txt";

      make_testfile(i, j, testfile);
      run_test(testfile);
    }
  }

  /////////////////////////////////////////////////
  // DO NOT EDIT HERE IF YOU HAVE NO REASON.
  // Clean up
  /////////////////////////////////////////////////
  system("rm ./test.out");

  return 0;
}
