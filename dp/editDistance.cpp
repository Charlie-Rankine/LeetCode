#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 2e9));

    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j) {
        if (!i || !j)
          dp[i][j] = max(i, j);
        else if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
      }

    return dp[m][n];
  }
};

/*
Gemini:
1. Define the Subproblems

    Imagine you have smaller substrings of word1 and word2.
    The key is to ask: "What's the minimum edit distance required to convert
substring word1[0...i] into substring word2[0...j]?"

2. Think Recursively

    Base Cases:
        If word1 is empty, we need to insert all characters of word2 (edit
distance = length of word2). If word2 is empty, we need to delete all characters
of word1 (edit distance = length of word1).

    Recursive Cases:
        If the last characters match: The edit distance is the same as
converting the substrings excluding the last characters. If the last characters
don't match: We have three choices: Insert: Insert a matching character into
word1 (1 edit), then compare the rest of the substrings. Delete: Delete the last
character from word1 (1 edit), then compare. Replace: Replace the last character
in word1 (1 edit), then compare.

3. Build the DP Table

    Create a table (matrix) with dimensions (len(word1) + 1) x (len(word2) + 1).
    The table cells dp[i][j] will store the minimum edit distance between
word1[0...i] and word2[0...j]. Fill in the base cases along the edges of the
table.

4. Calculate the Table

    Iterate through the table. For each cell, use the recursive relationship you
defined earlier to calculate its value based on its neighbors.

5. The Result

    The final value at dp[len(word1)][len(word2)] represents the minimum edit
distance to convert the entire word1 to word2.

GPT:
    Define the DP table:
        Create a 2D array dp of size (m+1) x (n+1), where m is the length of
word1, and n is the length of word2. dp[i][j] will represent the minimum number
of operations to convert the first i characters of word1 to the first j
characters of word2.

    Initialize the base cases:
        Set dp[i][0] to i for all i from 0 to m (represents deleting all
characters in word1). Set dp[0][j] to j for all j from 0 to n (represents
inserting all characters from word2).

    Fill in the DP table:
        Iterate over the rows and columns of the DP table, starting from i=1 and
j=1. For each dp[i][j], there are three possible operations: If word1[i-1] is
equal to word2[j-1], no operation is needed, and you can take the value from the
diagonal, dp[i-1][j-1]. Otherwise, take the minimum of the three adjacent cells
(dp[i-1][j], dp[i][j-1], and dp[i-1][j-1]) and add 1 to it.

    Final result:
        The final result will be stored in dp[m][n], which represents the
minimum number of operations to convert the entire word1 to word2.

This approach ensures that each cell in the DP table considers the optimal
solution for the subproblems, and by the end, you get the minimum operations to
transform one word into another.

*/
