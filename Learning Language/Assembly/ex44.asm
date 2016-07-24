;*************************************************************
ds_segment segment
	string1 db 'Please enter a string: $'
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
	
	; 输入字母，输出大写
	input:
		mov ah, 1
		int 21h
		cmp al, '$'
		jz done
		cmp al, 'a'
		jb output
		sub al, 32
	output:
		mov dl, al
		mov ah, 2
		int 21h
		mov dl, 10
		int 21h
		jmp input
	done:
		mov dl, 10
		mov ah, 2
		int 21h
		mov ah, 4ch
		int 21h
code ends
;*************************************************************
end main