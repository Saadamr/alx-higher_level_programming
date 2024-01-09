#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to pointer of the head of list
 * Return: pointer to the head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of the head of list
 * Return: 1 if it is a palindrome, 0 if it is not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *second_half = NULL;
    listint_t *prev_slow = *head;
    listint_t *mid_node = NULL;
    int is_pal = 1;

    if (*head != NULL && (*head)->next != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL)
        {
            mid_node = slow;
            slow = slow->next;
        }

        second_half = slow;
        prev_slow->next = NULL;
        reverse_list(&second_half);
        is_pal = compare_lists(*head, second_half);

        reverse_list(&second_half);

        if (mid_node != NULL)
        {
            prev_slow->next = mid_node;
            mid_node->next = second_half;
        }
        else
            prev_slow->next = second_half;
    }
    return is_pal;
}

/**
 * compare_lists - compares two linked lists
 * @head1: pointer to the head of the first list
 * @head2: pointer to the head of the second list
 * Return: 1 if both lists are equal, 0 otherwise
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->n == head2->n)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        else
            return 0;
    }

    if (head1 == NULL && head2 == NULL)
        return 1;

    return 0;
}

