
class UserMainCode(object):
   
    @classmethod
    def game(cls, input1):
        n = len(input1)
        if (n == 1):
            return input1
        max_len = 0
        start = 0 
        end = 0
        for i in range(n-1):
            left, right = i, i
            while (left >= 0 and right < n and input1[left] == input1[right]):
                left -= 1
                right += 1
            odd = (right - left - 1)
            left, right = i, i+1
            while (left >= 0 and right < n and input1[left] == input1[right]):
                left -= 1
                right += 1
            even = (right - left - 1)
            if (odd > max_len):
                start = i - odd // 2
                max_len = odd;1
            if (even > max_len):
                start = i - even // 2 + 1
                max_len = even;
        return input1[start:start+max_len]




print(game("slfjdflkracecaeeeeeeeeeeeerldjfl"))


