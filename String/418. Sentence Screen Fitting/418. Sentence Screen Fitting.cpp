
class Solution
{
public:
    int wordsTyping(vector<string> &sentence, int rows, int cols)
    {
        string s;
        for (auto str : sentence)
        {
            if (str.size() > cols)
                return 0;
            s += str + " ";
        }

        int i = 0;
        int len = s.size();

        for (int currRow = 0; currRow < rows; currRow++)
        {
            i += cols;
            while (s[i % len] != ' ')
                i--;
            i++;
        }
        return i / len;
    }
};

// ["a", "bcd", "e"], rows = 3, cols = 6
// a bcd e
//      6
// len = 7
// i = 6
// currRow = 0