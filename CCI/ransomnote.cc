// A ransom note can be formed by cutting words out of a magazine to form a new
// sentence. How would you figure out if a ransom note (represented as a string)
// can be formed from a given magazine (string)?

/*
  BREAKING DOWN THE PROBLEM:
  We're going to use a technique called Simplify and Generalize, where we change
  a constraint such as the data type of size of data. Then we solve this
  simplified version of the problem. The point is to generalize the problem.

  Words 
  What if we changed the problem to cut out chars instead of words from the mag?
  Then we would create an array of size 26 (Assuming all characters used in the
  note are alphabetic, and case insensitive), where the index corresponds to the
  letter (0 is 'a', 1 is 'b', etc). The value of the element will be the number
  of times that character appears in the ransom note. Then, we can just iterate
  through the chars in the magazine, and see if we have all the chars from the
  array.

  Now that we know how to do a simpler problem, we return to the word problem.
  We can do much the same thing, except that instead of an array of size 26, we
  need a different data structure (there are an estimated million+ words in the
  English language alone). We can create a hash table, where the keys are
  lowercase versions of the words, and they map to frequency values. Since the
  same word will always produce the same hash, this is comparable to using
  array indeces to represent chars.

  SOME CONSIDERATIONS:
  Once we have all the words from the ransom note represented and counted in the
  hash table, we need to check if there are enough instances of each in the mag.

  There are several ways of going about this; let's consider some:

  1. We could iterate through the map of words. With each word, we iterate
    through the magazine, stopping only when the frequency of that word is
    met. If we reach the end of the magazine, we know that there are not enough
    occurances of that word in the magazine; thus, we can exit early out of
    the entire function, returning false.

    The complexity of this approach is:
    O(n*m)
    But there are chances to exit early:
    - Exit the WHOLE thing whenever the inner loop reaches the end
    - Exit an inner loop whenever all the counts of a word are found
    This function returns early if a ransom note is not possible.

  2. We could iterate through the words in the magazine, checking each word
    by iterating through the hash map. If a word appears, we deduct the
    frequency count. If a frequency hits 0, we can delete that key-value pair
    from the map. When the map becomes empty, we return from the function.

    The complexity of this approach is:
    O(m*n)
    This function returns early once the entire ransom note is matched.
    
  The better approach is number 1.

  CLARIFYING QUESTIONS TO ASK:
  Case sensitive or insenstive?
  Locale alphabetic chars only?
  Numbers too?
  Is there a particular range in size of the note/mag?
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <ctype.h>
#include <boost/algorithm/string/predicate.hpp>


bool can_form(std::string ransom, std::string mag) {
  /*
    Checks to see if all the words in ransom can be formed by cutting out words
    from mag. Case insensitive. If there is more than one instance of a word,
    there must be at least that many instances of the word in mag. Returns true
    if it is possible; false otherwise.
  */
  
  std::unordered_map<std::string,int> ranmap; // words --> frequencies

  // Create map using ransom words as keys, and their occurances as values
  std::string word = "";
  for (int i=0; i<ransom.length(); i++) {
    if (isalpha(ransom[i])) {
      // letter found
      word += ransom[i];
    } else if (word.length() > 0) {
      // word found
      
      std::unordered_map<std::string,int>::const_iterator exists =
	ranmap.find(word);
      if (exists == ranmap.end()) {
	// new word
	ranmap[word] = 1;
      } else {
	// preexisting 
	ranmap[word] += 1;
      }

      // clear word
      word = ""; 

    } else {
      // char not alphabetic, but we have no word forming, so 
      // it must be a punctuation mark or something (skip it).
      continue; 
    }
  }


  // Match ranmap words to mag words
  for (auto kv : ranmap) {
    std::cout << kv.first << ": " << kv.second << std::endl;
    int occ = kv.second;

    word = "";
    for (int i=0; i<mag.length(); i++) {
      if (isalpha(mag[i])) {
	// letter found
	word += mag[i];
      } else if (word.length() > 0) {
	// word found
	
	// case-insensitive str compare
	if (boost::iequals(word, kv.first)) {
	  std::cout << "found___" << kv.first << "___" << word << std::endl;
	  occ--;
	}

	// clear word
	word = "";

      } else {
	// char not alphabetic, but we have no word forming, so 
	// it must be a punctuation mark or something (skip it).
	continue; 
      }
      
      if (occ == 0) {
	// we've found all the necessary occurances of this word in the mag.
	// next word.
	std::cout << "found all" << std::endl;
	break;
      }
    }

    if (occ != 0) {
      // all occurances of this word were NOT found in the mag
      std::cout << " ** FALSE ** " << std::endl;
      return false;
    }
  }

  // all occurances of this word WERE found in the mag
  std::cout << " ** TRUE ** " << std::endl;
  return true;
}

