import math

from numpy import arange
import matplotlib.pyplot as plt

Umax = 100
f = 50
R1 = 5
R2 = 4
R3 = 7
R4 = 2
L1 = 0.01
L3 = 0.015
C1 = 300 * math.pow(10, -6)
C2 = 150 * math.pow(10, -6)
T = 0.2
h = 0.0001
Y = [0] * 3
X = [0] * 3

def func1(par1, par2):
    return (U1-par1- par2)/C1*R1

def func2(par1, par2, par3):
    return 1/(C2*(R2+R3))*(U1-par1-par2)/R1*(R2+R3)-par3*R3 - par2

def func3(par1, par2, par3):
    return R3/L1*((U1-par1-par2)/R1-(U1-par1-par2)/R1*(R2+R3)-par3*R3 - par2 - par3)

if __name__ == '__main__':
    for t in arange(0, (T - h / 2), h):
        U1 = Umax * math.sin(2 * math.pi * f * t)

        X[0] = Y[0] + h*func1(Y[0], Y[1])
        X[1] = Y[1] + h*func2(Y[0], Y[1], Y[2])
        X[2] = Y[2] + h*func3(Y[0], Y[1], Y[2])

        X0 = func1(Y[0], Y[1])
        X1 = func1(X[0], X[1])
        X[0] = Y[0] + 0.5*h*(X0+X1)

        X0 = func2(Y[0], Y[1], Y[2])
        X1 = func2(X[0], X[1], X[2])
        X[1] = Y[1] + 0.5*h*(X0+X1)

        X0 = func3(Y[0], Y[1], Y[2])
        X1 = func3(X[0], X[1], X[2])
        X[2] = Y[2] + 0.5 * h * (X0 + X1)

        Y[0] = X[0]
        Y[1] = X[1]
        Y[2] = X[2]
        U2 = X[2] * L1
        print( str(U2) + '\t' + str(t))
        plt.plot(t+h,U2,'ro')

    plt.xlabel(r'$t$')
    plt.ylabel(r'$U2$')
    plt.grid(True)
    plt.show()
