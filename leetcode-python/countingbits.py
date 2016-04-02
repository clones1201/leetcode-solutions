class Solution(object):
    @staticmethod
    def countBits(num):
        """
        :type num: int
        :rtype: List[int]
        """
        ret = []
        for i in range(num + 1):
            pre = i / 2
            ret.append(0)
            if(i == 0):
                ret[i] = 0
            else:
                bit = i - (pre * 2)
                ret[i] = bit + ret[pre]
        
        return ret
      
