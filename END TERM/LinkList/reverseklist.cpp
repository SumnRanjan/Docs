#include <bits/stdc++.h>
using namespace std;

class List
{
public:
    int val;
    List *next;

    List(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

List *arrytoLL(vector<int> &nums)
{
    if (nums.empty())
        return NULL;

    List *head = new List(nums[0]);
    List *curr = head;

    for (int i = 1; i < nums.size(); i++)
    {
        curr->next = new List(nums[i]);
        curr = curr->next;
    }
    return head;
}

int count(List *head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

List * remove(List* head){
    List* curr = head;
    stack<List*>st;

    while(curr != NULL){
        while(!st.empty() && st.top()->val < curr->val){
            st.pop();
        }
        st.push(curr);
        curr = curr->next;
    }

    List * nxt = nullptr;
    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        curr->next = nxt;
        nxt = curr;
    }
    return curr;
}

void printLL(List *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }


    List *head = arrytoLL(nums);
    head = remove(head);
    printLL(head);

}