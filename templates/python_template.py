import sys
sys.setrecursionlimit(100000000)

stdint =lambda: int(sys.stdin.readline())
stdstr =lambda: sys.stdin.readline()
stdflt =lambda: float(sys.stdin.readline())
readintlist =lambda: [int(i) for i in sys.stdin.readline().split()]
readstrlist = lambda: [str(i) for i in sys.stdin.readline().split()]
readfloatlist = lambda: [float(i) for i in sys.stdin.readline().split()]
stdwrite =lambda line: sys.stdout.write(line+"\n")  

#-------------------------------------------------------------------------#
