#include<string>

class Solution
{
public:
    
    int uniqueMorseRepresentations(vector<string> &words)
    {
        set<string> stringSet;
        for (int i = 0; i < words.size(); i++)
        {
            string output = "";
            for(int j = 0; j < words[i].size(); j++){
                switch (words[i][j])
                {
                case 'a':
                    output += ".-";
                    break;
                case 'b':
                    output += "-...";
                    break;
                case 'c':
                    output += "-.-.";
                    break;
                case 'd':
                    output += "-..";
                    break;
                case 'e':
                    output += ".";
                    break;
                case 'f':
                    output += "..-.";
                    break;
                case 'g':
                    output += "--.";
                    break;
                case 'h':
                    output += "....";
                    break;
                case 'i':
                    output += "..";
                    break;
                case 'j':
                    output += ".---";
                    break;
                case 'k':
                    output += "-.-";
                    break;
                case 'l':
                    output += ".-..";
                    break;
                case 'm':
                    output += "--";
                    break;
                case 'n':
                    output += "-.";
                    break;
                case 'o':
                    output += "---";
                    break;
                case 'p':
                    output += ".--.";
                    break;
                case 'q':
                    output += "--.-";
                    break;
                case 'r':
                    output += ".-.";
                    break;
                case 's':
                    output += "...";
                    break;
                case 't':
                    output += "-";
                    break;
                case 'u':
                    output += "..-";
                    break;
                case 'v':
                    output += "...-";
                    break;
                case 'w':
                    output += ".--";
                    break;
                case 'x':
                    output += "-..-";
                    break;
                case 'y':
                    output += "-.--";
                    break;
                case 'z':
                    output += "--..";
                    break;
                DEFAULT:
                    output += "";
                }
                //cout << output << endl;
            }
            stringSet.insert(output);
        }

        return stringSet.size();
    }
};