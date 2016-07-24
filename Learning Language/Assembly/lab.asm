;little letter to big letter 
data segment
 strings1 db "thGnHJ","$"
 strings2 db "HJKLbuib","$"
data ends

stack segment stack
 dw 20h dup(0)
stack ends

code segment
 assume ds:data,ss:stack,cs:code
  start:mov ax,data
        mov ds,ax
        mov ax,stack
        mov ss,ax

        mov al,"a"
        mov bl,"b"
        nop
        lea bx,strings1;将strings1指向的字符串的第一个地址送入bx
        mov cx,6
compare: mov al,[bx]
        cmp al,60h
        ja changbig
        inc bx
recycle:    loop compare
            lea dx,strings1
            mov ah,9
            int 21h
            lea dx,strings2
            mov ah,0ah
            int 21h

            mov ah,4ch
            int 21h
changbig:sub al,20h
         mov [bx],al
         inc bx
         jmp recycle

        mov ah,4ch
        int 21h
code ends
end start