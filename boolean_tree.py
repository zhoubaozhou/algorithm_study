#-!-coding:utf8-!-

class Node(object):
    def __init__(self, data):
        self._data = data

    def eval(self):
        return self._data == 'TRUE'

    def __repr__(self):
        return "<Node '%s'>" % self._data
    __str__ = __repr__

class AndNode(Node):
    def __init__(self, left, right):
        self._left = left
        self._right = right

    def eval(self):
        return self._left.eval() and self._right.eval()

    def __repr__(self):
        return "<AndNode %s , %s >" %(self._left, self._right)
    __str__ = __repr__

class OrNode(Node):
    def __init__(self, left, right):
        self._left = left
        self._right = right

    def eval(self):
        return self._left.eval() or self._right.eval()

    def __repr__(self):
        return "<OrNode %s , %s >" %(self._left, self._right)
    __str__ = __repr__
    
class NotNode(Node):
    def __init__(self, node):
        self._node = node

    def eval(self):
        return not self._node.eval()

    def __repr__(self):
        return "<NotNode %s >" %(self._node)

    __str__ = __repr__


def parse_expression(tokens):
    KEYWORDS = ['AND', 'OR', 'NOT']
    token = tokens.pop(0)
    if token not in KEYWORDS:
        return Node(token)
    if token == 'AND':
        return AndNode(parse_expression(tokens), parse_expression(tokens))
    elif token == 'OR':
        return OrNode(parse_expression(tokens), parse_expression(tokens))
    elif token == 'NOT':
        return NotNode(parse_expression(tokens))
    raise RuntimeError("can't parse expression!")

def parse_tokens(expression):
    tokens = []
    for token  in expression.split(' '):
        token = token.strip()
        if len(token) == 0: continue
        tokens.append(token)
    return tokens
    
if __name__ == '__main__':
    tokens = parse_tokens("AND TRUE OR TRUE NOT TRUE")
    root = parse_expression(tokens)
    print root
    print eval(root)
