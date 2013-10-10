#-!-coding:utf8-!-

OPERATORS = ['+', '-', '*', '/']

OPERATOR_PRIO = {
    '+' : 1,
    '-' : 1,
    '*' : 2,
    '/' : 2,
}

def token_expr(expr_str):
    tokens = []
    token = ''
    for char in expr_str:
        if char in OPERATORS:
            if len(token) > 0:
                tokens.append(token)
                token = ''
            tokens.append(char)
            continue
        token += char
    if len(token) > 0:
        tokens.append(token)
    return tokens

def do_op(op, x, y):
    if op == '+': return x+y
    elif op == '-': return x-y
    elif op == '*': return x*y
    elif op == '/': return x/y
    raise RuntimeError("invalid op %s" %(op,))
    
def calc_heap(num_heap, op_heap, stop_prio):
    """
        运算堆栈里面的数据直到运算符的优先级小于或者等于stop_prio
    """
    while len(op_heap) > 0 and OPERATOR_PRIO[op_heap[-1]] > stop_prio:
        y = num_heap.pop(-1)
        x = num_heap.pop(-1)
        num_heap.append(do_op(op_heap.pop(-1), x, y))

def calc(expr):
    expr_tokens = token_expr(expr)
    num_heap = []
    op_heap = []
    for token in expr_tokens:
        if token not in OPERATORS:
            num_heap.append(int(token))
            continue
        if len(op_heap) == 0 or OPERATOR_PRIO[op_heap[-1]] <= OPERATOR_PRIO[token]:
            # 当前操作符的优先级不比堆栈的操作符优先级高
            op_heap.append(token)
            continue
        calc_heap(num_heap, op_heap, OPERATOR_PRIO[token])
        op_heap.append(token)
    calc_heap(num_heap, op_heap, 0)
    return num_heap[0]

if __name__ == '__main__':
    print calc('12+2*3+45*5+4/1+2')
