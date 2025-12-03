import operator , sys

def calc(expr):
    ops = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.floordiv, '%': operator.mod}
    def precedence(op):
        return {'+':1, '-':1, '*':2, '/':2, '%':2}.get(op, 0)
    def apply_ops(ops_stack, nums_stack):
        op = ops_stack.pop()
        b = nums_stack.pop()
        a = nums_stack.pop()
        nums_stack.append(ops[op](a, b))
    nums, ops_stack = [], []
    i = 0
    expr = expr.replace(' ', '')
    while i < len(expr):
        if expr[i].isdigit():
            num = 0
            while i < len(expr) and expr[i].isdigit():
                num = num * 10 + int(expr[i])
                i += 1
            nums.append(num)
        elif expr[i] == '(':
            ops_stack.append('(')
            i += 1
        elif expr[i] == ')':
            while ops_stack and ops_stack[-1] != '(':
                apply_ops(ops_stack, nums)
            ops_stack.pop()
            i += 1
        else:
            while ops_stack and ops_stack[-1] != '(' and precedence(ops_stack[-1]) >= precedence(expr[i]):
                apply_ops(ops_stack, nums)
            ops_stack.append(expr[i])
            i += 1
    while ops_stack:
        apply_ops(ops_stack, nums)
    return nums[0]

for line in sys.stdin:
    print(calc(line.strip()))