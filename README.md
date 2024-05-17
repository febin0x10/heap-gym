# Heap-Gym
Practice Binaries for learning basic Linux GLIBC Heap Exploitation techniques. 

I created a program named 'CapsuleDB' that works with Heap and has various Linux HEAP related bugs/vulnerabilities for you to practice Glibc Heap Exploitation. This might be helpful for you to lean binary exploitation, get hands-on heap exploitation, understand real-life 0-day exploits, CTFs and more.


## HEAP GYM Challenges

### With TCACHE

Programs compiled with one of the later GLIBC version (2.27), and has Tcache implementation. Your Objective is to exploit vulnerabilities in those programs to get a shell.

1.  **heap-easy0**: This is an easy challenge, you can exploit the binary to overwrite GOT entry of any function like printf,puts or free with a win function (debug_shell()) using Double-Free or Use-After-Free techniques
2.  **heap-easy1**: In this level, the Use-After-Free and Double-Free bugs are patched in the binary, you need to find an Heap Overflow bug and exploit it to gain arbitrary write primitive like in the previous level and overwrite GOT entry of any function like printf,puts or free with a win function (debug_shell()).
3.  
