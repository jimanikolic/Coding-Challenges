/*
Challenge #6 - Write a program to model dna replication. Output the conservative, 
semiconservative, and dispersive models. Then recreate the Meselson-Stahl experiment
with lowercase nucleotides representing light isotopes and uppercase representing heavy isotopes.
Runtime - O(1), constant
*/


#include <iostream>
#include <random>
#include <string>

using namespace std;

//for returning two strings from a function
struct StringPair {
    string dupdna;
    string dupdaughterdna;
};

StringPair generateDNA(int size); //generates a double stranded set of dna, two strings length size, complementary
StringPair conservative(string dna, string daughterdna); //duplicates the generated dna conservatively
StringPair semiconservative(string dna, string daughterdna); //duplicates the generated dna semiconservatively
string dispersive(string dna, string daughterdna, unsigned int seed); //duplicates the generated dna dispersively, basically 50/50 mix 
string daughter(string dna); //generates complimentary strand of dna
void printSequence(string dna, string daughterdna); //prints a double stranded dna

int main() {

  int size = 0;
  cout << "How large is your DNA Sequence: ";
  cin >> size;

  StringPair result = generateDNA(size);
  string dna = result.dupdna;
  string daughterdna = result.dupdaughterdna;

  cout << "Generated DNA strand with low mass:" <<endl; //low mass meaning all nucleotides are lowercase - modeling messelson stahl, capitals are high mass
  printSequence(dna, daughterdna);


  result = conservative(dna, daughterdna);
  string dupdna = result.dupdna;
  string dupdaughterdna = result.dupdaughterdna;
  cout << "Conservative Duplicated DNA strands round 1: \n" <<endl;
  printSequence(dna, daughterdna);
  printSequence(dupdaughterdna, dupdna);

  StringPair result1 = conservative(dupdna, dupdaughterdna);
  string dupdna1 = result1.dupdna;
  string dupdaughterdna1 = result1.dupdaughterdna;
  cout << "Conservative Duplicated DNA strands round 2: \n" <<endl;
  printSequence(dna, daughterdna);
  printSequence(dupdaughterdna, dupdna);
  printSequence(dupdna, dupdaughterdna);
  printSequence(dupdaughterdna1, dupdna1);

  result = semiconservative(dna, daughterdna);
  dupdna = result.dupdna;
  dupdaughterdna = result.dupdaughterdna;
  cout << "Semi-Conservative Duplicated DNA strands round 1: \n" <<endl;
  printSequence(dna, dupdna);
  printSequence(daughterdna, dupdaughterdna);

  result1 = semiconservative(dupdna, dupdaughterdna);
  dupdna1 = result1.dupdna;
  dupdaughterdna1 = result1.dupdaughterdna;
  cout << "Semi-Conservative Duplicated DNA strands round 2: \n" <<endl;
  printSequence(dna, dupdna);
  printSequence(daughterdna, dupdaughterdna);
  printSequence(dupdaughterdna, dupdaughterdna1);
  printSequence(dupdna, dupdna1);
  
  unsigned int seed = 11234; //change for randomization in dispersive sequence
  dupdna = dispersive(dna, daughterdna, seed);
  dupdaughterdna = dispersive(daughterdna, dna, seed);
  cout << "Dispersive Duplicated DNA strands round 1: \n" << endl;
  printSequence(dupdna, dupdaughterdna);
  printSequence(dupdna, dupdaughterdna);

  seed = 758; //change for randomization in dispersive sequence
  dupdna1 = dispersive(dna, daughterdna, seed);
  dupdaughterdna1 = dispersive(daughterdna, dna, seed);
  cout << "Dispersive Duplicated DNA strands round 2: \n" << endl;
  printSequence(dupdna, dupdaughterdna);
  printSequence(dupdna1, dupdaughterdna1);
  printSequence(dupdna, dupdaughterdna);
  printSequence(dupdna1, dupdaughterdna1);
}

void printSequence(string dna, string daughterdna) {
  cout << dna << "\n" << daughterdna <<"\n" << endl;
}

StringPair generateDNA(int size) {

  srand(time(nullptr));
  string dna, daughter;
  dna.reserve(size);// Reserve space for the DNA string to avoid reallocations
  
  dna.append("tac"); // Put a start codon at the beginning

  for (int i = 0; i < size-3; i++) {
    int x = rand() % 4;

    if (x == 0) {
      dna.push_back('a');
    }

    else if (x == 1) {
      dna.push_back('t');
    }

    else if (x == 2) {
      dna.push_back('c');
    }

    else if (x == 3) {
        
      dna.push_back('g');
    }
  }

  daughter.reserve(size);

  for(int i = 0; i < size; i++) {
    if (dna[i] == 'a') {
      daughter.push_back('t');
    }
    else if (dna[i] == 't') {
      daughter.push_back('a');
    }
    else if (dna[i] == 'c') {
      daughter.push_back('g');
    }
    else if (dna[i] == 'g') {
      daughter.push_back('c');
    }
  }
  return {dna, daughter};

}

StringPair conservative(string dna, string daughterdna) {
  string dupdna = daughter(dna);
  string dupdaughterdna = daughter(daughterdna);
  return {dupdna, dupdaughterdna};

}

StringPair semiconservative(string dna, string daughterdna) {
  string dupdna = daughter(dna);
  string dupdaughterdna = daughter(daughterdna);
  return {dupdna, dupdaughterdna};

}

string dispersive(string dna, string daughterdna, unsigned int seed) {
    int n = dna.length();
    string oldfragments, newfragments;

    // Seed the random number generator with the provided seed
    srand(seed);

    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) {
            oldfragments.push_back(dna[i]);
            newfragments.push_back('x');
        } else {
            newfragments.push_back(daughterdna[i]);
            oldfragments.push_back('x');
        }
    }

    string newfragments_complementary = daughter(newfragments);

    string combined_dna;
    combined_dna.reserve(n);

    for (int i = 0; i < n; ++i) {
        if (oldfragments[i] == 'x') {
            combined_dna.push_back(newfragments_complementary[i]);
        } else {
            combined_dna.push_back(oldfragments[i]);
        }
    }
    return combined_dna;
}

string daughter(string dna) {
  int n = dna.length();
  string repdna;
  repdna.reserve(n);

  for(int i = 0; i < n; i++) {
    if (dna[i] == 'a' || dna[i] =='A') {
      repdna.push_back('T');
    }
    else if (dna[i] == 't'|| dna[i] =='T') {
      repdna.push_back('A');
    }
    else if (dna[i] == 'c' || dna[i] =='C') {
      repdna.push_back('G');
    }
    else if (dna[i] == 'g' || dna[i] =='G') {
      repdna.push_back('C');
    }
    else if (dna[i] == 'x') {
      repdna.push_back('x');
    }
  }
  return repdna;
}