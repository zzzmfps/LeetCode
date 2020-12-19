# 68ms, 80.95%
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        visits, res = {}, []
        for domain in cpdomains:
            tmp = domain.split()
            count, doms = int(tmp[0]), tmp[1].split('.')
            for i in range(len(doms)):
                domain = '.'.join(doms[i:])
                if visits.get(domain, 0):
                    visits[domain] += count
                else:
                    visits[domain] = count
        for v in visits.items():
            res.append(str(v[1]) + ' ' + v[0])
        return res
    
