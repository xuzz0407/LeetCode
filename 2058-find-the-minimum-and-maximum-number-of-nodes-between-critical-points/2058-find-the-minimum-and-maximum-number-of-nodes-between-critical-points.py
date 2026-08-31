class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        first, pre = 0, -inf
        min_dis = inf
        a, b, c = head, head.next, head.next.next
        i = 1

        while c:
            if a.val < b.val > c.val or a.val > b.val < c.val:
                if first == 0:
                    first = i
                min_dis = min(min_dis, i - pre)
                pre = i
            a, b, c = b, c, c.next
            i += 1

        if first >= pre: 
            return [-1, -1]
        return [min_dis, pre - first]
