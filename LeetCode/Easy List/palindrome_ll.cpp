#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(int* head) {
        //ListNode* p = head;
        int count = 0;
        std::vector< int > arr;
        
        // while(p->next){
        //     p = p->next;
        //     arr.push_back(p->val);
        //     count++;   
        // }
        
        for(int i=0,j=1; i<j; i++,j--){
            if(head[i] != head[j]){
                return false;
            }else
                continue;
        }
        
        return true;
    }
};
int main(){
    Solution s;
    int A[2] = {1,2};
    std::cout<<s.isPalindrome(A);
    return 0;
}