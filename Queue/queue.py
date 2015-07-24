def push(element, queue):
    queue.append(element)
    print("ok")

def pop(queue):
    if len(queue) > 0:
        print(queue[0])
        queue.pop(0)
    else:
        print("error")

def front(queue):
    if len(queue) > 0:
        print(queue[0])
    else:
        print("error")

def size(queue):
    print(len(queue))

def clear(queue):
    print("ok")
    queue.clear()

def exit():
    import sys
    print("bye")
    sys.exit(0)

def parsecommand(cmd, queue):
    if(cmd[0]=="push"):
        push(int(cmd[1]), queue)
    elif(cmd[0]=="pop"):
        pop(queue)
    elif(cmd[0]=="front"):
        front(queue)
    elif(cmd[0]=="size"):
        size(queue)
    elif(cmd[0]=="clear"):
        clear(queue)
    elif(cmd[0]=="exit"):
        exit()
    else:
        print("Unrecognized command")

queue = []
while 1>0:
    commandstr = input()
    parsecommand(commandstr.split(' '), queue)
