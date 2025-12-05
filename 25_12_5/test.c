#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = cur->next;
        cur->next = copy;
        copy->val = cur->val;
        cur = copy->next;
    }

    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }

    //²ðÁ´±í  »Ö¸´Ô­Á´±í
    struct Node* copyhead = NULL;
    struct Node* copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        if (copytail == NULL)
        {
            copyhead = copy;
            copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;
        }
        cur = cur->next;
        cur = next;
    }
    return copyhead;
}