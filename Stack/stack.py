def push(element, stack):
    stack.append(element)
    print("ok")

def pop(stack):
    if len(stack) > 0:
        print(stack[-1])
        stack.pop()
    else:
        print("error")

def back(stack):
    if len(stack) > 0:
        print(stack[-1])
    else:
        print("error")

def size(stack):
    print(len(stack))

def clear(stack):
    print("ok")
    stack.clear()

def exit():
    import sys
    print("bye")
    sys.exit(0)

def parsecommand(cmd, stack):
    if(cmd[0]=="push"):
        push(int(cmd[1]), stack)
    elif(cmd[0]=="pop"):
        pop(stack)
    elif(cmd[0]=="back"):
        back(stack)
    elif(cmd[0]=="size"):
        size(stack)
    elif(cmd[0]=="clear"):
        clear(stack)
    elif(cmd[0]=="exit"):
        exit()
    else:
        print("Unrecognized command")

stack = []
while 1>0:
    commandstr = input()
    parsecommand(commandstr.split(' '), stack)
