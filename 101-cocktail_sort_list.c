#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker
 * 
 * @list: the list to be sorted
 * Return: nothing, it is void
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *head, *nex_t, *pre_v;
    bool flag, loop;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    head = *list;
    loop = true;
    while (loop)
    {
        flag = true;
        for (head = (*list); head->next; head = head->next)
        { 
            if (head->n > head->next->n)
            {
                nex_t = head->next;
                flag = false;
                head->next = nex_t->next;
                if (nex_t->next)
                    nex_t->next->prev = head;
                nex_t->prev = head->prev;
                if (head->prev)
                    head->prev->next = nex_t;
                else
                    *list = nex_t;
                nex_t->next = head;
                head->prev = nex_t;
                print_list(*list);
                head = head->prev;
            }
        }
        if (flag == true)
            return;
        for (; head->prev; head = head->prev)
        {
            if (head->n < head->prev->n)
            {
                flag = false;
                pre_v = head->prev;
                pre_v->next = head->next;
                if (head->next)
                    head->next->prev = pre_v;
                head->prev = pre_v->prev;
                if (pre_v->prev)
                    pre_v->prev->next = head;
                else
                    *list = head;
                head->next = pre_v;
                pre_v->prev = head;
                print_list(*list);
                head = head->next;
            }
        }
    }
}
