import numpy as np
import matplotlib.pyplot as plt

archivo = np.genfromtxt('tray.txt')
t = archivo[:,0]
x = archivo[:,1]
v = archivo[:,2]

plt.plot(t,x, label = 'x vs t')
plt.xlabel('t')
plt.ylabel('x')
plt.title('Posiciones')
plt.legend()
plt.savefig('pos.png')
plt.hold(False)

plt.plot(t,v, label = 'v vs t')
plt.xlabel('t')
plt.ylabel('v')
plt.title('Velocidades')
plt.legend()
plt.savefig('vel.png')
plt.hold(False)

plt.plot(x,v, label = 'v vs x')
plt.xlabel('x')
plt.ylabel('v')
plt.title('Espacio de fase')
plt.legend()
plt.savefig('phase.png')
plt.hold(False)
