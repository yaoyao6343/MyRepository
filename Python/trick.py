#!/usr/bin/python
# -*- coding: UTF-8 -*-


import unittest


"""
@summary: List to dictionary
@note: Only two elements in the list support.
"""
def list_to_dict():
    a = ['a', 'b']
    b = [1, 2]
    d = dict([a, b])
    print '\n'.join("%s: %s" % (k, v) for k, v in d.items())


"""
@summary: The difference between re.match and re.search
"""
def re_match_and_search():
    import re
    line = "Cats are smarter than dogs"
    matchObj = re.match(r'dogs', line, re.M|re.I)
    if matchObj:
        print "match --> matchObj.group() : ", matchObj.group()
    else:
        print "No match!!"
    matchObj = re.search(r'dogs', line, re.M|re.I)
    if matchObj:
        print "search --> matchObj.group() : ", matchObj.group()
    else:
        print "No match!!"


"""
@summary: Use variable name as funciton to execute
"""
def var_to_fun():
    def fun():
        print 'fun'
    t = eval('fun')
    t()


"""
@summary: Three sort funcitons
@note: dict.sort(), list.sort()
       sorted(list, dict, tuple, string), return list
"""
def three_sort_func():
    a = [5,7,6,3,4,1,2]
    a.sort()    # [1, 2, 3, 4, 5, 6, 7]
    print a

    b = sorted(a)
    print b

    a.reverse()
    print a


"""
@summary: Unit test
@note: Use unittest.main() to lanuch test
"""
def is_prime(num):
    for ele in range(num):
        if ele == 0 or ele == 1:
            continue
        if num % ele == 0:
            return False
    return True
def print_next_prime(num):
    idx = num
    while True:
        idx += 1
        if is_prime(idx):
            print(idx)
class PrimesTestCase(unittest.TestCase):
    """docstring for PrimesTestCase"""
    def test_is_five_prime(self):
        self.assertTrue(is_prime(5))


"""
@summary: Trick
"""
def some_tricks():
    a = 3
    b = 1
    print """"0 < b < a < 5" is %s""" % (0 < b < a < 5)

    s = 'xx'
    l = ['a']
    d = {'a': 'a'}
    if s and l and d:
        print """"if s and l and d" is True"""

    print """reverse_str(s):\n    return [::-1]"""

    sl = ["hello", "world"]
    print ' '.join(sl)

    l = [x*x for x in range(10) if x % 3 == 0]
    print l

    ## for...else...
    for x in xrange(1, 5):
        if x == 5:
            print 'find 5'
            break
    else:
        print 'can not find 5!'

    print "b = 2 if a > 2 else 1"





### Test
if __name__ == '__main__':
    # list_to_dict()
    # re_match_and_search()
    # var_to_fun()
    # three_sort_func()
    # unittest.main()
    some_tricks()
