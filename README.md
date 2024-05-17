# Heap-Gym
Practice Binaries for learning basic Linux GLIBC Heap Exploitation techniques. 

I created a program named 'CapsuleDB' that works with Heap and has various Linux HEAP related bugs/vulnerabilities for you to practice Glibc Heap Exploitation. This might be helpful for you to lean binary exploitation, get hands-on heap exploitation, understand real-life 0-day exploits, CTFs and more.


## HEAP GYM Challenges

### With TCACHE

Programs compiled with one of the later GLIBC version (2.27), and has Tcache implementation. Your Objective is to exploit vulnerabilities in those programs to get a shell.

1.  **heap-easy0**: This is an easy challenge, you can exploit the binary to overwrite GOT entry of any function like printf,puts or free with a win function (debug_shell()) using Double-Free or Use-After-Free techniques

2.  **heap-easy1**: In this level, the Use-After-Free and Double-Free bugs are patched in the binary, you need to find an Heap Overflow bug and exploit it to gain arbitrary write primitive like in the previous level and overwrite GOT entry of any function like printf,puts or free with a win function (debug_shell()).

3.  **heap-uaf1**: There's no win function, the binary is compiled without PIE and there's a memory leak bug. You need to find the libc base address and the address of system() function using the memory leak bypassing ASLR and exploit USE-AFTER-FREE bug to achieve Arbitrary write primitive and later gain code execution via GOT overwrite. Feel free to refer my commented exploit script (exploit.py) if you stuck at exploitation part.

4.  **heap-df1**: There's no win function, but the binary is compiled without PIE and there's a memory leak bug. In this level the Use-After-Free bug is fixed/patched. You need to find the libc base address and the address of system() function using the memory leak bypassing ASLR and exploit DOUBLE-FREE bug to achieve Arbitrary write primitive and later gain code execution via GOT overwrite. Feel free to refer my commented exploit script (exploit.py) if you stuck at exploitation part.

5.  **heap-OF1**: There's no win function, but the binary is compiled without PIE and there's a memory leak bug. In this level the Use-After-Free bug and the Double-Free bug has been fixed/patched. You need to find the libc base address and the address of system() function using the memory leak bypassing ASLR and you need to find and exploit a  HEAP OVERFLOW bug to overwrite a freed chunk, achieve Arbitrary write primitive and later gain code execution via GOT overwrite. Feel free to refer my commented exploit script (exploit.py) if you stuck at exploitation part.

6.  **heap-uaf2**: This time there's no win function, the binary is compiled with PIE and Full-Relro that means you can't perform GOT overwrite, but there's still a memory leak bug. You need to find the libc base address and the address of system() function using the memory leak bypassing ASLR and exploit USE-AFTER-FREE bug to achieve Arbitrary write primitive and later gain code execution via hijacking something else from libc(hint: HOOKS). Feel free to refer my commented exploit script (exploit.py) if you stuck at exploitation part.

7.  **heap-df2**: There's no win function, the binary is compiled with PIE and Full-Relro that means you can't perform GOT overwrite, but there's still a memory leak bug. In this level the Use-After-Free bug is fixed/patched. You need to find the libc base address and the address of system() function using the memory leak bypassing ASLR and exploit DOUBLE-FREE bug to achieve Arbitrary write primitive and later gain code execution via hijacking something else from libc(hint: HOOKS). Feel free to refer my commented exploit script (exploit.py) if you stuck at exploitation part.


