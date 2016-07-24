;*************************************************************
ds_segment segment
	val dw ?
	string1 db 'Please enter two characters: $'
	string2 db 'AL BL CL DL: $'
ds_segment ends
;*************************************************************
ss_segment segment
	
ss_segment ends
;*************************************************************
code segment
;-------------------------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

main:
	; initialize
	mov ax, ds_segment
	mov ds, ax
	mov ax, ss_segment
	mov ss, ax
	
	lea dx, string1
	mov ah, 9
	int 21h
	
	; 三次循环吃回车, val保存最终输入结果
	mov ah, 1
	int 21h
	mov dh, al
	int 21h
	mov dl, al
	int 21h
	mov val, dx
	
	; 四次向左移进行赋值
	mov cl, 4
	rol val, cl
	mov ax, val
	and ax, 000Fh
	rol val, cl
	mov bx, val
	and bx, 000Fh
	rol val, cl
	rol val, cl
	mov dx, val
	and dx, 000Fh
	ror val, cl
	mov cx, val
	and cx, 000Fh
	
	; 存储答案
	push dx
	push cx
	push bx
	push ax
	
	lea dx, string2
	mov ah, 9
	int 21h
	; 输出答案
	mov cx, 4
	mov ah, 2
	output:
		pop bx
		mov dl, bl
		int 21h
	loop output
	
	mov dl, 10 ; 输出回车
	int 21h
	mov ah, 4ch
	int 21h
code ends
;*************************************************************
end main
		