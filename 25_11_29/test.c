#define _CRT_SECURE_NO_WARNINGS 1

////203. 移除链表元素
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    if (head == NULL)
//        return NULL;
//
//    ListNode* prev = head;
//
//    while (prev->val == val)
//    {
//        prev = prev->next;
//        if (prev == NULL)
//            return NULL;
//    }
//    head = prev;
//    ListNode* cur = NULL;
//    if (prev)
//        cur = prev->next;
//    while (cur != NULL) {
//        if (cur->val == val) {
//            prev->next = cur->next;
//            free(cur);
//            cur = prev->next;
//        }
//        else {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//
//    return head;
//}

////206. 反转链表
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//        return NULL;
//
//    ListNode* cur = head->next;
//    head->next = NULL;
//    while (cur)
//    {
//        ListNode* next = cur->next;
//        cur->next = head;
//        head = cur;
//        cur = next;
//    }
//    return head;
//}

////876. 链表的中间结点
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head)
//{
//    ListNode* fast = head;
//    ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

////21. 合并两个有序链表
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     struct ListNode *next;
// * };
// */
//typedef struct ListNode ListNode;
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    ListNode* l1 = list1;
//    ListNode* l2 = list2;
//    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//    head->next = NULL;
//    ListNode* tail = head;
//    while (l1 && l2)
//    {
//        if (l1->val < l2->val)
//        {
//            ListNode* next = l1->next;
//            tail->next = l1;
//            tail = tail->next;
//            l1 = l1->next;
//        }
//        else
//        {
//            ListNode* next = l2->next;
//            tail->next = l2;
//            tail = tail->next;
//            l2 = l2->next;
//        }
//    }
//    if (l1)
//    {
//        tail->next = l1;
//    }
//    if (l2)
//    {
//        tail->next = l2;
//    }
//    ListNode* ret = head->next;
//    free(head);
//    head == NULL;
//    return ret;
//}

////27. 移除元素
//int removeElement(int* nums, int numsSize, int val)
//{
//    int fast = 0;
//    int slow = 0;
//    while (fast < numsSize)
//    {
//        if (nums[fast] != val)
//        {
//            nums[slow++] == nums[fast++];
//        }
//        else
//        {
//            fast++;
//        }
//    }
//    return slow;
//}

////88. 合并两个有序数组
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    int s1 = m - 1;
//    int s2 = n - 1;
//    int ret = m + n - 1;
//    while (s1 >= 0 && s2 >= 0)
//    {
//        if (nums1[s1] > nums2[s2])
//        {
//            nums1[ret--] = nums1[s1--];
//        }
//        else
//        {
//            nums1[ret--] = nums2[s2--];
//        }
//    }
//    while (s1 >= 0)
//    {
//        nums1[ret--] = nums1[s1--];
//    }
//    while (s2 >= 0)
//    {
//        nums1[ret--] = nums2[s2--];
//    }
//}