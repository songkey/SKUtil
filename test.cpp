#include "binfile.h"
#include <iostream>
#include <string>

using namespace std;

void testBinFile(){
  sk::binFW fw("binFile.dat");
  vector<float> out_vec(10000, 999.);
  fw << "This is a new float vector!!" << out_vec;
  fw.close();

  sk::binFR fr("binFile.dat");
  vector<float> in_vec;
  string in_str;
  fr >> in_str >> in_vec;
  cout << "in str: " << in_str << endl;
  cout << "in vec front: " << in_vec.front() <<
          "in vec back: " << in_vec.back() << endl;
  fr.close(); 
}

int main(int argc, char**argv){
  testBinFile();  
  return 0;
}
