/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr && curr->next) {

            bool isMax = curr->val > prev->val &&
                         curr->val > curr->next->val;

            bool isMin = curr->val < prev->val &&
                         curr->val < curr->next->val;

            if (isMax || isMin) {

                if (first == -1) {
                    first = index;
                } else {
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        return {minDist, last - first};
    }
};