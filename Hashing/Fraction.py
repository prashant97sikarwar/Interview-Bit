#Problem Link:- https://www.interviewbit.com/problems/fraction/

class Solution:
	# @param A : integer
	# @param B : integer
	# @return a strings
	def fractionToDecimal(self, num, den):
	    if num == 0:
	        return "0"
        sign = -1 if ((num < 0) ^ (den < 0)) else 1
        res = []
        if sign == -1:
            res.append("-")
        num = abs(num)
        den = abs(den)
        initial = num // den
        res.append(str(initial))
        d = dict()
        rem = num % den
        if rem > 0:
            res.append(".")
        repeat = False
        while  (rem > 0 and not repeat):
            if rem in d:
                repeat = True
                idx = d[rem]
                break
            else:
                d[rem] = len(res)
            rem *= 10
            temp = rem // den
            res.append(str(temp))
            rem %= den
        if repeat:
            res.append(")")
            res.insert(idx,"(")
        return "".join(res)
