/*
Challenge #8 - Write a examines two csv files from instagram to determine
who you are following that does not follow you back and vice-versa.Uses a chrome extension
to get csvs of followes, limited to ~500.
Runtime O(1) constant
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> readNames(string filename);

vector<string> findNotInFollowers(const vector<string>& following, const vector<string>& followers);

int main () {
  string followersFile = "followers.csv";
  string followingFile = "following.csv";
  
  vector<string> followers = readNames(followersFile);
  vector<string> following = readNames(followingFile);
  vector<string> notInFollowers = findNotInFollowers(following, followers);
  vector<string> notInFollowing = findNotInFollowers(followers, following);

  cout << "Accounts That Don't Follow You Back" << endl;
  for (const auto& username : notInFollowers) {
        cout << username << endl;
  }

  cout << "Accounts That You Don't Follow Back" << endl;
  for (const auto& username : notInFollowing) {
        cout << username << endl;
  }

   return 0;
}


vector<string> readNames(string filename) {

  vector<string> names;

  ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return names;
    }

    string line;
    while (getline(file,line)) {
      stringstream ss(line);
      string field;
      if (getline(ss, field, ',') && getline(ss, field, ',')) {

        names.push_back(field);
      }

    }

    return names;

}


vector<string> findNotInFollowers(const vector<string>& following, const vector<string>& followers) {
  vector<string> notInFollowers;

    // Iterate through each element in the following vector
    for (const string& username : following) {
        // Check if the current username is not found in the followers vector
        if (find(followers.begin(), followers.end(), username) == followers.end()) {
            // If not found, add it to the notInFollowers vector
            notInFollowers.push_back(username);
        }
    }

    return notInFollowers;
}
