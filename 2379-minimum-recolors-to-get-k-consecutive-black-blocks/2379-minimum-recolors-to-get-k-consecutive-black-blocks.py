class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = cnt_w = blocks[:k].count('W')

        for in_, out in zip(blocks[k:], blocks):
            cnt_w += (in_ == 'W') - (out == 'W')
            ans = min(ans, cnt_w)
        
        return ans