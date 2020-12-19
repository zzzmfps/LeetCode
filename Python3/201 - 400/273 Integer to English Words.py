# 36ms, 88.13%; 13.7MB, 8.70%
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0: return 'Zero'
        
        arr1 = ['', '', 'Thousand', 'Million', 'Billion']
        arr2 = ['', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        arr3 = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        arr4 = ['', '', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']

        num = str(num)
        bits = len(num) % 3
        if bits != 0: num = '0' * (3 - bits) + num
        res = []
        for i in range(0, len(num), 3):
            tmp = len(res)
            x, y, z = int(num[i]), int(num[i + 1]), int(num[i + 2])
            if x > 0: res.extend([arr2[x], 'Hundred'])
            if y == 1:
                res.append(arr3[z])
            else:
                if y > 1: res.append(arr4[y])
                if z > 0: res.append(arr2[z])
            if len(res) != tmp:
                tmp = (len(num) - i) // 3
                if tmp > 1: res.append(arr1[tmp])

        return ' '.join(res)
