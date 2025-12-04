#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>

//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//    //现在就需要三次转置，
//    k %= numsSize;//当k进行numsSize次轮转，实际上就是没有轮转
//    //不需要轮转的前面的元素进行逆置
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//}

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//struct ListNode* FindMid(struct ListNode* head)
//{
//    //快慢指针
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//struct ListNode* reverseList(struct ListNode* head)
//{
//    // if(head==NULL)
//    //     return NULL;
//
//    struct ListNode* cur = head->next;
//    head->next = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = head;
//        head = cur;
//        cur = next;
//    }
//    return head;
//}
//bool isPalindrome(struct ListNode* head)
//{
//    //首先找到中间节点
//    //这里需要注意的是如果是偶数个节点，那么需要指向后一个中间节点
//    struct ListNode* mid = FindMid(head);
//    //拿到中间节点后，进行反转后半部分链表
//    struct ListNode* after = reverseList(mid);
//
//    while (head && after)
//    {
//        if (head->val != after->val)
//            return false;
//        head = head->next;
//        after = after->next;
//    }
//    return true;
//}

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//
//int ListNodeLength(struct ListNode* head)
//{
//    int len = 0;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        cur = cur->next;
//        len++;
//    }
//    return len;
//}
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    //空链表直接就没有交点
//    if (headA == NULL || headB == NULL)
//        return NULL;
//    //求出链表长度差值，相交的地方肯定在除差值外的长度
//    int lenA = ListNodeLength(headA);
//    int lenB = ListNodeLength(headB);
//
//    int more = abs(lenA - lenB);
//
//    //假设A是长的那个
//    struct ListNode* longlist = headA;
//    struct ListNode* shortlist = headB;
//    //如果假设错误，那么交换过来就好了
//    if (lenA < lenB)
//    {
//        longlist = headB;
//        shortlist = headA;
//    }
//    //长的先走差值个，然后保证在同一起跑线上
//    while (more--)
//    {
//        longlist = longlist->next;
//    }
//    //一起走
//    while (longlist && shortlist)
//    {
//        if (longlist == shortlist)
//            return longlist;
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return NULL;
//}

int check(char* directions, int local) {
    char* cur = directions;
    int res = 0;

    if (local == 0)
    {
        // 判断第一个位置情况
        if (cur[local] == 'R' && cur[local + 1] == 'L')
        {
            res += 2;
            cur[local] = 'S';
            cur[local + 1] = 'S';
        }
        if (cur[local] == 'R' && cur[local + 1] == 'S')
        {
            res += 1;
            cur[local] = 'S';
        }
    }
    else if (local > 0 && local < strlen(directions) - 1)
    {
        if (cur[local] == 'R' && cur[local + 1] == 'L')
        {
            res += 2;
            cur[local] = 'S';
            cur[local + 1] = 'S';
        }
        if (cur[local] == 'L' && cur[local - 1] == 'R')
        {
            res += 2;
            cur[local] = 'S';
            cur[local + 1] = 'S';
        }
        if (cur[local] == 'R' && cur[local + 1] == 'S')
        {
            res += 1;
            cur[local] = 'S';
        }
        if (cur[local] == 'L' && cur[local - 1] == 'S')
        {
            res += 1;
            cur[local] = 'S';
        }
    }
    else
    {
        // 判断最后一个位置情况
        if (cur[local] == 'L' && cur[local - 1] == 'R')
        {
            res += 2;
            cur[local] = 'S';
            cur[local - 1] = 'S';
        }
        if (cur[local] == 'L' && cur[local - 1] == 'S')
        {
            res += 1;
            cur[local] = 'S';
        }
    }
    return res;

}
int countCollisions(char* directions) 
{
    int len = strlen(directions);

    int res = 0;

    int i = 0;

    while (i < len) 
    {
        res += check(directions, i);
        i++;
    }
    return res;
}


int main()
{
    char arr[] = "LLRR";
    int res = countCollisions(arr);
    return 0;
}
