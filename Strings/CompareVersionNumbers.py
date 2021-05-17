#Problem Link:- https://www.interviewbit.com/problems/compare-version-numbers/

class Solution:
	# @param A : string
	# @param B : string
	# @return an integer
	def compareVersion(self, s1, s2):
	    if (len(s1) == 0 and len(s2) == 0):
	        return 0
        if (len(s1) == 0):
            return -1
        if (len(s2)) == 0:
            return 1
	    l1 = s1.split(".")
	    l2 = s2.split(".")
	    i = 0
	    while (i < len(l1) and i < len(l2)):
    	    if  (int(l1[i]) < int(l2[i])):
                return -1
            if (int(l1[i]) > int(l2[i])):
                return 1
            if (int(l1[i]) == int(l2[i])):
                i+=1
        if (i >= len(l1) and i >= len(l2)):
            return 0
        if (i >= len(l1)):
            while i < len(l2):
                if int(l2[i]) > 0:
                    return -1
                i += 1
        if (i >= len(l2)):
            while (i < len(l1)):
                if (int(l1[i]) > 0):
                    return 1
                i += 1
	    return 0