int main() {
  can_form("Some hash, or the keys to the operation.",

	   "In computing, a hash table (also hash map) is a data structure used"
	   "to implement an associative array, a structure that can map keys to"
	   "values. A hash table uses a hash function to compute an index into "
	   "an array of buckets or slots, from which the correct value can be f"
	   "ound."
	   "Ideally, the hash function will assign each key to a unique bucket,"
	   "but this situation is rarely achievable in practice (usually some k"
	   "eys will hash to the same bucket). Instead, most hash table designs"
	   "assume that hash collisions—different keys that are assigned by the"
	   "hash function to the same bucket—will occur and must be accommodate"
	   "d in some way."
	   "In a well-dimensioned hash table, the average cost (number of instr"
	   "uctions) for each lookup is independent of the number of elements s"
	   "tored in the table. Many hash table designs also allow arbitrary in"
	   "sertions and deletions of key-value pairs, at (amortized[2]) consta"
	   "nt average cost per operation.[3][4]"
	   );

  can_form("Some hash, or the keys to the operation. Otherwise you will pay.",

	   "In computing, a hash table (also hash map) is a data structure used"
	   "to implement an associative array, a structure that can map keys to"
	   "values. A hash table uses a hash function to compute an index into "
	   "an array of buckets or slots, from which the correct value can be f"
	   "ound."
	   "Ideally, the hash function will assign each key to a unique bucket,"
	   "but this situation is rarely achievable in practice (usually some k"
	   "eys will hash to the same bucket). Instead, most hash table designs"
	   "assume that hash collisions—different keys that are assigned by the"
	   "hash function to the same bucket—will occur and must be accommodate"
	   "d in some way."
	   "In a well-dimensioned hash table, the average cost (number of instr"
	   "uctions) for each lookup is independent of the number of elements s"
	   "tored in the table. Many hash table designs also allow arbitrary in"
	   "sertions and deletions of key-value pairs, at (amortized[2]) consta"
	   "nt average cost per operation.[3][4]"
	   );

  can_form("Hash hash HASH! Ideally...in buckets.",

	   "In computing, a hash table (also hash map) is a data structure used"
	   "to implement an associative array, a structure that can map keys to"
	   "values. A hash table uses a hash function to compute an index into "
	   "an array of buckets or slots, from which the correct value can be f"
	   "ound."
	   "Ideally, the hash function will assign each key to a unique bucket,"
	   "but this situation is rarely achievable in practice (usually some k"
	   "eys will hash to the same bucket). Instead, most hash table designs"
	   "assume that hash collisions—different keys that are assigned by the"
	   "hash function to the same bucket—will occur and must be accommodate"
	   "d in some way."
	   "In a well-dimensioned hash table, the average cost (number of instr"
	   "uctions) for each lookup is independent of the number of elements s"
	   "tored in the table. Many hash table designs also allow arbitrary in"
	   "sertions and deletions of key-value pairs, at (amortized[2]) consta"
	   "nt average cost per operation.[3][4]"	   
	   );  
  return 0;
}
