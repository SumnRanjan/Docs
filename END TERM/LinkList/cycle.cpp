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

bool cycle(List *head)
{
    List *slow = head;
    List *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            return true;
        }
    }
    return false;
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

    
   bool ans = cycle(head);
   if(ans){
    cout<<"true"<<endl;
   }
   else{
    cout<<"false"<<endl;
   }

}