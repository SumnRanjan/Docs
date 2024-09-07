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

List * sort(List * head){
    vector<int>ans;
    List * temp = head;

    while(temp != NULL){
        ans.push_back(temp->val);
        temp = temp->next;
    }

    sort(ans.begin() , ans.end());
    int i = 0;
    temp = head;
    while(temp){
        temp->val = ans[i];
        temp = temp->next;
        i++;
    }
    return head;
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
    head = sort(head);
    printLL(head);

}