class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int fiveDollar=0, tenDollar=0, twentyDollar=0;
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                fiveDollar++;
            }
            else if(bills[i] == 10)
            {
                if(fiveDollar > 0)
                {
                    fiveDollar--;
                }
                else
                {
                    return false;
                }
                tenDollar++;
            }
            else if(bills[i] == 20)
            {
                if(tenDollar > 0 && fiveDollar > 0)
                {
                    tenDollar--;
                    fiveDollar--;
                }
                else if(tenDollar == 0 && fiveDollar > 2)
                {
                    fiveDollar=fiveDollar-3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> bills = stringToIntegerVector(line);
        
        bool ret = Solution().lemonadeChange(bills);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
