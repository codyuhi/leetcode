class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def convert_linked_list_to_list(linked_list):
    result_list = []
    while linked_list and hasattr(linked_list, 'val'):
        result_list.append(linked_list.val)
        if not linked_list.next:
            break
        linked_list = linked_list.next
    return result_list


class Solution:
    # Reached the optimal solution the first time.
    # Beats 93.84% of submissions with a runtime of 32 ms
    # Beats 69.82% of submissions with a memory usage of 13.9 MB
    def mergeTwoLists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1
        if list1.val < list2.val:
            list_node = list1
            list1 = list1.next
        else:
            list_node = list2
            list2 = list2.next
        head = list_node
        while list1 and list2:
            if list1.val > list2.val:
                list_node.next = list2
                list_node = list_node.next
                list2 = list2.next
            else:
                list_node.next = list1
                list_node = list_node.next
                list1 = list1.next
        if list1:
            list_node.next = list1
        if list2:
            list_node.next = list2
        return head


INPUTS = [
    [
        ListNode(
            val=1,
            next=ListNode(
                val=2,
                next=ListNode(
                    val=4,
                    next=None
                )
            )
        ),
        ListNode(
            val=1,
            next=ListNode(
                val=3,
                next=ListNode(
                    val=4,
                    next=None
                )
            )
        )
    ],
    [
        None,
        None
    ],
    [
        None,
        ListNode(
            val=0,
            next=None
        )
    ]

]


if __name__ == '__main__':
    sol = Solution()
    for inp in INPUTS:
        print(
            f'\n"{convert_linked_list_to_list(inp[0])}, {convert_linked_list_to_list(inp[1])}":')
        pretty_list = convert_linked_list_to_list(
            sol.mergeTwoLists(inp[0], inp[1])
        )
        print('1st:', pretty_list)
