# 180ms, 62.41%
class Solution:
    def multiply(self, num1, num2):
        product = [0] * (len(num1) + len(num2))
        pos = len(product)
        for n1 in reversed(num1):
            tmp = pos - 1
            for n2 in reversed(num2):
                product[tmp] += (ord(n1) - 48) * (ord(n2) - 48)
                if product[tmp] > 9:
                    product[tmp - 1] += product[tmp] // 10
                    product[tmp] %= 10
                tmp -= 1
            pos -= 1
        pos = 0
        while pos < len(product) - 1 and product[pos] == 0:
            pos += 1
        return ''.join([str(p) for p in product])[pos:]
        
