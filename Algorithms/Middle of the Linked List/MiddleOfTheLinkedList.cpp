/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *middle = head, *traverse = head;
        int count = 0;
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
            count++;
        }
        
        if(count%2 == 0)
        {
            count = count/2;
        }
        else
        {
            count = count/2 + 1;
        }
        
        while(count > 0)
        {
            middle = middle->next;
            count--;
        }
        return middle;
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) 
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) 
    {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) 
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) 
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) 
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) 
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) 
{
    if (node == nullptr) 
    {
        return "[]";
    }

    string result;
    while (node) 
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().middleNode(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
