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

List *reverseList(List *&head)
{
    List *prev = NULL;
    List *curr = head;

    while (curr != NULL)
    {
        List *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

List * middle(List *head)

{
    List *slow = head;
    List *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL )
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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

    // List *linklist = arrytoLL(nums);
    // cout << "Before Reverse : ";
    // printLL(linklist);
    // cout << "After Reverse : "; 
    // List *head1 = reverseList(linklist);
    // printLL(head1);
    List *head = arrytoLL(nums);

    List * mid = middle(head);
    cout<<mid->val<<endl;

}