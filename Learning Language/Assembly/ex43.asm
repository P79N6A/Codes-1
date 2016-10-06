;*************************************************************
ds_segment segment
	string1 db 'Please enter a string: $'
	string2 db 'The total number of non-digital char are : $'
	cnt db 0
ds_segment ends
;*************************************************************
ss_segment segment
ss_segment ends
;*************************************************************
code segment
;-------------------------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

main:
	mov ax, ds_segment
	mov ds, ax
	mov ax, ss_segment
	mov ss, ax
	
	lea dx, string1
	mov ah, 9
	int 21h
	
	; 输入字符串，判断非数字个数
	input:
		mov ah, 1
		int 21h
		cmp al, '$'
		jz done
		cmp al, '0'
		jb increase
		cmp al, ':'
		jnb increase
		jmp input
	increase:
		inc cnt
		jmp input
	done:
		mov dl, 10
		mov ah, 2
		int 21h
		lea dx, string2
		mov ah, 9
		int 21h
		
	; 用十进制输出答案
	mov al, cnt
	mov ah, 0
	mov dl, 100
	div dl
	push ax
	mov dl, al
	add dl, '0'
	mov ah, 2
	int 21h
	pop ax
	mov al, ah
	mov ah, 0
	mov dl, 10
	div dl
	push ax
	mov dl, al
	add dl, '0'
	mov ah, 2
	int 21h
	pop ax
	mov al, ah
	mov ah, 0
	mov dl, al
	add dl, '0'
	mov ah, 2
	int 21h
	mov dl, 10
	int 21h
	mov ah, 4ch
	int 21h
code ends
;*************************************************************
end main