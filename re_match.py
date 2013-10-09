#-!-coding:utf8-!-
import sys

def is_match(pattern, string):
    """
    判断string是否匹配pattern，其中pattern需要支持如下通配符：
    . 命中一个字符
    * 命中0个或者多个字符
    """
    if len(pattern) == 0 and len(string) == 0: return True
    if len(string) == 0:
        if len(pattern) != 0 and pattern[0] == '*':
            return is_match(pattern[1:], string)
        else: return False
    if len(pattern) == 0: return False
    if pattern[0] != '*':
        if pattern[0] != string[0] and pattern[0] != '.': return False
        return is_match(pattern[1:], string[1:])
    # 匹配'*'的情况
    return is_match(pattern[1:], string) or is_match(pattern, string[1:]) or is_match(pattern[1:], string[1:])

if __name__ == '__main__':
    test_cases = [
        (('zbz', 'zbz'), True),
        (('zbzz', 'zbz'), False),
        (('', 'zbz'), False),
        (('zbz', ''), False),
        (('*', 'zbz'), True),
        (('*', ''), True),
        (('.', ''), False),
        (('.', 'z'), True),
        (('.*', 'zh'), True),
        (('.*', 'z'), True),
        (('z.*', 'zhou'), True),
        (('z.z*', 'zhzou'), True),
        (('z.z*', 'zhz'), True),
        (('***', ''), True),
        (('*z*h*', 'zh'), True),
        (('*z*h*.*u', 'zhou'), True),
    ]
    for test_case in test_cases:
        ((pattern, string), matched) = test_case
        if is_match(pattern, string) != matched:
            sys.stderr.write("\"%s\" \"%s\" %s error!" %(string, pattern, str(matched)))
            sys.exit(-1)
