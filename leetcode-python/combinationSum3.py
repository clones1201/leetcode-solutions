class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        self.answer = {
            1: {1:[[1]], 2:[[2]] , 3:[[3]], 4:[[4]], 5:[[5]], 6:[[6]], 7:[[7]], 8:[[8]], 9:[[9]]},
            2:{},
            3:{},
            4:{},
            5:{},
            6:{},
            7:{},
            8:{},
            9:{} }
        return [a for a in self.solve(k,n)]

    def solve(self, k, n):
        if(k == 1 and n > 0 and n < 10): 
            if(self.answer[k].has_key(n)):
                for ans in self.answer[k][n]:
                    yield ans

        elif(n == (k+1) * k / 2):
            if(not self.answer[k].has_key(n)):
                self.answer[k][n] = [[i for i in range(1,k + 1)]]
            if(self.answer[k].has_key(n)):
                for ans in self.answer[k][n]:
                    yield ans

        elif(n > (k + 1) * k / 2):
            if(not self.answer[k].has_key(n)):
                self.answer[k][n] = []
                if(k-1 > 0):
                    for i in range(1,min(10,n + 1 / 2)):
                        for a in self.solve(k-1, n - i):
                            if(a != [] and not i in a):
                                accept = True
                                for any in a:
                                    if(i < any):
                                        accept = False
                                if(accept):
                                    self.answer[k][n].append(a + [i])
            if(self.answer[k].has_key(n)):
                for ans in self.answer[k][n]:
                    yield ans
