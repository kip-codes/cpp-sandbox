//
// scrabble.cpp
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef map<char, int> LetterMap; //lettermap
typedef map<string, int> WordMap; //wordmap
static const int TWO = 2;
static const int THR = 3;
static const int FOUR = 4;
static const int FIVE = 5;
static const int SIX = 6;
static const int SEV = 7;
static const int EIGHT = 8;
static const int TEN = 10;
static const int TS = 26;
static const int lcA = 97;
static const int npos = -1;


void populateChar(LetterMap& letterMap)
{
  int letterValues[TS] = {1, THR, THR, TWO, 1, FOUR, TWO, FOUR, TWO, EIGHT
    , FIVE, 1, THR, 1, 1, THR, TEN, 1, 1, 1, 1, FOUR, FOUR, EIGHT, FOUR, TEN};

  for(int i = 0, a = lcA; i < TS; i++, a++)
    letterMap.insert(pair<char, int> ((char)a, letterValues[i]));

}//insert()


//FUNCTIONS NEEDED
int getScore(const LetterMap& lmap, const string& word);
void populateLegal(const LetterMap& lmap, WordMap& wordMap, const char* file)
{
  string word;
  ifstream inf(file);   

  while(inf >> word)
  {
    int flagged = 0;
    
    for(string::iterator itr = word.begin(); itr != word.end(); itr++)
    {
      if((*itr) < 'a' || (*itr) > 'z')
      {
        flagged = 1;
        break;
      }//if
    }//for

    if(!flagged)
      wordMap.insert(pair<string, int>(word, getScore(lmap, word)));
  }//while
}//populate()


int getScore(const LetterMap& lmap, const string& word)
{
  int score = 0;

  for(string::const_iterator itr = word.begin(); itr != word.end(); itr++)
    score += lmap.find(*itr)->second;

  return score;
}//getScore()


//FUNCTIONS NEEDED:
void printAll(const LetterMap& lmap, const set<string>& sR, const string& word);
void printAllTwo(const LetterMap& lmap, const set<string>& sR,
                 const string& word, int hv);
void unscrambleSpace(const LetterMap& lmap, const WordMap& wmap,
                     string& word,  int i, int& hv, set<string>& sR);
void unscramble(const LetterMap& lmap, const WordMap& wmap, string& word,
                string& sWord, set<string>& sResult, int& hv)
{
  string pWord;
  sort(word.begin(), word.end());
     
  while(next_permutation(word.begin(), word.end()))
    for(int i = 0; i < (int)word.length(); i++)
    {
      pWord = word.substr(0, i + 1);
      WordMap::const_iterator pos = wmap.find(pWord);
      
      if(pos != wmap.end()) //if found legal word 
      { 
         int value = pos->second;
  
         if(value > hv)
         {
           sResult.clear();
           hv = value;
         }//if
         
         if(value >= hv)
           sResult.insert(pWord);
      }//if
    }//for
     
    if (hv)
      printAll(lmap, sResult, sWord);
    else //else
      cout << right << " 0 " << sWord << ": No words found.\n";
}//unscrabble

void printAll(const LetterMap& lmap, const set<string>& sR, const string& word)
{
  if (!sR.empty())
  {
    set<string>::iterator itr = sR.begin();
    cout << right << setw(2) << getScore(lmap, *itr) << " " << word << ":";

    for(; itr != sR.end(); itr++)
      cout << " " << *itr;

    cout << endl;
  }//while

}//printAll()


//void printNone(const string word)
//{
  //cout << right << " 0 " << word << ": No words found.\n";

//}//printNone() 



string substitute(string& word, int i, char& letter)
{
  char n = (char) i;
  replace(word.begin(), word.end(), ' ', n);
 
  letter = n;
  return word;  
}//substitute


//int compareGetScore(const string pWord, const LetterMap& lmap
//  , const WordMap& wmap, const LetterMap& letterFreq
//  ,  WordMap::const_iterator pos)
int compareGetScore(const LetterMap& lmap, const WordMap& wmap, char l,
                    WordMap::const_iterator pos)
{
//  LetterMap legalFreq = getFreq(pWord);
 
  if(l != '.')
      return pos->second - lmap.find(l)->second;  

  return pos->second;

}//compareGetScore()


void printAllTwo(const LetterMap& lmap, const set<string>& sR,
                 const string& word, int hv)
{
  if (!sR.empty())
  {
    set<string>::iterator itr = sR.begin();
    cout << right << setw(2) << hv << " " << word << ":";

    for(; itr != sR.end(); itr++)
      cout << " " << *itr;
    
    cout << endl;
  }//while

}//printAll()



void unscrambleSpace(const LetterMap& lmap, const WordMap& wmap, string& word,
                     int i, int& hv, set<string>& sR)
{
  char letter = '.';
  string sWord = word, tWord = substitute(sWord, i, letter), pWord;
  sort(tWord.begin(), tWord.end());
    
  while(next_permutation(tWord.begin(), tWord.end()))
    for(int i = 0; i < (int)tWord.length(); i++)
    {
      pWord = tWord.substr(0, i + 1);
      WordMap::const_iterator pos = wmap.find(pWord);
      
      if(pos != wmap.end()) //if found legal word 
      {
        int value = compareGetScore(lmap, wmap, letter, pos);
         
        if(value > hv)
        {
          sR.clear();
          hv = value;
        }//if
              
        if(value >= hv)
          sR.insert(pWord);
      }//if
    }//for
}//unscrambleSpace()



int main(int argc, char** argv)
{
  LetterMap letterMap;
  WordMap wordMap;
  populateChar(letterMap);
  populateLegal(letterMap, wordMap, "words.txt");

  string word, sWord, pWord;
  ifstream inf(*(argv + 1));
  set<string> sResult;

  while(getline(inf, word))
  {
    int hv = 0; sWord = word;
    
    if (word.find(' ') != string::npos) // IS SPACE
    {
      for(int i = lcA; i < lcA + TS ; i++)
        unscrambleSpace(letterMap, wordMap, word, i, hv, sResult);

      if (hv)
        printAllTwo(letterMap, sResult, sWord, hv);
      else //else
        cout << right << " 0 " << sWord << ": No words found.\n";

    }//if
    else //else
      unscramble(letterMap, wordMap, word, sWord, sResult, hv);
  }//while
} //main.cpp
